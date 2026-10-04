# PROYECTO — Hybrid Heaven: Recompiled (contexto maestro)

> **Fuente de verdad del contexto y el estado.** Mantenerlo corto (≈1-2 pantallas).
> Tareas → `TODO.md`. Arquitectura y decisiones → `docs/architecture.md` + `docs/adr/`.
> Histórico y evidencia → `notes/` (no editar). Última actualización: **2026-10-04**.

**Estado (2026-10-04)**: `main` = **v0.6.2** (release publicada) + **fix de input** (2026-10-04,
**validado en Windows**). Dos síntomas: (1) al confirmar `CONTINUAR` con A/START aún pulsada se cargaba
el **primer slot** sin ver el `DATA LOAD`; (2) **borrar un slot con el botón X del mando no funcionaba**
(solo la tecla H). Causa: lectura de input **inconsistente** (`read_input_button()` no incluye el mando;
los flujos leían acciones en estado mantenido). Fix: **una sola vía** para las acciones
(`hh_input_action_edges()`: teclado **+ ratón + mando + inyección**) con **flanco estricto con rearme**
(mantener no repite) y **auto-repeat solo para direcciones**; seed en el hook de apertura; retirados los
bloqueos por ms. Detalle: `RETOMAR.md`, `notes/2026-10-04-fix-input-flanco-botones-accion.md`.
**En paralelo:** interpolación / desbloquear FPS en la rama **`fps-interpolacion-tagging`** (tagging por
hook; sin validar gameplay).

## 1. Objetivo

Port nativo a PC de **Hybrid Heaven** (N64, Konami/KCEO, 1999, proyecto interno **RZ011**) por
**recompilación estática** (N64Recomp + RT64 + N64ModernRuntime), **sin emulador**, leyendo la ROM
del usuario. Sub-objetivo obligatorio: **extraer y traducir todo el texto**. Plataformas:
**Windows + Linux + Steam Deck** (mismo código). Legal: no se distribuyen ROM ni assets.

## 2. Entorno

| Ítem | Valor |
|---|---|
| Proyecto | raíz de este repo |
| Toolchain | gcc/g++ 15, cmake 4.2, ninja, SDL2, LLVM MIPS (`llvm-mc`/`ld.lld`) + splat/spimdisasm; Ghidra + N64LoaderWV solo vía legacy |
| Repos de referencia | N64Recomp, N64ModernRuntime, RT64, Zelda64Recomp y un port de Konami coetáneo (`toolchain/`, gitignored) |
| Derivados | `work/` y `toolchain/` gitignored (datos derivados, Ghidra, builds, artefactos) |

## 3. Arquitectura (resumen)

Stack: **N64Recomp** (MIPS→C) + **N64ModernRuntime** (`ultramodern`+`librecomp`) + **RT64** +
SDL2. Microcode gfx **F3DEX2 fifo 2.06** (RT64 lo soporta nativo). Audio: **`aspMain` del ROM**
recompilado con RSPRecomp (`build/recomp/rsp/hh_aspMain.cpp`, generado), reproducción a **43200 Hz** (720 frames/VI) con
feedback de cola; dispositivo WASAPI vía SDL. Release por defecto (Debug caía a 30 fps).

**Modelo unificado: imagen plana + módulos.** El boot es una imagen de código plana; el juego
descomprime módulos de código de la ROM a RAM y los ejecuta vía `trans`. → `docs/architecture.md`.

Decisiones de fondo pendientes: `docs/adr/0001-modelo-de-modulos.md`.

## 4. Hallazgos técnicos clave del binario

- Formato **z64 BE**, entry `0x80000400`, cartucho 16 MB.
- Símbolos de debug del original (paths `/game/source/*.c`, 62 fuentes) → anclas de análisis.
- **Compresión**: tabla **Nisitenma-Ichigo** + **LZKN64** (`tools/rommy.py`, `tools/lzkn64`).
  El código plano NO está comprimido; se comprimen assets y módulos. Variantes **LZSS 5/7** del
  `trans` por caracterizar.
- Carga de módulos por el loader `trans` (`seg_RomDecode_sep`); directorio `id→base` en
  `0x8008DFC0`. Mapa dinámico = tarea #3 (BizHawk).
