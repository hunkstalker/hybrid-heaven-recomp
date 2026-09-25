# Fix: cambiar de idioma aceleraba el juego (reapply sobre RDRAM)

> Evidencia del bug reportado en `RETOMAR.md §BUG CONOCIDO` (vi 30 → 60 al cambiar idioma).
> Estado: **resuelto y validado headless** (2026-09-25). Pendiente: confirmar en Windows.

## Síntoma y medición

Con `HH_FPS=1`, al ciclar el idioma (`HH_LANG_CYCLE_AT=15`), RT64 `viOriginalRate` pasaba de **30 a 60**
y `present` de ~29 a ~54. Control sin ciclo (`HH_FPS=1`): estable en `present≈29.5 / vi=30` durante 55 s.
→ El salto lo causa el cambio de idioma, no la progresión natural del arranque (medido, no inferido).

## Aislamiento (A/B)

Se añadió el knob `HH_LANG_REAPPLY=0` para saltar `hh_trans_reapply_language` en `text_set_language`.
- `HH_LANG_REAPPLY=0` + ciclo: `present≈29.5 / vi=30` en todo momento → **el culpable es el reapply**.
- default + ciclo: reproduce el 30 → 60.

## Causa raíz

`hh_trans_reapply_language` (`src/subsystems/trans_cache.cpp`) **reescribía el módulo entero** en RDRAM
desde el cache/ROM al cambiar de idioma. Pero el juego **modifica en caliente** las regiones que el
loader `trans` escribió. Diagnóstico `HH_LANG_DIAG=1` (comparaba RDRAM actual contra el original):

| src | dst | len | bytes distintos |
|---|---|---|---|
| `005F1190` | `801BF1A0` | 68432 | **241** (relocalización de código) |
| `0068BF26` | `803837E0` | 42464 | **33889** (buffer de trabajo) |
| `004E69A8` | `80107830` | 564464 | 7 |
| estáticos (varios) | — | — | 0 |

Al reescribir el módulo completo se pisaban esas modificaciones (relocs del módulo de código y el
buffer de trabajo) → el juego reprogramaba el VI a 60 Hz ~11 s después.

## Fix

`hh_trans_reapply_language` ya no escribe el módulo completo: reescribe **solo las posiciones cuyo
contenido actual coincide con el testigo `written`** (los bytes que el port escribió en la carga, con
la traducción ya aplicada). Las posiciones que el juego cambió se respetan.

- `Loaded` guarda `written` (orden guest) por módulo; se captura leyendo RDRAM tras cada carga.
- En el reapply: `next = traducir(original)`, `cur = RDRAM`; si `cur[k] == written[k]`, se aplica
  `next[k]` y se actualiza el testigo; si no, se salta (el juego lo tocó).
- `remember_loaded` **poda** entradas que solapan el rango de una carga nueva (región reutilizada).
- Tope de memoria `kWrittenCap` = 32 MB para los testigos (se liberan los más antiguos si se pasa).
- Knob `HH_LANG_REAPPLY=0` (diagnóstico A/B). Se retiró el `HH_LANG_DIAG`.

## Validación headless

- `HH_FPS=1 HH_LANG=en HH_LANG_CYCLE_AT=15`: tras el ciclo, `vi=30` y `present≈29.5` estables 25 s.
- `HH_FPS=1 HH_LANG=es HH_LANG_CYCLE_AT=15` (id → `ca` sin tabla → vuelve a inglés): estable igual.
- `HH_TEXT_TRACE=1`: el reapply traduce/restaura las cadenas (p. ej. el módulo `005F1190` lleva 62
  cadenas); el testigo no impide actualizar el texto.
- Verificado en RDRAM (`HH_DUMP_RDRAM_AT=17`, dump word-swapped → bswap32 y buscar): tras el cambio
  aparecen `SELECCIONA`×2, `INICIAR`×4, `NUEVA PARTIDA`×3, `CONTINUAR`×3, `MODO LUCHA`×3, `AJUSTES`×5,
  `DIFICULTAD`×2, y **desaparecen** `GAME START`/`NEW GAME`/`PLEASE SELECT`. El reapply sí actualiza el
  texto in-game; el fallo era pisar los cambios del juego, no dejar de traducir.

## Criterio de salida

Confirmar en Windows (build normal) que el menú cambia de idioma **sin acelerarse**, y que el texto
in-game cambia con F5. Pendiente de la validación visual del mantenedor.
