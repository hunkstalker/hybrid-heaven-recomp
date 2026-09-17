# CaC — B1 REFUTADO: el callback `0x801C1EE0` es del módulo residente (base real ≠ base link-time)

> Corrección del diagnóstico de `notes/2026-09-17-cac-b1-confirmado-callback-801c1ee0.md`.
> Fecha: 2026-09-17. Evidencia: `hh_ovl.log` y bytes de los blobs de la pasada de grabación
> (`work/debug/cac/20260917_1146_windows_replay/`).

## 1. Lo que estaba mal

- Se asumió que los símbolos `M23_FUN_*` (link base `0x801BF1A0`) describían el código que corre en
  esa base durante el combate. **No es así.**
- Orden de cargas real (Windows, pasada de grabación; sólo 32 líneas de `[OVL]` en toda la partida):
  - t=3.005 `rom=03000000` (módulo 23) → `0x801BF1A0`
  - t=3.163 `rom=03000000` (módulo 23) → **`0x801FA948`** (el `trans` lo **reubica**)
  - t=13.167 `rom=04000000` → `0x801BF1A0`
  - t=18.510 `rom=07000000` (array `section_7_module8_funcs`) → `0x801BF1A0` (se queda hasta el
    combate, t≈254).
- Por tanto, en combate la base `0x801BF1A0` la posee el módulo **`rom=0x07000000`**, y **módulo 23
  corre en `0x801FA948`**. La traza `HH_TRACE_RANGE=0x801BF1A0:0x9000` del plan miró la base
  equivocada: atribuyó a M23 código que es del módulo residente `rom=0x07000000`.

## 2. Prueba con bytes (decisiva)

Comparando `work/scratch/module8_be.bin` y `module23_be.bin` en el mismo offset:

| addr | módulo `0x07000000` (residente) | módulo 23 |
|---|---|---|
| `0x801C1EE0` | `27bdffe8 3c06801c…` = **prólogo de función** (`addiu sp,sp,-0x18`) | `304ab000…` = código interior |
| `0x801C40EC` | `44807000…` (interior a `M8_FUN_801bf1c0`) | `afa40000 03e00008` = función diminuta |

→ El callback `0x801C1EE0` del objeto **sí** es una función real del módulo residente y el port la
resuelve correctamente (`M8_FUN_801c1ee0`). **No había bug de propiedad ahí.**

## 3. Cambios revertidos / conservados

- **Revertidos**: split `M23_FUN_801c1ee0` (syms combined y module23), entradas en
  `keep_syms.txt`/`module_extras.json`, y el *range-clear* de `load_overlay` (runtime). Recompilado
  (`recomp.py --force`) y build/boot verificados.
- **Conservados** (útiles y ya validados): replay **poll-exacto** (`HH_REPLAY_MODE=poll`,
  `HH_REPLAYLOG=1`, `run_replay.bat`) y la instrumentación `[OWNER]` (gated por `HH_FUNC_OWNER`).

## 4. Consecuencias para la Parte B

- Las conclusiones tipo "la cadena de módulo 23 no corre" **deben re-medirse en la base real**:
  módulo 23 en `0x801FA948` → sus funciones quedan en `0x801FA948 + offset` (p. ej.
  `M23_FUN_801c1dc0` → `0x801FD568`, `M23_FUN_801c40f8` → `0x801FF8A0`).
- **Siguiente**: pasada (Windows, con el replay ya fiel) trazando **las dos bases** o, mejor,
  registrando en cada `load_overlay` la base activa y resolviendo llamadas por **base real**; y
  revisar el state machine (`M23_FUN_801c1dc0`, selector `case 2`) y la ruta de "disable"
  (`FUN_800058dc` escribiendo `0xFFFF84CD`) sin presuponer el módulo.
- Hipótesis de las 13 direcciones "raras" detectadas en la traza (t≈19 s, interior a
  `M8_FUN_801bf1c0`, coincidentes con símbolos M23): riesgo secundario de entradas rancias entre
  módulos que comparten base; confirmar antes de tocar símbolos.
