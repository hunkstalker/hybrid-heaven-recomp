# RETOMAR — handoff (2026-10-05)

> Handoff corto. **`main`** = **`v0.7.0` + `v0.7.1` publicadas** + **`v0.7.2` preparada** (rama
> `fase-b-interpolacion` **mergeada**; PATCH: fixes de **cámara** y del **objeto del menú de título** de
> la interpolación). **Falta: push de `main` + tag `v0.7.2`.** **Pendiente de Fase B**: (0b)
> discontinuidad de posición (enemigo en primer plano), (1) enumerar sitios de dibujo, (2) campo **LOD**,
> (3) 2D `ID_IGNORE`, (5) validar con `HH_PAIRING`. **Fase B (0b) VALIDADA (2026-10-05)**: el tagging
> de C768 no llegaba a RT64 en gameplay (gate por `a1` basura) → gate por **escena**. Investigación en
> rama **`fase-b-investigacion`**. Detalle:
> `notes/2026-10-05-fase-b-materializacion-c768.md`, `notes/2026-10-05-fase-b-camara-y-titulo.md`.
> Reglas: `AGENTS.md` y `docs/documentation.md`.

## Tarea de la sesión (2026-10-05): BUG inventario — caja negra anclada a la derecha — HECHA

**Validado por el mantenedor en Windows (2026-10-05)**; entra en **`v0.7.0`** (falta push/tag). Fix en
`src/hooks/hud_rewrite.cpp` (`case kFillRect`): solo la **caja canónica** del fondo del minimapa
(`197,143..277,223`) puede **establecer** el panel; antes valía "cualquier fill negro a la derecha"
(`right_panel_box`), lo que atrapaba el recuadro del inventario → `kRight` → anclado a la derecha. Traza
`[hh-mapbg]`. Detalle: `notes/2026-10-05-fix-inventario-caja-negra-ancla.md` (síntoma:
`notes/2026-10-05-bug-inventario-recuerdo-negro-desplazado.md`).

### Fix de CI (2026-10-05) — pin de plume + push/tag de `v0.7.0`

El push de `main` destapó que el pin de RT64 (`7c46232`, vía `5b11988`) arrastraba un submódulo
`plume` a un commit **no publicado** (`71fd344`), rompiendo el clon limpio/CI. Arreglado con **B**: commit
`234151a` en `lib/rt64` devuelve plume a **upstream** `d890ac8` (el de v0.6.2); `main` sube su pin
(gitlink + `runtime.lock`). Detalle: `notes/2026-10-05-ci-fix-plume-pin.md`.

**Push (orden)**: `git -C lib/rt64 push fork hybrid-heaven` y luego `git push origin main`; **tag**
`v0.7.0` a petición del mantenedor. El pin `234151a` no estará en el fork hasta el primer push.

### Fase A — cobertura libultra (2026-10-05, rama `fase-a-libultra`) — HECHA y VALIDADA

N64Recomp conocía 361 nombres (ignored/reimplemented) y el ELF solo reconocía 47; una libultra sin
nombrar se **recompila y ejecuta** (copia del juego). Auditoría + fingerprint conservador vs mnsg:
11 nuevas **alcanzables** de la clase peligrosa (cop0/cache/TLB) → añadidas a `recomp/symbol_addrs.txt`
y retirado el stub del TOML (`osUnmapTLBAll`). **Validado en Windows**: lógica a **30 Hz**
(`hh_tick.log` 30,09 ticks/s, `d2` dominante), velocidad/audio normales, sin errores de lookup, y
**subida fuerte de fps** (~80 media → 144 con bajadas ~80). Regen gate byte-a-byte OK, build Linux OK,
verify 1–3 OK, jump tables 0. `_recomp` registradas 58 (47+11). **Mergeada en `main`.** Detalle:
`notes/2026-10-05-fase-a-libultra-cobertura.md`.

