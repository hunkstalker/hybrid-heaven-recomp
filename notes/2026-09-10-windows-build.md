# SESIÓN 2026-09-10 — Port WINDOWS compila y hace boot; pantalla negra (sin render)

> Cierra la tanda de "preparar build Windows". Resultado: el port **Windows compila, hace boot y
> corre el bucle del juego**, pero **no renderiza** (pantalla negra) — mismo estado que Linux Release.
> El siguiente bloqueante es **conseguir la primera tarea de render (RSP/display list)**.

## 0. Qué se consiguió

- **El port compila en Windows** (MSVC 2026 = VS "Visual Studio 18 2026", MSVC 19.51) y genera
  `Hybrid Heaven Recomp.exe`. Compila en **Release** y **Debug**.
- **Boot OK**: `init_heap → init_saving done → Calling entrypoint → Entrypoint returned`; ROM USA
  validada (hash `0x0F6A72F2C36A216D`); RT64 setup OK (Vulkan, GPU RTX 4080).
- **Threads del juego corren** y el bucle del juego avanza (`osSendMesg mq=0x8005C288`), frames
  avanzando. **Pantalla negra** = el juego aún NO emite su primera tarea de render (`submit_rsp_task`
  nunca aparece → no se dibuja nada). Igual que Linux Release.
- No se cierra solo (bucle infinito sin render) → hay que cerrarlo manualmente.

## 1. Cómo se compiló en Windows (receta real)

- Generador: `Visual Studio 18 2026` (VS 2026, no 2022). `-A x64`.
- `build_win` aparte de `build` (Linux) — **no reutilizar** el `build/` de Linux (CMakeCache con
  rutas `/app/...` incompatibles).
- Los `lib/rt64` y `lib/N64ModernRuntime` son repos vendored (gitignored del repo principal) que hay
  que clonar en sus commits exactos + aplicar el patch (`port/windows_runtime_changes.patch`).

## 2. FIXES DE PORTABILIDAD MSVC aplicados en esta tanda (críticos)

1. **`mesgqueue.cpp`**: quitar `__builtin_return_address` de la traza `osCreateMesgQueue` — **no
   existe en MSVC** (C3861). El build Windows fallaba ahí.
2. **`N64Recomp/include/recomp.h`**: añadir `cause_reg` y `cop0_regs[32]` al struct `recomp_context`
   y las declaraciones `cop0_cause_read/write`, `cop0_register_read/write` — las usaba el código
   recompilado (MFC0/MTC0 de cop0) y no estaban declaradas (rompía `recomp.cpp` y `funcs_5.c`).
   **Backup**: `config/n64recomp_changes/recomp.h` (N64Recomp es submódulo sin git).
3. **`threads.cpp` `osStopThread`**: ya no hace `assert(false)` al detener otro thread — lo
   desequilibra del run queue y lo marca `STOPPED` (restable con `osStartThread`). Arregla el crash
   `Assertion failed` de los builds **Debug** (en Release el assert es no-op por eso no se veía).

## 3. Estado de los repos

- **Main repo** (`/app/hybrid-heaven-recomp`): `RecompiledFuncs/` unificado (341 funcs, ya con
  osCreateViManager/osViSetMode/osVirtualToPhysical) + assets + src versionados. `port/windows_runtime_changes.patch`
  + `port/build_windows.bat` + `port/README_windows.md` para reproducir.
- **N64ModernRuntime** (repo anidado, gitignored): contiene los fixes de runtime en el working tree
  (VI event, thread hardening, mesgqueue, osStopThread). Su git interno quedó en `cdf5abb` + commits
  nuevos (el `git checkout cdf5abb` del usuario descartó commits intermedios, pero el contenido del
  patch está aplicado en el working tree y es lo que compila).
- **rt64**: sin cambios (solo el submódulo `spirv-cross` aparece "m" por modos).
- **N64Recomp**: submódulo sin git; cambios en `config/n64recomp_changes/{operations,recompilation,recomp}.h`.

## 4. Próximo bloqueante: RENDERIZAR (antes que audio)

El juego corre su bucle pero no emite la primera tarea de render. Del análisis del scheduler ya se
sabe la estructura: el state machine de render (`FUN_80001454`) que llama a `FUN_80029fa0`
(submit display task → `submit_rsp_task`) no se alcanza. Hay que ver por qué el game loop no llega a
emitir el primer display list (probablemente espera un evento/condición que dispara el primer frame
dibujado). **Va ANTES que la tarea de audio RSP (aspMain)**.
