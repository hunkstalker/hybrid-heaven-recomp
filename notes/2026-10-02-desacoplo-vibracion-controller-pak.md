# Desacoplar VIBRACIÓN del Controller Pak (memoria + vibración a la vez)

> Tarea 2026-10-02, rama `menu-carga-guardado-partida`. Item 11 de `TODO.md` (antes BLOQUEANTE).
> Estado: **HECHO y VALIDADO en Windows (2026-10-02)**: con `VIBRACIÓN = SÍ` se guarda/carga
> **y** vibra. Verificado además headless.

## Problema

En N64 el **Rumble Pak** y el **Controller Pak** comparten la **misma ranura** del mando. El port
reporta al juego `RumblePak` cuando `CONTROLES → VIBRACIÓN = SÍ` (para que el rumble funcione), y el
juego interpreta que **no hay Controller Pak** → no se puede guardar ni cargar. Los mensajes de
conectar/desconectar ya se suprimían (`hh_pak_message_hook`), pero el flujo seguía roto.

## Hallazgos (medidos en el C recompilado)

- **El acoplamiento no está en el runtime, está en una función del juego**: `func_80002BE0`
  (`build/recomp/RecompiledFuncs/funcs_53.c:13396`) es el **clasificador de accesorio**. Llama a
  `osPfsInitPak` (Controller Pak), `osMotorInit` (Rumble) y `osGbpakInit`, y **prioriza el Rumble
  Pak**: si `osMotorInit` devuelve 0 → retorno **7** (Rumble) y **solo consulta el PFS si no hay
  Rumble**. Con VIBRACIÓN=SÍ nunca entra en la rama de Controller Pak.
- **El rumble se arma por una vía separada**: `func_80002A94` (`funcs_56.c:25069`) llama a
  `osMotorInit` y, si va bien, marca la tabla `0x80037780[ch] = 1`; `func_80002B44`
  (`funcs_57.c:20354`, arranque de motor) consulta esa tabla y llama a `__osMotorAccess`.
  → El rumble **no depende** del retorno del clasificador.
- **El PFS del port es virtual** (`lib/N64ModernRuntime/librecomp/src/pak.cpp`) y es independiente
  del pak reportado: las `osPfs*` siempre funcionan sobre el `.pak`. Solo el clasificador del juego
  bloqueaba.
- El enum `Pak` del runtime solo se consume en `__osContGetInitData` (booleano `pak != None`) y en
  `osMotorInit` (exige `== RumblePak`). El juego **no lee** ese tipo; lo deduce él mismo. Por eso un
  "pak combinado" en el runtime **no arregla nada** (se descartó).

## Solución

1. **Hook del clasificador** (`src/hooks/sections.cpp`), registrado con
   `add_loaded_function(0x80002BE0, hh_pak_detect_hook)`:
   - ejecuta el **original** (deja el motor inicializado: `OSPfs::status |= PFS_MOTOR_INITIALIZED`, y
     corre las ramas PFS/GB normales);
   - si `input_vibration_enabled()` y el retorno fue **7** → se fuerza **0** ("Controller Pak OK", el
     valor que da en vanilla con la vibración apagada).
   - Traza opt-in `HH_PAK_TRACE=1` → `hh.log`: `[vib] func_80002BE0 ch=0 vib=1 ret=7 -> 0`.
2. **PFS de UN solo sistema de memoria** (`pak.cpp`): `osPfsInitPak`/`osPfsInit` sirven el mismo
   `.pak` en **cualquier canal 0..3** (antes solo canal 0). Materializa "un sistema de memoria" para
   el futuro Modo VS (el 2.º jugador carga un slot del mismo sistema, sin 2.º Controller Pak).
3. **Vibración global** (`src/subsystems/input.cpp`): `set_rumble` ahora rumba **todos los mandos
   conectados** (J1 y J2 a la vez). Se añadió un registro `g_pads` de mandos SDL (hotplug en el bucle
   de eventos + apertura perezosa del primero); el input de gameplay sigue usando el puerto 0.
4. **No se toca** el runtime (enum `Pak`), ni el formato del `.pak`, ni `get_connected_device_info`
   (sigue reportando `RumblePak` con vibración ON).

## Evidencia headless (2026-10-02)

`HH_PAK_TRACE=1 HH_PAKLOG=1` + `[input] vibration = si`:

```
[00:41:06.056] [vib] func_80002BE0 ch=0 vib=1 ret=7 -> 0
get_connected_device_info port=0 -> dev=1 pak=1
osMotorInit ch=0 dev=1 pak=1 -> 0
osPfsInitPak ch=0 = 0 / ch=1 = 0 / ch=2 = 0 / ch=3 = 0
osPfsFindFile = 0
osPfsReadWriteFile file_no=0 READ off=0 size=256 -> 0
```

→ Con `RumblePak` reportado, la vibración sigue armada **y** el PFS (memoria) responde.

## Validación Windows (2026-10-02)

`CONTROLES → VIBRACIÓN = SÍ`: guardar (`DATA SAVE`) + cargar (`CONTINUAR`) **y** el mando vibra.
`VIBRACIÓN = NO` sigue guardando. Confirmado por el mantenedor.

## Notas / seguimiento

- El PFS responde ahora en canales 1..3 (antes `PFS_ERR_INVALID`); en single-player el juego sondea
  esos canales y no ha dado síntomas. Si apareciera algo raro en el menú de guardado, acotar los
  canales extra a cuando haya un 2.º mando / Modo VS.
- **Modo VS / 2P** (futuro): input de puerto 1 (`get_input`/`get_connected_device_info` solo sirven el
  0), mapeo `controller_num → gamepad`; local primero, online después.
- **Fork NMR**: el cambio de `pak.cpp` vive en el submódulo `lib/N64ModernRuntime` (commit + push del
  fork antes de bumpear el gitlink).
