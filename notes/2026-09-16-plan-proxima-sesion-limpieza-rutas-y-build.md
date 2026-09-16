# 2026-09-16 — Plan de la próxima sesión: limpieza de rutas/referencias y pipeline de compilación

Plan consolidado y **aprobado por el usuario** (queda ejecutarlo). Es la tarea que `RETOMAR.md` debe
apuntar al arrancar. Se ejecuta por bloques, **documentando antes de cada commit**.

## Reglas fijas del usuario

1. **Sin referencias a su equipo** (ni usuarios ni rutas de su PC).
2. **Sin referencias a nada fuera de la carpeta del repo** (nada de `/app/...`, `/tmp/...`, etc.).
3. **`AGENTS.md`** sin referencias a su equipo ni al contenedor; debe dejar claro que **lo importante
   vive dentro del repo, bien clasificado** (no en carpetas temporales del sistema).
4. Si algo es importante para el proyecto → **dentro del repo**, en su carpeta.

## Decisiones ya tomadas

- **Rutas**: relativas a la raíz del repo en todo lo publicado.
- **Icono**: publicar **solo** `port/HybridHeavenRecomp/assets/HybridHeaven.ico` (el que usa el
  compilador; idéntico byte a byte a `HybridHeavenV2.ico`). Nada más (ni `.bmp`, ni `.png`, ni
  `icon_bmp.inc`).
- **ROM**: ubicación oficial **`rom/` junto al ejecutable**; **una** salvaguarda: junto al `.exe`
  (opción **A**). Docker: binario y `rom/` bajo `/app` (imagen: `/app/hybrid-heaven-recomp` +
  `/app/rom/baserom.us.z64`).
- **`.opencode/` fuera del repo** (hoy hay 1 fichero versionado) y su línea en `.dockerignore`.
  **Cero cadenas "opencode"** en lo publicado.
- **Goemon**: se eliminan las menciones a sus ficheros; donde era el origen de nombres/algoritmo, se
  usa una frase neutra sin nombres.
- **Forks**: se mencionan por **URL pública** (`hunkstalker/N64ModernRuntime`, `hunkstalker/N64Recomp`).
- **3 ficheros locales** (`notes/us_manifest.yaml`, `notes/eu_manifest.yaml`,
  `notes/reference/n64sym_osfuncs_us_retail.txt`): **se quedan fuera** (son datos generados a partir
  de la ROM, no documentación; nadie que clone los necesita para compilar/jugar).
- **Identidad de los commits objetivo**: `Denis Anfruns Millán <daanfruns@gmail.com>`.
- **Build**: `.bat` local ignorado + pin al SHA **publicado** + traza del runtime usado.

## Bloque 1 — Rutas y referencias (todo lo publicado)

- Regla: rutas relativas al repo; nada de `/app`, `/tmp`, `C:\`, `E:\`, "hunk", "opencode".
- Ficheros con rutas fuera del repo (a limpiar):
  - `PROYECTO.md` → quitar toda referencia a la ROM (no debe mencionarla).
  - `RETOMAR.md`, `docs/workflows.md`, `tools/README.md`, `work/README_captura.md`,
    `work/cap_loop.sh`, `work/play.sh`, `AGENTS.md`.
  - `config/` (13): cabeceras de `config/us_module*.syms.toml` (`# Módulo: /app/...`) y
    `config/rsp_hh_aspMain.toml` (rutas absolutas).
  - `notes/` (15 ficheros) + `notes/archive/` (2).
