# RETOMAR — handoff (2026-10-08)

> **Estado**: **`main`** contiene (1) la traducción del diálogo (≈30 %, módulos 12-17), (2) el **overlay
> propio del diálogo** (texto por MENSAJE en un solo fichero) y (3) los fixes de PROBE/flecha/input.
> El rastro del experimento está en el tag **`exp/overlay-dialogo`**; las ramas del experimento se
> borraron. **El fix (Tarea 1) se hizo directo en `main`; la traducción (Tarea 2) va en una rama nueva
> desde `main`.**
>
> **TAREAS DE ESTA SESIÓN**: (1) ~~fix de los subtítulos de la intro al skipear~~ **HECHO y validado
> en Windows (2026-10-08)** → `notes/2026-10-08-fix-subtitulos-intro-skip.md`; (2) ~~caja de
> subtítulos = caja del diálogo (mismo límite de ancho + misma transparencia)~~ **HECHO y validado en
> Windows (2026-10-08)** → `notes/2026-10-08-subtitulos-caja-igual-dialogo.md`; (3) **continuar la
> traducción** del diálogo (es+ca) — **siguiente**, en rama nueva desde `main`.
>
> **PREMISA (mantenedor)**: implementación **robusta** y **1:1 con el original**; **prohibido**
> parchear caso a caso. Hay **muchísimos** textos; cualquier cosa que dependa de casos concretos fallará.

## Estado (implementado y compilando; validado a ojo, con detalles abiertos)

Detalle completo: **`notes/2026-10-07-experimento-overlay-dialogo.md` §7-§9**.

**Hecho**:
- Reconstrucción del mensaje desde `func_8001800C` + capa propia `set_dialogue` (caja fija).
- **Typewriter por VI** (`HH_DLG_TYPE_VI`, def. 2 = 1 letra/tick lógico 30 Hz): exactamente 1 letra
  por periodo, sin adelantos. Al **acumular** varios mensajes en una página, solo anima el nuevo.
- **Flecha**: diseño ▼ 5×6 del juego + pulso **medido** (fade 66 ms, hold 465 ms, off 470 ms).
  Aparece como "un carácter más" (un periodo tras la última letra) y arranca en alpha 0. La flecha
  **nativa** (`func_80019038`) se suprime con el overlay activo; con `KEEP_ORIGINAL=1` se ve la nativa.
- **Caja**: sigue el alfa real del `'wa fa'` (fade-in/out) y la **caja nativa está suprimida**.
- **Cierre**: al empezar el fade-out, **texto y flecha desaparecen de golpe** (solo se apaga la caja).
- **Salto** A/J o Start/Enter, detectado por **frame de render**. Mientras el typewriter escribe (o
  hasta **soltar** la tecla que lo completó) se **enmascara A/START** para el juego
  (`overlay::dialogue_block_advance_input`): la **1ª** pulsación solo completa; la **2ª** avanza.
  En modo comparación (`HH_DLG_KEEP_ORIGINAL=1`) **no** se enmascara, para que el original avance con
  la **misma** pulsación.
- Los hooks **funcionales** del overlay (`1800C` reconstrucción, `18E9C` supresión del texto nativo) se
  registran **siempre**; `HH_DLG_PROBE` solo añade trazas.
- **Acumulación por página** (robusta): el **corte real es el opcode `F800`** (`f0 00 f8 00`), no
  `FA/FE`. Los mensajes `FA/FE` se acumulan hasta `F800`/`F000FC00`. `[m5]` "Disculpe." + `[m6]`
  salen juntos (la caja nativa ya lo hacía). Ver nota §8.1-§8.2.
- **Texto por MENSAJE en un solo archivo** (§9): las correcciones se añaden a `assets/lang/es.txt` y
  `assets/lang/ca.txt` con **clave = mensaje inglés completo** y **valor con los saltos "baked"** (`\n`).
  Se verificó que `dialogos.txt` alinea 1:1 con los mensajes de la ROM (216/216), así que el mapeo es
  por posición. **214 entradas por idioma** (2 duplicados idénticos comparten traducción; es: 3
  entradas de una línea actualizadas, ca: 2). Menús intactos.
- **Menús intactos**; **`.dlg.txt` eliminado** como fuente aparte.
- Herramienta: **`tools/text/build_dialogue_messages.py`** (`--lang es|ca`, `--dry-run`, `--show N`).
- Runtime: `text::dialogue_message_choice` + `find_message_value` buscan la clave del mensaje en el
  índice único; el hook parte el valor por `\n`.

## Estado de validación

