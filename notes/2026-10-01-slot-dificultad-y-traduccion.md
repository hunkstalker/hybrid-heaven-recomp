# Tareas pequeñas de menú: DATA EDIT, dificultad en el slot y traducción de las filas (2026-10-01)

> Sesión 2026-10-01 (6.ª). Rama **`menu-carga-guardado-partida`**. Cuatro tareas pequeñas pedidas por
> el mantenedor, **validadas por él en Windows** en el momento de escribir (salvo lo anotado).
> `[MEDIDO]` = comprobado por build/guard; `[INFERIDO]` = deducido del código.

## 1. Quitar `DATA EDIT` del menú de MODO COMBATE `[MEDIDO]`

**Motivo**: `EDITAR DATOS` no tiene sentido en el port (no hay pantalla de opciones propia). El
mantenedor decidió **quitarlo** (no deshabilitarlo).

**Implementación** (`src/subsystems/menu.cpp`, `build_tree`): se elimina la entrada
`make_item("DATA EDIT", Action::BattleModeDataEdit)` de la pantalla `ScreenId::BattleMode`. Al caer
de la lista, el cursor no la alcanza (no hace falta deshabilitarla). El resto no cambia: `B` dispara
el EXIT nativo (cursor 3) y vuelve al título.

## 2. Dificultad en la caja del slot (letra a la izquierda del nivel) `[MEDIDO]`

**Cómo lo hace el original**: la lista de partidas marca la dificultad con **una sola letra** a la
izquierda del número del nivel (`N`=NORMAL, `H`=HARD, `U`=ULTIMATE):

```
ÁREA          1-1
NIVEL      N   20
TIEMPO       0:00
```

**Decisión**: poner la **1.ª letra de la traducción** de la dificultad (para que funcione en todos los
idiomas). Con la palabra entera el diseño se rompía, así que se descarta por ahora.

**Dónde está el dato** `[MEDIDO del C]`: la dificultad de una partida vive en el byte **`+7` del
registro de cabecera/trailer** del slot, que es el campo `+B` del descriptor nativo = global
**`0x801BBC0D`** (`0=NORMAL`, `1=HARD`/`DIFÍCIL`, `2=ULTIMATE`/`DEFINITIVO`). Lo escribe el juego en
`func_80141268` (rama de guardado: `d[0x801C3B80+slot*8 + 0xB] = *(u8*)0x801BBC0D`). Hasta ahora el
port no lo leía ni lo escribía (el trailer `+6/+7` quedaba a 0).

**Implementación**:
- `src/subsystems/save_edit.cpp`:
  - Nuevo getter `hh::save::meta_difficulty(slot)` (lee el byte `+7` del trailer).
  - `update_save_header(...)` acepta `difficulty` y lo escribe en el trailer y en la cabecera del
    juego (rec `+7`, con checksum). `save(...)` lo propaga (nuevo parámetro en `include/hh/save_edit.h`).
  - `save_live(...)` lee la dificultad VIVA de `0x801BBC0D` al guardar desde la cápsula y la persiste
    en el slot (para que la UI la muestre también tras reiniciar). Log `DIFF=%d`.
- `src/subsystems/menu.cpp` (`rebuild_load_game`): la fila de nivel pasa de `LEVEL\t<n>` a
  `LEVEL\t<LETRA>\t<n>`. `difficulty_letter(d)` = `first_glyph(localized(NORMAL/HARD/ULTIMATE))`; el
  valor `d` lo da `meta_difficulty(i)`. `first_glyph` no parte UTF-8 (kana en ja).
- `src/hooks/menu_overlay.cpp` (dibujo de la fila): cada línea es `ETIQUETA\tVALOR` **o**
  `ETIQUETA\tLETRA\tVALOR`. La **LETRA va en columna FIJA** (5 celdas a la izquierda del borde
  derecho) y el **VALOR se alinea a la derecha** → la letra no se mueve con 2/3 dígitos y el `100` no
  se sale de la caja.

**Letras resultantes** (1.ª letra de la traducción): en `N/N/N`, es `N/D/D`, ca `N/D/D`, fr
`N/D/U`, de `N/S/U`, ja `ノ/ハ/ア`.

