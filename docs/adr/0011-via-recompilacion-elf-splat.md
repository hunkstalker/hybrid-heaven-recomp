# ADR 0011 — Adoptar la vía de recompilación de la referencia (ELF + splat + residente limpio)

- **Estado**: Aceptado (2026-09-21).
- **Contexto relacionado**: `../../notes/2026-09-21-migracion-via-referencia-elf.md` (plan),
  `../../notes/2026-09-20-ab-bloqueo-boot-per-file.md` (evidencia del fallo),
  `0002-des-stub-libultra.md` y `0003-vi-libultra-del-rom.md` (restricción sobre libultra),
  `0010-dependencias-runtime-como-submodulos.md`.

## Contexto

El port se construyó con **syms-mode sobre una ROM combinada** y **fronteras de función de Ghidra por
fichero aislado**, con un residente `.text` reciclado del análisis plano viejo (mezcla código/datos/
libultra). Tras el reset per-file, el build arranca y llega al título, pero **sin el fondo 3D**;
diagnóstico: el nuevo ejecuta un subconjunto de funciones (callbacks de escena/recurso no invocados)
y no emite `G_MTX`. El build viejo, que usaba Ghidra **plano de imagen completa**, sí funcionaba.

La generación de fronteras por fichero aislado **pierde el contexto de imagen completa**
(cross-references residente↔overlays) y ya produjo bugs (split `0x801078E0`, datos-como-código en
`file_055`, funciones fantasma en el residente). La referencia usa **splat/spimdisasm sobre la imagen
expandida** (CFG de imagen completa + JAL scan + gates `verify_elf`/`jal_audit`) y **rechaza
explícitamente** el symbols-file mode sobre ROM descomprimida. Goemon usa ese modo pero **con
decompilación** (símbolos reales); nosotros no tenemos decomp.

## Decisión

Migrar la **entrada de la recompilación** a la vía de la referencia, por fases y con gates:

1. **Imagen expandida** (ROM + cada code file descomprimido en offset sintético) + `segments.json` +
   `file_table.h` (ya casi lo tenemos).
2. **splat/spimdisasm** de imagen completa → `asm/` + linker script → **ELF**; residente y `file_008`
   globales, resto con `exclusive_ram_id: overlay`; datos declarados (`dlabel`/`jlabel`).
3. **N64Recomp en ELF mode** (`elf_path`, `use_lookup_for_all_function_calls`,
   `relocatable_sections_path` con una sección por fichero).
4. **Gates**: segmentos byte-idénticos, 0 mid-function/nowhere en `jal_audit`, conteos reconciliados,
   sin datos-como-código.
5. Se **conserva** la arquitectura de loaders/runtime del port (no se reescribe) y los parches de
   `config/n64recomp_changes/`.

**Quién posee libultra**: se mantiene la postura de **ADR 0002/0003** (ROM-owned para el estado que el
juego lee: init/VI) durante la migración. `runtime-owned libultra` (como la referencia) es un
**sub-paso posterior a evaluar con A/B contra `emu_ref`**, no parte del primer golpe: adoptarlo sin
más reintroduciría el fallo que 0002/0003 arreglaron.

## Consecuencias

- **Positivas**: fronteras y datos de imagen completa (menos bugs de la clase actual); residente
  limpio; gates automáticos de completitud; vía estándar del ecosistema; parches MIPS de un solo
  fichero viables a futuro (enhancements).
- **Negativas/Riesgos**: migración grande (nueva dep. de desarrollo splat/spimdisasm + binutils MIPS);
  el boot debe re-validarse por fases; el pin de `runtime.lock`/submódulos depende del push de forks.
- **Operativa**: se hace por fases (M0–M5) sin romper el boot actual mientras no cierre cada gate. La
  vía por-fichero Ghidra (`ghidra_sections.py`, `fix_per_file_syms.py`) pasa a `legacy/` al cerrar.

## Alternativas descartadas

- **Seguir con Ghidra-per-file y parchear fronteras**: descartado; la deuda reaparece por cada
  fichero/escena y ya causó esta regresión.
- **splat solo para fronteras, seguir en syms-mode** (alcance medio): viable y más barato; se descarta
  por decisión del mantenedor (calidad/estándar; no prisa) a favor del ELF completo.
- **libultra del runtime ya**: descartado por ahora (choca con 0002/0003; ver arriba).

## Criterio de salida

`git clone --recursive` + imagen expandida + splat + ELF + N64Recomp generan el C; los gates pasan;
y el port **arranca, logos, título con fondo 3D, transición y CaC sin workarounds `HH_*`**.
