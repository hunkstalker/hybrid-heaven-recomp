# RETOMAR — handoff (2026-10-07)

> **Última sesión**: **contenido de la traducción del diálogo (es + ca)**. Traducidos completos los
> módulos **12, 13, 14, 16 y 17** y corregido un **bug de cobertura** (líneas con espacios
> extremos). Cobertura **≈ 30 %** del diálogo (solo-diálogo). Detalle:
> `notes/2026-10-07-dialogos-traduccion-es-ca.md`; normativa: **`docs/traduccion.md`**; decisión:
> **ADR 0016**. Reglas: `AGENTS.md`, `docs/documentation.md`.
>
> **TAREA EN CURSO**: **traducir TODO el diálogo del gameplay a español (es) y catalán (ca)** —
> siguiente módulo: **18** (luego 19, 20, 21, 26, 28-33, 37, 38, 40, 42-45, 47, 48, 50, 52, 53; y
> **terminar el 27**).

## TAREA SIGUIENTE — Traducir todo el diálogo (es + ca)

**Lee primero `docs/traduccion.md`** (pipeline, reglas y herramientas). Resumen operativo:

1. **Extraer** las líneas/mensajes por módulo:
   `python3 tools/text/extract_dialogues.py --rom work/roms/us_retail.z64 --module N`
   (o `--all --tsv work/dialogues/us.tsv --unique work/dialogues/us_unique.txt`).
2. **Traducir EN→ES** (español de España) usando como referencia
   `work/dialogues/us_de_fr.tsv` (DE/FR oficiales de la EU) y, para párrafos completos, el **guion
   inglés de GameFAQs** (*Hybrid Heaven - Game Script*, Pandora_aden). Luego **ES→CA**.
3. **Escribir** en `assets/lang/es.txt` y `assets/lang/ca.txt` (clave = línea inglesa **exacta**).
4. **Validar**: `python3 tools/text/check_dialogue_fit.py --lang es` (y `--lang ca`) — avisa de los
   mensajes que **no caben** y da la cobertura.

**Reglas clave (ver `docs/traduccion.md` §5)**:
- **Presupuesto A+ = caracteres del mensaje inglés** → redactar **conciso**; ancho de caja ~**30-32**
  chars/línea.
- **Nombres propios = línea oficial** (p. ej. **`Gargatuan`** se queda igual que en inglés).
  **Ante dudas de traducción (nombres, neologismos, convenciones): PREGUNTAR al mantenedor.**
- **No** asumir índice de módulo = área/orden del juego (son escenas).
- Acentos son caracteres reales (el motor los dibuja por color4).

**Código/estado**: motor en `src/subsystems/text.cpp` (EUC + A+) y `src/hooks/text_glyphs.cpp`
(inyección color0/color4); fuente `include/hh/game_font_color4.h` (`tools/text/build_font.py`). El
texto del diálogo va **inline en “nodos”** EUC-JP; **no** se mueve memoria (ruta B descartada).

**Cobertura actual (2026-10-07)**: alcance **solo-diálogo** = 27 escenas / **872 mensajes / 2173
líneas únicas**. Hecho: módulos **12, 13, 14, 16, 17** (completos, es + ca) → **262/872 mensajes
≈ 30 %**. Parcial: **27** (46/109). Pendiente: 18, 19, 20, 21, 26, 28-33, 37, 38, 40, 42-45, 47, 48,
50, 52, 53 y terminar el 27. (Los 936/2509 totales incluyen UI/menú, fuera de alcance.)

## Diferidos / aparte

- **JA** (juego + intro + final): **POSPUESTO** (requiere procesar la ROM JP). Menú JA en kana
  (`include/hh/jp_kana.h`), deshabilitado.
- **fr/de** de los subtítulos de la intro: sin revisar (el mantenedor no domina esos idiomas).
- **Subtítulos del final**: diferidos (no validables sin llegar al final).
- **BUG aparte**: subtítulos de la **intro al skipear** (siguen saliendo al entrar al gameplay).

## Run (mantenedor)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
hybrid-heaven-recomp\run_windows_release.bat
```

## Pitfalls (NO repetir)

- **No** concluir visual/sync solo desde headless; validar en Windows (el mantenedor).
- El diálogo lo dibuja **el juego** (loader `trans`), no el overlay (eso son los subtítulos de la intro).
- **No** editar el C generado (se regenera; ADR `0009`); no tocar ROMs/forks/push sin pedir.
- En títulos: `Gargatuan` NO se traduce (línea oficial). **Dudas → preguntar al mantenedor.**
- Un tema = un commit.
