# Hybrid Heaven Recomp — Build para Windows

Guía para compilar el port en Windows (MSVC / Visual Studio). La recompilación de funciones se hace
en el contenedor Linux; en Windows solo se compila y se prueba (`boot.log` / `hh.log`).

## Requisitos previos

- **Visual Studio 2022 o 2026** con el componente **Desktop development with C++** (MSVC + CMake).
- **Git** (para clonar/actualizar).
- La ROM retail: **`baserom.us.z64`** (Hybrid Heaven USA, 16 MB, hash `0x0F6A72F2C36A216DULL`),
  copiada junto al `.exe` generado o en el working directory.

## Estructura que debe existir en `port/HybridHeavenRecomp/`

```
port/HybridHeavenRecomp/
├── CMakeLists.txt          ← ya preparado (GLOB funcs_*.c, rsp/hh_aspMain.cpp, SDL2 win32, icono, DLLs)
├── RecompiledFuncs/        ← SET UNIFICADO ACTUAL (funcs_0..N + funcs.h + recomp_overlays.inl + lookup.cpp)
├── rsp/hh_aspMain.cpp      ← ucode de audio recompilado
├── assets/                 ← HybridHeaven.ico, app.rc.in, HybridHeaven.png, icon_bmp.inc
├── src/main/*.cpp          ← port (main, support, rt64_render_context, register_overlays, module_sources.inc)
├── lib/rt64/               ← repo rt64 (vendored, sin cambios)
└── lib/N64ModernRuntime/   ← repo N64ModernRuntime (vendored, CON NUESTROS FIXES)
```

> **IMPORTANTE:** los dos `lib/` son repos anidados con su propio `.git` (gitignored del repo
> principal). `rt64` va tal cual en `43373749dac9bbc1b653e6a02aed40a9e1783bed`. `N64ModernRuntime`
> debe estar en `fd6b0d0eedc922700f67bab8b770d3986187f3e9` + el patch de runtime.

## 1. Aplicar los fixes de runtime a N64ModernRuntime

`port/windows_runtime_changes.patch` contiene TODOS los cambios de runtime/librecomp que necesita el
port (VI, threads, mesgqueue, registro dinámico de módulos, **Controller Pak (PFS)**, `MEM_*`/`TO_PTR`
para direcciones no mapeadas, etc.). Base: `fd6b0d0eedc922700f67bab8b770d3986187f3e9`.

```bat
cd port\HybridHeavenRecomp\lib\N64ModernRuntime
git checkout fd6b0d0eedc922700f67bab8b770d3986187f3e9
git submodule update --init --recursive
git apply ..\..\..\..\windows_runtime_changes.patch
```

> Si no aplica limpio (base distinta), copia los archivos modificados que lista el patch
> (`librecomp/src/*`, `librecomp/include/librecomp/*`, `ultramodern/src/*`, `ultramodern/include/...`).

## 1b. Reparar el runtime si algo falla al compilar

`windows_runtime_changes.patch` lleva TODOS los cambios de runtime (incluye `hh_get_vi_count`,
`hh_missing.log`, Controller Pak, overlays, etc.). Si el runtime se ha revertido (p. ej. con
`--force-libs`) el link fallara con simbolos indefinidos. Reparacion:

```bat
cd port\HybridHeavenRecomp\lib\N64ModernRuntime
git -c safe.directory=* checkout -f fd6b0d0eedc922700f67bab8b770d3986187f3e9
git -c safe.directory=* apply ..\..\..\..\port\windows_runtime_changes.patch
```

Luego recompila con `port\build_windows.bat` y lanza con `run_windows.bat`.

## 2. Configurar y compilar

Recomendado: ejecutar `port\build_windows.bat`. Por defecto **omite git** si `lib\rt64` y
`lib\N64ModernRuntime` ya existen (evita cuelgues de git sobre unidades montadas), comprueba el patch
y compila en **Release** (la build Debug sin optimizar hace que el juego caiga a 30 fps y que el hilo
de audio solo produzca la mitad de buffers -> petardeo). Usa `build_windows.bat --force-libs` si
quieres clonar/actualizar las libs, o `--debug` solo para diagnosticar crashes.

Manual:

```bat
cd port\HybridHeavenRecomp
cmake -B build_win -G "Visual Studio 18 2026" -A x64   REM o "Visual Studio 17 2022"
cmake --build build_win --target HybridHeavenRecomp --config Release
```

- Exe: `build_win\bin\Release\Hybrid Heaven Recomp.exe` (con `--debug`: `build_win\bin\Debug\...`).
- El build copia automáticamente `SDL2.dll`, `dxcompiler.dll`, `dxil.dll` junto al `.exe`.
- ROM: copia `baserom.us.z64` junto al `.exe`.

## 3. Ejecutar y capturar logs

- **`hh.log`** → `%APPDATA%\HybridHeavenRecomp\hh.log` (setup RT64, validación de ROM, overlays).
- **`boot.log`** → junto al `.exe` — arranque y cualquier `Failed to find function at 0x...`.
- Capturas: `PrtScr` o cualquier grabador; RT64 también admite `RT64_*` envs si hace falta.

## 3b. Grabar una partida (para reproducir el crash)

Doble clic a **`port\run_windows.bat`**: graba tu partida automáticamente en
`hybrid-heaven-recomp\tests\mi_partida.txt` (no hay que configurar nada; hoy va comentado en
`run_windows.bat`, descomenta la línea `HH_RECORD` si la quieres). Juega hasta que crashee y
envía ese `.txt`. El replay en el contenedor es determinista (RMSE=0).

