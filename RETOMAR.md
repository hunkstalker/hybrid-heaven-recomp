# RETOMAR — handoff

> **Handoff para la próxima sesión.** Estado, siguiente tarea y métodos. **Diseño y técnica** viven en
> `docs/` y `notes/`; aquí solo se enlazan. Reglas: `AGENTS.md`.
> **`main` = release** (v0.5.0 publicada; `menu-nativo` ya mergeada). Para la próxima feature grande
> (editor de partida) **crear una rama** desde `main` (p. ej. `menu-edicion-partida`). Ver §Git.

## Estado (2026-09-27)

- **Sesión 2026-09-27 (rama `menu-nativo`)**: los tres temas del plan, **HECHOS Y VALIDADOS en
  Windows (2026-09-27)**:
  1. **`CÁMARA LIBRE`/`APUNTADO LIBRE` ocultos** (decisión final: retirados del árbol; antes se
     probaron deshabilitados en gris, `d27dc54`) — la maquinaria de deshabilitados se conserva.
  2. **Tildes/marcas a la derecha** (global, en el overlay): **`+0.5 px`** (se probó `+1 px` en
     `12961d4` y era **demasiado**) — commit `12961d4` + corrección final.
  3. **Menú en JAPONÉS (kana)** — commit `0c5f50c`: `color0` del ROM JP **byte-idéntico al US** (la
     kana ya está en la ROM cargada); mapping EUC→glifo de las tablas del `.resident` del ELF
     (`tools/text/extract_jp_kana.py` → `include/hh/jp_kana.h`); atlas **128×140** (`kMaxValue` 256);
     columna **JA** en `kMenuTr` y fin del fallback a inglés; endónimo `ニホンゴ`.
  Detalle: `notes/2026-09-27-c-camara-libre-off-tildes-y-menu-ja.md`.
  **Pendiente**: verificar los textos JA contra la ROM japonesa (backlog; el mantenedor no lee japonés).

- **`v0.5.0` PUBLICADA (2026-09-27)**: `main` = `c7d9698`, merge **fast-forward** de `menu-nativo`,
  tag **`v0.5.0`** (`v0.5.0 - Native menu: multilingual UI & PC options`). `menu-nativo` ya mergeada.
- **Release limpia sin volcados (`v0.5.1` en curso, 2026-09-27)**: el `.exe` release **solo** deja
  `hh.log` (sobrescrito cada run); `hh_audio/tick/slow/state/slice/hang/flag/crash/pak` pasan a
  **opt-in** (`HH_DIAG=1`, `HH_CRASH_LOG=1`, `HH_PAKLOG=1`; el fork NMR `39baeeb` cambia el default
  del paklog). Detalle: `notes/2026-09-27-d-release-sin-volcados.md`.
- **`EDICIÓN DE PARTIDA` (editor de save) HECHO en la rama `menu-edicion-partida` (2026-09-27,
  commit `14fa002`), pendiente validar en Windows**: menú en `EXTRAS` (`PROGRESO < N-P >`, `NIVEL`,
  `HABILIDADES` toggle, `BODY` con filtro `ESTADO`, `ITEMS`, `GUARDAR`). Edita el `.pak` en disco
  (offsets/checksums medidos) + recarga el runtime (fork NMR `0ae2585`). Fase 2: `JUGAR`/warp.
  Detalle: `notes/2026-09-27-e-editor-partida-plan.md`.

- **Limpieza de commits CERRADA (2026-09-26)**: `menu-nativo` parte de **`4759bd0`**
  (`origin/menu-nativo`); los 13 commits con basura (dumpeo/decodificador/bats/diagnóstico) se
  deshicieron y **nunca llegaron a `origin`**. `dump-logos/` y las herramientas temporales están
  **fuera del árbol** (`.gitignore` ignora `/dump-logos/` y `/dump*/`).
  - **Rama de respaldo `backup-sesion-intro-2026-09-26` (= `390b712`): CONSERVAR (no borrar).**
  - El trabajo real se **reaplicó en commits limpios**: `b5303da` (SFX Konami) y `dfb7da4`
    (`set_screen_image`); documentación en `54775c3`. Compila en Linux.
