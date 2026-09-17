# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** Estado: `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` (arquitectura/ADRs) y `notes/` (histórico). No duplicar.

## Ahora — Pacing/cadencia (foco), combate CaC (bloqueante), teardown y limpieza

> **Sesión 2026-09-16 (B en menús + CaC)**: **B físico = atrás en menús VALIDADO** y mid-entry
> `M55_FUN_8037948C` (crash al iniciar CaC). **BLOQUEANTE**: corrupción de estado al entrar en CaC
> (objeto `0x8024A990`, lista de broadcast recorrida fuera de rango); runtime con mitigaciones
> **locales**. Detalle: `notes/2026-09-16-sesion-b-menus-combate-corrupcion.md`.

> **Cuelgue por daño del robot: ARREGLADO y validado en Windows (2026-09-16)**, en dos capas:
> `s0` (r16) machacado por la cadena del frame (fix runtime `HH_S0FIX`) y, ya caído, personaje que no
> se levantaba por un fallthrough ausente al final de `M55_FUN_8037a6f4` (fuga `0x38`/frame +
> lógica de caída saltada; nueva regla de ramas condicionales en `fix_fallthroughs.py`).
> Detalle: `notes/2026-09-16-fix-caida-fallthrough-m55-8037a6f4.md`.
>
> **Entrega del objeto del NPC: ARREGLADA y validada (2026-09-15)**: fallthrough sin encadenar en
> módulo 55 (fuga `0x48`/frame + animación saltada) y mid-entries sin registrar (`0x80379954`,
> `0x803798E8`). Módulo 55 = overlay de la secuencia de objeto (`docs/architecture.md` §2.2).
> Detalle: `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md`.
1. [x] **Pacing/cadencia (2026-09-17)**: **Fases 0-2, gating y validación Windows HECHAS**.
   Original = 30 fps lógicos (`fase0`). Causa dominante: **I/O de los logs always-on** → ahora
   opt-in con `HH_DIAG=1`. Windows (RTX 4080) con `run_pacing.bat`: **polls 27,1-28,4/s, audio
   60,0/s, VI 60,0/s** (dentro del ±10%; antes ~16/s en Linux-disco). El freeze del CaC **persiste**
   con la cadencia corregida → no era (solo) la cadencia. Detalle:
   `notes/2026-09-17-validacion-windows-pacing-y-cac.md`.
2. [•] **Seguir la partida** (usuario, en curso; ya llega lejos): ante un
   `Failed to find function at 0x...` (se ve en consola y en `hh_missing.log`), registrarlo con
   `python3 tools/analysis/add_mid_entry.py 0xADDR` + `tools/recomp.py --config
   config/game_combined.toml --force` (ver nota, "Ronda 9"; **no** usar `setup_module.py`: cascado
   de `auto_mid` → datos como código). Hechos hoy: `M55_FUN_80378c48` (menú), `M9_FUN_80203830`
   (cinemática al cruzar una puerta) y `M10_FUN_8021d8d0` (**primer combate cuerpo a cuerpo**);
   los tres contenedores empezaban en `nop`/delay slot (frontera real desplazada).
   **Aviso**: al registrar mid-entries, la 1ª versión de `add_mid_entry.py` recalculaba todos los
   tamaños y **borró** el override `M9_FUN_802169AC:0x1C0` (regresión del cuelgue del NPC). Corregido
   (edición mínima + overrides) y protegido por `tools/analysis/check_syms_overrides.py` (paso 1b de
   `recomp.py`; aborta si se pierde un override). Ver
   `notes/2026-09-16-crash-cinematica-midentry-m9-80203830.md`.
