# RETOMAR — punto de retomada de la sesión

> Vista sintetizada para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md`
> (estado) y la nota más reciente en `notes/`.
> Actualizar o borrar este archivo cuando cambie la tarea.

## Estado en 3 líneas

- Se **juega** en Windows: menús → GAME START → escenas 3D y combate, con mando Xbox (`config.ini`),
  audio a 43200 Hz y Controller Pak emulado.
- **Cuelgue por daño del robot: ARREGLADO y validado (2026-09-16)**, en dos capas:
  1. `s0` (r16) machacado por la cadena del frame → el dispatch frame/no-op del bucle principal se
     rompía: fix runtime `HH_S0FIX` (incondicional; repara en la entrada del work, log en
     `hh_s0fix.log`). Validado con auto-test (`HH_TEST_S0BUG`) y por el usuario.
  2. Ya caído, el personaje **no se levantaba** (y la pila fugaba `0x38`/frame): **fallthrough
     ausente al final de `M55_FUN_8037a6f4`** — la `beq` final (0x8037A880) cae a `0x8037A884`
     (delay slot) y a la continuación `0x8037A888`, que desemboca en el epílogo compartido
     `0x8037A94C`/`0x8037A950` (`sp += 0x38`). El port salía por `;}` (fuga + lógica de caída
     saltada). Corregido en `tools/analysis/fix_fallthroughs.py` (nueva regla: rama condicional
     como última instrucción ⇒ encadenar a la contigua si `cont == last_addr+4`). Detalle:
     `notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md`.
- También arreglados y validados antes: **objeto del NPC** (fallthrough M55 `M55_FUN_80379690` →
  `0x803796E4` + mid-entries; syms reconstruidos a mano) y **regresión de las escaleras** (partir un
  switch fusionado; revertida). **Módulo 55 = overlay de la secuencia de objeto del NPC**
  (`docs/architecture.md` §2.2). Si hay que recompilar: `tools/recomp.py ... --force`.
  Detalle: `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`.
- **Crash de la cinemática de puerta: ARREGLADO (2026-09-16; pendiente de validar en Windows)**:
  `M9_FUN_80203830` era una frontera real de función (su contenedor `M9_FUN_8020382c` empezaba en un
  `nop` que es el delay slot del `jr $ra` anterior). Ojo: la primera pasada de `add_mid_entry.py`
  **revirtió** el fix del cuelgue del NPC (recalculaba todos los tamaños y borraba el override
  `M9_FUN_802169AC:0x1C0`); ya corregido (edición mínima + overrides) y protegido por
  `tools/analysis/check_syms_overrides.py` (paso 1b de `recomp.py`).
  Detalle: `notes/2026-09-16-crash-cinematica-midentry-m9-80203830.md`.
- **Primer combate cuerpo a cuerpo (CaC): ARREGLADO (2026-09-16; pendiente de validar en Windows)**:
  `M10_FUN_8021d8d0` era frontera real de función (su contenedor arrancaba con tres `nop`s) y cae en
  `M10_FUN_8021d8d8`. Igual que la cinemática de puerta (`M9_FUN_80203830`).
- **Guardado en cápsula: PENDIENTE y ya acotado**: el juego **detecta** el Controller Pak y pregunta
  si guardar, pero al aceptar **se salta la UI de slots**, **no crea `saves/`** y sale un aviso de
  accesorio. Como `saves/` solo se crea al escribir, ninguna operación de escritura/alocación llegó a
  ejecutarse. **Volcado activo por defecto** (`hh_pak.log` junto al exe: llamadas PFS con args,
  retorno, estado y los `OSPfs` del juego) + **autotest de la API PFS** (en Linux: `OK (0 fallos)`).
  Ojo: el `.pak` va al **directorio de config** del runtime (lo imprime el log), no junto al exe.
  Detalle: `notes/2026-09-16-guardado-capsula-pak-y-crash-cac-8021d8d0.md`.
- Quedan **huecos conocidos** de `LOOKUP` sin registrar (5 delay slots en el módulo 55 + otros
  módulos y plana; lista en la nota). Si crashea con `Failed to find function at 0x...`, la vía
  rápida es `python3 tools/analysis/add_mid_entry.py 0xADDR` seguido de
  `tools/recomp.py --config config/game_combined.toml --force`. La herramienta **rechaza** delay
  slots y direcciones dentro de switches fusionados (romperlos causa regresiones como el crash de
  las escaleras del 2026-09-15: ver nota, "Ronda 10").
- **Build/CI**: receta Linux (`tools/build_linux.sh`) + `Dockerfile` (Debian/glibc) + workflows
  `ci`/`release` + devcontainer (ADR 0005). Pendiente: validar los workflows en GitHub tras el push
  y el `.zip`/`.tar.gz` de un tag `v*`.
- **Teardown**: el cierre ordenado no se reproduce en Linux (rc=0) con el camino actual; hay hook de
  prueba `HH_AUTOQUIT=<segundos>` (solo si se define el env).

## TU TAREA AHORA (pasos exactos)

1. Recompilar: `port\build_windows.bat` (Release; sin `--force-libs`). No hay que publicar nada: se
   compila en la carpeta compartida y el pin de `runtime.lock` (`4e1ee0a`, pak nuevo + volcado) existe
   en el `.git` local. Si el checkout fallara, el script **aborta** en vez de compilar otro runtime.
   El árbol trae: objeto del NPC, láser, caída, menú (`M55_FUN_80378c48`), puerta/cinemática
   (`M9_FUN_80203830`) y **primer CaC** (`M10_FUN_8021d8d0`).
2. Ejecutar `port\run_windows.bat` y jugar:
   (a) el **combate cuerpo a cuerpo** que crasheaba;
   (b) **GAME START** (partida nueva) y luego el **guardado en cápsula**. Con el fix del pak virgen
      (`PFS_ERR_NEW_PACK`), el juego debe **crear su fichero** (`AllocateFile size=13568`) y guardar.
      Si el arranque/menús se comportara raro, `set HH_PAK_NEWPACK=0` lo revierte sin recompilar.
3. Enviarme (o dejarme en la carpeta compartida) **el final de**
   `port\HybridHeavenRecomp\build_win\bin\Release\hh_pak.log`: debe verse `osPfsAllocateFile` y el
   guardado completando. El `.pak` vive en el directorio de config del runtime
   (`%APPDATA%\HybridHeavenRecomp\saves\hh.us.bin.pak`, lo imprime el log).
4. Si crashea con `Failed to find function at 0x...`: pasarme la dirección (misma vía:
   `add_mid_entry.py` + `recomp --force`; ahora con edición mínima y guardián
   `check_syms_overrides.py`).
5. Después: teardown SEGV al cerrar, limpieza de instrumentación y mando de menús de combate
   (ver `TODO.md`).


## Cómo leer los logs

- `hh_sched.log`: `queue`/`next`/`signal`/`park`/`wake`/`rntw`/`swap` de cada hilo. Un `park tid=N`
  sin `next/wake tid=N` posterior = hilo encolado que nunca corre.
- `hh_mq.log`: eventos de la cola del loader (`0x8005C268`): `send-in`, `send-wake`, `recv-in`,
  `recv-block`, `recv-ok` con `tid`, `sender`, `valid` y `blockedHead`.
- `hh_state.log`: si `polls` se congela con `audio` subiendo, hay hilo(s) de juego aparcados.
- `hh_pi.log`: `tid=` por DMA; `mq=8005C268` es la cola del helper síncrono del loader.
- `hh_stub.log`: si aparece un `vram`, un símbolo mal acotado quedó en stub (vacío desde el fix M9).
- `hh_ovl.log`: qué overlay/módulo se carga y cuándo.
- `hh_crash.log`: crash con registros host/guest y **backtrace host** (`bt[i] exe+0x...`); mapear con
  `build_win/HybridHeavenRecomp-Release.map`.

## Entorno / git

- **Commits de la sesión (2026-09-15)**:
  - main repo: `1e97890` — *fix(mod55): encadenar fallthroughs y registrar mid-entries del objeto
    del NPC* (incluye `RecompiledFuncs/` regenerado, syms, docs y `tools/analysis/add_mid_entry.py`).
  - N64ModernRuntime (repo anidado, **detached HEAD** como venía siéndolo): `87acdbb` —
    *diag(runtime): instrumentacion del cuelgue del NPC y sombra host de scheduling*.
- **Commits de la ronda 15 (2026-09-16)** (main repo): *fix(recomp): encadenar fallthrough
  M55_FUN_8037a6f4->8037a884 (fuga 0x38/frame en la caida)* y
  *docs: ronda 15 (fix de la caida validado; heuristica de ramas condicionales)*.
- **Runtime y tool: FORKS propios** (rama `hybrid-heaven`), con `main` = upstream:
  - `hunkstalker/N64ModernRuntime` (23 commits del runtime) y `hunkstalker/N64Recomp`
    (`recomp.h` con `MEM_*` seguro + `symbol_lists.cpp`), que se compila dentro del port.
  - Los scripts clonan por **URL+SHA fijados en `port/runtime.lock`** (no hay patch).
  - Los cambios del runtime se hacen en el árbol local (`lib/N64ModernRuntime`) y se **pushean al
    fork**; luego se actualiza el SHA en `port/runtime.lock`.
  - Copias de trabajo/publicación en `/app/N64ModernRuntime` y `/app/N64Recomp`.
- Bats de apoyo (solo los recurrentes): `build_windows.bat`, `run_windows.bat` (admite
  `noaudio`/`audlog`), `run_mqlog.bat` (traza + s0fix) y `run_watch.bat` (watchpoint + ring + replay).
  Política: un bat puntual se borra tras usarse.
- Docs vivos: `AGENTS.md` (arranque) · `TODO.md` · `PROYECTO.md` · `notes/` (evidencia por ronda).
