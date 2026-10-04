# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-04, sesión 4)

> **TAREA (rama): interpolación fiel / desbloquear FPS.** Esta sesión **resolvió el sesgado de cámara**
> (grupo de proyección con generación) y **descartó la vía core** (materializar pass 1 a través de la
> frontera de workload). Queda pendiente el tagging de los **efectos/2D de pasada 2**.
> Detalle completo: `notes/2026-10-04-fps-core-frontera-workload-y-pasada2.md`.
> Reglas: `AGENTS.md` y `docs/documentation.md`. La vista no valida 1 frame → capturas **+ ojo**
> (el mal-emparejamiento no lo ve la métrica).

## Estado — lo que funciona (MEDIDO, run del mantenedor)

- **Sesgado de cámara RESUELTO** (commit `46b3f0d`, port-only): `emitter_wrap()` en
  `src/hooks/model_tagging.cpp` emite un **`gEXMatrixGroup` de PROYECCIÓN** (`proj=1`) con id de cámara
  ligado a la generación → RT64 no empareja el viewProj en un corte → **snap**. Gate `HH_EMIT_TAG=1`
  (alias `HH_FX_EMIT`) junto con `HH_FX_PASS2=1`. Validado: `gencap` de FIGHT con `unpaired=0` y
  encuadre coherente.
- **Arreglados** (sesiones previas): huesos del PJ, **#6** (gate de escala ON 2.0), **#8**, minas/láseres.
- **Identidad** `stable_slot()` generacional; **grupos** de pass 1 por NODO; generación de cámara (corte
  si >90u o >90°). Sin `gEXSetRDRAMExtended`; sin skip-spawn propio.
- **NO envolver los emisores 2D de menú** (`7750/78AC/79B0`, `919C/11958`, `A828`): **congelan**
  menú/LOAD DATA.

## TAREA ABIERTA — efectos/2D de pasada 2 (no-emparejados)

- **Síntoma**: capturas en minas, láser al jugador, partículas de golpe y **transiciones de puerta**.
- **Causa (MEDIDA)**: la geometría la dibujan los **emisores de pasada 2** (`7DE4/8F30/8754/C768/…`),
  no el dispatch de pass 1 (`A828` solo pinta fillrects/estado). Sin tag propio, esos transforms
  heredan el último grupo o van AUTO → *unpaired* / mal-emparejado.
- **Vía correcta (NO core)**: tagging **en el emisor** (conoce su nodo `ctx->r4`), en el mismo workload
  que la geometría. Identidad por nodo (`stable_slot`, **sin** `g_obj_slot`, obsoleto en pass 2). Para
  nodos con **N transforms** (efectos/partículas) usar `G_EX_ORDER_AUTO` o `G_EX_ID_IGNORE`, **nunca
  LINEAR** (baraja). Efectos → `IGNORE`.
- **Descartado**: materializar pass 1 a través de la frontera de workload ("grupo activo"): asocia por
  **tiempo, no por nodo** → rompe el HUD (el radial azul se movía). Ver la nota.

### Plan A2.2d (primeros pasos, concreto)

Punto de partida: `src/hooks/model_tagging.cpp` → `emitter_wrap()` (línea ~639) y los hooks de emisor
(~línea 702). `emitter_wrap` hoy **solo** emite el grupo de **proyección** (cámara); hay que volver a
emitir **también** un grupo de **modelview** por emisor. Registro de los hooks: `sections.cpp` (bajo
`HH_FX_PASS2`). No hace falta tocar el core.

1. **Re-añadir el grupo modelview** en `emitter_wrap` con id **por nodo**
   (`interp_id(2, 0, stable_slot(node, model), 0)`, **sin** `g_obj_slot`, que en pass 2 es obsoleto),
   con push/pop balanceados alrededor de `emitter_trace` (que llama a `orig`).
2. **Identificar qué es efecto** (no lo sabemos aún). Diagnóstico de 1 run: emitir el grupo con un id
   **reconocible por emisor** (p. ej. `0xEE000000u | uint32_t(id_emisor)`) y mirar en `hh_pairdump.log`
   qué `id=EE…` aparece en los no-emparejados de minas/láser/partículas/puertas. Ese emisor (o su tipo
   de nodo, `rd_u16(rdram, node + 0x2A)`) es el candidato a `IGNORE`.