- **Sincronización con `main` CERRADA y validada**: merge `main → menu-nativo` con v0.4.1–v0.4.4
  (HUD/minimapa #3/#7). Nota `notes/2026-09-26-a-sync-menu-nativo-con-main.md`; checkpoint pre-merge:
  tag **`backup-menu-nativo-sync`**. El merge `menu-nativo` → `main` sería **fast-forward** (`main` es
  ancestro) y sería la **feature release v0.5.0** (ver §Git / §Release).
- **Menú inicial del port (`hh_menu`) COMPLETO y validado en Windows**:
  - Navegación propia (A/B, **control total**), **menú nativo oculto** (F6 alterna), SFX por eventos.
  - Acciones de **video** (`[video]`) y **audio** (`[audio]`) que aplican en vivo y persisten.
  - **Acentos** (letra base + marca) y **sombras** (flecha + marcas, con las marcas **debajo** de la
    letra). Nombres de marcas **Set A**: `_base`/`_ed`/`_blank`.
  - **Idiomas EN/ES/CA/FR/DE** + **idioma del sistema** (`config.ini [lang]`); `IDIOMA` funcional;
    raíz `CONFIGURACIÓN` (antes AJUSTES).
  - **`CONTINUAR`** retoma la partida (reenvío al dispatch nativo del título).
  - **`EMPEZAR PARTIDA`** arranca partida nueva (**validado en Windows 2026-09-26**): disparo nativo
    puntual de **GAME START** (rama idx0 de `func_801C3A40`), sin pilotar el submenú nativo. **`DIFICULTAD`**
    fija la dificultad en el global `0x801BBC0D` (implementada; **efecto real —daño enemigo— por
    comprobar jugando**). Nota `notes/2026-09-26-g-…`.
  - Detalle: `notes/2026-09-26-b/…-idioma-configuracion-y-sombras.md`,
    `…-c-sombras-y-set-a.md`, `…-d-continuar-y-bugs-visuales.md`, `…-g-empezar-partida-y-dificultad.md`;
    **ADR 0008/0012**; `docs/menu.md`.
- **HUD/minimapa de `main`** integrados por el merge (issues #3 y #7).
- **Logos de intro HD (KONAMI/KCEO) + código Konami → `EXTRAS`**: implementado y **VALIDADO EN WINDOWS
  (2026-09-26)**. Causa raíz corregida (los logos de arranque los pinta el **módulo file 055**, no el
  de título), fundido por grupo con velo + clave de blanco, preload, `EXTRAS` con persistencia explícita
  (toggles `MANTENER EXTRAS`/`LOGOS ORIGINALES`), arranque de ventana borderless, y **fixes del attract**
  (sin logos HD en el replay; timer de inactividad nativo → intro/demos al ritmo original) y del
  **centrado del "Press Start"** traducido. Detalle:
  `notes/2026-09-26-i-logos-intro-hd-y-konami-impl.md`; §Git.
- **`CONFIGURACIÓN → CONTROLES` (remapeo + ejes + VIBRACIÓN)**: **VALIDADO en Windows (2026-09-26) y
  commiteado (`74dd5a8`)**. La `VIBRACIÓN` no es validable hasta resolver el item 11 (Rumble vs
  Controller Pak). Tabla de **acciones** con 2 columnas (**MANDO/TECLADO**), lista
  larga con **scroll de 5 filas + flechas ↑/↓**, menús del port **centrados**. Reasignación de
  cualquier acción a **cualquier botón (incl. D-PAD) y/o tecla** (**1 botón + 1 tecla**), con bloqueo
  de A/B 0.25 s al asignar; **movimiento** (4 ejes: stick izq/der + tecla), **D-PAD** como botones
  (`MENÚ ...`), toggle **`VIBRACIÓN`** (Rumble Pak → SDL) y **`RESET`**. Persiste en `[game]/[menu]`
  (mando) y `[keys]` (teclado/ejes); `config_ini_clear_section` evita claves viejas. Detalle:
  `notes/2026-09-26-j-controles-remapeo-y-vibracion.md`.
- **Traducción in-game (juego)**: charset + sustitución en runtime listos; **fuente 8×12 `color4`
  preparada pero sin cablear**.
- **`MODO COMBATE` (BATTLE MODE) COMPLETO y VALIDADO EN WINDOWS (2026-09-27)**: habilitado y
  recreado con nuestro menú (`MODO VS` / `COMBATE DE CRIATURAS` → `5 COMBATES` / `SUPERVIVENCIA` /
  `EDITAR DATOS`), con despacho nativo por cursor. `MODO VS` **no validado** (el port solo reporta el
  puerto 0 de mando). Commits `f0a4256` + `6e73337`; detalle en
  `notes/2026-09-27-battle-mode-recon.md`.

## TAREA `EDICIÓN DE PARTIDA` (editor de save, para tests)

**Estado: v1 HECHA (2026-09-27, rama `menu-edicion-partida`, commit `14fa002`)**. Pendiente:
**validar en Windows** (escritura real del `.pak` + `CONTINUAR`), pulir y hacer la **fase 2** (`JUGAR`/
viaje directo al nivel, sin pasar por guardar).

**Objetivo del mantenedor (2026-09-27)**: un menú (empezó como motivo de `EXTRAS`) para **cargar una
partida y editarla** y así probar el juego sin jugar horas: progreso (nivel-punto, p. ej. `1-0`), nivel
del PJ, habilidades (toggle), estadísticas por parte del cuerpo (`BODY`: ESTADO como filtro →
CABEZA/BRAZO IZQ/DER/PIERNA IZQ/DER/CUERPO), items (cantidad) y **GUARDAR** en un slot. Opción
valorada para fase 2: elegir nivel y **`JUGAR`** → pantalla de carga al nivel, sin cargar partida.

**Reconocimiento ya hecho (2026-09-27, ver `notes/` a escribir / este RETOMAR)**:
- **Guardado**: el `.pak` es un contenedor propio `HHPK` (13595 B; data del juego a `0x1B`, 13568 B =
  cabecera `0x100` + **4 slots `0xD00`**). Checksums en `0xFC` (cabecera) y `+0xCFC` (slot). El slot
  vivo se serializa con **`func_80141F28`** y se deserializa con `func_80141D08`; buffers
  `0x801BEC10` (0xD00) y **estado de partida `0x801BBBF0`**. `func_8014168C` (slot↔buffer) y
  `func_80142450`/`func_80142350` (escritura PFS). El juego **ya trae un editor nativo** (`DATA EDIT`
  del BATTLE MODE → `func_801406A4` → `func_8014168C`).
- **Estado en RAM (módulo 8)**: stats del PJ base **`0x8017DC40`** (HP, offense/defense por 6 partes,
  **hit count** `+0x68`, **damage count** `+0x76`, **nivel u8 `0x8017DC88`**); **items** `0x8017E004`
  (45×8, cantidad `+4`); **técnicas** `0x80183CE0` (86×6; "aprendida/usos" en `+4`); flags de
  progreso `0x8008DC18+8` (0x64 B). **DIFICULTAD** `0x801BBC0D`. El **campo exacto de progreso
  (nivel-punto)** está en `0x801BBBF0` pero **sin confirmar** (la pantalla CONTINUE pinta
  `+0x04`).
- **UI de slots** (carga/guardado): file-select de `file_008` (`func_8013E700` init, `func_8013E850`
  update LOAD, `func_8013EB2C` update SAVE, setup SAVE `func_8013EA94`, cursor `0x801BBF42`); la
  cápsula lo lanza desde `func_8021D768` (file_011). Las etiquetas de ese file-select **no** están en
  `kNativeRanges` (se ven completas).
- **Recetario overlay**: añadir `ScreenId`/`Action` en `include/hh/menu.h` + `build_tree` (`menu.cpp`),
  filas `make_selector`/`make_selector_with_action`/`make_submenu`/`make_option`; acciones en
  `feed_menu_navigation` (`sections.cpp`); traducción en `kMenuTr`; si las etiquetas son largas,
  añadir a `custom_layout` en `menu_overlay.cpp`.

**Pendiente antes de codificar**: (1) confirmar el campo de **progreso** en `0x801BBBF0` (comparando
saves con progreso real o `HH_*` de traza); (2) decidir **vía de guardado** (editar `0x801BEC10`/
`0x801BBBF0` y dejar que el nativo serialice vs recomputar checksums del `.pak`); (3) cómo enganchar
la UI nativa de slots para `GUARDAR` (propuesta (a): setup `func_8013EA94` + update `func_8013EB2C`).
Relacionado con el **bloqueante `VIBRACIÓN` ↔ guardado** (item 11 de `TODO.md`).

## SIGUIENTE TAREA: menú nativo — funcionales y pulido (orden recomendado)

1. **Logos de intro HD (KONAMI/KCEO) + código Konami → `EXTRAS`**.

   **Estado (2026-09-26): COMPLETADO y VALIDADO EN WINDOWS** (fades, skip, flash, `EXTRAS`, attract y
   "Press Start" centrado). Commitado **por tareas** (ver §Git). Solo queda el relleno de `EXTRAS`
   (`NIVEL`/`HABILIDADES`, por definir) y el fix de fondo de paridad headless.

   **CAUSA RAÍZ (corrige el diagnóstico antiguo)**: los logos que se ven **al arrancar** los pinta el
   **módulo de arranque file 055** (`func_80383AD4`, base `0x803837E0`), **NO** el módulo de título. Los
   handlers `0x801C1624/1764/17C8` son el **replay del modo attract** (mucho más tarde, t≈30 s). Por eso
   la intro HD salía tarde. Evidencia: `HH_TRACE_RANGE`/`HH_CANARY` (banderas/alfas del file 055) y
   capturas con `HH_OVERLAY=0` (nativo) vs overlay.

   - **Assets** (`assets/logos/`, PNG 4:3 3840×2880, dibujados a mano por el mantenedor en Affinity;
     CMake los copia a `<exe>/logos/`): clásicos `konami-1998.png` (fondo blanco) / `kceo-1995.png`
     (blanco); modernos `konami-2023.png` / `kceo-2000.png` (**fondo negro**).
   - **Composición** (`src/platform/overlay.cpp` + `shaders/OverlayPS.hlsl`): `negro base → tarjeta
     OPACA (blanca en clásicos / negra en modernos) → logo → velo negro de fundido → flash blanco`.
     El logo se composita **una sola vez** sobre la tarjeta y el grupo se funde con el velo (`alfa =
     1 - fade`); así no se “lava” (fallo clásico de fundir cada capa). El PS tiene **`mode 2` = clave
     de blanco** (el `#FFFFFF` del PNG se vuelve transparente y lo aporta la tarjeta). La tarjeta se
     elige con `set_screen_image(path, black_bg)` y `g_card_black` se aplica **al cargar** la textura.
   - **Alfas NATIVAS** (medidas con `HH_CANARY`, el hook las copia sin inventar tiempos):
     `0x8038DBC0` = alfa **KONAMI** (sube/baja), `0x8038DBD4` = alfa **KCEO** (sube/baja),
     `0x8038DBD8`/`0x8038DBD0` = flags de capa KONAMI/KCEO. Fade final KCEO a ~12/VI (~0.35 s).
   - **Preload**: `preload_screen_image` al arrancar (evita perder el primer fade-in decodificando el
     PNG). `g_window_show_pending`/`g_window_show_ready` ya **no** existen (ver ventana).
   - **Código Konami** (`↑↑↓↓←→←→BA` por flancos; SFX correct/error/unlock; timeout 2 s; reintentos
     infinitos): **pausa** al primer `↑` congelando el state machine del file 055 (`0x8038DBB8=1`,
     `0x8038DBB4=0`, `0x8038DBC0=0xFF`, `0x8038DBD4=0`), aplicada tras el original. Al completar →
     `unlock_extras()`, **cambio a los logos MODERNOS** y **flash blanco** (`flash_white(400)`).
   - **`EXTRAS`**: `ScreenId::Extras` + `Action::OpenExtras` (+ `ToggleExtrasPersist` /
     `ToggleOriginalLogos`); entrada en la raíz **encima de `SALIR`** si `extras_unlocked()` (código
     Konami de sesión **o** `MANTENER EXTRAS = SÍ`). Ajustes persistidos en `config.ini [extras]`:
     **`MANTENER EXTRAS <NO/SÍ>`** (def. `NO`; primera entrada: `SÍ` mantiene EXTRAS entre arranques)
     y **`LOGOS ORIGINALES <NO/SÍ>`** (def. `SÍ`: clásicos de fondo blanco; `NO` = modernos negros).
     `use_modern_logos()` = código de sesión **o** `NO`. `unlock_extras()` rehace el árbol (`reset()`).
     EXTRAS usa **layout propio** (desplazado a la izquierda + columna de valores por etiqueta larga).
   - **Skip con START**: KONAMI lo gestiona el nativo (1 pulsación); para KCEO el nativo ignora START
     durante su fade-in, así que el hook fuerza `0x8038DBCC=3` → **1 Enter = 1 skip** también en KCEO.
   - **Arranque de ventana** (`src/platform/support.cpp`): en fullscreen la ventana se crea ya
     **borderless** y a tamaño de monitor (visible), y RT64 confirma el modo (`setFullScreen`); así no
     se ve la transición con barra ni el resize. (Se probó `SDL_WINDOW_HIDDEN` + mostrar tras setup,
     pero **robaba el foco** → F11 caía en la terminal y no había icono en la taskbar; descartado.)
   - **Telón negro** (`set_screen_blackout`): desde el arranque tapa los logos **nativos del boot
     (file 8)**; se retira al terminar la intro. Auto-off a los 30 s. (El overlay solo empieza a
     dibujar en el primer *present* de RT64, ~1.5 s en headless.)
   - **Dónde mirar / instrumentación**: `HH_MENU_TRACE=1` escribe `[intro] boot logo konami=… kceo=…
     ak=… ae=… la=… fade=… pause=… out=…`, `[konami] inicio/acierto/COMPLETADO`, `[overlay] imagen
     cargada`, `[menu] goto pantalla=…`; `HH_TRACE_RANGE=0x803837E0:0xA5E0` y `HH_CANARY=0x8038Dxxx`
     para el file 055. Autoplay temporal de test (`HH_BOOT_KONAMI_AUTOPLAY`) usado y **retirado** (no
     está en el árbol).
   - **Validado en Windows (2026-09-26)**: fades inicio/KONAMI→KCEO/final, **skip con Enter** (1 por
     logo), flash + modernos al desbloquear, `EXTRAS` en la raíz, **attract** al ritmo original (sin
     logos HD en el replay) y **"Press Start" centrado** al traducir.
   - **Pendiente**:
     a) `EXTRAS`: ampliar el **contenido real** más allá de `LOGOS ORIGINALES` (nivel/habilidades) y
     cablearlo.
     b) **BUG de paridad headless** (carrera `ptick`/`bootstate`): fix de fondo (hoy `HH_FORCE_INTRO`).
     c) **Parpadeo de inicio**: si en alguna config persistiera, el nativo del **file 8** se pinta antes
     del primer present de nuestro overlay → **engancharlo/ocultarlo**, no solo taparlo.
   - Detalle: `notes/2026-09-26-i-logos-intro-hd-y-konami-impl.md`; plan previo:
     `notes/2026-09-26-h-logos-intro-hd-y-konami.md`.
