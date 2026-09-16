# 2026-09-16 — Guardado en cápsula (Controller Pak) sin UI de slots + crash de CaC `0x8021D8D0`

## 1. Crash al entrar en combate cuerpo a cuerpo: `M10_FUN_8021d8d0`

```
Failed to find function at 0x8021D8D0
(exit -1073740791)
```

- `add_mid_entry.py 0x8021D8D0` → **módulo idx 10** (base `0x8021B150`); no delay slot; no switch.
- El entorno `M10_FUN_8021d8c4` (vram `0x8021D8C4`, size `0x14`) empezaba con **tres `nop`**
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

Runtime (**fork**, commits locales `dc22060`+`4e1ee0a`): volcado a **fichero** (compartido por `pak.cpp` e
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

- `port/runtime.lock`: `NMR_COMMIT` → `4e1ee0a892aee41d778e4f578e7e5f9457e5a5a2`.
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

## 5. Secuencia real del guardado (capturas) y volcado de la cápsula

Capturas (`Referencias screenshots/Captura de pantalla 2026-09-16 1552xx.png`):

1. `DATA SAVE / CONTROLLER PAK`, **panel de slots vacío**, `Save play data? Yes/No`.
2. `Please connect Controller Pak to Controller 1 now. Do not remove Controller Pak.`
3. `Select location in which to save play data.` (panel vacío: no hay filas seleccionables).
4. `Saving current play data here. Yes/No`.
5. `Could not save. Canceling saving data.`
6. `Please connect a Rumble Pak now if you wish to use it. Please push A Button to continue.`
7. De vuelta en el mundo (sale de la cápsula).

Volcado final de `hh_pak.log` en la cápsula (lo esencial):

```
osPfsInitPak ch=0 -> 0
osPfsFindFile co=4134 game=4E485645 ("NHVE") -> 10   (nuestro NO_FILE mal: debe ser 5)
osPfsReadWriteFile file_no=237 WRITE off=256 size=3328 -> 5   (INVALID: file_no basura)
osMotorInit ch=0 -> 1 (NOPACK)
```

**Nunca aparece `osPfsAllocateFile`**: el juego da por hecho que su fichero existe y escribe con un
`file_no` no inicializado porque `osPfsFindFile` falló.

## 6. Causa raíz y fix: `osPfsFindFile` debe devolver **5** con `*file_no = -1`

**Desensamblando la libultra del propio ROM** (`osPfsFindFile`, 0x8002EE40):

```
0x8002EFC8: addiu $t9, $zero, -1    ; *file_no = -1
0x8002EFCC: addiu $v0, $zero, 0x5   ; return 5  (= fin del bucle de busqueda, no encontrado)
```

Es decir: **no existe `PFS_ERR_NO_FILE`=10 aquí**; esta libultra devuelve **5** cuando no encuentra el
fichero y deja `*file_no = -1`. Nosotros devolvíamos **10**.

Y ese 10 caía en el peor sitio: el wrapper del juego **`FUN_80002DBC`** mapea los errores de PFS a su
propio enum (`0→0, 1→1, 2→2, 3→9, 4→8, 5→3`) y **cualquier valor ≥6 lo trata como ÉXITO (0) sin
rellenar el `file_no` de salida** (`sltiu $at,$v0,0x6` + `beq`). Con 10, el juego creía que el
fichero existía y leía/escribía con un `file_no` basura (los 95/233/237 del log) → `PFS_ERR_INVALID`
→ "Could not save". Con **5**, el wrapper devuelve 3 (no-cero) y el juego detecta que no hay fichero
(y puede crear el suyo con el dispatcher op 2 → `AllocateFile` de 0x3500).

**Fix** (runtime `ff70e20`):
- `osPfsFindFile`: no encontrado → `*file_no = -1` y retorno **5**.
- `osPfsDeleteFile`: no encontrado → **5** (el ROM lo propaga de FindFile).
- `osPfsAllocateFile`: sin espacio → **9** (data full, como el ROM).

### 6.1 Intento descartado: pak virgen → `PFS_ERR_NEW_PACK` (runtime `4e1ee0a`)

Antes de desensamblar probé que un pak virgen devolviera `PFS_ERR_NEW_PACK` (el dispatcher
`FUN_800183D0` op 2 = crear ficheros → `M7_FUN_801414B0` → `osPfsAllocateFile` size **0x3500** =
53 páginas = los 4 slots). **No funcionó**: con ese estado el juego se quedaba en bucle de detección
y crasheaba en GAME START (`[HANG]` + SEGV en `FUN_80002dbc`) porque **no tiene función de formateo
en el ROM** (no existe `osPfsInit`) — un pak real de fábrica ya viene formateado y devuelve 0. Se
dejó **opt-in** (`HH_PAK_NEWPACK=1`) y se revirtió el valor por defecto. También se rellenan campos
`OSPfs` como libultra (`status=PFS_INITIALIZED`, `version=2`, `dir_size=16`, `inode_start_page=2`).

## 7. Siguiente paso
## 8. Portada portable: `saves/` junto al `.exe`

`hh::get_app_folder_path()` devolvía la carpeta de datos del usuario y el port la registra como
`config_path` del runtime; de ahí que el `.pak` (y `hh.log`) cayeran en
`%APPDATA%\HybridHeavenRecomp` / `~/.local/share/HybridHeavenRecomp`. Ahora **la carpeta de datos es
la del ejecutable** (filosofía portable del proyecto):

- `saves/` se crea junto al `.exe` y ahí van `hh.us.bin` y `hh.us.bin.pak`.
- Si esa carpeta no es escribible (Program Files, USB de solo lectura) se usa la del usuario como
  antes; `HH_DATA_DIR=<ruta>` lo fuerza.
- Bug asociado en Linux: `get_executable_path()` devolvía `/proc/self/exe` **sin resolver**, así que
  `parent_path()` era `/proc/self` y la sonda de escritura fallaba → siempre caía al fallback. Se
  resuelve con `std::filesystem::canonical()`.
- `config.ini` se lee relativo (CWD = carpeta del exe): sin cambios.

Verificado en Linux: `pak_load path=<...>/build_dbg/saves/hh.us.bin.pak` y la carpeta `saves/` creada
junto al binario.
