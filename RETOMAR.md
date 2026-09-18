# RETOMAR — punto de retomada de la sesión

> Handoff para arrancar rápido. **Fuentes de verdad**: `TODO.md` (tareas), `PROYECTO.md` (estado),
> `docs/README.md` (visión) y la nota más reciente en `notes/`. Actualizar o borrar al cambiar la tarea.
> Última sesión: **2026-09-18**.

## Estado en 6 líneas

- **El port corre y se juega en Windows** (menús → gameplay → CaC, mando Xbox, audio 43200 Hz), a
  **30 ticks/s** estables (rendimiento resuelto: fix de `get_function` + Fase B de assets).
- **El replay reproduce el CaC de forma fiable** con **`HH_REPLAY_MODE=poll`** (Windows VI≈20710,
  Linux VI≈20949); el **emulador pasa el CaC con el mismo input** (objeto sano). Tenemos los dos lados
  con input idéntico.
- **Diferencial por VI (20200–20900)**: port y emu **idénticos** en el estado del CaC (cuando el port no
  congela). Única divergencia reproducible = **timing** del loader (carga #12: port vis 413 vs emu vi
  1535), no la secuencia (verificada 1:1: 43/43 cargas).
- **Veneno capturado en vivo**: `FUN_800058dc` escribe `0xFFFF84CD` en `0x8024AB14` (callback del objeto
  `0x8024AAF8`); `M7_FUN_8012e774` lo consume. **Cadena confirmada**:
  `M10_FUN_8021b280 → M10_FUN_8022c7a4 → M10_FUN_8022c7ac → M55_FUN_80379410 → FUN_800058dc`.
- **CONTRALADO EMULADOR (decisivo)**: con el mismo replay, el emu ejecuta `FUN_800058dc` **1426 veces
  sin el veneno** y **0 veces** `M10_FUN_8021b280`/`M55_FUN_80379410`. La forma correcta es **NO
  ejecutar el disable**; el callback sano del objeto es `801CB71C`.
- **Lección de replay**: con el port ya a 30 ticks/s, `mode=vi` **sesga** el input; **`mode=poll` es el
  correcto**. `HH_REPLAY_PACE` vacío.

## TU TAREA AHORA (pasos exactos)

**Objetivo: confirmar QUIÉN dispara `M10_FUN_8021b280`** (que lleva al disable) en el port y **por qué
el emulador no lo ejecuta**. Ya está todo listo para capturarlo; falta una pasada que congele.

### 0. Instrumentación ya preparada (runtime NMR, **sin commitear**)

En `librecomp/src/overlays.cpp` y `librecomp/src/recomp.cpp` (ver §6c de la nota del diferencial):
- **`FUN_800058dc` enganchado SIEMPRE** (barato, ~1400 llamadas): al ver `a1=0xFFFF84CD`/`0xFF7F84CD`,
  vuelca a **`hh_venom.log`** la **pila guest** (palabras RA en `[sp, sp+0x600)`) + el anillo de
  llamadas. **La pila dirá quién llama al setter** (esperado: `M55_FUN_80379410` ← `M10_FUN_8022C7AC`
  ← `M10_FUN_8022C7A4` ← `M10_FUN_8021b280`).
- `hh_watch_log` (recomp.cpp) también sabe volcar pila al veneno, pero **gated por `HH_WATCH_VENOM=1`** y
  el watchpoint **enmascara el freeze** → preferir el wrapper del setter (sin watchpoint).

> **OJO (aprendizaje de la última pasada)**: el run **sí congeló** pero `hh_venom.log` quedó **vacío**.
> El store del veneno se hace con `ret=exe+0xA3D15` = **`FUN_800058f4+0x5D`** (una continuación por
> **fallthrough** del setter), y `FUN_800058f4` **no** pasa por el wrapper de `0x800058DC` (el C lo
> llama directo: `funcs_1.c:8283`). ⇒ Para capturar el llamante hay que **envolver también
> `FUN_800058f4`** (o usar el watchpoint con `HH_WATCH_VENOM=1`), no solo `FUN_800058dc`.

### 1. Capturar `hh_venom.log` (pasada que congele)

```
cd port/HybridHeavenRecomp/build_dbg
cmake --build . -j8     # ya compilado; recompilar si se toca el runtime
HH_REPLAY=<...>/cac_rec.txt HH_REPLAY_MODE=poll ./"Hybrid Heaven Recomp"
```
Sin watchpoint ni `HH_DUMP_VI`/`HH_M24LOG` (perturban el freeze). El freeze headless es **intermitente
(~1 de 3 pasadas)**: si no congela, repetir. Cuando salga, leer `hh_venom.log`.

### 2. Comparar con el emulador por qué NO se ejecuta `M10_FUN_8021b280`

Ya verificado: **0 ejecuciones en todo el replay** (`HB_TRACE_EXEC=0x8021B280`, log
`/tmp/opencode/emu_trace_b280.log`, volcado `work/debug/cac/emu_trace_b280`). Investigar qué condición
lo evita. **Candidato nº1: la espera de escena de §4** (el port llega antes a la transición).

### 3. Atacar el desfase de timing (frame limiter / espera de escena)

- El frame limiter `0x80001A88` busy-waitea en `osGetTime` (`0x80031190`, **reimplementado por el
  runtime**). El otro port le pone un hook de yield; nosotros no. Ver §6b de la nota.
- Verificar las rutinas libultra del frame limiter (`0x80026E58`/`0x80026F58`/`0x80034C24`/`0x80034AB8`
  = `__ll_*`): el otro port las aporta como stubs; en el nuestro están en `symbol_lists.cpp`. Si el
  runtime no las implementa bien, el `target` del limiter se calcula mal.

