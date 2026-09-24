# RETOMAR — handoff

> **Handoff para la próxima sesión** (última: **2026-09-24**). Corto: estado, siguiente tarea y Git.
> El **diseño** y la **técnica** viven en `docs/` y `notes/`; aquí solo se enlazan. Reglas: `AGENTS.md`.

## Estado

- **A2 (overlay del menú inicial)**: render hook de RT64 + plume + atlas RGBA8 de la fuente del juego.
  Validado en Windows en la fase A (`notes/2026-09-23-a2-render-hook-y-atlas.md`).
- **`hh_menu` (2026-09-24)**: modelo del árbol + dibujo 1:1 (fuente + flecha nativa) + navegación
  arriba/abajo; **menú nativo oculto por defecto** (F6 lo alterna). Los **3 bugs del overlay** están
  **VALIDADOS en Windows** (bearing de "MODO COMBATE", nativo al volver atrás, cierre instantáneo).
  Commit de código `82df034`. Ver `notes/2026-09-24-a2-*` (bugs) y
  `notes/2026-09-24-docs-presupuesto-y-acentos.md` (RETOMAR corto + presupuesto de contexto).
- **Paso 5 HECHO (2026-09-24, validado headless)**: navegación propia completa (arriba/abajo/izq-der,
  **A**=selecciona, **B**=atrás; **sin X**) y **control total**: el input del handler nativo se **mutea**
  (`hh_native_dir_input`/`hh_native_ab_input`) mientras el overlay manda; su temporizador de
  inactividad se mantiene a tope para que no cierre la pantalla solo. **Pendiente validar en Windows.**
- **Dibujo de menú (2026-09-24)**: **listas** con la opción aplicada en **verde** y el resto en **gris**;
  **selectores** con el activo en verde (valores juntos `NO/SÍ` o `< valor >` con flechas dibujadas);
  **dígitos y `:` `.` dibujados**. NUEVA PARTIDA = `EMPEZAR PARTIDA / DIFICULTAD / CÁMARA LIBRE /
  APUNTADO LIBRE`. GRÁFICOS = `RATIO / RESOLUCIÓN (filtrada por ratio) / P. COMPLETA / ANTIALIASING /
  VSYNC (SÍ) / LÍMITE DE FPS (NATIVO)`. **DEBUG** es submenú en AJUSTES (`VENTANA DEBUG` → Inspector F1
  + `MOSTRAR FPS`). IDs: **`HH_MENU_SCREEN=6`=GRÁFICOS, `=5`=IDIOMA, `=8`=DEBUG**.
  Ver `notes/2026-09-24-a2-selectores-y-arbol.md`.
- **El overlay aún NO renderiza acentos** (los pliega a ASCII); ver §Acentos.
- Diseño del menú: **`docs/menu.md`**. Técnica (overlay/fuente/alineación/supresión del nativo):
  **`docs/architecture.md` §7**.

## Siguiente tarea

**Completar el menú ANTES de integrar los acentos.** Al revés no se pueden validar: la raíz no tiene
tildes y los submenús (que sí) todavía no son navegables. Orden acordado con el mantenedor:

5. **[HECHO 2026-09-24] Navegación propia** (A/B + selectores) y **neutralizar el input del handler
   nativo** (control total). `feed_menu_navigation` cubre todo; submenús navegables (validado headless;
   falta Windows).
6. **Acciones**: mapear cada entrada a la función del juego (continuar, nueva partida, modo combate,
   ajustes, resolución…), pantalla a pantalla. **Parcial**: `VENTANA DEBUG` ya engancha el modo
   desarrollador de RT64; `CÁMARA LIBRE`/`APUNTADO LIBRE`/`RATIO`/`RESOLUCIÓN`/`P. COMPLETA`/
   `ANTIALIASING`/`VSYNC`/`LÍMITE DE FPS`/`MOSTRAR FPS` cambian en memoria pero **no** se aplican a
   RT64 ni se persisten.
