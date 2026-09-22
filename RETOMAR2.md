# RETOMAR 2 — mapa se sale por la derecha del rect negro (widescreen, fase 07b)

> Handoff para **sesión nueva**. **Última sesión: 2026-09-22.** Tarea: que el **contenido del
> minimapa** (mapa verde + flecha roja) quede recortado **dentro** del rect negro del panel
> (`197,143..277,223`, crop `kMapCrop`). **Síntoma**: el verde **se sale solo por el límite derecho**
> del rect negro (~11-12 game px); izquierda y Y sin desborde.
>
> **ESTADO**: **diagnóstico cerrado + fix B aplicado** (2026-09-22): traza `RECT` confirmó el
> desfase (bg `1826..2294` vs contenido `1830..2298` en `adjust=1`, Δ=**misalign 4 vs 0**).
> Fix en `rt64_framebuffer_renderer.cpp`: scissor **Ortopédico** ahora recibe
> `p.horizontalMisalignment` (igual que los rects). Build Linux OK. **Pendiente**: rebuild
> Windows + validar con **B** (Paso 3/5). La tarea sigue **abierta** hasta validar.
>
> Este fichero es el **continuación** de `RETOMAR.md` (historial + método general). **Lee este
> primero** si la tarea es el desborde del mapa; `RETOMAR.md` para fases anteriores.

> **MÉTODO**: el mapa **solo se dibuja en Windows**. NO reproducir en Linux headless. Compilar
> Linux solo para verificar que compila. La **Release es GUI**: las trazas van a ficheros junto al
> exe (`hh.log`, `hh-rect.log`), no a consola. **Yo leo los logs**; no pedir al mantenedor que pegue
> salidos. `RT64_LOG_PRINTF` se compila a nada con `NDEBUG` → traza propia `hhRectLog()`.

> **Lee también**: `RETOMAR.md` (parches RT64, quad abandonado, controles en caliente);
> `TODO.md`; `docs/architecture.md`.

---

## 0. Objetivo y criterio de aceptación

- Abrir el mapa con **B**: negro + verde + flecha **dentro** del panel; sin verde fuera del borde
  derecho del rect negro bajo **widescreen** (`aspect=auto`/`expand`).
- Recortes en caliente (`+`/`-`, `[`/`]`, `;`/`'`) se conservan.

---

## 1. Cómo llegamos aquí (resumen)

1. **HUD rewrite** (`src/hooks/hud_rewrite.cpp`): clasifica DLs, ancla radar/HUD izquierda y
   **mapa a la derecha** con `anchored_scissor` + panel canónico.
2. **Fondo del mapa**: se **reconstruye** con `emit_fill_rect_ext` (no se usa el `G_FILLRECT` del
   juego, que con origen RIGHT suma `fb_width` y da 197..597 px). Vía del **quad abandonada**
   (el contenido no es 2D en px; ver `RETOMAR.md` §2).