3. **Granularidad** (clave): si el nodo tiene **N transforms** (efectos/partículas) → `G_EX_ID_IGNORE`
   (efectos) o `G_EX_ORDER_AUTO` (evita el barajado de `LINEAR`); `LINEAR` **solo** para mallas de 1
   transform. `is_effect` por `ntype` o por lista de emisores.
4. **Validar**: `ignored>0` y caen las `paircap` de esos puntos; **además visual** (huesos, HUD/radial,
   efectos). OJO: la métrica **no** ve el mal-emparejamiento.
5. **No envolver** los 2D de menú (`7750/78AC/79B0`, `919C/11958`, `A828`): congela (probable desborde
   del buffer de gfx). Si un efecto 2D va por ahí, hay que buscar otra vía (rewrite en `send_dl`).

Si el paso 2 revela que el efecto lo dibuja un emisor 2D no envolvible, replantear: taggear en `send_dl`
(como `hud_rewrite`) o detectarlo en RT64.

## Otros pendientes

- **LOD** en el hash (id = slot, model, lod): sin campo localizado; probable "no aplica".
- **2D "de verdad"** (HUD/menús): `hud_rewrite` ya no interpola su proyección.

## Instrumentación (reutilizable; se conserva a propósito)

- `HH_MTXGROUP=1` tagging; `HH_MTXGROUP_LOG=1` → `[hh-types]` (histograma) y `[hh-interp]` (cortes).
- `HH_PAIRING=1` → `[hh-pair]`. **OJO**: `unpaired` **no** mide el **mal-emparejamiento** (el fallo
  visual del HUD/huesos) → validar también visual.
- `HH_PAIRCAP=<min moved>` / `HH_GENCAP=1` → `paircap_*`/`gencap_*` + `[hh-cap]`. No borrar los BMP
  hasta copiarlos.
- `HH_PAIRING_DUMP=<min moved>` → `hh_pairdump.log` (se **abre en append**: borrarlo antes de cada run).
- `HH_FX_PASS2=1` (registra hooks de emisores) + `HH_EMIT_TAG=1` (tagging de emisores/cámara).
- `HH_SCALE_GATE` (def. ON 2.0; `=0` off), `HH_ROT_GATE` (sonda), `HH_CAPMAX=<n>`.

### Banco headless (logos/menús; NO llega a gameplay)
```
Xvfb :99 & ; DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_MTXGROUP=1 HH_MTXGROUP_LOG=1 \
  timeout 20 "./Hybrid Heaven Recomp"   # cwd build/linux
```
En headless `[hh-pair]` sale 0 (no presenta frames). Para gameplay: run del mantenedor.

## Run del mantenedor (validación)

```powershell
hybrid-heaven-recomp\build_windows.local.bat; $env:HH_MTXGROUP='1'; $env:HH_PAIRING='1'; $env:HH_MTXGROUP_LOG='1'; $env:HH_FX_PASS2='1'; $env:HH_EMIT_TAG='1'; $env:HH_PAIRCAP='2'; $env:HH_GENCAP='1'; hybrid-heaven-recomp\run_windows.bat release
```
Log: `build\windows\bin\Release\hh.log`. Reproducir: FIGHT, minas, láser al jugador, partículas de
golpe y transición de puerta. Mirar `ignored`, `explicit_ids` y las capturas.

## Árbol

- `src/hooks/model_tagging.cpp` (tagging + `emitter_wrap` cámara + `[hh-emit]`), `sections.cpp` (hooks),
  `rt64_render_context.cpp` (auto-captura + log), `patches/rt64/hh-interpolation-tagging.patch`.
- `lib/rt64` SUCIO (fork): la instrumentación vive en el patch; **no commitear el submódulo**.

## Pitfalls (NO repetir)

- **NO** taggear modelview de objeto con `LINEAR` si el grupo puede tener N transforms (huesos/partículas).
- **NO** intentar recordar el grupo activo a través de la frontera de workload (asocia por tiempo → HUD roto).
- **NO** envolver los emisores 2D de menú (`7750/78AC/79B0`, `919C/11958`, `A828`): **congela**.
- La cámara es **proyección**, no modelview (taggear modelview no la arreglaba).
- **NO `git reset --hard` para un cambio puntual** (revertir el cambio, no la rama).
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
