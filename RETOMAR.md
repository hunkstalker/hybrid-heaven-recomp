# RETOMAR — handoff (2026-10-01)

> Handoff para la próxima sesión. **Rama de trabajo: `menu-carga-guardado-partida`** (creada desde
> `menu-edicion-partida`; nada pusheado; `main` = v0.5.1). Reglas: `AGENTS.md` y `docs/documentation.md`.
> Último commit de la rama: **`874b9f6`** (título del Área al cargar partida). (El editor/niveles vive en
> `menu-edicion-partida`.)

## 🎯 TAREA ACTUAL: unificar TODAS las traducciones en `assets/lang/*.txt` (Opción A)

Hoy las traducciones están en **dos mecanismos con claves distintas**: la **UI del port** en código
(`kMenuTr` en `menu.cpp`, ~170; `kAreaNames`; clave = **español**) y el **texto nativo de la ROM** en
datos (`assets/lang/<code>.txt`, clave = **inglés**). Objetivo: **una sola fuente** (ficheros por
idioma), clave = **texto original en inglés**; el código solo referencia **claves**. Beneficio extra: un
jugador puede corregir una traducción editando el `.txt` sin recompilar.

**Plan completo (leer antes de empezar): `notes/2026-10-01-i18n-unificar-traducciones-plan.md`.**

### Resumen del plan
- **Clave = inglés** (la que ya usan los `lang/*.txt` y la que necesita la sustitución nativa). `en` =
  identidad (sin fichero). Formato `.txt` sin cambios (`CLAVE=VALOR`, `^` = centrado).
- **API**: `hh::text::translate(key)` (búsqueda **exacta**; devuelve la clave si no hay o `en`);
  `hh::menu::localized` **delega** en ella. La sustitución nativa (`hh_text_translate_guest`) queda igual
  (misma tabla). **`kEndonyms` se quedan en código** (no son traducción); **`kEsDefaults` fuera**;
  *override* por mods **aplazado**.
- **Pasos**: (1) `translate()` + declaración en `include/hh.h`; (2) script de migración
  (`tools/text/`) que genere `assets/lang/{es,ca,fr,de,ja}.txt` desde `kMenuTr` + `kAreaNames` + lo ya
  existente; (3) claves de la UI a inglés (`menu.cpp`, `menu_overlay.cpp`); (4) nombres de Área por clave
  (`kAreaKey[9]`); (5) borrar `kMenuTr`/columnas; (6) retirar `kEsDefaults`; (7) docs (`architecture.md`
  §7, `menu.md`, `INDEX.md`) y nota.
- **Validación**: build + F5 (todos los idiomas), sustitución in-game, editar un valor y verlo, `ja` kana.
- **Riesgos**: colisiones de clave (misma cadena inglesa con distinto sentido), `=`/`\t`/`\n` en claves,
  longitud de registros nativos, glifos (acentos/kana/∞), reload en vivo.

### Hecho reciente — commit `874b9f6`: título del Área al cargar partida
Al cargar un slot, el nombre del Área (gráfico nativo intraducible) se pinta con **overlay propio**:
telón negro + `AREA N` (fuente del juego) + nombre en **Work Sans SemiBold incrustada**, traducido en
`en/es/ca/fr/de` (`ja` nativo). **Calibrado 1:1** con el original (ancho/alto/peso/métrica) y **salto de
línea** centrado cuando no cabe en el ancho visible (p. ej. 4:3). Candado anti-parpadeo; timing colgado
de la cadena nativa. Fuente **incrustada** (sin `.ttf` suelto; `licences/OFL.txt`). Además, reorg de
carpetas junto al exe: `assets/{lang,logos,sounds}`, `licences/`, `saves/{,templates}`. Detalle:
`notes/2026-10-01-titulo-area-carga.md` y `...-calibracion.md`.
- **Pendiente menor**: recompilar Windows (limpio) para regenerar estructura + embebido.
- **Decisión abierta**: ¿inglés usa overlay (actual) o nativo 1:1 (cambiar `!= "ja"` por `!= "en"`)?

> Nota: el bloque de traducción de la UI se **reutilizará** en la TAREA ACTUAL (los nombres de Área y las
> etiquetas del menú pasarán a ser claves en `assets/lang/*.txt`).

---

## VALIDADO en Windows (2026-10-01): UI de CARGA en `CONTINUAR` (`LoadGame`)

Tarea anterior, **HECHA y VALIDADA**. Documento maestro: **`notes/2026-10-01-cargar-partida-continuar.md`**.
- **Entrada** `CONTINUAR`: título → UI de carga **limpia** (sin superposición del título/logo, sin
  parpadeo, sin retardo). `g_load_enter` + hook `func_800179B0` (no dibuja el aviso de Controller Pak).
