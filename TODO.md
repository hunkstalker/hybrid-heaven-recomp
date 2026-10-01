# TODO — Hybrid Heaven: Recompiled

> **Única fuente de verdad de tareas.** `[ ]` pendiente · `[•]` en curso · `[x]` hecho.
> Detalle en `PROYECTO.md`, `docs/` y `notes/` (no duplicar). Histórico: `notes/`, `notes/archive/`.

## Ahora (priorizado)

- [x] **LÓGICA DE GUARDADO en la cápsula (`DATA SAVE`) — HECHA y VALIDADA en Windows (2026-09-30)**:
  flujo con fases propias (`hh::menu::SavePhase`: `Ask`→`Select`→`ConfirmHere`→`Completed`, +
  `ConfirmExit`); **guardado REAL** `hh::save::save_live()` (serializa los globals vivos con
  `func_80141F28` y persiste con `hh::save`: checksums + cabecera/trailer + recarga del PFS);
  `NEW GAME` = primer slot libre, slot con datos = sobrescribir; **salida** de la cápsula por la
  secuencia nativa; **reentrada** reinicia el flujo. **AREA 1-1** y **TIME** correctos. Detalle:
  **`notes/2026-09-30-save-capsule-logica.md`** (+ `notes/2026-09-30-save-data-ui-retoques.md`).
- [x] **BORRAR slots desde la cápsula — HECHO y VALIDADO en Windows (2026-09-30/10-01)**: en `Select`
  el mensaje informa de las dos acciones con bindings reales (inglés: `Select location in which to save
  play data pressing A/J or X/H to remove.`, 3 líneas); **X** sobre un slot con datos →
  `Remove play data?` → borra → `Remove completed.` + flecha; **A vuelve a la lista** (no sale).
  `NEW GAME` no se borra. Input en vivo (`hh_input_button_down`) + bloqueo ~120 ms al entrar en
  `Select`. Detalle: `notes/2026-09-30-save-capsule-logica.md` §8ter.
- [•] **UI de CARGA en el submenú `CONTINUAR` — PRÓXIMA TAREA**: (a) UI propia del `LoadGame`
  (confirmar con A, B atrás, mensajes/Yes-No estilo guardado; **decidir textos con el mantenedor**);
  (b) que un slot **cargue de verdad** (hoy `Action::LoadGamePick` solo llama a `func_801423C8(0, slot)`,
  que deserializa, pero **no arranca la escena**): replicar el final del flujo nativo CONTINUE
  (`func_80142570()` + `func_8012FE50(tipo=?, valor=?)` — **medir** los args con `HH_TRACE`) o dejar
  que la rama CONTINUE nativa haga setup+transición; (c) cerrar la sesión al salir (`close_load_game()`
  estilo guardado) y no republicar el overlay tras la transición. Pendiente: el prompt
  `Please connect Controller Pak…` se cuela con F8. **Receta completa en
  `notes/2026-09-30-save-capsule-logica.md` §9**.
- [x] **`DEBUG NIVELES` + `IR A ÁREA` (EXTRAS) — salto a cualquier nivel para TEST (2026-09-29,
  VALIDADO en Windows)**: **mecánica central descubierta y medida** (documento maestro:
  `notes/2026-09-29-editor-area-parte-plan.md`). Puntos clave:
  - **Campo del mapa = `0x564` (u16 LE) del slot**; el deserializador lo vuelca a `glob 0x801BBBF0[+4]`
    y el cargador de escena (`func_8012FE50(tipo=15, idx)` -> `func_80125968(idx)`) lo consume. **NO**
    es `0x366` (aquel no mueve el mapa). `idx = (area-1)*10` para los `N-0` (1-0=0, 2-0=10, ...,
    7-0=**75**, 8-0=80, 9-0=90).
  - **`EXTRAS > DEBUG NIVELES < NO/SÍ >`** (persiste `[extras].debug_levels`): activa el **CICLO DE
    PUNTOS** para mapear escenas: **F5/F6** = ±1, **RePág/AvPág** = ±10, **Inicio** = idx 0,
    indicador **`idx=`** en pantalla. Rango 0..99 con wrap. Índices que cuelgan en
    **`skip_indices.txt`** (junto al ejecutable, editable sin recompilar).
  - **`EXTRAS > IR A ÁREA`**: submenú con CARGAR/GUARDAR/ELIMINAR + selector **`ÁREA < N-N >`** (solo
    `N-0`) que **teletransporta** (`func_8012FE50`). Si no hay partida, carga la **plantilla**
    (`assets/save/template_slot.bin`: stats base + Code Key/Map Viewer/Defuser; la Code Key se quita
    al cargar 1-0). Verificado en Windows.
  - **Mapa de escenas medido**: `1-0`=0 … `9-0`=90; `100`=Demo Play #1; sub-puntos (`1-1a/b/...`) y
    estaciones por área. `skip_indices.txt` con la lista de los que cuelgan.
