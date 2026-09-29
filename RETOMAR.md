# RETOMAR — handoff (2026-09-29)

> Handoff para la próxima sesión. Rama **`menu-edicion-partida`** (nada pusheado; `main` = v0.5.0).
> Reglas: `AGENTS.md`.
>
> **Sesión 2026-09-29 (hecha):** RESUELTO el mapeo de Áreas-Partes / puntos de carga. Documento
> maestro: **`notes/2026-09-29-editor-area-parte-plan.md`** (todo medido: campo `0x564`, fórmula
> `idx=(area-1)*10` de los `N-0`, `EXTRAS > DEBUG NIVELES` con el ciclo F5/F6, `EXTRAS > IR A ÁREA`,
> plantilla `assets/save/template_slot.bin`, `skip_indices.txt`).
>
> **TAREA NUEVA (próxima sesión): Menú propio de CARGAR/GUARDAR partida (slots "infinitos", un `.pak`
> con N slots).** Plan COMPLETO (leer PRIMERO): **`notes/2026-09-29-menu-cargar-guardar-partida-plan.md`**
> (fases, hallazgos `[MEDIDO]`, estrategia A, formato del `.pak` ampliado, metadatos en la cabecera
> `0x100`, nombre `savegame_slot<N>`). La sesión nueva debe empezar por la **Fase 0** de ese plan
> (trazar `func_8013E7C0`/`func_8013E850` con oráculo + probar el `.pak` ampliado a N slots).
>
> **Puntos de guardado aportados por el mantenedor**: registro vivo en
> **`notes/reference/saveedit/PUNTOS_DE_GUARDADO.md`** (cobertura por área + cómo registrar los
> nuevos). El mantenedor puede decir en cualquier momento que ha guardado slots nuevos; ahí se anotan.
>
> **Contexto del mapeo de Áreas-Partes**: `notes/2026-09-29-editor-area-parte-plan.md` (§1 sigue siendo
> el material de partida original; el estado real está al principio de esa nota). Pendientes vivos:
> (a) **validar en Windows** `EXTRAS > IR A ÁREA` + `DEBUG NIVELES`; (b) **diseñar/implementar
> "mover mi partida a una Área-Parte"** (§6bis de la nota: plantilla de zona + datos del jugador);
> (c) **"volver al menú desde el gameplay"** (el idx 7 daba la intro pero hoy crashea: buscar vía).
> Antes del formato del save, leer
> `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md` y
> `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.

---

## 1. TAREA PRINCIPAL — nivel (Área-Parte) del save y carga con `CONTINUAR`

> **La sesión nueva debe EMPEZAR creando un item en `TODO.md` y una planificación/plan de la tarea**
> (pasos numerados + criterio de validación en Windows), y trabajar sobre ese plan. Lo de abajo es el
> material de partida, no el plan hecho.

### Objetivo

Que `EDICIÓN DE PARTIDA` → `PROGRESO` (Área-Parte) **determine de verdad** el nivel que el juego carga
al darle a **`CONTINUAR`**, y que la lista de niveles mostrada sea la **real** (ahora mismo sale
`1-0`…`1-9`, imposible: el área 1 no tiene 9 partes).

### Lo que YA funciona `[VALIDADO en Windows]`

- Editar el slot del `.pak` y **cargar** ya **no cuelga** (`hh::save::save()` llama a
  `hh_pak_reload_from_disk()` del fork NMR `9b14604`; ver nota §9).
- `PROGRESO` = **slot `+0x366`** (u16 **BE**) = global **`[0x801BBBF0+4]`** (ver nota §5).
- Al editar `PROGRESO` (p. ej. `3-1`) y cargar, **sí cambia el TEXTO del área** en la pantalla negra de
  entrada: ese texto sale de la **cabecera** (registro `0x10 + slot*8`: `+1` AREA N, `+2` AREA P).
- **PERO** el mapa/Área-Parte que se carga **sigue siendo el del save**, no el editado.

### El problema / por qué

El **texto** del área usa la cabecera, pero el **mapa** cargado usa otro campo. Hipótesis a confirmar:
- Candidato A: slot **`+0x364`** = `[0x801BBBF0+2]` (el serializer lo escribe junto a `0x366`).
- Candidato B: bloque de **100 B** `0x300..0x363` (copiado del global **`0x8008DC20`** en el save).
- Candidato C: el **struct de personaje** (`0x000..0x09D`).
Determinar cuál lee el flujo de **CARGAR**: `func_801411D0` → `func_801423C8` → `func_80141D08`
(copia el buffer a los globals) → **¿qué global/escena decide el mapa?**

### Niveles Área-Parte (primera cosa a resolver)

El modelo actual es **incorrecto**: `hh::save::valid_points_by_level` (`src/subsystems/save_edit.cpp:595`)
lee la tabla de escenas runtime **`D_80175490`** como **30 niveles × 10 puntos** (`valor = idx*10+punto`)
y de ahí salen `1-0..1-9` en el área 1. **Hay que determinar la enumeración real de Área-Parte**:
- Volcar `D_80175490` en runtime e interpretarla (¿es "sala por área", no "punto por nivel"?).
- Buscar la **tabla de nombres/áreas** que usa el texto del área al cargar (de ahí sale el "área 3").
- Contrastar con el juego real: qué Áreas-Partes **existen** y cómo se numeran (¿N-P? ¿índice 1D?).

### Plan sugerido

1. **Niveles**: identificar la tabla/estructura real de Área-Parte y reescribir `progress_options()` /
   `progress_value_at()` / `progress_index_of()` (`src/subsystems/menu.cpp:332`) para listar solo las
   válidas.
2. **Campo de carga**: trazar quién lee el Área-Parte en el flujo de `CONTINUAR` (arriba) y **contrastar
   con un save real**. Método rápido y fiable: **oráculo/diff** — en el juego, guarda en dos Áreas-Partes
   distintas y compara los `.pak` (qué offsets cambian con la zona). Ese(s) campo(s) es el que el editor
   debe escribir para que cargue donde toca.
3. **Cablear** en `hh::save`: escribir el campo correcto (además de la cabecera) al fijar `PROGRESO`, y
   validar en Windows: editar → `CONTINUAR` → carga en la Área-Parte elegida (texto **y** mapa).
4. `hh::save::save()`: al guardar, mantener cabecera y campo de carga **coherentes**.

### Datos y direcciones `[MEDIDO]` (detalle en la nota)

- Slot: `0x000..0x09D` struct personaje (**u16 LE** en fichero), `0x09E+id*3` técnicas (86),
  `0x1A0+id` items (45), `0x1CD..0x1E6` party, `0x300..0x363` copia 100 B (`0x8008DC20`),
  **`0x364+` bloque u16 de progreso/escena (BE)**; `0x364=[0x801BBBF0+2]`, **`0x366`=PROGRESO**.
- Cabecera `0x100`: magic `"HYBRID HEAVEN"` @`0x00`, checksum @`0xFF` = `sum(0..0xFE)`, registros
  `0x10+i*8`: `+0` presente, `+1` AREA N, `+2` AREA P, `+3` LEVEL, `+4..5` TIME.
- Funciones del juego (`file_024`): `0x801423C8` cargar slot, `0x80142450` guardar slot,
  `0x801422E4`/`0x80142350` leer/escribir cabecera, `0x80141268` flujo GUARDAR, `0x801411D0` flujo
  CARGAR, `0x80141F28`/`0x80141D08` serializar/deserializar `0xD00`.
- Guard de prueba: `work/debug/cac/saves_windows/hh.us.bin.pak` (capítulo **1-1** real).
- Verificación: `HH_SAVEEDIT_TEST=1` (escribe/relee y loguea `[save-edit][test]`).

---

## 2. Estado consolidado de la tanda anterior (2026-09-28, todo VALIDADO en Windows)

Commits en `menu-edicion-partida` (sin push): `cdcbd7a` centrar GRÁFICOS/CONTROLES · `a54f697` MODO
HEAVEN global + ventaja · `07b051a`/`b5136dc` docs/tools · `ad56dfc`/`feb1650` daño de campo ·
`f1ce2fb` stepper ANTIALIASING · `64c50db` VENTAJA + PODER/RESISTENCIA ∞ · `8ba43d2`/`289093e` docs ·
`ac9b6e7` arreglos de UI. **Árbol limpio.**

- **MODO HEAVEN** (EXTRAS, `[extras].heaven`, persistente): al cargar partida aplica ATRIBUTOS/ESTADO 99
  + 86 habilidades; en runtime invulnerabilidad (combate `func_80232D08` y campo `func_80379F04`→scratch
  `0x80388A68`), items no consumibles (`func_8013D520`) y **PODER/RESISTENCIA infinitos**. **No** incluye
  VENTAJA.
- **VENTAJA** (`[extras].advantage`): fuerza `0x801BCC24=2` (back attack). Independiente de HEAVEN.
- **PODER ∞ / RESISTENCIA ∞** (`[extras].infinite_power`/`.infinite_stamina`): `hh_battle_frame_hook`
  pinnea `actual=max` cada frame (PODER `0x801BC042←0x801BC040`, RESIS. `0x801BC046←0x801BC044`); O(1),
  no-op fuera de combate. El `∞` (U+221E) se dibuja vectorial (13×5, con sombra).
- **UI**: ANTIALIASING como stepper `< x2 >` (`Entry::stepper`); sombra de kana (copia negra +1,+1 en el
  overlay porque la fuente no la trae y el dakuten va en la col. 7); cedilla `Ç` dibujada delante de la
  `C`; `DEBUG` centrado.
- **Pendiente conocido (documentado, a afinar)**: la barra de **combo** arranca a 0 en el **1.er
  combate** (se rellena desde el 2.º; va ligada al PODER). Ver `TODO.md` y la nota.

Detalle: `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.

---

## 3. Cómo trabajar (rápido)

- Build Linux: `cmake --build build/linux --parallel $(nproc)`.
- Build Windows: `rmdir /s /q hybrid-heaven-recomp\build\windows` + `hybrid-heaven-recomp\build_windows_release.bat`.
- Traza de combate / campo: `run_battle_trace.bat` (F12), `run_field_watch.bat` (`HH_WATCH_ADDR`).
- Regenerar C recompilado: `python3 tools/regenerate.py` (no se versiona; ADR 0009/0011). Tras regenerar:
  `python3 tools/analysis/fix_fallthroughs.py`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).

## 4. Git / forks

- Rama **`menu-edicion-partida`**; **nada pusheado**. Commitear **solo lo validado o docs, y con
  permiso**. El mantenedor pidió **no pushear** de momento. Push (si se pide): forks primero
  (`N64Recomp`, `N64ModernRuntime`), luego el repo principal (ver `AGENTS.md`).

> **Calibración (AGENTS)**: distinguir "medido" de "inferido"; no concluir comportamiento de ejecución
> sin evidencia (oráculo/Windows); no inventar fórmulas. Un tema = un commit.
