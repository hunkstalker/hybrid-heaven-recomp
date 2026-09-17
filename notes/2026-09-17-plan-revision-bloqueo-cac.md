# 2026-09-17 — Plan de revisión del bloqueo al entrar en combate (CaC)

Documento de trabajo. Resume lo **probado**, lo que **falta revisar** y el orden propuesto.
Evidencia cruda y backups de logs: `logs_previos/`, `logs_nueva/`, `logs_sin_objetos/`,
`logs_flag/` (junto al `.exe` de Windows). Instrumentación en `port/run_corrupt.bat` + runtime
(`HH_DEBUG_TOOLS`).

---

## 0. Hechos probados (no volver a comprobarlos)

1. **NO es el guardado/carga**: partida nueva desde cero (sin cargar) se cuelga igual
   (`logs_nueva/`). El save del port es byte a byte igual al `.mpk` del emulador.
2. **NO son los fixes de objeto (NPC) ni de daño**: partida nueva sin recoger objetos y sin
   recibir daño se cuelga igual (`logs_sin_objetos/`).
3. **Mecanismo exacto de la corrupción**:
   - El objeto (`0x8024A990` cargando, `0x80249F04`/`0x8024AAF8` en partidas nuevas; la dirección
     **varía**) recorre **21 callbacks de módulo 10** (`0x80241948 … 0x802425F4`).
   - Módulo 10 lo **deshabilita**: `FUN_80005270(+0x6FF)` → `M10_FUN_8021b280` →
     `M10_FUN_8022c7ac` → `M55_FUN_80379410(a1=1)` → `FUN_800058dc` escribe `0xFFFF84CD` en `+0x1C`.
   - `M7_FUN_8012e774` (`0x8012E7F8`) hace `[+0x1C] &= 0xFF7FFFFF` → `0xFF7F84CD` (bit 23 borrado).
   - El dispatcher intenta llamar `0xFF7F84CD` → no-op (mitigación local) → state machine atascado
     → cascada `[BADMQ]` → watchdog.
   - El "disable" está **gated por `[0x8017DD92] == 0`**; ese flag se queda a **0** toda la partida.
4. **La cadena de "arranque de combate" de módulo 23 NO se ejecuta**:
   `0x801C43BC → 0x801C44C4 → 0x801C45C8` (traza = 0), ni el setter del flag
   `M7_FUN_80152cf8` (0x80152CF8).
5. La ruta del "armer" por habilidad (`M10_FUN_80223260`, gated por `mode==0xA`) **no se ejecuta**;
   el armer (`M12_FUN_802408f0`) corre **1 vez** y para otro objeto. `mode` nunca llega a `0xA`.
6. **Comparación estática**: el C recompilado de la cadena M23/M10/M7 es **fiel al ROM**; los
   `@fallthrough-fix` de módulo 23 son **cadenas muertas** tras `jr ra` (ruido de
   `fix_fallthroughs.py`, no ejecutan).
7. **Pacing**: VI/audio a **60/s**, lógica (`polls`) a **~28/s**. El hack de audio
   (`librecomp/src/ai.cpp`, 43200 Hz) es una **inferencia de tasa** (720 muestras/VI × 60), no un
   forzar-60fps.

---

## 1. Cosas a revisar (orden propuesto)

### Parte A — Pacing / cadencia (barato, responde a la hipótesis del usuario)
- [ ] **A1**. Medir la **tasa real del dispatcher** `FUN_80005270` en el port actual (traza
      `0x80005270`) y compararla con `polls` (~28/s) y con el emulador (nota: **64/s**).
      Si el port va a ~30 y el original a ~60, la lógica va a **mitad de cadencia**.
- [ ] **A2**. A/B del feedback de audio que alimenta `osAiGetLength`:
      - normal (cap a 1 VI, `sample_rate/60`)
      - `HH_AI_QUEUE_REPORT=full` (cola real)
      - opcional `HH_AI_SPEED=<x>`
      Medir si cambia `polls/s` (frames de lógica) y/o el desenlace.
- [ ] **A3**. Determinar la **tasa de lógica del original** con evidencia: en el emulador, contar
      `FUN_80001454` (frame) o `polls` por segundo. ¿30 o 60?
- [ ] **A4**. Si el port va a la mitad: localizar el porqué (VI delivery, `get_frames_remaining`,
      `speed_multiplier`, handshake AI/SP) y si eso rompe scripts por-frame.

### Parte B — Módulo 23 (arranque de combate) — la ruta que no corre
- [x] **B0 (resultado, pasada con `HH_TRACE_RANGE=0x801BF1A0:0x9000`)**:
      módulo 23 se ejecuta **hasta `0x801C40EC`** (stub no-op, 20 llamadas) y **nunca entra en
      `0x801C40F8`/`0x801C4104`** (offset `0x4F58`/`0x4F64` = 0), que son los que arman la cadena de
      combate (`0x801C4200` → `0x801C43BC` → `0x801C44C4` → `0x801C45C8`).
      El **selector** `M23_FUN_801c1dc0` (0x801C1DC0) hace `switch (lbu [s0+0])`, `s0 = 0x801CC8C4`;
      **`case 2` arma `0x801C40F8`** (cadena de combate).
      Tasa del dispatcher: `disp` ≈ 24/s (4172/3770 por pasada) vs emulador (nota: 64/s).
