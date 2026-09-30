# RETOMAR — handoff (2026-09-30)

> Handoff para la próxima sesión. **Rama de trabajo actual: `menu-carga-guardado-partida`**
> (creada desde `menu-edicion-partida` @ `9fbe2e8`; nada pusheado; `main` = v0.5.0). Reglas:
> `AGENTS.md`. (El trabajo del editor/niveles vive en `menu-edicion-partida`.)
>
> ## 🎯 TAREA ACTUAL: recrear la UI del `DATA LOAD` a 1:1 con el original
>
> ### Hecho (2026-09-30, 2ª sesión)
> - **CORREGIDO**: al pulsar **F8** aparecía el `BATTLE DATA LOAD` (MODO VS). Causa raíz `[MEDIDO]`:
>   el recompositor de F8 en `hh_file_select_hook` (`src/hooks/sections.cpp`) llamaba a
>   `func_80142840`, que compone la tabla `ＢＡＴＴＬＥ　ＤＡＴＡ　ＬＯＡＤ` + `1P/2P CONTROLLER` (no el
>   mensaje `Select play data…`, como decía el comentario). **Fix aplicado**: se deja solo
>   `func_801426B0` (setup real del `DATA LOAD`). **Validado en Windows por el mantenedor** ("mucho
>   mejor": ya sale el `DATA LOAD` de una columna). **Sin commitear.**
> - El enganche de CONTINUAR en sí **es correcto** (llamada directa `func_800058DC(obj, 0x801C3CDC)`,
>   `7dacb58`): ruta a `func_801C3D50/801C3D84` → `DATA LOAD` de una columna.
> - Evidencia y detalles: **`notes/2026-09-30-continuar-enganche-y-ocultado.md`**.
>
> ### Hecho (2026-09-30, 3.ª sesión)
> - **GEOMETRÍA 1:1 del `DATA LOAD` RECREADA** en el overlay (`menu_overlay.cpp`, rama `is_load_game`):
>   título (top y=28), `CONTROLLER PAK` (x=38, y=53), cajas de partida (x=37, w=112, h=37, paso 46,
>   texto +5/+4, paso de línea 12), caja de mensaje (x=29, y=171, w=262, h=51) y se **quita la flecha
>   de cursor** (el nativo marca la selección solo con el borde verde). Validado headless **pareado**
>   contra el render nativo del propio port (`work/gameplay screenshots/menu-carga/LOAD DATA
>   Continuar.png`): **Δ < 1 px** en todos los bordes. Evidencia:
>   **`notes/2026-09-30-data-load-maqueta-1a1.md`**. **Sin commitear.**
>
> - **AJUSTE FINO del mensaje + subtítulo (misma sesión, 3.ª)**: el mensaje salía con **espacios más
>   anchos** que el nativo; se ha **cableado el avance del motor** (`face_glyph_advance`): color4
>   **espacio=4**, `f i j l r t`=6. Medido pareado: el mensaje ahora **calca el nativo glifo a glifo**.
>   Además, el **punto final `.`** se dibujaba a mano como 2x2 (parecía un `·` grueso); ahora es un
>   **1x1 en el baseline** (Δ<0.3 px del nativo). Por decisión del mantenedor, el subtítulo
>   **`CONTROLLER PAK` → `MEMORY SLOTS`** (traducido: `RANURAS DE MEMORIA/MEMORY SLOTS/RANURES DE
>   MEMÒRIA/EMPLACEMENTS MÉMOIRE/SPEICHERPLÄTZE/メモリースロット`), en la misma posición 1:1.
>   `docs/fonts.md` §6 actualizado. **Además (misma sesión)**: **colores** medidos del nativo (el borde
>   del mensaje NO es blanco puro ~170; bordes de slot gris ~90; verde `19,255,13`; rellenos oscuros) y
>   **marco exterior que agrupa los slots** (rect del setup nativo `func_801426B0` x=32,y=66,w=122,
>   h=92, **expandido 1 px por lado** → x=31,y=65,w=124,h=94), **encima de él** van las cajas de slot.
>   Slot vacío = **`NO DATA` centrado y en blanco** (`SIN DATOS/SENSE DADES/…`). También: **sombra del
>   glifo nivel 2 = GRIS** (antes negro; el gancho de la `l` del mensaje salía mal). **Sin commitear.**
>
> ### PENDIENTE (lo que retoma la próxima sesión)
> 1. **Validar en Windows** (F7) la maqueta nueva: CONTINUAR → `LoadGame` debe calcar el nativo.
> 2. **Contenido/alineado de las filas**: el nativo (US) usa `AREA/LEVEL/TIME` con el valor **alineado a
>    la derecha**; el overlay usa `ÁREA/NIVEL/TIEMPO` y valor pegado a la etiqueta. No es geometría;
>    confirmar antes de cambiarlo (AGENTS: no inventar UI).
>
> ### Otros pendientes
> - **Ocultado sin F8**: aún se cuela el prompt nativo `Please connect Controller Pak…` por detrás de
>   nuestras cajas (otra vía de dibujo, no pasa por `func_8001B204`; sin localizar).
> - **Commit** del fix de F8 (un tema = un commit) cuando el mantenedor lo pida.
>
> ### Contexto
> - **DEPENDENCIA DE FORK:** la rama necesita 2 commits del fork `N64ModernRuntime`: `9b14604`
>   `hh_pak_reload_from_disk()` y `3523bf3` `PAK_SIZE=0x40000` (publicado). Gitlink bumpeado en
>   `dbb209a`; port **sin pushear**. ADR: `docs/adr/0013-pfs-virtual-ampliado-y-pak-de-n-slots.md`.
> - **Plan de fondo**: "Menú propio de CARGAR/GUARDAR partida (un `.pak` con N=74 slots: 45 partidas +
>   29 plantillas, trailer de metadatos)": **`notes/2026-09-29-menu-cargar-guardar-partida-plan.md`**.
>   Estado UI Fase 2/3: **`notes/2026-09-29-menu-cargar-guardar-fase2-ui.md`**. Tipografías:
>   **`notes/2026-09-30-tipografias-data-load-hallazgos.md`**.
> - **ESTRATEGIA DE MERGE**: `menu-carga-guardado-partida` es **DERIVADA** → **no** va a `main`. Al
>   terminar: merge a **`menu-edicion-partida`**; luego → **`main`**.
>
> **Puntos de guardado del mantenedor**: `notes/reference/saveedit/PUNTOS_DE_GUARDADO.md`.
>
> **Puntos de guardado aportados por el mantenedor**: registro vivo en
> **`notes/reference/saveedit/PUNTOS_DE_GUARDADO.md`** (cobertura por área + cómo registrar los
> nuevos). El mantenedor puede decir en cualquier momento que ha guardado slots nuevos; ahí se anotan.
>
> **Contexto del mapeo de Áreas-Partes**: `notes/2026-09-29-editor-area-parte-plan.md` (§1 sigue siendo
> el material de partida original; el estado real está al principio de esa nota). Pendientes vivos:
> (a) **validar en Windows** `EXTRAS > IR A ÁREA` + `DEBUG NIVELES`; (b) **diseñar/implementar
> "mover mi partida a una Área-Parte"** (§6bis de la nota: plantilla de zona + datos del jugador);
> (c) **"volver al menú desde el gameplay"** (el idx 7 daba la intro pero hoy crashea: buscar vía).
> Antes del formato del save, leer
> `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md` y
> `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.

---

## 1. TAREA PRINCIPAL — nivel (Área-Parte) del save y carga con `CONTINUAR`

> **La sesión nueva debe EMPEZAR creando un item en `TODO.md` y una planificación/plan de la tarea**
> (pasos numerados + criterio de validación en Windows), y trabajar sobre ese plan. Lo de abajo es el
> material de partida, no el plan hecho.

### Objetivo

Que `EDICIÓN DE PARTIDA` → `PROGRESO` (Área-Parte) **determine de verdad** el nivel que el juego carga
al darle a **`CONTINUAR`**, y que la lista de niveles mostrada sea la **real** (ahora mismo sale
`1-0`…`1-9`, imposible: el área 1 no tiene 9 partes).

### Lo que YA funciona `[VALIDADO en Windows]`

- Editar el slot del `.pak` y **cargar** ya **no cuelga** (`hh::save::save()` llama a
  `hh_pak_reload_from_disk()` del fork NMR `9b14604`; ver nota §9).
- `PROGRESO` = **slot `+0x366`** (u16 **BE**) = global **`[0x801BBBF0+4]`** (ver nota §5).
- Al editar `PROGRESO` (p. ej. `3-1`) y cargar, **sí cambia el TEXTO del área** en la pantalla negra de
  entrada: ese texto sale de la **cabecera** (registro `0x10 + slot*8`: `+1` AREA N, `+2` AREA P).
- **PERO** el mapa/Área-Parte que se carga **sigue siendo el del save**, no el editado.

### El problema / por qué

El **texto** del área usa la cabecera, pero el **mapa** cargado usa otro campo. Hipótesis a confirmar:
- Candidato A: slot **`+0x364`** = `[0x801BBBF0+2]` (el serializer lo escribe junto a `0x366`).
- Candidato B: bloque de **100 B** `0x300..0x363` (copiado del global **`0x8008DC20`** en el save).
- Candidato C: el **struct de personaje** (`0x000..0x09D`).
Determinar cuál lee el flujo de **CARGAR**: `func_801411D0` → `func_801423C8` → `func_80141D08`
(copia el buffer a los globals) → **¿qué global/escena decide el mapa?**

### Niveles Área-Parte (primera cosa a resolver)

El modelo actual es **incorrecto**: `hh::save::valid_points_by_level` (`src/subsystems/save_edit.cpp:595`)
lee la tabla de escenas runtime **`D_80175490`** como **30 niveles × 10 puntos** (`valor = idx*10+punto`)
y de ahí salen `1-0..1-9` en el área 1. **Hay que determinar la enumeración real de Área-Parte**:
- Volcar `D_80175490` en runtime e interpretarla (¿es "sala por área", no "punto por nivel"?).
- Buscar la **tabla de nombres/áreas** que usa el texto del área al cargar (de ahí sale el "área 3").
- Contrastar con el juego real: qué Áreas-Partes **existen** y cómo se numeran (¿N-P? ¿índice 1D?).

### Plan sugerido

1. **Niveles**: identificar la tabla/estructura real de Área-Parte y reescribir `progress_options()` /
   `progress_value_at()` / `progress_index_of()` (`src/subsystems/menu.cpp:332`) para listar solo las
   válidas.
2. **Campo de carga**: trazar quién lee el Área-Parte en el flujo de `CONTINUAR` (arriba) y **contrastar
   con un save real**. Método rápido y fiable: **oráculo/diff** — en el juego, guarda en dos Áreas-Partes
   distintas y compara los `.pak` (qué offsets cambian con la zona). Ese(s) campo(s) es el que el editor
   debe escribir para que cargue donde toca.
3. **Cablear** en `hh::save`: escribir el campo correcto (además de la cabecera) al fijar `PROGRESO`, y
   validar en Windows: editar → `CONTINUAR` → carga en la Área-Parte elegida (texto **y** mapa).
4. `hh::save::save()`: al guardar, mantener cabecera y campo de carga **coherentes**.

### Datos y direcciones `[MEDIDO]` (detalle en la nota)

- Slot: `0x000..0x09D` struct personaje (**u16 LE** en fichero), `0x09E+id*3` técnicas (86),
  `0x1A0+id` items (45), `0x1CD..0x1E6` party, `0x300..0x363` copia 100 B (`0x8008DC20`),
  **`0x364+` bloque u16 de progreso/escena (BE)**; `0x364=[0x801BBBF0+2]`, **`0x366`=PROGRESO**.
- Cabecera `0x100`: magic `"HYBRID HEAVEN"` @`0x00`, checksum @`0xFF` = `sum(0..0xFE)`, registros
  `0x10+i*8`: `+0` presente, `+1` AREA N, `+2` AREA P, `+3` LEVEL, `+4..5` TIME.
- Funciones del juego (`file_024`): `0x801423C8` cargar slot, `0x80142450` guardar slot,
  `0x801422E4`/`0x80142350` leer/escribir cabecera, `0x80141268` flujo GUARDAR, `0x801411D0` flujo
  CARGAR, `0x80141F28`/`0x80141D08` serializar/deserializar `0xD00`.
- Guard de prueba: `work/debug/cac/saves_windows/hh.us.bin.pak` (capítulo **1-1** real).
- Verificación: `HH_SAVEEDIT_TEST=1` (escribe/relee y loguea `[save-edit][test]`).

---

## 2. Estado consolidado de la tanda anterior (2026-09-28, todo VALIDADO en Windows)

Commits en `menu-edicion-partida` (sin push): `cdcbd7a` centrar GRÁFICOS/CONTROLES · `a54f697` MODO
HEAVEN global + ventaja · `07b051a`/`b5136dc` docs/tools · `ad56dfc`/`feb1650` daño de campo ·
`f1ce2fb` stepper ANTIALIASING · `64c50db` VENTAJA + PODER/RESISTENCIA ∞ · `8ba43d2`/`289093e` docs ·
`ac9b6e7` arreglos de UI. **Árbol limpio.**

- **MODO HEAVEN** (EXTRAS, `[extras].heaven`, persistente): al cargar partida aplica ATRIBUTOS/ESTADO 99
  + 86 habilidades; en runtime invulnerabilidad (combate `func_80232D08` y campo `func_80379F04`→scratch
  `0x80388A68`), items no consumibles (`func_8013D520`) y **PODER/RESISTENCIA infinitos**. **No** incluye
  VENTAJA.
- **VENTAJA** (`[extras].advantage`): fuerza `0x801BCC24=2` (back attack). Independiente de HEAVEN.
- **PODER ∞ / RESISTENCIA ∞** (`[extras].infinite_power`/`.infinite_stamina`): `hh_battle_frame_hook`
  pinnea `actual=max` cada frame (PODER `0x801BC042←0x801BC040`, RESIS. `0x801BC046←0x801BC044`); O(1),
  no-op fuera de combate. El `∞` (U+221E) se dibuja vectorial (13×5, con sombra).
- **UI**: ANTIALIASING como stepper `< x2 >` (`Entry::stepper`); sombra de kana (copia negra +1,+1 en el
  overlay porque la fuente no la trae y el dakuten va en la col. 7); cedilla `Ç` dibujada delante de la
  `C`; `DEBUG` centrado.
- **Pendiente conocido (documentado, a afinar)**: la barra de **combo** arranca a 0 en el **1.er
  combate** (se rellena desde el 2.º; va ligada al PODER). Ver `TODO.md` y la nota.

Detalle: `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.

---

## 3. Cómo trabajar (rápido)

- Build Linux: `cmake --build build/linux --parallel $(nproc)`.
- Build Windows: `rmdir /s /q hybrid-heaven-recomp\build\windows` + `hybrid-heaven-recomp\build_windows_release.bat`.
- Traza de combate / campo: `run_battle_trace.bat` (F12), `run_field_watch.bat` (`HH_WATCH_ADDR`).
- Regenerar C recompilado: `python3 tools/regenerate.py` (no se versiona; ADR 0009/0011). Tras regenerar:
  `python3 tools/analysis/fix_fallthroughs.py`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).

## 4. Git / forks

- Rama **`menu-edicion-partida`**; **nada pusheado**. Commitear **solo lo validado o docs, y con
  permiso**. El mantenedor pidió **no pushear** de momento. Push (si se pide): forks primero
  (`N64Recomp`, `N64ModernRuntime`), luego el repo principal (ver `AGENTS.md`).

> **Calibración (AGENTS)**: distinguir "medido" de "inferido"; no concluir comportamiento de ejecución
> sin evidencia (oráculo/Windows); no inventar fórmulas. Un tema = un commit.
