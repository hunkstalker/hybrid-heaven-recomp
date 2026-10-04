# RETOMAR — handoff (2026-10-04)

> Handoff corto. **`main` = `v0.6.2`** (release ya publicada). **TAREA ACTUAL: fix de input
> "mantener pulsado disparaba la acción repetidamente" — HECHO y VALIDADO en Windows.**
> Detalle (medido/inferido): `notes/2026-10-04-fix-input-flanco-botones-accion.md`.
> **Otra tarea (otra rama, NO mezclar):** interpolación/desbloquear FPS en
> **`fps-interpolacion-tagging`** (ver §"Otras ramas").
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Tarea actual — fix de input (acciones por flanco + lectura unificada)

**Hecho y VALIDADO en Windows (2026-10-04):**

- Los flujos propios del menú leían aceptar/borrar (A/START/X) en vías **inconsistentes** (estado
  mantenido de la ranura o `hh_input_button_down`, que **no incluye el mando**). Efectos: (1) al
  confirmar CONTINUAR con A/START aún pulsada se cargaba el **primer slot** sin ver el `DATA LOAD`;
  (2) **X del mando no borraba** slots (solo la tecla H).
- Fix: **una sola vía** para las acciones, `hh_input_action_edges()` (`input.cpp`): **teclado + ratón +
  mando + inyección** con **flanco estricto con rearme** (mantener no repite). Las **direcciones**
  conservan su auto-repeat. Anti-rebote de entrada por seed en el hook de apertura
  (`hh_input_action_seed`); retirados los bloqueos por ms `load/save_input_blocked`.
- Verificado Windows: CONTINUAR no carga con A/START mantenida; GUARDAR no autoguarda/autoborra;
  **borrar con X del mando OK**; teclado y mando a la vez; direcciones siguen repitiendo. Linux compila.
- Detalle: `notes/2026-10-04-fix-input-flanco-botones-accion.md`.

### Pendiente

1. Commit del fix + docs (si el mantenedor no lo ha hecho ya).

## Otras ramas

- **`fps-interpolacion-tagging`** (2 commits `wip` + 1 `docs` + fix identidad lógica, **sin mergear**):
  tagging de interpolación por hook del port. Detalle y siguiente paso:
  `notes/2026-10-03-fps-tagging-dobj-y-handoff.md`. Incluye
  `patches/rt64/hh-interpolation-tagging.patch` (cambios del submódulo `lib/rt64` como patch).

## Árbol

- `main` = `v0.6.2` + el fix de input, **submódulos limpios** en sus pins.
- Instrumentación reutilizable (`HH_PAIRING`, `HH_MTXGROUP`) y banco headless (Xvfb+lavapipe): nota §4.

## Pitfalls (NO repetir)

- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios.
- **La vista no valida** (el mantenedor vio "mejoras" con un `.exe` viejo): validar por métrica.
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
- **Botones vs direcciones**: los botones de acción van por **flanco**; el **auto-repeat es solo para
  direcciones**. No leer acciones en estado mantenido (bug 2026-10-04).