- **VALIDADO en Windows (2026-10-08)**: primer diálogo (módulo 12) en **normal** y en **comparación**
  (`HH_DLG_DY=-64 HH_DLG_KEEP_ORIGINAL=1`), con **mando y teclado**: texto correcto, **input** (1ª
  pulsación completa / soltar / 2ª avanza; avanzan juntos en comparación), cierre de la caja y **una
  sola flecha** (la nativa suprimida). Overlay **integrado en `main`**.
- **Pendiente de repaso visual**: resto del juego — mod17 (m28 vs m29 con traducciones distintas; m33
  "divertido, Johnny Slater!"; textos largos completos) y el resto de módulos.
- `ca.txt` generado; pendiente su validación visual en el juego.
- **VALIDADO en Windows (2026-10-08)**: **subtítulos de la intro** — skip con **START/ENTER** (A/J ya
  no cancelan; el flanco se evalúa también armado) y **caja unificada con la del diálogo** (mismo
  límite de ancho = área interior de la caja de diálogo, + misma transparencia). Notas
  `notes/2026-10-08-fix-subtitulos-intro-skip.md` y `notes/2026-10-08-subtitulos-caja-igual-dialogo.md`.

Bug ya corregido (no reintroducir): el opcode de fin podía **compartir palabra** con el último carácter
(`A1A9FA00` = `?` + fin) y se perdía el carácter. Arreglado en `hh_p1800c` (emitir la mitad no-fin
antes de cerrar). Imprescindible para que casen las claves de mensaje (`isn't it?`).

## Cómo probar (Windows)

**Ejecución normal (sin variables)** — overlay completo (texto + caja + flecha) y original oculto;
los defaults ya son `BOX=28,169,292,223`, `ALPHA=95`, `TYPE_VI=2`:
```powershell
hybrid-heaven-recomp\build_windows.local.bat
hybrid-heaven-recomp\run_windows_release.bat
```

**Comparar con el original** (nuestra caja arriba + texto y caja nativos):
```powershell
hybrid-heaven-recomp\build_windows.local.bat
$env:HH_DLG_DY=-64; $env:HH_DLG_KEEP_ORIGINAL=1; hybrid-heaven-recomp\run_windows_release.bat
```

**Trazas** (solo diagnóstico): añadir `$env:HH_DLG_PROBE=1`. Log en `build\windows\bin\Release\hh.log`.

Variables (tabla completa: nota `2026-10-07-experimento-overlay-dialogo.md` §9.7):
`HH_DLG_PROBE` (solo trazas), `HH_DLG_BOX`, `HH_DLG_DX/DY`, `HH_DLG_ALPHA`, `HH_DLG_KEEP_ORIGINAL`,
`HH_DLG_TYPE_VI`, `HH_DLG_ARROW`, `HH_DLG_BLINK_FADE_MS/HOLD_MS/OFF_MS`, `HH_OVERLAY`.
Los hooks **funcionales** del overlay están **siempre** activos; `HH_DLG_PROBE` solo añade sondas y logs.

## TAREA 2 — Continuar la traducción del diálogo (es + ca) *(después de la Tarea 1, en rama nueva)*

**Guía: `docs/traduccion.md`** (pipeline y reglas); detalle: `notes/2026-10-07-dialogos-traduccion-es-ca.md`.

Cobertura (solo-diálogo): **27 escenas / 872 mensajes / 2173 líneas**. Hecho: módulos **12, 13, 14,
16, 17** (es+ca) → **262/872 ≈ 30 %**. Parcial: **27** (46/109). **Pendiente**: 18, 19, 20, 21, 26,
28-33, 37, 38, 40, 42-45, 47, 48, 50, 52, 53 y terminar 27.

Fuentes y ficheros:
- **`assets/dialogos.txt`** = referencia editable EN/ES/CA por módulo y `[mNN]` (alinea 1:1 con los
  mensajes de la ROM). `ES (tú)`/`CA (tú)` = versión **larga** (la que no cabía); `ES aplicado:` = la
  corta que sí cabía. **OJO**: puede tener valores **mezclados EN/ES** (p. ej. `[m9]`); la tabla
  **por-línea** (`es.txt`/`ca.txt`) es la autoritativa.
- **`assets/lang/es.txt` / `ca.txt`** = tablas de runtime (**clave = línea inglesa**) + una **sección
  final de MENSAJES** (clave = mensaje inglés completo; valor con los saltos "baked" `\n`) que usa el
  **overlay**.
