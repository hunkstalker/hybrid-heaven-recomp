# 2026-09-21 — Migración a la vía de recompilación de la referencia (ELF + splat + residente limpio)

> Nota de sesión (evidencia + PLAN). Continúa `2026-09-20-ab-bloqueo-boot-per-file.md`.
> Define la dirección y los pasos; el estado se resume en `../PROYECTO.md`/`../TODO.md` y el handoff
> en `../RETOMAR.md`. Decisión estructural: `../docs/adr/0011-via-recompilacion-elf-splat.md`.

## 1. Motivo del cambio de vía

Se llega a esta decisión tras el bloqueo del build per-file: el juego llega al título pero **sin el
fondo 3D** (confirmado visualmente por el mantenedor y por captura de framebuffer: el viejo emite
`G_MTX` y el nuevo no). Diagnóstico: el nuevo ejecuta un **subconjunto** de funciones; callbacks de
escena/recurso no se invocan (`0x80124C54` 0 vs 171; `0x8012FF58` 0 vs 20; `func_80125808` 7 vs 67;
`FUN_80004bb0` 1 vs 14). La pieza sospechosa es la **generación de fronteras de función**.

Evidencia de que la **vía** (no el port) es la deuda:
- El viejo (Ghidra **plano de imagen completa**, 11 módulos) funciona; el nuevo (Ghidra **por fichero
  aislado**) no. El aislamiento pierde cross-references entre residente y overlays.
- Historial propio: bug de frontera `0x801078E0` (tumbó el boot), `file_055` con datos-como-código
  (`0x9A6C`), 27 funciones fantasma en ventanas de overlay + 44 en rango de datos en el residente,
  merges de `fix_per_file_syms`. Cada fichero/escena puede destapar otra.
- La referencia usa **splat/spimdisasm sobre la imagen expandida** (CFG de imagen completa + JAL scan
  + gates `verify_elf`/`jal_audit`: 0 mid-function) y **rechaza explícitamente** el "symbols-file mode
  sobre ROM descomprimida" (lo que hacemos). Goemon usa ese modo pero **tiene decompilación** (sus
  syms salen de un ELF con símbolos reales); nosotros no.
- La arquitectura de loaders que usamos **sí** es la estándar (secciones relocalizables +
  `use_lookup_for_all_function_calls` + loader envuelto): no se toca.

Decisión del mantenedor (2026-09-21): **ir a la vía completa de la referencia**, primando calidad
sobre prisa. El aislamiento táctico del `G_MTX` se **descarta** (quedaría obsoleto al regenerar
fronteras con splat).

## 2. Alcance

**Se migra**: la *entrada del recompilador* (de syms-mode + ROM combinada → ELF de splat sobre la
imagen expandida), el **residente** (de `.text` plano reciclado → sección limpia con datos
declarados) y la **verificación** (gates de fronteras/datos). 

**No se toca**: loaders (`sections.cpp`/`file_table.h`), runtime de port (audio, pak, input, cache
`trans`, RT64), ni la ROM del usuario.

**Sub-paso aparte (no en el primer golpe): quién posee libultra.** La referencia lo deja al runtime;
nuestros **ADR 0002/0003** lo movieron al **ROM** (init/VI) porque los stubs del runtime no
mantenían el estado que el juego lee. Adoptar runtime-owned sin más **reintroduciría** ese fallo.
Secuencia: migrar pipeline primero; medir; y solo entonces evaluar (con A/B contra `emu_ref`) si
conviene mover funciones de vuelta al runtime.

## 3. Plan por fases (con *gates*)

Referencia de diseño (consulta, no copiar): `danielgomesvieira2000/hybrid-heaven-recomp`
(`tools/unpack_rom.py`, `gen_splat_yaml.py`, `recomp/hybrid-heaven.us.yaml/.ld`, `verify_elf.py`,
`jal_audit.py`).

### Fase M0 — Toolchain de recompilación
- Instalar **splat + spimdisasm** (venv Python) y binutils MIPS (`mips-linux-gnu-as/ld`) en este
  entorno; wrapper `tools/splat_headless.sh`/`tools/build_elf.sh`.
- Documentar como dependencia de **desarrollo** (no de build).

### Fase M1 — Imagen expandida
- Reutilizar/ajustar `analyze_code_files.py`: produce `hh.expanded.z64` (ROM + cada code file
  descomprimido en un offset sintético >16 MB, alineado 16), `segments.json` (resident + files con
  rom/vram/text_size/size/bss) y `file_table.h`.
- `text_end` = justo tras el último `jr $ra` + delay, alineado 16; validar "sin prólogos después".
- *Gate*: nº de code files == 91; 0 errores de descompresión; offsets estables.

