# RETOMAR — handoff

> **Handoff para la próxima sesión.** Corto: estado, siguiente tarea y Git.
> **Diseño** y **técnica** viven en `docs/` y `notes/`; aquí solo se enlazan. Reglas: `AGENTS.md`.
> **Rama de trabajo: `menu-nativo`** (el `main` es la release; ver §Git).

## Sincronización con `main` — CERRADA (2026-09-26)

`menu-nativo` salió de **v0.4.0** (`c977bd5`) y `main` publicó **v0.4.1–v0.4.4**. El merge
`main → menu-nativo` está **hecho y validado** (unión: HUD/docs de `main`, menú/idiomas de
`menu-nativo`). Detalle en `notes/2026-09-26-a-sync-menu-nativo-con-main.md`.

- Resueltos a mano los 8 que conflictuaron: `include/hh.h`, `src/subsystems/input.cpp` (F5/F6 +
  calibración + F1/ratón-dev **y** F7–F10), `src/platform/rt64_render_context.cpp` (API de menú +
  captura F7/BMP), `AGENTS.md`, `PROYECTO.md`, `RETOMAR.md`, `TODO.md`, `docs/INDEX.md` (docs: unión).
- Auto-merge limpio: `src/platform/main.cpp`, `src/platform/support.cpp`, `src/hooks/dl_snap.cpp`,
  `build_windows.bat`, `.gitignore`, `README.md`; `src/hooks/hud_rewrite.cpp` llegó **limpio**
  (fixes #3/#7 intactos).
- **Validado**: Linux compila (`cmake --build build/linux`) y **Windows OK** (mantenedor).
- **No** mergear todavía `menu-nativo` → `main`: es WIP; será la **futura feature release**
  (probablemente **v0.5.0**) cuando esté completa. Checkpoint pre-merge: tag
  `backup-menu-nativo-sync`.

## Estado

- **Menú inicial (`hh_menu`) COMPLETO**: modelo, dibujo 1:1, menú nativo oculto, navegación propia
  (A/B, control total), acciones (RATIO/RESOLUCIÓN/P. COMPLETA/ANTIALIASING/VSYNC/LÍMITE DE FPS/
  MOSTRAR FPS/VENTANA DEBUG → `[video]`; SONIDO → `[audio]`) y SFX por eventos del modelo.
- **Acentos + idiomas HECHO (2026-09-25, headless)**: ver `notes/2026-09-25-d-menu-multilingue-...md`
  y **ADR 0012**:
  - Menú: **letra base color0 + marca** dibujada por el mantenedor (`tools/text/menu_marks.py` →
    `include/hh/menu_marks.h`; atlas 128×44). `¿ ¡` = `? !` girados.
  - **`IDIOMA` en `AJUSTES`** y **funcional** (cambia menú + texto in-game; persiste en
    `config.ini [lang]`). Etiquetas localizadas **en/es/ca/fr/de** (`hh::menu::localized`); lista en
    **endónimos**.
  - **Idioma del sistema** si no hay `[lang]` (Windows `GetUserDefaultLocaleName`; Linux `LANG`/`LC_*`),
    con fallback a **inglés**. Prioridad `HH_LANG` > `[lang]` > sistema > `en`.
- **HUD/minimapa de `main` (v0.4.1–v0.4.4) integrados por el merge**:
  - **POWER/STAMINA** por hash de contenido (`d820d8e`); **disco plateado** del radial por hash+caja
    `27,19,59,51`; **barra de combo** (4 `G_FILLRECT`, `y=28..30`) y **stamina gastada** (`y=34..38`)
    por posición → issue **#3** CERRADO. `notes/2026-09-25-f-hud-combate-contenido.md`.
  - **Minimapa** por **hash de contenido** de su `dl` (la dirección cambia por escena/capítulo) →
    issue **#7** CERRADO (v0.4.4). `notes/2026-09-26-fix-minimapa-contenido.md`.
- **Fuente in-game (8×12 `color4`) ES/CA/FR/DE preparada** (`tools/text/build_font.py` →
  `include/hh/game_font_color4.h`) pero **sin cablear** (hoy `text_glyphs.cpp` sirve un set 8×8 propio).
- **Idiomas en las ROMs**: EU = En/Fr/De; JP = ja (añadida a `work/roms/jp.z64`); ES/CA no existen.
- Diseño: **`docs/menu.md`**; ADRs **0008** y **0012**; técnica del overlay: `architecture.md` §7.

## BUG RESUELTO (2026-09-25, headless) — cambiar de idioma aceleraba el juego

**Causa (medida)**: `hh_trans_reapply_language` (`src/subsystems/trans_cache.cpp`) reescribía el módulo
entero desde el cache/ROM; el juego **modifica en caliente** esas regiones (relocaliza el módulo de
código `005F1190`@`801BF1A0`: 241 B; buffer de trabajo `0068BF26`@`803837E0`: 33889 B) y el reapply
las pisaba → `viOriginalRate` 30 → 60.

**Fix**: re-aplicar **solo** las posiciones cuyo contenido actual coincide con el testigo `written`
(los bytes que el port escribió en la carga, con traducción); se respetan los cambios del juego.
Además: poda de entradas que solapan una carga nueva, tope de memoria (32 MB) y knob de A/B
`HH_LANG_REAPPLY=0`. Detalle y evidencia: `notes/2026-09-25-e-fix-reapply-idioma.md`.

**Validado headless**: con `HH_FPS=1 HH_LANG_CYCLE_AT=15` el `vi` se queda en 30 y `present≈29.5`
(antes saltaba a 60 / ~54). **Falta confirmar en Windows** (ver tarea siguiente).

## Bug aplazado (interpolación de frames)

**Artefacto de interpolación (puerta + primer jefe del nivel 1) — APLAZADO.**
- **Síntoma**: con `Refresh Rate Mode = Display` (interpolación **ON**) cierta **puerta** parpadea
  entre visible/oculta, y el **primer jefe del nivel 1** muestra geometría incoherente. Con
  `Original` (interpolación **OFF**) **no** ocurre. `Presentation Mode = Present Early` no influye.
  **NO** ocurre en **BizHawk** ni **Simple64** → es del render (RT64/port).
- **Causa**: la **interpolación** de RT64 (`RefreshRate::Display`, v0.4.0): empareja draw calls entre
  frames e interpola sus matrices; con ciertos objetos salen frames intermedios incoherentes.
- **APLAZADO**: la solución de fondo es **desacoplar la lógica del juego del render** (lógica a 60 Hz)
  → épica aparte. Detalle: `notes/2026-09-22-fps-y-present-early.md` §Regresión conocida.

## SIGUIENTE TAREA: menú nativo — funcionales y pulido

Merge validado (Linux + Windows). Ahora, en `menu-nativo`, por orden recomendado:

1. **Bug del submenú `IDIOMA` (1b)**: entrar, mover el cursor sobre un idioma **sin aplicarlo** y salir
   con **B** (hoy no pasa nada); al **volver a entrar y salir** se aplica el idioma señalado sin
   confirmar. Debe aplicarse **solo con A/confirmar**.
2. **Renombrar `AJUSTES` → `CONFIGURACIÓN` (1)** con traducción a todos los idiomas.
3. **`CONTINUAR` (4b)**: enlazar con la función real de continuar (poco esfuerzo).
4. **`EMPEZAR PARTIDA` (4c)**: enlazar con la función real de empezar partida.
5. **`DIFICULTAD` (4d)**: controlar la config para que `EMPEZAR PARTIDA` cree la partida en la
   dificultad elegida (esfuerzo por determinar).
6. **Código Konami → `TRUCOS` (2)**: en la raíz, encima de `SALIR`; detección por mando o teclado,
   con SFX.
7. **Demos de inactividad (3)**: recuperar la intro/demos que salían a los segundos sin pulsar (se
   perdieron al crear el menú moderno); analizar.

### Después (backlog de la tarea)

- **Traducción — MENÚ (overlay)**: **JA del menú** (embeber la **kana** del `color0` JP o TTF; hoy las
  etiquetas caen a inglés). `color0` JP tiene kana, no kanji.
- **Traducción — JUEGO/GAMEPLAY (texto in-game)**: **cablear** `game_font_color4.h` en
  `src/hooks/text_glyphs.cpp`; extraer **DE/FR** de la ROM EU y **JA** de la JP (emparejar por módulo)
  → `assets/lang/*.txt`; redactar **ES/CA**; validar longitud variable/A1 en Windows.
- **Aparcado**: `CÁMARA LIBRE`/`APUNTADO LIBRE` (modifican el juego).

## Otras tareas (ver `TODO.md`)

- **Widescreen** (en `main`): falta la **barra HP** y elementos de la derecha (`right`/`stretch`) —
  re-derivar sus identidades con F7 (captura pareada).
- **APLAZADO**: artefacto de interpolación (puerta + jefe) — ver arriba.
- Resto del backlog de `TODO.md`.

## Método HUD

- **Lista de validación**: solo Windows (build release GUI). Linux headless solo compila.
- Trazas a fichero junto al exe: `HH_HUD_TRACE=1`, `HH_HUD_REWRITE_TRACE=1`, `HH_HUD_SCISSOR_TRACE=1`,
  `HH_FULL_FRAME=0` (off), `HH_NO_HUD_REWRITE=1` (off), `HH_MAP_CROP=<px>`.
- **Atajos de diagnostico** (A/B en caliente):
  - **F7 = captura pareada**: traza de identidades 2D de UN frame → `hh_cap_<n>.log` **+ imagen** de
    la ventana → `hh_cap_<n>.bmp`, en el mismo instante. Otro F7 la cancela. `HH_HUD_TRACE=1` sigue
    volcando traza continua a `hh_hud.log`.
  - **F8 = PresentEarly** ON/OFF (RT64: PresentEarly ↔ SkipBuffering).
  - **F9 = interpolación** ON/OFF (RT64: `RefreshRate` Display ↔ Original; ver bug de la puerta).
  - **F10 = reescritor HUD** ON/OFF (`HH_NO_HUD_REWRITE`).
- **Regla**: la **dirección RDRAM no es identidad**; usar **hash de contenido** (+ caja/posición
  cuando el hash se reutiliza). **No fiarse del color**: la barra de combo pasa rojo→azul y parpadea,
  y RT64 pinta el relleno con el **PRIM color** (la traza lee `fill_color=0`).
- El **Inspector de RT64** (`HH_DEVELOPER=1`, F1) fue clave: muestra el `Rect` y el `PrimColor` del
  draw bajo el cursor.

## Git

- **`main` = release**: al día y pusheado, **v0.4.4** (v0.4.1–v0.4.4 publicadas).
- **`menu-nativo`** (WIP del menú): **pusheado** hasta el tip pre-merge (`60171dd`;
  `backup-menu-nativo-sync`). Merge `main → menu-nativo` **hecho** (commit del 2026-09-26).
- Commitear **solo** lo validado o la documentación (regla `AGENTS.md`).

## Método (rápido)

- **Build/run Windows**: `AGENTS.md` (build) + `docs/BUILDING_windows.md`. **Build Linux**:
  `cmake --build build/linux --parallel $(nproc)` (necesita `lib/` ya clonado).
  **Regenerar C recompilado**: `python3 tools/regenerate.py` (ADR 0009/0011; no se versiona).
- **Headless + replay para llegar al menú**: `docs/workflows.md` §2.
- **Diagnósticos** (`hh.log`): `HH_MENU_TRACE=1`, `HH_NATIVE=1`, `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`,
  `HH_MENU_SCREEN=<id>`, `HH_FONT_TRACE=1`, `HH_FONT_DUMP_GLYPH=<color>`, `HH_ACCENTS=0`, `HH_LANG=es`,
  `HH_FPS=1`. Atajos: F2 aspecto, F3 ventana, F4 MSAA, F5 idioma, **F6 menú nativo**, F7–F10 (HUD).
  Inspector RT64: `HH_DEVELOPER=1` + F1 (o `DEBUG → VENTANA DEBUG = SÍ`).
- **Fuente/acentos**: `tools/text/menu_marks.py` (marcas del menú), `tools/text/build_font.py`
  (fuente in-game 8×12), `tools/text/README_font_sheet.md` (formato de las hojas). ROMs en `work/roms/`
  (`us_dec.z64`, `eu_dec.z64`, `jp.z64`).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM USA para el port:
  `build/linux/baserom.us.z64` (o cualquier `*.z64`, el nombre da igual). SHA-1 USA retail:
  `16dbc21620b52deab5c5abf8a309ac60adfbee85`.
- **Docs**: tras editar docs, `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`;
  `--check` valida enlaces y el presupuesto de arranque).

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
```
(La build **no siempre** refresca el `.exe`: comprobar su fecha; si no cambia, borrar
`build\windows` y recompilar desde cero. Verificado que sale `=== LISTO ===` pero a veces no
actualiza el ejecutable.)