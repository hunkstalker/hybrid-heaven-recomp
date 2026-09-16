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

La ROM **no** se distribuye: necesitas tu copia de Hybrid Heaven (USA, `NHVE`, 16 MB, hash
`0x0F6A72F2C36A216DULL`) como `baserom.us.z64` junto al ejecutable o en el directorio de trabajo.

**Binarios listos**: descarga el `.zip` (Windows) o `.tar.gz` (Linux) de *Releases* y aporta tu ROM.

| Plataforma | Comando | Requisitos |
|---|---|---|
| Windows | `port\build_windows.bat` | Visual Studio 2022/2026 (C++), CMake, Git |
| Linux | `tools/build_linux.sh` | gcc, CMake, Ninja, SDL2-dev, Vulkan-dev, X11-dev, GTK3-dev |
| Docker (Linux) | `docker compose build run` | Docker (la imagen clona las libs y compila) |

Ambos scripts **clonan las dependencias por URL+SHA fijados en `port/runtime.lock`**: `rt64` de
su upstream y `N64ModernRuntime` de un **fork propio** (rama `hybrid-heaven`) que incluye
nuestros cambios y cuyo submódulo `N64Recomp` también sale de un fork. Esos directorios están en
`.gitignore`, así que los scripts son la forma de reproducirlos. Guías:
`port/README_windows.md`, `port/README_linux.md`, `docs/workflows.md` §1.

## Estado

El estado y las tareas viven en **`PROYECTO.md`**, **`TODO.md`** y **`RETOMAR.md`** (una sola fuente
por tema; aquí no se duplican). Para arrancar una sesión: `AGENTS.md`.

## Créditos y licencias

El port se apoya en proyectos de terceros: **N64ModernRuntime** (GPL-3.0, equipo N64Recomp),
**N64Recomp** y **RT64** (MIT), más xxHash/miniz/o1heap. Autoría, licencias y commits exactos:
[`CREDITS.md`](CREDITS.md). El repositorio **no** incluye la ROM de Hybrid Heaven (© Konami): la
aporta cada usuario en runtime.