3. [x] **Guardado en cápsula (Controller Pak): VALIDADO (2026-09-16)**. Causa raíz (libultra del ROM):
   `osPfsFindFile` devuelve **5** con `*file_no = -1` cuando no hay fichero, no 10; el wrapper del
   juego (`FUN_80002DBC`) trata **>=6 como éxito sin rellenar el file_no** → usaba un `file_no` basura
   (95/233/237) y el juego nunca creaba su fichero. **Fix** (runtime `0619945`): FindFile→5 con
   `*file_no=-1`, DeleteFile→5, AllocateFile sin espacio→9. Verificado en Windows por el usuario: el
   guardado completa (UI de slots + `.pak` en `saves\`). Detalle:
   `notes/2026-09-16-guardado-capsula-pak-y-crash-cac-8021d8d0.md` y
   `notes/2026-09-16-guardado-capsula-validado.md`.
4. [ ] **Teardown SEGV** al cerrar en Windows (`Hybrid Heaven Recomp.exe +0x12A602`):
   mapear con `build_win/HybridHeavenRecomp-Release.map`, reproducir en Linux (cierre ordenado) y
   arreglar (orden de deinit/destructores estáticos).
5. [•] **Limpieza de instrumentación**: **HECHO el gating completo** — `hh_sched/hh_pi/hh_mq/
   hh_cmds/hh_ovl/hh_rsp` tras `HH_DIAG=1` (default off); bats de diagnóstico lo activan; verificado
   en Linux (defaults → solo `hh_state`/`hh_pak`; `HH_DIAG=1` → reaparecen todos). **Pendiente**:
   decidir sobre `requeue_pi=true`, `[MQDROP]`, la sombra `hh_sh_*` y el watchpoint.
6. [ ] **Mando**: identificar el botón N64 que abre los menús de combate cuerpo a cuerpo y asignarlo a
   **X** (`config.ini`). Decidir también `LB` (¿L?) y el atajo futuro de cámara/1ª persona.
7. [x] **Pipeline de compilación** (2026-09-16): `port/runtime.lock` apunta a commits **publicados**
   (runtime `feae2d5`, N64Recomp `cab94d9`). Verificado: build Linux (`tools/build_linux.sh
   --force-libs`) hace checkout de los pins y compila; build **Windows OK**; **CI verde**. Para
   commits locales sin publicar: `port/build_windows.local.bat` (no versionado; contenido en
   `port/README_windows.md` §2b). `build_windows.bat` imprime siempre el runtime usado.
8. [ ] **Smoke de arranque** (opcional, requiere ROM): con la ROM en `rom\` junto al `.exe`, arrancar
   y comprobar que el binario la encuentra (`hh.log`/consola) y que no hay `Failed to find function`.
   En Docker: `HH_HEADLESS=1` con `rom/` montado en `/work/rom`.

## Hecho (resumen; detalle en `notes/`)

- [x] **Gameplay alcanzado** (2026-09-14): menús → GAME START → escenas 3D in-game; overlays
  idx8/9/10/12/55; IA de combate (`0x80005C70`, `0x80005CB0`, `0x80022978`, `0x800229FC`, `0x80379970`
  + 17 mid-entries). Input sintético `HH_PRESS*`/`HH_STICK`/`HH_CSTICK`; record/replay por VI
  (RMSE=0 misma máquina). Ver `notes/2026-09-14-*.md`.
- [x] **Módulos por sección** (registro dinámico en la base real del loader; idx 7/23/24/25/54/99 +
  8/9/10/12/55), pipeline consciente de sección (`setup_module.py`, `validate_syms`,
  `fix_fallthroughs`, `gen_module_syms --filter-data`, `keep_syms_flat`).
- [x] **Memoria segura**: `MEM_*`/`TO_PTR` con mapeo no-mapeado → scratch (fix del callback de menú);
  `-fno-strict-aliasing` (fix de la transición).
- [x] **Guardado en cápsula (Controller Pak): VALIDADO en Windows** (2026-09-16): fix
  `osPfsFindFile`→5 con `*file_no=-1`; el juego muestra la UI de slots y escribe el `.pak` en
  `saves\` junto al `.exe`. PFS mínimo en RAM en `reimplemented_funcs`. Ver
  `notes/2026-09-16-guardado-capsula-validado.md`.
- [x] **Audio**: ucode `aspMain` del ROM recompilado; dispositivo WASAPI abierto; tasa 43200 Hz (720
  frames/VI) con feedback de cola; Release por defecto (Debug caía a 30 fps y rompía el pacing).
- [x] **Mando**: perfiles por contexto (`config.ini` [game]/[menu]) con detección automática por el
  flag de UI `0x802690D0` (pausa/mapa verificados); B físico=atrás en menús, Select=mapa, Y=C-Down
  (1ª persona, verificado), X libre.
- [x] **Diagnóstico**: volcados automáticos de crash (log + RDRAM + DMEM + registros del juego, SEH
  del entrypoint), watchdog de cuelgue (polls y audio), `hh_pi.log` con tiempos, `/MAP` de MSVC,
  `hh_missing.log`, bats de regresión `run_test_*`.
- [x] **Bisect del cuelgue del NPC**: conclusión documentada (no regresión) + `bisect_build.bat`.
- [x] **Build reproducible + CI/release** (2026-09-16): `tools/build_linux.sh` (rt64 clonado en commit
  fijo + **snapshot del runtime** + CMake), `Dockerfile` multi-stage (Debian/glibc, stages
  deps/build/runtime), `.github/workflows/{ci,release}.yml` (zip Windows / tar.gz Linux / imagen
  ghcr.io en tag) y devcontainer. Decisión: `docs/adr/0005-build-reproducible-y-artefactos.md`.
- [x] **Runtime y N64Recomp en forks propios** (2026-09-16, validado con los push): el runtime
  modificado vive en `hunkstalker/N64ModernRuntime` (rama `hybrid-heaven`, 23 commits) y el cambio
  de `recomp.h`/`symbol_lists.cpp` en `hunkstalker/N64Recomp` (que **se compila** en el port).
  `main` de ambos forks = upstream (crédito/lineage). Los scripts clonan por URL+SHA de
  `port/runtime.lock`; sin patch ni snapshot. Ver `docs/adr/0005-*.md`.
- [ ] **(Diferido) Ramas del toolchain**: para reproducir la **regeneración** (syms→C) hará falta
  una rama `hybrid-heaven-tool` en el fork de N64Recomp (la herramienta tiene 13 archivos
  modificados). El build no la necesita.
- [x] **Daño del robot, 2 capas** (2026-09-16, validado en Windows): `s0` machacado → dispatch
  frame/no-op roto (`HH_S0FIX` en runtime, incondicional, con auto-test `HH_TEST_S0BUG`); y caída que
  no se levantaba → fallthrough ausente en `M55_FUN_8037a6f4` (continuación `0x8037A884..` y epílogo
  compartido `0x8037A94C/A950` saltados; fuga `0x38`/frame). Ver `notes/2026-09-16-*.md`.

## Fundaciones pendientes

- [ ] **Higiene de runtime**: decidir si el lock single-CPU se elimina y si la entrega SI pasa a
  asíncrona (divergencias con upstream auditadas en `docs/architecture.md` §5).
- [ ] **Interfaces de sub-objetivos** (texto/traducción, audio, guardado): contrato y punto de hook.
- [ ] **Automatizar el inventario de módulos** (medir bases de forma desatendida vía loader).

## Licencia y distribución

- [x] **Créditos de terceros**: `CREDITS.md` (NMR GPL-3.0; N64Recomp/RT64/SDL2 MIT/Zlib; submódulos
  xxHash/miniz/o1heap; herramientas de desarrollo). Se incluye como `CREDITOS.md` en el `.zip`/`.tar.gz`
  de CI/release y en la imagen Docker.
- [x] **`LICENSE` = GPL-3.0** (2026-09-16): proyecto **público y comunitario**; compatible con
  N64ModernRuntime (GPL-3.0). `LICENSE` en el repo y se incluye en los artefactos
  (`.zip`/`.tar.gz` → `LICENCIA.txt`, imagen → `/usr/local/share/doc/...`).
- [x] **Mid-entry `M55_FUN_80378c48`** (2026-09-16, validado en Windows): crash en un menú
  (`Failed to find function at 0x80378C48`) → símbolo contenedor `M55_FUN_80378bb0` partido; el
  hueco hasta `0x80378CD8` era justo `0x90`. Recomp + build OK; usuario sigue avanzando.
  Ver `notes/2026-09-16-crash-menu-midentry-m55-80378c48.md`.
- [x] **Mid-entry `M55_FUN_8037948C`** (pendiente validar): epílogo compartido de `M55_FUN_80379464` (tres `b` vía `LOOKUP_FUNC`); recomp + build OK. Ver `notes/2026-09-16-fix-combate-midentry-m55-8037948c.md`.
- [x] **Menú: B físico = atrás** (pendiente validar): el `[menu]` no se aplicaba en el menú principal; ahora se detecta el front-end por el directorio `0x8008DFC0`. Ver `notes/2026-09-16-fix-menu-b-fisico-atras.md`.
- [•] **CaC: corrupción de estado (mitigado, BLOQUEANTE)** (2026-09-16): tras el mid-entry `M55_FUN_8037948C`, al entrar en combate el objeto `0x8024A990` acaba con el callback `+0x1C=0xFFFF84CD` (el emulador tiene `80135320`) y se corrompen nodos de cola (`[BADMQ] mq=00040000/C0000830` → divide-by-zero en `do_send`). Mitigado el crash (`get_function` no-op fuera de rango) pero el combate se cuelga. **2026-09-17 (cadencia ya corregida)**: el freeze persiste; tid 5 queda esperando en su cola de comandos `0x8005C288` (audio/VI siguen a 60/s). **B1 REFUTADO**: en combate la base `0x801BF1A0` la posee `rom=0x07000000` y módulo 23 corre reubicado en `0x801FA948`; `0x801C1EE0` es función real de M8 (se resuelve bien). La traza del plan miró la base equivocada; cambios especulativos revertidos. **B2 + ownership (2026-09-17, `notes/2026-09-17-cac-ownership-resuelto.md`)**: **repro Linux del freeze CONSEGUIDO** (replay corto desde guardado; PFS carga; `mode=0004`; objeto `0x8024A990`+0x1C=`0xFFFF84CD`; polls parados). Estado `[0x801CC8C4]` va `0→1→0xAF`, **nunca 2**. **Corrección clave**: en gameplay la función que corre en `0x801C1EE0` es de la **sección 7 (rom `0x07000000`, `M8_FUN_801c1ee0`)**, no de M23 → el selector/switch analizado (`M23_FUN_801c1dc0`) **no es el que se ejecuta**; el state machine está en la sección 7. `HH_RANGECLEAR=1` (opt-in) probado: **no cambia el freeze**. **Avance decisivo**: `[0x801CC8C4]` **es DATO del blob del módulo residente** (offset `0xD724`): tras cargar M23 → `0x00`, tras cargar sección 7 (M8) → `0xAF` (el canary veía `0→1→0xAF`). Barrido: ningún blob tiene `0x02` ahí → **la premisa del plan ("case 2 arma combate") no se sostiene**; hay que re-identificar el selector/estado real (sección 7, `M8_FUN_801c1ee0`→setter→`0x801C1F40`). Detalle: `notes/2026-09-17-cac-ownership-resuelto.md` §7-8. **Nuevo (ronda de esta sesión)**: el disable de `0x8024A990` está gated por `[0x8017DD92]==0` (`M10_FUN_8022c7ac` → `M55_FUN_80379410(a1=1)` → setter = `0xFFFF84CD`), y ese flag es 0 **también en el emulador**; en el emulador el objeto conserva **`M7_FUN_80135320` (módulo 7)**, en el port acaba en `0xFFFF84CD` → el desvío está en el estado que lleva a M10/disable, no en el gate. **Clarificado**: `0x802425F4` es `M12_FUN_802425f4`, de la misma sección (rom `0x0A000000`, base `0x802408F0`) que el armer `M12_FUN_802408f0` (notas previas llamaban “M10”/“M12” a la misma sección). Ese callback hace mates/globales y **no** pone el callback de módulo 7 → la transición la dispara otro sitio (tabla/loop). **Diferencial HECHO (2026-09-17, `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`)**: `work/hhinput.so` **ya reproduce el replay** (`HH_KEYS_REPLAY`, formato `%lf %lu %x %lf %lf` = el nuestro; sin Controller Pak en el emulador, el replay largo cubre el mismo combate). Emulador (replay largo 380 s, WP en `0x8024A9AC`): callback `0x80133AC0→0x80133B00→0x80135320` por setter y rearm `0x80135320` 8560 veces; **cero** `0xFFFF84CD`; objeto sano en el dump final. Port (WP `HH_WATCH_ADDR=0x8024A9AC`): mismo arranque M7, luego state machine M12 (`0x80241948…0x802425F4`, t=27–78 s), y a **t=136.241** `FUN_800058dc(a1=0xFFFF84CD)`. **Cadena exacta (gdb)**: `M10_FUN_8021b280 → M10_FUN_8022c7ac` (gate `0x8022CA90`: `if ([0x8017DD92]!=0) skip; a1=1`) `→ M55_FUN_80379410` (trampolín `a1-0x7B34`) `→ FUN_800058dc`; `1-0x7B34=0xFFFF84CD`. El rearm enmascara bit 23 (`FF7F84CD`) y el runtime ya lo trata como centinela no-op; el cuelgue real es la cascada `[BADMQ]`. **Medición hecha**: `HB_TRACE_EXEC` sobre el setter (main-exec) con el replay largo → 11.159 llamadas y **ninguna con `a1=0xFFFF84CD`** ni con `a1` de rango módulos 9/10/12; el emulador **no ejecuta** los state machines de módulo (`0x80241948…0x802425F4`, gate de módulo 10) que el port sí ejecuta (ver §9 de la nota). **Primera divergencia de FLUJO localizada (historia del loader)**: con el replay largo, las **21 primeras cargas** de `FUN_80003824` coinciden exactamente port↔emulador (incluidos los módulos del combate); la **#22** diverge: el emulador carga una **ráfaga de recursos de escena** a `0x8025D168…` en `vi=2195` (t≈36,6 s) que el port **no pide** (salta directo a `0x0053C77C @0x801BF1A0`, que en el emulador es la #35, t≈60,1 s). A partir de ahí todo diverge (state machine M12, gate, veneno a t=136,2). **Siguiente**: identificar qué dispara la carga #22 (tabla/estado del dispatcher `0x80004778`) y por qué el port no la pide. Opción de apoyo: `.mpk` de mupen con el mismo guardado (**no** savestate; `r64dump` no los carga). **Pendiente de higiene**: fuente del plugin con replay ausente del repo (`tools/analysis/hhinput.c` es la vieja) → recuperarla/documentarla. **Replay grabado** (partida nueva, 8846 muestras, VI 83→19167) con firma confirmada: objeto **`0x8024AAF8`+0x1C=`0xFFFF84CD`**, dispatcher reintentando en bucle (`hh_missing.log`) hasta el watchdog. Evidencia en `work/debug/cac/20260917_1146_windows_replay/` y `notes/2026-09-17-cac-replay-windows-y-firma-8024aaf8.md`. **Replay arreglado a poll-exacto** (`HH_REPLAY_MODE=poll` por defecto, `HH_REPLAYLOG=1`; validado en Linux con 0 discrepancias en 1793 polls): `notes/2026-09-17-replay-preciso-modo-poll.md`. **Siguiente**: mantenedor rebuild + `run_replay.bat` (modo poll; `sync` si hiciera falta) para confirmar que reproduce el CaC; después, reproducir en Linux con instrumentación de `func_map`/`get_function` y, si se confirma B1, fix candidato v3 (borrar `[ram, ram+size)` al cargar sección). **(2026-09-17, ronda nueva) MECANISMO DE LA DIVERGENCIA #22 RESUELTO**: la ráfaga son pasos de guion de la **línea temporal del módulo 24** (driver `M24_FUN_801bfaa0`); en el emulador el periodo `g2=[0x801D8CE8]` avanza `0→1` en VI 2187 (esperas por `osGetTime-epoch` de 3/11/20 s) y de ahí sale la ráfaga; en el port el avance (`M24_FUN_801bffac`) **nunca** ocurre (esperas siempre 0) y la **vía alterna de cambio de escena** (`M24_FUN_801bf508`→`M24_FUN_801c0254`, evento **id=1**) dispara en VI≈840 cargando los módulos 8/9/10/12 sobre el módulo 24 antes de la ráfaga. **(2026-09-17, rondas 2-3) CAUSA RAÍZ = alineación del replay**: `[0x80089478]` es el registro de flancos de input (`FUN_800021b4`, `t8=(prev^nuevo)&nuevo` desde `[0x8005CE50]`) y el bit `0x1000` = **START recién pulsado**. El emulador no lo pulsa durante la transición (watchpoint `0x89474-0x8947C`: solo boot y VI≥~3400); el port sí (VI 765/783/798) porque aplica el replay **por frame** y los samples 412-431 (START de menú, `vis` 1092-1135) caen en la transición; con `HH_REPLAY_MODE=vi` el START cae en VI 1092 pero el port ya lleva ~330 frames (original ~576) por su relación frame↔VI ~1.86 vs ~2.65. Base de tiempo general refutada. **Fix en curso (WIP)**: `HH_REPLAY_CLOCK=1` implementado (reloj esclavo a la muestra + interpolación intra-frame; sin ella había deadlock), pero con interpolación la **transición sigue adelantada** (muestra ~341 vs ~582) → el replay **aún no es fiel**; pendiente localizar dónde se pierden ~240 frames (`[LD384] … s=` vs emulador) y decidir gatear el frame loop por `vis`. **No cerrar conclusiones del CaC con el diferencial actual**. **El test de juego del port nativo lo hace el usuario (mantenedor)**; el entorno de dev solo hace pasadas headless. Detalle: `notes/2026-09-17-cac-timeline-modulo24-periodo.md` (§4b-5) y `notes/2026-09-17-replay-clock-y-desfase-frames-wip.md`.
- [x] **Datos del juego fuera del repo** (2026-09-16): purgados de **todo el historial** (capturas,
  assets, manifiestos); el **código del port** sí se versiona → el `.exe` compila **sin ROM** y la
  busca en runtime (`rom/baserom.us.z64`). Ver ADR 0005.
- [ ] **Sanear menciones a la ROM en docs/notas** (frases cortas del juego en notas/`PROYECTO.md`).

## Higiene del repo (candidatos de limpieza)

> Criterios: `notes/2026-09-16-limpieza-repo-inventario.md`.

- [ ] **Archivar** (`tools/archive/`) los scripts de una sola vez de `tools/analysis/` (62 `.java`
  de Ghidra + helpers), conservando los vivos de `docs/workflows.md` §6.
- [ ] Archivar **variantes obsoletas de `config/`** (activa: `game_combined.toml`).
- [ ] Decidir el **`work/` rastreado** (3 scripts de captura).
- [ ] **NO borrar** `config/*.syms.toml.keep` (los usa `gen_module_syms`/`setup_module`) ni
  `keep_syms*.txt`/`module_extras.json` ni `config/n64recomp_changes/*`.
- [ ] (Opcional) Selector de ROM tipo menú (Zelda64Recomp/Goemon64Recomp); hoy se carga de `rom/`.
- [ ] **Regeneración por terceros**: publicar la rama `hybrid-heaven-tool` del fork de N64Recomp
  (la herramienta tiene 13 archivos modificados).

## Backlog

- [ ] **Cadencia/hitches de puertas** (2026-09-17, tras el CaC): 28,4 `polls`/s con dips 21-25 y
  tirones al cruzar puertas (`trans`/LZSS); medir y valorar precarga/decode + enganche a VI.
  NO es la causa del CaC. Detalle: `notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`.
- [ ] **Audio (futuro)**: desacoplar de los fps (720 frames/frame de juego; a 30 fps hay huecos).
  Ideas: sacar la task del bucle de juego o amortiguar/resamplear.
- [ ] **Símbolos**: fronteras gruesas (`0xADDR:0xSIZE`) y auto-mid del módulo 12 (datos como código);
  regenerar syms con cuidado (nota 2026-09-15 §4).
- [ ] **Textos/traducción**: encoding + extracción + re-inserción (requisito de producto).
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco (+ Rumble).
- [ ] **Builds/empaquetado**: validar "build once, promote" en GitHub y empaquetado **Steam Deck**
  (AppImage/nativo). Hecho: receta Linux + Docker + CI + Releases (`docs/adr/0005`).
- [ ] **Tarea #3** (mapa overlay→RAM por BizHawk): complementa la medición empírica de bases.
- [ ] Limpiar data-as-code (189 sospechosas) → habilita re-evaluar `use_lookup_for_all_function_calls`.

## Documentos de detalle (no duplicar)
`PROYECTO.md` · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md` · `notes/2026-09-1*.md`.