### Fase B — interpolación: emparejamiento de ids (rama `fase-b-interpolacion`, MERGEADA en `main`)

**Hecho y VALIDADO en Windows (2026-10-05) — (0) cámara + objeto del título.** Diagnóstico por A/B
(`HH_EMIT_TAG`/`HH_EMIT_PROJ`/`HH_EMIT_MV`/`HH_EMIT_MV_SKIP`): la **cámara** la rompía cualquier grupo de
**PROYECCIÓN** (en HH la cámara va **horneada** en el modelview → se duplicaba) → **proyección OFF por
defecto**; el **objeto del título** lo rompía **C768** (id 15) llamado con `a1 != kGfxCursor` → su
modelview se gatea a la **ruta del cursor** (`ctx->r5 == kGfxCursor`). También se añadió la **generación
de cámara** a los ids de los emisores (antes `0xEE…`). Entra en **`v0.7.2`**. Detalle:
`notes/2026-10-05-fase-b-camara-y-titulo.md`.

**Pendiente**:
- **(0b) Discontinuidad de POSICIÓN por objeto**: un enemigo que **cambia de coordenadas** (mismo
  root/modelo → mismo id) se interpola a través del salto y aparece "en primer plano" al inicio.
  Candidato: detectar el salto y **bumpear su id** (como la generación de cámara).
- (1) Enumerar sitios de dibujo 3D y taggear por `kind`; (2) **LOD** en el id (A2.4); (3) 2D
  `G_EX_ID_IGNORE`; (4) `ORDER AUTO`; (5) validar con `HH_PAIRING` + `paircap`.

## Tarea actual (`main`) — fix de input (acciones por flanco + lectura unificada)

**Hecho y VALIDADO en Windows (2026-10-04):**

- Los flujos propios del menú leían aceptar/borrar (A/START/X) en vías **inconsistentes** (estado
  mantenido de la ranura o `hh_input_button_down`, que **no incluye el mando**). Efectos: (1) al
  confirmar CONTINUAR con A/START aún pulsada se cargaba el **primer slot** sin ver el `DATA LOAD`;
  (2) **X del mando no borraba** slots (solo la tecla H).
- Fix: **una sola vía** para las acciones, `hh_input_action_edges()` (`input.cpp`): **teclado + ratón +
  mando + inyección** con **flanco estricto con rearme** (mantener no repite). Las **direcciones**
  conservan su auto-repeat. Anti-rebote de entrada por seed en el hook de apertura
  (`hh_input_action_seed`); retirados los bloqueos por ms `load/save_input_blocked`.
- Verificado Windows: CONTINUAR no carga con A/START mantenida; GUARDAR no autoguarda/autoborra;
  **borrar con X del mando OK**; teclado y mando a la vez; direcciones siguen repitiendo. Linux compila.
- Detalle: `notes/2026-10-04-fix-input-flanco-botones-accion.md`.

### Fix de remapeo de teclado en CONTROLES (#17) — HECHO (2026-10-04)

- Asignar teclas (números, etc.) no persistía. Causas: los **defaults** de teclado se reinyectaban al
  cargar y ganaban a la tecla reasignada; teclas cuyo nombre rompe el INI (`; = #`) se perdían; la
  fuente no dibuja `[ ] \ '`.
- Fix (`input.cpp`): `[keys]` es **fuente autoritativa** del teclado; nombres seguros `sc_<n>` para el
  INI; **solo se mapean teclas dibujables** (`glyph_value` + `menu_char`, incluye `¡¿` y acentos); el
  rótulo se muestra **según la layout del SO** (`¡` en teclado ES), guardando por **scancode**.
- Detalle: `notes/2026-10-04-fix-remapeo-teclado-persistencia.md`. Pendiente validar en Windows.

### Pendiente

1. Commit del fix + docs (si el mantenedor no lo ha hecho ya).
2. Validar en Windows el remapeo de teclado (números + teclas del layout ES).

