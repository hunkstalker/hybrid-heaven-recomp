# 2026-09-20 — Pipeline de recompilación per-file: estado y bloqueos

> Nota de sesión (evidencia). Continúa `2026-09-20-lecciones-recompilacion-per-file.md` (método).
> Ejecuta la Fase 0 y la Fase 2 (1-3) de `../RETOMAR.md`. No operativa: el método está en el doc.

## 1. Resumen

Se construyó el pipeline **per-file** completo y se validó de punta a punta con el fichero de
combate (**id 57**): manifiesto de los 91 code files, extracción, Ghidra por fichero con siembra de
fronteras, syms `.file_NN`, validación y **N64Recomp recompila residente + file_057**. El lote de
los 91 se ejecutó entero; la recompilación del set completo aún **no** cierra por dos clases de
defecto de fronteras/jump-tables (abajo).

Artefactos (generados, gitignored): `work/scratch/code_files/file_NN.bin`,
`work/scratch/syms/file_NN.toml`, `work/scratch/code_combined.z64`, `work/scratch/code_sections.json`,
`work/scratch/code_files.syms.toml`, `work/scratch/code_files.fixed.syms.toml`,
`work/scratch/ghidra_batch.log`.

## 2. Corrección de nombres: índice de entrada ≠ id Nisitenma

El proyecto viejo llamaba `idx N` a la **entrada** de la tabla; el **file id** es `N+1` (la tabla
indexa `A[id-1]`/`A[id]`). Consecuencia: los antiguos `M54/M55/M56/M99` son los **ids
55/56/57/100**. En particular:

| viejo "idx" | file id | vram | src_rom | papel |
|---|---|---|---|---|
| 7  | **8**  | 0x80107830 | 0x4E69A8 | motor (residente en carga, base del boot) |
| 54 | **55** | 0x803837E0 | 0x68BF26 | overlay pequeño |
| 55 | **56** | 0x803757E0 | 0x68FF2C | **exploración** |
| 56 | **57** | 0x80358820 | 0x69E416 | **combate** |
| 99 | **100**| 0x8038B7E0 | 0x6DCA78 | overlay |

El pipeline usa el **id** en todo (`config/code_files.json`). El manifiesto reconcilia exactamente
con el port de referencia: **91 code files, 0x368070 bytes, 15782 `jr $ra`**, agrupados por base:
`0x80107830`(8), `0x801BF1A0`(9,24,25), `0x801E1BE0`(26-53), `0x801E4AA0`(10), `0x8021B150`(11),
`0x802408F0`(12-22,54), `0x80358820`(57), `0x803757E0`(56), `0x803837E0`(55), `0x8038B7E0`(100),
`0x8038CFC0`(58-98).

## 3. Herramientas nuevas

| Herramienta | Qué hace |
|---|---|
| `tools/install_ghidra.sh` | JDK 21 + Ghidra 12.1.3 + N64LoaderWV en `toolchain/ghidra/` (dev) |
| `tools/ghidra_headless.sh` | wrapper de `analyzeHeadless` (JDK 21, `GHIDRA_HOME`/`JAVA_HOME`) |
| `tools/analyze_code_files.py` | enumera la tabla Nisitenma + VRAM, clasifica código, escribe `config/code_files.json` y `config/code_files.overlays.txt` |
| `tools/ghidra_sections.py` | por fichero: import crudo MIPS BE + análisis + siembra + export; agrega `code_files.syms.toml`; construye el ROM combinado |
| `tools/analysis/ghidra_code/*.java` | `FindIndirectFunctions` (aggressive finder), `SeedFunctionStarts` (jal/prólogo/post-`jr`), `ExportSectionSyms` (sección TOML) |

Detalle del formato: la tabla de offsets está en ROM `0x39BE0` (magic + u32 BE desde `+0x10`); la
tabla de VRAM en ROM `0x3885C` (8 B por id `{vram_start, vram_end}`); ids `1..0x270`;
"es código" = ≥3 `jr $ra` y ≥3 prólogos. Fin de texto = tras el último `jr $ra` + delay, alineado a
16 (coincide con el port de referencia: file 8 `0x4B840`, file 57 `0x2CCB0`).

## 4. Resultado de Ghidra por fichero

`python3 tools/ghidra_sections.py --all` procesó los 91 (EXIT=0, ninguno falló). Total agregado:
**92 secciones** (residente `.text` + 91 code files), **17297 funciones**.