3. **Parches RT64 1 y 2** aplicados en `lib/rt64` (misalign #82 + misalign en triángulos 2D);
   **parche 3** (`patch_rt64_scissor_quant.py`) NO aplicado.
4. Traza `hhRectLog()` en FILL y TRI de `rt64_framebuffer_renderer.cpp` (funciona en Release).
5. Análisis de `hh-rect.log` real (34 MB, sesiones ~17 s): contenido clip OK en nativo; desfase
   de anclaje en pasada aspecto; bg **ausente** de la rama FILL.

---

## 2. Datos de la traza (`hh-rect.log` anterior)

- **Dos pasadas/frame**: `adjust=0` (320×240, `invRatio=1`, `extOrigin=0`) y `adjust=1` (salida
  2560×1440, `invRatio≈0.75`, `extOrigin=1`, resScale≈8×6).
- **FILL**: solo `callRect=0,0..1280,960` (clears). **Nuestro bg NO aparece** → `cycleType ≠ G_CYC_FILL`
  → va a **Rectangle (type=3)**.
- **TRI**: scissors `0,0..1280,960` y `792,576..1104,888` (= panel `198,144..276,222` px), todos
  **type=2 Ortográfico** = contenido ✓.
- Contenido nativa: `outScissor=198,144..276,222` ✓.
- Contenido aspecto: `outScissor=1830,864..2298,1332` (equiv juego ~228..287; desplazado a la
  derecha vs negro en ancla RIGHT).
- Enum `Projection::Type`: None=0, Perspective=1, **Orthographic=2**, **Rectangle=3**, Triangle=4.
- Conteo global (sesión anterior): type=1 84166, type=2 826, type=3 43370; type=2 scissor full: 350.
- `hh.log` DL mapa: `fill@197,143,277,223` con scissor ambiente `0,0..320,240` → bg emitido
  `198,144..276,222`.

---

## 3. Diagnóstico (CERRADO 2026-09-22 con traza RECT)

### Pipeline del bg

```
hud_rewrite kFillRect/kRight
  → emit_fill_rect_ext(RIGHT, RIGHT, b_ulx..b_lry)   // coords = panel - fbq ± crop
  → G_EX_FILLRECT_V1 → fillrectV1 → RDP::fillRect → drawRect
  → movedFromOrigin(+fb_width si origin RIGHT)
  → changeProjection(Rectangle) → GameCall type=3
  → render: NO rama FILL (cycleType≠FILL) → rama Rectangle
```

### Por qué se sale por la derecha (confirmado)

Comparación en **pasada aspecto** (`adjust=1`), mismo rect de entrada `792,576..1104,888`
(= panel `198,144..276,222` px), origins **RIGHT/RIGHT** (`1024/1024`):

| Pieza | Rama | `out` (render px) | `invRatio` | **misalign** |
|---|---|---|---|---|
| **BG** (negro) | Rectangle | **1826..2294** | 0.75 | **4** |
| **Contenido** (verde) | TRI type=2 Ortopédico | **1830..2298** | 0.75 | **0** |

- Nativo (`adjust=0`): ambos `198..276` → **casan** (el bug solo aparece en `adjust=1`).
- Δ = **4 render px** = `p.horizontalMisalignment` → el verde puede pintar hasta 2298 y el
  negro solo cubre hasta 2294 → **desborde solo por la derecha**.
- Causa: la rama **Rectangle** sí aplica `horizontalMisalignment = p.horizontalMisalignment`
  (`:1696`); la rama **Ortopédica** lo dejaba en `0` al convertir el scissor
  (`:1671` → `:1735`). La **geometría** ya compensaba vía `screenOffset` (parche HH `:1537`);
  el **scissor** no.
- Comentario en `hud_rewrite.cpp:617-621` («cubre → invRatio=1») sigue **incorrecto** para
  Rectangle (`regularOrigins` exige NONE/NONE); no hizo falta tocarlo: `invRatio` ya coincidía
  (0.75 en ambos).

### Fix aplicado (B, 2026-09-22)

`lib/rt64/src/render/rt64_framebuffer_renderer.cpp` rama `Orthographic`: asignar
`horizontalMisalignment = p.horizontalMisalignment` antes de `convertFixedRect` del scissor.
`convertFixedRect` solo lo aplica si el origen ≠ NONE (scissors full-screen intactos).

**Alternativas no usadas**: A (bg NONE/NONE) — más invasiva; C (parche `regularOrigins`) —
ya no hace falta.

### ⚠ Posible bug adicional (NO bloqueante; no confirmado)

`RDP::fillRect(..., const ExtendedAlignment &extAlignment)` (`rt64_rdp.cpp:1033`) llama a
`drawRect(..., extAlignment)`. Verificado 2026-09-22: el parámetro **sí es** `extAlignment`
(definición y cabecera); el nombre en el cuerpo (`extAlignment`) es el del parámetro real —
**no es bug**, la traza muestra `rectOri=1024/1024` correcto. Mismo patrón en
`setScissor`/`setRectAlign`.

---

## 4. Plan de ejecución (siguiente sesión)

### Paso 1 — Ampliar traza Rectangle ✅ (2026-09-22)

`lib/rt64/src/render/rt64_framebuffer_renderer.cpp` rama `case Projection::Type::Rectangle`
tras `convertViewportRect` (~1699), si `HH_RECT_TRACE`:

- `[hh-rect] RECT rect=… pairScissor=… rectOri=… cycle=… ext=… invRatio=… misalign=… asp=… adjust=… resScale=… extOrigin=… fbWidth=… regularOrigins=… covers=…`
- `[hh-rect] RECT vpOut=…` (render px del `viewportRect`)

Build Linux OK. **No** traza de ingest (Paso 1 completo sin ella).

### Paso 2 — Compilar Linux ✅ (2026-09-22)

```bash
cmake --build build/linux -j
```

### Paso 3 — Comandos Windows (el mantenedor) ← SIGUE (tras fix)

```powershell
rmdir /s /q hybrid-heaven-recomp\build\windows
hybrid-heaven-recomp\build_windows_release.bat
$env:HH_RECT_TRACE=1; $env:HH_HUD_DRAWS_TRACE=1; $env:HH_HUD_SCISSOR_TRACE=1
hybrid-heaven-recomp\run_windows_release.bat
```

Abrir mapa con **B**, cerrar. **Yo leo**:

- `hybrid-heaven-recomp\build\windows\bin\Release\hh-rect.log`
- `...\hh.log`

Esperado con fix: en `adjust=1`, `RECT vpOut` del bg = `1830,864..2298,1332` (igual que
`TRI outScissor` del contenido).

### Paso 4 — Fix ✅ (B aplicado 2026-09-22)

- **Hecho**: scissor Ortopédico recibe `p.horizontalMisalignment` (alinea bg ↔ contenido).
- **No** hizo falta A (NONE/NONE) ni C (parche `regularOrigins`): `invRatio` ya coincidía.
- **No** cambiar `kLeft`/`widen_scissor` sin validar (radar/HUD).

### Paso 5 — Validar y cerrar

1. Rebuild Windows + validar visualmente con **B** (ver Paso 3).
2. Si sigue ~1 px: `[`/`]`/`;`/`'` y fijar defaults en `hud_rewrite.cpp`.
3. Si tras el fix sigue desfase de cuantizado: `python3 tools/patch_rt64_scissor_quant.py` (parche 3).
4. Actualizar `TODO.md`/`PROYECTO.md`, nota en `notes/`; commitear solo si el mantenedor pide
   documentar o la tarea queda **validada**.

---

## 5. Build / run / envs

| Eso | Valor |
|---|---|
| Build Windows | `hybrid-heaven-recomp\build_windows_release.bat` (+ `rmdir …\build\windows` si no se ve el cambio) |
| Run Windows | `hybrid-heaven-recomp\run_windows_release.bat` |
| Build Linux | `cmake --build build/linux -j` o `tools/build_linux.sh` (solo compilar) |
| Logs | junto al exe: `hh.log`, `hh-rect.log` |
| Traza rect | `HH_RECT_TRACE=1` |
| Traza HUD | `HH_HUD_DRAWS_TRACE=1`, `HH_HUD_SCISSOR_TRACE=1`, `HH_HUD_REWRITE_TRACE=1` |
| Crop panel | `HH_MAP_CROP` / `+`/`-` (default `kMapCrop`) |
| Crop fondo | `HH_MAP_BG_CROP` / `[`/`]` |
| Shift fondo | `HH_MAP_BG_SHIFT` / `;`/`'` |
| Widescreen | `HH_FULL_FRAME`, `config.ini [video] aspect` |
| Desactivar rewrite | `HH_NO_HUD_REWRITE=1` |

---

## 6. Ficheros clave

| Fichero | Papel |
|---|---|
| `RETOMAR.md` | handoff anterior (histórico, quad, parches 1-2) |
| `RETOMAR2.md` | este (desborde derecho + plan Rectangle) |
| `src/hooks/hud_rewrite.cpp` | rewrite; `anchored_scissor`, `emit_fill_rect_ext`, `kFillRect`, `map_crop*` |
| `include/hh/hudid.h`, `include/hh/hudrewrite.h` | identidades / API |
| `src/platform/rt64_render_context.cpp` | enganche `send_dl` |
| `src/subsystems/input.cpp` | `+`/`-`, `[`/`]`, `;`/`'`, F11 |
| `lib/rt64/src/render/rt64_framebuffer_renderer.cpp` | **traza + conversión**; parches 1+2 ya aplicados |
| `lib/rt64/src/hle/rt64_rdp.cpp` | `fillRect`/`drawRect`/origins |
| `lib/rt64/src/gbi/rt64_gbi_extended.cpp` | `fillrectV1` |
| `lib/rt64/src/hle/rt64_framebuffer_pair.cpp` | `fillRectOnly`, proyecciones |
| `lib/rt64/include/rt64_extended_gbi.h` | `G_EX_FILLRECT_V1`, `G_EX_ORIGIN_*` |
| `tools/patch_rt64_*.py` | parches 1/2 aplicados, 3 no |
| `build_windows_release.bat`, `run_windows_release.bat` | Windows |

Git: `lib/rt64` solo con parches 1+2 sin commitear; build Windows usa `SKIP_LIBS=1`.

---

## 7. Gotchas (no repetir)

1. **No** concluir «el juego está bien/mal» solo con logs headless; el mapa hay que **verlo en Windows**.
2. **No** recompilar solo por ganas: una tanda de cambios → un rebuild Windows.
3. **No** leer otros `RETOMAR*`; solo `RETOMAR.md` y **`RETOMAR2.md`**.
4. **No** editar el C recompilado a mano (`build/recomp/`).
5. `RT64_LOG_PRINTF` = no-op en Release → usar `hhRectLog()` o `hh::log`.
6. Escrituras concurrentes parten líneas en `hh-rect.log` → `grep -o` con patrones.
7. Origen RIGHT en RT64: `movedFromOrigin` suma `fb_width` (q); scissor/bg deben compartir
   **mismos números y mismos origins** o el clip se abre por un lado.
8. Fondo **después** del contenido; viewport vigente puede ser el del último elemento.
9. Quad del fondo: **prohibido retomarlo** sin leer por qué se abandonó (gira con la matriz).

---

## 8. Estado de la sesión (2026-09-22)

- Leídos: `RETOMAR.md`, `hud_rewrite.cpp`, `framebuffer_renderer.cpp`, `rt64_gbi_extended.cpp`,
  `rt64_rdp.cpp`, `rt64_framebuffer_pair.cpp`, `rt64_rdp.h`, `rt64_common.cpp` (FixedRect).
- **Plan Mode** primera sesión: solo plan.
- **Sesión siguiente**: Paso 1+2 — traza `RECT` + build Linux OK.
- **Sesión actual**: analizado `hh-rect.log` (50 MB) → Δ misalign 4 vs 0 → **fix B aplicado**
  en `rt64_framebuffer_renderer.cpp` (scissor Ortopédico) + build Linux OK + `RETOMAR2.md`.
- Pendiente: Paso 3 (rebuild Windows + traza) → validar visualmente con **B** → Paso 5.
- Fallo de sesión previa: avalancha de `glob` mal formados (ruido; no afecta al repo).
