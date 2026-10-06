# RETOMAR — handoff (2026-10-06)

> Rama **`subtitulos-intro`** (parte de `main`). Tarea de la sesión: **subtítulos de la intro/prólogo**.
> Motor + datos + i18n + ancla **HECHOS y validados headless**; **siguiente: adaptarlos a 4:3**.
> Detalle: **`notes/2026-10-06-subtitulos-intro.md`**. Reglas: `AGENTS.md`, `docs/documentation.md`.
> (La épica FPS / transiciones sigue en `TODO.md`; no es la tarea de esta rama.)

## Estado (2026-10-06)

- **Motor**: capa de subtítulos en el overlay (`hh::overlay::set_subtitle`; `Face::Color4` = tipografía
  del diálogo in-game) + subsystem `hh::subtitles` (timing + textos por idioma, reloj por **VI**,
  **líneas fijas** `[N]`, paginado **balanceado por ancho**, cortes `---`, **skip** con A).
- **Ancla robusta**: al **fin de la 2ª oleada de cargas** de la escena 0x104 (coincide con la
  campanada; +12.15 s desde `EMPEZAR PARTIDA`). Independiente de la carga entre PCs y del audio.
- **Datos**: referencia editable `notes/reference/Hybrid-Heaven-Intro-Dialogues.txt` (formato
  `[N][IN] [OUT]` + texto) → `tools/text/build_subtitles.py` → `assets/subtitles/*.timing.txt` +
  `assets/lang/subtitles_<code>.txt` (en/es/ca/fr/de). Preview: `tools/text/preview_subtitles.py`.
- **Pendiente inmediato**: validar en Windows; luego **4:3**.

## TAREA SIGUIENTE — adaptar los subtítulos a 4:3

En 4:3 el juego va **pillarboxeado**; hay que comprobar que la capa de subtítulos (posición, ancho de
línea, panel, **líneas fijas**) sigue 1:1. Pistas:
- La proyección del overlay es **uniforme y centrada** (mitad del área virtual **320**); el wrap usa
  `hh::overlay::visible_width()` (320 en 4:3, ~427 en 16:9). Repasar `src/platform/overlay.cpp`
  (bloque de subtítulos) y `src/subsystems/subtitles.cpp` (`max_w`).
- Probar headless forzando `[video] aspect = 4:3` (o el atajo F1) y capturar la intro.
- **Vías a analizar**: (a) confiar en `visible_width` + centrado en 160 (probablemente ya vale);
  (b) usar el **área 4:3 real** del framebuffer (letterbox/pillarbox) en vez del ancho visible;
  (c) ajustar el **ancho máximo de línea** por aspecto. Decidir con captura pareada.

## Instrumentación

- `HH_SUBTITLES=0` desactiva; `HH_SUB_TRACE=1` traza líneas/páginas/ancla; **`HH_SUB_OFFSET_MS=<ms>`**
  (positivo = subtítulos **antes**).
- `HH_AUDIODUMP=<f>` (+ `HH_AUDIODUMP_MB=<n>`) vuelca PCM; `HH_AUDIOLOG=1` log de buffers.
- `HH_MENU_TRACE=1` (EMPEZAR PARTIDA, `goto pantalla`), `HH_SCENE_TRACE=1`, `HH_SAVE_TIME_TRACE=1`.

## Run (mantenedor)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Pitfalls (NO repetir)

- **No** concluir sync/visual solo desde headless; validar en Windows.
- La campanada es **BGM** (no hay disparador de SE); **no** usar onset de audio como ancla (depende de
  volumen/driver/música).
- Los tiempos del `.txt` son **relativos al inicio de la cinemática** (no a `EMPEZAR PARTIDA`).
- Un tema = un commit; no editar el C generado; no tocar ROMs/forks/push sin pedir.
