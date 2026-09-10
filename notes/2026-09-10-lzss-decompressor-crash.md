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

## 6. INVESTIGACIÓN INTERNET (2026-09-10) — HALLAZGO CLAVE: el asset es LZKN64

### 6.1 El asset 0x4E69A8 es LZKN64, NO el LZSS custom de FUN_80003824

- **Goemon's `lzkn64_decompress` (ya en `tools/lzkn64/`) DECODIFICA correctamente el asset**:
```python
from lzkn64 import decompress
data = rom[0x4E69A8:0x4E69A8+0x55DD4]
out = decompress(data)   # 564464 bytes (0x89CF0) de codigo MIPS valido
```
- El output es **codigo MIPS coherente** (verificado con capstone en offsets 0x0, 0x1000, 0x40000:
  `addiu sp,sp,-0x18; sw ra,0x14(sp); jal ...` = prologo valido; ramas a direcciones validas 0x800xxxxx).
- La firma LZKN64: header de 4 bytes = `compressed_size` (0x00055dd4), y el stream empieza en offset 4
  (`input_pos = 4` en el codigo de Goemon).

### 6.2 FUN_80003824 es un descompresor de la MISMA familia LZKN64 (mismos rangos de comando)

- FUN_80003824 usa los **mismos rangos de comando** que LZKN64:
  `0x00-0x7F` sliding-window copy, `0x80-0x9F` raw copy, `0xA0-0xDF` RLE any-value,
  `0xE0-0xFE` RLE short-zero, `0xFF` RLE long-zero.
- DIFERENCIA: FUN_80003824 usa offset de **10 bits** en el sliding-window
  (`s3 = (s0<<8|next) & 0x3FF`, `length = (s0>>2)+2`), mientras LZKN64 (Goemon) usa offset de
  **8 bits** (`offset = next_byte & 0x7FF`). → variantes distintas ("LZSS 5"/"LZSS 7" del cargador).
- El routing (FUN_8000469C) SOLO tiene 2 caminos: `*(tabla+0xC) < 0` → FUN_80003824 (comprimido),
  `>= 0` → DMA directo (sin comprimir). No hay un 3er descompresor.

### 6.3 Causa del crash (chunk-reload)

- FUN_80003824 lee el stream en **chunks de 0x2000 bytes** via DMA (FUN_80003DB4 → FUN_80001FE8 →
  FUN_80001F30). Al agotarse un chunk, FUN_80003D3C (contador 0x8006D020 == 1) llama a FUN_80003DB4
  para cargar el siguiente y resetea s2 a 0x80089518.
- El crash es **s2 = 0xc** en el bloque 513 (frontera del 1er chunk 0x2000): el reload del chunk NO
  se produjo (s2 no volvió a 0x80089518) y el puntero se corrompió. El estado global del descompresor
  (0x8006D014=0x18, 0x8006D020=0x90, 0x8006D01C=0xffffb8ba en la ENTRY) parece mal inicializado.

### 6.4 Próximo paso concreto

1. El estado del chunk (0x8006D000) no está bien inicializado al entrar en FUN_80003824, O la cadena
   de DMA (FUN_80003DB4/0x80001FE8/0x80001F30) no devuelve el chunk correcto en el 2º reload.
2. Comparar la cadena DMA recompilada vs original (0x80001F30 llama a 0x80028A90/0x80030640/0x800306C0
   = PI DMA del runtime). Verificar que el 2º reload lee de ROM[0x4E69A8+0x2000] correctamente.
3. Alternativa (oráculo del TODO): el output de `lzkn64.decompress(asset)` (564464 bytes de MIPS
   valido) sirve como **oráculo** para validar la salida del descompresor recompilado.
