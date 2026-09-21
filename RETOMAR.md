# RETOMAR — anclaje del HUD (widescreen, fase 07b)

> Handoff para una **sesión nueva** que coja el testigo. **Última sesión: 2026-09-21.**
> **Tarea de esta etapa: anclar el HUD/mapa a los bordes** con el widescreen activo (el 3D ya llena la
> ventana; el HUD/mapa se queda en la zona 4:3). Es **cosmético** y **opcional**; el widescreen por
> defecto ya funciona sin él.
>
> **Estado del repo**: `main` pusheado a `c94dce9` (3 commits: Release GUI sin consola, versión como
> fuente única `0.2.0`, accesos directos build/run por config). El **mantenedor está creando el
> Release `v0.2.0`** desde GitHub (el CI debe pasar antes). Sin cambios locales salvo `lib/rt64` en
> `m` (dirty preexistente). Nada pendiente de commitear.
>
> **Lee primero**: este fichero; `docs/BUILDING_windows.md` §“[video]” (widescreen y `HH_FULL_FRAME`);
> `TODO.md` (backlog). El histórico per-file/ELF está en `notes/` (no hace falta para esta tarea).

---

## 0. OBJETIVO

Con widescreen (`[video] aspect = auto|expand`, **default**) la escena 3D **llena la ventana**, pero
el **HUD/mapa** (radar arriba-izquierda, barras POWER/STAMINA/HP, cajas de diálogo) siguen dibujándose
en la zona 4:3 centrada — **no se desmontan**, solo no se re-anclan. Meta: que el radar (y los
elementos que corresponda) se **anclen al borde** correspondiente (izquierda/derecha), como en el port
de referencia.

## 1. CAUSA (por qué pasa)

El juego dibuja la escena dentro de un `G_SETSCISSOR` de *overscan* 4:3 y el HUD bajo una proyección
**ortográfica** de 320×240. RT64, en `aspect = Expand`, ensancha el 3D pero **no** re-ancla la 2D: no
hay opción de configuración para eso. Hay que **insertar GBI extendido de RT64** alrededor de cada
elemento 2D clasificado.

**Ya hecho** (`src/hooks/dl_snap.cpp`, adaptado de la referencia `src/dlcensus.cpp` Phase 07):
recorremos cada display list enviada y **reescribimos in-place** el scissor de overscan
(`16,8..304,232` → `0,0..320,240`; `32,16..608,464` → `0,0..640,480`, conservando bits de modo). Eso
hace que el 3D llene. **Falta**: el anclaje del HUD (esto es lo que hay que hacer ahora).
`HH_FULL_FRAME=0` desactiva todo el widescreen (A/B).

## 2. CÓMO LO RESUELVE LA REFERENCIA (Phase 07, MIT)

Repo de referencia: **`danielgomesvieira2000/hybrid-heaven-recomp`** (MIT; ver `CREDITS.md` y
`licenses/hybrid-heaven-recomp-MIT.txt`). Ficheros clave (para consultar/re-clonar; el clon temporal
de la sesión anterior estaba en `/tmp/opencode/ref-hh`, **puede no existir ya**):

| Fichero (referencia) | Qué aporta |
|---|---|
| `docs/findings/phase-07.md` | **La crónica completa** (corridas, errores y hallazgos). Leer entero. |
| `src/hudrewrite.cpp` (~398 líneas) | El reescritor: copia la lista a RDRAM scratch e inserta GBI extendido. |
| `src/dlcensus.cpp` (~520) | Censo/identidades de los elementos 2D + el *snap* de overscan (`HH_FULL_FRAME`). |
| `include/hh/hudid.h` (~69) | Identidades con hash (clave para no sobre-emparejar entre escenas). |
| `include/hh/hudrewrite.h` | Contrato (`rewrite(rdram, list_address)` → dirección del copy, o 0). |
| `include/hh/inspector.h` | Clases del inspector F1 (`kLeft`/`kRight`/`kStretch`/`kSpill`/`kAuto`). |

### Mecanismo (resumen fiel)

