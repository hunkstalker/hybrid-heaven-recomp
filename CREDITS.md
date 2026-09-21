# Créditos y licencias de terceros

Este proyecto **no** distribuye la ROM de Hybrid Heaven (© Konami): cada usuario aporta la suya
(`baserom.us.z64`) en runtime. Lo que sí usa y, cuando su licencia lo permite, redistribuye, es lo
siguiente. Se conservan sus avisos de copyright y licencias.

## Runtime y recompilación

| Proyecto | Autoría | Licencia | Uso en el port |
|---|---|---|---|
| [N64ModernRuntime](https://github.com/N64Recomp/N64ModernRuntime) | equipo N64Recomp: Mr-Wiseguy (Wiseguy), David Chavez, Anghelo Carvajal, Garrett Smith, dcvz, Darío, Reonu y colaboradores | **GPL-3.0** | runtime del port (`ultramodern` + `librecomp`) |
| [N64Recomp](https://github.com/N64Recomp/N64Recomp) | Mr-Wiseguy (Wiseguy) y colaboradores | MIT | recompilador MIPS→C (toolchain) y submódulo del runtime |
| [RT64](https://github.com/rt64/rt64) | RT64 Contributors (Mr-Wiseguy y colaboradores) | MIT | renderer N64 (RDP/RSP) sobre Vulkan |
| [SDL2](https://github.com/libsdl-org/SDL) | Sam Lantinga y colaboradores | Zlib | ventana, entrada (mando/teclado) y audio |

Dependencias del sistema que se enlazan en Linux (no se distribuyen; licencias propias): Vulkan
Loader (Apache-2.0), Vulkan ICD/lavapipe y demás drivers, GTK3 (LGPL-2.1+) y las bibliotecas de
X11/zlib del sistema.

## Submódulos incluidos en el snapshot del runtime

| Componente | Autoría | Licencia | Commit (en el snapshot) |
|---|---|---|---|
| [xxHash](https://github.com/Cyan4973/xxHash) | Yann Collet | BSD-2-Clause | `ac3a25da` |
| [miniz](https://github.com/richgel999/miniz) | RAD Game Tools / Valve Software / Rich Geldreich / Tenacious Software | MIT | `8573fd7c` |
| [o1heap](https://github.com/N64Recomp/o1heap) (fork de N64Recomp) | Pavel Kirienko | MIT | `a124b850` |
| [N64Recomp](https://github.com/N64Recomp/N64Recomp) (submódulo) | Mr-Wiseguy (Wiseguy) y colaboradores | MIT | `81213c18` |

## Cambios propios: forks (rama `hybrid-heaven`)

Los cambios de este port sobre las dependencias viven en **forks reales** (con `main` = upstream, así
se conserva el vínculo “forked from …” y los avisos de licencia):

| Fork | Cambios | Base upstream |
|---|---|---|
| [hunkstalker/N64ModernRuntime](https://github.com/hunkstalker/N64ModernRuntime) | 23 commits: VI desde la ROM, registro dinámico de módulos, mesgqueue/threads, Controller Pak, `MEM_*` seguro, instrumentación, fix `s0` | `N64Recomp/N64ModernRuntime` (GPL-3.0) |
| [hunkstalker/N64Recomp](https://github.com/hunkstalker/N64Recomp) | `include/recomp.h` (`MEM_*` seguro, watchpoint) + `src/symbol_lists.cpp` (PFS reimplementado) | `N64Recomp/N64Recomp` (MIT) |

`lib/N64ModernRuntime` y `lib/N64Recomp` se incluyen como **submódulos git** (ADR 0010) apuntando a
estos forks (el `N64Recomp` sale del `.gitmodules` anidado del fork NMR). `port/runtime.lock` queda
como referencia/fallback. Los cambios quedan marcados en los propios commits de cada fork (GPL-3.0 §5).

`RT64` **no** se modifica: se clona del upstream en el commit fijo
`43373749dac9bbc1b653e6a02aed40a9e1783bed` (MIT). `SDL2` también se toma del sistema.

## Repo de referencia (tooling adoptado, MIT)

Parte del **tooling de recompilación por ELF** (ADR 0011) se adapta del port de referencia
**[danielgomesvieira2000/hybrid-heaven-recomp](https://github.com/danielgomesvieira2000/hybrid-heaven-recomp)**
(**MIT**, © 2026 Hybrid Heaven: Recompiled contributors; aviso completo en
[`licenses/hybrid-heaven-recomp-MIT.txt`](licenses/hybrid-heaven-recomp-MIT.txt)). Es compatible con
nuestra GPL-3.0 al preservar el aviso de copyright.

| Script/decisión nuestra | Origen en la referencia |
|---|---|
| `tools/unpack_rom.py` (imagen expandida + `segments.json`) | `unpack_rom.py` |
| `tools/gen_splat_yaml.py` (config de splat) | `gen_splat_yaml.py` |
| `tools/gen_link_syms.py` (asignaciones sin shadowing ABS) | `gen_link_syms.py` |
| `tools/gen_reimplemented_decls.py` (declaraciones `_recomp`) | `gen_reimplemented_decls.py` |
| `tools/gen_runtime_func_table.py` (registro por dirección de cartucho) | `gen_runtime_func_table.py` |
| `tools/build_elf.sh` (ensamblar/enlazar el ELF; aquí con LLVM en vez de GNU) | `wsl_split.sh` + `wsl_build_elf.sh` |
| `recomp/macro.inc` + `recomp/*.yaml/toml` (esqueleto) | `recomp/macro.inc`, `hybrid-heaven.us.{yaml,ld,toml}` |

El `macro.inc` de la referencia, a su vez, procede de **Rayman 2: Recompiled** (MIT); aquí está
reescrito con el mismo propósito.

## Herramientas de desarrollo (no se distribuyen)

| Herramienta | Autoría | Licencia | Uso |
|---|---|---|---|
| [Ghidra](https://ghidra-sre.org/) | NSA / Ghidra contributors | Apache-2.0 | desensamblado/decompilado y generación de símbolos |
| N64LoaderWV | Warranty Voider | (ver su distribución) | loader de ROMs N64 para Ghidra |
| [mupen64plus](https://github.com/mupen64plus/mupen64plus-core) | equipo mupen64plus | GPL-2.0 | emulador de referencia ("oráculo") para diagnóstico |
| [BizHawk](https://github.com/TASEmulators/BizHawk) | BizHawk contributors | MIT | emulador de referencia para capturas y replay |

También se usan herramientas propias y utilidades de Python (`zlib`, `numpy`, PyYAML...) bajo sus
licencias respectivas.

## Licencia de este proyecto

El proyecto se distribuye bajo **GPL-3.0** (texto en [`LICENSE`](LICENSE)): es un proyecto
**público y comunitario**. La combinación enlaza **N64ModernRuntime (GPL-3.0)**, por lo que esta
licencia cumple los requisitos (código fuente disponible + avisos de terceros, que están en este
documento). `CREDITOS.md`/`LICENCIA.txt` se incluyen en los artefactos publicados.
