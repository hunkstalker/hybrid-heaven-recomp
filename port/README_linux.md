# Hybrid Heaven Recomp — Linux

Binario Linux (x86_64, glibc) del port. **La ROM no se incluye**: al arrancar, el binario busca tu
copia de Hybrid Heaven (USA) — `NHVE`, 16 MB, hash `0x0F6A72F2C36A216DULL` — en la carpeta `rom/`
junto al binario (`rom/baserom.us.z64`); como salvaguarda también acepta `baserom.us.z64` junto al
binario.

## Ejecutar (nativo)

Dependencias de ejecución (Debian/Ubuntu):

```sh
sudo apt install libsdl2-2.0-0 libgtk-3-0 libvulkan1 mesa-vulkan-drivers
```

Arch/Steam Deck: `sudo pacman -S sdl2 gtk3 vulkan-icd-loader mesa`

```sh
./"Hybrid Heaven Recomp"          # GUI (Vulkan; necesita servidor gráfico)
```

- La config del mando se crea como `config.ini` junto al binario (editable).
- Los saves (Controller Pak) van a `saves/*.bin.pak` **junto al ejecutable** (portable). Si esa
  carpeta no es escribible se usa el directorio de datos del usuario; `HH_DATA_DIR=<ruta>` lo fuerza.
- Logs: `hh.log` (setup), `boot.log` (arranque), y en crash/cuelgue `hh_crash*.log`, `hh_hang*.log`.
- Envs útiles: `HH_RES=original|2x|<n>`, `HH_INVERT_Y=1`, `HH_AUDIODRIVER`/`SDL_AUDIODRIVER`, y para
  pruebas sin mando `HH_PRESS*`/`HH_STICK`.

### Headless (sin GPU ni display, p. ej. CI)

```sh
sudo apt install xvfb
VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  xvfb-run -a -s "-screen 0 1280x720x24" ./"Hybrid Heaven Recomp"
```

### Steam Deck

Modo escritorio → añadir como "juego no-Steam" (o desde la terminal). El binario es glibc x86_64;
instala las dependencias con `pacman` (arriba). Para el mando, usa el perfil por defecto
(`config.ini`, perfiles [game]/[menu] automáticos).

## Ejecutar con Docker

La ROM se monta en `rom/` junto al binario (`/work/rom/baserom.us.z64`):

```sh
mkdir -p rom && cp tu_copia.z64 rom/baserom.us.z64
docker run --rm -v "$PWD/rom:/work/rom:ro" \
  ghcr.io/hunkstalker/hybrid-heaven-recomp:latest
```

Con GPU y display (host Linux), añade el dispositivo Vulkan, `DISPLAY` y el **socket X11 del
sistema** (normalmente `.X11-unix`; consulta la documentación de Docker para tu SO):

```sh
docker run --rm --device /dev/dri \
  -e DISPLAY -v "$X11_SOCKET:.X11-unix:rw" \
  -v "$PWD/rom:/work/rom:ro" \
  ghcr.io/hunkstalker/hybrid-heaven-recomp:latest
```

Headless: añade `-e HH_HEADLESS=1`.

## Compilar desde fuente

- **Docker** (recomendado, reproducible): `docker compose build run`
- **Nativo**: `tools/build_linux.sh` (clona `rt64` de upstream y el runtime de su **fork** por
  URL+SHA de `port/runtime.lock`, con submódulos; luego compila). Dependencias de compilación:

```sh
sudo apt install build-essential cmake ninja-build git pkg-config \
  libsdl2-dev libvulkan-dev libx11-dev libxext-dev libxrandr-dev libxtst-dev libgtk-3-dev
```

El C recompilado (`RecompiledFuncs/`) está versionado: **no** hacen falta Ghidra ni N64Recomp
para compilar (solo para regenerar símbolos/módulos, que además requiere la ROM).