### Fase M2 — splat → ELF
- `gen_splat_yaml.py`: residente (global) + `file_008` (global) + resto con
  `exclusive_ram_id: overlay`; subsegmentos `asm`/`data`/`bss`; `symbol_name_format $VRAM_$ROM`;
  `asm_data_macro: dlabel`, `asm_jtbl_label_macro: jlabel`.
- splat → `asm/`; ensamblar/enlazar → `hybrid-heaven.us.elf`.
- *Gate*: **segmentos byte-idénticos** a la imagen (resident + 91); 0 funciones ABS / tamaño 0 /
  solapadas; `jal_audit` = 0 mid-function / 0 nowhere.

### Fase M3 — Recompilar en ELF mode
- `game.toml` con `elf_path`, `entrypoint 0x80000400`, `use_lookup_for_all_function_calls`,
  `relocatable_sections_path = overlays.txt` (una sección por fichero), `functions_per_output_file`.
- `gen_reimplemented_decls` para lo que delega al runtime; conservar parches de
  `config/n64recomp_changes/` (documentar).
- *Gate*: N64Recomp rc=0; conteos emitidos == FUNC − nombres runtime; sin avisos de datos-como-código.

### Fase M4 — Runtime/port
- Mantener loaders y `load_overlay_by_id`; ajustar `register_flat_code`/registro (el residente ya no
  es un blob con libultra mezclado; ver sub-paso libultra).
- *Gate*: boot, logos, **título con fondo 3D**, transición y CaC (sin workarounds `HH_*`).

### Fase M5 — Limpieza
- Retirar la vía por-fichero Ghidra (`ghidra_sections.py`, `fix_per_file_syms.py`, syms generadas) a
  `legacy/`; quedarse con splat. Actualizar `docs/workflows.md`, `tools/README.md`, `RETOMAR.md`.

## 4. Riesgos
- **Libultra del runtime** choca con ADR 0002/0003 (ver §2): no hacerlo sin evidencia.
- **Toolchain MIPS**: puede requerir instalar binutils; la referencia lo hace en WSL. En este entorno
  (Linux) es nativo.
- **Determinismo de splat/spimdisasm**: fijar versiones (como con Ghidra).
- **Coste**: es una migración grande; se hace por fases con *gates*, sin romper el boot actual
  mientras no cierre cada gate.

## 5. Estado al cerrar esta sesión
- Decisión tomada y documentada (`docs/adr/0011`); **M0 hecho**: toolchain instalado en
  `toolchain/splat-venv/` (splat 0.50.0, spimdisasm 1.42.4, n64img, pygfxd, crunch64, pypng) y
  backend MIPS de LLVM (`llvm-mc`, `ld.lld`, `llvm-objcopy`, `llvm-readelf`; paquetes `llvm`+`lld`).
  Scripts: `tools/install_splat.sh`, `tools/splat_headless.sh`. Verificado: `llvm-mc` ensambla MIPS
  BE y `ld.lld -m elf32btsmip` enlaza un ELF32 MIPS correcto (`jr $ra; nop`).
- **M1 HECHO**: `tools/unpack_rom.py` construye la imagen expandida, `segments.json` y `file_table.h`.
  Resultado: **91 code files, 0x368070 bytes** (coincide con el manifiesto de la referencia), imagen
  `work/scratch/expanded/hh.expanded.z64` (20349040 bytes), todos los `text_size` > 0.
  *Abierto*: el SHA-1 de la imagen no coincide con el documentado por la referencia
  (`99ba14e6…`); la puerta real es ELF↔nuestra imagen. Revisar si aparece una divergencia.
- **M2 HECHO**: split de splat OK + ensamblado/enlazado con LLVM → `elf/hybrid-heaven.us.elf`.
  Scripts: `tools/build_elf.sh` (normaliza `.set gp=64`, `glabel D_`→`dlabel D_`; ensambla con
  `llvm-mc`; envuelve `ipl3`/`gap` con `.incbin`; `tools/gen_link_syms.py` con `llvm-nm`; enlaza con
  `ld.lld`). **Gate superado**: el ELF reconstruye la imagen expandida **byte a byte** (0 diffs de
  20 349 040). `recomp/macro.inc` es nuestro (sustituye al de splat): `nonmatching` fija el tamaño de
  la función real (si no, N64Recomp no emitiría nada) y `alabel` sin `.aent`.
  Detalle de adaptación a LLVM: `.set gp=64`→`.set gp,64`; `.aent` no soportado; `/DISCARD/ { *(*) }`
  de splat → `/DISCARD/` selectivo (abiflags/reginfo) porque lld rechaza descartar `.shstrtab` y
  colocaba `.reginfo` encima del residente; los `.bin.o` por `.incbin` (ABI o32, no n64).
