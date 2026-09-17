# CaC — B2 avanzado: switch del selector (s0=0x801CC8C4) y análisis de bases reales

> Ronda 2026-09-17 tras refutar B1 (`notes/2026-09-17-cac-b1-refutado-base-real-modulos.md`).

## 1. Instrumentación nueva: `HH_MODTRACE` (base-aware)

- `HH_MODTRACE=rom:offset:label,...` traza `get_function(addr)` por **offset dentro del módulo
  cargado**, resolviendo la sección que contiene `addr` y comparando el offset → funciona aunque el
  módulo esté **reubicado** (módulo 23 en `0x801FA948`). Si se omite `rom`, vale cualquier módulo.
- Implementado en `overlays.cpp` (`hh_modtrace_match` + log `[MODT]`) y activable por env.
- Verificado: en boot se ven las dos cargas de módulo 23 (`0x801BF1A0` y `0x801FA948`).

## 2. Análisis retrospectivo de propiedad (traza Windows de la grabación)

- Parseando `hh_ovl.log` (cargas) + `recomp_overlays.inl` (símbolos por sección) + `hh_trace.log`:
  **228 llamadas ejecutaron código de un módulo distinto al residente** (p. ej. `owner sec[4]
  rom=04000000` mientras reside `sec[7] rom=07000000`), todas a **t≈18.5-19.1** (menú/boot temprano).
- Causa: al reutilizar base (`0x801BF1A0`), el port **no borra** las entradas del módulo anterior en
  direcciones que el nuevo no cubre → `func_map` sirve código rancio.
- **En combate (t≈254) no se detectó ningún mismatch**: los callbacks/llamadas del combate sí
  pertenecen al módulo residente. → El bug de entradas rancias es real pero **no explica el freeze**
  (ocurre pronto); queda como riesgo secundario.

## 3. State machine del selector (`M23_FUN_801c1dc0`, s0 = `0x801CC8C4`)

```
s0 = 0x801D0000 - 0x373C = 0x801CC8C4 ;  switch (lbu [s0])  (jump table @0x801CF264)
  case 0 (0x801C1F10): [0x801BBC0D]=0 ; setter(a0=obj, a1=0x801C3940)
  case 1 (0x801C1F30): 0x800023A8(0); 0x80020718(8); setter(a1=0x801C3CDC)
  case 2 (0x801C1F58): setter(a1=0x801C40F8)          <-- ARMA la cadena de combate
  case 3 (0x801C1F70): setter(a1=0x801C4960)
  case 4 (0x801C1F88): si ([0x80037754] & 1) setter(a1=0x801C5108)
  case 5 (0x801C1FB4): s0=0; bucle 6x 0x8001B204(i, 0, 0, 0x801CF30C); jal 0x801BF1A0
```

- `setter` = `FUN_800058DC` (escribe el callback `+0x1C` del objeto).
- **case 2** es el que arma combate (coincide con el plan); el estado `[0x801CC8C4]` nunca llega a 2
  (se queda en `0xAF`, en port y emulador).
- **case 5 llama a `0x801BF1A0`** (base link-time del módulo). Si el módulo corre reubicado
  (`0x801FA948`), ese destino es incorrecto salvo que el loader reubique también el **código** — y el
  port ejecuta C recompilado con esa constante fija. Línea de investigación prioritaria.

## 4. Siguientes pasos

1. **Pasada Windows con el replay** usando la instrumentación nueva (rebuild + `run_replay.bat`):
   - `HH_MODTRACE`: ¿corre la cadena en la base link-time o en `0x801FA948`? ¿se llama `0x801BF1A0`
     (case 5) y a dónde resuelve?

## Actualización (validación de `HH_MODTRACE`)

- Primer intento en Windows sin líneas `[MODT]`: era un **error aritmético mío en los offsets** del
  spec (`0x801C1340 - 0x801BF1A0 = 0x21A0`, no `0x1A0`). La instrumentación en sí funciona.
- Validado en Linux con el replay: `HH_MODTRACE=03000000:21A0:M23_mask,...` produce **106 hits**
  `[MODT] M23_mask addr=801C1340 -> <func de módulo 23>`. El resto de offsets del spec
  (`2C20/2D40/4F4C/4F58/521C/5324/5428`) son correctos.
- `run_replay.bat` corregido (offset `21A0`) y en modo `modt` guarda la consola en
  `modt_console.log` (para poder analizarla desde `/app`).

## Flujo de repro CORTO desde guardado (2026-09-17)

- El mantenedor reportó que el replay largo **varía** (durante el diálogo la cámara se sitúa distinto
  y el input grabado deja de valer) → el port no es 100% determinista en tramos largos.
- Acordado: grabar un replay **cargando partida** (tramo corto hasta el freeze). `run_corrupt.bat`
  ya graba; basta cargar el save y jugar hasta el CaC. Se apoya el `.pak` del mantenedor en
  `work/debug/cac/saves_windows/hh.us.bin.pak` (md5 `157b0c18f4e944508dc9a4b700602428`) y se copió a
  `port/HybridHeavenRecomp/build_dbg/saves/` para intentar también el replay en Linux con el mismo
  estado de partida.
- Si el replay cross-platform sigue divergiendo, la traza `[MODT]` se hará en **Windows**
  (`run_replay.bat`, por defecto `modt` + `modt_console.log`), que ya es fiel en la máquina que lo
  grabó.
   - trazar `setter 0x800058DC` (a0/a1) y el estado `[0x801CC8C4]`; y los escritores de
     `0xFFFF84CD` (M10/M55).
2. **Estático**: quién escribe `[0x801CC8C4] = 2` (buscando stores a `s0`/absolutos) y por qué la
   ruta de "disable" (`FUN_800058DC` con `a1=0xFFFF84CD` vía M55) se dispara antes.
3. Decidir si el problema central es la **reubicación de módulos** (destinos absolutos en código
   recompilado) → posible `ADR`/modelo de módulos.