### 4. Investigar `0x8005C4F0`/`0x8005C268`

En el port (sin freeze) están a **cero**; en el emu valen `80049930` (§2b de la nota).

> **Informe del diferencial (con §6 de esta ronda): `notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`.**

## Datos de partida (fijos)

- Replay: `port/HybridHeavenRecomp/build_win/bin/Release/logs_pacing_20260918_210956/cac_rec.txt`
  (9815 muestras). **No re-grabar** salvo que se cambie algo del port.
- Captura del veneno (watchpoint): `build_dbg/hh_watch.log` (`HH_WATCH_ADDR=0x8024AB14`),
  `hh_hang_rdram_50826_*.bin`.
- Contralado emulador: `work/debug/cac/emu_trace_*` (setter 1426/0 veneno; `M10_FUN_8021b280` 0).
- Dumps del diferencial (paridad): `work/debug/cac/diff_vi_20260918/`.
- **Bug corregido**: `hh_ring2_n`/`hh_ring_n` desbordaban `int` a ~50 s (43 M llamadas/s) → SEGV en
  `hh_ring2_record`. Ya son `uint64_t` (runtime NMR, **commit pendiente de push**).

## Contexto del CaC (lo ya sabido; no repetir)

- Reproducido en Linux con replay; **no es rendimiento**.
- La **ráfaga #22** del módulo 24 **sí** se ejecuta (teoría "burst saltado" refutada).
- La llamada a `M10_FUN_8022C7A4` en `0x8021B69C` está condicionada por `lhu [objeto+0x2C]` ∈ {0xA,0xB}
  (pero ese campo vale 0 en los dumps → el discriminante es otro).
- Otro port independiente (`danielgomesvieira2000/hybrid-heaven-recomp`) va **más atrás** (no llegó al
  CaC) pero su doc confirma `0x801CC8C4` = "level/battle select" y da el lead del frame limiter.
- Histórico: `notes/2026-09-17-cac-ownership-resuelto.md`, `notes/2026-09-17-cac-veneno-ffff84cd-y-llamante.md`,
  `notes/2026-09-17-bizhawk-replay-freeze-con-rafaga.md`, `notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`.

## Otras tareas vivas (TODO.md "Ahora")

- **Audio**: sincronizar la tasa (feedback del error de cola SDL en `osAiGetLength`).
- **Menú in-game (ADR 0008)**: spike go/no-go antes de comprometerlo.
- **Definir ADR 0009** (visión de cobertura nativa/clean-room) cuando se adopte.
- **Teardown SEGV** al cerrar en Windows; **mando** (botón de menú CaC → X, bloqueado por el CaC).

## Comandos útiles

- Build Linux debug: `cmake --build port/HybridHeavenRecomp/build_dbg -j8`
- Run headless: `DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_NOAUDIO=1 ./port/HybridHeavenRecomp/build_dbg/"Hybrid Heaven Recomp"`
- Replay headless (el bueno): `HH_REPLAY=<cac_rec.txt> HH_REPLAY_MODE=poll` (añadir `HH_DUMP_VI=...`,
  `HH_M24LOG=1` solo si no perturban el objetivo).
- Emulador: `tools/analysis/emu_ref.sh <prefix> <secs> [dumps]` (usa `work/r64dump`, `work/roms/us_retail.z64`).
- Lanzadores Windows: `run_cac_record.bat`, `run_cac_replay.bat` (**ya usa `poll`**), `run_cac_tick2.bat`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `INDEX.md`; `--check` valida).

## Knobs del runtime

`HH_AI_FIFO` (def fiel), `HH_AI_MAX_MS`, `HH_TIMESCALE`, `HH_VI_EVERY`, **`HH_REPLAY_MODE` (`poll`)**,
`HH_REPLAY_PACE` (vacío; **no** usar `vi`: tirones), `HH_REPLAY_CLOCK` (reloj determinista por VI),
`HH_DUMP_VI`, `HH_DUMP_SAMPLE`, `HH_M24LOG`, `HH_S0FIX`, `HH_DIAG`, `HH_WATCH_ADDR`/`HH_WATCH_VENOM`/
`HH_MQLOG_ALL`. **Fase B**: `HH_TRANS_CACHE` (def 1), `HH_TRANS_NATIVE` (def 1), `HH_TRANS_VERIFY`,
`HH_TRANS_DUMP`.

## Estado de repos/branches

- **Main repo**: `main` = `origin/main` (`17f4406`, todo pusheado). Historial reescrito (limpieza de la
  mención a ROMs). `backup-orig` conserva el historial anterior (borrar con `git branch -D backup-orig`).
- **Runtime fork** (`port/HybridHeavenRecomp/lib/N64ModernRuntime`, repo aparte): `hybrid-heaven` en
  `e5b15f5` (ya pusheado) **con 2 ficheros modificados sin commitear** = la instrumentación de esta
  ronda (`overlays.cpp`, `recomp.cpp`). `port/runtime.lock` apunta al pin publicado.
- Windows compila con `port\build_windows.local.bat` (árbol local, no versionado).

## Documentación de esta sesión

- **`notes/2026-09-18-diferencial-port-emu-vi-cac-paridad.md`** (informe del diferencial + §6: cadena
  del disable, comparación con el otro port, instrumentación nueva).
- **`notes/2026-09-18-hito-replay-reproduce-cac-port-vs-emu.md`** (HITO: replay fiel + emulador).
- **`notes/2026-09-18-cac-replay-en-vivo-no-reproduce.md`** (reloj determinista, test de determinismo).
- **`notes/2026-09-18-faseb-cache-trans-implementado.md`** (Fase B + fix de `get_function`).
- **`docs/README.md`** (visión/roadmap) · `notes/archive/2026-09-18-plan-maestro-legacy.md`.
