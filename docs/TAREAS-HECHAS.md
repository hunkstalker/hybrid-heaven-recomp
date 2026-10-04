# TAREAS HECHAS — Hybrid Heaven: Recompiled

> **Archivo de tareas completadas** (extraído de `TODO.md` para mantenerlo corto). Es un resumen
> navegable; el detalle/evidencia está en `notes/` y `docs/`. No se edita para "actualizar": si algo se
> reabre, vuelve a `TODO.md`.

## FPS / interpolación (2026-10-02 … 2026-10-04)

- **Sesgado de cámara — RESUELTO y validado en Windows (2026-10-04, `46b3f0d`).** *Shearing* de 1 frame
  en los cortes de cámara (p. ej. FIGHT). La cámara va horneada en la matriz de **vista/proyección**;
  fix **port-only** en `src/hooks/model_tagging.cpp` (`emitter_wrap()` → `gEXMatrixGroup` de PROYECCIÓN
  con id de cámara + generación) → RT64 no empareja el viewProj en el corte → snap del encuadre. Se
  **descartó** la vía core (materializar pass 1 a través de la frontera de workload: asocia por tiempo,
  rompe el HUD). `notes/2026-10-04-fps-core-frontera-workload-y-pasada2.md`.

## 2026-10-02 (sesión de bugs)

- **#13 minimapa desanclado al cambiar de Área — HECHO y VALIDADO en Windows (todos los niveles).**
  `class_of` anclaba el mapa por **hash de contenido** (`0xbbb8c0ba`/`0x1427da33`), que cambia por
  capítulo → `kAuto`. Fix **estructural**: eliminados del `class_of` los 2 hashes `dl:` y el fill
  posicional; el minimapa se ancla por su **panel** (`right_panel_box`/`right_panel_scissor`) en
  `hud_rewrite.cpp`. **ADR 0015**; `notes/2026-10-02-fix-minimapa-estructural-issue13.md`.
- **#14 crash del ataque a distancia/veneno — HECHO y VALIDADO en Windows.** Era un **abort** de
  `switch_error` en `func_8035A3D8`: N64Recomp **truncaba su jump table** (8→2) al topar con un destino
  que es **inicio de otra función**. Fix general del recompilador (`toolchain/src/N64Recomp`:
  `analysis.cpp` + `recompilation.cpp`, tail-call); **11 funciones / 73 entradas**. Parche:
  `recomp/n64recomp_changes/2026-10-02-jump-table-cross-function.patch`;
  `notes/2026-10-02-fix-jumptable-recompilador-issue14.md`.
- **Textos que desaparecían al GUARDAR — HECHO y VALIDADO en Windows.** `hh_leave_capsule` no
  desactivaba la categoría FILE-SELECT (`g_file_select_active`) → el hook de composición saltaba todo
  el texto. Fix: `set_file_select_active(false)`.
  `notes/2026-10-02-fix-textos-desaparecen-al-guardar.md`.
- **Número de Área del título al cargar — HECHO y VALIDADO en Windows.** Salía equivocado según la
  parte (1-2 → Área 2; 6-1 → Área 1); se indexaba `D_801CCAE0` con `func_8013EA54` (valor que avanza por
  parte). Fix: derivar de `[0x801BBBF4]` con `area_sub_from_value`.
  `notes/2026-10-02-fix-titulo-area-numero.md`.
- **VIBRACIÓN ↔ Controller Pak.** Con `VIBRACIÓN = SÍ` no se guardaba/cargaba: hook `func_80002BE0`
  (7→0) + PFS de un solo `.pak` (canal 0..3) + vibración global.
  `notes/2026-10-02-desacoplo-vibracion-controller-pak.md`.
- **Rótulo `AREA` del título traducido** (`ÁREA`/`ÀREA`/`ZONE`/`BEREICH`): clave `AREA` de
  `assets/lang/*.txt`, ancho en codepoints. `notes/2026-10-02-titulo-area-rotulo-traducido.md`.
- **Acentos/`¿`/`¡` en los mensajes del overlay (cápsula).** Franja de acentos en el atlas
  (`font.cpp`, `hh::kGameGlyphs` = color4 EU + compuestos base+marca), fuera el `?` girado y CP437.
  `notes/2026-10-02-tildes-y-signos-en-mensajes.md`.
- **Transición del título del Área: fundido y hold** (fade por tiempo, fade-out por hilo de render,
  hold, telón opaco). `notes/2026-10-02-transicion-titulo-fade.md`.
