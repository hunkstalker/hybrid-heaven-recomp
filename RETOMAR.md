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

### Fix de remapeo de teclado en CONTROLES (#17) — HECHO (2026-10-04)

- Asignar teclas (números, etc.) no persistía. Causas: los **defaults** de teclado se reinyectaban al
  cargar y ganaban a la tecla reasignada; teclas cuyo nombre rompe el INI (`; = #`) se perdían; la
  fuente no dibuja `[ ] \ '`.
- Fix (`input.cpp`): `[keys]` es **fuente autoritativa** del teclado; nombres seguros `sc_<n>` para el
  INI; **solo se mapean teclas dibujables** (`glyph_value` + `menu_char`, incluye `¡¿` y acentos); el
  rótulo se muestra **según la layout del SO** (`¡` en teclado ES), guardando por **scancode**.
- Detalle: `notes/2026-10-04-fix-remapeo-teclado-persistencia.md`. Pendiente validar en Windows.

### Pendiente

1. Commit del fix + docs (si el mantenedor no lo ha hecho ya).
2. Validar en Windows el remapeo de teclado (números + teclas del layout ES).

## Rama `fps-interpolacion-tagging` — estado y plan de integración

> **Esta sección la añadió la sesión 2026-10-04** (la que trabajó en esa rama) para dejar aquí, en
> `main`, el contexto del estado de la interpolación y **cómo integrarla**. No mezclar con el fix de
> input de `main`.

**Estado de la rama** (28 commits, **sin mergear**): arregla artefactos de la **interpolación de
frames** a alta tasa. Validado en Windows **con flags** (`HH_MTXGROUP=1`/`HH_EMIT_TAG=1`; por defecto
la rama no cambia nada). Contenido:

- **Sesgado de cámara RESUELTO** (`46b3f0d`, port-only): `gEXMatrixGroup` de PROYECCIÓN con generación.
- **Identidad por nodos** (`stable_slot` + generación de cámara): arreglados **huesos** del PJ, **#6**
  (gate de escala, en RT64), **#8** (puertas), minas/láseres.
- **A2.2d CERRADA** (efectos/2D pasada 2, no-bug): los efectos los dibuja `C768` y **materializa**;
  capturas de minas/láser/partículas/puerta = **transitorios**, no fallos.
- **Partículas del heal = no-bug** (asset original; coincide con el emulador).
- Bug **latente** de walkers de DL corregido (`a8212b3`).
- **Instrumentación**: RT64 vía `patches/rt64/hh-interpolation-tagging.patch` (gates, contadores,
  pairing) y del port (`HH_MTXGROUP`, `HH_EMIT_TAG`, `HH_PAIRING`, `HH_PAIRING_DUMP`, …). **`lib/rt64`
  en `main` está limpio**; en la rama el patch se aplica aparte (`docs/workflows.md §1.2`).
- Handoffs/notas: `notes/2026-10-04-fps-a2-2d-emisores-y-capturas-transitorias.md`,
  `.../fps-particulas-heal-asset-no-bug.md`, `.../fps-walker-dl-comandos-extendidos-latente.md`.

**Plan de integración en `main`** (por fases; **NO** es un merge ciego):

1. **Sincronizar**: mergear `main` → rama y resolver conflictos (`src/subsystems/input.cpp` —ambas lo
   tocan— y los `.md` de estado).
2. **Re-validar** en Windows con los flags ON (cámara, identidad, #6/#8) sin regresiones.
3. **Promover**: **encender por defecto** solo lo **validado** (cámara + identidad + #6); dejar
   **gateado** lo incompleto (efectos/A2.2d, instrumentación).
4. **RT64**: para un release, **commitear el fork** (gate de escala, etc.) + subir la chincheta; o
   mantener el patch. Detalle: `docs/workflows.md §1.2`.
5. **Merge/PR a `main`** con su documentación.

## Árbol

- `main` = `v0.6.2` + el fix de input, **submódulos limpios** en sus pins.
- Instrumentación reutilizable (`HH_PAIRING`, `HH_MTXGROUP`) y banco headless (Xvfb+lavapipe): nota §4.

## Pitfalls (NO repetir)

- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios.
- **La vista no valida** (el mantenedor vio "mejoras" con un `.exe` viejo): validar por métrica.
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
- **Botones vs direcciones**: los botones de acción van por **flanco**; el **auto-repeat es solo para
  direcciones**. No leer acciones en estado mantenido (bug 2026-10-04).
