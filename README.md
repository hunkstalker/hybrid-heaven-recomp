# Hybrid Heaven Recomp (N64 → PC port)

Port a PC de **Hybrid Heaven** (N64, Konami Computer Entertainment Osaka, proyecto interno
**RZ011**) por **recompilación estática** con el stack N64Recomp + RT64 + N64ModernRuntime.
Plataformas objetivo: **Windows, Linux y Steam Deck**.

> **⚠️ Proyecto EN DESARROLLO (fase temprana).** No está terminado: puede haber fallos,
> incompatibilidades, regresiones y cambios que rompan partidas guardadas. Las builds de *Releases*
> son de prueba. El estado real y las tareas: `PROYECTO.md` y `TODO.md`.

- **`PROYECTO.md`** → contexto maestro: motor Konami confirmado (tabla Nisitenma-Ichigo +
  LZKN64), mapa de la ROM, decisiones de arquitectura, roadmap y riesgos. **_Actualizar aquí
  en cada sesión._**
- **`docs/README.md`** → plan maestro, fases, stack y riesgos (detallado).
- **`notes/`** → notas de sesión e manifests de extracción (US/EU).
- **`tools/`** → herramientas propias (extracción de assets, shim LZKN64, análisis); ver
  `tools/README.md`.
- **`work/`** y **`toolchain/`** → artefactos derivados y herramientas, **gitignored**
  (ROMs del usuario, proyecto Ghidra, toolchain, C recompilado). El repo versionado queda limpio de
  assets y del código derivado (modelo No-Intro; ADR 0009): el port requiere la ROM del usuario.

## Compilar y ejecutar

Modelo (igual que Goemon64Recomp / Zelda64Recomp): el repositorio guarda **el port y sus
herramientas**, y **no incluye datos del juego ni el código recompilado** (que es una traducción del
binario del juego, obra derivada). El código recompilado se **regenera una vez desde tu ROM** antes
de compilar.

- **Compilar requiere la ROM** (una vez, para recompilar): `python3 tools/regenerate.py` (necesita
  JDK 21 + Ghidra + N64Recomp; ver `docs/workflows.md`). El C generado vive en `work/recomp/` y
  `regenerate.py` lo materializa como directorio real en `port/HybridHeavenRecomp/RecompiledFuncs/`.
- **Ejecutar también**: aporta tu copia de Hybrid Heaven (USA, `NHVE`, 16 MB, hash
  `0x0F6A72F2C36A216DULL`) en la carpeta `rom/` junto al ejecutable (`rom/baserom.us.z64`); como
  salvaguarda también se acepta `baserom.us.z64` junto al `.exe`. Nunca se distribuye la ROM ni una
  compilación con datos de ella.
- **No hace falta compilar para jugar**: descarga el `.zip` (Windows) o `.tar.gz` (Linux) de
  *Releases*.

| Plataforma | Comando | Requisitos |
|---|---|---|
| Windows | `port\build_windows.bat` | Visual Studio 2022/2026 (C++), CMake, Git |
| Linux | `tools/build_linux.sh` | gcc, CMake, Ninja, SDL2-dev, Vulkan-dev, X11-dev, GTK3-dev |
| Docker (Linux) | `docker compose build run` | Docker |

Los scripts usan los **submódulos git** `port/HybridHeavenRecomp/lib/rt64` (upstream) y
`.../lib/N64ModernRuntime` (**fork propio**, rama `hybrid-heaven`, con su submódulo `N64Recomp`):
`git clone --recursive` (o `git submodule update --init --recursive`) los trae;
`port/runtime.lock` queda como referencia/fallback. Guías: `port/README_windows.md`,
`port/README_linux.md`, `docs/workflows.md` §1, `docs/adr/0005`, `docs/adr/0010`.

> Solo para **mantenedores**: regenera el C con tu ROM (`python3 tools/regenerate.py`). El C
> recompilado **no se versiona** (ADR 0009); se genera en `work/recomp/` y es la entrada de build.

## Estado

El estado y las tareas viven en **`PROYECTO.md`**, **`TODO.md`** y **`RETOMAR.md`** (una sola fuente
por tema; aquí no se duplican). Para arrancar una sesión: `AGENTS.md`.

## Licencia

**Software libre bajo GPL-3.0** — ver [`LICENSE`](LICENSE). Es un proyecto **público y
comunitario**: nace de recompilación estática con ayuda de IA (entrenada con código de la
comunidad), así que devuelve el resultado a la comunidad con las mismas libertades. Al enlazar
**N64ModernRuntime (GPL-3.0)**, esta licencia es compatible y cumple los requisitos (fuente
disponible + avisos).

## Créditos y licencias de terceros

El port se apoya en: **N64ModernRuntime** (GPL-3.0, equipo N64Recomp), **N64Recomp** y **RT64**
(MIT), más xxHash/miniz/o1heap. Autoría, licencias y commits exactos: [`CREDITS.md`](CREDITS.md).
El repositorio **no** incluye la ROM de Hybrid Heaven (© Konami): la aporta cada usuario en runtime.