`rewrite(rdram, list_address)`:
1. Si no hay ninguna clase asignada → devuelve 0 (se envía la lista del juego tal cual).
2. Elige uno de **dos buffers scratch** en RDRAM (en la referencia `0x807A0000` / `0x807C8000`,
   0x28000 bytes cada uno; se **alternan por frame**), y **copia la lista** ahí recorriéndola y:
   - emite `gEXEnable` al **principio de cada lista** (RT64 olvida el GBI extendido al terminar cada
     lista) y **tras cada llamada**;
   - **calls** (`G_DL` push): copia el destino y salta por encima (placeholder reescrito a branch
     no-push); **branches** (`G_DL` no-push): sigue el destino *inline* (¡el dial del radar se alcanza
     así!);
   - **rects** (`G_TEXRECT`/`G_TEXRECTFLIP` con su `RDPHALF`, y `G_FILLRECT`): envuelve con
     `rect_begin(cls)`/`rect_end(cls)`;
   - **grupos de triángulos** (listas llamadas): `group_begin(cls)`/`group_end(cls)`;
   - mantiene estado: segmentos (`G_MOVEWORD` idx 6 → **F3DEX2: índice en bits 16-23**), `fb_width`
     (`G_SETCIMG`: 320/640), imagen (`G_SETTIMG`), color de relleno (`G_SETFILLCOLOR`), viewport
     (`G_MOVEMEM` idx 8), proyección (`G_MTX` idx 4).
3. Si **desborda** o la lista no termina en `G_ENDDL` → devuelve 0 (envía la original; log de aviso).
4. Devuelve la dirección KSEG0 (`0x80000000 | (base + start)`) y el frontend **envía esa** en vez de
   la del juego.

### Emisión de GBI extendido según clase

- **left**: `widen_scissor()` + `gEXSetRectAlign(cmd, LEFT, LEFT, 0,0,0,0)` (rects) /
  `gEXSetViewportAlign(cmd, LEFT, offset, 0)` + reemitir el viewport (grupos de triángulos).
- **right**: igual con `RIGHT` y `off = origin_cancel(G_EX_ORIGIN_RIGHT)` (compensa el
  desplazamiento que RT64 aplica a la coordenada anclada: `off = -(origin*fb_width*4)/G_EX_ORIGIN_RIGHT`).
- **stretch**: `gEXSetRectAspect(cmd, G_EX_ASPECT_STRETCH)` (rects) / grupo de proyección con
  `gEXMatrixGroup(..., G_EX_ASPECT_STRETCH)` + reemitir la proyección (triángulos).
- **spill**: solo `widen_scissor()`.
- Al cerrar: reverso (`G_EX_ORIGIN_NONE` / `G_EX_ASPECT_AUTO`, y restaurar scissor/viewport).
- `widen_scissor()`: `gEXSetScissor(cmd, mode, G_EX_ORIGIN_LEFT, G_EX_ORIGIN_RIGHT, ulx, uly, lrx-fb_width, lry)`.

GBI extendido disponible: **`lib/rt64/include/rt64_extended_gbi.h`** (definir `#define F3DEX_GBI_2`
antes de incluirlo). Macros/constantes usadas:
`gEXEnable(cmd)`, `gEXSetScissor(cmd,mode,lorigin,rorigin,ulx,uly,lrx,lry)`,
`gEXSetRectAlign(cmd,lorigin,rorigin,ulxOff,ulyOff,lrxOff,lryOff)`,
`gEXSetViewportAlign(cmd,origin,xOff,yOff)`, `gEXSetRectAspect(cmd,aspect)`,
`gEXMatrixGroup(cmd,id,mode,push,proj,pos,rot,scale,skew,persp,vert,tile,order,edit,aspect,tc,lookat)`;
`G_EX_ORIGIN_{NONE,LEFT,CENTER,RIGHT}`, `G_EX_ASPECT_{AUTO,STRETCH,ADJUST}`, `G_EX_ID_AUTO`,
`G_EX_INTERPOLATE_SIMPLE`. Cada `gEX*` ocupa **2 commands Gfx (16 bytes)** → `reserve(2)`.