2. **Demos de inactividad**: recuperar la intro/demos que salían a los segundos sin pulsar (se
   perdieron al crear el menú moderno); analizar.
3. **Fallos visuales** (capturas del mantenedor en `work/gameplay screenshots/CONTINUAR/`; `work/` es
   **gitignored**, pedir/copiar si hay que conservarlas):
   - **`DATA LOAD`**: el borde verde del cuadro de selección aparece pegado al borde superior de la
     pantalla (menú **nativo**; investigar con **F7** y `HH_FULL_FRAME=0`).
   - **Combate (golpes)**: las cajas verdes/rojas salen con **recuadro negro**; el original no lo lleva.
4. **Traducción — MENÚ (overlay)**: **JA** (embeber la **kana** del `color0` JP o TTF; hoy cae a inglés;
   `color0` JP tiene kana, no kanji).
5. **Traducción — JUEGO/GAMEPLAY (texto in-game)**: **cablear** `game_font_color4.h` en
   `src/hooks/text_glyphs.cpp`; extraer **DE/FR** (ROM EU) y **JA** (ROM JP) emparejando por módulo →
   `assets/lang/*.txt`; redactar **ES/CA**; validar longitud variable/A1 en Windows.
6. **Comprobar `DIFICULTAD` jugando**: verificar que el valor de `0x801BBC0D` se traduce en el **daño
   real** de los enemigos (requiere partida). La escritura está implementada (`0x801BBC0D`).
