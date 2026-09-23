# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-23.**

## Tarea de ESTA sesión: spike de traducción — empezar por los textos del menú

Objetivo: probar que podemos **traducir en runtime** y ver cambiar textos del **menú** en pantalla
(base del selector de idioma del ADR 0008). Sería la **primera traducción al español** del juego.

**PROGRESO (2026-09-23)** — detalle en `notes/2026-09-23-*.md`:
1. [x] **Charset**: resuelto. El texto USA es **ASCII** en **campos de ancho fijo terminados en NUL**;
   los bytes no-ASCII junto a las anclas eran **flujos LZKN64**, no glifos. Extractor:
   `tools/text/extract_strings.py`. El título/menú/opciones está en **Nisitenma idx 23**.
2. [x] **Sustitución en runtime** interceptando el loader `trans`
   (`src/subsystems/text.cpp` + `src/subsystems/trans_cache.cpp`): `HH_LANG=es` traduce 68 cadenas
   del módulo 23 antes de escribirlas a RDRAM. **Validado visualmente en Windows** (título/opciones
   en español). Nota: `assets/lang/es.txt` editable junto al `.exe`.
3. [x] **A1 — sistema de idiomas + cambio en vivo** (`text.cpp`): lista `en/es/ca/fr/de/ja` + mods,
   `hh::text_set_language`/`text_cycle_language`, persistencia en `config.ini [lang]`, atajo **F5**,
   re-aplicación a módulos cargados (cambio en vivo). Detalle:
   `notes/2026-09-23-a1-sistema-idiomas-y-cambio-en-vivo.md`.
4. [•] **A2 — menú in-game AJUSTES → IDIOMA / SONIDO** (requisito del mantenedor). **Decisión**:
   reutilizar el **motor de texto del juego** (estilo idéntico), con arquitectura
   `hh_menu → hh_font → backend_game` (+ `backend_modern` futuro para fuentes HD). **Motor de texto
   localizado**: `0x8001B204` (set entrada) → `0x8001BC04` (colocar texto; color `0x8009E48..E4F`).
   Diagnóstico `HH_MENUTRACE=1`. **Importante**: los *overrides* del menú del juego quedan
   **DESACTIVADOS** (`src/hooks/sections.cpp`) porque el módulo 23 está **empaquetado** (sin offsets
   libres) y corrompían el menú principal. Detalle: `notes/2026-09-23-b-motor-texto-localizado.md` y
   `notes/2026-09-23-a2-plan-menu-ajustes-idioma.md`.
   **Siguiente**: entender `0x8001BC04` (firma de colocar texto) → montar `hh_font`/`backend_game`.
5. [ ] **B — glifos/acentos**: la PAL trae los acentos como gaiji (bloque JIS `B0A1..B0CA`); el ROM
   USA **no** los trae. Vía elegida: reutilizar fuente del juego (camino 1). Detalle:
   `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`.

**Permisos**: solo **lectura** de la ROM (`build\windows\bin\Release\hh.us.z64`); no modificar ni
versionar la ROM. Herramientas: `tools/text/extract_strings.py`, `tools/lzkn64/lzkn64.py`,
`tools/rommy.py`, `notes/us_manifest.yaml` (`expansionram` = idx 23). Diagnósticos nuevos:
`HH_LANG`, `HH_LANG_CYCLE_AT`, `HH_DUMP_RDRAM_AT`, `HH_MENU_TRACE`, `HH_MENUTRACE`.

## Estado (ya cerrado)

- **High frame rate por defecto (v0.4.0)**: `PresentEarly` + `Refresh Rate = Display` → presenta al
  refresco del monitor (~109 fps validados con RTSS; lógica a 30 Hz). Revertir: `HH_REFRESH_RATE=original`
  / `HH_PRESENT_EARLY=0`. `notes/2026-09-22-fps-y-present-early.md`.
- **Atajos**: **F2** aspecto, **F3** ventana, **F4** MSAA; **F1** = Inspector de RT64 (con
  `HH_DEVELOPER=1`). Diagnóstico: `HH_FPS=1`, `HH_GRAPHICS_API`.
- **Publicado**: **v0.3.0**. `lib/rt64` en el fork `hunkstalker/rt64` (`hybrid-heaven` = `a8f0a70`).

## Pendiente inmediato (mantenedor)

- **Push de 2 commits de docs** y **tag `v0.4.0`** tras CI verde:
  ```powershell
  git -C hybrid-heaven-recomp push origin main
  # esperar CI verde
  git -C hybrid-heaven-recomp tag -a v0.4.0 -m v0.4.0
  git -C hybrid-heaven-recomp push origin v0.4.0
  ```
  (`release.yml` usa `docs/releases/v0.4.0.md`.)

## Qué toca después

**Prioridad**: **A2/B** — entender `0x8001BC04` (rutina de "colocar texto" del motor del juego) para
envolverla en `hh_font`/`backend_game` y montar el menú **AJUSTES → IDIOMA / SONIDO** con el estilo
del juego. De paso, localizar la **textura de fuente** del módulo 23 (resuelve los acentos de B).
Todo el contexto en `notes/2026-09-23-b-motor-texto-localizado.md` y
`notes/2026-09-23-a2-plan-menu-ajustes-idioma.md`.

Ver también **`TODO.md`** §Ahora (otros pendientes: smoke de arranque, ADR 0009).

## Método

- **Mapa/HUD**: solo se valida en Windows; Linux headless solo para compilar
  (`cmake --build build/linux -j`). Trazas a `hh.log` (`HH_HUD_*`, `HH_RECT_TRACE=1`).
- **Menú/traducción**: validar en Windows (headless no llega al menú sin input). Diagnósticos:
  `HH_LANG=es`, `HH_MENU_TRACE=1`, `HH_MENUTRACE=1`, `HH_DUMP_RDRAM_AT=<seg>`.
- **Rendimiento**: medir con `HH_FPS=1`; FPS en pantalla con `HH_DEVELOPER=1` + F1 (o RTSS).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso explícito.

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Git

- **`main`**: `origin/main` = `c977bd5` (v0.4.0 versionada); **este handoff y los docs recientes**
  sin push (haz `git log origin/main..HEAD` para verlos).
- **`lib/rt64`** (fork): `hybrid-heaven` = `a8f0a70`.
- **`N64ModernRuntime` / `N64Recomp`**: en sync.
- Tags publicados: `v0.1.x`, `v0.2.0`, `v0.3.0`. **`v0.4.0` pendiente de tag.**
