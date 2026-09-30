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

- **Tipografías (TAREA APARTE, ver `2026-09-29-tipografias-data-load-tarea.md`)**: el DATA LOAD nativo
  usa **3 tipografías** (título `DATA LOAD` ~11 ud, mensaje `Select play data...` ~9.3 ud, cabeceras
  `AREA/LEVEL/TIME` ~7 ud = la del menú de título). El overlay hoy dibuja todo con la del título; para
  el 1:1 hay que extraer/mapear las otras (el compositor `func_8001B204` elige estilo por `a0` →
  tabla `D_8008EF70` en BSS).

- **Fondo del título**: al forzar la pantalla con `HH_MENU_SCREEN` desde el menú de título, el logo
  `HYBRID HEAVEN` del fondo permanece (es de la pantalla de TÍTULO, no del DATA LOAD). En el flujo real
  (Fase 3, al interceptar `func_8013E850`) no aparecerá. **Confirmar en Windows.**
- **Afinado fino del 1:1** (posición/ancho exactos de cajas y caja de mensaje, sangrías) contra el
  nativo, con la captura F7 pareada en Windows.
- **Fase 3 (enganche) HECHA pero A MEDIAS (2026-09-29, sin commitear)**: funciona y está validado
  headless:
  - Al dar **CONTINUAR** sale nuestra `LoadGame` (`screen=19`) y el **DATA LOAD nativo queda oculto**
    (texto + cajas).
  - **F8** muestra/oculta toda la UI nativa.
  - Ocultado por CATEGORÍAS en `menu_overlay.cpp`: `g_native_visible` (F8, visibilidad única) +
    `g_file_select_active` (qué pantalla nativa corre). Hooks de `func_801C3D84` (update del
    file-select: oculta + mutea input + publica) y `func_8001A804` (cajas: se saltan).
  - **⚠️ NO enganchar `func_801C3D50`** (setup del file-select): su dirección la comparte otro módulo
    (base solapada) y el hook **cuelga el juego** (medido). La categoría se activa desde CONTINUAR.
  - **Qué quedó a medias (y por qué)**:
    1. **Afinado 1:1 ❌ bloqueado** por las **tipografías** (tarea aparte): el overlay dibuja TODO con
       la fuente del menú (`color0`), pero el DATA LOAD nativo usa 3 fuentes distintas → no se puede
       dejar idéntico hasta extraerlas/mapearlas.
    2. **Al elegir una partida NO carga todavía**: hoy solo llama a `func_801423C8(0, slot)` (lee el
       slot y deserializa a los globals); **falta la transición de escena** que hace el flujo nativo
       tras elegir (`func_80142570` + `func_8012FE50(0x17,0x73,…)`). Se dejó así para no complicar el
       enganche antes de validar el ocultado.
    3. **F8 solo recompone** el título/mensaje del DATA LOAD llamando a `func_801426B0`/`func_80142840`
       (las filas ya se recomponen por frame); validado headless, **falta validar en Windows**.
