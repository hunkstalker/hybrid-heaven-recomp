# RETOMAR — handoff (2026-10-08)

> **Estado**: **`main`** = v0.7.3 + **overlay propio del diálogo** (texto por MENSAJE) + **subtítulos de
> la intro** (fix de skip, caja = caja del diálogo, modo attract) + **fix raíz de interpolación**
> (límite de discontinuidad de posición en RT64, fork `db300ca`; gate `native_title_active` retirado).
> Todo **pusheado** (`main` en sync con `origin/main`; fork RT64 al día).
>
> **TAREA DE LA PRÓXIMA SESIÓN**: **Tarea 2 — continuar la traducción del diálogo es+ca**, en **rama
> nueva desde `main`** (tras el squash, git no ve las ramas viejas como fusionadas). Guía:
> `docs/traduccion.md`; detalle: `notes/2026-10-07-dialogos-traduccion-es-ca.md`.
>
> **PREMISA (mantenedor)**: implementación **robusta** y **1:1 con el original**; **prohibido** parchear
> caso a caso. Hay **muchísimos** textos; cualquier cosa que dependa de casos concretos fallará.

## TAREA 2 — Continuar la traducción del diálogo (es + ca)

**Guía: `docs/traduccion.md`** (pipeline y reglas).

Cobertura (solo-diálogo): **27 escenas / 872 mensajes / 2173 líneas**. Hecho: módulos **12, 13, 14, 16,
17** (es+ca) → **262/872 ≈ 30 %**. Parcial: **27** (46/109). **18 volcado (2026-10-09)**: 51 mensajes a
`es.txt`/`ca.txt` (per-line) + `dialogos.txt` (`(tú)` completos) + build; **pendiente validación visual
en Windows**. **Pendiente**: 19, 20, 21, 26, 28-33, 37, 38, 40, 42-45, 47, 48, 50, 52, 53 y terminar 27.

Fuentes y ficheros:
- **`assets/dialogos.txt`** = referencia editable EN/ES/CA por módulo y `[mNN]` (alinea 1:1 con los
  mensajes de la ROM). `ES (tú)`/`CA (tú)` = versión **completa** (la que **se muestra** en el overlay,
  sin límite); `ES aplicado:` = versión corta **legada** (render nativo A+). **OJO**: puede tener valores
  **mezclados EN/ES** (p. ej. `[m9]`); la tabla **por-línea** (`es.txt`/`ca.txt`) es la autoritativa.
- **`assets/lang/es.txt` / `ca.txt`** = tablas de runtime (**clave = línea inglesa**) + una **sección
  final de MENSAJES** (clave = mensaje inglés completo; valor con saltos "baked" `\n`) que usa el
  **overlay**.
- Herramientas (`tools/text/`): `extract_dialogues.py` (mensajes/líneas EN con offsets),
  `build_dialogue_messages.py` (genera la sección de MENSAJES; **`COVERED` está hardcodeado** a
  `(12,13,14,16,17,18)` → **añadir cada módulo nuevo**), `check_dialogue_fit.py` (cobertura; presupuesto
  A+ = informativo), `check_translations.py` (claves/formato).

Flujo por módulo nuevo:
1. `python3 tools/text/extract_dialogues.py --module <N>` (mensajes/líneas EN).
2. Traducir **EN→ES→CA**; escribir cada línea en `assets/lang/es.txt`/`ca.txt` (**clave = línea inglesa
   exacta**, con espacios extremos/dobles tal cual) y la versión **completa** del mensaje en
   `assets/dialogos.txt` como `ES (tú)`/`CA (tú)` (**sin límite de caracteres**; `aplicado` no obligatorio).
3. Añadir `<N>` a `COVERED` en `build_dialogue_messages.py`; ejecutar
   `python3 tools/text/build_dialogue_messages.py --lang es` y `--lang ca` (idempotente; **no toca menús**).
4. Validar: `check_dialogue_fit.py --lang es|ca`, `check_translations.py [--lang ca]`, `docs_index.py --check`.
5. **Validación visual en Windows** (mantenedor): overlay normal; y comparar con
   `HH_DLG_DY=-64 HH_DLG_KEEP_ORIGINAL=1`.

Reglas (`docs/traduccion.md`): clave exacta; **sin límite de caracteres** (overlay) → traducir
**completo, sin acortar**; ancho ~**30-32 chars/línea** (saltos `\n` inferidos); **nombres propios**
según la línea oficial (p. ej. `Gargatuan` se queda); ante dudas (nombres/términos/tuteo): **preguntar
al mantenedor**. (El **presupuesto A+** = suma de chars del mensaje inglés es **legado** del render
nativo; `check_dialogue_fit.py` es informativo.)

**Reglas de esta localización (mantenedor, 2026-10-09)**:
- **Método**: antes de tocar ficheros, presentar la tabla **EN | ES | CA a nivel de MENSAJE** (EN =
  mensaje inglés completo; ES/CA = traducción) para que el mantenedor la revise.
