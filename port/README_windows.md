# Hybrid Heaven Recomp — Build para Windows

Guía para compilar el port en Windows (MSVC / Visual Studio). Los cambios de runtime y la
generación de funciones se hacen en el contenedor Linux; en Windows solo se compila y se prueban
`boot.log` / `hh.log`.

## Requisitos previos

- **Visual Studio 2022** con el componente **Desktop development with C++** (MSVC + CMake).
- **Git** (para clonar/actualizar).
- La ROM retail: **`baserom.us.z64`** (Hybrid Heaven USA, 16 MB, hash `0x0F6A72F2C36A216DULL`),
  copiada junto al `.exe` generado o en el working directory.

## Estructura que debe existir en `port/HybridHeavenRecomp/`

```
port/HybridHeavenRecomp/
├── CMakeLists.txt          ← ya preparado (GLOB funcs_*.c, SDL2 win32, icono, DLLs)
├── RecompiledFuncs/        ← SET UNIFICADO (341 funcs, funcs_0..6 + lookup.cpp + recomp_overlays.inl) — YA GENERADO
├── assets/                 ← HybridHeaven.ico, app.rc.in, HybridHeaven.png, icon_bmp.inc
├── lib/
│   ├── rt64/               ← repos rt64 (SUBMODULE vendored, sin cambios)
│   └── N64ModernRuntime/   ← repos N64ModernRuntime (SUBMODULE vendored, CON NUESTROS FIXES)
└── src/main/*.cpp          ← port (main, support, rt64_render_context, register_overlays)
```

> **IMPORTANTE:** los dos `lib/` son repos anidados versionados en su propio `.git` (gitignored del
> repo principal). `rt64` va tal cual. `N64ModernRuntime` debe tener los fixes de runtime.

## 1. Aplicar los fixes de runtime a N64ModernRuntime (Windows)

El patch `port/windows_runtime_changes.patch` contiene TODOS los cambios de runtime/librecomp que
necesita el port (fix deadlock VI, endurecimiento de threads, `register_flat_code`, etc.). Se generó
contra la base upstream `cdf5abb` ("Add CLI options to select games and game modes. (#153)").

Si tu `N64ModernRuntime` está en ese commit base (o más arriba y no tienes esos fixes):

```bat
cd port\HybridHeavenRecomp\lib\N64ModernRuntime
git apply ..\..\..\..\windows_runtime_changes.patch
```

> Si no aplica limpio (base distinta), copia los archivos modificados que lista el patch:
> `librecomp/src/overlays.cpp`, `librecomp/src/recomp.cpp`, `librecomp/include/librecomp/{addresses,overlays}.hpp`,
> `librecomp/CMakeLists.txt`, `ultramodern/CMakeLists.txt`,
> `ultramodern/src/{threads,mesgqueue,events}.cpp`,
> `ultramodern/include/ultramodern/ultramodern.hpp`.

## 2. Configurar y compilar

```bat
cd port\HybridHeavenRecomp
cmake -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --target HybridHeavenRecomp --config Debug
```

- Exe: `build\bin\Debug\Hybrid Heaven Recomp.exe`.
- El build copia automáticamente `SDL2.dll`, `dxcompiler.dll`, `dxil.dll` junto al `.exe`.
- ROM: copia `baserom.us.z64` junto al `.exe`.

## 3. Ejecutar y capturar logs

```bat
cd build\bin\Debug
Hybrid Heaven Recomp.exe
```

- **`hh.log`** → `%APPDATA%\HybridHeavenRecomp\hh.log` (setup RT64, ROM validation, overlay register).
- **`boot.log`** → en el CWD (junto al `.exe`) — orden de arranque: `init_heap → init_saving done →
  Calling entrypoint → Entrypoint returned`, threads del juego, y **any `Failed to find function at
  0x...`** (imprime el vram para mapearlo en el syms).
- Cópialos y pégalos en el chat para iterar.

## 4. Estado actual esperado (2026-09-10)

- El boot llega a `Entrypoint returned`, crea los threads del juego y el juego **corre estable**
  (frames avanzan; verificado en Linux headless).
- El **scheduler del motor Konami** ya no deadlockea (fix osCreateViManager/osViSetMode).
- Si sale `Failed to find function at 0xXXXX` → añadir ese vram a
  `config/us_unified.syms.toml` (nombre `FUN_XXXX`), regenerar el set en el contenedor y
  volver a copiar a `RecompiledFuncs/`.

## Notas

- **N64Recomp** en Windows genera `.lib` (no `.exe`), por eso **no** se regenera en Windows: se usa
  el set ya generado en Linux. Solo se regenera en el contenedor:
  `config/RecompiledFuncs_unified` + copiar a `port/HybridHeavenRecomp/RecompiledFuncs/`.
- `config/game_unified.toml` + `config/us_unified.syms.toml` definen la generación (no se tocan en
  Windows salvo para añadir funciones en el syms).