## 3c. Diagnóstico de audio (si suena a tirones)

El port escribe solo en su carpeta de trabajo (junto al .exe):

- **`hh_audio.log`** — una línea por segundo: `calls/s`, `frames/s`, cola pendiente, tasa del juego y
  del dispositivo. Lo correcto es ~60 calls/s y ~43.2k frames/s (720 frames por VI a 60 Hz).
- **`hh_rsp.log`** — duración media/máxima de la task de audio del RSP (debe ser < 16.7 ms).

Si el juego cae a 30 fps (habitación con mucha carga), el driver produce 720 frames por frame de
juego: a 30 fps solo son 21.6k frames/s y el dispositivo (43.2k) se queda sin datos. Ese es el motivo
de compilar en **Release**: con optimizaciones el juego mantiene 60 fps y el audio no se corta.

## 4. Estado actual esperado (2026-09-14, tarde)

- **GAME START funciona**: al pulsar START → GAME START el juego carga los overlays de código
  (idx8/9/10/12/55) y entra en la primera escena jugable con HUD (`work/debug/port_v3_*.png`).
- **Resolución**: por defecto Auto (escalado entero a la ventana). Override `HH_RES=original|2x|<n>`
  (p. ej. `set HH_RES=2x`).
- **Mando Xbox** (mapeo 2026-09-15): A = salto/acción; **B = agacharse** (Z); **Back/Select = mapa**
  (B); Start = START; LB = L; RB = apuntar (R); **Y = C-Up** (vista en 1ª persona, también arriba en el
  stick derecho); **X = B** (menús de combate cuerpo a cuerpo; en exploración abre también el mapa);
  **stick derecho = botones C** (digital, umbral 0.5); cruceta = D-pad; stick izquierdo = analógico
  (eje Y por defecto correcto; `HH_INVERT_Y=1` lo invierte). Libres: L3 y R3. Al arrancar
  el port imprime `[PAD]` con el mapeo activo y `[CFG]` con las envs. `port\run_windows.bat` lanza con
  las envs en la misma consola.
- **Si vuelve a crashear** (abort/assert): junto al `.exe` se escribe **`hh_missing.log`** con las
  direcciones `Failed to find function at 0x...`; pásalas y se añaden.
- Env útiles: `HH_RES=original|2x|<n>` (resolución), `HH_INVERT_Y=1` (eje), `HH_INPUTLOG`/`HH_PRESS*`
  y `HH_STICK=x,y` (input sintético para pruebas).

### Grabar y reproducir una partida (depuración determinista)

```bat
REM 1) Grabar tu partida (botones+stick) hasta justo antes del crash.
REM    Ruta absoluta = fiable; una relativa cae en el CWD (con run_windows.bat, en build_win\bin\Release).
set HH_RECORD=E:\mi_partida.txt
Hybrid Heaven Recomp.exe

REM 2) Reproducirla después (sin mando): el port mete exactamente el input grabado
set HH_RECORD=
set HH_REPLAY=E:\mi_partida.txt
Hybrid Heaven Recomp.exe
```

El replay es **por índice de poll** (una muestra por frame), así que reproduce la sesión píxel a píxel
(verificado RMSE=0). Envía el `.txt` grabado y se puede reproducir el fallo en el contenedor Linux.

## 4b. Estado anterior (2026-09-10)

- Boot completo, transición y burst de módulos; **renderiza** logo, pantalla de título, menú y
  **cutscenes 3D in-engine**.
- **Menú**: `START` → menú principal → `START` → GAME START/DIFFICULTY/EXIT → `A` entra en la intro
  (exige **Controller Pak**, ya emulado con PFS en RAM + `saves/*.bin.pak`).
- **Mando Xbox compatible** (SDL2 GameController):
  - `A`=A, `B`=B (y C-derecha), `X`=C-izq, `Y`=C-arriba, `LB`=L, `RB`=R, `Back`=Z, `Start`=Start,
    D-Pad, stick izquierdo (botón = C-abajo) y eje analógico.
  - Hot-plug soportado (`SDL_CONTROLLERDEVICEADDED/REMOVED`).
  - Rumble no implementado (no-op).
- Si sale `Failed to find function at 0xXXXX`: apuntar el vram, añadirlo en el contenedor Linux
  (`add_missing_funcs.py` / `config/module_extras.json`), regenerar el set y volver a copiar
  `RecompiledFuncs/` a Windows.

## 4c. Audio

El port inicializa el subsistema de audio de SDL (y `hh::init_audio()` corre antes de
`reset_audio()`). En Windows debe salir en consola
`SDL Audio Driver: wasapi` (o `directsound`) y oirse. Si no hay dispositivo, avisa y sigue sin sonido
(cola virtual). Para forzar driver: `set SDL_AUDIODRIVER=directsound` (o `wasapi`).
Nota: `queue_samples` recibe `sample_count` en muestras int16; el byte_len se calcula como
`sample_count * sizeof(int16_t)` (antes usaba bytes por frame y corrompia el heap al abrir dispositivo).

## 5. Problemas conocidos

- Frontera actual: cola del módulo 25 (`0x801FF260`, fuera del blob/syms actuales) y confirmación de
  gameplay interactivo (control/HUD).
- En Linux headless el input se prueba también con los envs `HH_PRESS*` (útil para automatizar).
