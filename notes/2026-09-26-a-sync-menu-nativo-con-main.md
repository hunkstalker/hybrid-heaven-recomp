# Sincronizar `menu-nativo` con `main` (v0.4.1–v0.4.4)

> Sesión 2026-09-26. Cierra la desincronización de **`menu-nativo`** (que salió de `v0.4.0`,
> `c977bd5`) trayéndole los fixes de `main` con un **merge**, antes de seguir con el menú.
> Contexto: `RETOMAR.md` de ambas ramas.

## 1. Método

- **Merge, no rebase**: `menu-nativo` ya estaba en `origin` (61 commits posteriores al merge-base).
- Checkpoint: `git tag backup-menu-nativo-sync` en el tip pre-merge (`60171dd`) y push de
  `menu-nativo` antes de tocar nada (fast-forward; `origin/menu-nativo` iba 26 detrás).
- `git switch menu-nativo && git merge main`.

## 2. Conflictos (8) y resolución (unión de ambos aportes)

| Fichero | Resolución |
|---|---|
| `include/hh.h` | API de menú (`video_set_*`, `audio_set_*`, `text_*`/idiomas, `menu_overlay`, `menu_sfx`, `dev_panel_open`, `set_developer_mode`) **+** API de `main` (`video_toggle_present_early/interpolation`, `hud_capture_*`, `hud_trace_file`); `get_rom_paths` deduplicado; `kVersionPatch=4`. |
| `src/subsystems/input.cpp` | Cadena de teclas completa: F1 Inspector, F2/F3/F4 (comunes), **F5** idioma, **F6** menú nativo, Ctrl+calibración (menú) **y** **F7** captura pareada, **F8** PresentEarly, **F9** interpolación, **F10** reescritor; ratón→A/B desactivado con el panel dev abierto. |
| `src/platform/rt64_render_context.cpp` | Estado/API de menú (dev panel, developer mode, VSYNC, reapply, inspector) **+** bloque de `main` (`g_app`, captura BMP) y `menu_overlay::tick()`; la captura F7 se dispara en `update_screen`. |
| `AGENTS.md` | De `main`: push fast-forward + regla de título de release. De `menu-nativo`: calibración crítica (medido/inferido). |
| `PROYECTO.md` | Estado combinado: v0.4.4 (HUD/minimapa validados) **+** WIP del menú. |
| `RETOMAR.md` | Reescrito como handoff de `menu-nativo`. |
| `TODO.md` | Unión de las entradas "Hecho" (`#7` minimapa + input ratón/panel). |
| `docs/INDEX.md` | Regenerado con `tools/analysis/docs_index.py`. |

- **Auto-merge limpio** (sin conflicto): `src/platform/main.cpp`, `src/platform/support.cpp`,
  `src/hooks/dl_snap.cpp`, `build_windows.bat`, `.gitignore`, `README.md`.
- **`src/hooks/hud_rewrite.cpp`** (y `include/hh/hud{id,rewrite}.h`) llegaron **limpios**: los fixes
  de HUD #3/#7 (de `main`) intactos. Como se esperaba, el riesgo estaba en la **API/teclas**, no en
  la lógica del anclaje.
- `tools/analysis/docs_index.py` y `docs/documentation.md` solo los tocó `menu-nativo` → se conserva
  el **presupuesto agregado de arranque** (sin `HARD_LIMITS`), tal como se decidió allí
  (`notes/2026-09-24-docs-presupuesto-y-acentos.md` §2).

## 3. Validación

- **Linux**: `cmake --build build/linux` → `[100%] Built target HybridHeavenRecomp` (se recompilaron
  `input`, `rt64_render_context`, `support`, `main`, `text`, `menu_sfx`, `trans_cache`).
- **Windows**: OK (build release, validación del mantenedor): menú, acentos, `IDIOMA`
  (EN/CA/FR/DE sin acelerar el juego), idioma de sistema, y HUD/minimapa + F7–F10 tras el merge.
- `python3 tools/analysis/docs_index.py --check` → exit 0.

## 4. Consecuencias

- `menu-nativo` queda al día con `main` (v0.4.4). **No** se mergea aún `menu-nativo` → `main`: es
  WIP; será la **feature release** cuando esté completa (probablemente **v0.5.0**).
- Backlog del menú anotado en `TODO.md` (rename `AJUSTES`→`CONFIGURACIÓN`, bug del submenú `IDIOMA`,
  código Konami → `TRUCOS`, demos de inactividad, `CONTINUAR`/`EMPEZAR PARTIDA`/`DIFICULTAD`).
