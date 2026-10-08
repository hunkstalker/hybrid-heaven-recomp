# 2026-10-07 — Experimento: overlay propio del diálogo (quitar el límite de líneas/caracteres)

> Rama **`experimento-overlay-dialogo`**. Objetivo: **ocultar el texto del juego y dibujar el nuestro**
> (líneas y longitud libres), en vez de reescribir los nodos (vía frágil). Ver ADR `0016`
> (alternativa "overlay propio", descartada entonces). **Handoff: `../RETOMAR.md`.**

## 1. Ruta REAL del dibujo del texto del diálogo (medida)

- El texto del diálogo **NO** pasa por `func_8001B204` (esa es la API de entradas de menú; el hook
  a B204 nunca se dispara en el diálogo).
- El diálogo se compone **carácter a carácter**:
  - **`func_80018E9C`**: dibuja **un** carácter. `a0` = **código EUC**; `a1` = struct de estado (su
    primer `u16` es la **X** que avanza); `a2` = 4; `a3` = offset en la textura de trabajo
    (`0x800F51C0`).
  - **`func_8001800C`**: recibe **2 chars EUC** por llamada (`a0` = `HHHH` = 2 códigos). Primer par
    del mensaje = `0xF000FC00` (cabecera de nodo); `a1=0x8008DA88` (contexto de caja),
    `a2=0x7D0`, `a3=0x140`.
  - **`func_80017BB8`**: procesador de comandos 2D (cola `D_8008EE78`); llama a `8001800C`.
- **Fin de mensaje**: `0xFA00`/`0xFE00`. Salto de línea: `0xF300`/`0xF000`.
- **Avances** (`func_8001BD20`, tablas `jtbl_8004CDF0`/`jtbl_8004CE2C`, base 8 para color4):
  **espacio=6, `.`=4, `,`=6, `'`=4, `f i j l r t`=6**, resto=8. (Corrige una medición previa errónea
  de espacio=4.) Cableado en `hh::font::game::face_glyph_advance` (`src/subsystems/font.cpp`).
- **Caja del diálogo**: `func_8001A804` con formato **`'wa fa'`** (2 params: alfa relleno + alfa
  marco), `a0=0`. El HUD usa `'sx sy sf wa fa'`; el menú, `'px py …'`. → **`'wa fa'` identifica la
  caja del diálogo**.

## 2. Implementado (rama, commits)

- Probe `HH_DLG_PROBE=1` (`text_glyphs.cpp`): hook a `80018E9C`/`1800C`/`17BB8`/`B204` + volcados de
  la caja (`sections.cpp`). **Solo loguea.**
- **Reconstrucción del mensaje** (`hh_p1800c`): acumula los chars de `a0` (2 EUC), mapea acentos
  color4→UTF-8, filtra líneas vacías → `set_dialogue(...)`.
- **Capa de diálogo propia** (`src/platform/overlay.cpp` + `include/hh/overlay.h`):
  `set_dialogue(bool, lines)` con **CAJA FIJA** (no adaptativa, a diferencia de `set_subtitle`),
  texto **alineado a la izquierda**, tipografía `Color4`, interlinea nativa (12), `pad_x=4`.
- **Avances** corregidos (ver §1).
- **Ocultado al acabar** (cableado, sin commitear al cerrar la sesión): `notify_dialogue_box()` (el
  hook de la caja llama cuando el formato es `'wa fa'`) + la capa solo se dibuja si la caja se ha
  visto en < 500 ms.

## 3. Valores del mantenedor (caja / alfa)

- `HH_DLG_BOX="28,169,202,223"` (x0,y0,x1,y1 → caja **28..202 × 169..223**).
- `HH_DLG_ALPHA=95`.
- Se fijaron como **defaults** en `overlay.cpp` (aún overridables por entorno).

## 4. ESTADO y PROBLEMA ABIERTO (importante)

- La **posición** del texto y los **avances** cuadran con el juego (validado por el mantenedor:
  "el texto encaja perfecto").
- **Ancho de caja — RESUELTO**: el valor correcto es **`HH_DLG_BOX="28,169,292,223"`** →
  caja **28..292 × 169..223** (ancho **264**, alto 54). (Ni 174 ni 198; el mantenedor lo confirmó.)

