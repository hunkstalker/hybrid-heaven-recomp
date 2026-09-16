# 2026-09-16 — Limpieza de rutas/referencias y pipeline de compilación (ejecución del plan)

Nota de sesión. Ejecuta el plan consolidado
`notes/2026-09-16-plan-proxima-sesion-limpieza-rutas-y-build.md` por bloques 1 → 7; el bloque 8.B
(reescritura de identidad, destructivo) se prepara al final y los `force-push` los lanza el usuario.
Decisión estructural: **ADR 0006** (`docs/adr/0006-politica-de-rutas-relativas-y-contenido-externo.md`).

## Bloque 1 — Rutas y referencias

**Regla aplicada**: en todo lo publicado (docs vivos, `notes/`, `config/`, mensajes) se usan **rutas
relativas al repo**; se elimina cualquier ruta absoluta del entorno, ruta temporal del sistema,
unidad Windows, identidad local del entorno de desarrollo y nombres de fichero del proyecto de
referencia de Konami. Los forks se citan por **URL pública** y `docker/` conserva lo relativo a la
imagen Docker del proyecto.

Hecho:

- `AGENTS.md`: la regla de persistencia ya no cita rutas ni el entorno; ahora dice que **lo importante
  vive dentro del repo, bien clasificado** y que lo que deba conservarse se guarda en el repo.
- `PROYECTO.md`: se quitan las filas de identidad de la ROM (rutas/hashes) y se generaliza §4.
- `notes/` + `notes/archive/` (32 ficheros): rutas absolutas → relativas; rutas temporales →
  `work/debug/`; identidades locales → redacción neutra; "contenedor" narrativo → "entorno de
  desarrollo"; nombres de fichero del proyecto de referencia → frase neutra.
- `config/us_module*.syms.toml`: cabeceras `# Módulo: ...` con ruta relativa.
- `tools/README.md`, `docs/workflows.md`, `work/README_captura.md`: ejemplos relativos.
- `.dockerignore`: eliminada la entrada del tooling local; **esa carpeta borrada del repo**
  (`git rm -r`). Cero cadenas de ese tooling en lo publicado.
- `docs/documentation.md`: nota sobre datos generados (se producen localmente y no se versionan).

Pendiente en bloques siguientes: los scripts (`tools/analysis/*`, `work/*.sh`) y el runtime
(`events.cpp`) llevan raíz derivada del propio fichero / rutas relativas (Bloque 4).

## Bloque 2 — Icono

- `.gitignore`: se quita **solo** la línea de `assets/HybridHeaven.ico`; el `.ico` pasa a versionarse
  (verificado idéntico byte a byte al original de publicación). El icono de ventana (`.bmp`/
  `icon_bmp.inc`) sigue sin versionar y es opcional.
- `src/main/icon.cpp` y el comentario de `CMakeLists.txt` (Windows): aclarado que el `.ico` sí se
  versiona/embebe como recurso y que el `.bmp` de ventana es opcional.
- `Referencias screenshots/` ya estaba ignorada.

## Bloque 3 — ROM (opción A) y Docker

- `src/main/support.cpp` (`get_rom_candidates`): solo `<carpeta del .exe>/rom/baserom.us.z64`
  (oficial) y `<carpeta del .exe>/baserom.us.z64` (salvaguarda). **Se elimina** la búsqueda en el
  directorio de lanzamiento (CWD).
- Mensajes actualizados: `tools/build_linux.sh`, `port/build_windows.bat`, `port/run_windows.bat`,
  `README.md`, `port/README_windows.md`, `port/README_linux.md`.
- Docker (imagen de ejecución): el binario vive en `/work/hybrid-heaven-recomp` y la ROM se monta en
  `/work/rom/baserom.us.z64` (carpeta `rom/` junto al binario) → encaja con la búsqueda nueva.
  Actualizados `Dockerfile`, `docker/Dockerfile.runtime`, `docker/entrypoint.sh`,
  `docker-compose.yml` (volumen `./rom:/work/rom`) y `port/README_linux.md`. En la documentación de
  Docker se evita citar rutas absolutas del sistema (socket X11 descrito genéricamente).

