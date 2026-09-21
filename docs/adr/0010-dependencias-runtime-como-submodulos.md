# ADR 0010 — Dependencias del runtime como submódulos git (estándar del ecosistema)

- **Estado**: Aceptado (2026-09-20). Supersede la parte de **clonado por `port/runtime.lock`** de
  `0005-build-reproducible-y-artefactos.md` y la parte de **`RecompiledFuncs` como symlink** de
  `0009-no-versionar-c-recompilado.md` (el C sigue sin versionarse; cambia cómo se materializa).
- **Contexto**:
  - Hasta ahora `port/HybridHeavenRecomp/lib/{N64ModernRuntime,rt64}` vivían **fuera de git**
    (`.gitignore`) y se fijaban con `port/runtime.lock` (URL+SHA), clonados por
    `port/build_windows.bat` / `tools/build_linux.sh`. Ventaja: el mantenedor iteraba el fork local
    sin publicar (`build_windows.local.bat`). Coste: un clon limpio **no compila** sin el paso de
    clonado, el pin no lo enforce git y no es el mecanismo que espera el ecosistema N64Recomp (el
    repo de referencia y Zelda64Recomp/Wave Race usan submódulos).
  - Además, `port/HybridHeavenRecomp/RecompiledFuncs` era un **symlink** de Linux a
    `work/recomp/RecompiledFuncs`; en Windows el symlink no se resuelve y el build local abortaba
    con *"Faltan RecompiledFuncs/funcs_*.c"*.
- **Decisión**:
  1. **`lib/N64ModernRuntime` y `lib/rt64` son submódulos git** (`.gitmodules` + gitlinks) fijados a
     los commits de los forks. `git clone --recursive` / `git submodule update --init --recursive`
     los trae. `rt64` es upstream en su commit fijo; `N64ModernRuntime` es el fork propio, con su
     `.gitmodules` anidado (fork de `N64Recomp` + thirdparty).
  2. `port/runtime.lock` deja de ser la fuente canónica: queda como **referencia legible** y
     **fallback** de los scripts si `lib/` no existe y el submódulo no resuelve (p.ej. commit del
     fork aún sin publicar).
  3. `build_windows.bat` / `build_linux.sh` intentan **primero** `git submodule update --init
     --recursive`; si falla, caen al clonado por `runtime.lock`.
  4. **`build_windows.local.bat` se mantiene** como escape de desarrollo: compila `lib/` tal cual
     (sin tocar git), para iterar el fork sin publicar.
  5. El C recompilado sigue **sin versionarse**; `regenerate.py` lo materializa como **directorio
     real** `port/HybridHeavenRecomp/RecompiledFuncs/` (no symlink), para que Linux y Windows
     compilen igual.
  6. Los commits de los forks deben existir en el remoto para que un clon limpio/submódulo funcione;
     orden de push **N64Recomp → N64ModernRuntime → main** (ver `AGENTS.md`).
- **Consecuencias**:
  - Un clon limpio compila con `git clone --recursive` (más la ROM para regenerar el C). Se elimina
    el paso "clona las libs".
  - `git status`/`git log` del port reflejan el runtime; el pin no puede divergir en silencio.
  - **Coste**: cada cambio del fork exige commit+push y **bump** del gitlink en el port; mientras no
    se publique, el build estándar no lo ve (para eso está `build_windows.local.bat`).
  - Los gitlinks apuntan a commits **locales aún sin publicar** (`NMR 840a947`, `N64Recomp cab94d9`);
    hasta el force-push de los forks un clon nuevo fallará al inicializar el submódulo.
- **Alternativas**:
  - Mantener lock + clonado (estado anterior): descartado, no estándar y clon no reproducible.
  - `CMake FetchContent` con `GIT_TAG=<sha>`: viable, sin `.gitmodules`; peor para iterar el fork
    local y menos transparente.
  - `git subtree`/vendoring: descartado (fork activo, tamaño).
- **Criterio de salida**: `git clone --recursive` + `tools/regenerate.py` + build funciona en Linux
  y Windows sin pasos manuales de clonado; `build_windows.local.bat` sigue compilando el árbol local;
  `git submodule status` es la fuente de verdad del pin.