## 5. Pendiente (para la próxima sesión)

1. **Resolver el ancho de caja** (ver §4) con el mantenedor.
2. Usar el **texto EXTENDIDO** (tabla `assets/lang/<code>.dlg.txt`), no el reconstruido del juego
   (hoy la capa muestra el texto conciso reconstruido → idéntico al del juego).
3. **Ocultar el texto original** del juego (hoy se ven **superpuestos**): suprimir la composición del
   diálogo (hook `80018E9C`/`1800C` → no dibujar) manteniendo solo el overlay propio.
4. Verificar el **ocultado al acabar** (la caja `'wa fa'` deja de dibujarse → overlay se oculta).

## 6. Cómo probar (Windows)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
$env:HH_DLG_PROBE=1          # hooks + log [dlgprobe]
$env:HH_DLG_BOX="28,169,202,223"
$env:HH_DLG_ALPHA=95
hybrid-heaven-recomp\run_windows_release.bat
```
Log: `build\windows\bin\Release\hh.log` (líneas `[dlgprobe] MSG …` = mensaje reconstruido).

---

## 7. Sesión 2026-10-07 (implementación del overlay) — detalle

> Premisa del mantenedor: **robusto y 1:1 con el original**; **no** arreglar diálogo a diálogo.
> Handoff: `../RETOMAR.md`.

### 7.1. Ciclo de vida real del diálogo (medido)

- **La caja `'wa fa'` solo se dibuja durante los FUNDIDOS**, no mientras está mostrada:
  - Entrada: `a2` = 9,19,…,95,96 (≈0.33 s; ~11 draws a 30 Hz).
  - Salida: `a2` = 95,86,…,9 (≈0.3 s).
  - Entre medias (todo el diálogo): **cero** llamadas `'wa fa'`.
  → No se puede usar "frescura de la caja" para saber si el diálogo está vivo. Se **latchea**:
  alfa creciente = entrada (abre), decreciente = salida (cierra).
- **El juego compone el mensaje ENTERO en un frame** (todos los `18E9C` de un mensaje en el mismo
  frame). La "escritura" que se ve es **animación**, no composición por carácter.
- **La caja acumula líneas** de varios "mensajes" (`FA00`/`FE00`) hasta un **corte de página**.
  Nuestro overlay reemplaza por mensaje → **pierde la acumulación** (p. ej. "Disculpe.").

### 7.2. Funciones clave

- `func_80018E9C` (`0x80018E9C`): compone **un** carácter del diálogo. Solo lo llama `1800C`.
- `func_8001800C` (`0x8001800C`): procesa **2 chars EUC** por llamada. Inicio de nodo `F000FC00`;
  fin `FA00`/`FE00`; salto `F300`/`F000`. **Bug corregido**: el fin puede compartir palabra `a0` con
  el último carácter (`A1A9FA00` = `?`+fin) y se perdía; ahora se emite la mitad no-fin antes de
  cerrar.
- `func_80019038` (`0x80019038`, opcode `FA00`): dibuja la **flecha** (sprite con `a7==16`).
- `func_80018C9C` (`0x80018C9C`): aplica el **fade** de la caja: `D_8008EE9C += 256/D_8008EBE8`.
- **Flecha (pulso medido con `[dlgar2]`)** sobre el sprite `a7==16`: fade ≈66 ms (3 pasos ~105),
  hold ≈465 ms a 255, off ≈470 ms a 0. Ciclo ≈1.06 s.
- **Caja nativa**: se **suprime** su dibujo (`hh_box_draw_hook`, `'wa fa'` con overlay activo) para
  no dejar el residuo del ~3 %.

### 7.3. Implementado (código)

- **Typewriter por VI** (`overlay.cpp`): `budget = (vi - start_vi) / HH_DLG_TYPE_VI` (def. 2 = 1
  letra/tick 30 Hz). Exactamente 1 letra por periodo.
- **Flecha**: forma ▼ 5×6 (filas de 2 px) extraída del juego; entra un periodo tras la última letra;
  pulso anclado al aparecer (arranca en alpha 0).
- **Caja**: panel/texto siguen `g_dlg_box_alpha` (alfa real del `'wa fa'`).
- **Cierre**: `dialogue_active()` suelta en cuanto el fade-out apaga la caja (`box_a<=24`) o 80 ms
  sin dibujos. Al empezar el cierre, **texto y flecha NO se dibujan** (desaparecen de golpe).
- **Salto**: `dialogue_skip()` (A=`0x8000`/START=`0x1000`) detectado en el **frame de render**
  (`overlay.cpp`), no en los hooks del juego (que solo corren al esperar input).
- **Texto extendido**: `hh::text::dialogue_message_extended` (índice inverso EUC traducida→inglés
  `rev`, `msg_norm` con espacios normalizados). Solo refluye si difiere del conciso.
- **Sondas** (bajo `HH_DLG_PROBE`): `[dlgbox]`, `[dlgfade]`, `[dlgclose]`, `[dlgours]`, `[dlgar2]`,
  `[dlgskip]`, `[dlgprobe] MSG/EXT`.

### 7.4. Problemas abiertos (robustez)

1. **Agrupación/acumulación de mensajes** (bloqueante): mostrar la "página" completa (acumular
   líneas hasta el corte real), no reemplazar por `FA/FE`.
2. **`.dlg.txt` con valores mezclados EN/ES**: `assets/dialogos.txt` `[m9]` deja
   "changers are top secret" en inglés; `assets/lang/es.txt` (por línea) es correcto. No preferir el
   extendido ciegamente; nunca empeorar el conciso.
3. **Saltos de línea**: conservar los originales cuando el extendido no aporta.

### 7.5. Variables de entorno

`HH_DLG_BOX`, `HH_DLG_DX/DY`, `HH_DLG_ALPHA`, `HH_DLG_KEEP_ORIGINAL`, `HH_DLG_TYPE_VI`,
`HH_DLG_ARROW`, `HH_DLG_BLINK_FADE_MS` (66), `HH_DLG_BLINK_HOLD_MS` (465), `HH_DLG_BLINK_OFF_MS`
(470).

---

## 8. Sesión 2026-10-07 (robustez: acumulación por página + decisión del extendido)

> Resuelve los 3 problemas abiertos de §7.4. Compila en Linux; **pendiente validación visual Windows**.
> Handoff: `../RETOMAR.md`. Log de la sesión previa: `build/windows/bin/Release/hh.log`.

### 8.1. El corte de página es el opcode `F800` (medido)

Volcado del módulo 12 (`work/roms/us_retail.z64`, `tools/text/extract_dialogues.py` + hexdump). La
gramática real del script:

| opcode | significado real |
|---|---|
| `F000 FC00` + 4 ceros | **inicio de nodo/conversación** (abre la caja) |
| `F300` (y `F000` suelto) | **salto de línea** dentro del mensaje |
| `FA00` / `FE00` | **fin de mensaje**: para y espera A (`FA00` además dibuja la flecha) |
| `F800` (siempre como `F000 F800`) | **CORTE DE PÁGINA**: limpia la caja; la frase siguiente empieza de cero |
| `F000 FD00` | **fin de nodo** (cierra la caja) |

Ejemplo decisivo (segundo diálogo de Mr.Diaz):
```
0x374E F000FC00            (nuevo nodo)      m5: "Excuse me."
0x3768 F000 FA00 0000 0000
0x3770 F300                (SALTO, no F800)  m6: "This is...your first time to / use a code key, isn't it?"
0x37DE FA00 0000 0000 F000 F800 ...          <- aquí sí corta
```
`m5` y `m6` comparten página → la caja NATIVA los muestra juntos (captura
`dialogos/Captura de pantalla 2026-10-07 222351.png`). Nuestro overlay reemplazaba por mensaje y
perdía `m5`. En cambio `m0..m4` van cada uno precedido de `F000 F800` → página por mensaje. Todas las
páginas observadas tienen **≤4 líneas** (la caja soporta 4), consistente con que `F800` = corte.

### 8.2. Acumulación por página (código)

`hh_p1800c` (`src/hooks/text_glyphs.cpp`): se mantiene `g_page` (líneas de la página). En cada
`FA00/FE00` se añade el mensaje a `g_page` y se publica la página completa; en `F800` y en
`F000FC00` se limpia (`overlay::clear_dialogue_text()`). El **typewriter** solo anima el mensaje
recién añadido: `set_dialogue(visible, lines, animate_from)` guarda los caracteres ya visibles y el
draw arranca su presupuesto en `animate_from` (no reescribe lo anterior). Se preserva el fix del
opcode de fin que comparte palabra con el último carácter (`A1A9FA00` = `?`+fin).

### 8.3. Decisión robusta del texto extendido (`hh::text::dialogue_message_choice`)

Reemplaza a `dialogue_message_extended`. Pasos:
1. Reconstruye las líneas INGLESAS originales desde el EUC del juego: índice inverso `rev`
   (línea ya traducida) o `euc_decode` (línea que quedó SIN traducir → marca **incompleto**).
2. `ext` = `.dlg.txt` por la clave inglesa (cruda y normalizada). `perline` = traducción **por línea**
   (`es.txt`, la autoritativa que corrige el mantenedor).
3. Decide:
   - **conciso incompleto** → `perline` si cubre todas las líneas, si no `ext`.
   - **conciso completo** → `ext` **solo si el conciso es subsecuencia de tokens del extendido**
     (realmente lo extiende); si no, se conserva el conciso.
4. Si lo elegido coincide con el conciso (salvo espacios) → no se cambia nada.

Validación offline (simulación con `es.txt`+`es.dlg.txt`): **módulo 12 → 48/48 conservan el conciso**
(no cambia, como decía la nota); **módulo 17 → 5 mensajes usan el extendido** (incluido el ejemplo
canónico "núcleo del sistema de control **central**…"); `[m9]` ("changers are top secret" mezclado)
queda descartado por el test de subsecuencia. Así **nunca se empeora** el conciso.

### 8.4. Saltos de línea del texto extendido (referencia = líneas originales)

El mantenedor da las correcciones sin saltos; se infieren a partir de las líneas originales.
`overlay::wrap_dialogue_like(text, reference)` reparte el texto en tantas líneas como el original,
con ancho proporcional al de cada línea de referencia (`face_text_width`), sin pasar del ancho de la
caja; si el texto es más largo, el sobrante se envuelve por ancho de caja. `wrap_dialogue(text)` pasa
a ser `wrap_dialogue_like(text, {})` (codicioso puro).

### 8.5. Pendiente

- **Validación visual en Windows** (mantenedor): "Disculpe." + frase siguiente juntos; typewriter del
  mensaje nuevo; `[m9]` en español correcto; módulos 12 sin cambios y 17 con textos extendidos.
- Posible mejora: alinear los saltos a las **palabras finales** de cada línea original (hoy se hace
  por proporción de anchos).

---

## 9. Sesión 2026-10-07 (rediseño: fuente única por MENSAJE en `es.txt`)

> **Supera §8.3-§8.4.** El mantenedor rechazó el enfoque de dos fuentes (`es.txt` por línea +
> `es.dlg.txt` por mensaje) y la heurística de "detectar inglés". Regla: **un solo archivo, la
> unidad es el MENSAJE, saltos "baked" en el valor**, y solo se trabaja con diálogos (menús intactos).

### 9.1. Por qué el índice por LÍNEA no vale (medido en la ROM)

- El texto del guion **se repite**: medido en los módulos de diálogo, **122 líneas** aparecen en ≥2
  mensajes; y hay **32 mensajes** idénticos (26 de ellos entre mod29 y mod31, mismo final reutilizado).
- Casos que rompen el índice por línea: `control system of this shelter,` (mod17 m28 **y** m29) y
  `Johnny Slater!` (mod14 m23 / mod17 m15 **y** m33) exigen traducciones distintas según el mensaje.
  Verificado en los bytes: son **dos posiciones reales distintas** (`0xD9D2` y `0xDA9A` en el mismo
  nodo `0xD924`; el NPC repite la frase), no un artefacto de extracción.
- La **posición** (lo que hace el juego) es única pero frágil/opaca. La unidad con **contexto
  cerrado** es el **mensaje** (lo que compone el juego hasta `FA00/FE00`).

### 9.2. Alineación correcciones ↔ ROM (verificada)

Los bloques `[mNN]` de `assets/dialogos.txt` alinean **1:1 y en orden** con los mensajes extraídos de
la ROM: **216/216** en mod 12,13,14,16,17 (0 desalineados). Por tanto el mapeo corrección→mensaje es
por **posición (módulo, índice)**, sin casar texto.

### 9.3. Diseño final

- **Un solo archivo** `assets/lang/<code>.txt`. Las entradas de diálogo se añaden **al final**, en una
  sección marcada `# --- MENSAJES de diálogo (<code>) ...`, con:
  - **clave = texto inglés del mensaje completo** (líneas unidas con un espacio; normalizado);
  - **valor** = la corrección LARGA (`<lang> (tú)`) si existe —con los saltos "baked" como `\n`—; si
    no, la **traducción por línea ya presente en la tabla de runtime** (`es.txt`), con los saltos del
    original. Esto es clave: `dialogos.txt` tiene valores **obsoletos/mezclados** (p.ej. `[m9]` deja
    "changers are top secret"), mientras que `es.txt` por línea es correcto. Así **no se empeora**
    ningún mensaje.
