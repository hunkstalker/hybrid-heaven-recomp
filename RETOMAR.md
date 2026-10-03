# RETOMAR — handoff RAMA `fps-interpolacion-tagging` (2026-10-03, sesión 2)

> **TAREA (rama): interpolación fiel / desbloquear FPS.** Esta sesión **rehízo la identidad del
> tagging** y la **validó en gameplay** (run del mantenedor). Detalle y evidencia:
> `notes/2026-10-03-fps-tagging-identidad-logica-y-generacion-camara.md` (actualizada).
> Reglas: `AGENTS.md` y `docs/documentation.md`. **La vista no valida 1 frame** → usar capturas.

## Estado — lo que funciona (MEDIDO, run del mantenedor)

- **Arreglados**: huesos del PJ dispersos, **#6** (textura del boss), **#8** (puerta), minas/láseres.
  El mantenedor no percibe fallos (salvo lo de abajo).
- **#6 (regresión) CERRADO con gate de escala**: el rebobinado del efecto es un **reset de escala
  ~100×**; `rt64_rigid_body.cpp` ahora hace `HH_SCALE_GATE` **ON por defecto (2.0)** (`=0` off), con
  log a `hh_scale.log`. Validado en dos runs del jefe (determinista). El cambio especulativo `is_fx`
  9/13 se **revirtió**.
- **Identidad estable**: `stable_slot()` generacional (map<root,{slot,model,last_frame}>, slot nuevo
  si se recicla) → un objeto persistente conserva id (verificado: `root=80252214` slot=31, id
  constante 30 s). Los roots reciclados/efectos reciben slot nuevo (no heredan ids de objetos muertos).
- **Grupos**: pass 1 (`func_800068C0` fija el slot de objeto; `func_800069A8` emite **un grupo por
  NODO**, id=`FNV(slot_objeto, slot_nodo, gen)`). Los tipos 1..4 (sprites/2D) van con `G_EX_ID_IGNORE`
  (no interpolar); el resto `G_EX_ORDER_LINEAR`. Esto arregló el esqueleto del PJ (el grupo por OBJETO
  con LINEAR lo barajaba al cambiar el orden/nº de transforms; la métrica NO lo veía).
- **Generación de cámara**: corte si salto >90u o giro >90° (`D_801BBBF0+0xE8 → +0x2C`, pos +0x30,
  objetivo +0x3C). Se evalúa 1×/frame. Evita el barrido en cortes.
- Sin `gEXSetRDRAMExtended` (rompe widescreen). Sin skip-spawn propio.
- Limpieza: no se emiten grupos para nodos tipo 0 (contenedores no-op).

## Pendiente (lo de la sesión nueva)

1. **Pasada 2 (efectos/2D ordenados)** — el hilo principal que queda. **Diagnóstico hecho** con
   `[hh-emit]`: `7328/736C/73AC` son **compute-only** (no emiten gfx; sus grupos quedan colgados) y
   el cursor es el global único `D_8008D5BC` (el `groups_seen=0` de headless era el logo tipo 2 →
   falso positivo). Los emisores reales son `7DE4/8754/8F30/A828/C768/11958/919C`; los **2D/texrect**:
   **`919C` (tipo 9)** y **`11958` (tipo 13)**. Rellenar: enganchar el tagging en el emisor correcto
   (no en los wrappers) y validar con capturas.
2. **Sesgado de cámara ocasional** (2 veces en la run): probablemente *shearing* por la cámara
   horneada + descomposición por objeto a 30 fps (limitación conocida de PW64, agravada a 30). No es
   identidad. Investigar si `G_EX_COMPONENT_*` de la cámara o un grupo de cámara aparte lo mitiga.
3. **LOD** en el hash (id = slot, model, **lod**): no localizado el campo. Solo importa si un objeto
   cambia de malla por distancia; el slot generacional cubre parte. Medir si pasa.
4. **2D "de verdad"** (HUD/menús): `hud_rewrite` ya no interpola su proyección; confirmar que cubre
   todo (el combate 2D puede ir por la pasada 2).

## Instrumentación (reutilizable)

- `HH_MTXGROUP=1` tagging; `HH_MTXGROUP_LOG=1` → `[hh-types]` histograma de tipos de nodo (~2 s) y
  `[hh-interp]` cortes de cámara.
- `HH_PAIRING=1` → `[hh-pair]` (frames, transforms, explicit_ids, groups_seen, gen, groups,
  unpaired, unpaired_tagged, unpaired_moved). **OJO: `unpaired` no mide el fallo visual** (el fallo
  era *mal* emparejado, no "sin pareja").
- **Auto-captura** (clave para 1-frame): `HH_PAIRCAP=<min moved>` (frames con no-emparejados movidos)
  y `HH_GENCAP=1` (cortes de cámara) → `paircap_NNN_*.bmp` / `gencap_NNN_*.bmp` + `[hh-cap] auto` en
  `hh.log`. Tope 80 y 120 ms de separación. **El mantenedor no debe borrar los BMP hasta copiarlos.**
- `HH_FX_AUTO=1` → vuelve a interpolar tipos 1..4 (A/B). `HH_FX_PASS2=1` → activa hooks pasada 2.
- `HH_SCALE_GATE=<ratio>` + `HH_SCALE_GATE_LOG=1` en `lib/rt64` (sonda de escala, off).

### Banco headless (logos/menús; NO llega a gameplay)
```
Xvfb :99 & ; DISPLAY=:99 SDL_VIDEODRIVER=x11 SDL_AUDIODRIVER=dummy \
  VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json HH_MTXGROUP=1 HH_MTXGROUP_LOG=1 \
  timeout 20 "./Hybrid Heaven Recomp"   # cwd build/linux
```
**En headless `[hh-pair]` sale 0** (no presenta frames); `groups_seen=0` en menús es normal (logo
tipo 2 → `ID_IGNORE`). Para gameplay: run del mantenedor.

## Run del mantenedor (validación)
```powershell
hybrid-heaven-recomp\build_windows.local.bat; $env:HH_MTXGROUP='1'; $env:HH_PAIRING='1'; $env:HH_MTXGROUP_LOG='1'; $env:HH_PAIRCAP='2'; $env:HH_GENCAP='1'; hybrid-heaven-recomp\run_windows.bat release
```
Log: `build\windows\bin\Release\hh.log`. Reproducir: combate con partículas 2D (los "churros"),
minas, y el punto donde fallaba el sesgado de cámara.

## Árbol
- `src/hooks/model_tagging.cpp` (reescrito), `sections.cpp` (hooks), `rt64_render_context.cpp`
  (auto-captura + log), `patches/rt64/hh-interpolation-tagging.patch` (regenerado).
- `lib/rt64` SUCIO (fork): la instrumentación está en el patch; no commitear el submódulo.
- Nota: `notes/2026-10-03-fps-tagging-identidad-logica-y-generacion-camara.md`.

## Pitfalls (NO repetir)
- La identidad por dirección (nodo/modelo/root/índice de lista) **falla** (se recicla/desplaza).
- El nodo de render no tiene campo estable de instancia; la identidad se deriva del **comportamiento**
  (slots generacionales), no de una dirección.
- Un grupo por OBJETO con LINEAR **baraja huesos**; hace falta grupo por NODO.
- Parchear la pasada 2 sin validar puede romper la DL (usa otra vía de gfx).
- No editar el C generado; no tocar ROMs/forks sin pedir; no push sin pedir.
