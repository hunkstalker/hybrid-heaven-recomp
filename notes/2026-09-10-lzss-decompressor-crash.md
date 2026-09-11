# SESIÓN 2026-09-10 — Crash determinista del descompresor LZSS (boot) + FIX de concurrencia del runtime

> Complementa `notes/2026-09-10-ghidra-syms-solucion-fondo.md` §7.5. Documenta dos cosas:
> (1) **no es un race**: el crash del boot es un **descompresor LZSS mis-compilado/mal-acotado**;
> (2) **FIX de concurrencia** aplicado al runtime (violación del modelo single-CPU del N64).

## 0. Reproducción (build_dbg, headless Xvfb + lavapipe)

```sh
cd port/HybridHeavenRecomp/build_dbg
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  timeout 45 "./Hybrid Heaven Recomp" >/tmp/hh.log 2>&1 ; echo $?   # 139 (SIGSEGV), SIEMPRE
```

Crash determinista en `FUN_80003824` (funcs_1.c:3621, vram 0x80003D04):

```
#0 FUN_80003824 (rdram, ctx)  funcs_1.c:3621   ctx->r22 = MEM_BU(ctx->r18, 0X0);
#1 FUN_8000469c            funcs_1.c:5520
#2 FUN_800011b0 (game loop) funcs_0.c:2905
#3 run_thread_function     recomp.cpp:560   (thread "[Game] 5")
```

En gdb, en el punto de crash:
- `ctx->r18` (s2, puntero al dato comprimido) = **`0xc`** (offset pequeño, NO dirección virtual).
- El macro `MEM_BU` hace `rdram + ((s2 ^ 3) - 0xFFFFFFFF80000000)` = `rdram + (0xc - 0x80000000)` =
  `rdram - 0x80000000 + 0xf` → **fuera de RDRAM** → SIGSEGV.
- Heap `0x80089518` = todo ceros; globals `0x8006D000` = todo ceros.

## 1. No es un race — es el descompresor LZSS (bloqueante #3)

- El crash **se reproduce en gdb** (que enlentece todo) → **no depende del timing** → NO es un race.
- La nota anterior (§7.5) decía "no determinista" por un estado previo; tras añadir
  `FUN_80003D3C`/`FUN_80003db4` el crash quedó determinista.
- `FUN_80003824` es el **descompresor LZSS** del cargador `trans`: se le llama con
  `a0 = 0x4E69A8` (offset ROM del asset Nisitenma, size `a2 = 0x55DD4` = 351700 bytes,
  == la entrada `[7]` del manifest: `off=0x4E69A8 comp=1 size=351700`).
- Instrumentación temporal (`fprintf` en la entrada + en 0x80003D04) mostró el walk:
  `s2` va `0x80089524 → 0x8008b514` en pasos de `+0x10` (**512 bloques**), y el contador
  `r9 = *(0x8006D01C)` baja `0x55DC7 → 0x53DC7` (pasos de `-0x10`). En el bloque final
  (s2 = 0x8008b514) el **header de 4 bytes leído es corrupto (`0x8000000f`)** → s2 colapsa a 0xc.

## 2. Diagnóstico del descompresor (causa raíz del bloqueante #3)

- `FUN_80003824` lee en `s2` un header de 4 bytes (tamaño de bloque) vía 4 llamadas a
  `FUN_80003D3C` (que devuelve `a0+1`), construye `s6`, y hace `s7 = base + s6 - 4`; luego
  descomprime un bloque LZSS (`s0 < 0x80` = literal; `s0 >= 0x80` = match con
  `s3 = (t4<<8|s0) & 0x3FF`, copia `a0 = s1 - s3`).
- El bug se manifiesta al final del buffer comprimido: el header del último bloque (en
  `0x8008b514`) no es un tamaño válido sino `0x8000000f` → `s2 += s6` envuelve y queda `0xc`.