## Rama `fps-interpolacion-tagging` — estado y plan de integración

> **Esta sección la añadió la sesión 2026-10-04** (la que trabajó en esa rama) para dejar aquí, en
> `main`, el contexto del estado de la interpolación y **cómo integrarla**. No mezclar con el fix de
> input de `main`.

**Estado de la rama** (**MERGEADA en `main`**, 2026-10-04; `main` = `9b45c3a`): arregla artefactos de
la **interpolación de frames** a alta tasa. **Ya activo por defecto** en `main` (tagging ON; se apaga
con `HH_MTXGROUP=0`/`HH_EMIT_TAG=0`). Contenido:

- **Sesgado de cámara RESUELTO** (`46b3f0d`, port-only): `gEXMatrixGroup` de PROYECCIÓN con generación.
- **Identidad por nodos** (`stable_slot` + generación de cámara): arreglados **huesos** del PJ, **#6**
  (gate de escala, en RT64), **#8** (puertas), minas/láseres.
- **A2.2d CERRADA** (efectos/2D pasada 2, no-bug): los efectos los dibuja `C768` y **materializa**;
  capturas de minas/láser/partículas/puerta = **transitorios**, no fallos.
- **Partículas del heal = no-bug** (asset original; coincide con el emulador).
- Bug **latente** de walkers de DL corregido (`a8212b3`).
- **Instrumentación**: RT64 vía `patches/rt64/hh-interpolation-tagging.patch` (gates, contadores,
  pairing) y del port (`HH_MTXGROUP`, `HH_EMIT_TAG`, `HH_PAIRING`, `HH_PAIRING_DUMP`, …). **`lib/rt64`
  en `main` está limpio**; en la rama el patch se aplica aparte (`docs/workflows.md §1.2`).
- Handoffs/notas: `notes/2026-10-04-fps-a2-2d-emisores-y-capturas-transitorias.md`,
  `.../fps-particulas-heal-asset-no-bug.md`, `.../fps-walker-dl-comandos-extendidos-latente.md`.

### INTENCIÓN: integrar en `main` (promover los arreglos validados)

**Objetivo de la rama:** llegar a **integrar en `main`** lo ya **validado** (aunque no haya 100% de
emparejamiento), para que esos arreglos visuales lleguen a los usuarios.

**Plan de integración** (por fases; **NO** es un merge ciego):
1. **Sincronizar**: `git merge main` en esta rama y resolver conflictos (`src/subsystems/input.cpp`
   —ambas lo tocan— y los `.md` de estado). **HECHO (2026-10-04)**.