- Los **menús** (cadenas ASCII) **no se tocan**.
- Duplicados idénticos (2 casos: `What!`, `Ha ha ha ha ha....!!!!`) comparten traducción; la
  herramienta deduplica y avisa si algún día dos idénticos necesitaran valores distintos.
- Los mensajes de **una sola línea** coinciden con su entrada por-línea (misma clave): se **actualiza**
  esa entrada en vez de duplicarla (3 casos reales: m45 "¡Bross!", m47 "Acabo de tener una gran idea.",
  m51 "¡Mierda!").
- Herramienta: **`tools/text/build_dialogue_messages.py`** (`--lang es|ca [--dry-run --show N]`).
  Genera **214 entradas** para `es` (195 por-línea + 19 largas `tú`). Saltos largos: reparto
  proporcional a las líneas originales **capando a ~32 chars/línea** (si la frase es más larga, salen
  más líneas).
- `.dlg.txt` **desaparece** (`es.dlg.txt`/`ca.dlg.txt` borrados): su papel lo cubren las entradas de
  mensaje de `es.txt`.

### 9.4. Runtime (un índice para todo)

- `text.cpp`: `find_message_value(s, joined)` busca la clave del mensaje en el **mismo** `s.index`
  (y `s.norm`, normalizado) del archivo único. Se eliminó la carga de `.dlg.txt`.