## Bloque 4 — Arreglos funcionales (sin variables de entorno)

- `config/rsp_hh_aspMain.toml`: rutas relativas al directorio del `.toml` (`../work/...`), tal como
  resuelve `RSPRecomp` (`concat_if_not_empty(basedir, ...)`).
- `port/HybridHeavenRecomp/src/main/main.cpp`: el volcado de crash pasa a `hh_crash.log` en el
  directorio de trabajo (junto al `.exe`), como el resto de logs. Antes: ruta temporal del sistema.
- `support.cpp`: el fallback de carpeta de datos usa `temp_directory_path()` en vez de una ruta fija.
- `config/merge_loop.py`: deriva la raíz del repo de la ubicación del propio fichero.
- `tools/analysis/` (`analyze_rom.py`, `detect_lzkn64.py`, `textseg.py`, `test_lzkn64.py`,
  `scan_lzkn64_strict.py`, `gen_ghidra_syms.py`, `ghidra_recon.java`, `ghidra_scripts/ExportFuncsX.java`,
  `emu_ref.sh`, `fbdecode.py`, `r64dump.cpp`, `hhinput.c`, `retro_dump.cpp`): ROMs en `rom/...`, raíz
  derivada del script donde aplica, salidas en `work/debug/` y rutas relativas.
- `work/play.sh`, `work/cap_loop.sh`: raíz derivada de la ubicación del script; salidas en
  `work/...`.
- Runtime (fork `hunkstalker/N64ModernRuntime`): `ultramodern/src/events.cpp` escribe el volcado
  `port_vi*.bin` en `work/debug/` (relativo) en vez de una ruta absoluta (commit propio).

Verificado: build Linux incremental del port OK tras los cambios.

## Bloque 5 — Pipeline de compilación

- **`port/build_windows.local.bat`** (nuevo, **ignorado** en git): compila `lib/` tal cual, sin tocar
  git, avisa si faltan `lib/rt64` o `lib/N64ModernRuntime` e imprime ruta + commit del runtime local.
  Su contenido queda documentado en `port/README_windows.md` §2b para poder recrearlo.
- `.gitignore`: añadida la línea `port/build_windows.local.bat`.
- `port/runtime.lock`: `NMR_COMMIT` vuelve al SHA **publicado**
  `c976c89bbc8eb2d58d7e30b8d1e03d3ad822f7b1` y el comentario explica que el pin solo se mueve tras
  publicar (para probar local, el `.bat` local).
- `port/build_windows.bat`: imprime **siempre** la ruta + commit del runtime y si omitió git/revisó
  git, además del pin (`NMR_URL`@`NMR_COMMIT`). Mantiene el aborto si el commit fijado no existe.
- `TODO.md`: anotado el punto del `.bat` local y el pin.
- CI/Release: el flujo "build once, promote" de ADR 0005 no requiere cambios de código; queda
  pendiente publicar los commits de runtime, dejar el CI verde y etiquetar (`v*`).

## Bloque 6 — Lo que NO se toca

Sin cambios: el proyecto de referencia de Konami y su ROM (fuera del repo), la herramienta local de
símbolos, los manifiestos y `notes/reference/*` (locales, ignorados), las ROMs y las copias locales
de los forks.

## Bloque 7 — Verificación

- `git grep` sin rutas absolutas del entorno ni temporales del sistema, unidades Windows, identidades
  locales ni el nombre del tooling local en ficheros publicados: **limpio** (solo quedan
  `chunk`/`thunk` legítimos y las URLs de los forks).
