# FASE 0 — Menú propio de cargar/guardar (trazado del file-select + prueba del `.pak` a N slots)

> Evidencia de la **Fase 0** del plan `notes/2026-09-29-menu-cargar-guardar-partida-plan.md`.
> Rama `menu-carga-guardado-partida`. Todo lo de abajo es **`[MEDIDO]`** en esta sesión salvo lo
> marcado `[INFERIDO]`. Método: desensamblado del C recompilado (`build/recomp/asm/file_008.s`,
> `file_024.s` — el C es exacto del pipeline ELF/splat) + ejecución headless del port con un hook
> temporal (ya retirado) que llama a `func_801423C8(slot)` y lee `glob[+4]`.

## 1. Trazado del file-select DATA LOAD (`func_8013E7C0` / `func_8013E850`) `[MEDIDO]`

**Cadena (módulo de título, file_024):**
`func_801C3CDC` (monta runtime, `func_80152240`) → `func_801C3D50` (setup: llama **`func_8013E7C0`** y
registra el update) → `func_801C3D84` (update wrapper: llama **`func_8013E850`**).

**`func_8013E7C0` (0x8013E7C0, setup LOAD — residente, file_008):**
- Inicializa el estado compartido (ver §2): `D_801BEBCC=0`, `D_801BEC02=1`, `D_801BEC03=0`,
  `D_801BEC04=0`, `D_801BEC05=0`.
- `func_8013E700(D_801BEB80)` (limpia el modelo de filas), `func_80002364(0xC000C0C,10,2,0)`,
  `func_800179B0(D_80180458)`, **`func_801426B0`** (setup de pantalla: textos + caja) y
  `func_8014307C(0, 0xFF, D_801BEB84)` (pinta la fila 0).
- **`func_801426B0`** (setup LOAD) compone: `func_8001B204(7, 0x7D0, 0x1C, D_8018F16C)` (título
  `DATA LOAD`), `func_8001B204(0xB, 0x26, 0x30, D_8018F184)` (`CONTROLLER PAK`) y
  `func_8001A804(...)` (caja). El setup SAVE análogo es **`func_8013EA94`** + **`func_80142778`**
  (mismas posiciones, otras cadenas `D_8018F1BC/…`). **NO hay un "draw" monolítico**: título/caja/líneas
  se registran por `func_8001B204`/`func_8001A804` (los mismos que ya filtra `hh_entry_register_hook`).

**`func_8013E850` (0x8013E850, update por frame):** máquina de estados con jump table en
**`0x8018EF0C`** sobre `D_801BEBCC` (0..5):
- Primero: `func_800178E8()` — si devuelve 0, no hace nada (pantalla no activa).
- Si `D_801BEC03==1`: animación/scroll de fila (`func_80142FC4` + `func_80143B5C`), vuelve y limpia.
- **state 0** (espera de arranque del pak, flag `D_801BBF42`): si `D_801BBF42!=0`, `func_8014150C(1,
  D_801BEB84)` (lee la cabecera del slot seleccionado, canal 0) + `func_8014307C(0, v0&0xFF,
  D_801BEB84)` (pinta la fila) y pasa a **state 2**; si `D_801BBF42==2` → **state 1** (cancelar).
- **state 2** (lista interactiva): si el mando tiene `A|Z|Start` (`0x8000|0x2000|0x1000`, leído en
  `0x80089474+4`), `func_8014115C()` decide si el slot admite la operación: 0 → `D_801BEBCC=3` +
  mensaje `D_80180598`; !=0 → mensaje `D_80180668`. Luego `func_80140E88(0,4,D_801BEB84)` (navegación
  con D-pad ↑/↓ → mueve **cursor `D_801BEC05`** y **top `D_801BEC04`**, y activa `D_801BEC03`) y
  `func_80142B28(0, D_801BEC04)` (dibuja el cursor/caja).
- **state 3**: espera el fin del diálogo (`D_801BBF42`): 0 → **state 4**; 2 → **state 1**.
- **state 4**: **`func_801411D0()`** → ejecuta la operación real:
  - según `D_801BEC02` (1/2 = página/región) y `D_801BEC05` (slot), llama a `func_801415C4` que
    despacha a **`func_801423C8(0, slot)`** (cargar) o `func_80142450(0, slot)` (guardar).
  - retorno 0 → **state 5** + mensaje `D_801806E4`; !=0 → **state 1** + mensaje `D_8018071C`.