7. **SFX** desde los eventos del modelo, retirando el puente actual.
4. **Etiquetas propias + acentos del overlay** (paso 4, **movido a después de completar el menú**):
   reusar `include/hh/accent_glyphs.h` para ampliar el atlas del overlay y dejar de plegar en
   `to_ascii`. Validable con `HH_MENU_SCREEN=6` (GRÁFICOS: RESOLUCIÓN, LÍMITE DE FPS) / `=5` (IDIOMA:
   ESPAÑOL, CATALÁN, FRANCÉS…) o navegando.
8. **Validar en Windows.**

Alcance: **solo el árbol de menús** (estructura, navegación y dibujo). **NO** persistir la config
todavía (los selectores cambian en memoria; el guardado en `config.ini` queda para después).

## Acentos — aclaración (dos sistemas distintos)

- **Overlay (nuestra UI)**: no usa el motor de texto del juego; tiene su propio atlas y **hoy pliega
  los acentos a ASCII** (`ESPAÑOL` → `ESPANOL`). Es el **paso 4** (arriba).
- **B** (`src/hooks/text_glyphs.cpp`): inyecta glifos acentuados en el **motor del juego** (texto
  in-game: diálogos, HUD, ítems). Implementado, pero **NO validable hoy**: la única cadena traducida
  con tilde (`RESOLUTION=RESOLUCIÓN`, en `es.txt`) vivía en el **menú vanilla**, ya oculto/abandonado,
  y no hay otra cadena con tilde. **Aparcado** hasta que traduzcamos texto in-game con acentos. **No
  bloquea el menú.**

## Método (rápido)

- **Build/run Windows**: `AGENTS.md` (build) + `docs/BUILDING_windows.md`.
- **Headless + replay para llegar al menú**: `docs/workflows.md` §2.
- **Diagnósticos** (`hh.log`): `HH_MENU_TRACE=1`, `HH_NATIVE=1` (muestra el nativo al arrancar;
  equivale a F6), `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`, `HH_MENU_SCREEN=<id>`, `HH_FONT_TRACE=1`,
  `HH_ACCENTS=0`, `HH_LANG=es`. Atajos: F2 aspecto, F3 ventana, F4 MSAA, F5 idioma, **F6 menú nativo**.
  Inspector de RT64: `HH_DEVELOPER=1` + F1.
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM de análisis: `/app/baserom.us.z64`
  (Windows: `build\windows\bin\Release\hh.us.z64`).

## Git (estado al cerrar esta sesión)

- **Paso 5 SIN COMMITEAR** (2026-09-24): `src/hooks/sections.cpp`, `src/platform/overlay.cpp`,
  `include/hh/overlay.h`, `docs/menu.md`, `RETOMAR.md`, `TODO.md` + nota. No se commitea hasta que se
  **valide en Windows** (regla: commitear tarea validada).
- **`main` local** (SIN push), **árbol limpio**. Commits de **código** de la sesión: `2181fab` (hh_menu:
  modelo + dibujo 1:1 + navegación + nativo oculto, sets A/B), `4e4cf1e` (bugs 1 y 2 del overlay:
  bearing + set C) y `82df034` (bug 3: cierre instantáneo). El resto son **docs** (RETOMAR corto +
  `docs/menu.md`, presupuesto de contexto de arranque). HEAD exacto: **`git log`**.
- Sesiones previas: `8265b9d`, `5867de5` (overlay A2), `d6f4afb` · `de99550` · `b95c6a4` (SFX).
  `c2ce652` (hh_menu) y `3aede33` (SFX submenús): **REVERTIDOS/eliminados**.
- **`origin/main` = `c977bd5` (v0.4.0)**. Locales sin push: `ac4a89f` (traducción/idiomas), arreglo del
  pin de rt64, `22e3eed` (ratón).
- **`lib/rt64`** (fork): `hybrid-heaven` = `a8f0a70` (gitlink correcto). **`N64ModernRuntime` /
  `N64Recomp`**: en sync. Tags: `v0.1.x`…**`v0.4.0`**; próximo `v0.4.1`.
- Push normal de `main` pendiente (**requiere `--force-with-lease`**; ver `AGENTS.md` §Push).
