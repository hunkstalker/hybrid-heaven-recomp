# Fase 0 — Referencia de cadencia del original (emulador): HH = 30 fps lógicos

> Evidencia de la Fase 0 del work order `notes/2026-09-17-workorder-pacing-cadencia.md`.
> Resuelve la ambigüedad "30 o 60 fps lógicos" del original. Fecha: 2026-09-17.

## Comando

```sh
HB_TRACE_EXEC=0x80001454,0x80005270,0x80000ed0 \
  tools/analysis/emu_ref.sh work/debug/emu_rate2 60 60 \
  > work/debug/emu_rate2_stdout.log 2>&1
```

(El stdout del harness se redirige a mano; `emu_ref.sh` no lo hace.)

## Resultado (60 s emulados, r64dump + rice/GLX)

| Función | Hits (t≥10 s) | VI span | **hits/VI** | hits/s |
|---|---|---|---|---|
| `FUN_80001454` (frame) | 1457 | 2912 | **0.5003** | 29.8 |
| `FUN_80005270` (dispatcher) | 1456 | 2910 | **0.5003** | 29.8 |
| `FUN_80000ed0` (submit task) | 1457 | 2910 | **0.5007** | 29.8 |

- **Gaps entre frames consecutivos en unidades de VI (t≥10 s): 1456 gaps, todos exactamente `2`**
  (media 2.0). → El frame lógico corre **una vez cada 2 VI**.
- Fase de boot (t<10 s): mezcla (484 hits, gaps de 1 y 2 VI) — artefacto del arranque/attract, no del
  régimen estable.
- `disp` y `submit` van **1:1 con el frame** (mismo conteo total: 1884 = 1884 = 1884 en los 60 s).
- VI/s medidos: **≈57.8** (`vi_count=3534` a t=59.99); el déficit vs 60 es ruido del harness/trace.
  La métrica robusta es hits/VI.

## Conclusión

**Hybrid Heaven ejecuta su lógica a 30 fps** (no 60): el frame consume un mensaje de VI cada dos
interrupts, y dispatcher/submit acompañan 1:1. El "1:1" del work order es **igualar el ratio del
original**, es decir **0.5 hits/VI** (≈30/s) para frame y disp — no 1.0.

## Implicación para el port

- Target: `frame/VI ≈ disp/VI ≈ 0.50` (≈30/s con VI a 60/s).
- Estado actual del port (work order §3): frame ≈22/s (**0.37/VI**), disp ≈16–24/s (**0.27–0.40/VI**)
  → el port va **por debajo** del original; no hay que "frenarlo", hay que recuperar cadencia.
- La hipótesis de "media cadencia" del plan CaC queda matizada: es ~0.7× en frame y ~0.5–0.8× en
  dispatcher, no exactamente la mitad; la divergencia de state machines sigue siendo plausible pero
  el objetivo medible pasa a ser **0.5 hits/VI**.

## Artefactos

- `work/debug/emu_rate2_stdout.log` (traza + `vi_count`), `work/debug/emu_rate2.t0.bin` (dump RDRAM),
  prefijo `work/debug/emu_rate2`. (Gitignored; evidencia resumida aquí.)
- Comparativa previa: `work/debug/ratetest.log`, `work/debug/emu_rate_stdout.log`.

## Siguiente

Fase 1 del work order (`§5`): instrumentar el port (Linux `build_dbg`) con
`HH_TRACE` + `HH_VERBOSE/GATELOG/TBLTRACE/MQLOG_ALL/STATE_SECS` para localizar la espera que roba
tiempo entre frames y quién deja `[0x8005CD4C]` en 1–2.