- El recursive-descent de Ghidra **no** alcanza funciones solo referenciadas por puntero
  (p.ej. `func_80379410` en file_057, llamada por `jal` desde file_011): se siembran con
  `SeedFunctionStarts` (jal + prólogo + dirección tras `jr $ra`, descartando destinos de rama
  interna).
- `file_057` pasó de 380 → **557 funciones**; `func_80379410_...` presente, size `0x80`.
- `validate_syms.py` (existe y ya se usaba): `--fix` corrigió **1804 delay-slots cortados** (Ghidra
  excluye el delay slot del cuerpo) y **282 ramas cruzadas** (fusionar). En el residente quedan
  **133 "sospecha de datos"** (la `.text` plana vieja `us_ghidra.syms.toml` arrastra libultra/datos).

Smoke test (solo residente + file_057) `config/game_code057.toml` → N64Recomp **OK** (rc=0),
emitiendo el C de `func_80379410_...`. Esto valida el método; el fichero descartable se eliminó.

## 5. Bloqueos para el set completo de 91

`./toolchain/src/N64Recomp/build_recomp/N64Recomp config/game_code_files.toml` (rc=1, ~3 s):
1. **`Error recompiling func_801BF1C0_1089CF0`** (file_009): *"Unhandled link branch at end of
   function"*. El cuerpo acaba en `jal 0x801BF1A0` (`0x801c1954`) sin el `jr`/delay posterior ⇒
   frontera **truncada** por Ghidra (el `jr $ra` siguiente no se atribuyó a la función).
2. **`Skipping jump table at 0x801E256C for instruction at 0x801BF268 (no valid entries)`**
   (file_009): un **switch** partido; la syms no lleva información de jump-tables (el viejo
   `gen_module_syms.py` fusionaba los `switch`; `ExportSectionSyms` no).
3. Residente: 133 funciones con datos absorbidos / stubs (`analysis failed (data absorbed...)`).

Falta por tanto: (a) **manejo de jump-tables** en las fronteras por-file, (b) cerrar funciones que
terminan en `jal`/`jr` no-RA, (c) regenerar el **residente** con Ghidra excluyendo overlays
(en vez de reciclar `us_ghidra.syms.toml`), y (d) los **loaders** `recomp_load_overlays`/
`unload_overlays` notificados en ambos (`FUN_80003824`/`0x8000469C` y `FUN_80004838`).

## 6. Reproducir

```sh
python3 tools/install_ghidra.sh                     # una vez (dev)
python3 tools/analyze_code_files.py work/roms/us_retail.z64 --extract work/scratch/code_files
python3 tools/ghidra_sections.py --only 57          # un fichero
python3 tools/ghidra_sections.py --all              # lote (~40 min)
python3 tools/analysis/validate_syms.py work/scratch/code_files.syms.toml \
    --rom work/scratch/code_combined.z64 --fix --out work/scratch/code_files.fixed.syms.toml
./toolchain/src/N64Recomp/build_recomp/N64Recomp config/game_code_files.toml
```

`config/game_code_files.toml` es la config per-file (relocatable = `code_files.overlays.txt`;
ignora `FUN_800493c4/FUN_80049430/FUN_80049538/FUN_800495ec`, los no-code libultra ya ignorados en
`game_combined.toml`).

## 7. Decisión de ubicación de artefactos

Siguiendo `docs/documentation.md` §2, los **datos generados** (manifiesto, syms, ROM combinado) **no
se versionan**: viven en `work/scratch/`. Se versionan los **tools**, la config y (cuando cierre) el
**C recompilado**. `config/code_files.overlays.txt` y `config/code_files.json` (pequeños, definen el
set) se mantienen en `config/`; las syms grandes se referencian desde `work/scratch/`.

## 8. Bloqueos resueltos y N64Recomp completo

`config/game_code_files.toml` recompila **residente + 91 secciones** (rc=0). Cambios que lo hicieron
posible:

- **Jump-tables / `jal` final**: `tools/analysis/fix_per_file_syms.py` (capstone) hace contiguas las
  fronteras, fusiona continuaciones de `jal`/`jalr` y aplica el merge de jump-tables de
  `gen_module_syms.py`. Reproducido en `ghidra_sections.py` (paso de post-proceso por fichero).
- **Secciones relocalizables en modo syms**: N64Recomp marca una sección como relocalizable solo si
  tiene `relocs`; `ghidra_sections.py` emite `relocs = []` en cada `.file_NN` (las llamadas van por
  lookup). Sin esto: `Failed to find written section index of relocatable section`.
- **`overlays.txt` con punto**: las secciones se llaman `.file_NN`; el fichero de lista debe llevar
  el punto (bug del primer generador).
