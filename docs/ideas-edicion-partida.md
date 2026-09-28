# Ideas — Edición de partida y sistema de guardado

> **Documento de ideas (no vinculante).** Recoge lo hablado con el mantenedor el 2026-09-27 sobre
> `EDICIÓN DE PARTIDA` y el rediseño del sistema de guardado en PC. **No** es un plan cerrado ni una
> decisión; sirve para no perder las ideas. El estado real del editor implementado está en
> `../notes/2026-09-27-e-editor-partida-plan.md`, `../TODO.md` y `../RETOMAR.md`.

## 0. Contexto técnico medido (para que las ideas sean aterrizables)

- El guardado en PC es un **`.pak` propio del port** (`HHPK`): `magic(4) + count(4) + 1 fichero (19 B)
  + data`, y `data = 0x3500 = cabecera 0x100 + 4 slots × 0xD00`. **El número de slots lo gobierna el
  port**, no la ROM (el contenedor es nuestro).
- El juego cree que existen **2 "controller paks"** (canal 0 = jugador 1, canal 1 = jugador 2). El
  runtime del port **solo reporta el canal 0**; los canales 1-3 devuelven `osPfsInitPak = 5`. De ahí
  que `DATA EDIT` copie "al pak 2", que **nunca existirá**.
- Funciones útiles ya localizadas: `func_801423C8(channel, slot)` lee un slot + deserializa a los
  globals; `func_80142450(channel, slot)` serializa los globals y escribe el slot; file-select nativo
  (`func_8013E700/E7C0/E850/EA94/EB2C`) con 4 slots y cursor `0x801BBF42`; cabecera con 4 registros de
  metadatos desde `0x10` (`func_801419A4`/`func_80141BD0`/`func_80141A74`).

## 1. `DATA EDITOR` del juego no tiene sentido en PC

El `DATA EDIT` original está pensado para **copiar partidas entre dos controller paks** (jugador
1 ↔ jugador 2). En PC no hay segunda consola ni segundo pak, y no habrá juego a 2 jugadores local.
→ Se **reemplaza** por utilidades propias (ver §3, §4), no se replica tal cual.

## 2. Slots "infinitos" (o muchos más de 4)

- Idea: **ampliar el número de slots** más allá de 4, rediseñando el sistema para hacerlo "moderno".
- Como el `.pak` es nuestro, pasar de 4 a `N` (p. ej. 12/20/**ilimitado**) es viable; el límite es de
  diseño del contenedor, no técnico.
- A decidir más adelante:
  - **N grande con scroll** (reutiliza casi todo el código actual) **vs. ilimitado** (el `.pak` crece o
    hay varios ficheros/carpeta).
  - **Compatibilidad** con `.pak` viejos de 4 slots (cabecera con "nº de slots" + migración) — recomendable.
  - Límites del runtime: `PAK_SIZE`/`PAK_MAX_FILES` (`0x8000`/16) y lo que reportan
    `osPfsFileState`/`osPfsFreeBlocks`.
  - La **UI nativa de slots** (file-select) asume 4; los slots extra se mostrarán en **nuestro menú**
    (ver §3), no en el file-select nativo.

## 3. Rediseño de la UI de partidas guardadas (estilo moderno)

- Mostrar la **lista de partidas guardadas** y, **arriba del todo, un slot/opción `NUEVO`**
  (patrón estándar actual).
- Como la UI la dibuja el port, se puede **imitar el estilo** del original pero con lista + `NUEVO`.
- Implica **recrear el file-select con nuestro menú** (patrón ya usado en `MODO COMBATE`), no pilotar
  el nativo.
- Posible extra (a valorar): mostrar **metadatos** por slot (progreso `N-P`, nivel, fecha...); sabemos
  leer un slot, así que es factible.

## 4. Clonar slot sin interfaz (copia A→A)

- Para **copiar** un slot **no** hace falta una pantalla: es un **menú inútil**.
- Basta una **opción simple "CLONAR SLOT"** que genere la copia en el **último slot** disponible.

## 5. `EDITAR DATOS` → ordenar slots

- `EDITAR DATOS` **deja de copiar** entre paks y pasa a **ordenar/organizar los slots** del mismo pak.
- Ideas de interacción (a decidir): subir/bajar un slot, "mover a…", borrar, marcar favorito...
  Encaja con la lista de §3.

## 6. Estilo y textos

- Se **imita el estilo** del original; los **textos** (etiquetas/traducciones) ya se verán cómo
  (añadir a `kMenuTr`, endónimos, etc.). **Pronto** para decidirlo; no bloquea nada.

## 7. Pendiente de decidir (cuando se aborde)

- Alcance/prioridad: ¿primero slots (N + lista con `NUEVO`) o primero `DATA EDIT` → ordenar?
- "Infinitos": ¿N grande con scroll o ilimitado (multi-fichero)?
- Comportamiento de `NUEVO`: ¿crear en hueco libre o al final?
- Operaciones de ordenación exactas y su UI.
- ¿Migrar/compatibilizar el `.pak` de 4 slots?

## 8. Relación con lo ya implementado

- La **v1 fichereo** y la **v2 en memoria** del editor (commit `6c917b0`, rama `menu-edicion-partida`)
  atacan **editar un slot** (progreso/nivel/habilidades/body/items) y `GUARDAR`. Estas ideas son el
  **siguiente nivel** (gestión de slots y UI de partidas), y reutilizan las mismas piezas
  (`func_801423C8`/`func_80142450`, lectura de slots, menú propio).