- `dialogue_message_choice` ya **no** decide entre fuentes: reconstruye el mensaje inglés
  (`rev`/`euc_decode`), lo une y devuelve el valor del mensaje (con sus `\n`). Si no hay entrada, se
  conserva el conciso (saltos originales).
- El hook (`hh_p1800c`) parte el valor por `\n` y publica esas líneas (typewriter/página igual).
- El **rebuild de arena** (`hh_text_rebuild_dialogues`, etapa 3b del experimento `limites-texto`) queda
  **fuera** de esta rama limpia: el overlay no lo necesita. Se conserva como histórico en
  `notes/2026-10-07-experimento-limites-texto.md` y la herramienta `tools/text/analyze_dialogue_nodes.py`.
- Verificado: en los 19 mensajes `tú` la reconstrucción por `rev` **no** es ambigua (0 fallos).

### 9.5. Estado de validación

- **VALIDADO en Windows (2026-10-07)**: primer diálogo (módulo 12) — el texto aparece correcto, la
  respuesta al input es correcta, y el cierre de la caja se validó comparando con la caja nativa
  (`HH_DLG_DY=-64` + `HH_DLG_KEEP_ORIGINAL=1`; se arregló que `KEEP_ORIGINAL` también dibuje la caja).
- **`ca.txt`**: generado igual con `--lang ca` (214 entradas: 195 per-línea + 19 largas `CA (tú)`;
  m47/m51 actualizados; `[m9]` correcto "canviadors és secreta"). Pendiente la misma validación visual.
