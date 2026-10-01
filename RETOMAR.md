# RETOMAR — handoff (2026-10-01)

> Handoff para la próxima sesión. **Rama de trabajo: `menu-carga-guardado-partida`** (creada desde
> `menu-edicion-partida`; nada pusheado; `main` = v0.5.1). Reglas: `AGENTS.md` y `docs/documentation.md`.
> (El trabajo del editor/niveles vive en `menu-edicion-partida`.)
>
> ## 🎯 TAREA ACTUAL (siguiente sesión): el TÍTULO DEL ÁREA no aparece al cargar una partida
>
> **Comportamiento normal del juego** al cargar un slot (`CONTINUAR` → elegir partida): la pantalla
> queda **en negro unos segundos** con un **título en blanco = el nombre del Área** por donde va el
> progreso del jugador (**solo el nombre, sin números**). Ese texto se quita pulsando un botón/tecla
> (o esperando); **entonces** ya se
> ve el render del gameplay, el PJ saliendo de la cápsula de guardado.
>
> **FALLO actual (port):** ese **título de Área NO aparece**; solo se ve la pantalla en negro unos
> segundos y luego el PJ saliendo de la cápsula. **Falta visualizar el título del Área.** `[VALIDADO
> en Windows por el mantenedor, 2026-10-01]`.
>
> ### Pistas de partida (a confirmar; NO fiarse sin trazar)
> - El estado de "pantalla negra + título" lo lleva el flujo de ÉXITO nativo que el port replica en
>   `hh_do_load_game` (`src/hooks/sections.cpp`): `func_801423C8(0, slot)` →
>   `func_80142570()` + `func_800179B0(0)` + `func_801C11BC(0xA)` + `func_800058DC(obj, 0x801C3E24)`,
>   con `D_801CC8CC=2` (ver `notes/2026-10-01-cargar-partida-continuar.md` §3).
> - La pantalla negra/título probablemente la monta/compone `func_801C3E24` y su cadena
>   (`func_8013EA54`, `func_801C3F48`, `func_801C4074`: transición `func_8012FE50(0x18, D_801BBBF4, 6,
>   1, 0)` usando el índice de escena del slot). **Hipótesis a trazar**: qué función compone el TEXTO
>   del Área y por qué no sale (¿se compone con `func_8001B204` y lo estamos saltando? ¿el `hide_now()`
>   o el `set_file_select_active(false)` lo tapan? ¿el título lo dibuja el propio Sistema de Texto del
>   juego y no llega a componerse?).
> - OJO: nuestro `hh_entry_register_hook` (compositor `func_8001B204`) **salta** el texto del
>   file-select mientras la categoría FILE-SELECT está activa y el nativo oculto. Verificar que, al
>   salir de la carga, esa categoría queda **desactivada** (ya se hizo en `hh_do_load_game`) y que el
>   texto del Área (post-file-select) **sí** se compone.
> - El dato del Área sale de la **cabecera** del slot (registro `0x10 + slot*8`: `+1` AREA N, `+2`
>   AREA P) — ver `notes/2026-09-29-editor-area-parte-plan.md` §5. OJO: esos campos son los **datos
>   fuente** (números); el **texto que se muestra es SOLO el NOMBRE del Área**, sin números.
>   Comprobar que `func_801423C8` deja el dato disponible para el compositor del título y localizar la
>   **tabla nombre↔área** (o la función) que convierte el índice en el nombre mostrado.
>
> ### Plan sugerido (crear item en `TODO.md` + plan antes de tocar código)
> 1. **Trazar** el flujo de ÉXITO de cargar (`func_801C3E24` y cadena) con `HH_SCENE_TRACE`/`HH_TRACE`
>    (hooks ya existentes: `hh_scene_transition_hook`, `hh_scene_load_hook`) y localizar **quién
>    compone/dibuja el título del Área** y en qué frame.
> 2. Comparar con el **flujo nativo** (CONTINUAR sin overlay, o `HH_OVERLAY=0`) y con un save real:
>    ¿el título sale en el nativo? ¿qué función/handler lo pinta?
> 3. Verificar que nuestro overlay/hooks no lo suprimen (categoría FILE-SELECT aún activa, `hide_now`,
>    compositor de texto saltado, blackout…).
> 4. Cablear/QS la composición (o dejar pasar la función correcta) y **validar en Windows**: cargar →
>    pantalla negra con **título de Área** → botón/espera → gameplay.
>
> ---
>
> ## VALIDADO en Windows (2026-10-01): UI de CARGA en `CONTINUAR` (`LoadGame`)
>
> Tarea anterior, **HECHA y VALIDADA**. Documento maestro: **`notes/2026-10-01-cargar-partida-continuar.md`**.
> - **Entrada** `CONTINUAR`: título → UI de carga **limpia** (sin superposición del título/logo, sin
>   parpadeo, sin retardo). `g_load_enter` + hook `func_800179B0` (no dibuja el aviso de Controller Pak).
> - **Carga real** (A): deserializa el slot (`func_801423C8`) y arranca la escena replicando la rama de
>   ÉXITO nativa (ver la TAREA ACTUAL arriba).
> - **Borrado** (X): `Remove play data?` → `Remove completed.` → A vuelve a la lista.
> - **Vuelta** (B): cinemática nativa → **menú de título** (ya no reaparece la carga; fix
>   `close_load_game` retira `LoadGame` de la pila).
> - Flujo por fases `hh::menu::LoadPhase` (`Browse`/`ConfirmDelete`/`Removed`, +`Loaded` reservado).
> - Traza de diagnóstico: `run_load_trace.bat` (`HH_LOAD_TRACE`).
>
> ### Guardado (`DATA SAVE`) — VALIDADO (2026-09-30 / 10-01)
> Guardar (`NEW GAME`/sobrescribir) · **AREA 1-1** · **TIME** · salida de la cápsula · reentrada ·
> borrado de slots · mensaje de `Select` con bindings. Detalle:
> **`notes/2026-09-30-save-capsule-logica.md`** (su §8ter: borrado; §9: recetas reutilizables).
>
> ---
>
> ## Aviso de método (AGENTS)
> - Distinguir **medido** de **inferido**; no concluir comportamiento de ejecución sin evidencia
>   (oráculo/Windows); no inventar UI ni fórmulas.
> - **Un tema = un commit**; **no commitear/pushear** sin que lo pida el mantenedor.
> - No validar el caso "todo vacío" con un `.pak` con datos.
>
> ### Pendientes menores (aparcados)
> - **JA**: restos sin consolidar (`Face::Color1`, `？/！` en `jp_kana.h`); kana útil solo de
>   `color0`/`color1`; el kanji vive en `color3` **JP** (no lo tenemos).
> - **UI de GUARDAR**: sigue publicándose como COPIA de la de cargar sobre el DATA SAVE nativo; afinar
>   a 1:1 si se pide.
>
> ---
>
> ## Contexto vivo
> - **DEPENDENCIA DE FORK:** la rama necesita 2 commits de `N64ModernRuntime`: `9b14604`
>   `hh_pak_reload_from_disk()` y `3523bf3` `PAK_SIZE=0x40000` (publicado). Gitlink bumpeado en
>   `dbb209a`. ADR: `docs/adr/0013-pfs-virtual-ampliado-y-pak-de-n-slots.md`.
> - **Plan de fondo**: "Menú propio de CARGAR/GUARDAR partida (un `.pak` con N=74 slots: 45 partidas +
>   29 plantillas, trailer de metadatos)": **`notes/2026-09-29-menu-cargar-guardar-partida-plan.md`**.
>   UI Fase 2/3: `notes/2026-09-29-menu-cargar-guardar-fase2-ui.md`. Tipografías:
>   `notes/2026-09-30-tipografias-data-load-hallazgos.md`.
> - **ESTRATEGIA DE MERGE**: `menu-carga-guardado-partida` es **DERIVADA** → **no** va a `main`. Al
>   terminar: merge a **`menu-edicion-partida`**; luego → **`main`**.
> - **Puntos de guardado del mantenedor**: `notes/reference/saveedit/PUNTOS_DE_GUARDADO.md` (registro
>   vivo; se anotan los nuevos que aporte el mantenedor).
> - **Áreas-Partes**: `notes/2026-09-29-editor-area-parte-plan.md`. Pendientes vivos: (a) validar en
>   Windows `EXTRAS > IR A ÁREA` + `DEBUG NIVELES`; (b) diseñar "mover mi partida a una Área-Parte"
>   (§6bis); (c) "volver al menú desde el gameplay" (el idx 7 daba la intro pero hoy crashea).
> - Antes del formato del save, leer
>   `notes/2026-09-28-editor-partida-formato-slot-y-logica-juego.md` y
>   `notes/2026-09-28-editor-atributos-estado-modo-heaven.md`.
>
> ---
>
> ## Cómo trabajar (rápido)
> - Build Linux: `cmake --build build/linux --parallel $(nproc)`.
> - Build Windows: `rmdir /s /q hybrid-heaven-recomp\build\windows` + `hybrid-heaven-recomp\build_windows_release.bat`.
> - Traza de carga: `hybrid-heaven-recomp\run_load_trace.bat`. Guardado: `run_save_trace.bat`.
>   Combate/campo: `run_battle_trace.bat` (F12), `run_field_watch.bat` (`HH_WATCH_ADDR`).
> - Regenerar C recompilado: `python3 tools/regenerate.py` (no se versiona; ADR 0009/0011). Tras
>   regenerar: `python3 tools/analysis/fix_fallthroughs.py`.
> - Docs: `python3 tools/analysis/docs_index.py` (regenera `docs/INDEX.md`; `--check` valida).
>
> ## Git / forks
> - Rama **`menu-carga-guardado-partida`**; **nada pusheado**. Commitear solo lo validado/docs y con
>   permiso. Push (si se pide): **forks primero** (`N64Recomp`, `N64ModernRuntime`), luego el repo
>   principal (ver `AGENTS.md`).
