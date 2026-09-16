# 2026-09-16 — Limpieza del repo: purga de `.vs/` e inventario de candidatos

> Contexto: el usuario crea el repo en GitHub (`hunkstalker/hybrid-heaven-recomp`) y pide limpiar
> el proyecto antes de publicarlo. Este documento fija **qué se hizo** y **qué queda por decidir**
> (para que no se olvide ni se borre por error algo necesario).

## Hecho (este commit)

- **`.vs/` purgado de TODO el historial** (169 commits). La cache de Visual Studio pesaba 337 MB
  (`Browse.VC.db` 243 MB + `slnx.sqlite` 57 MB + `.vsidx`/`.wsuo`/`workspaceFileList.bin`) y se
  añadió en `da2a38a`. GitHub **rechaza blobs >100 MB**, así que el push fallaba.
  - `git filter-branch --index-filter 'git rm -r --cached --ignore-unmatch port/HybridHeavenRecomp/.vs' --prune-empty -- main`
  - limpieza: `rm -rf .git/refs/original && git reflog expire --expire=now --all && git gc --prune=now`
  - Resultado: `.git` **284,5 MB → 24 MB**; árbol rastreado **379 → 41,8 MB**; 0 blobs >10 MB.
  - **Los hashes de los commits cambiaron** (rewrite); `main` quedó en HEAD y ya no está detached.
- **`.gitignore`**: añadidos `.vs/`, `.vscode/`, `*.suo`, `*.wsuo`, `*.user`, `Thumbs.db` y
  `tools/analysis/xshot` (binario local).
- **Borrados** (basura inequívoca): `port/petardeo)` (62 B, resto de un redirect) y
  `tools/analysis/xshot` (ELF compilado; se reconstruye desde `tools/analysis/xshot.c`).
- **Remote** `origin` → `https://github.com/hunkstalker/hybrid-heaven-recomp.git` (el push lo hace
  el usuario desde Windows: `git push -u origin main`).

## Candidatos a limpieza (decisión pendiente)

1. **`Referencias screenshots/`** (12 archivos, 4,7 MB): capturas del juego (incluye
   `muestra-menu-hybrid-heaven.png`, 1,7 MB) + juegos JPG de BizHawk. No es código y contiene
   imágenes con copyright → **propuesta: fuera del repo** (moverlas fuera del workspace o a un
   `notes/reference/` local si se quieren conservar como referencia).
2. **`tools/analysis/` (93 archivos)**: los **62 `.java` de Ghidra** (`ghidra_scripts/*`,
   `Decomp*X`, `Vi*X`, `Sched*X`...) y varios helpers `.py`/`.c` de fases pasadas
   (`r64dump`, `retro_dump`, `gl_force33`, `hhinput`, `fbdecode`, `ppmascii`, `textseg`,
   `parse_exec_trace`, `auto_syms_loop`, `detect_lzkn64`, `scan_lzkn64_strict`, `test_lzkn64`,
   `xshot.c`, `overlay_chunks`, `analyze_rom`, `gen_ghidra_syms`...). Muchos ya no se usan; los
   vivos están citados en `docs/workflows.md` §6. **Propuesta**: `tools/archive/` (o
   `notes/archive/`) conservando los que siguen en uso, con una nota de qué quedó dónde.
3. **`port/bisect_build.bat` + `port/bisect_extra.patch`**: herramienta del bisect del cuelgue del
   NPC (conclusión documentada: no era regresión). Conservar solo si habrá más bisects.
4. **`work/` rastreado** (`README_captura.md`, `cap_loop.sh`, `play.sh`): scripts de captura
   antiguos; el directorio `work/` ya está en `.gitignore` pero estos 3 se versionaron antes.
   Decidir: mover a `tools/` o borrar.
5. **Variantes de `config/`**: la activa es `game_combined.toml`; revisar y archivar las que ya no
   se usen (`game.toml`, `game_module7.toml`, `game_retail.toml`, `game_unified.toml`,
   `us_ghidra.syms.toml`, `us_retail.syms.toml`, `us_dec.syms.toml`, `us_unified.syms.toml`).
6. **Instrumentación del runtime** (`hh_*.log`, `HH_S0FIX`, callring, watchdog): ya listada en
   `TODO.md` ("Limpieza de instrumentación").

## NO borrar (documentado para que no se confunda con basura)

- **`config/us_moduleNN.syms.toml.keep`** (9): **no son backups**. Los escribe
  `gen_module_syms.py` (entradas protegidas + auto-punteros) y los lee `setup_module.py`. Si se
  borran, el pipeline de syms pierde las anclas de jump-tables/callbacks.
- **`config/keep_syms.txt` / `keep_syms_flat.txt` / `module_extras.json`**: inputs del pipeline.
- **`config/n64recomp_changes/*`**: parches al recompilador (ADR 0002), necesarios para recompilar.
- **`port/HybridHeavenRecomp/RecompiledFuncs/*.c`**: input real del build (los
  `config/RecompiledFuncs_*` sí están ignorados).
- **`port/config_test_oldmap.ini` + `port/run_test_*.bat`**: regresión (el propio `.ini` documenta
  el mapeo antiguo).
- **`notes/**`** (evidencia; no se edita) y **`notes/reference/`** (dato generado).
- **`assets/*`** (iconos bmp/ico/png) y **`.entorno/skills/`** (tooling del asistente).

## Reproducir la purga de un path en la historia

```sh
FILTER_BRANCH_SQUELCH_WARNING=1 git filter-branch --force \
  --index-filter 'git rm -r --cached --ignore-unmatch <PATH>' --prune-empty -- main
rm -rf .git/refs/original && git reflog expire --expire=now --all && git gc --prune=now
```
