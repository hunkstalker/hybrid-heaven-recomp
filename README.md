# Hybrid Heaven Recomp (N64 → PC port)

Port a PC de **Hybrid Heaven** (N64, Konami Computer Entertainment Osaka, proyecto interno
**RZ011**) por **recompilación estática** con el stack N64Recomp + RT64 + N64ModernRuntime.
Plataformas objetivo: **Windows, Linux y Steam Deck**.

- **`PROYECTO.md`** → contexto maestro: motor Konami confirmado (tabla Nisitenma-Ichigo +
  LZKN64), mapa de la ROM, decisiones de arquitectura, roadmap y riesgos. **_Actualizar aquí
  en cada sesión._**
- **`docs/README.md`** → plan maestro, fases, stack y riesgos (detallado).
- **`notes/`** → notas de sesión e manifests de extracción (US/EU).
- **`tools/`** → herramientas propias (extracción de assets, shim LZKN64, análisis); ver
  `tools/README.md`.
- **`work/`** y **`toolchain/`** → artefactos derivados y herramientas, **gitignored**
  (ROMs del usuario descomprimidas, proyecto Ghidra, toolchain). El repo versionado queda
  limpio de assets (modelo No-Intro): el port requiere la ROM del usuario en runtime.

## Compilar y ejecutar

Modelo (igual que Zelda64Recomp/Goemon64Recomp): el repositorio incluye **todo lo necesario para
compilar el `.exe`** (el código del port, incluido el recompilado) y **no incluye datos del juego**
(ni la ROM, ni assets/capturas, ni textos extraídos). El `.exe`, **al ejecutarse, busca la ROM del
usuario y la procesa** para extraer los datos.

- **Compilar NO requiere la ROM.**
- **Ejecutar sí**: aporta tu copia de Hybrid Heaven (USA, `NHVE`, 16 MB, hash
  `0x0F6A72F2C36A216DULL`) como `rom/baserom.us.z64` (junto al ejecutable o en el directorio de
  trabajo) o `baserom.us.z64` junto al `.exe`/CWD. Nunca se distribuye la ROM ni una compilación con
  datos de ella.
- **No hace falta compilar para jugar**: descarga el `.zip` (Windows) o `.tar.gz` (Linux) de
  *Releases*.

| Plataforma | Comando | Requisitos |
|---|---|---|
| Windows | `port\build_windows.bat` | Visual Studio 2022/2026 (C++), CMake, Git |
| Linux | `tools/build_linux.sh` | gcc, CMake, Ninja, SDL2-dev, Vulkan-dev, X11-dev, GTK3-dev |
| Docker (Linux) | `docker compose build run` | Docker |

Los scripts **clonan las dependencias por URL+SHA fijados en `port/runtime.lock`**: `rt64` de su
upstream y `N64ModernRuntime` de un **fork propio** (rama `hybrid-heaven`, con nuestros cambios y su
submódulo `N64Recomp`). Guías: `port/README_windows.md`, `port/README_linux.md`,
`docs/workflows.md` §1, `docs/adr/0005`.

> Solo para **mantenedores**: si tocas los símbolos del recompilador, regenera el C con tu ROM
> (`tools/setup_module.py --build`, `tools/recomp.py --config config/game_combined.toml --force` y
> `RSPRecomp`); el resultado sí se versiona porque es el código del port.

## Estado

El estado y las tareas viven en **`PROYECTO.md`**, **`TODO.md`** y **`RETOMAR.md`** (una sola fuente
por tema; aquí no se duplican). Para arrancar una sesión: `AGENTS.md`.

## Créditos y licencias

El port se apoya en proyectos de terceros: **N64ModernRuntime** (GPL-3.0, equipo N64Recomp),
**N64Recomp** y **RT64** (MIT), más xxHash/miniz/o1heap. Autoría, licencias y commits exactos:
[`CREDITS.md`](CREDITS.md). El repositorio **no** incluye la ROM de Hybrid Heaven (© Konami): la
aporta cada usuario en runtime.