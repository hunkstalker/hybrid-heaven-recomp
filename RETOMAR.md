# RETOMAR — handoff

> **Handoff para la próxima sesión** (última: **2026-09-24**). Corto: estado, siguiente tarea y Git.
> El **diseño** y la **técnica** viven en `docs/` y `notes/`; aquí solo se enlazan. Reglas: `AGENTS.md`.
> **Rama de trabajo: `menu-nativo`** (el `main` es la release; ver §Git).

## Estado

- **A2 (overlay del menú inicial)**: render hook de RT64 + plume + atlas RGBA8 de la fuente del juego.
  Validado en Windows en la fase A (`notes/2026-09-23-a2-render-hook-y-atlas.md`).
- **`hh_menu`**: modelo del árbol + dibujo 1:1 + **menú nativo oculto** (F6 lo alterna). Los **3 bugs del
  overlay** están **validados en Windows** (`82df034`). Ver `notes/2026-09-24-a2-*.md`.
- **Paso 5 HECHO (validado headless; falta Windows)**: navegación propia (arriba/abajo/izq-der,
  **A**=selecciona, **B**=atrás; **sin X**) y **control total**: el input del handler nativo se **mutea**
  (`hh_native_dir_input`/`hh_native_ab_input`) mientras el overlay manda, y su temporizador de
  inactividad se mantiene a tope. `feed_menu_navigation`.
- **Dibujo de menú HECHO (validado headless)**: **listas** (aplicada verde, resto gris); **selectores**
  (`NO/SÍ` o `< valor >` con flechas dibujadas; activo verde); **dígitos y `:` `.` dibujados**.
  Árbol: NUEVA PARTIDA = `EMPEZAR PARTIDA / DIFICULTAD / CÁMARA LIBRE / APUNTADO LIBRE`; GRÁFICOS =
  `RATIO` (filtra `RESOLUCIÓN`) / `RESOLUCIÓN` / `P. COMPLETA` / `ANTIALIASING` / `VSYNC` (SÍ) /
  `LÍMITE DE FPS` (NATIVO); **DEBUG** submenú de AJUSTES (`VENTANA DEBUG` → Inspector F1 + `MOSTRAR FPS`).
  `HH_MENU_SCREEN`: `6`=GRÁFICOS, `5`=IDIOMA, `8`=DEBUG. Ver `notes/2026-09-24-a2-selectores-y-arbol.md`.
- **Fix ROM integrado en esta rama** (cherry-pick de `main`): el `.exe` detecta cualquier `*.z64` en la
  raíz o en `rom/` (**por formato**, el nombre da igual), valida por hash y usa la primera válida; si
  ninguna vale, muestra un mensaje con el **SHA-1** esperado.
- **El overlay aún NO renderiza acentos** (los pliega a ASCII); ver §Acentos.
- Diseño del menú: **`docs/menu.md`**. Técnica (overlay/fuente/alineación/supresión del nativo):
  **`docs/architecture.md` §7**.

## Siguiente tarea

**Completar el menú ANTES de los acentos** (los submenús ya son navegables, así se validan las tildes).
Orden acordado con el mantenedor:

6. **Acciones** (pantalla a pantalla): mapear cada entrada a la función del juego. **Parcial**:
   `RATIO`, `RESOLUCIÓN`, `P. COMPLETA`, `ANTIALIASING`, `VSYNC`, `LÍMITE DE FPS`, `MOSTRAR FPS` y
   `VENTANA DEBUG` aplican en vivo y **persisten en `config.ini` `[video]`** (`hh::video_set_aspect` /
   `video_set_resolution` / `video_set_fullscreen` / `video_set_msaa` / `video_set_vsync` /
   `video_set_fps_limit` / `video_set_show_fps` / `video_set_developer_mode`); el menú se inicializa
   con esos valores. `res=ANCHOxALTO` con max(ancho/320, alto/240) y widescreen (`snap_overscan`) para
   aspectos > 4:3 (arregla el `21:9` "caja pequeña"). Ventana `windowed`: geometría recordada (`win_*`)
   → `res` concreta → nativa. `MOSTRAR FPS` mide presents reales. `VENTANA DEBUG` persiste; F1 en
   caliente lo maneja el port (`hh::toggle_inspector`) porque el hook Win32 de RT64 solo se instala al
   arrancar. **AUDIO HECHO**: `SONIDO` = `VOLUMEN` (0-100 %, afecta a todo) + `SALIDA`
   (`ESTÉREO`/`MONO`/`AURICULARES` = crossfeed), persistido en `[audio]`. Ver VSYNC con `HH_FPS=1`.
   **Pendiente acordado**: `CÁMARA LIBRE`/`APUNTADO LIBRE` (requieren modificar el juego; de momento
   NO), `DIFICULTAD` + `EMPEZAR PARTIDA` (arrancar partida nueva con la dificultad interna del juego),
   `CONTINUAR`; SFX y después acentos/idiomas.
7. **SFX** desde los eventos del modelo, retirando el puente actual (con el input muteado, el puente por
   cursor nativo queda en silencio).
4. **Etiquetas propias + acentos del overlay**: reusar `include/hh/accent_glyphs.h` para ampliar el
   atlas y dejar de plegar en `to_ascii`. Validable con `HH_MENU_SCREEN=5` (IDIOMA) o navegando.
8. **Validar en Windows** (paso 5 + dibujo + DEBUG + fix ROM + GRÁFICOS/geometría de ventana).

Alcance: **solo el árbol de menús** (estructura, navegación, dibujo, acciones y **persistencia** de
las acciones conectadas en `config.ini`).

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
  Inspector de RT64: `HH_DEVELOPER=1` + F1 (o `DEBUG → VENTANA DEBUG = SÍ`).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM de análisis: `/app/baserom.us.z64`
  (Windows: `build\windows\bin\Release\hh.us.z64`); el `.exe` acepta **cualquier `*.z64`** (nombre
  indiferente). SHA-1 USA retail: `16dbc21620b52deab5c5abf8a309ac60adfbee85`.

## Git (estado al cerrar esta sesión)

- **Rama de trabajo: `menu-nativo`** (WIP del menú). Contiene TODO el trabajo posterior a **v0.4.0**
  (los 18 commits que llegaron a `main` + el menú A2) **+ el fix ROM** (cherry-pick de `main`).
  `origin/menu-nativo` = `4a989d5`; el local va **2 commits por delante** (los cherry-picks ROM, sin
  push).
- **`main` = release**: `v0.4.0` (`c977bd5`) + fix ROM + `build(version): 0.4.1`; `origin/main` =
  `59cd15c` (push hecho). **Falta subir `4600fa3`** (SHA-1 + README) y **tag `v0.4.1`** (release.yml).
- `origin/main` anterior (`8265b9d`: 18 commits A2/SFX/A1) **preservado en `menu-nativo`**.
- `lib/rt64` (fork) y `N64ModernRuntime`/`N64Recomp`: en sync. Tags hasta **v0.4.0**.
- Al retomar: `git switch menu-nativo`; si `main` avanzó, `git merge main` en `menu-nativo`.