- **Textos/idiomas**: el texto USA es **ASCII terminado en NUL en campos de ancho fijo** (el
  "encoding custom" era en realidad los flujos LZKN64; el motor usa **EUC-JP** y los acentos PAL son
  gaiji de 2 bytes). Sustitución en runtime vía el loader `trans` (`src/subsystems/text.cpp`).
  **Sistema de idiomas A1 (2026-09-23)**: lista `en/es/ca/fr/de/ja` + mods, selección/ciclo (F5),
  **cambio en vivo** (re-aplicación a módulos cargados) y persistencia en `config.ini [lang]`.
  Anclas: `WASHINGTON D.C.` @`0x061CD7A`, `PLEASE SELECT` @`0x05FB543`, `BATTLE` @`0x05FAF4C`,
  `ITEM...WEAPON` @`0x06C33AF`; módulo título/menú = Nisitenma idx 23. Detalle:
  `notes/2026-09-23-a1-sistema-idiomas-y-cambio-en-vivo.md`,
  `notes/2026-09-23-texto-euc-jp-y-glifos-pal.md`.
  **A2 (overlay, 2026-09-23)**: el intento por **GBI** (inyectar `G_EX_TEXRECT_V1` en la DL del juego,
  patrón `hud_rewrite`) **falló** (RT64 compone el framebuffer del juego; el overlay no llega al
  swapchain presentado) y **se retiró**. Vía nueva: **render hook de RT64** (`SetRenderHooks`) +
  **plume** (como Goemon/recompui), dibujando encima del frame. `notes/2026-09-23-a2-overlay-primer-paso.md`.
  **`hh_menu` (2026-09-24)**: modelo del árbol + dibujo 1:1 con la fuente del juego + navegación
  básica, y **menú nativo oculto por defecto** (el juego tiene **varias copias** de las etiquetas del
  menú; el filtro cubría solo una). Diseño y estado: **`docs/menu.md`**; técnica:
  **`docs/architecture.md` §7**. `notes/2026-09-24-a2-ocultar-menu-nativo-dos-tablas.md`.
  **Multi-idioma + acentos (2026-09-25 / 2026-09-27)**: acentos del menú = **letra base `color0` +
  marca** (no se deforma; `tools/text/menu_marks.py`); etiquetas localizadas **en/es/ca/fr/de/ja**
  (JA en **kana**: el `color0` del ROM JP es idéntico al US, mapping en `include/hh/jp_kana.h`;
   `tools/text/extract_jp_kana.py`) con `IDIOMA` funcional (persiste `[lang]`) e **idioma del sistema**
   por defecto (fallback inglés); fuente in-game **8×12 `color4`** preparada. **ADR 0012**;
   `docs/menu.md §Idiomas`.
   **Fuente única de traducciones (2026-10-01, validado en Windows; ADR 0014)**: TODAS las
   traducciones (UI del port + texto nativo) viven en `assets/lang/<code>.txt` con **clave = inglés**;
   `en` = identidad. Único punto: `hh::text::translate()` (`menu::localized` delega); se eliminan
   `kMenuTr`/`kEsDefaults` (editar un `.txt` no requiere recompilar). Guard
   `tools/text/check_translations.py`; migración `tools/text/migrate_menu_tr.py`.
- Herramientas: `tools/rommy.py` (Nisitenma US/EU, manifests en `notes/`), `tools/lzkn64`,
  `tools/text/extract_strings.py` (ROM → cadenas).

## 5. Estado de avance

