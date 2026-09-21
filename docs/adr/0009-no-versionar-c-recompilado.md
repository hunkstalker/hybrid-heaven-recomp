# ADR 0009 — No versionar el C recompilado (obra derivada)

- **Estado**: Aceptado (2026-09-20).
- **Contexto**: el proyecto versionaba `port/HybridHeavenRecomp/RecompiledFuncs/` (~2.0 M líneas de C
  generado, ~40 MB en Git por bytes, ~72 MB en disco) para que quien clonara pudiera compilar **sin**
  la ROM ni el recompilador. El C recompilado es una **traducción del binario de Hybrid Heaven**
  (© Konami): obra derivada del juego. La norma del ecosistema (Goemon64Recomp, ports de N64Recomp)
  es **no** versionarlo y regenerarlo desde la ROM en setup/build. Además ensuciaba los diffs, las
  estadísticas del repo (GitHub marcaba 96.9 % C) y la zona legal.
- **Decisión**:
  1. **No versionar** el C recompilado (`.gitignore`: `port/HybridHeavenRecomp/RecompiledFuncs` como
     **symlink** a `work/recomp/RecompiledFuncs`, generado). Tampoco el microcódigo RSP derivado se
     versiona como regenerable, pero `rsp/hh_aspMain.cpp` sí se mantiene versionado (es pequeño y
     estable; decisión revisable).
  2. Pipeline de regeneración **determinista y documentado**: `tools/regenerate.py`
     (ROM → manifiesto → extracción → Ghidra per-file → syms → N64Recomp → fallthroughs →
     `file_table.h`). Ghidra + JDK 21 + N64Recomp son **dependencias de desarrollo**.
  3. El repo versiona: el **port hecho a mano**, la **config** (`config/*.toml`, `code_files.json`,
     `code_files.overlays.txt`), las **herramientas**, el **linker/config de recompilación**
     (`recomp/n64recomp_changes/`) y `rsp/hh_aspMain.cpp`.
  4. El registro de secciones usa el esquema de la referencia: `file_table.h` + hooks de loader
     (`add_loaded_function` + `load_overlay_by_id`/`unload_overlay_by_id`), sin `module_sources`.
- **Consecuencias**:
  - **Compilar requiere la ROM** (una vez, para recompilar). Ejecutar también (para extraer datos).
  - El `.git` pasó de ~15 MB a ~1.6 MB y la historia se **reescribió** (filter-branch) para eliminar
    el C derivado del pasado: **force-push** obligatorio; los hashes de commits cambian.
  - Los commits con `RecompiledFuncs/funcs_*.c` dejan de existir en la historia pública.
  - Alternativa considerada: repositorio/secreto privado con el C generado para CI (como Goemon);
    se descarta por ahora (el CI no compila el port sin la ROM).
- **Alternativas**:
  - Mantener el C versionado con `.gitattributes linguist-generated` (parche cosmético): descartado,
    no resuelve el fondo (tamaño/legal/diffs).
  - Repo privado de secretos + CI: viable si en el futuro se quiere CI que compile el port; requiere
    una ROM en secreto (no se sube nunca la ROM a un repo público).
- **Criterio de salida**: `tools/regenerate.py` reproduce el C; `CMakeLists` falla con un mensaje
  claro si falta y apunta al regenerador; el port compila tras regenerar.

## Actualización (2026-09-21)

- **El microcódigo RSP ya no se versiona** (antes era la excepción de esta ADR). Se trata como el C
  recompilado: **generado con RSPRecomp** (`recomp/rsp_hh_aspMain.toml` →
  `build/recomp/rsp/hh_aspMain.cpp`, gitignored) por `tools/regenerate.py`. Quien clone el repo lo
  genera con su ROM (RSPRecomp, dep. de dev); el CI lo trae del repo privado de secretos
  (`secrets/rsp/hh_aspMain.cpp`). Así el repo público queda **sin traducción de código del juego**
  (el C recompilado ya estaba fuera).
- **Plan futuro (cobertura nativa)**: cuando el baseline esté **congelado (100 % features)**, se
  **clonará** y se abrirá un **repo separado** para la **reimplementación nativa progresiva** (que
  será **código derivado**). El baseline (menos expuesto: tooling + port, sin traducción del juego)
  queda como **producto y oráculo**; la reescritura (más expuesta) en su repo → **radio de explosión**
  ante un DMCA. Nota: un takedown puede ir contra repos *y/o* la cuenta, y los **binarios** también
  embeben derivado; la protección real es el **backup fuera de GitHub**.
- El **norte legal sigue siendo clean-room** (reimplementar desde comportamiento, no desde el
  código original); la reescritura derivada es un paso pragmático, no el fin.
- El microcódigo RSP generado es **byte-idéntico** al que se versionaba (verificado con RSPRecomp).