- **state 1** → `func_800023A8(0)`; **`return 2` = CANCELAR/atrás**.
- **state 5** → `func_800023A8(0)`; **`return 1` = ÉXITO**.

**Salida (`func_801C3D84`, file_024):** si `ret == 0` no hace nada; si `ret != 0`,
`func_80142570()` + `func_800179B0(0)`, y:
- `ret == 1` (éxito) → `func_801C11BC(0xA)` + `func_800058DC(obj, 0x801C3E24)` (continuar carga).
- `ret == 2` (cancelar) → `func_8012FE50(0x17, 0x73, 1, 1, 0)` + `func_800058DC(obj, 0x801C40EC)`.

> ⚠️ El plan (§1) sitúa el estado en `0x801C3…` (`-0x13fd`/`-0x1434`). **Medido: es incorrecto** —
> el estado/cursor del file-select viven en el bloque **`0x801BEBxx/0x801BECxx`** (residente, §2).

## 2. Globals del file-select `[MEDIDO]` (base `0x801BEB80`, residente)

| Global | Rol medido |
|---|---|
| `0x801BEBCC` `D_801BEBCC` | **estado** 0..5 (jump table `0x8018EF0C`) |
| `0x801BEC05` `D_801BEC05` | **cursor** (fila seleccionada) |
| `0x801BEC04` `D_801BEC04` | **top/scroll** de la lista (0/1 = página) |
| `0x801BEC03` `D_801BEC03` | sub-estado de **transición/scroll** de fila |
| `0x801BEC02` `D_801BEC02` | **página/región** de save (1/2), no load-vs-save |
| `0x801BEB80` `D_801BEB80` | **modelo de filas** (registros de 8 B; +4.. flags y datos) |
| `0x801BEB84` `D_801BEB84` | fila 0 del modelo (`D_801BEB80+4`) |
| `0x801BEC00/01`, `D_801BEBFF` | 2.º juego cursor/top/flag (misma familia de pantallas) |
| `0x801BBF42` | flag auxiliar de arranque/mensaje (lo espera state 0/3) |

El modelo de filas se rellena desde la **cabecera `0x100`** vía `func_8014150C`→`func_801422E4`
(leer) y `func_80141568`→`func_80142350` (escribir); `func_80141268` compone la fila (AREA/LEVEL/TIME)
y `func_8014307C` la pinta. Las mismas funciones sirven a varias pantallas (LOAD/SAVE/EDIT); el update
de CARGAR es `func_8013E850` y el de GUARDAR (cápsula) es `func_8013EB2C` (setup `func_8013EA94`).

**Implicación para la estrategia A (Fase 3):** se envuelve `func_8013E850` (como el menú de título),
se **mutea la lectura de mando** que consume (`0x80089474+4` para A/Z/Start y el D-pad en
`func_80140E88`) y se **oculta** el texto/caja nativos (ya hay `hh_entry_register_hook` +
`suppress_native`). Para confirmar un slot: fijar `D_801BEC05`/`D_801BEC04` + inyectar A (o, más
directo, llamar a `func_801423C8(0, slot)` y replicar la salida `ret=1`).

## 3. Captura del DATA LOAD nativo (diseño 1:1) `[MEDIDO]`

Referencia existente (nativo, no overlay): `work/gameplay screenshots/CONTINUAR/Captura de pantalla
2026-09-26 033740.png`. Layout observado (fondo = escena attract, velo oscuro):
- Título **`DATA LOAD`** centrado arriba; subtítulo **`CONTROLLER PAK`** a la izquierda de la lista.
- **Una caja por slot presente** (lista vertical), cada una con tres filas de ancho fijo:
  `AREA  N-P` · `LEVEL  N  <n>` · `TIME  M:SS` (valores alineados a la derecha).
- **Caja de mensaje inferior**: `Select play data to be loaded.`
- **Bug conocido**: borde verde del cuadro de selección descolgado a `y≈0` (widescreen/overscan).

La captura pareada **F7** existe (`src/hooks/dl_snap.cpp`: `hh_cap_N.log` + imagen). Mis runs headless
(llvmpipe) **no llegaron** al menú de título en tiempo útil, así que no produje una F7 nueva; el
mantenedor puede tomarla en Windows (CONTINUAR con ≥2 partidas) si quiere las identidades 2D exactas.
La captura existente basta para el 1:1 (posiciones y contenido).

