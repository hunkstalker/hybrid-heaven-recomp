# RETOMAR — handoff

> **Handoff para la próxima sesión.** Estado, siguiente tarea y métodos. **Diseño y técnica** viven en
> `docs/` y `notes/`; aquí solo se enlazan. Reglas: `AGENTS.md`.
> **Rama de trabajo: `menu-nativo`** (el `main` es la release; ver §Git).

## Estado (2026-09-26)

- **Sincronización con `main` CERRADA y validada**: merge `main → menu-nativo` con v0.4.1–v0.4.4
  (HUD/minimapa #3/#7). Nota `notes/2026-09-26-a-sync-menu-nativo-con-main.md`; checkpoint pre-merge:
  tag **`backup-menu-nativo-sync`**. **No** mergear `menu-nativo` → `main` todavía (es WIP; será la
  **feature release v0.5.0**).
- **Menú inicial del port (`hh_menu`) COMPLETO y validado en Windows**:
  - Navegación propia (A/B, **control total**), **menú nativo oculto** (F6 alterna), SFX por eventos.
  - Acciones de **video** (`[video]`) y **audio** (`[audio]`) que aplican en vivo y persisten.
  - **Acentos** (letra base + marca) y **sombras** (flecha + marcas, con las marcas **debajo** de la
    letra). Nombres de marcas **Set A**: `_base`/`_ed`/`_blank`.
  - **Idiomas EN/ES/CA/FR/DE** + **idioma del sistema** (`config.ini [lang]`); `IDIOMA` funcional;
    raíz `CONFIGURACIÓN` (antes AJUSTES).
  - **`CONTINUAR`** retoma la partida (reenvío al dispatch nativo del título).
  - **`EMPEZAR PARTIDA`** arranca partida nueva (**validado en Windows 2026-09-26**): disparo nativo
    puntual de **GAME START** (rama idx0 de `func_801C3A40`), sin pilotar el submenú nativo. **`DIFICULTAD`**
    fija la dificultad en el global `0x801BBC0D` (implementada; **efecto real —daño enemigo— por
    comprobar jugando**). Nota `notes/2026-09-26-g-…`.
  - Detalle: `notes/2026-09-26-b/…-idioma-configuracion-y-sombras.md`,
    `…-c-sombras-y-set-a.md`, `…-d-continuar-y-bugs-visuales.md`, `…-g-empezar-partida-y-dificultad.md`;
    **ADR 0008/0012**; `docs/menu.md`.
- **HUD/minimapa de `main`** integrados por el merge (issues #3 y #7).
- **Traducción in-game (juego)**: charset + sustitución en runtime listos; **fuente 8×12 `color4`
  preparada pero sin cablear**.

## SIGUIENTE TAREA: menú nativo — funcionales y pulido (orden recomendado)

1. **Código Konami → `TRUCOS`**: en la raíz, encima de `SALIR`; detección por mando o teclado, con SFX.
2. **Demos de inactividad**: recuperar la intro/demos que salían a los segundos sin pulsar (se
   perdieron al crear el menú moderno); analizar.
3. **Fallos visuales** (capturas del mantenedor en `work/gameplay screenshots/CONTINUAR/`; `work/` es
   **gitignored**, pedir/copiar si hay que conservarlas):
   - **`DATA LOAD`**: el borde verde del cuadro de selección aparece pegado al borde superior de la
     pantalla (menú **nativo**; investigar con **F7** y `HH_FULL_FRAME=0`).
   - **Combate (golpes)**: las cajas verdes/rojas salen con **recuadro negro**; el original no lo lleva.
4. **Traducción — MENÚ (overlay)**: **JA** (embeber la **kana** del `color0` JP o TTF; hoy cae a inglés;
   `color0` JP tiene kana, no kanji).
5. **Traducción — JUEGO/GAMEPLAY (texto in-game)**: **cablear** `game_font_color4.h` en
   `src/hooks/text_glyphs.cpp`; extraer **DE/FR** (ROM EU) y **JA** (ROM JP) emparejando por módulo →
   `assets/lang/*.txt`; redactar **ES/CA**; validar longitud variable/A1 en Windows.
6. **Comprobar `DIFICULTAD` jugando**: verificar que el valor de `0x801BBC0D` se traduce en el **daño
   real** de los enemigos (requiere partida). La escritura está implementada (`0x801BBC0D`).

> **Hecho (2026-09-26)**: `EMPEZAR PARTIDA` **validado en Windows**; `DIFICULTAD` implementada
> (`notes/2026-09-26-g-empezar-partida-y-dificultad.md`).

### Aparcado
- **`CÁMARA LIBRE`/`APUNTADO LIBRE`** (requieren modificar el juego).

**Widescreen/HUD — CERRADO (2026-09-26)**: radar y HUD de combate (POWER/STAMINA, disco, combo,
stamina) a la izquierda y minimapa a la derecha, anclados y persistentes entre combates/niveles;
**no hay barra HP** (dial + numérico); los cuadros de diálogo van centrados. Detalle en `TODO.md`.

## Referencia técnica del menú (para reanudar)

- **Modelo**: `src/subsystems/menu.cpp` + `include/hh/menu.h` (pantallas, cursor, `Action`, `Event`).
- **Overlay**: `src/hooks/menu_overlay.cpp` (frame del título), `src/platform/overlay.cpp` (dibujo
  GPU: paneles/texto/marcas), `src/subsystems/font.cpp` (atlas de la fuente + marcas).
- **Entrada y acciones**: `src/hooks/sections.cpp` → `feed_menu_navigation` (navegación + acciones) y
  `hh_title_menu_hook` (envuelve `func_801C1DB8`; input nativo muteado con `g_mute_native_input`).
- **Dispatch nativo del título** (`sel` @ `0x801CC8C4`, valor 0..4): `0=NEW GAME / 1=CONTINUE /
  2=BATTLE MODE / 3=SOUND / 4=RESOLUTION`. Para disparar una acción del juego: fijar `sel` e inyectar
  **A** una vez (`g_inject_native_a` en `hh_native_ab_input`).
- **Marcas del menú**: `tools/text/menu_marks.py` (Set A: `_base` plantilla / `_ed` **diseño fuente de
  verdad** / `_blank` lienzo de `--template`) → `include/hh/menu_marks.h`.
- **Textos del menú**: `kMenuTr` en `menu.cpp` (ES canónico → en/ca/fr/de) + `hh::menu::localized`.

## Bug aplazado (interpolación de frames)

**Artefacto de interpolación (puerta + primer jefe del nivel 1) — APLAZADO.**
- **Síntoma**: con `Refresh Rate Mode = Display` (interpolación **ON**) cierta **puerta** parpadea y el
  **primer jefe del nivel 1** muestra geometría incoherente; con `Original` **no** ocurre (PresentEarly
  no influye). **NO** pasa en **BizHawk**/ **Simple64** → es del render (RT64/port).
- **Causa**: la interpolación de RT64 (`RefreshRate::Display`) empareja draw calls e interpola matrices.
- **Solución de fondo**: **desacoplar la lógica del juego del render** (lógica a 60 Hz) → épica aparte.
  Detalle: `notes/2026-09-22-fps-y-present-early.md` §Regresión conocida.

## Método HUD

- **Lista de validación**: solo Windows (build release GUI). Linux headless solo compila.
- Trazas junto al exe: `HH_HUD_TRACE=1`, `HH_HUD_REWRITE_TRACE=1`, `HH_HUD_SCISSOR_TRACE=1`,
  `HH_FULL_FRAME=0` (off), `HH_NO_HUD_REWRITE=1` (off), `HH_MAP_CROP=<px>`.
- **Atajos de diagnóstico**: **F7 = captura pareada** (traza `hh_cap_<n>.log` **+ imagen** `hh_cap_<n>.bmp`
  del mismo instante); **F8** PresentEarly; **F9** interpolación; **F10** reescritor HUD.
- **Regla**: la **dirección RDRAM no es identidad**; usar **hash de contenido** (+ caja/posición). **No
  fiarse del color** (RT64 pinta el relleno con el PRIM color). Inspector de RT64: `HH_DEVELOPER=1` + F1.

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
  (fuente in-game 8×12), `tools/text/README_font_sheet.md`. ROMs en `work/roms/` (`us_dec.z64`,
  `eu_dec.z64`, `jp.z64`).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM USA para el port:
  `build/linux/baserom.us.z64` (o cualquier `*.z64`). SHA-1 USA retail: `16dbc21620b52deab5c5abf8a309ac60adfbee85`.
- **Docs**: tras editar docs, `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`;
  `--check` valida enlaces y el presupuesto de arranque).

## Git

- **`main` = release**: al día y pusheado, **v0.4.4** (v0.4.1–v0.4.4 publicadas).
- **`menu-nativo`** (WIP del menú): **~24 commits por delante de `origin/menu-nativo`** (sin pushear);
  merge con `main` ya incluido. Commits de la sesión 2026-09-26: sync, backlog/docs, IDIOMA/CONFIGURACIÓN,
  sombras, `CONTINUAR`, `EMPEZAR PARTIDA`/`DIFICULTAD`.
- Commitear **solo** lo validado o la documentación (regla `AGENTS.md`).

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
```
(La build **no siempre** refresca el `.exe`: comprobar su fecha; si no cambia, borrar
`build\windows` y recompilar desde cero. Verificado que sale `=== LISTO ===` pero a veces no
actualiza el ejecutable.)