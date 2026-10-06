# Diálogos ruta B: reubicación de bloques de guion a una arena (longitud libre)

> Sesión 2026-10-06 (continúa `notes/2026-10-06-dialogos-guion-punteros-y-ruta-a.md`). Implementa la
> **ruta B** acordada: en vez de encajar el español/catalán en el bloque inglés, se **reconstruyen los
> bloques de guion** con longitud libre y se **reubican** en una arena, parcheando los punteros.

## 1. Hecho

- `src/subsystems/text.cpp`: `hh::text_rebuild_euc_block(in,len,out,changed)` — recorre un bloque de
  guion copiando bytes y sustituyendo las tiras EUC que casen con una clave por su traducción **sin
  límite de longitud** (los opcodes `f3/f8/fa/fd` se copian tal cual).
- `src/subsystems/trans_cache.cpp`: `rebuild_dialogue_blocks`:
  1. localiza las **instancias de puntero** del módulo (u32 BE en `[dst, dst+len)` que apuntan a una
     tira de texto);
  2. para cada bloque (de un puntero al siguiente), si **no tiene refs absolutas internas**, lo
     reconstruye y lo **escribe en la arena**; parchea **todas** las instancias de su puntero;
  3. si tiene refs internas → **no se mueve** (se queda con la ruta A in-place).
- **Arena**: `0x80600000` (físico `0x600000`), 1 MB, bump. Elección medida con un volcado RDRAM
  (`HH_DUMP_RDRAM_AT`): `0x400000-0x7A0000` está a cero (el juego usa ~4 MB; el HUD usa
  `0x7A0000`/`0x7C0000`).
- **Reaplicación en vivo (F5)**: si la ruta B está activa, `hh_trans_reapply_language` **reinicia la
  arena** y reconstruye los bloques de **todos** los módulos cargados (reparto consistente).
- **Gate**: `HH_DLG_BLOCK=1` (por defecto **off**; la ruta A queda como predeterminada/fallback).

## 2. Validación

- Compila (`cmake --build build/linux -j`).
- Simulación offline (espejo Python) sobre `módulo 12`: bloque `0x340C` reubicado a `0x80600000`
  (texto libre: `Sr.Diaz, puede que ya lo sepa, pero / hay una cosa de la que debo / informarle.`),
  puntero `0x033F8` parcheado; los demás bloques se saltan por refs internas.
- **Pendiente**: validación **visual en Windows** con `HH_LANG=es HH_DLG_BLOCK=1` en el primer diálogo.

## 3. Riesgos / pendiente

- El puntero se parchea en los **datos** del módulo; se asume que el código lo lee de ahí (la tabla
  parece leerse como datos). Confirmar en la prueba visual.
- Arena **sin liberar**: al recargar módulos se acumula (tope 1 MB → fallback a ruta A). Endurecer el
  asignador (por módulo) antes de dar B por definitiva.
- Bloques con **refs internas** (saltos) siguen con ruta A (limitada). Migrarlos exige reubicar y
  reescribir esas refs (siguiente paso).
- Los valores en `assets/lang/es.txt` ya pueden **superar** la longitud por línea; sin `HH_DLG_BLOCK`
  (ruta A) esas líneas concretas no caben y se deja el inglés.
