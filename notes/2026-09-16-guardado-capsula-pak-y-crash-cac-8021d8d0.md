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

Runtime (**fork**, commit local `dc22060`): volcado a **fichero** (compartido por `pak.cpp` e
`input.cpp`), **activo por defecto** durante esta fase:

- `hh_pak.log` en el **directorio del exe** (que es donde `run_windows.bat` pone el CWD). `HH_PAKLOG=0`
  lo desactiva; `HH_PAKLOG=<ruta>` lo redirige. Flush por línea (el final queda aunque crashee).
- Cada `osPfs*`/`osGbpakInit` registra: argumentos (incluidos `company`/`game` y los **nombres de
  fichero en hex**), el `ra` del llamante, el **retorno**, y el estado tras la llamada (nº
  ficheros/usados/libres + los 4 `OSPfs` del juego en `0x8005CE70 + ch*0x68`). `pak_load/pak_save`
  escriben ruta y nº de ficheros; `osMotorInit` y `get_connected_device_info` van al mismo fichero.
- **Autotest de la API PFS** (opt-in, `HH_PAKTEST=1`): init → allocate → find → write → read →
  filestate → numfiles → freeblocks → delete sobre un pak temporal (`hh_paktest.tmp`) y un rdram de
  mentira, restaurando el estado real y **sin tocar `saves/`**. **Resultado en Linux: OK (0 fallos)**
  → nuestra API PFS es consistente; el problema no está en la aritmética de ficheros, sino en cómo/si
  el juego la usa. Se dejó opt-in para no arriesgar el arranque tras el susto de abajo.

**Hallazgo colateral**: el `.pak` **no** vive junto al exe, sino en el directorio de config del
runtime. En Linux el log lo imprime: `/home/<user>/.local/share/HybridHeavenRecomp/saves/hh.us.bin.pak`
(en Windows, el equivalente bajo `%APPDATA%`). Conviene confirmarlo en el log del usuario antes de
concluir "no hay `saves/`" mirando junto al exe.

- `port/runtime.lock`: `NMR_COMMIT` → `dc220601e11ccfc6f4d95665296587d66fb9cd80`.
- `port/build_windows.bat` / `tools/build_linux.sh`: si no se puede hacer checkout del commit fijado
  **abortan** con mensaje claro en vez de compilar un runtime distinto. Como la carpeta de trabajo es
  la compartida, el checkout del commit local funciona **sin publicar el fork**.

### Para obtener el log

```bat
port\build_windows.bat
port\run_windows.bat
REM ir a una capsula, aceptar el guardado, esperar el aviso final y salir
REM el volcado queda en port\HybridHeavenRecomp\build_win\bin\Release\hh_pak.log
```

## 4. Regresión de arranque en Windows (`setvbuf`) y primer volcado real

**Síntoma**: el `.exe` moría nada más arrancar (tras `Initializing recomp heap...`,
`exit -1073740791` = `0xC0000409`) y `hh_pak.log` quedaba **creado pero vacío** (0 bytes).
Ese "creado y vacío" fue la pista: el fallo estaba **dentro de la primera línea** del log, entre el
`fopen` y el `vfprintf`.

**Causa**: el CRT de Windows considera inválido `setvbuf(stream, NULL, _IOLBF, 0)` y llama al
*invalid parameter handler* → fast-fail `0xC0000409`. En Linux no ocurre. Además el tamaño 0 no
aporta nada porque el log hace `fflush` por línea. **Fix** (`dc22060`): quitar `setvbuf`, pasar los
`%zu` a `%u` (portabilidad MSVC) y dejar el autotest como opt-in.

**Primer volcado útil** (arranque del juego, que ya lee datos de guardado):

```
osPfsFindFile ra=00000000 co=4134 game=4E485645 name=00001D22 ext=34413221
  -> osPfsFindFile = 10            (PFS_ERR_NO_FILE: el pak está vacío)
osPfsReadWriteFile ra=00000000 file_no=95 READ off=0 size=256 buf=80265FF8
  -> osPfsReadWriteFile = 5        (PFS_ERR_INVALID: file_no=95 fuera de rango)
osMotorInit ch=0 dev=1 pak=0 -> 1  (PFS_ERR_NOPACK: sin Rumble)
osMotorInit ch=1 dev=0 pak=0 -> 4  (PFS_ERR_CONTRFAIL: puerto sin mando)
```

Lectura: `game=0x4E485645` = `"NHVE"` (código de juego). El juego busca su fichero, no lo encuentra
(`10`) y aun así intenta **leer con un `file_no` basura (`95`)** → `5`. Encaja con la hipótesis de que
el juego espera el camino **"pak nuevo → formatear → crear ficheros"** (`PFS_ERR_NEW_PACK`) y que,
como nuestro pak se declara "formateado y vacío", se salta ese camino. El volcado del flujo de la
**cápsula** (el que importa) se capturará en la siguiente partida.

## 5. Siguiente paso

- Leer **el final** de `hh_pak.log` (y ver si aparece el `.pak` en la ruta que indique el log) para
  identificar la primera llamada que falla o el punto donde el juego deja de llamar a PFS tras
  aceptar el guardado; entonces arreglar la semántica correspondiente (tamaño/reserva `PAK_SIZE`/
  `PAK_RESERVED`, `NumFiles`, `FindFile`, o `PFS_ERR_NEW_PACK` + ruta de formato). Capturas de la
  secuencia de mensajes: pendientes de recibir.