- Herramientas (`tools/text/`): `extract_dialogues.py` (mensajes/líneas EN con offsets),
  `build_dialogue_messages.py` (genera la sección de MENSAJES; **`COVERED` está hardcodeado** a
  `(12,13,14,16,17)` → **añadir cada módulo nuevo**), `check_dialogue_fit.py` (presupuesto/cobertura),
  `check_translations.py` (claves/formato).

Flujo por módulo nuevo:
1. `python3 tools/text/extract_dialogues.py --module <N>` (mensajes/líneas EN).
2. Traducir **EN→ES→CA**; escribir cada línea en `assets/lang/es.txt`/`ca.txt` (**clave = línea inglesa
   exacta**, con espacios extremos/dobles tal cual) y, si alguna **no cabe** en el presupuesto A+, la
   versión **larga** en `assets/dialogos.txt` como `ES (tú)`/`CA (tú)`.
3. Añadir `<N>` a `COVERED` en `build_dialogue_messages.py`; ejecutar
   `python3 tools/text/build_dialogue_messages.py --lang es` y `--lang ca` (idempotente; **no toca menús**).
4. Validar: `check_dialogue_fit.py --lang es|ca`, `check_translations.py [--lang ca]`, `docs_index.py --check`.
5. **Validación visual en Windows** (mantenedor): overlay normal; y comparar con
   `HH_DLG_DY=-64 HH_DLG_KEEP_ORIGINAL=1`.

Reglas (`docs/traduccion.md`): clave exacta; presupuesto = suma de chars del **mensaje inglés**; ancho
de caja ~**30-32 chars/línea**, ~4 líneas; **nombres propios** según la línea oficial (p. ej.
`Gargatuan` se queda); ante dudas (nombres/términos/tuteo): **preguntar al mantenedor**.

## Integración en `main` (squash + tag)

El overlay se integró con **squash** en un único commit, **podando antes la arena** del experimento
`limites-texto` (no la necesita el overlay). El **rastro completo del experimento** (33 commits) queda
en el **tag `exp/overlay-dialogo`**; las ramas `experimento-overlay-dialogo`, `overlay-limpio` y
`experimento-limites-texto` **se eliminaron**. **Cambios futuros: rama nueva desde `main`** (tras un
squash, git no ve la rama vieja como fusionada). Detalle del proceso: nota
`2026-10-07-experimento-overlay-dialogo.md` **§9.8**.

## TAREA 1 ✅ — Fix: subtítulos de la intro al SKIPEAR (salían en el gameplay) — **HECHO, en `main`**

**HECHO y validado en Windows (2026-10-08).** Causa: el skip de subtítulos solo se evaluaba con la
secuencia **activa** (`g_active`); al skipear antes del ancla estaba **armada** (`g_pending`) → la
pulsación no cancelaba y el ancla (2.ª oleada de cargas, ya en gameplay) activaba la secuencia allí.

Fix en `src/subsystems/subtitles.cpp`: (1) el flanco de skip se evalúa **también armada** (`g_pending
|| g_active`; armada solo cuenta tras ver la escena 0x104, `g_scene_seen`); (2) `begin()` **siembra**
el flanco (`g_seed_skip`) para no confundir la pulsación de EMPEZAR PARTIDA (y se quitó el seed del
ancla); (3) **`kSkipMask` = solo START** (`0x1000`): **A/J ya NO cancelan** los subtítulos, **START/
ENTER** sí (saltan la cinemática y cancelan a la vez). No consume input. Traza: `[subs] skip
(armada=… activa=… btn=…)` con `HH_SUB_TRACE=1`.

Descartado: `stop()` al salir de la escena 0x104 (depende de que 0x104 no cambie en ~5,6 min de
cinemática; arriesgaba cortar el prólogo normal). Detalle: `notes/2026-10-08-fix-subtitulos-intro-skip.md`.

## Diferidos / aparte

- **JA** (juego + intro + final): **POSPUESTO** (requiere ROM JP). Menú JA en kana, deshabilitado.
- **fr/de** de los subtítulos de la intro: sin revisar. **Subtítulos del final**: diferidos.
- **Repaso visual del resto del juego** (overlay del diálogo): mod17 (m28/m29 con traducciones
  distintas, m33, textos largos) y demás módulos.

## Pitfalls (NO repetir)

- **No** concluir visual/sync solo desde headless; validar en Windows (el mantenedor).
- **No** editar el C generado (ADR `0009`); no tocar ROMs/forks/push sin pedir. Un tema = un commit.
- **No** "medir" capturas cuando el mantenedor da una variable exacta. Dudas → preguntar.
- **No** resolver textos diálogo a diálogo: implementación **robusta** o nada.