**Margen** `[INFERIDO]`: la etiqueta de la línea de nivel más larga es `NIVELL`/`NIVEAU` (6 glifos,
48 px) → termina en x=90; la letra fija está en x=102 → **12 px** de margen (con 2 cifras, 4 px entre
letra y número).

## 3. Traducir `AREA` / `LEVEL` / `TIME` de la caja del slot `[MEDIDO]`

**Motivo**: el mantenedor validó el slot y lo vio sin traducir: los rótulos seguían en inglés como
texto fijo (`"AREA\t"`, `"LEVEL\t"`, `"TIME\t"`).

**Implementación** (`src/subsystems/menu.cpp`): los rótulos pasan por `localized("AREA")`,
`localized("LEVEL")`, `localized("TIME")`. Nueva clave **`TIME`** en `assets/lang/*.txt`: es `TIEMPO`,
ca `TEMPS`, fr `TEMPS`, de `ZEIT`, ja `タイム` (en = identidad, sin fichero).

> ⚠️ `TIME` es una clave CORTA: por la unificación i18n entra también en la tabla de sustitución
> NATIVA (clave = inglés) y podría coincidir con texto in-game. Vigilar regresiones (el límite de
> longitud del registro lo acota). Igual aplica a `AREA`/`LEVEL` (ya existentes).

**Resultado**: `ÁREA/NIVEL/TIEMPO`, `ÀREA/NIVELL/TEMPS`, `ZONE/NIVEAU/TEMPS`, `BEREICH/LEVEL/ZEIT`,
`エリア/レベル/タイム`.

## 4. Corrección de la traducción FR de `ULTIMATE` + `NO DATA` a dos líneas `[MEDIDO]`

- **`ULTIMATE` (fr)**: estaba como `SUPRÊME` (= "supremo", no es lo mismo); corregido a **`ULTIME`**
  (`assets/lang/fr.txt`). es/ca se dejan como están (no hay traducción asentada; el mantenedor los
  conserva).
- **`NO DATA` (fr)**: `PAS DE DONNÉES` (14 glifos) tocaba/no cabía en la caja (112 px = 14 glifos).
  Se pasa a **`PAS DE\nDONNÉES`** (6/7). El dibujo CENTRADO del slot ahora soporta `\n`: centra cada
  línea y el bloque verticalmente, con **2 px de aire** entre líneas (`lh = 10`). Los demás idiomas
  caben en una línea (`NO DATA` 7, `SIN DATOS` 9, `SENSE DADES` 11, `KEINE DATEN` 11, `データナシ` 5).

> Nota: se probó a subir el aire también en las **filas** del slot (`AREA/LEVEL/TIME`) y el mantenedor
> lo rechazó (solo quería la separación en el `NO DATA` del francés). Queda revertido: `line=12`,
> `kTextDy=4`.

## 5. Validación

- **Build Linux**: OK en cada paso. Guard `python3 tools/text/check_translations.py`: OK.
- **Windows (mantenedor)**: tareas validadas en la sesión (tras recompilar/copiar `assets/lang/`).
  `DATA EDIT` fuera; letra de dificultad visible y en columna fija; rótulos traducidos; `PAS DE
  DONNÉES` a 2 líneas.

## Ficheros tocados

- `src/subsystems/menu.cpp` (DATA EDIT fuera, `difficulty_letter`/`first_glyph`, fila del slot,
  rótulos localizados), `src/hooks/menu_overlay.cpp` (columna fija de la letra, centrado con `\n`).
- `src/subsystems/save_edit.cpp` + `include/hh/save_edit.h` (`meta_difficulty`, `difficulty` en
  `update_save_header`/`save`, `save_live`).
- `assets/lang/{es,ca,fr,de,ja}.txt` (`TIME`; `ULTIMATE` fr; `NO DATA` fr a 2 líneas).

## Referencias

- Formato del slot/cabecera: `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md` §4/§6.
- UI del DATA LOAD: `notes/2026-09-30-data-load-maqueta-1a1.md`.
- i18n (fuente única, clave = inglés): `notes/2026-10-01-i18n-unificar-traducciones-plan.md`, ADR 0014.
