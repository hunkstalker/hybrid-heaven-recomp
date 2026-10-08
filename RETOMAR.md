# RETOMAR — handoff (2026-10-07, sesión overlay del diálogo)

> **Ramas**: **`main` ya contiene el overlay** (commit `feat(overlay): diálogo propio con texto por
> MENSAJE…`), además de la traducción del diálogo (≈30 %, módulos 12-17). El **rastro completo del
> experimento** (incluido el de `limites-texto`) se conserva en el **tag `exp/overlay-dialogo`**
> (tip `1a334fd`); las ramas `experimento-overlay-dialogo`, `overlay-limpio` y `experimento-limites-texto`
> **se eliminaron** (el tag las cubre). **Para cambios futuros: rama nueva desde `main`.**
>
> **PREMISA (mantenedor)**: implementación **robusta** del overlay del diálogo, **1:1 con el original**
> en todo lo que NO cambiamos (saltos de línea, animación, flecha, cierre, salto con A). **Prohibido
> parchear diálogo por diálogo**: el sistema debe reconstruir el diálogo del juego con fidelidad y
> solo usar el texto extendido cuando de verdad lo extiende. Hay **muchísimos** textos a lo largo del
> juego; cualquier cosa que dependa de casos concretos fallará.

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

- **VALIDADO en Windows (2026-10-07)**: primer diálogo (módulo 12) — texto correcto, respuesta al input
  y cierre de la caja (comparado con la nativa). `HH_DLG_KEEP_ORIGINAL=1` ahora conserva texto **y caja**
  nativos; con `HH_DLG_DY=-64` se ven ambas (ver §9.7 de la nota).
- **Pendiente de repaso visual**: resto del juego — mod17 (m28 vs m29 con traducciones distintas; m33
  "divertido, Johnny Slater!"; textos largos completos) y el resto de módulos.
- `ca.txt` generado; pendiente su validación visual.

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

## La otra tarea (en `main`) — Traducir el diálogo (es + ca)

**Pipeline: `docs/traduccion.md`**; detalle: `notes/2026-10-07-dialogos-traduccion-es-ca.md`.
Cobertura: solo-diálogo = 27 escenas / **872 mensajes / 2173 líneas**. Hecho: módulos **12, 13, 14,
16, 17** (es+ca) → **262/872 ≈ 30 %**. Parcial: **27** (46/109). Pendiente: 18, 19, 20, 21, 26,
28-33, 37, 38, 40, 42-45, 47, 48, 50, 52, 53 y terminar 27. (`main` **4 commits** por delante de
`origin/main`: 3 de traducción + el merge del overlay; sin push.)

## Integración en `main` (squash + tag)

El overlay se integró con **squash** en un único commit, **podando antes la arena** del experimento
`limites-texto` (no la necesita el overlay). El **rastro completo del experimento** (33 commits) queda
en el **tag `exp/overlay-dialogo`**; las ramas `experimento-overlay-dialogo`, `overlay-limpio` y
`experimento-limites-texto` **se eliminaron**. **Cambios futuros: rama nueva desde `main`** (tras un
squash, git no ve la rama vieja como fusionada). Detalle del proceso: nota
`2026-10-07-experimento-overlay-dialogo.md` **§9.8**.

## Diferidos / aparte

- **JA** (juego + intro + final): **POSPUESTO** (requiere ROM JP). Menú JA en kana, deshabilitado.
- **fr/de** de los subtítulos de la intro: sin revisar. **Subtítulos del final**: diferidos.
- **BUG aparte**: subtítulos de la **intro al skipear** (siguen saliendo al entrar al gameplay).

## Pitfalls (NO repetir)

- **No** concluir visual/sync solo desde headless; validar en Windows (el mantenedor).
- **No** editar el C generado (ADR `0009`); no tocar ROMs/forks/push sin pedir. Un tema = un commit.
- **No** "medir" capturas cuando el mantenedor da una variable exacta. Dudas → preguntar.
- **No** resolver textos diálogo a diálogo: implementación **robusta** o nada.