- **Implicación**: o el buffer de entrada (RAM `0x80089518..`) es demasiado corto (se esperan
  0x55DD4 bytes de comprimido pero solo hay ~0x2000), o la lectura llega un bloque más allá del
  final del stream, o el formato LZSS al final difiere. Es la **investigación de las variantes
  LZSS (`LZSS 5`/`LZSS 7`) ya marcada como bloqueante #3** — necesita comparar el binario
  descomprimido real (oráculo en RAM 0x801BB000 etc.) contra la salida del `trans` loader.

### 2.1 Cómo comparar original vs recompilado (herramienta lista)

- El mapeo correcto es `rom_off = vram - 0x7FFFF400` (la ROM retail tiene header de 0xC00).
  (La nota de `n64sym` que decía `rom_off = vram - 0x7FFFF400` es correcta.)
- Disasemblar con capstone (disponible en el contenedor):
```sh
python3 - <<'EOF'
import capstone
rom=open('work/roms/us_retail.z64','rb').read()
md=capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS32|capstone.CS_MODE_BIG_ENDIAN)
off=0x80003A3C-0x7FFFF400
for i in md.disasm(rom[off:off+0x200], 0x80003A3C):
    print(f"{i.address:08X}: {i.mnemonic} {i.op_str}")
EOF
```
- Verificado: el recompilado coincide con el original en todo el rango revisado
  (delay-slots duplicados correctamente: `addiu s7,s7,1` y `move s2,v0` se emiten en ambas ramas).

## 3. FIX de concurrencia (runtime) — violación del modelo single-CPU del N64

> Este fix es **correcto** (el N64 tiene UNA CPU) pero **NO arregla** el crash del descompresor
> (que es determinista). Lo mantengo porque era la hipótesis marcada en §7.5 y corrige una
> violación real: `osStartThread` desde el hilo de boot (`thread_self == NULL`) hace
> `resume_thread(t)` (señala) **sin aparcar el hilo de boot**, así que los game-threads corren
> **concurrentemente** en sus host-threads → datos compartidos (heap/colas) se corrompen.

### 3.1 Cambios (repo `lib/N64ModernRuntime`, sin commitear)

| Archivo | Cambio |
|---|---|
| `ultramodern/src/threads.cpp` | `#include <mutex>`; `static std::mutex game_mutex` + `thread_local bool holds_game_lock`; `ultramodern::acquire_game_lock()`/`release_game_lock()`; `wait_for_resumed` libera el lock antes de `running.wait()` y lo re-adquiere al despertar; `_thread_func` libera el lock en los paths de salida (`run_next_thread` y "destroyed before start") |
| `ultramodern/include/ultramodern/ultramodern.hpp` | decl `acquire_game_lock()`/`release_game_lock()` |
| `ultramodern/src/mesgqueue.cpp` | `wait_for_external_message`/`_timed` liberan el lock antes del `wait_dequeue` y lo re-adquieren después (park de `pause_self`/`yield_self`) |
| `librecomp/src/recomp.cpp` | el hilo de boot/entrypoint adquiere el lock antes de `game_entry.entrypoint(...)` y lo libera al terminar (y en los `catch`) |

### 3.2 Verificación

- Build_dbg compila (gcc) y **el boot avanza**: el game-loop (thread 5) corre y el descompresor
  procesa 512 bloques antes del crash (determinista). No deadlock.
- **Pendiente**: validación en Windows (no puedo ejecutarlo en el contenedor). El lock debe
  re-validarse en el build MSVC.

## 4. Estado / próximos pasos

