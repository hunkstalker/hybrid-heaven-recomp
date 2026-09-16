# 2026-09-16 — Crash al entrar en CaC: callback centinela `0xFF7F84CD`

Tras el mid-entry `M55_FUN_8037948C`, al entrar en combate cuerpo a cuerpo cae:

```
Failed to find function at 0xFF7F84CD
  caller ra=00000000 sp=8005BE90 r4=8024A990 r5=8008DA88 r6=00000004 r7=8005BE08
  host_ret=exe+0x5031F     (FUN_80005270 + 0x6FF)
```

## Cadena

- `FUN_80005270` es un **dispatcher de callbacks**: lee `[s0+0x18]`, `[s0+0x1C]`, `[s0+0x20]` y hace
  `jalr`; se salta el callback si `bit23 (0x00800000)` está puesto (convención de "deshabilitado").
- El objeto `s0=0x8024A990` tenía `+0x18=8012E584`, `+0x1C=FF7F84CD` (malo), `+0x20=8012E654`
  (funciones del módulo 7).
- El escritor de `+0x1C` era `M55_FUN_80379410` (vía el setter `FUN_800058DC`: `sw a1,0x1C(a0)`) al
  que el módulo 10 llama **con `a1=1`** (`0x8022CAA4`): `a1 - 0x7B34 = 0xFFFF84CD`, un **centinela**
  con bit23 puesto que el dispatcher debería saltarse.
- En algún punto el bit23 se pierde (`0xFFFF84CD` → `0xFF7F84CD`, watch `hh_watch.log` t≈136.1) y el
  dispatcher intenta llamar a un puntero imposible. No se localizó aún el punto exacto (varias
  escrituras al campo desde `M7_FUN_8012e774`, que copia `[obj+0x8C]` a `+0x1C`).

## Mitigación (runtime, `librecomp/src/overlays.cpp`)

En `get_function`, si el target **no cae en el rango de código** (`0x80000000..0x807FFFFF`) —un
puntero corrupto/centinela como `0xFF7F84CD`— se devuelve un **no-op** con aviso (hasta 20),
en vez de abortar. Esto equivale a lo que el juego pretendía ("callback no habilitado"). Un target
**dentro** del rango pero sin registrar sigue abortando, para poder añadirlo como mid-entry.

Además quedan en el runtime (diagnóstico) el `host_ret` y el volcado `hh_badlookup.log` al fallar el
lookup.

## Pendiente

- Validar en Windows que el combate continúa (y no se queda colgado por saltar el callback).
- Si aparece, encontrar por qué se pierde el bit23 (recompilación de `M7_FUN_8012e774`/quien escribe
  `+0x8C`).