### Identidades de los elementos HH (de la referencia, `HH_HUD_ELEMENTS_LOG=1`)

Formato (ver `hudid.h`): `tex:<addr>#<hash 64B>`, `dl:<addr>#<hash 16 cmds>`,
`fill:<color>@ulx,uly,lrx,lry`; **los fills a pantalla completa son *clears* y no tienen identidad**.

Promocionados en la referencia:
- **left**: `tex:0x802866f8#a3036828`, `tex:0x80286af8#dfde6ac5` (radar, dos capas de textura,
  rects 27,19..59,51) y `dl:0x80181860#e59a0172` (dial del radar, 12..72 × 5..65, alcanzado por
  **branch**).
- **right**: `dl:0x03000f10#1427da33`, `dl:0x030002e0#bbb8c0ba`, `fill:0x00000000@197,143,277,223`.

> **IMPORTANTE**: los hashes son de la build de la referencia. Como es la **misma ROM**, el
> *contenido* debería coincidir, pero **hay que re-derivarlos con nuestra build** (los `#hash`
> dependen del contenido, no de direcciones; las direcciones de heap pueden variar). Necesitamos un
> **trace** propio (equivalente a `HH_HUD_ELEMENTS_LOG`) para listar identidades una vez y fijarlas.

---

## 3. QUÉ HAY QUE HACER (plan)

1. **Re-derivar identidades**: añadir un trace temporal (p. ej. `HH_HUD_TRACE=1`) que, recorriendo las
   listas como ya hace `dl_snap.cpp`, imprima `tex:`/`dl:`/`fill:` (con el mismo hash de `hudid.h`)
   **una vez por identidad**, con su extensión en 320×240. Correr en exploración (radar visible) y
   apuntar las identidades reales.
2. **Clasificar**: por ahora **no** hay inspector F1. Empezar con una **tabla fija** (las identidades
   del punto 1) → `left` (radar); valorar `right` (los 3 de la referencia) y `stretch`. Empezar por
   **el radar a la izquierda** y validar antes de añadir más.
3. **Reescribir la lista**: nuevo módulo `src/hooks/hud_rewrite.cpp` (o extender `dl_snap.cpp`)
   implementando el `copy_list` + emisión del §2. Enganchar en el mismo sitio que el snap:
   `src/platform/rt64_render_context.cpp:274` (`send_dl`, `hh::snap_overscan(app->core.RDRAM, task->t.data_ptr)`);
   tras el snap, calcular `nueva = hh::hud_rewrite(rdram, data_ptr)` y usar `nueva` si ≠ 0.
   Añadir el fichero a `CMakeLists.txt`.
4. **Elegir RDRAM scratch segura** (ver §4).
5. **Validar** visualmente (ver §5).

## 4. SCRATCH RDRAM — ¡verificar en NUESTRA build!

La referencia eligió `0x807A0000`/`0x807C8000` porque en **su** layout el fichero 3 termina en
`0x80796000` y la lista de comandos de audio vive en `0x807F0000`. **Nuestro build debe confirmarse**
(misma ROM ⇒ probablemente igual, pero comprobar): que la región elegida **no** la usa el juego ni el
runtime. Pistas: el port no reserva ahí (no hay constantes `0x806/0x807` en `src/`); el `trans_cache`
y el replay usan memoria host. Método seguro: dump de RDRAM + observar que la región no cambia de
forma viva, o buscar las reservas del `.text`/heap en la config de recompilación (`recomp/`).
Dos buffers **alternos por frame** (el frame anterior puede seguir en vuelo).

## 5. VALIDACIÓN

- Con `aspect=auto|expand` (default) y widescreen ON: el **radar queda pegado al borde izquierdo** de
  la ventana (antes: en la zona 4:3). Barras/diálogos según se clasifiquen.
