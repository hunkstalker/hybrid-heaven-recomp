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
