# RETOMAR — handoff

> Handoff para **sesión nueva**. **Última sesión: 2026-09-23.**

## Terminología clave (LEER — evita malinterpretaciones)

Hay que distinguir **dos cosas muy distintas**, porque los nombres se solapan:

1. **Motor de TEXTO del juego** = la rutina que dibuja caracteres (fuente, glifos, color, layout).
   - **SÍ se reutiliza** (se quiere estilo idéntico). Es el "backend_game" de `hh_font`.
   - Es lo que hay que entender: `0x8001BC04` (colocar texto) ← `0x8001B204` (set entrada de menú).
2. **Menú del JUEGO** = las pantallas de opciones del propio juego (título/sonido/resolución) y su
   navegación/estado en el módulo 23.
   - **NO se reutiliza ni se parchea.** Ya se intentó y **falló** (ver abajo): el módulo 23 está
     **empaquetado** (no hay offsets de texto libres) y los *overrides* corrompían el menú
     principal. **Esos overrides quedan DESACTIVADOS** en `src/hooks/sections.cpp`.
   - El **menú (entradas, cursor, acciones) lo construye el PORT** (`hh_menu`), sobre su propia
     pantalla, usando el motor de texto del juego para dibujar.

Frase-resumen: **"reutilizar el motor de TEXTO del juego, NO el menú del juego"**.

## ORDEN acordado: B ANTES que A2 (no confundir)

El mantenedor decidió **atacar B (fuentes/acentos) ANTES de implementar A2 (el menú)**:

- **Por qué**: B hay que hacerlo **sí o sí** (el ROM USA no trae acentos; el motor EUC-JP necesita
  gaiji). Si se hace el menú primero, los rótulos tendrían que ir en **ASCII provisional**
  (`ESPANOL`, `CATALA`, `FRANCAIS`) y habría que **rehacerlos** al llegar los acentos. Haciendo B
  primero, los rótulos salen bien (`ESPAÑOL`, `CATALÀ`, `FRANÇAIS`) a la primera.
- **Consecuencia**: **A2 queda EN PAUSA** hasta que B esté resuelto. El siguiente trabajo real es **B**
  (localizar la textura de fuente + mapear/meter los glifos con acento), no A2.
- Lo único de A2 ya hecho es la **decisión de arquitectura** (`hh_menu → hh_font → backend_game`) y los
  intentos descartados; **no** hay que seguir por ahí todavía.
- Matiz: el "motor de texto del juego" (backend_game) y B comparten trabajo (la fuente), por eso
  hacer B primero también prepara el camino para A2.

**Siguiente paso real: B.** Ver `notes/2026-09-23-b-motor-texto-localizado.md` y
`notes/2026-09-23-b-fuente-localizacion.md` y `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`.

## Tarea de ESTA sesión: spike de traducción (menús) → base del selector de idioma

Objetivo original: probar que podemos **traducir en runtime** y ver cambiar textos **del menú del
juego** en pantalla (base del selector de idioma del ADR 0008). Sería la **primera traducción al
español** del juego. (Ojo: "textos del menú" = los rótulos del menú *del juego*; eso NO implica
reutilizar el menú del juego, ver Terminología.)

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
4. [•] **A2 — menú PC in-game (AJUSTES → IDIOMA / SONIDO)** (requisito del mantenedor). **El port
   construye el menú**; se reutiliza solo el **motor de texto del juego** para el estilo. Arquitectura
   `hh_menu → hh_font → backend_game` (+ `backend_modern` futuro para fuentes HD).
   **Motor de texto localizado**: `0x8001B204` (set entrada) → `0x8001BC04` (colocar texto; color
   `0x8009E48..E4F`). Diagnóstico `HH_MENUTRACE=1`.
   **Cronología de errores a NO repetir** (ver `notes/2026-09-23-a2-plan-menu-ajustes-idioma.md`):
   - *Overrides* de las funciones de menú del juego (`0x801C4960/0x801C4AA8/0x801C5108/0x801C5378`) y
     reutilización de offsets de texto del módulo 23 → **corrompían el menú** (idioma con sonido,
     entradas movidas, menú roto). **Descartado.** Overrides **desactivados** en `sections.cpp`.
   - Texto nuevo fuera del módulo (buffers propios) → posible, PERO el mantenedor eligió el camino 1
     (motor del juego) por estilo idéntico y porque **B (fuente/acentos) hay que hacerlo sí o sí**.
   **Siguiente**: entender `0x8001BC04` (firma de colocar texto) → `hh_font`/`backend_game`.
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

- **`v0.4.0` YA está publicado** (tag en `origin`, commit `c977bd5`). Su **gitlink de `lib/rt64`
  apunta al fork `a8f0a70`** (correcto) y `.gitmodules` también usa el fork → un clon con
  submódulos obtiene lo correcto. **No borrar/re-tag.**
- **Defecto conocido de v0.4.0** (corregido ya en `main`): su `build_windows.bat` clonaba de
  **upstream** `rt64/rt64` en `4337374` (perdía el fix 2D) si no se inicializaban submódulos.
  Ahora el script lee `RT64_URL`/`RT64_COMMIT` de `runtime.lock` (fork, `a8f0a70`).
- **Plan**: dejar v0.4.0 como está (**a**) y publicar **`v0.4.1`** con este arreglo cuando toque la
  próxima release (**c**).
- Pendiente de push (normal): los commits locales de `main` (incluido el arreglo).
  ```powershell
  git -C hybrid-heaven-recomp push origin main
  ```
  Recuerda: el repo principal requiere **`--force-with-lease`** (ver AGENTS.md §Push).

## Qué toca después

**Prioridad: B (fuentes/acentos)** — el mantenedor decidió hacer B **antes** que A2 (ver "ORDEN
acordado"). Pasos:
1. Localizar la **textura de fuente** del módulo 23 y la rutina que mapea `código EUC → tile`
   (arrancando de `0x8001BC04`, la de "colocar texto").
2. Determinar qué glifos con acento hay (¿`á í ó ú ñ ¿ ¡`?) y añadir los que falten (o transplantar
   los gaiji de la PAL). Ver `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`.
3. Con B resuelto, retomar **A2**: menú **AJUSTES → IDIOMA / SONIDO** dibujado por el port con el
   motor de texto del juego (`hh_font`/`backend_game`). **NO reutilizar el menú del juego.**

Contexto: `notes/2026-09-23-b-motor-texto-localizado.md`, `-b-fuente-localizacion.md`,
`-texto-euc-jp-y-glifos-pal.md`, `-a2-plan-menu-ajustes-idioma.md`.

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

- **`main`**: `origin/main` = `c977bd5` (v0.4.0). Locales sin push: el commit de traducción/idiomas
  (`ac4a89f`) y el arreglo de pin de rt64 (`build_windows.bat`/`runtime.lock`).
- **`lib/rt64`** (fork): `hybrid-heaven` = `a8f0a70` (gitlink correcto; árbol limpio).
- **`N64ModernRuntime` / `N64Recomp`**: en sync.
- Tags publicados: `v0.1.x`, `v0.2.0`, `v0.3.0`, **`v0.4.0`**. Próximo: `v0.4.1` (arreglo del script).