- **M3 HECHO**: `recomp/hybrid-heaven.us.toml` (ELF mode) + `recomp/overlays.txt`; N64Recomp **rc=0**,
  80 unidades, 15947 funciones, **0 datos-como-código**, 0 errores. Los `No function found for jal
  target` son los jal cross-window (van por lookup).
- **M4 (integrar en el port) — BLOQUEADO en M4b (propiedad de libultra)**:
  `port/.../src/main/sections.cpp` actualizado a los nombres ELF (`func_8000469C_529C`,
  `func_80004838_5438`); `recomp/hybrid-heaven.us.toml` con los patches de boot (stub TLB, hook de
  yield, clamp de audio). El port **compila** con el C del ELF pero **segfaultea al arrancar**:
  `osDestroyThread` (0x80026CE0) entra en **recursión** y desborda la pila nativa. gdb muestra que
  `__osDispatchThread` (`func_80027824`) se **genera del ROM** (aviso "eret treated as nop"), pero
  **el runtime debe poseerlo**. Causa: `recomp/symbol_addrs.txt` está **vacío** → N64Recomp no conoce
  los nombres libultra → no aplica las listas de reimplementadas y recompila hilos/dispatch. Es el
  sub-paso que ADR 0011 §2 dejó explícito.
  **M4b (siguiente)**: poblar `recomp/symbol_addrs.txt` con los nombres libultra (al menos
  hilos/dispatch: `__osDispatchThread`, `osCreateThread`, `osDestroyThread`, `__osDisableInt`…),
  alinear las listas reimplementadas/ignored del toolchain (`config/n64recomp_changes/symbol_lists.cpp`),
  registrar las funciones del runtime en sus direcciones de cartucho en el port (como
  `runtime_provided_funcs` de la referencia) y re-generar. Gate: boot + título con 3D.
- **Siguiente: M4b** (libultra del runtime) → M5 (limpieza).
- **M4b (en curso)**: se nombraron libultra en `recomp/symbol_addrs.txt` (hilos:
  `osStopThread`, `osDestroyThread`, `osCreateThread`, `osStartThread`, `__osDisableInt`,
  `__osRestoreInt`) para que N64Recomp los reconozca como reimplementados (el runtime los provee).
  Nuevos generadores: `tools/gen_reimplemented_decls.py` (declaraciones `_recomp`) y
  `tools/gen_runtime_func_table.py` (registro por dirección de cartucho; 6 funciones). `sections.cpp`
  las registra. **Resultado**: ya no se recompilan los hilos (sin la recursión de `osDestroyThread`),
  y el SEGV que queda es del watchdog (`hh_dump_stack_scan`), no del juego.
  **Bloqueo**: el juego llega a `main` (0x80001078) pero el **bucle por frame nunca corre**
  (`polls=0`, `audio=0`, sin `[trans] load`), con `osTvType=1` (NTSC) y VI avanzando. Los hilos
  creados no llegan a ejecutar la lógica. Sospecha: el runtime de hilos necesita también
  `__osDispatchThread`/`__osDequeueThread`, que **nuestro runtime no implementa** (la referencia sí
  los tiene en su fork). **M4b.2**: portar/implementar `__osDispatchThread`/`__osDequeueThread` en el
  fork del runtime (o comparar con el fork de la referencia) y volver a validar.
- **Créditos**: el tooling adaptado de la referencia es **MIT**; añadido a `CREDITS.md` y
  `licenses/hybrid-heaven-recomp-MIT.txt`, con aviso en cada script.
- Cambios de esta sesión (commitear antes de M1): submódulos (ADR 0010), `regenerate.py` materializa
  el C como dir real, Fase A.1 en `ghidra_sections.py`, campos de estado en `main.cpp`, notas y ADRs.
- El build actual (per-file) arranca y llega al título sin 3D; la vía nueva lo reemplazará.

## 6. Notas de toolchain (M0)
- Se usa **LLVM** para MIPS en lugar de binutils GNU (Alpine no trae cross-binutils MIPS y el
  paquete `binutils-cross-embedded` no incluye mips). **Medido**: el único GNU-ismo que `llvm-mc` no
  acepta es `.set gp=64` (→ `.set gp,64`); normalizarlo basta para ensamblar el código. `llvm-mc` no
  reconoce `-mcpu=vr4300` (usar `mips3`, que es la ISA del R4300i). Si surgieran más incompatibilidades
  al enlazar, se compila binutils GNU `--target=mips-linux-gnu`.
- Version determinista pendiente de fijar (splat/spimdisasm + LLVM) al cerrar M2.
