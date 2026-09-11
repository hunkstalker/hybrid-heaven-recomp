# Arquitectura — Hybrid Heaven: Recompiled

> Documento vivo. Modelo técnico canónico del port. Las decisiones se registran en `docs/adr/`.
> El estado y las tareas están en `../PROYECTO.md` y `../TODO.md`. El histórico, en `../notes/`.

## 1. Stack

| Capa | Elección |
|---|---|
| Recompilación | **N64Recomp** (MIPS → C) |
| Runtime libultra | **N64ModernRuntime** (`ultramodern` + `librecomp`) |
| Render | **RT64** (Vulkan/D3D12/Metal), microcode **F3DEX2 fifo 2.06** |
| Input / ventana | SDL2 |
| Plataformas | Windows + Linux + Steam Deck (mismo código) |
| Símbolos | **Ghidra** (N64LoaderWV) → `config/us_ghidra.syms.toml` |

Sin decompilación de referencia: los límites de función dependen de Ghidra y de un
validador propio (ver `../TODO.md`, fundación 3).

## 2. Modelo unificado: **imagen plana + módulos**

El boot es una **imagen de código plana**; el resto del juego (diálogos, combate, escenas, etc.)
llega como **módulos de código que se descomprimen de la ROM a RAM y se ejecutan** vía el cargador
`trans` (`seg_RomDecode_sep`, `trans_to_malloc64_sep`). No es "código plano + overlays de fase":
es **una imagen + N módulos con origen (asset/Nisitenma) y base RAM conocidos**.

Consecuencia: la recompilación estática necesita **pre-recompilar cada módulo** y resolver sus
funciones en runtime por `(origen, base)`. Decisión **aceptada** (ADR 0001): pre-recompilar y
registrar en la base determinista.

### 2.1 Contrato del módulo (medido 2026-09-11)

- El módulo es **MIPS autoligado** en `base+offset` (entry en offset 0), con **direcciones
  absolutas** (llama al código plano por `jal 0x8000xxxx` y se autorreferencia); **sin relocs**.
- El salto sale de un **descriptor** en heap con `+0x1C = base` (lo consume `FUN_80005270`).
- Módulo de boot = **Nisitenma índice 7**: `ROM 0x4E69A8`, comprimido `0x55DD4`, descomprimido
  `0x89DB0` (~564 KB MIPS), CRC32 `0xA9213032`, base `0x80107830` (determinista en 3 runs).
- Detalle: `../notes/2026-09-11-modelo-modulos-trans.md`.

## 3. Mapa de memoria (a confirmar en runtime cuando aplique)

| Región | Detalle |
|---|---|
| Código principal plano | vram `0x80000400`, tamaño sección `0x4E5B40`; entry `0x80000400` |
| Mapeo vram↔ROM | ROM retail (header `0xC00`): `rom_off = vram - 0x7FFFF400` |
| Directorio `trans` | RDRAM física `0x8DFC0` (vista CPU `0x8008DFC0`), 0x100 entradas × 8 B (`id16`, `base32`) |
| Stack principal (entry) | `SP = 0x80057BD0` |
| Thread 5 (game loop) | pila con tope `0x8005BF30` |
| Threads RSP 16-19 | pilas: 16→`0x80055BD0`, 17→`0x80053BD0`, 18→`0x80051BD0`, 19→`0x8004FBD0` |
| Buffer de chunk `trans` | `0x80089518` (chunks de `0x2000`) |
| Salida de descompresión | p. ej. `0x80107830` (base de módulo; ver ADR 0001) |
| Globales del descompresor | `0x8005D010..0x8005D026` (fuente, base, restante, fin, contador, stride) |

> Nota: los globales del descompresor están en **`0x8005D0xx`** (no `0x8006D0xx`). En el código
> recompilado, `MEM_W(0, 0x8005D0xx)` con literal NO sign-extended lee fuera de RDRAM; usar
> `MEM_W(0, 0xFFFFFFFF8005D0xx)`.

## 4. Compresión y carga (`trans`)

- Tabla de ficheros **Nisitenma-Ichigo** (común a los N64 de Konami; la usa `tools/rommy.py`).
  Entradas de 4 B BE: bits [0-30] = offset ROM, bit 31 = comprimido (LZKN64). Termina en `0x00000000`.
- **LZKN64** resuelto y reutilizable (`tools/lzkn64`, `rommy.py`). El descompresor del juego
  (`FUN_80003824`) es de la misma familia pero con offset de 10 bits.
- **Confirmado (2026-09-11)**: `lzkn64` descomprime **correctamente** el módulo idx 7 (CRC32
  `0xA9213032`, 564464 B) → `tools/setup_module.py` lo extrae de la ROM **sin ejecutar el juego**
  (determinista). Una nota histórica que decía que `lzkn64` daba "basura" era **errónea**.
- Variantes **`LZSS 5`/`LZSS 7`** del `trans`: por caracterizar (otros módulos podrían usarlas).
- El código plano NO está comprimido; se comprimen assets y módulos de código.

## 5. Contrato de runtime (N64ModernRuntime) y parches del port

- **Modelo single-CPU**: el N64 tiene una CPU; el runtime debe serializar los hilos de juego.
- Hilos, message queues, eventos (VI/AI/SP/DP/SI/PI) y VI timing vienen del runtime.
- **Parches del port (deben ser mínimos y documentados):**
  - `run_next_thread_and_wait` hace *idle* en mensajes externos si la `running_queue` está vacía
    (patrón racer). Evita el abort "No threads left to run".
  - Lock global single-CPU (`acquire_game_lock`/`release_game_lock`) — **reevaluar**; puede
    enmascarar comportamiento (ver `../TODO.md`, fundación 4).
  - Revertida la entrega directa de mensajes externos a RDRAM desde hilos I/O (se usa el
    `external_messages` de upstream).
- **Pendiente para render**: wiring de eventos (`osSetEventMesg` con IDs estándar) + routing de
  tareas RSP + `loadUCodeGBI`.

## 6. Toolchain de recompilación

- Config activa: `config/game_unified.toml` → `us_ghidra.syms.toml` → `RecompiledFuncs_unified/`.
- Recompilador: `toolchain/src/N64Recomp/build_recomp/N64Recomp`.
- Port: `port/HybridHeavenRecomp/` (CMake globs `RecompiledFuncs/funcs_*.c`).
- Post-paso obligatorio: `tools/analysis/fix_fallthroughs.py`.
- Quirk conocido: añadir la declaración `osYieldThread_recomp` a `funcs.h` tras cada regen.
- Regla: **nunca editar a mano el C generado**; todo fix va a la syms/config (ver ADR futuro).

## 7. Preguntas abiertas (bloquean el diseño)

1. ¿Las bases RAM de los módulos son **deterministas**? (`init_trans 0x80018420`, tabla `0x8009EBD4`).
2. ¿Cuál es el **contrato del módulo** (cómo se referencian sus funciones: `base+offset`? tabla?
   relocs internas?).
3. ¿Qué assets de la tabla Nisitenma son **código ejecutable** vs datos?
4. ¿El lock single-CPU es necesario con el modelo upstream + parches de racer?

Detalle y evidencia: `../notes/2026-09-10-*.md` y `../notes/2026-09-08-overlay-directory.md`.