7. **`CONTROLES` (remapeo + ejes + D-PAD + `RESET`)**: **VALIDADO en Windows (2026-09-26)** y
   commiteado (`74dd5a8`). Detalle: `notes/2026-09-26-j-controles-remapeo-y-vibracion.md`.
   - **`VIBRACIÓN` ↔ guardado** (tarea aparte, `TODO.md` item 11): con `VIBRACIÓN` en SÍ **no se puede
     cargar/guardar** (Rumble Pak vs Controller Pak comparten ranura) → hasta resolverlo, la
     `VIBRACIÓN` no es validable.
8. **`MODO COMBATE` (BATTLE MODE) — COMPLETO Y VALIDADO EN WINDOWS (2026-09-27)**:
   decisión del mantenedor: **recrear** los submenús con nuestro menú (traducidos). **Hecho**:
   (1) mapa de la secuencia nativa (todo en `file_024`: setup `0x801C40F8` → update `0x801C4200`;
   `VS MODE`→stub, `CREATURE BATTLE`→`0x801C43BC…`, `DATA EDIT`→`0x801C47D0…`, `EXIT`→`0x801C56B8`;
   `DEMO SELECT` en `file_025`); (2) **SEGV `FUN_80026f58` NO reproducido** headless;
   (3) **`MODO COMBATE` habilitado** + pantallas propias `MODO VS` / `COMBATE DE CRIATURAS` →
   (`5 COMBATES` / `SUPERVIVENCIA`) / `EDITAR DATOS` (en/ca/fr/de; sin `SALIR`, se sale con `B`);
   (4) **despacho nativo cableado** (`hh_battle_menu_hook`→`func_801C4200` y
   `hh_battle_creature_hook`→`func_801C44C4`: cursor `0x801CC8C8`+A inyectada, patrón `sel`+A;
   etiquetas nativas suprimidas; resincronización al volver a la raíz).
   **Validado en Windows (2026-09-27)** salvo **`MODO VS`**: el port **solo reporta el puerto 0** de
   mando (`src/subsystems/input.cpp`), así que no se detecta un **2.º mando** (¿o 2.º Controller Pak?)
   → backlog (`TODO.md`). `EDITAR DATOS` no tiene pantalla de opciones propia (flujo nativo).
   Detalle: `notes/2026-09-27-battle-mode-recon.md`; `TODO.md` item 12.