- **Pendiente de repaso visual**: resto del juego (mod17: m28/m29 con traducciones distintas, m33,
  textos largos; y el resto de módulos).

### 9.6. Auditoría de `assets/dialogos.txt` (frases no fiables)

Se listaron los bloques cuya corrección ES/CA tenía segmentos en inglés (criterio: segmento que es
literalmente el inglés y con palabra funcional inglesa, para no marcar nombres propios/cognados).
De los 7 detectados, **4 eran fallos reales** (se corrigieron en `dialogos.txt` con los valores
correctos de `es.txt`/`ca.txt`):

- mod12 `[m9]`: "changers are top secret" → "cambiadores es secreta" / "canviadors és secreta".
- mod14 m33 ("But after all…"): "no more than an illusion." → "de paz." / "una il·lusió de pau.".
- mod16 `[m9]`: "However, things could work" → "Sin embargo, todo" / "No obstant això, tot podria".
- mod17 `[m11]`: "programmed into" → "que programé en" / "que vaig programar en les".

Los otros 3 tienen justificación (no se tocan; revisar a futuro): mod14 `[m79]` (cargos/nombres),
mod17 `[m8]` ("Rock and roll, baby!" conservado), mod17 `[m39]` (placeholder: sin contexto).

Además, en `dialogos.txt` se dejó anotado `⚠ REVISAR traducción ES/CA` en **mod14 m33** y **mod16
`[m9]`** (los dos fragmentos que se resolvieron con los valores de `es.txt`/`ca.txt` pero conviene
confirmar).