- **Patch heredado**: `[[patches.instruction]]` de `0x8012591C` con la función contenedora nueva
  `func_80125808_1000000` (0x80125814 ya no es inicio).
- **C generado limpio**: N64Recomp **no** borra el directorio de salida; regenerar sobre él deja
  `funcs_N.c` rancios con definiciones duplicadas (`multiple definition`). Borrar antes de recompilar.

**Resultado**: `config/RecompiledFuncs_code/` (341 ficheros) copiado a
`port/HybridHeavenRecomp/RecompiledFuncs/` + `fix_fallthroughs.py` (269 cadenas) + build **OK**, y el
port **arranca** (RT64, frames avanzan) con `module_sources.inc` de 91 entradas.

## 9. Regresión pendiente: el boot no pasa de la fase temprana

A/B con el mismo replay `cac_full` (`HH_REPLAY_MODE=poll`, headless):

- **build viejo (committed)**: carga `file_055` (`src=68BF26`) en `vi≈85` y sigue con decenas de
  overlays (menús/gameplay).
- **build per-file nuevo**: solo carga `file_008` (`4E69A8`→`80107830`) y el id base
  (`4E5F40`→`800F41C0`); **no** llega a cargar `file_055`. Frames avanzan (`[FRM]`, ~60 VI/s) pero
  no hay más `[LD384]`/`[OVL]`.

Comprobado (no es la causa): fronteras del residente idénticas (mismos tamaños; solo 4 funciones
filtradas), **residente `funcs_0..14` byte-idéntico** al build viejo, `FUN_801079B0`/`FUN_80133AAC`
presentes; desactivar `register_module_sources`, registrar todo flat (`HH_FLAT_ALL`), o usar las
fronteras viejas de file_008 **no** lo arregla; sin lookup misses (`hh_missing.log`/stderr vacíos).

## 10. A/B real viejo↔nuevo (reconstruido el viejo)

Se reconstruyó el **build viejo determinista** (`git worktree` en `8fd6ddf`, + `setup_module.py`
para los 11 módulos, `game_combined.toml`) y se hizo A/B con el mismo replay:

- **Viejo**: carga `file_055` (`68BF26`) en `vi≈77` y sigue (decenas de overlays).
- **Nuevo (per-file)**: solo `file_008`; se queda en el **mismo bucle libultra** de idle
  (`80026E58/80026F58/80034AB8/80034C24/80031190=osGetTime`), pero **no** avanza.
- **Contacto diferencial (calltrace de 4 s)**: los dos builds son idénticos hasta ~700 llamadas;
  ambos ejecutan `func_80107830` (registra callbacks), `FUN_80005270` (dispatcher), etc. En el viejo,
  `func_801079B0` **se invoca** (y dispara `FUN_80004484(0x37)` → carga `file_055`); en el nuevo
  `func_801079B0` **nunca se invoca** (solo queda registrado). `FUN_80005270` corre en ambos.
- **Conclusión**: el **código recompilado es el mismo**; la divergencia está en el **registro/estado
  de secciones** (la cadena de callbacks de `file_008` no llega a `func_801079B0`). El residente y
  `file_008` tienen fronteras y cuerpos idénticos.

## 11. Fase A.2: loaders estilo referencia (hecho)

Implementado en `port/HybridHeavenRecomp/src/main/sections.cpp` (sustituye a
`register_overlays.cpp` + `module_sources.inc`):

- `include/hh/file_table.h` (`tools/gen_file_table.py`): `kCodeFiles[]` `{id, vram, size}` en orden
  de `code_files.overlays.txt`.
- `announce_load(id, dest)`: evicta solapes (`unload_overlay_by_id`) y registra la sección vigente
  (`load_overlay_by_id`).
- Hooks por dirección (`add_loaded_function`) de **ambos** loaders (`FUN_8000469C`, `FUN_80004838`),
  registrados en **`on_init`** (`hh::register_runtime_functions`, tras `init_overlays`; antes los
  borraba `func_map.clear()`). `register_flat_code` ya no omite por `module_sources` (no se registra).
- Añadidas `load_overlay_by_id`/`unload_overlay_by_id` a `overlays.hpp` del fork.

El hook **funciona** (`[hh-load] file 8 -> 0x80107830`), pero **el boot sigue sin avanzar**: confirma
que el registro no era la causa. **Siguiente paso**: comparar el estado de `func_map` / colas justo
tras `func_80107830` entre viejo y nuevo, y por qué la cadena de callbacks de file_008 no progresa
(el dispatcher `FUN_80005270` sí corre).