- [x] **B0b (pasada canary sobre `0x801CC8C4` + traza `0x801C1DC0`)**:
      - `[0x801CC8C4]` **solo cambia 2 veces** (vi=534 `0→1`, vi=961 `1→0xAF`) y luego queda fijo;
        **nunca 2**. En los dumps `emu` y `port` vale **`0xAF` en ambos** → puede no ser la variable
        de estado real (o `s0` no es 0x801CC8C4 en runtime).
      - La **entrada** `0x801C1DC0` **no se llama** vía `get_function` (0); en cambio se llama la
        dirección intermedia `0x801C1EE0` (4 veces) → **posible problema de frontera de símbolo /
        entry de módulo 23**.
      - No hay escrituras literales a `-0X373C` en el C; el default del selector escribe `sb 0,(s0)`.
- [ ] **B1**. Revisar **símbolos/bases de módulo 23** (¿el port carga/ejecuta módulo 23 en la base
      link-time `0x801BF1A0`?; ¿fronteras de `M23_FUN_801c1dc0` correctas?). La llamada a
      `0x801C1EE0` (intermedia) es sospechosa.
- [ ] **B2**. Reversear el **state machine de `M23_FUN_801c1dc0`** (estático): qué estado (`2`) arma
      el combate y quién lo fija.
- [ ] **B3**. Comparar con emulador **solo** la variable/estado (no hace falta llegar al combate si
      se puede leer en un breakpoint temprano).


### Parte C — Estado del objeto (semántica)
- [ ] **C1**. Mapear el struct del objeto: significado de `+0x18/+0x1C/+0x20/+0x24/+0x2C/+0x36/+0x8C`.
- [ ] **C2**. ¿La secuencia de 21 callbacks es la esperada? (¿ataque/animación/cinemática?).
- [ ] **C3**. Condición real del `disable` en `M10_FUN_8022c7ac` (más allá del flag `[0x8017DD92]`):
      leer qué decide entre "armar siguiente" y "deshabilitar".
- [ ] **C4**. ¿Quién debería rearmar tras `0x802425F4`? (armer por habilidad vs módulo 23).

### Parte D — Recompilación / símbolos
- [ ] **D1**. Revisar los `@fallthrough-fix` muertos de módulo 23 y buscar **fallthroughs
      faltantes** en la cadena (clase del cuelgue del NPC).
- [ ] **D2**. Verificar bases/símbolos de los módulos implicados (7/23/10) y de las funciones de la
      cadena (`M23_FUN_801c43bc`, `M23_FUN_801c44c4`, `M23_FUN_801c45c8`, `M10_FUN_8021b280`,
      `M10_FUN_8022c7ac`, `M55_FUN_80379410`, `M7_FUN_8012e774`).

### Parte E — Instrumentación / higiene (transversal)
- [ ] **E1**. Corregir el **watchpoint de hardware (DR)**: sigue con falsos positivos; ahora mismo
      se ignora. Arreglar o retirar del bat.
- [ ] **E2**. Añadir a `HH_TRACE`: `0x80005270:disp`, `0x801C4200:M23_upd`, `0x801C43BC:M23_setup`,
      `0x801C1340:M23_mask`.
- [ ] **E3**. Mantener backups por pasada (`logs_*/`) y no mezclar runs (los logs se abren en "w").

---

## 3. Fix probado y REVERTIDO: registro rancio de módulos al reutilizar base

Se probó a desregistrar del `func_map` la sección anterior al reutilizar base (con
`load_module_by_source`). La v1 (desregistrar también la misma sección reubicada) **rompía el
arranque** (`Failed to find function at 0x801BF1CC`, se carga en dos bases a la vez); la v2 (solo
rango destino + misma base) **arrancaba pero NO cambiaba el bloqueo**: misma cadena de módulo 23
(`0x4F64/0x5060/0x521C/0x5324/0x5428` = 0), mismo estado `[0x801CC8C4]`, mismo cuelgue. **Revertido**
(el código vuelve al original; queda un comentario). No es la causa raíz.

## 3b. Anomalía de pacing (Parte A) — pendiente de confirmar

Medido en el port: `VI` y `audio` a **60/s**, pero `polls` (frames de lógica) a **~28/s** y el
dispatcher `FUN_80005270` a **~24/s**. La nota del emulador (`2026-09-13`) midió `FUN_80005270` a
**64/s**. Si la lógica del original va a ~60 y el port a ~30, hay media cadencia y los state machines
por-frame/temporizador divergen. **Confirmar la tasa del original en gameplay** (no hace falta
llegar al combate: boot → GAMEPLAY y medir `FUN_80001454`/dispatcher con `HB_EXEC`/traza).

---

## 4. Pasadas propuestas (una variable por pasada)



1. **Pasada P1 (medir)**: `run_corrupt.bat` con trazas de A/B1 añadidas; **cargar partida** hasta
   el combate. Objetivo: tasa del dispatcher + si M23 corre.
2. **Pasada P2 (pacing)**: igual pero con `HH_AI_QUEUE_REPORT=full`. Comparar `polls/s` y desenlace.
3. **Pasada P3 (si A/B1 apunta a M23)**: trazar la máscara `0x801C1340` y la rama concreta.
4. **Pasada P4 (validación)**: cuando haya fix, repetir el repro corto (cargando) y luego el A/B
   sin objetos/daño.

> Recordatorio: no commitear sin pedirlo; borrar bats/scripts puntuales; los `.exe`/`build_*` no se
> versionan.
