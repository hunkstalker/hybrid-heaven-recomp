# RETOMAR — handoff (2026-10-04)

> Handoff corto. **`main` = `v0.6.2`** (release ya publicada). **TAREA ACTUAL: fix de input
> "mantener pulsado disparaba la acción repetidamente" — HECHO y VALIDADO en Windows.**
> Detalle (medido/inferido): `notes/2026-10-04-fix-input-flanco-botones-accion.md`.
> **Otra tarea (otra rama, NO mezclar):** interpolación/desbloquear FPS en
> **`fps-interpolacion-tagging`** (ver §"Otras ramas").
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Tarea actual — fix de input (botones de acción por flanco)

**Hecho y VALIDADO en Windows (2026-10-04):**

- Los flujos propios del menú (`feed_load_flow`/`feed_save_flow`) leían aceptar/borrar
  (A/START/X) en **estado mantenido** (`hh_input_button_down`, nivel) → mantener pulsado repetía la
  acción. Efecto reportado: al confirmar CONTINUAR con A/START aún pulsada, se cargaba el **primer
  slot** sin ver el `DATA LOAD`.
- Fix: **flanco estricto con rearme** para los botones de acción (`pressed = btn & ~prev`, que ya
  cubre teclado **y** mando). Las **direcciones** conservan su auto-repeat. Anti-rebote de entrada por
  *seed* (`g_load_seed_input`/`g_save_seed_input`); retirados los bloqueos por ms
  `load/save_input_blocked`. `open_load_game`/`open_save_game` devuelven "apertura nueva".
- Verificado: mantener A/START en CONTINUAR → se ve `DATA LOAD`; en GUARDAR mantener A no autoguarda
  y mantener X no autoborra; direcciones siguen repitiendo. Linux compila.

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
