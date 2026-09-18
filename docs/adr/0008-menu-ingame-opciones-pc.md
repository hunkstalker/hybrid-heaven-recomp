# ADR 0008 — Menú in-game de opciones PC (reutilizando el menú del Expansion Pak)

- **Estado**: Aceptado (2026-09-18; implementación pendiente, tras el cache de assets)
- **Fecha**: 2026-09-18
- **Contexto relacionado**: `../../notes/2026-09-18-suavizado-fase1-y-cache-loader.md` §6,
  `../../notes/archive/2026-09-11-proyecto-legacy.md` §4.4-4.5,
  `../../notes/2026-09-13-arranque-memsize-y-accesorios.md`, ADR 0002, ADR 0007.

## Contexto

Los ports del ecosistema N64Recomp suelen reutilizar el **launcher común** (elegir ROM + ajustes
gráficos; plantilla de Zelda64Recomp). Este repo no lo tiene (el exe exige `baserom.us.z64` y lee
`config.ini`). El mantenedor quiere que el port **se sienta nativo de PC**: opciones dentro del
propio juego, como si se hubiera desarrollado para PC (referencia: el port **decomp** de Perfect
Dark, que integra su menú in-game). Se acepta una experiencia distinta al original N64.

Datos relevantes del binario: el juego tiene un módulo dedicado **`expansionram`**
(`/game/source/expansionram.c` conservado como ancla en la ROM) con un menú de **3 resoluciones
(Low / High Normal / High Letterbox)**. En el port la RDRAM es siempre 8 MB (Expansion Pak
presente), así que ese menú es prescindible y es el sitio natural para las opciones de PC. El
runtime ya expone `GraphicsConfig` (WindowMode, `msaa_option`, `resolution`, filtrado,
`developer_mode`) + mejoras de RT64, con `update_config`/`trigger_config_action` y persistencia.

## Decisión

**Implementar un menú in-game de opciones PC reutilizando la pantalla del Expansion Pak**
(módulo `expansionram`), conservando el UI/fuentes/navegación del juego y sustituyendo las
opciones y sus acciones:

1. **Localizar** el módulo `expansionram` (carga, tabla de opciones, handler de confirmación y
   formato de la lista) usando el path `expansionram.c` como ancla de símbolos.
2. **Handler**: reimplementarlo (ADR 0002) o engancharlo con `[[patches.hook]]` para aplicar cada
   opción a `GraphicsConfig` (+ RT64) y **persistir** en la config del port.
3. **Textos**: rótulos de las opciones nuevas (sistema de texto del juego; encoding custom).
4. **Opciones** (a concretar): resolución/escala, antialiasing, filtrado de texturas, vsync, límite
   de presentación, modo de pantalla (ventana/borderless/fullscreen); más adelante idioma (traducción)
   y mando.
5. **Descartar** el launcher del ecosistema como opción principal; el "elegir ROM la primera vez"
   queda cubierto por el cache de assets (ADR 0007) y, si acaso, un prompt mínimo de primera
   ejecución.

## Consecuencias

- Positivas: sensación de **port nativo**; opciones en el sitio natural; aprovecha el sistema de
  texto (útil también para la traducción); sin dependencia de ImGui/launcher externo.
- Riesgos/trabajo: identificar con precisión la lógica del `expansionram` y su formato de lista;
  recompilar el árbol al reimplementar/enganchar; aplicar cambios de gráficos **en vivo** depende de
  RT64 (si no, puede requerir reinicio); mantener el estilo visual del juego.
- Alternativas descartadas: launcher ImGui estilo ecosistema (menos "nativo", más dependencias).

## Criterio de salida

- El menú del Expansion Pak muestra las opciones PC, navegable con mando/teclado, aplica y persiste
  cada ajuste (verificado tras reiniciar), y los textos se ven con las fuentes del juego.
- Sin regresiones en el resto del juego (front-end, guardado, cinemáticas).