- **Artefactos en el diálogo del ordenador (acentos vs `value` nativo) — HECHO y VALIDADO en Windows.**
  La ventana usa **color3** (12×13, `stride=78`) con un glifo nativo `value=200`; `hh_accent_bfe4`
  interceptaba por `value` a secas y escribía 32 B de color0 8×8 (corrupción). Fix: **donante ASCII
  (`@`) + marca de origen + guarda de `stride`** en `text_glyphs.cpp` (`gen_accent_glyphs.py` deja de
  inventar `value`). `notes/2026-10-02-fix-glifos-acentos-colision-value-color3.md`.

## Editor de partida, stats y EXTRAS (2026-09-27 … 2026-09-28)

- **`MODO HEAVEN` (EXTRAS) — modo GLOBAL persistente, validado en Windows (2026-09-28).** No depende
  de la partida ni del editor (persiste en `config.ini [extras].heaven`). Aplica al personaje vivo
  `0x8017DC40` **ATRIBUTOS/ESTADO 99 + 86 habilidades** (`apply_heaven_runtime` vía hooks
  `func_80144E68`/`func_80152240`), daño 0 al PJ (`func_80232D08`) e items que no se gastan
  (`func_8013D520`). Detalle: `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.
- **`VENTAJA` (EXTRAS) — validado en Windows (2026-09-28).** Selector NO/SÍ, 6 idiomas, persistente
  (`[extras].advantage`); fuerza `0x801BCC24 = 2` (POWER al máximo al empezar). Independiente de MODO
  HEAVEN.
- **`PODER ∞` / `RESISTENCIA ∞` (EXTRAS) — validado en Windows (2026-09-28).** Dos selectores NO/SÍ
  (símbolo `∞`) persistentes (`[extras].infinite_power`/`infinite_stamina`); `hh_battle_frame_hook`
  pinnea `actual = max` cada frame (PODER `0x801BC042←0x801BC040`, RESISTENCIA `0x801BC046←0x801BC044`).
- **Daño FUERA de combate (robots) — validado en Windows (2026-09-28).** `func_80379F04` hace
  `HP -= *(s16*)0x80388A68`; hook pone el scratch a 0 con HEAVEN.
- **Centrar `GRÁFICOS` y `CONTROLES`** en el overlay (`custom_layout`; `scroll_cap5` solo para
  EXTRAS/CONTROLES/editor).
- **`EDICIÓN DE PARTIDA` (editor de save) — v3 sobre el `.pak` (2026-09-27/28).** Menú en `EXTRAS`
  (CARGAR/GUARDAR PARTIDA, PROGRESO, NIVEL, HABILIDADES, ESTADO, ITEMS, ATRIBUTOS); `GUARDAR` escribe
  el `.pak` con offsets/checksum (recarga `g_pak`); formato real del slot documentado; **escalado
  parte→stats RESUELTO** (`func_80376D48`, 6 atributos con tablas; reward = fila del enemigo derrotado
  `0x8023C940` por `a0+0x36`; tope por dificultad `func_80376D10` 79/89/99); **word-swap 32-bit** del
  save corregido (`swap16=r^2`, `swap8=r^3`); pantalla **`SIM. COMBATE`** con la fórmula exacta.
  `notes/2026-09-27-f-editor-partida-v3-y-hallazgos.md`,
  `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md`,
  `notes/2026-09-28-logica-juego-tecnicas-items-y-stats.md`,
  `notes/2026-09-28-stats-recompute-correccion.md`, `docs/stats-partes.md`.

## Menú de cargar/guardar y editor (2026-09-27 … 2026-10-01)

- **Tareas pequeñas de menú (2026-10-01).** `DATA EDIT` quitado de `MODO COMBATE`; **letra de
  dificultad** en la caja del slot (byte `+7` = `0x801BBC0D`, columna fija); `AREA/LEVEL/TIME`
  traducidos (clave `TIME`); `ULTIMATE` fr corregido y `NO DATA` fr a 2 líneas. Validado en Windows.
  `notes/2026-10-01-slot-dificultad-y-traduccion.md`.
- **i18n — unificar traducciones en `assets/lang/*.txt` (Opción A) (2026-10-01).** `hh::text::translate()`
  único punto, clave = inglés, `en` = identidad; borrados `kMenuTr`/`kAreaNames`/`kEsDefaults`; guard
  `tools/text/check_translations.py`; **ADR 0014**. Validado en Windows.
  `notes/2026-10-01-i18n-unificar-traducciones-plan.md`.
- **Pulido de menú/vídeo (2026-10-01).** `CONTINUAR` gris sin partidas; `SALIDA` stepper `< ESTÉREO >`;
  arreglo pantalla completa ↔ ventana. `notes/2026-10-01-menu-continuar-salida-fullscreen.md`.
- **TÍTULO DEL ÁREA al cargar partida (commit `874b9f6`, 2026-10-01).** Overlay propio (telón negro +
  `AREA N` fuente del juego + nombre Work Sans SemiBold incrustada), traducido `en/es/ca/fr/de` (`ja`
  nativo), calibrado 1:1 y con salto de línea en 4:3. `notes/2026-10-01-titulo-area-carga.md` y
  `...-calibracion.md`.
- **LÓGICA DE GUARDADO en la cápsula (`DATA SAVE`) (2026-09-30).** Fases `SavePhase`, `save_live()`
  (serializa globals vivos), checksums + cabecera/trailer, AREA/TIME correctos. Validado en Windows.
  `notes/2026-09-30-save-capsule-logica.md`.
- **BORRAR slots desde la cápsula (2026-09-30/10-01).** `X` sobre slot → `Remove play data?`; `NEW GAME`
  no se borra. `notes/2026-09-30-save-capsule-logica.md` §8ter.
- **Higiene de `menu.cpp` (guardado + editor) (2026-10-01).** Variables unificadas; "slot libre" con
  `first_free_game_slot()`; retirado código muerto. `notes/2026-10-01-menu-save-edit-higiene.md`.
- **UI de CARGA en `CONTINUAR` (2026-10-01).** Fases `LoadPhase`; **A** carga directo, **X** borra,
  **B** vuelve al título; carga real replicando la rama de ÉXITO nativa. Validado en Windows.
  `notes/2026-10-01-cargar-partida-continuar.md`.
- **`DEBUG NIVELES` + `IR A ÁREA` (EXTRAS) (2026-09-29).** Campo del mapa = `0x564` (u16 LE); ciclo
  F5/F6 ±1, RePág/AvPág ±10, Inicio=0, `skip_indices.txt`; `IR A ÁREA` teletransporta. Validado.
  Documento maestro: `notes/2026-09-29-editor-area-parte-plan.md`.
- **Menú propio de CARGAR/GUARDAR, `.pak` de 74 slots (2026-09-29/30).** PFS virtual ampliado
  (`PAK_SIZE=0x40000`), 45 partidas + 29 plantillas + trailer de metadatos; migración del `.pak` de 4
  slots. **ADR 0013**. UI 1:1 del DATA LOAD/SAVE.
- **Tipografías del DATA LOAD (2026-09-29/30).** Mapeo color3 (título) / color4 (mensaje) / color0
  (filas); cableado en `font.h/cpp`; maqueta 1:1 (geometría) Δ<1 px.
  `notes/2026-09-30-tipografias-data-load-hallazgos.md`, `notes/2026-09-30-data-load-maqueta-1a1.md`.
- **`MODO HEAVEN` (EXTRAS) (2026-09-28).** Modo global persistente: ATRIBUTOS/ESTADO 99 + 86
  habilidades + invulnerabilidad combate/campo + items no consumibles. Validado en Windows.
- **`VENTAJA` (EXTRAS) (2026-09-28).** Fuerza `0x801BCC24 = 2` (POWER máximo al empezar); persistente.
- **`PODER ∞` / `RESISTENCIA ∞` (EXTRAS) (2026-09-28).** Pinnea gauges cada frame; no se gastan.
- **Daño FUERA de combate (robots) (2026-09-28).** Hook anula el scratch de daño con HEAVEN.
- **Centrar `GRÁFICOS` y `CONTROLES`** en el overlay (`custom_layout`, `scroll_cap5`).
- **Escalado parte→stats del editor (2026-09-28).** `func_80376D48`; fórmula exacta y SIM. COMBATE.
  `docs/stats-partes.md`, `notes/2026-09-28-stats-recompute-correccion.md`.
- **Release sin volcados (v0.5.1) (2026-09-27).** El `.exe` release solo deja `hh.log`; el resto
  opt-in (`HH_DIAG`/`HH_CRASH_LOG`/`HH_PAKLOG`). `notes/2026-09-27-d-release-sin-volcados.md`.
- **MODO COMBATE recreado con menú propio (2026-09-27).** `MODO VS` / `COMBATE DE CRIATURAS` /
  `EDITAR DATOS`; despacho nativo cableado. Validado en Windows. `notes/2026-09-27-battle-mode-recon.md`.
- **Traducción del MENÚ al JAPONÉS (kana) (2026-09-27).** `color0` JP byte-idéntico al US; mapping
  `include/hh/jp_kana.h`. Validado en Windows.
- **Tildes a +0.5 px (2026-09-27)** y **sombra de flecha de cursor** (`append_native_cursor`).
- **Logos de intro HD KONAMI/KCEO + código Konami (2026-09-26).** `EXTRAS` con toggles persistidos.
- **Demos de inactividad / attract al ritmo original (2026-09-26).**
- **Menú multilingüe + acentos + idiomas (2026-09-25/26).** `IDIOMA` en AJUSTES, idioma del sistema,
  persistencia `[lang]`. **ADR 0012**. Validado en Windows.
- **`empezar partida` / `dificultad` / `continuar` en el menú (2026-09-26).** Despacho nativo.
- **Bugs del menú overlay A2 (2026-09-24).** Bearing, tercer set de etiquetas, cierre instantáneo.
- **Menú A2 — overlay moderno (render hook RT64) + opciones PC (2026-09-23/25).** `hh_menu → hh_font →
  backend_game`; GRÁFICOS/DEBUG/AUDIO aplican en vivo y persisten. **ADR 0008**. Validado en Windows.
- **FPS en pantalla (2026-09-26).** `MOSTRAR FPS` en menú DEBUG; `[video].showfps`.

## Widescreen, issues y bugs (v0.4.x)

- **Widescreen: anclaje del HUD/mapa (fase 07b) (2026-09-26).** Izquierda (radar, POWER/STAMINA, disco
  radial, combo, stamina gastada) y derecha (minimapa). Issues **#3** y **#7** cerrados y validados.
  `notes/2026-09-21-anclaje-hud-widescreen-radar.md`, `...-fase07b.md`,
  `notes/2026-09-25-f-hud-combate-contenido.md`, `notes/2026-09-26-fix-minimapa-contenido.md`.
- **High frame rate por defecto (v0.4.0, 2026-09-23).** `PresentEarly` + `Refresh Rate = Display`
  (~109 fps, lógica 30 Hz); F2/F3/F4 atajos; F1 Inspector. `notes/2026-09-22-fps-y-present-early.md`.
- **Input ratón vs panel de RT64 (2026-09-23).** `hh::dev_panel_open()` desactiva ratón→A/B.
- **Cursor oculto, release `rom/` y README (2026-09-22).** `notes/2026-09-22-cursor-release-rom-readme.md`.
- **Fork de RT64 publicado (2026-09-22).** `hunkstalker/rt64` rama `hybrid-heaven`.
- **Versión `0.3.0` (2026-09-22)** con widescreen HUD/mapa, cursor y release `rom/`. Publicada.
- **Ajustes gráficos `[video]` + widescreen (2026-09-21).** `config.ini [video]`; snap del scissor de
  overscan (`dl_snap.cpp`); validado en Linux y Windows.
- **Estéreo L/R corregido (2026-09-21).** `queue_samples` des-swapea samples.
- **Limpieza de instrumentación (2026-09-21).** `[BADMQ]`/`[MQDROP]` tras `HH_DIAG`.
- **Mando/teclado (2026-09-21).** Mapeo fijo; D-pad→stick por defecto; teclado WASD/HJKL. Validado.
- **Audio sin petardeo (2026-09-21).** Cola SDL real − headroom; `drops/s=0`.
  `notes/2026-09-21-audio-petardeo-ref-y-plan.md`.

## Base del port (arranque, ELF/splat, toolchain)

- **Bug: cambiar de idioma aceleraba el juego (30→60) (2026-09-25).** `hh_trans_reapply_language`
  reescribía el módulo entero; fix: re-aplicar solo bytes con testigo `written`.
- **Publicación CI/releases (2026-09-21).** Release `v0.1.1`; `RecompiledFuncs` desde repo privado de
  secretos (ADR 0009).
- **Vía de recompilación ELF/splat (ADR 0011), M0–M5.** Entrada al CaC validada en Windows (START →
  menú → gameplay, primer NPC, primer CaC, ~30 min sin cuelgues).
- **Teardown SEGV (M4c) RESUELTO.** Fix en fork NMR (no liberar RDRAM + parar el planificador).
- **Estructura/higiene (M5).** Port en raíz, `recomp/tools/`, intermedios en `build/recomp/`.
- **Submódulos `lib/{N64ModernRuntime,rt64}` publicados (ADR 0010).**
- **Arranque completo, gameplay, menús, combate y cinemáticas** en Windows con mando Xbox.
- **Guardado en cápsula (Controller Pak) validado** (`osPfsFindFile`→5).
- **Audio `aspMain` del ROM recompilado a 43200 Hz**; perfiles de mando por contexto.
- **Fase B (ADR 0007).** Cache de assets + loader LZKN64 nativo.
- **Rendimiento.** `get_function` sin `getenv` por llamada → stalls eliminados, 30 ticks/s.
- **Replay fiel (`HH_REPLAY_MODE=vi`)**; build reproducible + CI/Releases (ADR 0005).

## Issues cerrados

- **#3** HUD de combate desanclado a partir del 2.º combate (v0.4.1–v0.4.3).
- **#7** minimapa desanclado al inicio del 2-1 (v0.4.4) — anclaje por hash de contenido.
