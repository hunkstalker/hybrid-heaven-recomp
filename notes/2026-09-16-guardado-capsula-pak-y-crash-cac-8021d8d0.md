# 2026-09-16 — Guardado en cápsula (Controller Pak) sin UI de slots + crash de CaC `0x8021D8D0`

## 1. Crash al entrar en combate cuerpo a cuerpo: `M10_FUN_8021d8d0`

```
Failed to find function at 0x8021D8D0
(exit -1073740791)
```

- `add_mid_entry.py 0x8021D8D0` → **módulo idx 10** (base `0x8021B150`); no delay slot; no switch.
- El contenedor `M10_FUN_8021d8c4` (vram `0x8021D8C4`, size `0x14`) empezaba con **tres `nop`**
  (`0x8021D8C4/C8/CC`); la función real arranca en `0x8021D8D0` (`lui $a3,0x801C` /
  `addiu $a3,$a3,-0x4410` = puntero a `0x801BC410`) y **cae** en `M10_FUN_8021d8d8` (cadena de
  fallthrough). Mismo patrón que los mid-entries anteriores (nop/delay slot mal asignado como inicio).
- Split: `M10_FUN_8021d8c4` `0xC` + `M10_FUN_8021d8d0` `0x8`; recomp + build Linux OK.
- **Pendiente**: validar en Windows el primer CaC.

## 2. Proceso de guardado del juego (documentado)

No hay "SAVE" en el menú de pausa. El guardado es **en el mundo**, mediante **cápsulas**:

1. La cápsula está **fija en una sala**; se puede entrar cuantas veces se quiera.
2. Al entrar, el juego **cura** la salud.
3. Después **detecta si hay Controller Pak**.
4. Si lo detecta, **pregunta si quieres guardar partida**.
5. Si dices que sí → debería mostrar las **filas/slots de guardado**, elegir, aprobar y escribir.

### Síntoma observado (exe del último commit)

- La detección del pak **parece funcionar**: el juego **pregunta si quieres guardar**.
- Al aceptar: **no aparece la UI de selección de slot** (se salta), **no se guarda**, aparece un
  **aviso de accesorio (Rumble Pak)** y el personaje **sale de la cápsula**.
- **No existe `saves/`** en el equipo del usuario.

### Evidencia y lectura

- `saves/` solo se crea en `pak_save()` (runtime `librecomp/src/pak.cpp`), que se llama desde
  `osPfsInit` (formato), `osPfsAllocateFile`, `osPfsDeleteFile` y `osPfsReadWriteFile(WRITE)`.
  Es decir: **ninguna operación de escritura/alocación llegó a ejecutarse**.
- Como el juego **sí pregunta** por guardar, la detección básica (`FUN_80002be0` →
  `osPfsInitPak`→0, `osMotorInit`→`PFS_ERR_NOPACK`, `osGbpakInit`→0xB; status `0` = mempak OK) pasa.
  El corte está **tras confirmar**: la ruta que lee/prepara el área de guardado del pak.
- Candidatos (a confirmar con log, no a ciegas):
  - `osPfsFindFile` → `PFS_ERR_NO_FILE(10)` (pak vacío) y el juego no encadena la creación del fichero.
  - `osPfsAllocateFile` rechazado por tamaño: nuestro `PAK_SIZE=0x8000` con `PAK_RESERVED=0x200`
    ⇒ máximo `0x7E00`. El **tamaño que pide el juego es dinámico** (viene por argumento), así que
    pudo pedir más y recibir `PFS_ERR_INCONSISTENT(3)` **sin escribir** (encaja con "no `saves/`").
  - `osPfsNumFiles` devolviendo `max_files=16` (nuestro `PAK_MAX_FILES`) frente al valor real del
    pak, si la UI de slots se dimensiona con él.
  - `pfs->status` a 0 (libultra marca `PFS_INITIALIZED`) y demás campos (`version/dir_size/...`) vacíos.
- El texto del aviso **no está en ASCII ni Shift-JIS** en la ROM (usa glifos propios), así que no se
  puede localizar por cadena; el mensaje "Controller Pak / Socket 1" (vram `0x805FAA11`, off
  `0x5FB611`) es un blob mixto con códigos de control y tabla de punteros del overlay de menú.

## 3. Instrumentación añadida (Fase 1, aprobada)

Runtime (**fork**, commit local `333cdbd`): `HH_PAKLOG=1` traza
`osPfsInitPak/osPfsInit/osPfsFreeBlocks/osPfsAllocateFile/osPfsFindFile/osPfsDeleteFile/
osPfsReadWriteFile/osPfsFileState/osPfsNumFiles/osPfsIsPlug/osPfsChecker/osPfsRepairId/osGbpakInit`
(args + **retorno**), `osMotorInit` (dev/pak/retorno), `pak_load/pak_save` (ruta + nº ficheros) y
`get_connected_device_info` (una línea por puerto). Sin el env no imprime nada.

- `port/runtime.lock`: `NMR_COMMIT` → `333cdbdcd3de2872c15b17f075d9b2b0cd1028cc`.
- `port/build_windows.bat` / `tools/build_linux.sh`: si no se puede hacer checkout del commit fijado
  (p. ej. fork sin publicar) **abortan** con mensaje claro en vez de compilar un runtime distinto.

### Para obtener el log

```bat
REM 1) publicar el runtime (una vez)
pushd port\HybridHeavenRecomp\lib\N64ModernRuntime
git push fork hybrid-heaven
popd
REM 2) compilar y ejecutar con el log
port\build_windows.bat
set HH_PAKLOG=1
port\run_windows.bat
REM 3) reproducir el guardado en una capsula y enviar hh_pak.log (stderr) + saves\*.bin.pak si aparece
```

## 4. Siguiente paso

- Con el log: identificar la primera llamada que devuelve error tras aceptar el guardado y arreglar
  la semántica PFS correspondiente (tamaño/reserva, `NumFiles`, `FindFile`, o `PFS_ERR_NEW_PACK` +
  ruta de formato). Capturas de la secuencia de mensajes: pendientes de recibir.