- `python3 tools/analysis/docs_index.py --check`: **OK** (76 documentos).
- Compilación Linux (incremental, `build_dbg`): **OK** tras los cambios de código y del runtime.
- Icono: `.ico` versionado (idéntico byte a byte al de publicación); el recurso se embebe al compilar
  en Windows vía `CMakeLists.txt`/`app.rc.in`.
- Docker: cambios de rutas aplicados; el **smoke headless** queda pendiente (no hay Docker en el
  entorno de esta sesión). Al validar: `HH_HEADLESS=1` con `rom/` montado en `/work/rom`.
- `docs/INDEX.md` regenerado; `TODO.md`, `PROYECTO.md`, `RETOMAR.md` y `AGENTS.md` actualizados.

## Bloque 8 — Identidad de los commits (8.B, publicado)

Identidad objetivo: `Denis Anfruns Millán <daanfruns@gmail.com>` (author **y** committer) en **todo**
el historial propio de los 3 repos, **preservando intactos los commits upstream** (autores y firmas).

Método: **rebase/reescritura solo de los commits propios**, no `filter-branch` global. Se descartó
`filter-branch --all` porque reescribía también los commits de upstream (les quitaba la firma GPG).
- N64Recomp: `git rebase --exec 'git commit --amend --no-edit --reset-author' <base upstream>`
  (1 commit propio).
- N64ModernRuntime: reescritura de los 30 commits propios por la vía de objetos (`git commit-tree`
  con author/committer objetivo y fechas originales), sin tocar el árbol de trabajo (el montaje 9p
  del host da `Permission denied` al borrar/renombrar algunos ficheros). Luego se añade un commit
  que actualiza el gitlink de `N64Recomp` al SHA nuevo.
- Main: `filter-branch` sobre `main` (todos los commits son propios).

Cadena de SHAs (antes → después), con copias de seguridad en ramas `backup/pre-identidad`:

| Repo | Antes | Después |
|---|---|---|
| N64Recomp | `63069b9…` | `cab94d912ff858d6574974cead7dbbcca09e282f` |
| N64ModernRuntime (tip) | `6a518eb…` | `feae2d564bac2f31ba51865f2ead97de74d311d4` |
| N64ModernRuntime (= 725a5a8 reescrito) | `725a5a8…` | `c976c89bbc8eb2d58d7e30b8d1e03d3ad822f7b1` |

- `port/runtime.lock` apunta al **tip reescrito** (`feae2d5…`) y al SHA nuevo de N64Recomp.
- Referencias a SHAs de runtime en `TODO.md`/`notes/` actualizadas al mapa nuevo; las referencias a
  commits del repo `main` quedan como históricas (los hashes de `main` cambian al reescribirse).
- El commit de `events.cpp` del fork (antes `6a518eb…`) queda en `b01d4b4bcec…`.

## Publicación y verificación post-push

- **`force-push` hechos** (por el usuario), en orden: N64Recomp `cab94d9` → N64ModernRuntime `feae2d5`
  → main `0d283d5`. Remotos comprobados por `ls-remote`; copias de publicación resincronizadas.
- **Build Linux verificado**: `tools/build_linux.sh --force-libs` hace checkout de `rt64 4337374`,
  runtime `feae2d5` y submódulo `N64Recomp cab94d9`, y compila al 100% (`build_verify`, borrado).
- **Build Windows**: OK (usuario).
- **CI (GitHub Actions)**: compilación correcta tras el push.
- **Ramas de seguridad** `backup/pre-identidad`: el usuario las eliminó después de verificar. Los
  objetos viejos siguen en local hasta que caduquen reflogs/gc (por defecto 30–90 días).

## Resumen

Plan ejecutado por bloques 1→7, con un commit por bloque en `main` y un commit en el fork del runtime
(`ultramodern/src/events.cpp`); decisión estructural en **ADR 0006**. **8.B publicado** y build
Linux/Windows + CI verificados. Pendiente de gameplay: validar el guardado en cápsula en Windows
(UI de slots + `saves\hh.us.bin.pak` + `osPfsAllocateFile ... size=13568`).
