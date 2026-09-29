# FASE 2 — UI de carga (pantalla CARGAR PARTIDA, overlay 1:1)

> Evidencia de la **Fase 2** del plan `notes/2026-09-29-menu-cargar-guardar-partida-plan.md`. Rama
> `menu-carga-guardado-partida`. Estado: **skeleton + render 1:1 funcionando** (validado headless con
> captura). Ver Fases 0/1 en `...fase0-hallazgos.md` y `...fase1-formato-pak.md`, y ADR 0013.

## 1. Qué se ha implementado `[MEDIDO]`

- **Modelo (`hh::menu`)**: nueva pantalla `ScreenId::LoadGame` y acciones `OpenLoadGame`/`LoadGamePick`.
  - `rebuild_load_game()` construye **una fila por partida** del rango de partidas del `.pak`
    (`hh::save::game_slot_count()` = 45), con acción `LoadGamePick` e `index` = slot (0-based).
    Las partidas **no presentes** van `enabled=false` (el cursor no se posa); el cursor arranca en la
    primera presente.
  - Metadatos desde el **trailer**: `slot_present`, `meta_area_n/p`, `meta_level`, `meta_time`. El
    texto de cada fila son **3 líneas** (`ÁREA N-P\nNIVEL n\nTIEMPO M:SS`, u `PARTIDA VACÍA`), que el
    overlay dibuja dentro de la caja.
  - `HH_MENU_SCREEN=19` (`ScreenId::LoadGame`) permite revisar el dibujo sin navegar.
- **Overlay (`menu_overlay.cpp`)**: rama dedicada de `LoadGame` (dibujo 1:1 con el DATA LOAD nativo):
  - Título **`DATA LOAD`** centrado (cadena literal del nativo; la traducción devuelve `DATA LOAD`
    en todos los idiomas para no romper el 1:1).
  - **Caja con borde por partida** (3 líneas): borde **verde** en la seleccionada, blanco/gris el resto;
    relleno oscuro translúcido (`kBoxFill`). El área usa 4 `Panel` de 1 px por borde (`append_box`).
  - **Cursor**: flecha nativa a la izquierda de la caja seleccionada. **Scroll**: flechas ▲/▼
    (`append_scroll_arrow`) cuando hay más partidas que cajas visibles.
  - **Caja de mensaje** inferior ancha con `Select play data to be loaded.` (literal del nativo,
    centrado). El overlay ya vectoriza `:` `-` `.` (la fuente no los trae).
- **Enganche (parcial, `sections.cpp`)**: A sobre una partida llama a `func_801423C8(0, slot)` (carga
  nativa del slot a los globals). **La transición de escena completa se cierra en la Fase 3.**

## 2. Validación `[MEDIDO]`

- Build Linux OK.
- Headless con un `.pak` de **74 slots** y metadatos variados: el log muestra
  `[save-edit] .pak cargado (247147 B, 74 slots)` y `[overlay] screen=19 (CARGAR PARTIDA) entries=45`.
- Captura (`import` sobre Xvfb): la pantalla sale con `DATA LOAD`, 3 cajas (1-0/2-1/3-2 con NIVEL y
  TIEMPO), borde verde en la seleccionada, cursor, flecha de scroll y el mensaje nativo. **Layout ≈ 1:1**
  con la referencia `work/gameplay screenshots/CONTINUAR/`.

## 3. Pendiente / notas

- **Fondo del título**: al forzar la pantalla con `HH_MENU_SCREEN` desde el menú de título, el logo
  `HYBRID HEAVEN` del fondo permanece (es de la pantalla de TÍTULO, no del DATA LOAD). En el flujo real
  (Fase 3, al interceptar `func_8013E850`) no aparecerá. **Confirmar en Windows.**
- **Afinado fino del 1:1** (posición/ancho exactos de cajas y caja de mensaje, sangrías) contra el
  nativo, con la captura F7 pareada en Windows.
- **Fase 3**: enganchar `CONTINUAR` a esta pantalla (ocultar el file-select nativo, mutear input,
  publicar el overlay) y cerrar la transición de carga (lo que hace `func_8013EA94/…`).