- **A/B** con un interruptor (p. ej. `HH_NO_HUD_REWRITE=1`): con él, el radar vuelve a la zona 4:3.
- **No romper otras escenas** (regresión conocida de la referencia: al promover tags por dirección,
  la intro del **Expansion Pak** quedaba sin limpiar a la izquierda). Con identidades **hasheadas** no
  dispara. Comprobar explícitamente: intro/Expansion Pak, título, exploración, combate.
- En `hh.log`/stderr dejar trazas de “N elementos clasificados dibujados” (como la referencia).

## 6. GOTCHAS (aprendidos en la referencia)

- El **dial del radar** se alcanza por `G_DL` **branch** (no call) → hay que envolver el branch.
- **F3DEX2** `G_MOVEWORD` idx 6: el **índice va en bits 16-23** y el offset (segmento×4) en los 16
  bajos (Fast3D lo decodifica mal; ya lo hacemos bien en `dl_snap.cpp`).
- `fb_width` cambia (320/640) vía `G_SETCIMG` (`0x00400000` ⇒ 640); las extensiones se miden en
  **320×240** (halvar en hi-res).
- Los **fills a pantalla completa son *clears*** → sin identidad (si se clasifican, manchan otras
  escenas).
- Identidades **por contenido (hash)**, no por dirección/color.
- `gEXEnable` al inicio de **cada** lista y tras **cada** call (RT64 resetea el GBI extendido).
- Si el copy **desborda** o no acaba en `G_ENDDL` → **enviar la lista original** (nunca a medias).
- Con el snap global ya activo, el `widen_scissor` por elemento puede ser redundante; decidir si el
  reescritor sustituye al snap o convive con él.

## 7. FICHEROS NUESTROS

- `src/hooks/dl_snap.cpp` — snap de overscan (base a reutilizar: `Walker`, `physical()`, `dl_word()`,
  decodificación de `G_SETSCISSOR`/`G_DL`/`G_MOVEWORD`).
- `src/platform/rt64_render_context.cpp:271-274` — `send_dl` (punto de enganche; llama `snap_overscan`).
- `include/hh.h:76-92` — `VideoConfig`/`video_config()`/`full_frame_enabled()`/`snap_overscan()`.
- `lib/rt64/include/rt64_extended_gbi.h` — GBI extendido.
- `docs/BUILDING_windows.md` §“[video]” — widescreen y `HH_FULL_FRAME`.
- `TODO.md` (backlog: “Widescreen: anclaje del HUD/mapa…”).

## 8. ENVS / INTERRUPTORES

- `HH_FULL_FRAME=0` — desactiva el widescreen (snap de scissor). Default ON.
- (a añadir) `HH_NO_HUD_REWRITE=1` — desactiva solo el anclaje del HUD (A/B).
- (a añadir) `HH_HUD_TRACE=1` — lista identidades 2D una vez (para re-derivar).
- `config.ini [video] aspect` — `auto`/`expand` (widescreen), `original` (4:3).

## 9. PRIMEROS PASOS DE LA SESIÓN NUEVA

1. Leer `docs/findings/phase-07.md` de la referencia (re-clonar el repo si hace falta:
   `https://github.com/danielgomesvieira2000/hybrid-heaven-recomp`).
2. Re-derivar identidades (§3.1) en un run de exploración; confirmar radar (rects 27,19..59,51).
3. Implementar el copy+emisión (§3.3) empezando **solo por el radar** → `left`.
4. Confirmar la RDRAM scratch (§4) y validar (§5), incluida la no-regresión de la intro/Expansion Pak.
5. Si funciona, ampliar a `right`/`stretch` (barras/cajas) según se vea.

---

## ANEXO — Pendientes de otras áreas (no son esta tarea)

- **Release `v0.2.0`**: el mantenedor lo crea desde GitHub; requiere CI verde del commit `c94dce9`.
- **Estéreo L/R**: corregido (`queue_samples` des-swapea); **falta validar de oído en Windows** (cascos).
- **Menú in-game (ADR 0008)**, **traducción/subtítulos**, **audio desacoplado de fps**: en `TODO.md`.