**Nota**: el runtime **no** se veía afectado por esos 4 (los mensajes "fit" toman el valor por-línea
de `es.txt`/`ca.txt`, que ya era correcto); la corrección alinea la fuente de referencia.

### 9.7. Variables de entorno del overlay de diálogo (para depurar)

Todas se leen una vez (al primer uso); hay que fijarlas **antes** de lanzar. Las dos **clave para
depurar comparando con el original** están marcadas con 🔑.

| Variable | Defecto | Qué hace |
|---|---|---|
| `HH_DLG_PROBE=1` | off | Activa los hooks de sonda y las trazas `[dlgprobe] MSG/EXT`, `[dlgbox]`, `[dlgfade]`, `[dlgclose]`, `[dlgours]`, `[dlgar2]`, `[dlgskip]`. |
| `HH_DLG_BOX="x0,y0,x1,y1"` | `28,169,292,223` | Rect fijo de **nuestra** caja (unidades virtuales 320×240). |
| 🔑 `HH_DLG_DY` (y `HH_DLG_DX`) | 0 | Desplaza **nuestra** caja y su texto sin cambiar el tamaño. **`HH_DLG_DY=-64`** la sube y deja ver la nativa. |
| 🔑 `HH_DLG_KEEP_ORIGINAL=1` | off | Conserva el **texto Y la caja nativos** (para comparar). Sin esto, la caja nativa se suprime. |
| `HH_DLG_ALPHA` | 95 | Alfa del panel negro (0–255). |
| `HH_DLG_TYPE_VI` | 2 | VI por letra del typewriter (VI = 60 Hz; 2 = 1 letra/tick lógico 30 Hz; 0 = instantáneo). |
| `HH_DLG_ARROW=0` | on | Desactiva la flecha ▼. |
| `HH_DLG_BLINK_FADE_MS` | 66 | Fade-in/out de la flecha (ms). |
| `HH_DLG_BLINK_HOLD_MS` | 465 | Hold de la flecha a alpha máximo (ms). |
| `HH_DLG_BLINK_OFF_MS` | 470 | Off de la flecha (ms). |
| `HH_OVERLAY=0` | on | Desactiva **todo** el overlay del port (menús incluidos). |

Comando de comparación (nuestra caja arriba + caja nativa en su sitio):
```powershell
$env:HH_DLG_DY=-64; $env:HH_DLG_KEEP_ORIGINAL=1
```