> **Hecho (2026-09-26)**: `EMPEZAR PARTIDA` **validado en Windows**; `DIFICULTAD` implementada
> (`notes/2026-09-26-g-empezar-partida-y-dificultad.md`).

### Aparcado
- **`CÁMARA LIBRE`/`APUNTADO LIBRE`** (requieren modificar el juego; **ocultos** en el menú desde
  2026-09-27). **Interacción con CONTROLES
  (decidido 2026-09-26)**: el **stick derecho** simula los **botones C** por defecto (`STICK C`); con
  la **cámara libre activa**, el stick derecho pasa a ser **cámara** y se **desactivan todos los
  mapeados de los botones C**. Sin conflicto (la cámara libre no es un botón C).

**Widescreen/HUD — CERRADO (2026-09-26)**: radar y HUD de combate (POWER/STAMINA, disco, combo,
stamina) a la izquierda y minimapa a la derecha, anclados y persistentes entre combates/niveles;
**no hay barra HP** (dial + numérico); los cuadros de diálogo van centrados. Detalle en `TODO.md`.

## Referencia técnica del menú (para reanudar)

- **Modelo**: `src/subsystems/menu.cpp` + `include/hh/menu.h` (pantallas, cursor, `Action`, `Event`).
- **Overlay**: `src/hooks/menu_overlay.cpp` (frame del título), `src/platform/overlay.cpp` (dibujo
  GPU: paneles/texto/marcas), `src/subsystems/font.cpp` (atlas de la fuente + marcas).
