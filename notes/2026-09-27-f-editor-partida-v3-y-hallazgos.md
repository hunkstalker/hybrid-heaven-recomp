# 2026-09-27 — Editor de partida v3 (sobre el `.pak`) y hallazgos

> Sesión larga (`menu-edicion-partida`). Continúa `notes/2026-09-27-e-editor-partida-plan.md`.
> Resume qué se hizo, qué funciona y qué queda abierto. Commit `77d2ad6`.

## 1. Vías probadas (y por qué la v3)

- **v1 (fichero)**: parser/escritor propio del `.pak`. Se descartó.
- **v2 (memoria)**: `func_801423C8` (lee slot + deserializa a globals) + `func_80142450` (serializa +
  escribe). **Edita globals del juego**, pero al **arrancar/cargar** el juego **los pisa**: las
  ediciones no sobreviven. Verificado en Windows: el editor mostraba lo guardado, pero `CONTINUAR`
  cargaba el save **sin cambios**.
- **v3 (ELEGIDA, commit `77d2ad6`)**: editar **directamente los bytes del SLOT del `.pak`** (el
  fichero que `CONTINUAR`/la cápsula leen). Autocontenido y verificable.

## 2. Layout real del slot (MEDIDO comparando `.pak` reales)

Contenedor `HHPK`: data a `0x1B` = cabecera `0x100` + **4 slots `0xD00`**. Checksum por slot en
`+0xCFC = sum(slot[0..0xCFB]) & 0xFF` (bytes `+0xCFD..0xCFF` a 0). **Offsets DENTRO del slot**:

| Campo | Offset | Tipo | Nota |
|---|---|---|---|
| PROGRESO | `+0x366` | u16 BE | `N*10+P` (ej. `0x0B`=1-1) |
| NIVEL | `+0x04B` | u8 | valor guardado; mostrado = +1 (por confirmar) |
| TÉCNICAS (aprendida) | `+0x09E` + id*3 | u8 flag | 86 entradas; `+0` = aprendida |
| ITEMS (cantidad) | `+0x1A0` + id | u8 | 45 items |
| ESTADO: offense | `+0x010` + part*2 | u16 BE | 6 partes |
| ESTADO: defense | `+0x01C` + part*2 | u16 BE | |
| ESTADO: hit | `+0x068` + part*2 | u16 BE | |
| ESTADO: damage | `+0x076` + part*2 | u16 BE | |

Verificado headless: escribir progreso/nivel/tech0/item0 y releer el `.pak` da los valores correctos
y el checksum cuadra (`[save-edit][test] antes/despues` + `cmp` del fichero).

## 3. Estado actual (lo que funciona)

- `GUARDAR PARTIDA` **escribe el `.pak` correctamente** (offsets + checksum). Verificado.
- UI del editor montada: `CARGAR PARTIDA < PARTIDA N >`, `GUARDAR PARTIDA < NUEVA PARTIDA / PARTIDA N >`,
  `PROGRESO < N-P >` (tabla real de escenas `D_80175490` leída en runtime), `NIVEL`, `HABILIDADES`
  (`< SIN CAMBIOS / TODO SÍ / TODO NO >` + toggles), `ESTADO` (CUERPO bajo CABEZA), `ITEMS`.
- **Repeat** de arriba/abajo/izquierda/derecha (retardo ~0.4 s + aceleración).
- **Cierre F11/SALIR rápido y limpio**: `_exit(0)` tras `recomp::start` + fix en el submódulo plume
  (no destruir el `VkDevice` en `release()`).

## 4. ABIERTO (para la próxima sesión)

1. **`CONTINUAR` no refleja lo editado** (Windows, 2026-09-27): aunque el `.pak` en disco cambia,
   `CONTINUAR` **no previsualiza** los cambios y **carga el save sin cambios**. Dos hipótesis:
   (a) el runtime/el juego **cachean el `.pak`** (se añadió `hh_pak_reload_from_disk` en el fork NMR
   `9b14604`, pero puede no bastar: hay que llamarlo **antes** de que `CONTINUAR` lea, o el juego lee
   otra copia); (b) el slot que `CONTINUAR` lee **no es el `+0x100`** que editamos (¿otro fichero/slot
   o cabecera distinta?).
   - **Pista**: los `.pak` reales (Windows/partida avanzada vs Linux/nueva) **sí** difieren en `+0x366`
     (progreso) y `+0x04B` (nivel), así que el layout es correcto. El problema es **de carga/relectura**.
2. **ESTADO en OFENSIVO/DEFENSIVO muestra 256** (Windows RUN 1): al leer `body_stat_of` sale 256 en
   todas las partes. Sospecha: **offset equivocado** (se está leyendo otro campo, p. ej. u16 donde el
   valor real es u8, o un bloque contiguo). El mantenedor dice que **deberían ser counts** (1), así que
   hay que **identificar los offsets reales** de las 4 estadísticas por parte (no fiarse del mapa del
   struct `0x8017DC40`, que puede no coincidir con el orden/empaquetado del slot).
3. **Numeración de PROGRESO**: ahora lista las **224 entradas con escena** de `D_80175490`
   (`idx*10+p`, mostrado = `idx`/`p`). Pero eso es "escenas", no "puntos de guardado usables"
   (`D_801DC930` curado = 56). **Decisión pendiente**: listar escenas vs. solo puntos de guardado.
   El mantenedor se ofreció a **mapear** a qué nivel corresponde cada numeración si logramos que
   cargue un punto.
4. **`NIVEL` +1**: aplicado (guardado = mostrado-1). Por confirmar en partida.
5. **Limpieza**: quedan restos de la v2 (argumentos `rdram`/`base_ctx` en `save::load/save` ya sin uso,
   `HH_SAVEEDIT_TEST` de prueba). Consolidar.

## 5. Instrumentación útil

- `HH_SAVEEDIT_TEST=1`: tras el primer frame de título, abre el `.pak`, escribe progreso/nivel/tech/item
  del slot 0, guarda, reabre e imprime `[save-edit][test] antes/despues` en `hh.log`. Sirve para validar
  la escritura sin mando.
- `HH_PAKLOG=1`: log del Controller Pak (reads/writes) en `hh_pak.log`.
- `HH_MENU_SCREEN=12`: fuerza la pantalla del editor (con `HH_PRESS_SEQ` para llegar al título).
