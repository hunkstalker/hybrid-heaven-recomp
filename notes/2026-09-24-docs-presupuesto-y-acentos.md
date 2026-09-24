# Docs: RETOMAR corto, presupuesto de contexto de arranque y aclaración de acentos

> Sesión 2026-09-24 (continuación). Cierra la reorganización de documentación (RETOMAR dejó de hacer
> de documentación), sustituye los topes de tamaño autoimpuestos por un presupuesto de contexto real,
> y aclara el estado de los acentos. Contexto previo: `notes/2026-09-24-a2-*.md`.

## 1. RETOMAR como handoff corto (no documentación)

`RETOMAR.md` había crecido a **303 líneas** y hacía de documentación. Ahora es un **handoff corto**
(~70 líneas): estado, siguiente tarea, método y Git. El contenido durable se movió a su sitio (una
fuente de verdad por tema):

- Diseño del menú → **`docs/menu.md`** (nuevo).
- Técnica del overlay/fuente/alineación/supresión del nativo → **`docs/architecture.md` §7**.
- Receta headless (replay para llegar al menú) → **`docs/workflows.md` §2**.
- Evidencia → `notes/` (ya estaba).

`AGENTS.md` conserva las reglas durables ("no inventar UI"; "distinguir medido de inferido"; "un tema
= un commit") y, de paso, **añadió `RETOMAR.md` a §"Lee esto"** (estaba omitido; `documentation.md`
§3 ya lo pedía).

## 2. Topes de tamaño → presupuesto de contexto de arranque

Motivo: la ventana de contexto es de ~1M tokens y en una época una sesión consumía **~30 %** solo al
ponerse al día. Para controlarlo se habían añadido **topes duros por fichero** (`HARD_LIMITS` en
`tools/analysis/docs_index.py`: AGENTS 110, PROYECTO 140, TODO 170, documentation 120) — **norma
autoimpuesta, sin motivo técnico** (nada de build/juego/runtime lo requiere). Se **retiran**.

En su lugar, el script mide el **set de arranque** (`AGENTS`+`RETOMAR`+`PROYECTO`+`TODO`+
`documentation`+`architecture`) y **falla `--check`** si su **total** supera `STARTUP_BUDGET_TOKENS`
(def. **30k tokens ≈ 120 KB ≈ ~3 % de 1M**; `HH_DOCS_BUDGET_TOKENS` lo ajusta). Reporta siempre el
dato. Los avisos por **>250 líneas** siguen (solo informan; no hay topes por fichero).

- Estado medido (2026-09-24): **6 docs, 62 KB ≈ 15.9k tokens (~1.6 % de 1M)** — margen amplio.
- `docs/documentation.md` §2/§5 y `docs/workflows.md` §7 describen el mecanismo; los "≤N pantallas"
  quedan como **guía editorial**.

## 3. Acentos — dos sistemas distintos y orden acordado

- **Overlay (nuestra UI)**: **no** usa el motor de texto del juego; tiene su propio atlas
  (`hh::font::game`) y **hoy pliega los acentos a ASCII** (`to_ascii`: `ESPAÑOL`→`ESPANOL`). Es el
  **paso 4** de `docs/menu.md` (pendiente).
- **B** (`src/hooks/text_glyphs.cpp`): inyecta glifos acentuados en el **motor del juego** (texto
  in-game: diálogos, HUD, ítems). Implementado, pero **NO validable hoy**: la única cadena traducida
  con tilde (`RESOLUTION=RESOLUCIÓN`, en `es.txt`) vivía en el **menú vanilla**, ya oculto/abandonado,
  y no hay otra cadena con tilde alcanzable. **Aparcado** hasta que traduzcamos texto in-game con
  acentos. **No bloquea el menú.**
- **Orden acordado**: completar el menú (**5** navegación/control total → **6** acciones → **7** SFX)
  **antes** de los acentos (**4**). Al revés no se pueden validar: la raíz no tiene tildes y los
  submenús (que sí) aún no son navegables. Validables con `HH_MENU_SCREEN=7` (GRÁFICOS: RESOLUCIÓN,
  LÍMITE DE FPS) / `=6` (IDIOMA) o navegando.

## 4. Comprobación

- `python3 tools/analysis/docs_index.py --check` → **exit 0** (informa del set de arranque).
- Forzando `HH_DOCS_BUDGET_TOKENS=1000` → **exit 1** (el guardarraíl funciona).