- **Entrada y acciones**: `src/hooks/sections.cpp` → `feed_menu_navigation` (navegación + acciones) y
  `hh_title_menu_hook` (envuelve `func_801C1DB8`; input nativo muteado con `g_mute_native_input`).
- **Dispatch nativo del título** (`sel` @ `0x801CC8C4`, valor 0..4): `0=NEW GAME / 1=CONTINUE /
  2=BATTLE MODE / 3=SOUND / 4=RESOLUTION`. Para disparar una acción del juego: fijar `sel` e inyectar
  **A** una vez (`g_inject_native_a` en `hh_native_ab_input`).
- **Marcas del menú**: `tools/text/menu_marks.py` (Set A: `_base` plantilla / `_ed` **diseño fuente de
  verdad** / `_blank` lienzo de `--template`) → `include/hh/menu_marks.h`.
- **Textos del menú**: `kMenuTr` en `menu.cpp` (ES canónico → en/ca/fr/de) + `hh::menu::localized`.

## Bug aplazado (interpolación de frames)

**Artefacto de interpolación (puerta + primer jefe del nivel 1) — APLAZADO.**
- **Síntoma**: con `Refresh Rate Mode = Display` (interpolación **ON**) cierta **puerta** parpadea y el
  **primer jefe del nivel 1** muestra geometría incoherente; con `Original` **no** ocurre (PresentEarly
  no influye). **NO** pasa en **BizHawk**/ **Simple64** → es del render (RT64/port).
