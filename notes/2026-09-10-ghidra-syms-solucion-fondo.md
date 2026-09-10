# SOLUCIÓN DE FONDO — Syms/ELF con límites correctos (splat/flib/Ghidra) — EN PROGRESO

> Documenta el intento de la "solución de fondo" (generar una syms/ELF completa con límites de
> función correctos) para eliminar el bucle de arreglos de límites. Complementa
> `notes/2026-09-10-n64sym-osfuncs-rootcause.md` §9-10.

## 0. Resumen

- Se investigó **splat** y **Ghidra** para generar límites de función correctos.
- **splat NO se pudo instalar** (dependencias pesadas: tables/HDF5 fallan en Python 3.14/Alpine).
- **Ghidra SÍ funciona** (ya estaba configurado): exportó **1095 funciones** del proyecto HH (mucho
  más que las ~351 de la syms actual), con límites y nombres.
- Se generó una **syms Ghidra** (`config/us_ghidra.syms.toml`, 867 funciones tras filtrar al rango de
  la sección `.text`) con los nombres os correctos (94 os funcs de n64sym).
- **PERO** el enfoque Ghidra tiene **falsos positivos y divisiones incorrectas** que requieren
  refinamiento extenso. **No se adoptó como config activo** — el repo queda en el estado funcional
  (os funcs mapeados, thread 5 desbloqueado).

## 1. Splat — NO instalable aquí

- `pip install splat` falla: dependencias `numpy` + `tables` (PyTables/HDF5) no compilan en
  Python 3.14 / Alpine (falta `Python.h` al inicio, luego `tables` no construye ni con `hdf5-dev`).
- Splat requiere además el **toolchain MIPS** (`mips-linux-gnu-*`), no disponible como paquete apk.
- **Conclusión**: splat no es viable en este contenedor sin resolver las deps de build pesadas.

## 2. Ghidra — SÍ funciona (enfoque adoptado para el intento)

### 2.1 Exportar funciones
Script `/tmp/ghidra_scripts/ExportFuncsX.java` → recorre `FunctionManager`, exporta
`{ name, vram, size }` de cada función en `0x80000400..0x804E5F40` → `work/ghidra_funcs.txt`
(**1095 funciones**).

```sh
export JAVA_HOME=/usr/lib/jvm/java-21-openjdk && export PATH=$JAVA_HOME/bin:$PATH
toolchain/ghidra/ghidra_12.1.3_PUBLIC/support/analyzeHeadless work/ghidra/proj HH \
  -process -scriptPath /tmp/ghidra_scripts -postScript ExportFuncsX.java
```
> OJO: Ghidra requiere `bash` y el JDK (reinstalar si `apk add` los removió). Headless recompila
> TODOS los scripts del `-scriptPath` → usar un dir aparte solo con los propios.

### 2.2 Generar syms Ghidra
Script `/tmp/gen_syms.py`: construye `config/us_ghidra.syms.toml` con:
- Bloque `[[section]]` `.text` (rom 0x1000, vram 0x80000400, size 0x4E5B40).
- Funciones de Ghidra (límites), **filtrando al rango** `0x80000400..0x804E5F40` (excluye overlays/datos).
- **Nombres os correctos** desde n64sym (94 os funcs: osSetTimer, osRecvMesg, osSendMesg,
  osCreateViManager, osSpTaskLoad, osGetTime, etc.).
- Excluye símbolos de DATOS (osTvType, __osTimerList, etc.) — solo funciones.

Resultado: `us_ghidra.syms.toml` = 867 funciones (vs 351 actuales). Mucho más completo.

### 2.3 Ajustes aplicados
- `/tmp/fix_sizes.py`: hace las funciones **contiguas** (size = gap hasta la siguiente función) para
  arreglar funciones truncadas (485 corregidas).
- Fusión manual de `FUN_8001fefc`+`FUN_8001ffac` (Ghidra dividió mal una función; `FUN_8001ffac`
  brancha hacia atrás a `FUN_8001fefc`) → `FUN_8001fefc` size 0x178.

## 3. PROBLEMAS del enfoque Ghidra (por qué no se adoptó aún)

1. **Falsos positivos: datos detectados como funciones.** Ej. `FUN_80133aac` (size 0x7AC4) es un
   **blob de datos** (el disasm es basura `cache 4,-0x6dc4($s1)` / `.byte`), no código. Ghidra lo
   marcó como función; el recompilador intenta compilarlo y falla.
2. **Divisiones incorrectas.** Ghidra a veces divide una función real en dos (`FUN_8001fefc` +
   `FUN_8001ffac`) → hay que fusionarlas (detectable por branches cruzados).
3. **Funciones llamadas no compiladas.** El código plano llama a funciones (p.ej. `FUN_80133aac`,
   `FUN_801414b0`, `FUN_801302cc`) que Ghidra no detectó como funciones o son datos → "implicit
   declaration" / no se compilan.
4. **Declaraciones faltantes en funcs.h.** Como con `osYieldThread_recomp`, el recompilador emite
   llamadas a funciones (osPfsRepairId, __osContRamWrite, __osDispatchThread) sin declararlas en
   funcs.h → hay que añadirlas tras cada regen.

## 4. Conclusión / estado

- **Ghidra es la vía correcta y está configurada** (exporta 1095 funciones; la syms Ghidra tiene 867
  con os funcs correctos). Es un **gran avance** frente a la syms byte-matched (351).
- **PERO** necesita **refinamiento extenso** (filtrar falsos positivos de datos, fusionar divisiones,
  resolver funciones llamadas no compiladas, y los overlays que el código plano llama). Es un trabajo
  de **largo plazo**, no un cambio rápido.
- **El repo queda en el estado funcional** (commit `e67490d`/`fbcfb1e`): config → `us_unified.syms.toml`
  + `use_lookup=false`, thread 5 desbloqueado. La syms Ghidra (`config/us_ghidra.syms.toml`) y los
  scripts (`/tmp/gen_syms.py`, `/tmp/fix_sizes.py`, `/tmp/ghidra_scripts/ExportFuncsX.java`,
  `work/ghidra_funcs.txt`) se guardan para el refinamiento futuro.

## 5. Próximos pasos para el enfoque Ghidra
1. Filtrar falsos positivos: eliminar de la syms las "funciones" cuyo disasm es basura/datos.
2. Fusionar funciones divididas por Ghidra (detectar branches cruzados entre funciones).
3. Añadir declaraciones faltantes a funcs.h (auto, tras cada regen).
4. Resolver las funciones de overlay que el código plano llama (requiere el mapa de overlays — tarea #3).
5. Regenerar con la syms Ghidra refinada → build → boot → render.
