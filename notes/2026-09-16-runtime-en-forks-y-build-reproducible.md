# 2026-09-16 — Runtime en forks propios y build reproducible (sustituye el snapshot)

> Consolida el trabajo del día: receta de build (script + Docker + CI), hallazgo del commit local y
> **decisión final: forks**. Sustituye a `2026-09-16-nmr-snapshot-y-build-reproducible.md` (snapshot,
> intermedio y descartado).

## Hallazgo: el runtime no era reproducible desde upstream

- `fd6b0d0eedc922700f67bab8b770d3986187f3e9` (base del patch) **es un commit LOCAL** del proyecto
  (`opencode-hh <opencode@local>`); `origin/main` = `cdf5abb` es su ancestro. Nunca se publicó → un
  clon limpio no puede `checkout fd6b0d0`.
- Además, `windows_runtime_changes.patch` se generó con `--ignore-submodules=all`, así que **no
  incluye** los cambios del submódulo **N64Recomp** (`include/recomp.h` con los `MEM_*` seguros y
  `src/symbol_lists.cpp`), que `librecomp` **compila** dentro del port.
- Los 23 commits del runtime estaban en **HEAD detached** (sin rama): sólo el reflog los referenciaba.
- Detección: todo funcionaba en las máquinas con `lib/N64ModernRuntime` ya presente; el camino de clon
  limpio (`--force-libs`, Docker/CI) nunca se ejercitó.

## Decisión (usuario): forks reales

Publicar los cambios en **forks de GitHub** con `main` = upstream (crédito/lineage), nuestros commits
en la rama **`hybrid-heaven`**:

- `hunkstalker/N64ModernRuntime` — 23 commits del runtime + 1 que apunta el submódulo al fork y
  actualiza `.gitmodules` → HEAD de la rama `725a5a827c9b2bc836fc8e4a5fa5dcd5f9bb3f9d`.
- `hunkstalker/N64Recomp` — `include/recomp.h` + `src/symbol_lists.cpp` →
  `63069b9176310ba78b4fe76476d86f0b0d584ae6`.

El build clona por **URL+SHA de `port/runtime.lock`**; sin patch y sin snapshot. `rt64` sigue
clonándose de upstream en commit fijo (sin modificar). Ver ADR 0005.

## Implementación

- `port/runtime.lock` (nuevo): `NMR_URL` + `NMR_COMMIT` (+ referencias a N64Recomp).
- `tools/build_linux.sh`: reescrito (clon `--recursive` del fork + `checkout` del SHA + submódulos);
  fuera snapshot y patch. Flags: `--force-libs/--debug/--build-dir/--jobs/--configure-only/--libs-only`.
- `port/build_windows.bat`: lee `runtime.lock`, clona el fork y hace checkout + submódulos; fuera
  snapshot y patch.
- `Dockerfile`/`.dockerignore`: la capa de libs clona los forks; sin snapshot.
- Retirados: `lib_snapshots/`, `tools/analysis/make_nmr_snapshot.sh`,
  `port/windows_runtime_changes.patch`, `port/bisect_build.bat`, `port/bisect_extra.patch`
  (dependían del mecanismo de patch).
- Copias de publicación en la raíz del workspace: `/app/N64ModernRuntime` y `/app/N64Recomp`
  (con remotos `origin`=upstream y `fork`=propio). Los push los hizo el usuario desde Windows.
- Docs: `CREDITS.md` (forks + lineage + GPLv3), `README`, `port/README_windows.md`,
  `port/README_linux.md`, `docs/workflows.md` §1.1, `RETOMAR/PROYECTO/TODO`, ADR 0005.

## Validación

- Push verificado con `git ls-remote`: `main` de ambos forks = upstream y `hybrid-heaven` = nuestros
  SHA esperados (725a5a8… y 63069b9…).
- `sh -n` de scripts, YAML de workflows/compose y `docs_index.py --check` OK.
- Pendiente de validar en CI (primer push del port): build Linux por Docker y Windows en
  `windows-latest` (clon limpio de los forks).

## Modelo final: qué va y qué no va en el repo (aclarado por el usuario)

Igual que Zelda64Recomp/Goemon64Recomp: **el `.exe` se compila SIN ROM** y, **al ejecutarse, busca la
ROM del usuario y extrae de ella los datos**. Nadie está obligado a compilar (hay binarios en
*Releases*).

- **Sí se versiona**: el código del port, **incluido el C recompilado** (`RecompiledFuncs/`) y el
  ucode (`rsp/hh_aspMain.cpp`), más `config/*.syms.toml`/`keep_syms*`/`rsp_hh_aspMain.toml`
  (configuración/metadatos del recompilador).
- **No se versiona**: la ROM ni **datos del juego** (capturas, iconos/logo, textos/manifiestos
  extraídos, dumps de símbolos). Se **purgaron de todo el historial** (filter-branch + `gc`; `.git`
  284 MB → 1 MB). El `.exe` carga la ROM de `rom/baserom.us.z64` (o junto al ejecutable/CWD).
- `.gitignore` bloquea `work/`, `rom/`, `*.z64` y los datos/assets; CMake avisa si faltara el C del
  port. CI vuelve a compilar (Linux Docker + Windows) y los releases son automáticos por tag.

## Pendiente / diferido

- **Regeneración** (syms→C): rama `hybrid-heaven-tool` en el fork de N64Recomp (la herramienta tiene
  13 archivos modificados) + ROM; fuera del build reproducible.
- **`LICENSE`** GPL-3.0-compatible del proyecto (los binarios enlazan NMR).
- (Opcional) selector de ROM tipo menú; hoy se carga de `rom/`.
- Identidad de los commits de los forks: `opencode-hh <opencode@local>` (igual que los 23 previos);
  si se quiere atribuir a la cuenta de GitHub, reescribir antes de nuevos push.