- **Causa**: la interpolación de RT64 (`RefreshRate::Display`) empareja draw calls e interpola matrices.
- **Solución de fondo**: **desacoplar la lógica del juego del render** (lógica a 60 Hz) → épica aparte.
  Detalle: `notes/2026-09-22-fps-y-present-early.md` §Regresión conocida.

## Método HUD

- **Lista de validación**: solo Windows (build release GUI). Linux headless solo compila.
- Trazas junto al exe: `HH_HUD_TRACE=1`, `HH_HUD_REWRITE_TRACE=1`, `HH_HUD_SCISSOR_TRACE=1`,
  `HH_FULL_FRAME=0` (off), `HH_NO_HUD_REWRITE=1` (off), `HH_MAP_CROP=<px>`.
- **Atajos de diagnóstico**: **F7 = captura pareada** (traza `hh_cap_<n>.log` **+ imagen** `hh_cap_<n>.bmp`
  del mismo instante); **F8** PresentEarly; **F9** interpolación; **F10** reescritor HUD.
- **Regla**: la **dirección RDRAM no es identidad**; usar **hash de contenido** (+ caja/posición). **No
  fiarse del color** (RT64 pinta el relleno con el PRIM color). Inspector de RT64: `HH_DEVELOPER=1` + F1.

## Método (rápido)

- **Build/run Windows**: `AGENTS.md` (build) + `docs/BUILDING_windows.md`. **Build Linux**:
  `cmake --build build/linux --parallel $(nproc)` (necesita `lib/` ya clonado).
  **Regenerar C recompilado**: `python3 tools/regenerate.py` (ADR 0009/0011; no se versiona).
- **Headless + replay para llegar al menú**: `docs/workflows.md` §2.
- **Diagnósticos** (`hh.log`): `HH_MENU_TRACE=1`, `HH_NATIVE=1`, `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`,
  `HH_MENU_SCREEN=<id>`, `HH_FONT_TRACE=1`, `HH_FONT_DUMP_GLYPH=<color>`, `HH_ACCENTS=0`, `HH_LANG=es`,
  `HH_FPS=1`. Atajos: F2 aspecto, F3 ventana, F4 MSAA, F5 idioma, **F6 menú nativo**, F7–F10 (HUD).
  Inspector RT64: `HH_DEVELOPER=1` + F1 (o `DEBUG → VENTANA DEBUG = SÍ`).
- **Intro de logos (file 055)**: `HH_MENU_TRACE=1` → `[intro] boot logo konami=… kceo=… ak=… ae=… la=…
  fade=… pause=… out=…`, `[konami] inicio/acierto/COMPLETADO`, `[overlay] imagen cargada`, `[menu]
  goto pantalla=…`. Para el file 055: `HH_TRACE_RANGE=0x803837E0:0xA5E0` (llamadas con `t=`) y
  `HH_CANARY=0x8038Dxxx` (cambios de banderas/alfas por VI). El autoplay de test
  (`HH_BOOT_KONAMI_AUTOPLAY`) se usó y **se retiró** (no está en el árbol).
- **Replay con START**: `tests/replays/*` o `HH_REPLAY=<f> HH_REPLAY_MODE=vi` (formato `<t> <vis>
  <btn> <x> <y>`, START=`0x1000`); útil para llegar al menú sin mando.