- [•] **Menú propio de CARGAR/GUARDAR partida (slots "infinitos", un `.pak` con N slots) — FASE 0 y 1
  HECHAS (2026-09-29)**: sustituir los menús nativos (CARGAR al `CONTINUAR`; GUARDAR en cápsula; y, al
  final, `EDICIÓN DE PARTIDA`) por un **menú propio (overlay)** con **N slots** en un **único `.pak`**
  (contenedor `HHPK` ampliado; `func_801423C8(slot)` sirve para cualquier índice), diseño **1:1**
  (Área-Level, nivel, tiempo; nombre `savegame_slot<N>`), estrategia **A**.
  - **Fase 0 `[MEDIDO]`** (`notes/2026-09-29-menu-cargar-guardar-fase0-hallazgos.md`): file-select
    trazado (estado `D_801BEBCC` 0..5, cursor `D_801BEC05`, top `D_801BEC04`; confirmar = inyectar A /
    `func_801423C8`; salida `ret=1` éxito, `ret=2` cancelar); captura 1:1 en
    `work/gameplay screenshots/CONTINUAR/`; `.pak` a N probado → **el PFS del runtime recortaba a
    `PAK_SIZE=0x8000`** y la cabecera `0x100` solo da para **30 registros**.
  - **Fase 1 = opción "b" HECHA `[MEDIDO]`** (`notes/2026-09-29-menu-cargar-guardar-fase1-formato-pak.md`;
    ADR **`docs/adr/0013-pfs-virtual-ampliado-y-pak-de-n-slots.md`**): fork NMR `PAK_SIZE` → **`0x40000`**
    (commit local, **sin push**); `hh::save` con **`kSlots=74`** y reparto **45 partidas (0..44) + 29
    plantillas (45..73)**; **trailer de metadatos** de 74×8 B y `size` del contenedor a `0x3C550`;
    `load()` migra `.pak` de 4 slots. Verificado: `func_801423C8` carga slots altos (p. ej. **slot 63**
    → escena `glob[+4]=0x13F`), fuera de rango falla; migración verificada **offline**.
    **Pendiente**: validar en Windows (migración real + flujo de guardado).
  - **DEPENDENCIA DE FORK**: la rama necesita **2 commits de NMR (no pusheados)** — `9b14604`
    `hh_pak_reload_from_disk` y el de `PAK_SIZE` (pendiente de commit) — y **bumpear el gitlink de
    `lib/N64ModernRuntime` tras push** (`AGENTS.md`).
  - **Fase 2 (UI 1:1) HECHA `[MEDIDO]`** (`notes/2026-09-29-menu-cargar-guardar-fase2-ui.md`): pantalla
    `LoadGame` (45 partidas del rango de juego, metadatos del trailer) + render 1:1 en overlay
    (`DATA LOAD`, caja de 3 líneas por partida, scroll/mensaje nativos). Validado headless con captura.
    **MAQUETA 1:1 (geometría) HECHA (2026-09-30, 3.ª sesión)**: título (y=28), `CONTROLLER PAK`
    (x=38,y=53), cajas (x=37,w=112,h=37,paso 46; texto +5/+4, línea 12), mensaje (x=29,y=171,w=262,
    h=51) y **sin flecha de cursor** (el nativo marca con el borde verde). Medido **pareado** contra el
    render nativo del port (`work/.../LOAD DATA Continuar.png`), **Δ<1 px**. Evidencia:
    `notes/2026-09-30-data-load-maqueta-1a1.md`. **Pendiente**: validar en Windows (F7) + ocultar el
    fondo del título.
  - **Fase 3 (enganche a CONTINUAR) HECHA `[MEDIDO]` (2026-09-29; 2ª sesión 2026-09-30)**: al dar
    CONTINUAR sale `LoadGame` y el **DATA LOAD nativo queda oculto** (texto + cajas); **F8** muestra/
    oculta la UI nativa. Ocultado por CATEGORÍAS en `menu_overlay.cpp`; hooks
    `func_801C3D84`/`func_8001A804`. **NO** enganchar `func_801C3D50` (cuelga). **Fix 2026-09-30**:
    F8 pintaba el `BATTLE DATA LOAD` porque el recompositor llamaba a `func_80142840` (tabla
    `ＢＡＴＴＬＥ　ＤＡＴＡ　ＬＯＡＤ` + `1P/2P CONTROLLER`); ahora solo llama a `func_801426B0`
    (setup real del `DATA LOAD`). El enganche de CONTINUAR en sí era correcto. Evidencia:
    `notes/2026-09-30-continuar-enganche-y-ocultado.md`. **Pendiente**: (a) validar en Windows
    CONTINUAR→F8→A; (b) el ocultado sin F8 aún se cuela el prompt `Please connect Controller Pak…`;
    (c) commit.
  - **BLOQUEANTE del 1:1 → TAREA APARTE**: las **tipografías del DATA LOAD** (3 fuentes distintas;
    `func_8001B204` elige estilo por `a0` → tabla `D_8008EF70`). Documento:
    **`notes/2026-09-29-tipografias-data-load-tarea.md`**. **Es la tarea principal ahora.**
- [•] **Extracción/mapeo de las TIPOGRAFÍAS del DATA LOAD (2026-09-29/30, desvío deliberado)**: MAPEO
  **RESUELTO `[MEDIDO]`** (traza `HH_FONT_TRACE`+`HH_FONT_DUMP_GLYPH` en headless). **Corrige** la
  premisa: `a0` de `func_8001B204` es el **contexto/slot** (no la fuente); la fuente la elige el código
  `%m <n>` **dentro** de la cadena (→ `colorN`). Reparto del DATA LOAD: título `DATA LOAD` = **color3**
  (idx 106, 12×13, stride 78) `[MEDIDO]`; mensaje `Select play data to be loaded.` = **color4** (idx 108,
  8×12, ya extraída); `CONTROLLER PAK` + cabeceras/filas `AREA/LEVEL/TIME` = **color0** (atlas actual).
  Valores de glifo medidos del título: `A=0x76` (`valor = 0x76 + (c-'A')`). **CABLEADO HECHO** en la UI
  propia (`LoadGame`): `Face{Color0,Color4,Color3}` en `font.h/cpp` (atlas 128×214 con franjas color4 y
  color3), `overlay::Text.face` y uso en `menu_overlay.cpp` (título→color3, mensaje→color4,
  filas→color0). Validado headless con captura (coincide con el nativo). Evidencia y detalle:
  **`notes/2026-09-30-tipografias-data-load-hallazgos.md`** (doc. tarea:
    `notes/2026-09-29-tipografias-data-load-tarea.md`).     **Pendiente**: validar 1:1 en Windows (F7).
    **Maqueta/geometría HECHA (2026-09-30)**: ver `notes/2026-09-30-data-load-maqueta-1a1.md`.
    **Avance color4 del mensaje HECHO**: `face_glyph_advance` (espacio=4, `f i j l r t`=6) → el mensaje
    **calca el nativo glifo a glifo**; **punto final `.` rehecho** (1x1 en el baseline, antes 2x2).
    **Subtítulo `CONTROLLER PAK` → `MEMORY SLOTS`** (traducido), por decisión del mantenedor. **Colores
    1:1** (borde del mensaje gris ~170, bordes de slot gris ~90, verde `19,255,13`) y **marco exterior
    que agrupa los slots** (x=31,y=65,w=124,h=94; del setup nativo +1 px por lado), con las cajas de
    slot por encima. Slot vacío = **`NO DATA` centrado y en blanco** (`SIN DATOS/SENSE DADES/…`).
    **Sombra de glifo nivel 2 = gris** (antes negro; corregía el gancho de la `l` del mensaje).
    Queda **pendiente de decisión**: el **contenido/alineado de las filas**
    (`AREA/LEVEL/TIME` nativo con valor a la derecha vs `ÁREA/NIVEL/TIEMPO` del overlay).
- [ ] **`EDICIÓN DE PARTIDA`: "mover mi partida a una Área-Parte" (2026-09-29, DISEÑADO)**: cargar la
  partida del jugador en el editor, elegir Área-Parte, y **GUARDAR** = plantilla de esa Área-Parte +
  sobrescribir **atributos/estado/items/habilidades** del jugador (lo demás, de la plantilla). Requiere
  **plantillas por punto de guardado** (`assets/save/templates/<n-p>.bin`, generadas jugando). Detalle:
  `notes/2026-09-29-editor-area-parte-plan.md` §6bis.
- [ ] **Editor `PROGRESO` del slot**: ahora escribe **`0x564` (u16 LE)** con
  `(area-1)*10+(sub-1)*2` y lista solo puntos de guardado (sin `N-0`). **Pendiente validar en Windows**
  que `CONTINUAR` carga donde toca.