- **Carga real** (A): deserializa el slot (`func_801423C8`) y arranca la escena replicando la rama de
  ÉXITO nativa (`func_80142570` + `func_800179B0` + `func_801C11BC` + callback `func_801C3E24`).
- **Borrado** (X): `Remove play data?` → `Remove completed.` → A vuelve a la lista.
- **Vuelta** (B): cinemática nativa → **menú de título** (fix `close_load_game` retira `LoadGame`).
- Flujo por fases `hh::menu::LoadPhase` (`Browse`/`ConfirmDelete`/`Removed`, +`Loaded` reservado).
- Traza de diagnóstico: `run_load_trace.bat` (`HH_LOAD_TRACE`).

> Nota: la carga sigue siendo **DIRECTA** (`hh_do_load_game`, rama de ÉXITO replicada). Se probó a
> dejar que la máquina nativa del file-select hiciera `state 2→3→4` inyectándole A, pero se **congela
> en state 3** (su gate de mensaje `D_8008EE78` no se limpia en el port). Verifica: `notes/2026-10-01-titulo-area-carga.md` §3.

### Guardado (`DATA SAVE`) — VALIDADO (2026-09-30 / 10-01)
Guardar (`NEW GAME`/sobrescribir) · **AREA 1-1** · **TIME** · salida de la cápsula · reentrada ·
borrado de slots · mensaje de `Select` con bindings. Detalle:
**`notes/2026-09-30-save-capsule-logica.md`** (su §8ter: borrado; §9: recetas reutilizables).

---

## Aviso de método (AGENTS)
- Distinguir **medido** de **inferido**; no concluir comportamiento de ejecución sin evidencia
  (oráculo/Windows); no inventar UI ni fórmulas.
- **Un tema = un commit**; **no commitear/pushear** sin que lo pida el mantenedor.
- No validar el caso "todo vacío" con un `.pak` con datos.

### Pendientes menores (aparcados)
- **JA**: restos sin consolidar (`Face::Color1`, `？/！` en `jp_kana.h`); kana útil solo de
  `color0`/`color1`; el kanji vive en `color3` **JP** (no lo tenemos).
- **UI de GUARDAR**: sigue publicándose como COPIA de la de cargar sobre el DATA SAVE nativo; afinar
  a 1:1 si se pide.

---

## Contexto vivo
- **DEPENDENCIA DE FORK:** la rama necesita 2 commits de `N64ModernRuntime`: `9b14604`
  `hh_pak_reload_from_disk()` y `3523bf3` `PAK_SIZE=0x40000` (publicado). Gitlink bumpeado en
  `dbb209a`. ADR: `docs/adr/0013-pfs-virtual-ampliado-y-pak-de-n-slots.md`.
- **Plan de fondo**: "Menú propio de CARGAR/GUARDAR partida (un `.pak` con N=74 slots: 45 partidas +
  29 plantillas, trailer de metadatos)": **`notes/2026-09-29-menu-cargar-guardar-partida-plan.md`**.
  UI Fase 2/3: `notes/2026-09-29-menu-cargar-guardar-fase2-ui.md`. Tipografías:
  `notes/2026-09-30-tipografias-data-load-hallazgos.md`.
- **ESTRATEGIA DE MERGE**: `menu-carga-guardado-partida` es **DERIVADA** → **no** va a `main`. Al
  terminar: merge a **`menu-edicion-partida`**; luego → **`main`**.
- **Puntos de guardado del mantenedor**: `notes/reference/saveedit/PUNTOS_DE_GUARDADO.md`.
- **Áreas-Partes**: `notes/2026-09-29-editor-area-parte-plan.md`. Pendientes vivos: (a) validar en
  Windows `EXTRAS > IR A ÁREA` + `DEBUG NIVELES`; (b) "mover mi partida a una Área-Parte" (§6bis);
  (c) "volver al menú desde el gameplay" (el idx 7 daba la intro pero hoy crashea).

---

## Cómo trabajar (rápido)
- Build Linux: `cmake --build build/linux --parallel $(nproc)`.
- Build Windows: `rmdir /s /q hybrid-heaven-recomp\build\windows` + `hybrid-heaven-recomp\build_windows_release.bat`.
- Traza de carga: `hybrid-heaven-recomp\run_load_trace.bat`. Guardado: `run_save_trace.bat`.
  Combate/campo: `run_battle_trace.bat` (F12), `run_field_watch.bat` (`HH_WATCH_ADDR`).
- Regenerar C recompilado: `python3 tools/regenerate.py` (no se versiona; ADR 0009/0011). Tras
  regenerar: `python3 tools/analysis/fix_fallthroughs.py`.
- Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).

## Git / forks
- Rama **`menu-carga-guardado-partida`**; **nada pusheado**. Commitear solo lo validado/docs y con
  permiso. Push (si se pide): **forks primero** (`N64Recomp`, `N64ModernRuntime`), luego el repo
  principal (ver `AGENTS.md`).