2. **Re-validar** en Windows con los flags ON (cámara, identidad, #6/#8) sin regresiones.
   **HECHO (2026-10-04)** por el mantenedor.
3. **Promover**: **encender por defecto** solo lo **validado** (cámara + identidad + #6). **HECHO
   (2026-10-04)**: el tagging por objeto/nodo (`g_enabled`, `HH_MTXGROUP`) y el tagging de **emisores/
   cámara** (`g_emit_tag`, `HH_EMIT_TAG`) pasan a **ON por defecto** (apagables con `=0`); el gate de
   escala (#6) ya estaba **ON** en el patch de RT64 (ahora commit). La instrumentación
   (HH_PAIRING/LOGs/capturas/TEXDUMP, `HH_FX_PASS2`) sigue **OFF**.
4. **RT64**: **HECHO (2026-10-04)**: el **gate de discontinuidad de escala/rotación (#6)** es **commit
   permanente** del fork `hunkstalker/rt64` rama `hybrid-heaven` (`7c46232`); el gitlink de
   esta rama apunta a él + `runtime.lock` actualizado. **Corregido (2026-10-05)**: el pin sube a
   `234151a` (sobre `7c46232`) para devolver plume a upstream `d890ac8`, porque el pin anterior a
   `5b11988` apuntaba a un commit de plume no publicado y rompía el clon limpio/CI; ver
   `notes/2026-10-05-ci-fix-plume-pin.md`. La **instrumentación** (contadores/sondas) queda
   **solo** en `patches/rt64/hh-interpolation-tagging.patch`. Detalle: `docs/workflows.md §1.2`.
5. **Merge/PR a `main`** con su documentación. **HECHO (2026-10-04)**: merge **fast-forward** a `main`
   (`f144881`), más el fix de build de `9b45c3a` (stubs weak de la instrumentación RT64 para que
   `main` compile sin el patch). **Pendiente del mantenedor**: `git push origin main`.

### Pendiente tras el merge

- **Validar en Windows desde `main` sin variables** (cámara, huesos, #6, #8). El gate de escala va en
  el commit del fork (`7c46232`, pin actual `234151a`), así que un clon limpio de `main` lo tendrá.
- `lib/rt64` en local puede quedar “sucio” (patch de diagnóstico aplicado); para `main` limpio:
  `git -C lib/rt64 checkout -- .`.
- **Push** de `main` (lo hace el mantenedor).

### TAREA SIGUIENTE — A1 tick lógico + A3 validar 120/240

**A1 — Estabilizar el tick lógico** (`notes/…-workorder… §4`):
- Garantizar **2 VI/frame estables** (lógica a **30 Hz**, como el N64) y **slips a 3 VI solo cuando el
  trabajo no quepa** (no por jitter). Un tick irregular dispara fallos de matching/interpolación.
- Herramientas: **`HH_DET_CLOCK=1|quant` + `HH_DET_CLOCK_BIAS`** (reloj determinista en el runtime,
  `ultramodern timer.cpp`), compensación de stalls (precarga/caché de módulos `trans`, audio/DMA).
- Verificar que **render/present no realimentan el tick** (que el frame de RT64 no retrase la lógica).
- **Criterio**: cadencia estable (2 VI/tick, `d2` dominante en `hh_tick.log`, `d3/d4+=0`); desaparecen
  los artefactos dependientes de jitter (hitches de puerta).

**A3 — Validar a 120/240 Hz (Windows RTX 4080 + Steam Deck)**:
- Regresión: menús, guardado, combate, cinemáticas; **sin** parpadeo ni geometría incoherente.
- A/B por métrica (`HH_FPS=1`) y ojo; F9 (interpolación ON/OFF), F8 (PresentEarly).

### Observación del mantenedor (2026-10-04)

**Rara vez ve 120 fps y nunca 240.** `[hh-fps]` ya imprime `present vs target`, `target/vi/swapChain/
refresh/vsync`. Primer paso: **medir** con `HH_FPS=1` a 120/240 (menú GRÁFICOS o `HH_REFRESH_RATE=manual:<hz>`),
distinguir si el cuello está en: (a) **lógica/tick** (slips → `hh_slow.log`), (b) **present/GPU**
(`present` por debajo de `target` con tick sano) o (c) **VSync/monitor** (`target=swapChain`).

## Instrumentación (reutilizable)

- **Cadencia**: `HH_FPS=1` → `[hh-fps]` (update/present + target/vi/swapChain/refresh/vsync);
  `HH_DIAG=1` → **`hh_tick.log`** (ticks, `d1..d4+` = VI por tick, `max_dt`) y **`hh_slow.log`**
  (ticks >36 ms: `send_dl`/`update_screen`/`guest_busy`/`pending_ext`);
  `HH_STATE_SECS=<s>` → `hh_state.log` (estado de hilos).
- **Present/video**: `HH_REFRESH_RATE=original|display|manual:<hz>`; **F9** = toggle interpolación;
  **F8** = menu nativo; `HH_PRESENT_EARLY=0` (=F8 sonda).
- **Runtime**: `HH_VI_EVERY=<n>` (entrega VI al guest; diagnóstico de cadencia), `HH_DET_CLOCK[_BIAS]`.
- **Tagging/interpolación**: `HH_MTXGROUP`, `HH_EMIT_TAG`/`HH_FX_EMIT`, `HH_FX_PASS2`,
  `HH_PAIRING` (con `emitmat=[…]`), `HH_PAIRCAP`/`HH_GENCAP`, `HH_PAIRING_DUMP`, `HH_SCALE_GATE`.

### Run del mantenedor (cadencia)

```powershell
hybrid-heaven-recomp\build_windows.local.bat
$env:HH_FPS='1'; $env:HH_DIAG='1'; $env:HH_STATE_SECS='2'; $env:HH_MTXGROUP='1'; $env:HH_EMIT_TAG='1'
hybrid-heaven-recomp\run_windows.bat release
```
Logs en `build\windows\bin\Release\` (`hh.log`, `hh_tick.log`, `hh_slow.log`, `hh_state.log`). Borrar los
`hh_*.log` antes de cada run (algunos abren en `w`/append).

## Árbol y pistas

- `main` = `v0.7.0` (v0.6.2 + fix de input + épica de interpolación integrada; **ON por defecto**),
  **submódulos limpios**: `lib/rt64` en **`234151a`** (fix 2D + gate de escala/rotación; `7c46232` +
  plume upstream). La rama `fps-interpolacion-tagging` = `main` (idéntica).
- Tick/lógica: `src/subsystems/input.cpp` (`get_input`, `HH_DIAG`, `hh_tick.log`/`hh_slow.log`),
  `src/platform/main.cpp` (`HH_STATE_SECS`), runtime `N64ModernRuntime` (`events.cpp`, `timer.cpp`).
- Present/GPU: `src/platform/rt64_render_context.cpp` (`[hh-fps]`, send_dl/update_screen),
  `lib/rt64` (`rt64_workload_queue.cpp`, present queue).
- Notas: `notes/2026-10-02-workorder-desbloquear-fps-interpolacion.md` §4 (A1/A3),
  `notes/2026-09-17-ralentizaciones-puertas-y-30hz-logicos.md`,
  `notes/2026-09-19-causa-raiz-cadencia-frames.md` (1 vs 2 VI/tick),
  `notes/2026-09-22-fps-y-present-early.md`.
- **`lib/rt64`**: `main` pinea **`234151a`** (fix 2D + **gate de discontinuidad de escala/rotación**
  `7c46232`, + plume upstream `d890ac8`; commit permanente del fork `hybrid-heaven`). La instrumentación
  (contadores/sondas) va en el
  **patch** `patches/rt64/hh-interpolation-tagging.patch`, no commiteada; el port enlaza sin ella por
  los **stubs** (`rt64_render_context.cpp`, weak + `/alternatename` en MSVC). Para activarla:
  `git -C lib/rt64 apply patches/rt64/hh-interpolation-tagging.patch`; quitarla:
  `git -C lib/rt64 checkout -- .`. Detalle: `docs/workflows.md §1.2`.

## Pitfalls (NO repetir)

- **Metas**: ">30 visual" ya existe (interpolación); **240 "reales" (lógica a 240) NO** es el objetivo
  (eso es la Fase B/ADR). No confundir fps **presentados** con lógica.
- **F7** = captura del HUD 2D; no sirve para artefactos 3D transitorios.
- **La vista no valida** (el mantenedor vio "mejoras" con un `.exe` viejo): validar por métrica.
- No concluir cuelgues/freeze solo desde headless; validar en Windows.
- `HH_VI_EVERY` es **diagnóstico global** (baja el frame en todo el juego), no un fix.
- **Botones vs direcciones**: los botones de acción van por **flanco**; el **auto-repeat es solo para
  direcciones**. No leer acciones en estado mantenido (bug 2026-10-04).
- **NO** `git reset --hard`; no editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