- Sustituciones:
  - `/app/hybrid-heaven-recomp/...` → ruta relativa.
  - `/tmp/opencode/...` → `work/debug/...`.
  - Menciones a ROMs → lenguaje neutro ("la ROM que aporta el usuario, en `rom/baserom.us.z64`").
  - Menciones a las copias de los forks en `/app/N64ModernRuntime` y `/app/N64Recomp` → por URL
    pública del fork.
  - Menciones a `/app/goemon-sourcecode`, `goemon-baserom.us.z64` → eliminadas o frase neutra.
  - Identidad `opencode-hh <opencode@local>` en notas → redacción neutra ("los commits de los forks
    se hicieron desde el entorno de desarrollo").
  - Palabra "contenedor" narrativa (RETOMAR/TODO/notas) → "entorno de desarrollo" (en `docker/` se
    queda: habla de la imagen Docker del proyecto, que sí se publica).
- **`AGENTS.md`**: reescribir la regla de persistencia (líneas ~15-26, 72, 87) para que diga, sin
  rutas concretas: *"todo lo importante (repo, herramientas, ficheros de desarrollo) vive dentro del
  repo, bien clasificado; lo temporal puede quedar fuera, pero lo que deba conservarse se guarda en
  el repo"*.
- `docs/documentation.md`: línea neutra: los datos generados (manifiestos, listas de funciones) se
  generan localmente y **no** se versionan.
- `.dockerignore`: quitar `.opencode`. Borrar `.opencode/` del repo
  (`git rm -r .opencode`).

## Bloque 2 — Icono

- `.gitignore`: quitar **solo** la línea
  `port/HybridHeavenRecomp/assets/HybridHeaven.ico`; versionar ese fichero.
- `src/main/icon.cpp`: ajustar el comentario (hoy dice que no hay assets versionados). El icono de
  ventana (`.bmp`/`icon_bmp.inc`) sigue sin versionar y opcional; CMake ya lo maneja.
- Capturas (`Referencias screenshots/`) ya están ignoradas ✓ (verificado).

## Bloque 3 — ROM (código + Docker) — opción A

- `port/HybridHeavenRecomp/src/main/support.cpp` (`get_rom_candidates`): buscar **solo**
  `<carpeta del .exe>/rom/baserom.us.z64` (oficial) y `<carpeta del .exe>/baserom.us.z64`
  (salvaguarda). Eliminar los dos candidatos de la carpeta de lanzamiento (CWD).
- Mensajes: `tools/build_linux.sh`, `port/build_windows.bat`, `port/run_windows.bat`,
  `README.md`/`port/README_*.md` y `docker/entrypoint.sh` → "pon la ROM en la carpeta `rom` junto al
  ejecutable".
- Docker (imagen de ejecución): mover el binario a `/app/hybrid-heaven-recomp` y la ROM a
  `/app/rom/baserom.us.z64`; actualizar `docker/Dockerfile.runtime`, `Dockerfile`,
  `docker/entrypoint.sh`, `docker-compose.yml` y `port/README_linux.md`.

## Bloque 4 — Arreglos funcionales (para terceros; **sin variables de entorno**)

- `config/rsp_hh_aspMain.toml`: rutas relativas.
- `port/HybridHeavenRecomp/src/main/main.cpp`: `/tmp/hh_crash.log` → `hh_crash.log` (junto al exe,
  como el resto de logs).
- `config/merge_loop.py`: derivar la raíz del repo desde la ubicación del propio fichero.
- `tools/analysis/*` (`analyze_rom.py`, `detect_lzkn64.py`, `emu_ref.sh`, `fbdecode.py`,
  `gen_ghidra_syms.py`, `scan_lzkn64_strict.py`, `test_lzkn64.py`, `ghidra_scripts/*`) y
  `tools/README.md`: raíz derivada del propio script; ejemplos relativos.
- `work/cap_loop.sh`, `work/play.sh`: igual.
- Runtime (fork): `ultramodern/src/events.cpp` escribe un volcado en `/app/...` → ruta relativa
  `work/debug/` (sin `/app`, sin env). Commit en el fork (se publica con lo demás).

## Bloque 5 — Pipeline de compilación (detalle)

Estado actual: `port/build_windows.bat` (Windows) y `tools/build_linux.sh` (Linux) clonan el runtime
del fork por el SHA de `port/runtime.lock`; si `lib/` ya existe **omiten git** (se añadió porque git
se colgaba sobre la unidad montada) y compilan el árbol local. Consecuencia: los commits de runtime
de esta sesión se compilan en local, pero un clon limpio/`--force-libs`/CI necesita el SHA publicado.

Cambios:

1. **`port/build_windows.local.bat` (ignorado en git, solo para el usuario)**: compila `lib/` tal
   cual, **sin tocar git**, avisa si falta `lib/`, e imprime la ruta y el commit del runtime
   (`git -C lib\N64ModernRuntime rev-parse --short HEAD` si es repo).
2. **`.gitignore`**: añadir `port/build_windows.local.bat`.
3. **`port/runtime.lock`**: volver al SHA **publicado** (`725a5a827c9b2bc836fc8e4a5fa5dcd5f9bb3f9d`)
   y corregir el comentario (hoy dice "commit local"). Los commits de runtime de esta sesión se
   publican aparte (ver Bloque 8 / publicación) y entonces se sube el pin.
4. **`port/build_windows.bat`**: imprimir **siempre** qué runtime usa (ruta + commit + si omitió git);
   mantener el aborto si el commit fijado no está disponible.
5. **Docs**: `port/README_windows.md` (+ este plan/nota): explicar el flujo (pruebas locales con
   `build_windows.local.bat`; el pin solo se mueve tras publicar) e incluir el contenido del `.bat`
   local para poder recrearlo.
6. **CI/Release** (ya diseñado en ADR 0005: "build once, promote"): `ci.yml` compila en Linux
   (Docker) y Windows y sube artefactos; `release.yml` descarga artefactos de un CI verde y publica
   Release + imagen ghcr. **Pendiente**: publicar los commits de runtime, dejar el CI en verde y
   etiquetar (`v*`).
7. Dejar anotado en `TODO.md` (el usuario lo pidió expresamente) el punto del `.bat` local y el pin.

## Bloque 6 — Lo que NO se toca

- `/app/goemon-sourcecode` y `goemon-baserom.us.z64` (fuera del repo; no se tocan).
- `/app/gen_os_syms.py`: no es importante (no se usa en el repo; hay equivalentes en
  `tools/analysis/`). No se mueve.
- Manifiestos y `notes/reference/*` (locales, ignorados): se quedan como están.
- ROMs (las aporta el usuario) y copias de los forks (fuera del repo).

## Bloque 7 — Verificación

- `git grep` sin `/app`, `/tmp`, `C:\`, `E:\`, `hunk`, `opencode` en ficheros publicados.
- `python3 tools/analysis/docs_index.py --check` OK.
- Compilación Linux (`tools/build_linux.sh --build-dir build_dbg`) OK.
- Icono embebido en Windows (comprobar que el `.exe` lleva recurso).
- Docker: arranque headless con la ROM montada en `/app/rom` (smoke local).
- Al final, nota fechada + **ADR nuevo** (política de rutas relativas y contenido externo) +
  `docs/INDEX.md`, `TODO.md`, `RETOMAR.md`, `PROYECTO.md`.

## Bloque 8 — Identidad de los commits

Datos: en este entorno la identidad local es `opencode-hh <opencode@local>`.
- Repo principal: **195 commits** a ese nombre (188 publicados, **7 sin publicar**).
- Fork del runtime: 29 (24 publicados, **5 sin publicar**).
- Fork de N64Recomp: **1 commit** (`63069b9…`), publicado; el fork del runtime lo referencia por
  `.gitmodules`.

Identidad objetivo: `Denis Anfruns Millán <daanfruns@gmail.com>` (vincula a su cuenta de GitHub si
ese email está **añadido y verificado** en ella; si no, saldrá el nombre sin enlace).

**8.A — Solo lo no publicado (recomendado, sin force-push)**
1. Configurar identidad **local** en los 3 repos (`git config user.name/user.email`) — no tocar la
   global de Windows.
2. Reescribir los 7 de main: `git rebase --exec 'git commit --amend --no-edit --reset-author' origin/main`
   (autor y committer).
3. Reescribir los 5 del fork: `git rebase --exec 'git commit --amend --no-edit --reset-author' fork/hybrid-heaven`.
4. Push normal (lo hace el usuario).

**8.B — Todo el historial (ELEGIDO por el usuario; force-push + actualizar referencias)**

Objetivo: que **todos** los commits (publicados y no publicados) figuren como
`Denis Anfruns Millán <daanfruns@gmail.com>`, **author y committer**.

Orden obligatorio (por la cadena de referencias):

1. **N64Recomp** (fork): configurar identidad local, reescribir su único commit nuestro y
   **force-push** (`hunkstalker/N64Recomp`, rama `hybrid-heaven`). Anotar el SHA nuevo.
2. **N64ModernRuntime** (fork): configurar identidad local; actualizar el puntero del submódulo
   N64Recomp al SHA nuevo (el `.gitmodules` ya apunta al fork correcto; lo que cambia es el gitlink);
   reescribir su historia (29 commits nuestros) y **force-push** (`hunkstalker/N64ModernRuntime`,
   rama `hybrid-heaven`). Anotar el SHA nuevo.
3. **Main** (`hybrid-heaven-recomp`): configurar identidad local; actualizar `port/runtime.lock`
   (`NMR_COMMIT` = SHA nuevo; `N64RECOMP_COMMIT` = SHA nuevo); reescribir su historia (195 commits)
   y **force-push** (`origin main`). Anotar el SHA nuevo.
4. Actualizar referencias a SHA en `docs/`, `notes/` y `CREDITS.md` (texto) si las hubiera
   (p. ej. menciones a `725a5a8`, `63069b9`): deben apuntar a los SHAs nuevos.
   Nota: editar esas referencias **antes** del paso 3 (si no, habría que reescribir otra vez).

Herramientas: `git filter-branch --env-filter` (disponible; `git-filter-repo` no está instalado).
Alternativa más limpia si se instala: `git filter-repo --mailmap`.
Reescritura con `--env-filter`:

```
export GIT_AUTHOR_NAME="Denis Anfruns Millán"    ; export GIT_AUTHOR_EMAIL="daanfruns@gmail.com"
export GIT_COMMITTER_NAME="Denis Anfruns Millán" ; export GIT_COMMITTER_EMAIL="daanfruns@gmail.com"
git filter-branch -f --env-filter '
  export GIT_AUTHOR_NAME="Denis Anfruns Millán"; export GIT_AUTHOR_EMAIL="daanfruns@gmail.com"
  export GIT_COMMITTER_NAME="Denis Anfruns Millán"; export GIT_COMMITTER_EMAIL="daanfruns@gmail.com"
' --tag-name-filter cat -- --all
```

Confirmar después: `git log --format='%an <%ae> | %cn <%ce>' | sort -u` (deben quedar solo las
identidades nuestras y las de upstream).

Riesgo: force-push en repos públicos y jóvenes; hacerlo **antes** de que haya terceros clonando.
La reescritura en la carpeta compartida puede ir lenta (git ya se colgó ahí antes).

**Publicación (independiente de 8.A/8.B)**: cuando el fix del guardado esté validado →
`git push fork hybrid-heaven` (runtime) + `git push origin main` + **subir el pin** de
`runtime.lock` al SHA publicado.

## Orden de ejecución

1. Rutas y referencias (Bloque 1).
2. Icono (Bloque 2).
3. ROM + Docker (Bloque 3).
4. Arreglos funcionales + runtime `events.cpp` (Bloque 4).
5. Pipeline de compilación (Bloque 5).
6. Identidad de commits (Bloque 8) — requiere decisión 8.A/8.B.
7. Verificación (Bloque 7).
8. Documentar (nota + ADR) y commitear; al final, publicación (fork + main + pin).

## Decisiones tomadas (2026-09-16)

1. **Bloque 8**: **8.B** — aplicar `Denis Anfruns Millán <daanfruns@gmail.com>` a **todo** el
   historial (publicado y no publicado), con force-push y actualización de pins/referencias.
2. Email: `daanfruns@gmail.com` (el que usa en su equipo; vinculación a GitHub si está verificado
   en su cuenta).
3. **Sí** se reescribe también el campo *committer*.

## Pendiente aparte (gameplay)

- **Validar en Windows** el guardado en cápsula con el último fix (`osPfsFindFile` → 5 con
  `*file_no = -1`): en `hh_pak.log` debe verse `osPfsAllocateFile ... size=13568` y el guardado
  completar (`saves\` junto al `.exe`). Detalle:
  `notes/2026-09-16-guardado-capsula-pak-y-crash-cac-8021d8d0.md`.
- Los fixes de runtime de esta sesión siguen siendo **locales** hasta publicar el fork (con el pin
  publicado `725a5a8`, un clon limpio/`--force-libs` no los tendría).
