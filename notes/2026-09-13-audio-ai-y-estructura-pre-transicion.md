# 2026-09-13 — Audio/AI, tasas del emulador y estructura de contexto pre-transición

> Continúa `2026-09-13-deadlock-sp-race.md` (§5). Objetivo: por qué el port no alcanza la
> transición (`fe00`, id 0x19) con el deadlock SP ya resuelto.

## 1. Fix del mapa task→hilo (runtime, gitignored)

La clave del mapa `sp_task_submitters` estaba mal en ambos lados (PTR completo como clave vs
cálculo con base distinta): el lookup **siempre fallaba** para audio y `target` quedaba `NULLPTR`
(reparto normal). Corregido a clave por **offset de rdram**:

- store: `sp_task_submitters[(uint32_t)((uint64_t)task_ - 0xFFFFFFFF80000000ULL)] = submitter;`
- lookup: `uint32_t task_key = (uint32_t)((uint8_t*)task - rdram);`

Evidencia (`work/debug/port_keyfix.log`, 95 s): audio vuelve (`SPT type=2`: 67) y todas las
completaciones llevan `target=0xffffffff8005c828` (t18), correcto.

## 2. AI sin dispositivo de audio (port, tracked)

Sin device SDL, `osAiGetLength()` devolvía 0 siempre (el AI "no reproducía"). Añadido **drenaje
virtual** en `support.cpp` cuando `audio_device == 0` (cola virtual drenada a `sample_rate` real;
knob de diagnóstico `HH_AI_SPEED`). Efecto sobre el pacing: **ninguno** (55–58 tasks/40 s con y sin
speed-up ×32) ⇒ el intro no está paced por `osAiGetLength`.

## 3. Tasas reales del emulador (`HB_TRACE_EXEC` + r64dump; breakpoints)

- `FUN_80005270` (dispatcher) y `FUN_80000ed0` (pump): **3833 en 60 s (64/s)**; el port hace 9–12/s.
- `FUN_80003824` (loader): 22 llamadas; 11 de boot hasta t=10,54 s y **burst de 12 a t=63,66–65,26 s**
  (la transición), con `a0=0x5FBEC6 a1=0x801BF1A0 a2=0x135B0` (id 0x19) a t=63,66 s; caller común
  `ra=0x80004778`.
- `FUN_801CBDC0/88/90` (progreso módulo 23): **0 llamadas en el emulador** (≤70 s) ⇒ no son el
  mecanismo de progreso (confirma la nota anterior).
- `osSetTimer` en el port: **0 llamadas**. `osAiSetNextBuffer` (0x80034B70) en el emulador antes de
  la transición: **0 hits** (el audio no arranca antes del burst).

## 4. Estado: el port iguala al emulador pre-transición

Con el deadlock resuelto, el estado del port a VI36000 es **idéntico** al del emulador antes de la
transición: `node1C=801BF1CC`, `n18=8012E584`, `fe00=0`, `0x801CFCF4=801D03C0`. Tras la transición
el emulador pasa a `fe00=801E`, `node1C=0`, `n18=03E00008`. El port no diverge: aún no dispara el
burst del loader.

**Ojo con los dumps del harness**: los `.bin` de `r64dump` ya están en LE nativo; el `bswap32` de la
nota de AGENTS los **corrompe** (`801BF1CC` → `CCF11B80`). El port y el emulador coinciden sin swap.

## 5. Divergencia estructural detectada

Comparando palabras **estables** (VI3600 vs VI36000 en port; VI3000 vs VI3600 en emu) y distintas
entre ambos, destaca una estructura de contexto en **`0x8004FAEC..0x8004FBC0`**:

- En el emulador está poblada desde t0: `+0x14=80091BF0` (hilo; antes `80059D80` = t5), `+0x2C=
  8005BF14`, `+0x30/34=8005C4B0` (obj RSP), `+0x38=80000A3C`, `+0x4C=8005C288`, `+0x60=800007F0`,
  `+0x68=80000824`, `+0x6C=8005C560` (mq VI), `+0x70=8004FBB8` (lista), `+0xA8=800279A0`.
- En el port está **todo a cero** (nunca se inicializa). Réplicas del mismo patrón a `0x80051AEC` y
  `0x80053AEC` (stride 0x2000) también a cero.

Es el candidato nº 1 a explicar por qué el juego se queda en el estado pre-transición pese a
superar el conteo de dispatches del emulador.

## 6. Reproducción

```sh
# Emulador (tasas + loader; los breakpoints ralentizan pero los conteos son útiles)
HB_TRACE_EXEC=0x80034B70,0x80000ed0,0x80005270 tools/analysis/emu_ref.sh work/debug/emu_rate 60 55
HB_TRACE_EXEC=0x80003824,0x801CBDC0,0x801CBE88,0x801CBE90,0x801BF1CC \
  tools/analysis/emu_ref.sh work/debug/emu_m23 70 65
# Port (AI virtual + audio)
HH_VERBOSE=1 HH_AI_SPEED=32 HH_DUMP_VI=3600 ... ./Hybrid\ Heaven\ Recomp
```

Artefactos (gitignored): `work/debug/{emu_rate_stdout.log,emu_m23_stdout.log,port_keyfix.log,
port_ai.log,port_ai2.log,port_ai32.log,port_tim.log,port_ql18.log,port_fixsp5.log}`.