## 4. Prueba del `.pak` ampliado a N slots `[MEDIDO]`

Método: generar `.pak` con `HHPK` + registro de fichero rehecho (`size` = `0x100 + N*0xD00`) y datos
extendidos; cada slot lleva su campo de escena `0x564` (u16 LE) = `0x100+slot` y su checksum `0xCFC`.
Hook temporal (retirado) llamó a `func_801423C8(0, slot)` y volcó `glob 0x801BBBF4` (`[+4]`).

| `.pak` | resultado por slot (`ret`/`glob[+4]`) |
|---|---|
| **N=8** (`0x6900`) | slots 0..7 → `ret=0`, `glob=0x100+slot` (260..263) → **carga real**. Slot 8 (`off==size`) → `ret=0`, `glob=0` (vacío). Slots 9,10 → `ret=9`. |
| **N=12** (`0x9D00`) | slots 0..8 → `ret=0`/`glob=260..264`. Slot 9 → `ret=14` (`glob` sin cambios = lectura parcial). Slots 10..12 → `ret=9`. |

- **`func_801423C8(slot)` carga correctamente slots > 3** (4, 5, 6, 7…) cuando el fichero del PFS es
  lo bastante grande. Offset leído = `0x100 + slot*0xD00`, tamaño `0xD00` (confirmado en `hh_pak.log`).
- **El PFS del runtime RECORTA a `PAK_SIZE = 0x8000`** (`lib/N64ModernRuntime/librecomp/src/pak.cpp:42`
  y `pak_load` 191-193: `if (f.size > PAK_SIZE) f.size = PAK_SIZE;`). Por eso con N=12 el slot 9+
  falla pese a que el registro del `.pak` dice `0x9D00`. `osPfsAllocateFile` (pak.cpp:317) también usa
  `PAK_SIZE`, así que la creación del fichero por el juego tope a ~9 slots.
- **Tope de la cabecera `0x100`**: registros `0x10 + slot*8` → solo caben **30 slots**
  (`0x10 + 30*8 = 0x100`).

### Conclusión: fijar N (recomendación)

- **Con el runtime actual, N máx = 9** (`0x100 + 9*0xD00 = 0x7600 ≤ 0x8000`). El plan pide 32/64 →
  **hace falta subir `PAK_SIZE` en el fork NMR** (`pak.cpp`), p. ej. `0x20000` (→ hasta 39 slots) o
  `0x40000` (→ hasta 78). No toqué el fork (regla: sin tocar forks/push).
- **N recomendado = 30** para el primer corte: cabe justo en la cabecera actual (30 registros) y con
  `PAK_SIZE=0x20000` sobra (`0x100 + 30*0xD00 = 0x18700`). **N=64 exige además rediseñar los
  metadatos** (la cabecera `0x100` no da para más de 30 registros): p. ej. leer AREA/LEVEL/TIEMPO del
  propio slot (autodescriptivo) o una zona de metadatos aparte.

## 5. Fase 1 propuesta (siguiente sesión)

1. **Fork NMR**: subir `PAK_SIZE` (y revisar `PAK_MAX_FILES`/`osPfsNumFiles`/`FreeBlocks`) en
   `lib/N64ModernRuntime/librecomp/src/pak.cpp`; commit en el fork (sin push). Validar con el mismo
   test de boot que slots 0..N-1 cargan y `>N` falla.
2. **`hh::save` a N configurable**: `kSlots` de 4 a N=30; `load()` acepta/tolera `0x100 + N*0xD00`
   (pad/trunc a N); `flush/save/delete/restore` iteran N; `update_save_header` a N registros.
3. **Metadatos por slot** para la UI (AREA-LEVEL/nivel/tiempo): desde la cabecera `0x100` (ya lo hace
   `update_save_header`) + **fecha del fichero**. Nombre `savegame_slot<N>` (1-based).
4. Documentar en `docs/` sólo lo que se convierta en contrato (formato `.pak`).

**Criterio de validación Windows (Fase 1):** un `.pak` de 30 slots se abre/edita/guarda; `CONTINUAR`
nativo (aún sin UI propia) lista y **carga** el slot > 3 correcto (texto y mapa).
