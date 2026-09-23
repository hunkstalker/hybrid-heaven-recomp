# B — Localización de la fuente (en curso)

> Sesión 2026-09-23. Objetivo: poner acentos (ñ, tildes, ¿ ¡) al texto del juego, que en USA no
> existen (ver `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`).

## Herramientas nuevas

- **`HH_DUMP_RDRAM_AT=<seg>`** (port, `src/platform/rt64_render_context.cpp`): vuelca 8 MB de RDRAM
  una vez a `hh_rdram_dump.bin` (word-swapped; bswap32 al analizar). Sirve para cazar assets en
  memoria. Ejemplo validado: dump a los 25 s.

## Verificado

- La tabla de glifos especiales USA está en `0x8001D4B0` (flat) y el **módulo 23 ya sale traducido en
  RDRAM** (`NUEVA PARTIDA`, `CONTINUAR`, `MODO LUCHA`) — confirma que A1 funciona en memoria real.
- El `rdram` del port se obtiene fiablemente como 1.er arg de `hh_trans_load` (para gdb).

## Intento de localizar la fuente (renderer) vía watchpoint

- `rwatch` sobre el string del menú (`rdram + 0x1CEBC4`): dispara en `store_guest`/`hh_trans_load`
  (loader) y en `func_8001F160/8001F204` (un *memclear*), pero **no se aisló el renderer**.
- Motivo: en x86 los watchpoints de gdb no son de solo-lectura (disparan en escritura), así que se
  confunden con nuestras propias escrituras del loader; y bajo gdb el juego va lento.

## Siguientes vías (más prometedoras)

1. **Estática**: localizar la rutina de dibujo de texto a partir de la tabla de glifos real (no la de
   `0x8001D4B0`, que resultó ser de otro tipo). Buscar una función que lea bytes y haga lookups de
   glifo. Ayuda: `func_8001F204` (llamada por el loop) es candidata a parsear texto/formato.
2. **Oráculo con emulador** (`docs/workflows.md` §6: `emu_ref.sh`, write-breakpoints): capturar la
   textura de fuente desde el emulador, donde sí hay control de DMA/TMEM.
3. **Enfoque distinto**: en vez de reusar la fuente del juego, **dibujar acentos** con un atlas
   propio superpuesto (enlaza con A2/overlay propio) — evita depender de la fuente USA, pero cambia
   el enfoque de A2.

## Recomendación de secuencia

Dado que localizar la fuente USA es costoso y abierto, y que A1 ya da el cambio de idioma, lo más
eficiente puede ser:
- **A2 con rótulos ASCII** ahora (menú AJUSTES con sección IDIOMA: `ESPANOL`, `CATALA`, `FRANCAIS`…),
  y **acentos cuando B esté resuelto**; o
- **A2 con overlay propio** (fuente propia) que sí cubre acentos ya, difiriendo el menú del juego.

Decidir antes de invertir más en localizar la fuente USA.
