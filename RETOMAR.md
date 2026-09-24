# RETOMAR — handoff

> **Handoff para la próxima sesión** (última: **2026-09-24**). Este archivo debe ser **corto**: estado,
> siguiente tarea y Git. El **diseño** y la **técnica** viven en `docs/` y `notes/`; aquí solo se
> enlazan (no duplicar). Reglas de trabajo: `AGENTS.md`.

## Estado

- **A2 (overlay del menú inicial)**: render hook de RT64 + plume + atlas RGBA8 de la fuente del juego.
  Validado en Windows en la fase A (`notes/2026-09-23-a2-render-hook-y-atlas.md`).
- **`hh_menu` (2026-09-24)**: modelo del árbol + dibujo 1:1 (fuente + flecha nativa) + navegación
  arriba/abajo; **menú nativo oculto por defecto** (F6 lo alterna).
  **Los 3 bugs del overlay VALIDADOS en Windows (2026-09-24)**: 1) bearing de "MODO COMBATE";
  2) nativo al volver atrás (**tercer set** de etiquetas); 3) cierre del overlay (instantáneo).
  Commit `82df034`. Ver `notes/2026-09-24-a2-*`.
- Diseño del menú: **`docs/menu.md`**. Técnica (overlay/fuente/alineación/supresión del nativo):
  **`docs/architecture.md` §7**. Evidencia: `notes/2026-09-24-a2-ocultar-menu-nativo-dos-tablas.md`,
  `notes/2026-09-24-a2-overlay-alineacion-y-cierre.md`.

## Siguiente tarea

Continuar `hh_menu` por los pasos 4–8 de **`docs/menu.md` §Estado de implementación`**:

4. **Etiquetas propias** (tabla del port; quita el límite de 15 caracteres de los campos del juego) e
   integración con el sistema de idiomas (A1/B).
5. **Navegación propia** (A/B/X + selectores) y **neutralizar el input del handler nativo** (control
   total). Terreno hecho: `feed_menu_navigation` (arriba/abajo).
6. **Acciones**: mapear cada entrada a la función del juego (continuar, nueva partida, modo combate,
   ajustes, resolución…), pantalla a pantalla.
7. **SFX** desde los eventos del modelo, retirando el puente actual.
8. **Validar en Windows.**

Alcance: **solo el árbol de menús** (estructura, navegación y dibujo). **NO** persistir la config
todavía (los selectores cambian en memoria).

## Pendiente inmediato

- **Validar B (acentos)** en Windows: la inyección compila ("25 glifos inyectados") pero no se ha visto
  en pantalla (afecta a los rótulos de idioma: ESPAÑOL, CATALÁN, FRANÇAIS…).
- **Push** de `main` cuando se decida (orden y `--force-with-lease`: `AGENTS.md` §Push).

## Método (rápido)

- **Build/run Windows**: `AGENTS.md` (build) + `docs/BUILDING_windows.md`.
- **Headless + replay para llegar al menú**: `docs/workflows.md` §2.
- **Diagnósticos** (`hh.log`): `HH_MENU_TRACE=1` (traza de composición y pantallas), `HH_NATIVE=1`
  (muestra el nativo al arrancar; equivale a F6), `HH_OVERLAY_X/Y/SX/SY`, `HH_OVERLAY=0`,
  `HH_MENU_SCREEN=<id>`, `HH_FONT_TRACE=1`, `HH_ACCENTS=0`, `HH_LANG=es`. Atajos: F2 aspecto, F3
  ventana, F4 MSAA, F5 idioma, **F6 menú nativo**. Inspector de RT64: `HH_DEVELOPER=1` + F1.
- **Regla ROM**: no tocar ROMs/`work/*.so` sin permiso. ROM de análisis: `/app/baserom.us.z64`
  (Windows: `build\windows\bin\Release\hh.us.z64`).

## Git (estado al cerrar esta sesión)

- **`main` local** (SIN push): `HEAD = 82df034`; **árbol limpio**. Commits de código de la sesión:
  `2181fab` (hh_menu: modelo + dibujo 1:1 + navegación + nativo oculto, sets A/B), `4e4cf1e` (bugs 1 y
  2 del overlay: bearing + set C) y `82df034` (bug 3: cierre instantáneo). El resto son docs.
- Sesiones previas: `8265b9d`, `5867de5` (overlay A2), `d6f4afb` · `de99550` · `b95c6a4` (SFX).
  `c2ce652` (hh_menu) y `3aede33` (SFX submenús): **REVERTIDOS/eliminados**.
- **`origin/main` = `c977bd5` (v0.4.0)**. Locales sin push: `ac4a89f` (traducción/idiomas), arreglo del
  pin de rt64, `22e3eed` (ratón).
- **`lib/rt64`** (fork): `hybrid-heaven` = `a8f0a70` (gitlink correcto). **`N64ModernRuntime` /
  `N64Recomp`**: en sync. Tags: `v0.1.x`…**`v0.4.0`**; próximo `v0.4.1`.
- Push normal de `main` pendiente (**requiere `--force-with-lease`**; ver `AGENTS.md` §Push).