1. **Desbloquear el boot**: arreglar el descompresor LZSS (`FUN_80003824`, bloqueante #3).
   - Comparar el stream comprimido real (oráculo) contra la salida del `trans` loader.
   - Puede requerir un límite de función o un parche de instrucción en la zona 0x80003824-0x80003D0C.
2. **Validar el fix de concurrencia** en Windows.
3. Tras boot estable: wiring de eventos + RSP routing + `loadUCodeGBI` para el render (tareas 5/6 del TODO).

## 5. Archivos tocados en esta sesión

- `lib/N64ModernRuntime/ultramodern/src/threads.cpp` (concurrencia)
- `lib/N64ModernRuntime/ultramodern/include/ultramodern/ultramodern.hpp` (concurrencia)
- `lib/N64ModernRuntime/ultramodern/src/mesgqueue.cpp` (concurrencia)
- `lib/N64ModernRuntime/librecomp/src/recomp.cpp` (concurrencia)
- `port/HybridHeavenRecomp/RecompiledFuncs/funcs_1.c` (instrumentación TEMPORAL — **revertida**)
- `build_dbg/` (binario reconstruido; gitignored)

---

## 6. INVESTIGACIÓN INTERNET (2026-09-10) — el asset es un LZKN64 **estructurado en bloques**, no plano

### 6.1 lzkn64 NO es un oráculo válido para este asset

- `lzkn64.decompress(asset)` decodifica **la primera parte** a MIPS coherente (offsets 0x0/0x1000/0x40000),
  **pero el resto es basura**: de 30 regiones aleatorias, **19** no tienen ni 4 instrucciones válidas
  en 40 bytes. → el asset NO es LZKN64 plano (el algoritmo plano de Goemon solo "encaja" por azar al inicio).
- El asset es un LZKN64 **estructurado en bloques** (la variante propia del `trans`, "LZSS 5/7"):
  cada bloque tiene un header de 4 bytes y datos LZSS.

### 6.2 FUN_80003824 = descompresor de la familia LZKN64 (mismos rangos de comando)

- Mismos rangos que LZKN64: `0x00-0x7F` sliding-window, `0x80-0x9F` raw, `0xA0-0xDF` RLE-any,
  `0xE0-0xFE` RLE-zero, `0xFF` RLE-long-zero.
- Diferencia: offset de **10 bits** (`s3 = (s0<<8|next) & 0x3FF`, `length=(s0>>2)+2`) vs 8 bits de Goemon.
- El routing (FUN_8000469C) solo tiene 2 caminos: `*(tabla+0xC) < 0` → FUN_80003824 (comprimido),
  `>= 0` → DMA directo. Es el único descompresor comprimido.
- Header de bloque: lee 4 bytes en `s6` (`s7 = base + s6 - 4`), y si `s6 & 0xF000` → big-block path.

### 6.3 Causa del crash (chunk-reload) — CONFIRMADO con instrumentación

- **Solo se produce UN reload** de chunk (el contador 0x8006D020 llega a 1) — justo al final, antes del crash.
  El reload es correcto (resetea s2 a 0x80089518). → el estado del chunk NO es el problema.
- **El crash real**: en el bloque 512 (frontera del 1er chunk 0x2000) FUN_80003824 lee un **header
  corrupto `0x82E7A800`** en los últimos 4 bytes del chunk (0x8008b514). Al tener `0xF000` set se va
  al big-block path; `s6 & 0x0FFFFFFF` = 0x02E7A800 (tamaño gigante) → el puntero s2 colapsa a 0xc → SIGSEGV.
- Los tamaños de bloque NO alinean con la frontera 0x2000 (los 512 bloques consumen 0x1FFC, dejando 4
  bytes que se leen como un header fantasma). → bug de **contabilidad de bloques** en la frontera del chunk.

### 6.4 Próximo paso concreto

1. **Contabilidad de bloques**: los tamaños de bloque no suman exactamente 0x2000 (quedan 4 bytes). Hay que
   entender por qué el header del bloque 513 se lee en 0x8008b514 en vez de hacer reload antes.
   - Comparar el recompilado vs original de la zona 0x80003A7C-0x80003D08 (big-block path + padding +
     bgtzl) con capstone (rom_off = vram - 0x7FFFF400) para hallar el desvío.
   - Posible límite de función incorrecto o un `s7`/`base` mal calculado al cruzar el chunk.
2. **NO usar lzkn64 como oráculo** (su salida es basura para este asset). El oráculo válido es el
   binario descomprimido real en RAM del emulador (tarea #3 / BizHawk).

### 6.5 CORRECCIÓN CLAVE (2026-09-10) — los globales están en 0x8005D0xx, NO 0x8006D0xx

- **Error mío**: `0x80060000 - 0x2FEC = 0x8005D014`. Los globales del descompresor son:
  `0x8005D010` (fuente ROM), `0x8005D014` (base/posición), `0x8005D018` (restante),
  `0x8005D01C` (fin), `0x8005D020` (contador de chunk), `0x8005D026` (**stride**).
- Con las direcciones CORRECTAS, la instrumentación (513 iteraciones del block-top) muestra:
  - **ENTRY: a0=0x4E69A8 a1=0x80107830 a2=0x55DD4** (args correctos).
  - **stride(0x8005D026) = 1** constante → **NO es el bug** (descartado).
  - **s1 (puntero de salida) = 0x80107830 CONSTANTE** → el descompresor **lee el stream pero NO escribe
    salida** (0 bytes producidos). base(0x8005D014) y el contador 5D020 sí cambian (procesa bloques).
  - s2 avanza 0x10 por bloque (lee el header de 4 bytes + 0xC de datos).
- **Conclusión**: FUN_80003824 procesa bloques (estado cambia) pero el **decode LZSS no produce salida**
  (s1 no avanza) → bug de recompilación profundo del bucle de decode, NO de stride ni de datos.
  - Siguiente: por qué s6 (tamaño de bloque) sale 0/negativo y el `sltu v1, s7` (decode loop) sale al
    instante sin escribir. Comparar el recompilado vs original del decode (0x80003918-0x80003C98).

### 6.6 PIVOT (2026-09-10) — CAUSA RAÍZ: el asset NO se carga (buffer vacío), el DMA no copia

- **s6 = 0x0 para TODOS los 513 bloques.** El header de 4 bytes leído en `s2=0x80089518` es 0.
  → **El buffer del chunk (0x80089518) está vacío (ceros): el asset NUNCA se cargó en RDRAM.**
- La traza del DMA (2 llamadas) muestra args CORRECTOS:
  - `src=0x4E69A8 dest=0x80089518 size=0x2000` (chunk 1)
  - `src=0x4E89A8 dest=0x80089518 size=0x2000` (chunk 2, = 0x4E69A8+0x2000)
- **PERO la copia NO ocurre**: la cadena de carga `FUN_80003DB4 → FUN_80001FE8 → FUN_80001F30`
  llama a `FUN_80028A90`, `0x80030640`, `0x800306C0` que son **TODAS operaciones de cache**
  (`cache 0x19/0x10/0x15`) + preparación de un struct en 0x8005D280 — **NO copian ROM→RDRAM.**
- **El runtime lee la ROM vía `osPiStartDma_recomp` → `do_dma` → `do_rom_read` (pi.cpp)**, pero el DMA
  del juego (custom, FUN_80001F30) **NO pasa por `osPiStartDma`** → `do_dma` nunca se invoca → sin copia.
- **CONCLUSIÓN (PIVOT)**: el descompresor FUN_80003824 probablemente es CORRECTO; el problema es que el
  asset **no se carga del ROM al RDRAM** porque la vía de lectura del juego (custom PI DMA / trans loader)
  no está soportada por el runtime. Es un **hueco de emulación del PI DMA / ROM read**, NO un bug del
  descompresor.
- **Siguiente**: averiguar CÓMO el juego lee el asset del ROM (¿osPiStartDma real de libultra? ¿MMIO del
  PI 0xA4600000? ¿memory-mapped 0x10000000?) y hacer que el runtime lo soporte (o parchear el juego para
  usar `recomp::do_rom_read`). Ver pi.cpp (do_dma/do_rom_read/osPiStartDma_recomp).

### 6.7 FIX ENCONTRADO (2026-09-10) — la función del DMA estaba dividida por Ghidra (igual que el game loop)

- **Ghidra dividió la función del DMA** `0x80001F30-0x80001FE8` en **4 partes**:
  `FUN_80001f30` (0x80001F30-0x80001FB4) + `FUN_80001fb4` (0x80001FB4-0x80001FC8) +
  `FUN_80001fc8` + `FUN_80001fd8`. El caller `FUN_80001fe8` solo llamaba a `LOOKUP_FUNC(0x80001F30)`
  (cache ops + struct setup) y **NUNCA** a `FUN_80001fb4` (que llama a **osEPiStartDma**).
  → **el DMA de carga del asset NUNCA se ejecutaba** → buffer 0x80089518 vacío → s6=0 → crash.
- **FIX**: fusionar las 4 en una `FUN_80001f30` (vram 0x80001F30, size 0xB8 = 0x80001F30-0x80001FE8)
  en `us_ghidra.syms.toml` (commit `8387efd`). El caller `FUN_80001fe8` ahora alcanza el DMA completo.
- **Por qué fix_fallthroughs.py no lo cazó**: su heurística `has_ret = any("return;")` es demasiado
  amplia — FUN_80001f30 tiene 22 `return;` (early jr ra en ramas), así que la saltaba. (He dejado la
  heurística conservadora y he resuelto el caso concreto con el merge en la syms.)
- **VERIFICADO (progreso)**: tras el merge el DMA corre (postea a 0x8005c268, src=5=Pi), el buffer
  `0x80089518` tiene datos reales (chunk 2 = `0x9ce78ba2`) y **s6 = 0x55dd4** (tamaño descomprimido
  correcto). Antes s6=0. El boot avanza más.

### 6.8 SIGUIENTE BLOQUEANTE (tras el merge) — CORRECCIÓN: el chunk setup es correcto; el decode corrompe base/s2

- **CORRECCIÓN de mi error de lectura**: `MEM_W(0, 0x8005D0xx)` con literal NO sign-extended calcula
  `addr + 0x80000000` (fuera de RDRAM) → leía basura. Hay que usar `MEM_W(0, 0xFFFFFFFF8005D0xx)`.
  Con las lecturas CORRECTAS, el estado del chunk ES correcto:
  - `5D014 = 0x4e69a8`, `5D010 = 0x4e69a8` (fuente, correcta)
  - `5D020 = 8188 (0x1FFC)` (contador de chunk, decrementando bien desde 0x2000)
  - `s6 = 0x55dd4` (tamaño descomprimido, correcto), `s2 = 0x80089518` (buffer), `s1 = 0x80107830` (salida)
- **PERO** el decode del PRIMER bloque corrompe `base(v1) = 2` y `s2 = 0` (valores pequeños) → crash.
  Solo se procesa 1 bloque (1 HDR print). El DMA carga el asset y el chunk setup es correcto, pero el
  **bucle de decode LZSS corrompe base/s2** → parece OTRA función dividida por Ghidra en la cadena del
  decode, o una mis-compilación profunda del decode de FUN_80003824.
- **fix_fallthroughs agresivo (259 cadenas, racer-proven) NO arregló** este crash (el crash sigue en
  FUN_80003824, no en una función dividida de la cadena). Se revirtió (dejó el estado limpio con el
  merge de FUN_80001f30).
- **A investigar**: por qué el decode corrompe base/s2 a valores pequeños. Comparar el recompilado vs
  original del bucle de decode (0x80003918-0x80003C98) — posible mis-compilación o función dividida
  dentro de FUN_80003824 que el recompilador no fusiona.

### 6.9 MECANISMO EXACTO del crash (2026-09-10, instrumentado con lecturas corregidas)

- **El merge de FUN_80001f30 FUNCIONA**: `osEPiStartDma_recomp` lee `dramAddr=0x80089518` (correcto),
  `devAddr=0xb04e69a8` (ROM, correcto), `size=0x2000`, `mq=0x8005c268` → **el asset se carga bien**
  (s6=0x55dd4, chunk counter 0x1FFC, source 0x4e69a8).
- **El crash es un CLOBBER del stack del reload**: `FUN_80003D3C` (reload) guarda `a0=0x80089518` en
  `sp+0x18 = RDRAM 0x8005BE18`, llama a la cadena del DMA, y al restaurar lee **0x0** (clobbered).
  → `FUN_80003D3C` devuelve 0 → `s2 = 0` → `MEM_BU(0,0)` = rdram-0x80000000+3 → SIGSEGV.
- **Confirmado**: la traza LIT muestra s2 avanzando `0x8008b511..0x8008b517` con 5D020 `7..1`, y al
  llegar a 5D020=1 el reload dispara (5D020→8192 correcto) pero `s2=0x0` (a0 restaurado = 0).
- **La cadena DMA clobberea 0x8005BE18**: los frames del stack (FUN_80003db4 sp-0x18, FUN_80001fe8
  sp-0x20, FUN_80001f30 sp-0x20, osEPiStartDma 0x800304F0, osSendMesg 0x800266B0) usan `ctx->r29`.
  Alguno escribe en `sp+0x30` (=0x8005BE18) → pisa el `a0` guardado por FUN_80003D3C.
- **NO es la cache op** (FUN_80028A90: el `cache` es no-op en N64Recomp). Es la cadena
  osEPiStartDma/osSendMesg recompiladas (posible frame grande con offset positivo) o un solapamiento
  de frames del stack recompilado.
- **A investigar**: el frame del stack de `osEPiStartDma` (0x800304F0) y `osSendMesg` (0x800266B0)
  recompilados — por qué escriben en `sp+0x30` (0x8005BE18). Comparar el recompilado vs original.
- **Alternativa**: el problema es que la DMA recompilada (async-callback del juego, FUN_80001f30)
  pisa el stack. Considerar que el juego usa `osEPiStartDma` con un `OSIoMesg` en 0x8005D280 + cola
  0x8005c268, y el runtime lo hace SÍNCRONO (do_dma/do_rom_read). Si la recompilación de
  osEPiStartDma/osSendMesg tiene un frame bug, ese es el fix.

### 6.10 REFINADO (2026-09-10) — el clobber NO es de las funciones recompiladas de la cadena

- Verificado con precisión (extracción de cuerpos): `FUN_80003db4` solo accede a `sp+0x14` (frame 0x18,
  correcto). `FUN_80001fe8`/`FUN_80001f30` (merged) acceden a sp+0x30..0x34 pero sus sp están por debajo
  de 0x8005BE18 (0x8005BDC8/0x8005BDA8 + 0x30 = 0x8005BDF8/0x8005BDD8), así que NO alcanzan 0x8005BE18.
- `do_rom_read` escribe en `ram_address` (0x80089518), correcto (0x80089518..0x8008B518), NO en 0x8005BE18.
- `0x800266B0` es `osRecvMesg` (runtime, HOST stack) y `osEPiStartDma` es `osEPiStartDma_recomp`
  (runtime, HOST stack). Ambos usan la pila del host, NO la recompilada (ctx->r29).
- **CONCLUYENDO**: el clobber de 0x8005BE18 (a0 guardado por FUN_80003D3C) proviene de la **vía de runtime
  del DMA** (osEPiStartDma_recomp/osRecvMesg_recomp + do_dma) o de su **interacción con el lock de
  concurrencia** (mi fix: al hacer osRecvMesg la cola está vacía → bloquea → suelta el game lock → otro
  thread corre y pisa el stack del thread 5). El watchpoint de gdb cae en syscall de pthread (park),
  no en un write del recompilado → confirma que el clobber ocurre durante el park/unpark del threading.
- **Siguiente**: (a) verificar si osRecvMesg bloquea (cola 0x8005c268 vacía en el momento del reload)
  y si el game-lock/otro-thread pisa el stack; (b) si es el lock de concurrencia, reconsiderar su alcance
  (tal vez no debe liberarse en el park de osRecvMesg, o el stack del thread 5 debe protegerse).