- **Fuente/acentos**: `tools/text/menu_marks.py` (marcas del menú), `tools/text/build_font.py`
  (fuente in-game 8×12), `tools/text/README_font_sheet.md`. ROMs en `work/roms/` (`us_dec.z64`,
  `eu_dec.z64`, `jp.z64`).
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM USA para el port:
  `build/linux/baserom.us.z64` (o cualquier `*.z64`). SHA-1 USA retail: `16dbc21620b52deab5c5abf8a309ac60adfbee85`.
- **Docs**: tras editar docs, `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`;
  `--check` valida enlaces y el presupuesto de arranque).

## Git

- **`main` = release**: **v0.5.0 PUBLICADA y pusheada (2026-09-27)** — `main` = `c7d9698`, tag
  `v0.5.0` (`v0.5.0 - Native menu: multilingual UI & PC options`), CI verde. Fue **fast-forward** de
  `menu-nativo` (98 commits: menú inicial propio, `CONTINUAR`/`EMPEZAR PARTIDA`/`DIFICULTAD`,
  `MODO COMBATE`, `CONTROLES`, `EXTRAS`+logos HD/código Konami, acentos e idiomas EN/ES/CA/FR/DE/JA).
- **`v0.5.1` (en curso, 2026-09-27)**: release limpia sin volcados. En `main`: port + fork NMR
  `39baeeb` (`NMR_COMMIT` en `runtime.lock`) + `docs/releases/v0.5.1.md` + bump `0.5.1`. **Orden de
  push**: fork NMR primero (`git -C lib/N64ModernRuntime push fork hybrid-heaven`), luego `main`, y
  el tag `v0.5.1` **tras CI verde**.
- **`menu-nativo`** (WIP del menú): basado en **`4759bd0`** (`origin/menu-nativo`; los 13 commits con
  basura se deshicieron y **nunca llegaron a `origin`**). Merge con `main` ya incluido. Commits limpios
  de 2026-09-26 **sin pushear**: sync, backlog/docs, IDIOMA/CONFIGURACIÓN, sombras, `CONTINUAR`,
  `EMPEZAR PARTIDA`/`DIFICULTAD`, `b5303da` (SFX Konami), `dfb7da4` (`set_screen_image`), la **tarea 1**
  troceada en 6 commits (`422714c` capa de imagen del overlay, `33147da` pantalla `EXTRAS`, `a9eb0ae`
  logos HD + código Konami, `ff8fdc0` ventana borderless, `4318527` WAVs, `57dca28` docs) y los
  **fixes validados en Windows (2026-09-26)**: `a7705d5` (toggles `EXTRAS` + layout propio), `6e4df36`
  (attract + timer de inactividad), `5e93d61` (centrado de traducciones `^`) y sus docs. Después,
  `1d790c7` (`chore(sfx)`: sonido de error + créditos Konami) y `74dd5a8` (`feat(config)`: pantalla
  `CONTROLES` con remapeo, ejes, D-PAD, `VIBRACIÓN`, `RESET`, layout/scroll) + su commit de docs.
- **Sesión 2026-09-27** (sin pushear): `6e73337` (`COMBATE DE CRIATURAS`) y `f0a4256` (`MODO COMBATE`);
  `94732b5`/`1dfd9ad` (docs); y los temas de hoy: `dc5f902` (docs del plan), `d27dc54` (selectores
  `CÁMARA/APUNTADO LIBRE` off), `12961d4` (tildes), `0c5f50c` (menú JA) y `7d3f10f` (docs de cierre).
- **`backup-sesion-intro-2026-09-26`**: respaldo del estado con el trabajo de logos/SFX; **CONSERVAR**.
- **Estado del árbol**: la corrección de tildes `+1 px → +0.5 px` y este cierre de documentación están
  **sin commitear** (validados en Windows; ver `notes/2026-09-27-c-…`). El resto, commiteado.
- Commitear **solo** lo validado o la documentación, y **solo con permiso del mantenedor** (regla
  `AGENTS.md`). Las herramientas de volcado/pruebas y sus docs van **fuera del repo** (`/tmp` o `work/`).

## Build Windows

```
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
```
(La build **no siempre** refresca el `.exe`: comprobar su fecha; si no cambia, borrar
`build\windows` y recompilar desde cero. Verificado que sale `=== LISTO ===` pero a veces no
actualiza el ejecutable.)