- **Registro formal/informal** (`tú`/`usted`): se decide **frase a frase según el original**, no por
  módulo. Fuente **principal = inglés**; **de/fr de la ROM EU = referencias de contexto** (codifican
  `Du/Sie` y `tu/vous`). Trato directo, contracciones o `Johnny` a secas → **tú**; `please`/distancia/
  respeto → **usted**.
- **Cotejo con otros idiomas**: **antes de traducir**, contrastar cada mensaje con las versiones
  **DE/FR de la ROM EU** (`work/dialogues/us_de_fr.tsv`) para desambiguar matices (p. ej. "becoming
  more aware" = *reprend conscience* / *das Bewußtsein kommt zurück*). El **inglés manda**; DE/FR dan
  contexto, no alinean 1:1 (el `--pair` fusiona/desplaza filas).

## Contexto del overlay del diálogo (ya en `main`)

Detalle completo: **`notes/2026-10-07-experimento-overlay-dialogo.md` §7-§9**.

- Reconstrucción del mensaje desde `func_8001800C` + capa propia `set_dialogue` (caja fija).
- **Typewriter por VI** (`HH_DLG_TYPE_VI`, def. 2 = 1 letra/tick lógico 30 Hz); al **acumular** varios
  mensajes en una página, solo anima el nuevo. **Flecha** ▼ 5×6 con pulso medido (66/465/470 ms); la
  flecha **nativa** se suprime con el overlay.
- **Caja** = la del diálogo (mismo límite de ancho + misma transparencia); **cierre** de texto/flecha de
  golpe al fade-out. **Salto** A/J o Start/Enter (1ª pulsación completa, 2ª avanza;
  `HH_DLG_KEEP_ORIGINAL=1` para comparar). Hooks **funcionales** siempre; `HH_DLG_PROBE` solo trazas.
- **Corte de página = opcode `F800`** (`f0 00 f8 00`); `FA/FE` se acumulan. Texto por MENSAJE en
  `assets/lang/es.txt`/`ca.txt` (clave = mensaje inglés completo, valor con `\n` "baked"); verificado
  que `dialogos.txt` alinea 1:1 con la ROM (216/216). Runtime: `text::dialogue_message_choice`.

## Cómo probar (Windows)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
hybrid-heaven-recomp\run_windows_release.bat
```
Comparar con el original: `$env:HH_DLG_DY=-64; $env:HH_DLG_KEEP_ORIGINAL=1; ...run_windows_release.bat`.
Trazas: `$env:HH_DLG_PROBE=1` → `build\windows\bin\Release\hh.log`. Variables: nota §9.7
(`HH_DLG_BOX/DX/DY/ALPHA/KEEP_ORIGINAL/TYPE_VI/ARROW/...`). Defaults: `BOX=28,169,292,223`, `ALPHA=95`,
`TYPE_VI=2`.

## Hecho recientemente (2026-10-08, validado en Windows — no reintroducir)

- **Subtítulos de la intro**: skip con **START/ENTER** (A/J ya no cancelan; flanco evaluado también
  armado); **caja = caja del diálogo** (mismo límite/transparencia); **modo attract** (auto-arm al
  entrar en la escena 0x104). Notas `notes/2026-10-08-fix-subtitulos-intro-skip.md`,
  `notes/2026-10-08-subtitulos-caja-igual-dialogo.md`, `notes/2026-10-08-subtitulos-attract.md`.
- **Interpolación — raíz**: límite de discontinuidad de posición en RT64 (`computeTransformMatch`,
  `HH_PAIR_MAX` def. 150; fork `db300ca`) → el objeto 3D del título ya no barre; gate
  `native_title_active` **retirado** (C768 emite en todas las escenas). Nota:
  `notes/2026-10-08-fix-interpolacion-discontinuidad-posicion-titulo.md`.
- Bug del opcode de fin (podía compartir palabra con el último carácter, `A1A9FA00`): corregido en
  `hh_p1800c` (emitir la mitad no-fin antes de cerrar).

## Integración / ramas

El overlay se integró con **squash** en `main`; el rastro del experimento está en el tag
**`exp/overlay-dialogo`** (las ramas del experimento se borraron). **Cambios futuros: rama nueva desde
`main`** (tras un squash, git no ve la rama vieja como fusionada). Detalle:
`notes/2026-10-07-experimento-overlay-dialogo.md` §9.8.

## Diferidos / aparte

- **JA** (juego + intro + final): **POSPUESTO** (requiere ROM JP). Menú JA en kana, deshabilitado.
- **fr/de** de los subtítulos de la intro: sin revisar. **Subtítulos del final**: diferidos.
- **Repaso visual del resto del juego** (overlay del diálogo): mod17 (m28/m29 con traducciones distintas,
  m33, textos largos) y demás módulos.

## Pitfalls (NO repetir)

- **No** concluir visual/sync solo desde headless; validar en Windows (el mantenedor).
- **No** editar el C generado (ADR `0009`); no tocar ROMs/forks/push sin pedir. Un tema = un commit.
- **No** "medir" capturas cuando el mantenedor da una variable exacta. Dudas → preguntar.
- **No** resolver textos diálogo a diálogo: implementación **robusta** o nada.
