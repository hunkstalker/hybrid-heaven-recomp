# 2026-09-20 — A/B binario del bloqueo per-file: el freeze es de BOOT (no de la transición)

> Nota de sesión (evidencia). Continúa `2026-09-20-pipeline-per-file-estado.md` §15-18.
> No operativa: el método está en `docs/`; el handoff, en `../RETOMAR.md`.

## 1. Resumen (reencuadre del bloqueante)

El bloqueo **no** es "la transición al intro/CaC no dispara". Con A/B binario (build per-file nuevo
vs build pre-reset `8fd6ddf`, mismo runtime/replay) queda claro que el build per-file **se congela
durante el boot desatendido**, justo después de cargar `file_024` y unos assets de `trans`
(`src=0005D280 -> 801B6600`, t≈6 s). A partir de ahí el estado del juego queda **totalmente
congelado**; el bucle principal sigue corriendo y renderizando (VI sube hasta 1800+), pero la lógica
no avanza.

El build viejo (heurístico) recorre el mismo boot y **sí avanza**: en `notes/` se midió que carga
`file_025/026/100` (`src=005FBEC6/0060F476/006DCA78`) en t≈9.1 s y luego explora. El nuevo no llega.

**Dato clave**: el freeze **se reproduce sin replay** (`HH_REPLAY` sin definir), a los ~6 s. Luego no
es input/replay ni cadencia: es código del boot.

## 2. Método (receta reproducible)

```sh
# Binario nuevo: port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"
# Binario viejo: /tmp/opencode/oldb/port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
SDL_AUDIODRIVER=dummy HH_HANG_FORCE=70 HH_HANG_SECS=70 timeout 80 "./Hybrid Heaven Recomp"
```

Sin `HH_REPLAY`. Artefactos: `hh.log` (`[trans] load ...` del loader nativo de assets) y
`hh_state.log` (snapshots cada ~3 s). `[trans] load` es quien revela la progresión real (los code
files van por `[hh-load]` con `HH_DEBUG_LOADS=1`).

## 3. Evidencia A/B (sin replay, 70 s)

`hh_state.log` (primer snapshot vs últimos):

| | nuevo (70 s) | viejo (70 s) |
|---|---|---|
| `g2` (`0x801D8CE8`) | **0 siempre** | 0 → `0xAFB90010` → `1` |
| `cnt30` (`0x801D8DA8`) | **0 siempre** | 0 → `0x10410009` → `0x1D` → `0xAF` |
| `objCB` (`0x8024AB14`) | `F0F0FBFE` (basura) siempre | se reescribe a `0x801CB71C` |
| último `[trans] load` | `0005D280 -> 801B6600` (t≈6 s) | decenas de assets de gameplay (t≈70 s) |

El nuevo tiene 10 snapshots **idénticos** en 70 s: lógica detenida. El viejo recorre el boot/night-city
y las pantallas siguientes.

### Traza de escritura de `0x8024AB14` (`HH_WATCH_ADDR`)

Ambos builds ejecutan **las mismas 16 escrituras** hasta t≈2.83 (mismos valores: `...F0F0FBFE`).
Después:
- viejo: sigue (`t=6.5/6.6/9.5`) y en `t=9.669` escribe `0x801CB71C` (callback real).
- nuevo: **no vuelve a tocar la dirección**.

Es decir: la divergencia es *entre* t≈2.8 y t≈9.1, no en un valor concreto aislado.

### Calltrace (`HH_CALLTRACE`), 10 s

- nuevo: 1.65 M de llamadas; viejo: 110 M. El nuevo pasa el resto del tiempo en un bucle corto
  (frame limiter / dispatch). El primer índice distinto es 682, justo tras `0x80133AAC` (ya anotado en
  §13 de la nota anterior): el nuevo ejecuta **una iteración extra** del grupo de scheduling
  `800266b0 80032360 80028a10 800349d0 80026300 8002bf90` antes del broadcast `0x80000A0C`. Es
  divergencia de *scheduling* temprana, probablemente no la causa raíz.

### Descartado en esta ronda

- **`[MQDROP]`** (`mq=800CE920`): el nuevo descarta 2 mensajes externos que el viejo no. Forzar
  `requeue_ai/requeue_vi=true` **elimina el drop pero el freeze sigue** → síntoma, no causa.
- **Yield hook** (`0x80001A88`): el viejo *no* lo tiene y avanza; el nuevo *sí* y se congela.
  Desactivarlo (`HH_NO_YIELD`, experimento local) **no cambia el freeze** → no es el yield.
- **Input/replay**: sin replay también se congela.
- **Lookups**: sin `Failed to find`/`hh_missing` en la ventana del freeze.

## 4. Fronteras y residente (hallazgos laterales)

- El **residente `.text` sigue siendo el plano viejo** (`us_ghidra.syms.toml`): `size = 0x4E5B40`,
  vram `0x80000400..0x804E5F40` — **incluye los rangos de overlay**. `register_flat_code` solo salta
  las secciones relocalizables, no las funciones planas que caen en ventanas de overlay. Es la deuda
  de Fase A.1 de `../RETOMAR.md` (residente con Ghidra per-file excluyendo overlays).
- Al comparar las syms viejas (`us_module*`) con las nuevas (`.file_NN`), las viejas son **supersets
  con datos-como-código**: p.ej. `file_055` acaba en `0x80384354` size **`0x9A6C`** (basura/datos) en
  el viejo vs `0xC` en el nuevo; y el viejo divide en 20 funciones lo que el nuevo fusiona en 12. Las
  fronteras nuevas parecen **más correctas**.
- La divergencia no es una función ausente: no hay lookup miss; todo resuelve.

## 5. Hipótesis viva y siguiente paso

El código que debe ejecutar tras cargar `file_024` y que dispara el siguiente paso (los
`FUN_8001f160`/`FUN_8000469c`/`FUN_80015798` que en el viejo escriben `0x8024AB14` a t≈6.5-9.7) **no
se ejecuta** en el nuevo. Como residente y `file_008` están (según §12) byte-idénticos, el candidato
es el **código recompilado de `file_055`/`file_024`** o la **cadencia/timing del registro por loader**.

Siguiente:
1. **Instrumentar `func_801BF9A4` / `func_801C0C44`** (file 24, escriben `g2`/`cnt30`) y sus
   callers: ¿se invocan? Si no, trazar la función *anterior* que debería invocarlos (comparar con el
   viejo por `HH_CALLTRACE` alineado tras el `[trans] load` de `file_024`).
2. **Fase A.1 real**: regenerar el residente con Ghidra per-file excluyendo overlays (quitar el
   `.text` plano de `us_ghidra.syms.toml`). Es lo único estructural que sigue "híbrido".
3. Si el freeze persiste, **A/B de `file_055`/`file_024`**: recompilar con las fronteras viejas de
   esas dos secciones y ver si el boot avanza.

## 6. Instrumentación usada (ya existente)

| Var | Uso |
|---|---|
| `HH_DEBUG_LOADS=1` | `[hh-load]` por code file (id, dest, evict) |
| `HH_WATCH_ADDR`+`HH_WATCH_SIZE` | escrituras a una vaddr; `ret` mapeable con `addr2line` |
| `HH_CALLTRACE=<ruta>` | stream u32 LE de cada `get_function` (todos los calls) |
| `HH_HANG_FORCE/SECS` | volcado forzado (hilo/ctx + `hh_state.log`) |
| `HH_STATE_SECS` | cadencia de snapshots de estado |