**Estado actual (2026-09-27)**: **`main` = v0.5.0** (publicada; v0.4.1–v0.4.4 siguen vigentes). Incluye
el **menú inicial propio** (ver abajo) y, desde v0.4.4, los **issues #3 y #7 CERRADOS y validados en
Windows** — el HUD de combate y el **minimapa** se anclan enteros en widescreen en todas las
escenas/capítulos: POWER/STAMINA por hash de contenido (`d820d8e`), disco plateado del radial por
hash+caja `27,19,59,51`, barra de combo (4 `G_FILLRECT` en `y=28..30`) y **stamina gastada**
(`G_FILLRECT` en `y=34..38`) por posición, y **minimapa** por hash de contenido de su lista.
Herramienta: **F7 = captura pareada** (traza + imagen).
`notes/2026-09-25-f-hud-combate-contenido.md` · `notes/2026-09-26-fix-minimapa-contenido.md`.
**`menu-nativo` (mergeada en `main` → **v0.5.0**, 2026-09-27)**: menú inicial + idiomas
HECHOS (árbol, navegación, acciones video/audio, SFX, acentos por letra+marca,
EN/ES/CA/FR/DE/**JA** + idioma del sistema); **BUG del reapply de idioma resuelto**
(`notes/2026-09-25-e-fix-reapply-idioma.md`); **validado en Windows (2026-09-26, tras el merge con
`main`)**; **JA del menú (kana), tildes +0.5 px y `CÁMARA/APUNTADO LIBRE` ocultos, validados en Windows
(2026-09-27)**. Merge `menu-nativo` → `main` = **fast-forward** → **release v0.5.0** (MINOR).
**`EMPEZAR PARTIDA` validado en Windows (2026-09-26)** y
**`DIFICULTAD`** implementada (escritura de `0x801BBC0D`; efecto por comprobar jugando). **Logos de
intro HD KONAMI/KCEO + código Konami** implementados y **validados en Windows (2026-09-26)** (assets en
`assets/logos/`, fundido por grupo + clave de blanco, preload, skip START, `EXTRAS` con toggles
`MANTENER EXTRAS`/`LOGOS ORIGINALES` persistidos, attract al ritmo original y "Press Start" centrado);
queda ampliar el contenido de la pantalla `EXTRAS`. Próximas tareas del menú en `TODO.md`
(contenido de `EXTRAS`, fallos visuales). Detalle: `notes/2026-09-26-i-logos-intro-hd-y-konami-impl.md`.
**`v0.5.1` (2026-09-27, en curso)**: release limpia — el `.exe` **solo** deja `hh.log`; los volcados
(`hh_audio/tick/slow/state/slice/hang/flag/crash/pak`) pasan a **opt-in** (`HH_DIAG`/`HH_CRASH_LOG`/
`HH_PAKLOG`). Próxima feature: **editor de partida** (`EDICIÓN DE PARTIDA`; ver `RETOMAR.md`).
**Rama `menu-edicion-partida` (2026-09-28, sin pushear; `main` = v0.5.0)**: **editor de partida**
rediseñado (ATRIBUTOS/ESTADO como niveles de atributo/parte, HABILIDADES `RESET`, ITEMS en mayúsculas,
ELIMINAR); **MODO HEAVEN** convertido en **modo global persistente** (ATRIBUTOS/ESTADO 99 + 86
habilidades + invulnerabilidad combate/campo + items no consumibles); **`VENTAJA`** (back attack) y
**`PODER ∞`/`RESISTENCIA ∞`** como toggles de EXTRAS persistentes (`∞` dibujado vectorial); daño de
campo (robots) anulado; **stepper `< valor >`** para ANTIALIASING; GRÁFICOS/CONTROLES centrados. Todo
**validado en Windows**. Detalle: `RETOMAR.md`, `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.
**Sesión 2026-09-29**: RESUELTO el **mapeo de Áreas-Partes/puntos de carga**: campo de mapa
**`0x564` (u16 LE)** del slot, `idx=(area-1)*10` para los `N-0` (1-0=0 … 9-0=90; 7-0=75); **`EXTRAS >
DEBUG NIVELES`** (ciclo de escenas F5/F6 + indicador `idx=` + `skip_indices.txt` editable) y **`EXTRAS >
IR A ÁREA`** (teletransporte a `N-0` con plantilla). Documento maestro:
**`notes/2026-09-29-editor-area-parte-plan.md`**.
**Menú propio de cargar/guardar (Fases 0 y 1, 2026-09-29, rama `menu-carga-guardado-partida`)**: PFS
virtual ampliado (`PAK_SIZE=0x40000`, fork NMR) y `.pak` de **74 slots** (`hh::save`) con reparto **45
partidas + 29 plantillas** y **trailer de metadatos**; `func_801423C8` carga slots altos; migración de
`.pak` de 4 slots verificada offline. **Pendiente validar en Windows**. Decisión: **ADR 0013**; notas
`notes/2026-09-29-menu-cargar-guardar-fase0-hallazgos.md` y `...-fase1-formato-pak.md`.
**UI propia del `DATA SAVE` en la cápsula (2026-09-30)**: vía de guardado enganchada (`0x803771A4` /
`0x80377140`), copia de la UI de cargar con prompt `Save play data? Yes/No`, lista `NEW GAME` + slots con
datos, valores alineados a la derecha, puntuación desde la ROM, SFX y **ocultado del nativo con F8**
(fix del vaciado `func_80142570`). **Lógica de guardado HECHA y VALIDADA en Windows (2026-09-30)**:
fases `hh::menu::SavePhase`, confirmación `Saving current play data here.` → `hh::save::save_live()`
(serializa los globals vivos con `func_80141F28` y persiste con `hh::save`), `Save completed.` + flecha
↓, salida nativa, **AREA 1-1** y **TIME** correctos, y reinicio del flujo al reentrar. **Próximo**:
terminar el ciclo de CARGA desde `CONTINUAR` (handoff en `notes/2026-09-30-save-capsule-logica.md` §9).
Notas: `notes/2026-09-30-save-capsule-logica.md` y `notes/2026-09-30-save-data-ui-retoques.md`.
**Higiene/correcciones de `menu.cpp` en guardado + editor (2026-10-01, VALIDADO en Windows)**:
`g_save_target_slot`/`g_save_delete_slot` unificadas; "slot libre" del editor alineado con la cápsula
(`first_free_game_slot`); retirado el código muerto `load_game_row_present`. Sin cambio de UI.
Nota: `notes/2026-10-01-menu-save-edit-higiene.md`.
**UI de CARGA en `CONTINUAR` (2026-10-01, VALIDADA en Windows)**: flujo propio por fases
(`hh::menu::LoadPhase`), **A carga directo**, **X borra**, **B vuelve al título**; **carga real**
(replica la rama de ÉXITO nativa → transición con el índice de escena del slot); transición de entrada
sin parpadeo ni superposición al título, y mensajes Controller/Rumble Pak ocultos (hook
`func_800179B0`). Textos: mensaje de `Browse` con bindings
(`Select play data to be loaded pressing A/J or X/H to remove.`). Nota:
`notes/2026-10-01-cargar-partida-continuar.md`.
**Título del Área al cargar partida (2026-10-01, rama `menu-carga-guardado-partida`)**: el nombre del
Área es un **gráfico nativo intraducible**; el port lo pinta con **overlay propio** (telón negro +
`AREA N` con la fuente del juego + nombre en **Work Sans SemiBold**), traducido en **EN/ES/CA/FR/DE**
(`ja` nativo), colgado de la cadena nativa (fade/espera/transición) y con **candado anti-parpadeo**.
**Calibrado 1:1** con el original (ancho/alto/peso/métrica) y **salto de línea automático** en 4:3 para
los nombres largos (centrado; en 16:9 no cambia). **Validado en Windows (2026-10-01)**.
Notas: `notes/2026-10-01-titulo-area-carga.md` y `notes/2026-10-01-titulo-area-calibracion.md`.
**i18n — unificar traducciones (HECHO, 2026-10-01; validado en Windows)**: **una sola fuente**
(`assets/lang/*.txt`, clave inglés) con `hh::text::translate()` como único punto y `menu::localized`
delegando; borrados `kMenuTr`/`kEsDefaults`; el jugador edita un `.txt` sin recompilar. **ADR 0014**;
estado + validación: `notes/2026-10-01-i18n-unificar-traducciones-plan.md` §8.
**Pulido de menú/vídeo (HECHO, 2026-10-01; validado en Windows)**: `CONTINUAR` **gris y no
seleccionable** sin partidas en el `.pak`; `SONIDO -> SALIDA` como **stepper `< ESTÉREO >`**; **arreglo
del paso pantalla completa ↔ ventana** (`P. COMPLETA`/F3), fijando en RT64 el rect de ventana y
sincronizando su estado (`rt64_render_context.cpp`). Nota:
`notes/2026-10-01-menu-continuar-salida-fullscreen.md`.
**Tareas pequeñas de menú (HECHO, 2026-10-01; validado en Windows)**: `DATA EDIT` **quitado** de `MODO
COMBATE`; **letra de dificultad** a la izquierda del nivel en la caja del slot (1.ª letra de la
traducción; dato en el byte `+7` del registro = `0x801BBC0D`, `save::meta_difficulty` + persistencia en
`save_live`), en **columna fija** (no se mueve con 2/3 dígitos, el 100 no se sale); **`AREA/LEVEL/TIME`
traducidos** (clave `TIME`); `ULTIMATE` fr corregido a `ULTIME` y `NO DATA` fr a 2 líneas
(`PAS DE\nDONNÉES`). Nota: `notes/2026-10-01-slot-dificultad-y-traduccion.md`.
**VIBRACIÓN ↔ Controller Pak (HECHO y VALIDADO en Windows, 2026-10-02)**: hook de `func_80002BE0`
(7→0) + PFS de **un solo sistema de memoria** (`.pak` en canal 0..3) + vibración **global**. Nota:
`notes/2026-10-02-desacoplo-vibracion-controller-pak.md`.
**#13 minimapa desanclado (HECHO y VALIDADO en Windows en todos los niveles, 2026-10-02)**: se elimina el
anclaje del minimapa por **hash de contenido** (fallaba por área/capítulo, #7/#13) y se ancla por su
**panel** (scissor/fondo negro que no cubre el ancho y cae en la mitad derecha); validado headless sin
over-match y en Windows en todos los niveles. **ADR 0015**; nota
`notes/2026-10-02-fix-minimapa-estructural-issue13.md`.
**#14 ataque a distancia (RESUELTO y validado en Windows, 2026-10-02)**: el crash era un **abort** del
runtime (`switch_error`) porque N64Recomp **truncaba la jump table** de `func_8035A3D8` (8→2 casos) al
topar con un destino que es **inicio de otra función**. Fix **general** del recompilador
(`toolchain/src/N64Recomp`: `analysis.cpp` + `recompilation.cpp`, tail-call), **11 funciones / 73
entradas** corregidas. Parche versionado: `recomp/n64recomp_changes/2026-10-02-jump-table-cross-function.patch`.
Nota: `notes/2026-10-02-fix-jumptable-recompilador-issue14.md`.
**Textos que desaparecían al GUARDAR (RESUELTO y validado en Windows, 2026-10-02)**: al salir de la
cápsula no se desactivaba la categoría FILE-SELECT (`g_file_select_active`) y el hook de composición de
texto saltaba todo el texto (nombres de habilidades). Fix: `set_file_select_active(false)` en
`hh_leave_capsule`. Nota: `notes/2026-10-02-fix-textos-desaparecen-al-guardar.md`.
**Número de Área del título al cargar (RESUELTO y validado en Windows, 2026-10-02)**: salía equivocado
según la **parte** (1-2 → Área 2; 6-1 → Área 1) porque se indexaba `D_801CCAE0` con un valor que avanza
por parte; ahora se deriva de `[0x801BBBF4]`. Nota: `notes/2026-10-02-fix-titulo-area-numero.md`.
**Artefactos en el diálogo del ordenador (RESUELTO y validado en Windows, 2026-10-02)**: la ventana usa
**color3** (12×13, stride 78) con un glifo nativo `value=200`; `hh_accent_bfe4` interceptaba por `value`
a secas y le escribía 32 B de color0 8×8 (corrupción). Fix: **donante ASCII (`@`) + marca de origen +
guarda de stride** (`src/hooks/text_glyphs.cpp`); `gen_accent_glyphs.py` deja de inventar `value`.
Nota: `notes/2026-10-02-fix-glifos-acentos-colision-value-color3.md`.
Pendiente: cablear la fuente in-game 8×12 **por color** (servir el bloque color4/color3) y las
traducciones in-game (DE/FR/JA de las ROMs; ES/CA propias). **High frame rate por defecto** — el port presenta hasta el refresco del monitor
(interpolando los frames de 30 Hz del juego; **~109 fps** validados con RTSS, lógica a 30 Hz).
Antes: **mapa widescreen (fase 07b) validado** (`notes/2026-09-22-fix-mapa-rect-negro-widescreen.md`);
**migración ELF (ADR 0011) hasta M4** validada en Windows (playtest CaC ~30 min sin cuelgues).
**M5** (saneamiento) y **M4c** (SEGV teardown, fix en fork NMR) hechos. `lib/` como **submódulos**
(ADR 0010). Plan general: `notes/2026-09-21-migracion-via-referencia-elf.md`.
**Historial (detalle en `notes/`)**: reset per-file 2026-09-20 (causa del bloqueo de boot/CaC, superado
por la vía ELF); antes, live 30 ticks/s + replay y CaC investigado por el scheduler de eventos; 2026-09-18
cacheo de flags de `get_function` (stalls); 2026-09-16 guardado en cápsula y fixes de M55/`HH_S0FIX`.

| Fase | Estado | Nota |
|---|---|---|
| 0. Entorno | ✅ | toolchain + repos + Ghidra + assets |
| 1. Análisis estático | ✅/en curso | syms Ghidra; mapa overlay→RAM = tarea #3 (camino crítico, ver ADR 0001) |
| 2. Recompilación | ✅ base | boot + game loop corren (Linux/Windows); pipeline **ELF/splat** (ADR 0011; vía Ghidra multi-módulo archivada en `legacy/`) |
| 3. Render (RT64) | ✅ | RT64 renderiza logo/título/attract, cutscenes 3D, **gameplay con HUD** y combate; resolución auto (`HH_RES`); **high frame rate** (presenta al refresco del monitor). Historia del arranque/VI en `notes/2026-09-1*.md` y `docs/architecture.md` §5. |
| 4. Audio | ✅ base | `aspMain` del ROM + SDL; 43200 Hz; estable. **Futuro**: desacoplar de los fps (ver TODO). |
| 5. Guardado | ✅ | PFS emulado (`pak.cpp`); guardado en cápsula **validado en Windows** (UI de slots + `.pak` en `saves\`) tras el fix `osPfsFindFile`→5 (nota 2026-09-16) |
| 6. Textos/traducción | 🚧 | charset USA resuelto (ASCII, campos fijos; motor EUC-JP) + substitución en runtime + **A1** (idiomas, cambio en vivo, `[lang]`); **menú localizado EN/ES/CA/FR/DE + acentos + idioma del sistema (2026-09-25, headless; validado en Windows 2026-09-26)** + **JA en kana (2026-09-27, validado en Windows)** + **fuente única de traducciones `assets/lang/*.txt` clave=inglés (2026-10-01, validado en Windows; ADR 0014)**. Falta: verificar los textos JA contra la ROM japonesa, cablear la fuente in-game 8×12 y las traducciones in-game (DE/FR/JA de ROM; ES/CA propias) |
| 7. Robustez/empaquetado | en curso | build reproducible Linux (`tools/build_linux.sh`) + Docker + CI/Releases (ADR 0005); falta validar en GitHub y empaquetado Deck |

Detalle actual: `TODO.md`. Fuente de verdad técnica: `docs/architecture.md`.

## 6. Riesgos

1. **Módulos de código dinámicos (`trans`)**: base del módulo de boot determinista (ADR 0001);
   riesgo residual = bases de módulos posteriores (aún no medibles).
2. **Símbolos sin decompilación**: límites de Ghidra frágiles → mitigar con validador (TODO A3).
3. **Símbolos con fronteras mal acotadas** (datos absorbidos): causan stubs `do_break` silenciosos
   (caso `M9_FUN_802169ac`, 2026-09-15). Mitigar con `0xADDR:0xSIZE` y revisando avisos
   *"analysis failed (data absorbed...)"* del recompilador.
4. **LZSS 5/7** del `trans`: bloqueante para módulos.
5. **Efectos framebuffer / cinematografía**: verificar en RT64.
6. **Rendimiento/multiplataforma**: RDRAM 32-bit BE + 3 backends.
7. **Accesorios N64 (Controller Pak / Rumble Pak / device type)**: el boot ramifica según el estado
   del SI; ya han mordido input y Expansion Pak. Auditar contra el emulador de referencia (sin mempak
   ni rumble) — ver `notes/2026-09-13-arranque-memsize-y-accesorios.md` §5.

## 7. Estructura de documentación (modelo por capas)

```
/AGENTS.md          # arranque de sesión (1 pantalla)
/PROYECTO.md        # ESTE archivo: contexto + estado (vivo, corto)
/TODO.md            # única lista de tareas (viva, corta)
/RETOMAR.md         # punto de retomada de la sesión actual (handoff, corto)
/docs/
  README.md         # visión y roadmap a largo plazo
  architecture.md   # modelo técnico canónico (vivo)
  documentation.md  # cómo documentar (normativo, leer cada sesión)
  workflows.md      # procedimientos (build, regen, protocolo de imágenes)
  adr/NNNN-*.md     # decisiones inmutables
/notes/             # ARCHIVO histórico append-only (no se mantiene)
  archive/          # docs legacy congelados
  reference/        # datos generados (syms, manifests)
/tools/             # scripts propios; /work y /toolchain gitignored
```

**Normativa detallada: `docs/documentation.md`** (dónde va cada cosa, ciclo de sesión, cuándo crear
un ADR, consolidación y anti-patrones). Resumen: una fuente de verdad por tema; docs vivos cortos;
`notes/` es evidencia (no se edita); ADRs inmutables; nunca editar a mano el C generado.

## 8. Próximos pasos

Ver **`TODO.md`** (sección "Ahora"). Foco actual (2026-09-23): menú IN-GAME, smoke de arranque,
ADR 0009. Pendiente inmediato: **publicar Release `v0.4.0`** (tag; ver `RETOMAR.md`). Visión:
`docs/README.md`.