- [x] **`MODO HEAVEN` (EXTRAS) — modo GLOBAL persistente, VALIDADO en Windows (2026-09-28)**: NO
  depende de la partida ni del editor (persiste en `config.ini [extras].heaven`). Al cargar/empezar
  cualquier partida aplica al personaje vivo `0x8017DC40` **ATRIBUTOS/ESTADO 99 + 86 habilidades**
  (`apply_heaven_runtime` vía hooks `func_80144E68`/`func_80152240`), y en runtime **daño 0 al PJ**
  (`func_80232D08`) e **items que no se gastan** (`func_8013D520`; no se fuerzan a 99). El save normal
  persiste el estado; apagar quita invuln/consumo pero conserva lo guardado. Detalle: `RETOMAR.md`,
  `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.
- [x] **`VENTAJA` (EXTRAS) — VALIDADO en Windows (2026-09-28)**: selector NO/SÍ, traducido a los 6
  idiomas y persistente en `config.ini [extras].advantage`. Fuerza `0x801BCC24 = 2` (POWER al máximo al
  empezar). **Independiente de MODO HEAVEN** (se le retiró: con PODER ∞ es redundante). Validado contra
  un enemigo que NO sale sorprendido: ON = POWER al máximo, OFF = no. Detalle: `RETOMAR.md`.
- [ ] **Combo: no se rellena en el 1.er combate (a afinar en el futuro, 2026-09-28)**: la barra de
  combo se alimenta del PODER (100 % → +1 segmento) y con `PODER ∞` queda llena, pero **arranca a 0 en
  el 1.er combate** y solo se rellena desde el 2.º (parece un gateo de estado al terminar/vaciar el
  PODER en el 1.er combate). **No** localizado el contador (0..4) en las zonas vigiladas. Plan: traza
  que cruce el fin del 1.er combate con el 2.º para hallar el flag y forzarlo. Detalle: `RETOMAR.md`.
- [x] **`PODER ∞` / `RESISTENCIA ∞` (EXTRAS) — VALIDADO en Windows (2026-09-28)**: dos selectores NO/SÍ
  (con símbolo vectorial `∞`) debajo de `VENTAJA`, persistentes en `config.ini [extras].infinite_power`
  / `[extras].infinite_stamina`. `hh_battle_frame_hook` pinnea `actual = max` cada frame (PODER
  `0x801BC042←0x801BC040`, RESISTENCIA `0x801BC046←0x801BC044`) → no se gastan. **MODO HEAVEN los
  incluye.** O(1), no-op fuera de combate. Detalle: `RETOMAR.md`.
- [x] **Centrar los submenús `GRÁFICOS` y `CONTROLES`** en el overlay (`menu_overlay.cpp`): `Graphics`
  añadido a `custom_layout`; `scroll_cap5` solo para EXTRAS/CONTROLES/editor (GRÁFICOS conserva 6 filas).
- [x] **Daño FUERA de combate (robots) — VALIDADO en Windows (2026-09-28)**: la vida de campo es el
  sheet `0x8017DC40+0x02`; `func_80379F04` hace `HP -= *(s16*)0x80388A68`. Hook
  `hh_heaven_field_damage_hook`: con HEAVEN pone el scratch de daño a 0 durante la llamada → no baja la
  vida. Una sola función para todos los robots. Detalle en `RETOMAR.md`.
- [ ] **Sistema de guardado en PC: rediseño (ideas apuntadas 2026-09-27)** — sin planificar aún;
  detalle en `docs/ideas-edicion-partida.md`: `DATA EDITOR` no tiene sentido en PC; **slots "infinitos"**
  (o N con scroll); UI moderna de partidas (**lista + `NUEVO` arriba**); **`CLONAR SLOT`** sin interfaz
  (copia al último slot); **`EDITAR DATOS` → ordenar slots** (no copiar entre paks).
- [•] **`EDICIÓN DE PARTIDA` (editor de save) — v3 sobre el `.pak`, rama `menu-edicion-partida`,
  commit `77d2ad6` (2026-09-27)**: menú en `EXTRAS` con `CARGAR PARTIDA < PARTIDA N >`,
  `GUARDAR PARTIDA < NUEVA PARTIDA / PARTIDA N >`, `PROGRESO < N-P >`, `NIVEL`, `HABILIDADES`
  (`< SIN CAMBIOS / TODO SÍ / TODO NO >`), `ESTADO` (CUERPO bajo CABEZA), `ITEMS`. `GUARDAR` escribe
  el `.pak` con offsets/checksum correctos (verificado headless). **ABIERTO (bloqueante)**: `CONTINUAR`
  no refleja lo editado. También: repeat up/down/izq/der y cierre F11 rápido. Detalle:
  `notes/2026-09-27-f-editor-partida-v3-y-hallazgos.md`. Ideas de sistema de guardado:
  `docs/ideas-edicion-partida.md`.
  - **Sesión 2026-09-28** (`notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md`):
    **formato real del slot documentado** (struct de personaje bswap32 / `u16 LE`; técnicas/items/progreso)
    y **función del juego que escribe la cabecera** (`func_80142350`/`func_80141268`). Corregido:
    `CONTINUAR` (recarga `g_pak` tras GUARDAR), `NIVEL` (u16 LE en `0x4A`), contadores `ESTADO`
    (u16 LE, ya no 256), **items** (nombre real del registro `0x8017E004+id*8`; la **cantidad** va en
    el slot de su familia invertido, S↔X/M↔L: `item_slot_of`), **cabecera de la lista de partidas**
    (`update_save_header`: AREA/LEVEL/checksum del registro del slot → DATA LOAD refleja los cambios y
    `NUEVA PARTIDA` crea entrada) y **pantalla `ATRIBUTOS`** (edición manual de
    HP/HP MAX/STAMINA/OFENSIVO/DEFENSIVO/VELOCIDAD/REFLEJO). **Lógica de juego documentada**
    (maestría, aprendizaje, partes) en `notes/2026-09-28-logica-juego-tecnicas-items-y-stats.md`.
    **Escalado parte→stats: RESUELTO (2026-09-28)**. Lo hace **`func_80376D48`** al acabar el combate
    (`func_803840A4`): 6 atributos con nivel+progreso+tablas independientes; HP sube con su parte
    (`+0x04`) por `incremento_HP` 5,10,10,15…, DEFENSE con `+0x53` por 24,6,6…, OFFENSE `+0x52` por
    36,8,8…, etc. El nivel global (`+0x48`) es la media de las 6 partes (`func_8037865C`) y **no**
    entra en las fórmulas. **Modelo del progreso (traza `[STATEXP]`+`HH_CANARY`)**: `progreso_i +=
     round(reward_i × ref_i / stat_i)`, divisor la **propia stat** → **rendimientos decrecientes** (con
     OFFENSE=410 a mano, OFFENSE deja de subir). **CORRECCIÓN (2ª sesión 2026-09-28)**: la reward **NO
     es fija** — es la **fila del ENEMIGO derrotado** (`func_8022CAFC` la elige en `0x8023C940` por
     `a0+0x36`; `func_80376D48` 1 vez/combate); confirmado con `[STATEXP]`/`[ROW]` en 5 combates. Y el
     **tope de nivel** por atributo depende de la dificultad (`func_80376D10`: 79/89/99). Detalle:
     `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`. Corregida además la pista previa
    (`0x800D425C`/`0x800D4260` era error de complemento a dos → `0x800CBDA4`/`0x800CBDA0`).
    Detalle y tablas: `notes/2026-09-28-stats-recompute-correccion.md` §6 y referencia
    `docs/stats-partes.md`. **Hecho en el editor (2026-09-28)**: (1) confirmado y corregido el
    **word-swap 32-bit** del save (`swap16=r^2`, `swap8=r^3`): OFF/DEF y VEL/REF ya no salen
    invertidos; (2) NIVEL global **solo lectura** (derivado); (3) **nivel y progreso por parte
    editables** (`add_part_levels` aplica `incremento[nivel]`). **Lead** "dificultad dinámica":
    `func_8022CAFC` cruza OFFENSE_ente←DEFENSE jugador (§8); confirmar identidad con oráculo.
    **Pendiente**: **validar en Windows** (build + editar nivel de parte → ver stat/STATUS).
    **Hecho (2026-09-28)**: pantalla **`SIM. COMBATE`** (selector COMBATES 1/2/5/10/25/50; A simula)
    que aplica la fórmula EXACTA del juego (`save::simulate_combats`: `EXP_i += round(reward_i×ref_i/
    stat_i)` con `ref_i=min(transformada, tope)` cruzada OFF↔DEF, + bucle de subida). Verificado: vanilla
    2 combates → HP 100→105 y DEFENSE 50→74 (idéntico al juego). Abajo, filas de solo lectura
    `NIVEL n  valor  EXP`. **ATRIBUTOS** sigue editable (raw). **Futuro**: barras de progreso.
    **Corrección (2026-09-28, mantenedor)**: en ESTADO, **OFENSIVO/DEFENSIVO son NIVELES de la parte**
    (suben al atacar / al **GUARDAR**, `+0x10`/`+0x1C`), y **HIT/DAMAGE COUNT son contadores**
    (`+0x68`/`+0x76`). Alimentan la **potencia de combate** (`func_8022DB40`/`func_8022F0E0`);
    `func_80232A80` incrementa el nivel defensivo de una parte (`entidad+0x8E+part*2`). **Pendiente**:
    fórmula exacta del incremento de nivel de parte y si afecta al nº de golpes/combo; y el
    **nivel de maestría** de técnicas (¿desbloquea niveles superiores?).
- [x] **Release sin volcados (v0.5.1) — HECHO (2026-09-27)**: el `.exe` release **solo** deja
  `hh.log` (sobrescrito cada run). Pasaron a **opt-in**: `hh_audio.log`, `hh_tick.log`/`hh_slow.log`,
  watchdog (`hh_state.log`/`hh_slice.log`/`hh_hang*.log`/`hh_flag.log`), crash
  (`hh_crash*.log`+RDRAM/DMEM) y `hh_pak.log` (fork NMR). Envs: `HH_DIAG=1`, `HH_CRASH_LOG=1`,
  `HH_PAKLOG=1`. Detalle: `notes/2026-09-27-d-release-sin-volcados.md`; `docs/releases/v0.5.1.md`.

- [x] **BUG resuelto (headless, 2026-09-25): cambiar de idioma aceleraba el juego (30→60)**. Causa:
  `hh_trans_reapply_language` reescribía el módulo entero y pisaba cambios del juego (relocs de código,
  buffers de trabajo). Fix: re-aplicar solo los bytes cuyo contenido coincide con el testigo `written`
  (lo escrito en la carga) + poda de solapes y tope de memoria. Knob A/B `HH_LANG_REAPPLY=0`.
  Validado headless (`vi=30` estable); **falta confirmar en Windows**.
  `notes/2026-09-25-e-fix-reapply-idioma.md`.
- [x] **Bugs del menú overlay A2 (2026-09-24) — VALIDADOS en Windows**: bearing de "MODO COMBATE",
  **tercer set** de etiquetas al volver atrás, y cierre del overlay (instantáneo al cambiar de
  pantalla). Ver `notes/2026-09-24-a2-overlay-alineacion-y-cierre.md` y `...-dos-tablas.md`.
- [x] **Menú IN-GAME de opciones PC (ADR 0008) — HECHO (2026-09-25, headless)**: árbol, navegación
  (A/B, control total), acciones (video → `[video]`; audio → `[audio]`), SFX por eventos, **acentos**
  (letra+marca) e **idiomas** (EN/ES/CA/FR/DE + **idioma del sistema**). Detalle:
  `notes/2026-09-25-d-menu-multilingue-acentos-e-idiomas.md`, ADR 0008/0012.
  **Validado en Windows (2026-09-26, tras el merge con `main`)**; falta el **JA del menú** (kana).
- [ ] **Menú nativo — funcionales y pulido (2026-09-26, orden recomendado)**:
  1. [x] **Bug del submenú `IDIOMA` — RESUELTO y validado en Windows (2026-09-26)**: al entrar con A
     en `IDIOMA` se aplicaba el idioma del cursor (el `Accept` de entrar ejecutaba acciones de la
     pantalla hija). Fix: aplicar acciones por `Accept` solo si no cambió la pantalla.
     `notes/2026-09-26-b-menu-idioma-configuracion-y-sombras.md`.
  2. [x] **`AJUSTES` → `CONFIGURACIÓN` — HECHO y validado (2026-09-26)**: ES `CONFIGURACIÓN` · EN
     `SETTINGS` · CA `CONFIGURACIÓ` · FR `CONFIGURATION` · DE `KONFIGURATION` (`kMenuTr`).
  3. [x] **`CONTINUAR` — VALIDADO en Windows (2026-09-26)**: reenvía la acción al **dispatch nativo**
     del menú de título (`sel 0x801CC8C4 = 1` = CONTINUE + A inyectada una vez,
     `src/hooks/sections.cpp`), reutilizando la carga real (`func_801C3CDC`). Con overlay activo; con
     `HH_OVERLAY=0` manda el nativo. `notes/2026-09-26-d-continuar-y-bugs-visuales.md`.
  4. [x] **`EMPEZAR PARTIDA` — VALIDADO en Windows (2026-09-26)**: dispara la rama **GAME START** del
     submenú nativo `NUEVA PARTIDA` (`func_801C3A40` idx 0): `func_80005670(obj, 0x80044090)` +
     `func_800058DC(obj, 0x801C3BA4)`; la cadena nativa crea la partida. No pasa por `func_801C3940`
     (solo resetea dificultad/registra etiquetas). `src/hooks/sections.cpp`. Método en `docs/menu.md`
     §Acciones nativas; nota `notes/2026-09-26-g-empezar-partida-y-dificultad.md`.
  5. [x] **`DIFICULTAD` — HECHO (2026-09-26)**: `EMPEZAR PARTIDA` escribe la dificultad elegida en el
     global `0x801BBC0D` (`0=NORMAL`/`1=DIFÍCIL`/`2=DEFINITIVO`) leyendo la opción marcada del modelo
     (`hh::menu::screen(ScreenId::Difficulty)`). **Pendiente de comprobar jugando** el efecto real
     (daño que hacen los enemigos); el mantenedor confía en la implementación (2026-09-26).
   6. [x] **Logos de intro HD (KONAMI/KCEO) + código Konami → `EXTRAS` — VALIDADO en Windows
     (2026-09-26)**: **Causa raíz**: los logos de arranque los pinta el **módulo file 055**
     (`func_80383AD4`), NO el de título. Composicion **negro base + tarjeta opaca (blanca clásicos /
     negra modernos) + logo (`mode 2` clave de blanco) + velo de fundido (grupo) + flash**. Alfas
     copiadas del nativo (`0x8038DBC0`/`0x8038DBD4`). **Preload** del PNG. Código `↑↑↓↓←→←→BA` →
     `unlock_extras()` **de sesión** + **flash blanco**. Entrada `EXTRAS` en la raíz; toggles
     persistidos en `config.ini [extras]`: **`MANTENER EXTRAS <NO/SÍ>`** y **`LOGOS ORIGINALES
     <NO/SÍ>`**, con **layout propio** (desplazado a la izquierda + columna de valores dinámica).
     **Skip con START** (1 por logo). **Ventana** borderless al crear (sin transición). Fixes del
     **attract** (ya no re-muestra logos HD; timer de inactividad nativo) y **"Press Start" centrado**
     al traducir. **Falta**: ampliar el contenido de `EXTRAS` (nivel/habilidades).
     `notes/2026-09-26-i-logos-intro-hd-y-konami-impl.md`.
   7. [x] **Demos de inactividad — RESUELTO/VALIDADO (2026-09-26)**: el menú moderno forzaba el timer
     de inactividad (`obj+0x3C`) **cada frame**, falseando el timeout del attract; ahora se **reinicia
     solo con input real**. Intro/demos salen al ritmo del original.
  8. [x] **Sombra de la flecha de cursor — VALIDADO en Windows (2026-09-26)**:
     `append_native_cursor` (`src/hooks/menu_overlay.cpp`) la dibujaba con rectángulos sólidos; ahora
     lleva **copia negra `kShadow` desplazada +1,+1** detrás (como el texto).
  9. [x] **Sombra de las tildes/marcas + z-order — VALIDADO en Windows (2026-09-26)**:
     `tools/text/menu_marks.py` aplica `add_shadow_cell` (**nivel 2, +1,+1**) a **todas** las marcas
     (tildes + `· Æ Œ`, con `Æ`/`Œ` desplazados 1 px); `include/hh/menu_marks.h` regenerado desde
     `assets/fonts/menu_marks_ed.png` (formas del mantenedor verificadas; máx. 8×9). Las marcas se
     dibujan **debajo de la letra** (`src/platform/overlay.cpp`) para que la sombra no pise la tinta.
     Nombres `Set A`: `_base` (plantilla), `_ed` (diseño), `_blank` (lienzo de `--template`).
     Detalle: `notes/2026-09-26-c-sombras-y-set-a.md`.
  10. [x] **`CONTROLES` (remapeo + ejes + D-PAD + `RESET`) — VALIDADO en Windows (2026-09-26) y
     commiteado (`74dd5a8`)**: submenú con tabla de **acciones** y 2 columnas (**MANDO/TECLADO**),
     **scroll de 5 filas + flechas ↑/↓**, menús del port centrados. Reasignación a **cualquier botón
     (incl. D-PAD) y/o tecla** (**1 botón + 1 tecla**), con bloqueo A/B 0.25 s al asignar; **movimiento**
     (4 ejes: stick izq/der + tecla), **D-PAD** como botones (`MENÚ ...`) y **`RESET`**. Persiste en
     `[game]/[menu]` + `[keys]`. `notes/2026-09-26-j-controles-remapeo-y-vibracion.md`.
     **La `VIBRACIÓN` no es validable hasta resolver el item 11** (con `VIBRACIÓN` en SÍ no se puede
     cargar/guardar).
  11. [ ] **VIBRACIÓN ↔ guardado (Rumble Pak vs Controller Pak) — BLOQUEANTE jugable**: en N64 ambos
     comparten la **misma ranura**; Hybrid Heaven pide conectar el **Controller Pak** al guardar y el
     **Rumble Pak** después. Con `VIBRACIÓN` en SÍ (CONTROLES) se reporta **Rumble Pak siempre** y nunca
     hay Controller Pak → **no se puede cargar ni guardar** (in-game no hay forma de "quitar" el Rumble
     Pak). **Tarea**: modificar el juego para que **vibración y guardado coexistan** (p. ej. que el PFS
     virtual funcione aunque se reporte Rumble Pak, o permitir ambos a la vez); y, si ya no hace falta
     conectar/desconectar dispositivos, **eliminar los mensajes** de conectar Controller/Rumble Pak.
     **Es un problema común a los recompilados (pasa en el 100 % de los casos): investigar cómo lo
     resolvieron otros proyectos** (p. ej. Zelda64Recomp / N64Recomp) — probablemente reportando o
     emulando un "pak combinado" (Rumble + Controller a la vez) o adaptando el PFS. Relacionado:
     `VIBRACIÓN` (item 10) y el PFS virtual (`lib/N64ModernRuntime/librecomp/src/pak.cpp`).
   12. [x] **`MODO COMBATE` (BATTLE MODE) — RECREADO CON NUESTRO MENÚ Y VALIDADO EN WINDOWS
      (2026-09-27)**:
      el nativo la tiene como `sel=2` (`func_801C1DB8`, `0x801CC8C4`). **Hecho (2026-09-27)**:
      (1) mapa completo de la secuencia nativa (todo en `file_024`: setup `0x801C40F8` → update
      `0x801C4200`; `VS MODE`→stub `0x801C43B0`, `CREATURE BATTLE`→`0x801C43BC/44C4/…`, `DATA EDIT`→
      `0x801C47D0/…`, `EXIT`→`0x801C56B8` vuelve a la raíz; `DEMO SELECT` está en `file_025`);
      (2) **SEGV `FUN_80026f58` NO reproducido** en la build Linux actual por ninguna de las ramas
      (harness headless); pendiente validar en Windows;
      (3) **`MODO COMBATE` habilitado** y **recreado** (`MODO VS` / `COMBATE DE CRIATURAS` /
      `EDITAR DATOS`, traducido en/ca/fr/de; navegación propia; sin `SALIR`, se sale con `B`);
      (4) **despacho nativo cableado** (`hh_battle_menu_hook` envuelve `func_801C4200`): cursor
      `0x801CC8C8` + A inyectada (patrón `sel`+A), etiquetas/flecha nativas suprimidas,
      resincronización al volver a la raíz;
      (5) **pantalla interna `COMBATE DE CRIATURAS` recreada** (`5 COMBATES` / `SUPERVIVENCIA`;
      `hh_battle_creature_hook` envuelve `func_801C44C4`; `B` vuelve a la raíz).
      Verificado headless sin SEGV (`801C4200` y `801C44C4`); **validado en Windows (2026-09-27)**.
      **No validado**: `MODO VS` — el port **solo reporta el puerto 0** de mando
      (`src/subsystems/input.cpp`: `return controller_num == 0`), así que el juego no detecta un
      **2.º mando** (¿o un 2.º **Controller Pak**?); imposible probar 2P hasta resolverlo (ver backlog).
      `EDITAR DATOS` no tiene pantalla de opciones propia (flujo nativo); si se quiere, se recrea tras
      inspeccionarlo. Detalle/receta: `notes/2026-09-27-battle-mode-recon.md`; `docs/menu.md` §MODO COMBATE.
   13. [x] **`CÁMARA LIBRE` / `APUNTADO LIBRE` ocultos — HECHO Y VALIDADO en Windows (2026-09-27)**:
      decisión final del mantenedor (último cambio antes de v0.5.0): **no se muestran** en `NUEVA
      PARTIDA` (se retiraron del árbol, `build_tree`). Antes se probaron como **deshabilitados** (gris,
      cursor sin posarse) — se conserva la maquinaria (`make_selector(..., enabled=false)` + `move_up`/
      `move_down` saltan `!enabled` con `step_enabled`, y el overlay los pinta en gris) por si se
      deshabilitan otras entradas. Nota: `notes/2026-09-27-c-…`.
   14. [x] **Tildes a la derecha — HECHO Y VALIDADO en Windows (2026-09-27, `12961d4` + corrección)**:
      el `dx` centrado de la marca en `src/platform/overlay.cpp` suma un offset (global, todas las
      marcas). Se probó `+1.0 px` y era **demasiado**; queda en **`+0.5 px`**. No se regenera
      `include/hh/menu_marks.h`.
   15. [x] **Traducción del MENÚ al JAPONÉS — HECHO Y VALIDADO en Windows (2026-09-27, commit
      `0c5f50c`)**: **hallazgo**: `color0` (idx107) del **ROM JP es byte-idéntico al US** → la kana
      (valores 64..255) ya está en la ROM que carga el port; **no** hay que extraer nada de `jp.z64`.
      Mapping kana→glifo desde las tablas EUC→slot del `.resident` del ELF (filas A4/A5/A1) →
      `tools/text/extract_jp_kana.py` genera `include/hh/jp_kana.h` (165 entradas). Atlas 128×32 →
      **128×140** (`kMaxValue` 256); `kMenuTr` con columna **`ja`** (kana) y `localized()` sin fallback
      a inglés (`lang=5`); endónimo JA `ニホンゴ`. Nota: `notes/2026-09-27-c-…`.
- [ ] **Smoke de arranque** (opcional, requiere ROM): ROM en `rom\` junto al `.exe` (o `HH_HEADLESS=1` +
  `rom/` en Docker): la encuentra y sin `Failed to find function`.
- [ ] **Definir ADR 0009** (cobertura nativa / clean-room) cuando se adopte la visión de
  `docs/README.md`: manifiesto de reimplementadas + métrica de cobertura.

## Backlog (priorizado)

- [ ] **Verificar los textos JA del menú contra la ROM japonesa** (2026-09-27): el menú ya sale en
  kana (columna `ja` de `kMenuTr`, `include/hh/jp_kana.h`) pero el mantenedor **no lee japonés**; una
  tarea futura debe **cotejar** los rótulos con los originales de `work/roms/jp.z64` (menús nativos,
  EUC-JP) y corregir la redacción/terminología. La infraestructura (kana + mapping) ya está.
- [ ] **Fallos visuales detectados por el mantenedor (2026-09-26; capturas en
  `work/gameplay screenshots/CONTINUAR/`)**: `work/` está gitignored; si hace falta conservar las
  capturas, copiar las relevantes al repo.
  1. **`DATA LOAD` (slots de partida)** — al mover el cuadro de selección entre slots, su **borde
     verde** aparece pegado al **borde superior de la pantalla** (línea verde a `y≈0`), descolgado del
     cuadro. Captura `Captura de pantalla 2026-09-26 033740.png`. Es un menú **nativo** (no overlay).
     Probable artefacto de widescreen (`snap_overscan`)/rect 2D; investigar con **F7** (captura pareada)
     y `HH_FULL_FRAME=0` para acotar.
  2. **Combate (golpes)**: los ataques salen como **cajas verdes/rojas con recuadro negro (solo el
     borde)**; en el original **no** llevan ese borde. El mantenedor irá añadiendo capturas a esa carpeta.
- [x] **FPS en pantalla (2026-09-26)**: `MOSTRAR FPS` en el menú `DEBUG` (menú moderno de
  `menu-nativo`) enciende el **indicador de FPS del overlay** (solo números, arriba-izquierda; mide la
  tasa **real** de presentación) y persiste en `config.ini [video].showfps`. `HH_FPS=1` sigue volcando
  a `hh.log`. Vías alternativas: `HH_DEVELOPER=1` + F1 (Inspector de RT64) y RTSS (overlay externo,
  subir *detection level*). Ver `notes/2026-09-22-fps-y-present-early.md`.
  `src/hooks/sections.cpp` (acción), `src/platform/support.cpp` + `rt64_render_context.cpp`.
- [x] **Menú A2 — overlay moderno (render hook RT64) + opciones PC (2026-09-23/25)** — HISTÓRICO.
  Menú propio del port, **solo en el menú inicial** (no el de pausa). Arquitectura `hh_menu → hh_font →
  backend_game` (atlas de la **fuente del juego**, hoy) / `backend_modern` (TTF, futuro,
  **seleccionable desde el propio menú**). El intento por GBI (`hud_rewrite`/`send_dl`) **falló** (RT64
  compone el framebuffer del juego; los draws GBI no llegan al swapchain) y se retiró; la vía es
  **`RT64::SetRenderHooks(init, draw, deinit)` + plume**. Hitos: shaders+CMake, render hook+atlas RGBA8,
  `hh_menu` del título (hook `0x801C1DB8`, modelo+dibujo 1:1+navegación, **menú nativo oculto**, F6),
  navegación/control total (A/B), **GRÁFICOS** (RATIO/RESOLUCIÓN/P. COMPLETA/ANTIALIASING/VSYNC/LÍMITE
  DE FPS), **DEBUG** (VENTANA DEBUG→F1 + MOSTRAR FPS) y **AUDIO** (VOLUMEN/SALIDA/MENÚ SFX) aplican en
  vivo y **persisten en `config.ini`** (`[video]`/`[audio]`); SFX por eventos del modelo. Todo
  **validado en Windows (2026-09-26)**. Detalle: `notes/2026-09-24-a2-*.md`, `notes/2026-09-23-a2-*.md`,
  `docs/menu.md`, ADR 0008/0012. Contexto descartado: `notes/2026-09-23-b-motor-texto-localizado.md`,
  `...-a2-plan-menu-ajustes-idioma.md`.
- [•] **Traducción — MENÚ (overlay del port)**. Alcance: **etiquetas del menú moderno** (no usa el
  motor de texto del juego). **Hecho (2026-09-25/26)**: localización **en/es/ca/fr/de**
  (`hh::menu::localized`, lista en **endónimos**); acentos = **letra base `color0` + marca**
  (`tools/text/menu_marks.py` → `include/hh/menu_marks.h`; `¿ ¡` = `? !` girados); **`IDIOMA` en
  `AJUSTES`** funcional (menú + texto in-game), con **idioma del sistema** (fallback inglés) y
  persistencia `[lang]`; **validado en Windows (2026-09-26)**.
  **Pendiente**: **JA del menú** (embeber la **kana** del `color0` JP — tiene kana, no kanji).
  Detalle: `notes/2026-09-25-d-menu-multilingue-acentos-e-idiomas.md`, **ADR 0012**, `docs/menu.md`.
- [•] **Traducción — JUEGO/GAMEPLAY (texto in-game)**. Alcance: **cadenas del juego** vía el motor de
  texto (loader `trans`). **Hecho (2026-09-23)**: charset USA derivado (ASCII en campos de ancho fijo +
  NUL; el "encoding custom" era LZKN64) y **sustitución en runtime** (`src/subsystems/text.cpp`;
  `HH_LANG=es`); extractor `tools/text/extract_strings.py`; **sistema A1** (lista `en/es/ca/fr/de/ja` +
  mods, **cambio en vivo** F5 con re-aplicación a módulos cargados, persistencia `[lang]`).
  **Pendiente**: control de **longitud variable** y validar A1 en Windows; **cablear** la fuente
  in-game **8×12 `color4`** (`tools/text/build_font.py` → `include/hh/game_font_color4.h`, ES/CA/FR/DE)
  en `src/hooks/text_glyphs.cpp` (hoy sirve un set 8×8 propio; `HH_ACCENTS=0` la desactiva);
  **extraer DE/FR** (ROM EU) y **JA** (ROM JP) emparejando por módulo → `assets/lang/*.txt`, y redactar
  **ES/CA**; **medir cobertura** (nº de strings/zonas) y decidir formato (La PAL FR/DE = referencia).
  Detalle: `notes/2026-09-23-spike-traduccion-charset-y-sustitucion.md`,
  `notes/2026-09-23-a1-sistema-idiomas-y-cambio-en-vivo.md`,
  `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`, `notes/2026-09-23-b-fuente-formato-y-gaiji.md`,
  `notes/2026-09-25-e-fix-reapply-idioma.md`. Ver `PROYECTO.md §4`, `notes/2026-09-05_asset-map.md`.
- [x] **Widescreen: anclaje del HUD/mapa (fase 07b) — COMPLETO y validado en Windows (2026-09-26)**:
  - **Izquierda**: radar y **HUD de combate** (POWER/STAMINA, disco radial, combo, stamina gastada);
    **derecha**: **minimapa** (contenido + fondo negro a todo el ancho). Persiste entre combates y niveles.
  - **No existe barra HP**: la salud es el **dial radial** + el **numérico `HP n/n`** (bloque izquierdo
    ya anclado). **Cuadros de diálogo**: salen centrados con su propio anclaje → **sin cambios**.
  - **Issue #3 (v0.4.1–v0.4.3, validado)**: desde el **2º combate** el HUD se quedaba en 4:3 (la
    dirección RDRAM del gráfico cambia por encuentro; no es identidad). POWER/STAMINA por **hash de
    contenido** (`d820d8e`); **disco radial** por **hash + caja `27,19,59,51`**; **combo** (4
    `G_FILLRECT`, `y=28..30`) y **stamina gastada** (`y=34..38`) por **posición** (el color cambia
    rojo→azul→naranja y RT64 pinta el relleno con el PRIM color → la traza lee `fill_color=0`).
  - **Issue #7 (v0.4.4, validado)**: **minimapa** por **hash de contenido** (la dirección del overlay
    cambia por escena/capítulo). `notes/2026-09-26-fix-minimapa-contenido.md`.
  - Reescritor: `src/hooks/hud_rewrite.cpp` (+ `include/hh/hudid.h`); `HH_NO_HUD_REWRITE=1` lo
    desactiva, `HH_FULL_FRAME=0` el widescreen, `HH_HUD_TRACE=1` la traza; **F7** = captura pareada.
  - Detalle: `notes/2026-09-21-anclaje-hud-widescreen-radar.md`,
    `notes/2026-09-22-anclaje-hud-widescreen-fase07b.md`,
    `notes/2026-09-22-fix-mapa-rect-negro-widescreen.md`,
    `notes/2026-09-25-f-hud-combate-contenido.md`.
- [ ] **Artefacto de interpolación de frames (puerta + jefe del nivel 1) — APLAZADO (largo plazo)**:
  con `Refresh Rate = Display` (interpolación ON, v0.4.0) cierta **puerta** parpadea y el **primer
  jefe del nivel 1** muestra geometría incoherente; con `Original` no ocurre (PresentEarly no
  influye). **Depende de desacoplar la lógica del juego del render** (lógica a 60 Hz) → épica aparte.
  Ver `RETOMAR.md` y `notes/2026-09-22-fps-y-present-early.md`.
- [ ] **2.º mando / 2.º Controller Pak — `MODO VS` no validable (2026-09-27)**: `MODO COMBATE →
  MODO VS` no se pudo validar; el port **solo reporta el puerto 0** de mando
  (`src/subsystems/input.cpp`: `return controller_num == 0` por el arranque del juego), así que no se
  detecta un **2.º mando** (¿o un 2.º **Controller Pak**?). Tarea: reportar un 2.º puerto conectado
  (y el Controller Pak que corresponda) **sin** romper la detección de arranque (que dependía de
  reportar `CONT_NO_RESPONSE_ERROR` en los puertos ausentes). Relacionado: item 11 (Rumble vs
  Controller Pak) y el SEGV del menú multijugador (abajo).
- [ ] **Menú multijugador: SEGV al entrar** (aparcado 2026-09-16): crash host ≈ `FUN_80026f58`;
  rama multijugador **fuera de alcance** (`notes/2026-09-16-fix-menu-b-fisico-atras.md` §Aparcado).
  **No reproducido** en la build Linux actual (2026-09-27, ninguna rama del submenú de batalla);
  confirmar en Windows si reaparece al conectar un 2.º mando.
- [ ] **Docker smoke headless** (`HH_HEADLESS=1` + `rom/`): validar `docker compose` de punta a punta
  (`notes/2026-09-16-limpieza-rutas-referencias-y-pipeline-build.md` §104).
- [ ] **Audio (futuro): desacoplar de los fps** — hoy el audio va atado al tick de 30 Hz, así que un
  hitch puede afectarlo. `PROYECTO.md §7`, `notes/2026-09-15-fix-modulo9-cuelgue-npc-y-handoff.md:68`.
- [ ] **Audio: `osAiGetStatus` real** (hoy devuelve 0 fijo, `librecomp/src/ai.cpp`); completar con el
  estado del DMA **solo si se observa algún síntoma** (`notes/2026-09-17-replay-mode-vi-vis-negativo.md` §5b).
- [ ] **Guardado**: validar Controller Pak contra el emulador; ficheros en disco + **Rumble**.
- [ ] **Builds/empaquetado**: **Steam Deck**; validar `release.yml` end-to-end.
- [ ] **Steam Deck: detección + perfil gráfico por defecto (idea futura, 2026-09-25)**. Al arrancar,
  detectar Deck (`SteamDeck=1`, o DMI Valve + `Jupiter`/`Galileo`; override `HH_DECK=0|1`) y, **si no
  hay perfil marcado**, escribir defaults de `[video]` (`fps=NATIVO` o capado, `msaa=off`, `res=auto`,
  `aspect` 16:10) sin pisar los cambios del usuario. Casi todo reutilizable: `RefreshRate` de RT64 ya
  se **recorta al refresco del panel** (`swapChainRate`), así que `fps=NATIVO` respeta 40/60 Hz de
  SteamOS; `res`/`msaa`/`aspect` ya aplican en vivo y persisten. El **TDP/límites de rendimiento los
  controla SteamOS** (no el port); el perfil solo elige lo nuestro. Futuro: selector `PERFIL GRÁFICO`
  (DECK / CALIDAD / EQUILIBRADO / RENDIMIENTO / BATERÍA) que aplique combinaciones de golpe.
- [ ] **Tarea #3**: mapa overlay→RAM por BizHawk (complementa la medición empírica de bases).
- [ ] **Cadencia/hitches de puertas** (mejora): precarga/decode y enganche a VI
  (`notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`).
- [ ] **Símbolos**: fronteras gruesas (`0xADDR:0xSIZE`) y auto-mid del módulo 12 (datos como código).
- [ ] **Data-as-code**: limpiar sospechosas → permite reevaluar `use_lookup_for_all_function_calls`.
- [ ] **Ramas del toolchain**: publicar `hybrid-heaven-tool` (13 ficheros) para reproducir la
  regeneración (el build no la necesita).
- [ ] **Higiene**: archivar scripts one-off de `tools/analysis/`. **NO borrar** los `*.keep`,
  `keep_syms*.txt`, `module_extras.json`, `recomp/n64recomp_changes/*`.
- [ ] **Sanear menciones a la ROM en docs/notas** (frases cortas del juego en `notes/`).

## Hecho (resumen; detalle en `notes/`)

- [x] **Input ratón vs panel de RT64 (2026-09-23)**: con el Inspector abierto (`HH_DEVELOPER=1`+F1) el
  clic se colaba al juego (L→A). `hh::dev_panel_open()` (publicado en `update_screen`) desactiva el
  mapeo ratón→A/B **solo mientras el panel está abierto**. Pendiente validar en Windows.
  `notes/2026-09-23-input-raton-y-panel-rt64.md`.
- [x] **[Issue #7](https://github.com/hunkstalker/hybrid-heaven-recomp/issues/7) — minimapa
  desanclado al inicio del nivel 2-1 (2026-09-26)**: la salud ya se arregló con el issue #3; el
  **minimapa** se anclaba por identidad `dl:<dirección>#<hash>` y el overlay cambia de dirección por
  escena/capítulo → no casaba. Fix: emparejar los `dl` del mapa por **hash de contenido** (estable)
  en `class_of`. `notes/2026-09-26-fix-minimapa-contenido.md`.
- [x] **High frame rate por defecto (v0.4.0, 2026-09-23)**: `PresentEarly` + `Refresh Rate = Display`
  → presenta al refresco del monitor (~109 fps validado con RTSS), lógica a 30 Hz. Diagnóstico
  `HH_FPS=1`; FPS en pantalla con `HH_DEVELOPER=1`+F1; `HH_GRAPHICS_API`; atajos **F2** aspecto /
  **F3** ventana / **F4** MSAA (**F1** = Inspector). `notes/2026-09-22-fps-y-present-early.md`.
- [x] **Cursor, release `rom/` y README (2026-09-22)**: cursor oculto sobre la ventana (validado en
  Windows); los artefactos de release incluyen `rom/PON_AQUI_LA_ROM.txt`; README con características
  y punto de control de estado. `notes/2026-09-22-cursor-release-rom-readme.md`.
- [x] **Fork de RT64 publicado (2026-09-22)**: `hunkstalker/rt64` (rama `hybrid-heaven` = `a8f0a70`);
  `.gitmodules` y el submódulo `lib/rt64` apuntan al fork. `main` y forks pusheados.
- [x] **Versión `0.3.0` (2026-09-22)**: bump MINOR por las features (widescreen HUD/mapa, cursor,
  release `rom/`). **Release `v0.3.0` publicado.**
- [x] **Ajustes gráficos `[video]` + widescreen (2026-09-21)**: `config.ini [video]` (wm
  borderless/windowed, res auto/nativa/`<n>`/4k/8k, aspect, msaa); ventana a **resolución nativa
  borderless**; atajos **F3** (ventana), **F2** (aspecto), **F4** (MSAA). **Widescreen** con *snap*
  del *scissor* de overscan a full-frame (`src/hooks/dl_snap.cpp`, adaptado de la referencia Phase 07;
  `HH_FULL_FRAME=0` off) → con `aspect=auto`/`expand` (default) el 3D llena la ventana; el HUD/mapa
  **no se desmonta** (queda en la zona 4:3, sin anclar). Validado en Linux y Windows.
  **Pendiente**: anclaje del HUD a los bordes (fase 07b, cosmético).
- [x] **Estéreo L/R corregido (2026-09-21)**: los samples llegaban con L/R invertidos (librecomp
  byte-swapped + puntero crudo); `queue_samples` ahora los des-swapea (`HH_AUDIO_NO_SWAP=1` off).
  Pendiente validar de oído en Windows. `notes/2026-09-21-audio-petardeo-ref-y-plan.md` §8.
- [x] **Limpieza de instrumentación (2026-09-21)**: `[BADMQ]`/`[MQDROP]` gateados tras `HH_DIAG`
  (consola limpia por defecto; fork NMR); `HH_NO_STREAMED_LOADS` eliminado (el hook streamed se
  registra siempre). Se **quedan** (funcionales/opt-in): `requeue_pi=true` (evita cuelgue de PI DMA),
  la sombra `hh_sh_*` (el scheduler lee/escribe ahí los enlaces de hilo) y el watchpoint
  (`HH_WATCH_ADDR`, opt-in).
- [x] **Mando/teclado (2026-09-21)**: mapeo **fijo** (sin remapeo por contexto) — B físico = N64 B
  (atrás/mapa), **X = agacharse**, A=A, Y=C-Down, LB/RB=L/R. **D-pad → stick** por defecto
  (`HH_DPAD_TO_STICK=0` off) → el D-pad navega menús; stick→D-pad también. **Teclado**: WASD=stick,
  H/J/K/L = X/A/B/Y, U/I=L/R, O/P=Z/R, Enter=Start. Validado en Windows.
- [x] **Audio sin petardeo (2026-09-21)**: el juego sobreproducía ~5–6% (modelo FIFO) → cola hasta el
  watermark → descartes. Fix (modelo de la referencia): reportar la **cola SDL real − headroom**
  (`HH_AI_HEADROOM_MS`=30); el FIFO sigue con el evento AI. `frames/s≈43.2k`, `drops/s=0`. Validado en
  Windows y Linux. `notes/2026-09-21-audio-petardeo-ref-y-plan.md`.
- [x] **Publicación hecha (2026-09-21)**: CI verde (Linux/Windows) + **Release `v0.1.1`** publicado,
  con el repo público sin datos del juego y el `RecompiledFuncs` traído del repo privado de secretos
  (ADR 0009). Etapa ELF/splat y M4c validados en Windows.
- [x] **Vía de recompilación ELF/splat (ADR 0011), M0–M5** + **entrada al CaC validada en Windows
  (2026-09-21)**: START → menú → GAME START → gameplay, primer NPC, cajas, **primer CaC**, ~30 min
  hasta el **6º combate** sin cuelgues; **mando** y **guardado/carga** correctos.
- [x] **Estructura/higiene (M5)**: port en la raíz (`src/{platform,hooks,subsystems}`), `recomp/tools/`,
  intermedios → `build/recomp/`, vía Ghidra → `legacy/`, `config/`→`recomp/`, `work/` fuera del repo
  (scratch gitignored), purga `HH_*`, docs vivas + créditos.
- [x] **Teardown SEGV (M4c) RESUELTO** (Linux + Windows): el runtime liberaba RDRAM y el planificador
  seguía despachando hilos al salir; fix en el fork NMR (no liberar RDRAM + parar el planificador).
  `notes/2026-09-21-m4c-teardown-segv.md`.
- [x] **CI con el C recompilado (ADR 0009)**: repo privado de secretos + PAT
  (`notes/2026-09-21-ci-recompilado-desde-repo-privado.md`).
- [x] **Submódulos** `lib/{N64ModernRuntime,rt64}` publicados (forks propios; ADR 0010).
- [x] Arranque completo, gameplay, menús, combate y cinemáticas en Windows con mando Xbox.
- [x] Guardado en cápsula (Controller Pak) validado (`osPfsFindFile`→5).
- [x] Audio `aspMain` del ROM recompilado a 43200 Hz; perfiles de mando por contexto.
- [x] Fase B (ADR 0007): cache de assets + loader LZKN64 nativo.
- [x] Rendimiento: `get_function` sin `getenv` por llamada → stalls de 1-4 s a 0 y 30 ticks/s.
- [x] Replay fiel (`HH_REPLAY_MODE=vi`); build reproducible + CI/Releases (ADR 0005).

## Documentos de detalle (no duplicar)

`PROYECTO.md` · `docs/README.md` (visión) · `docs/architecture.md` · `docs/adr/` · `docs/workflows.md`
· `notes/2026-09-1*.md`.
