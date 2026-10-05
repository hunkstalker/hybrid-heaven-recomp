# Interpolación: emparejamiento de transforms (método y oráculo)

> **Doc vivo.** Cómo RT64 interpola los frames que el juego no dibuja, cómo se le dice qué es cada
> transform (matrix groups) y **cómo medirlo sin jugar a mirar** (el *pairing log*). Reutilizable por
> otros repos de Hybrid Heaven y por cualquier port N64Recomp+RT64. Basado en los ports de referencia:
> `pilotwings-64-recomp` (`patches/interpolation.c`), y `wr3`/`zelda`/`waverace`
> (`docs/TRANSFORM-PAIRING.md`, `tools/patch_rt64.py`, `tools/pairing_log.py`,
> `patches/*_transform_tagging.c`). Ver también `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §3c.

## 1. Por qué

RT64 presenta a la tasa del monitor frames que el juego (a 30 Hz) no dibuja: empareja cada transform
de este frame con el del anterior y **interpola**. Cuando empareja mal dos transforms —de objetos
distintos, o de una parte de un modelo con otra— el resultado se ve como un barrido, una pieza que se
desprende, o un objeto que “planea” de sitio. **El defecto no es la interpolación: es el pareado.**

## 2. El método estándar (decirle a RT64 qué es cada transform)

Se envuelve cada punto de dibujo 3D con un **matrix group** con un `id` lógico:

```
gEXMatrixGroupDecomposed(id, PUSH, G_MTX_MODELVIEW, pos/rot/scale=INTERPOLATE, resto=SKIP,
                         ORDER, EDIT_NONE, ...)   // abre
... carga la(s) matriz(es) del objeto ...
gEXPopMatrixGroup(G_MTX_MODELVIEW)                 // cierra
```

RT64 empareja por `id` y orden dentro del grupo. Reglas:

- **`id = FNV(kind, objeto, modelo, LOD)`, nunca una dirección cruda**, y **mezclado con una
  “generación de cámara”** que avanza en cada corte (la cámara va horneada en cada matriz; un corte
  mueve todo a la vez, así que un corte debe cambiar *todos* los ids o RT64 barre el encuadre).
- **`G_EX_ORDER_LINEAR`**: las mismas partes, en el mismo orden. **`AUTO`**: cosas cuyas piezas
  aparecen/desaparecen (efectos). **`G_EX_ID_IGNORE`** (`gEXMatrixGroupNoInterpolate`): 2D.
- **Un id sin contraparte en el frame anterior NO se interpola**: así un spawn, un corte o un cambio
  de LOD evitan el barrido. Por eso el id debe **cambiar** en un respawn (modelo/slot nuevos).
- **Efectos: interpolar** (`AUTO`), no ignorar (sus matrices también llevan la cámara).
- **Cámara**: grupo de **proyección** aparte con `INTERPOLATE_SIMPLE`.
- No hace falta lógica de “skip de spawn”: RT64 lo hace solo si el id no tiene pareja.

Desviaciones que HH necesita (validadas): la cámara de HH va **horneada en el modelview**, así que un
grupo de proyección la **duplica** → proyección **OFF**; el corte se maneja con la generación. El
tagging del traversal/dispatch cubre el pass-1; los emisores/C768 el resto (ver §5).

## 3. El oráculo: `HH_PAIRING_LOG`

En vez de mirar el juego, se **mide**. En RT64 (`GameFrame::match`, tras `matchScenes`), con
`HH_PAIRING_LOG=<fichero>` se escribe **una línea por transform y frame**:

```
F <frame> wall=<ms>                    inicio de frame
T <t> <prev> <id|auto> id=<id> call=<hash> range=<lo>-<hi> cur=<x,y,z> prev=<x,y,z>
    jump=<u> lerp=<0|1> pvel=<u>       transform emparejado
U <t> id=<id> call=<hash> range=<lo>-<hi> cur=<x,y,z>     sin pareja
S frame=<n> total=<n> paired=<n> j50=<n> j100=<n> j200=<n> max=<u> refused=<n>   resumen
```

- `id` vs `auto`: pareado por **id explícita** (nuestro tagging) o por la **heurística** de RT64.
- `jump`: distancia entre la traslación previa y la actual; `lerp`: si RT64 la interpola; `pvel`:
  velocidad previa (una `pvel` grande en un `jump` pequeño delata el rastro de un pareado erróneo).
- `refused`: candidatos que el **límite de pareja** (§6) rechazó.
- `HH_PAIRING_LOG` acepta `%t` (fecha-hora) para no pisar entre sesiones; `HH_PAIRING_LOG_MAX` limita
  las líneas.

Lectura (lector adaptado de `wr3/tools/pairing_log.py`):

```
python3 tools/analysis/pairing_log.py hh_pair.log            # totales y distribución de saltos
python3 tools/analysis/pairing_log.py hh_pair.log --over 100 # frames con pares >100 u
python3 tools/analysis/pairing_log.py hh_pair.log --models   # modelos multiparte sin pareja/snap
python3 tools/analysis/pairing_log.py hh_pair.log --calls     # agrupar por hash de draw call
```

### 3b. Oráculo de cámara (`HH_CAM_LOG`)

El pairing log cubre **objetos**; para la **cámara** hay un log aparte (port-side, en
`src/hooks/model_tagging.cpp`): `HH_CAM_LOG=<fichero>` escribe una línea `C` por frame con `eye`/`at`,
velocidad `v`, aceleración `a`, `dot` (giro) y si se detectó corte. Lector:
`python3 tools/analysis/camera_log.py hh_cam.log [--cuts]`. Sirve para distinguir un **corte real**
(discontinuidad: `|v|` o `|a|` grande, o `dot` bajo) de un **movimiento rápido sostenido** (elevador:
`|v|` alto pero `|a|` bajo) y diseñar la regla por predicción.

## 4. Qué mirar (el criterio, sin ojo)

| Métrica | Objetivo | Delata |
|---|---|---|
| `paired/total` | ≈1 (el resto = primeras apariciones) | caminos sin pareja |
| `by id` / `paired` | ≈1 (hoy 99.99%) | tagging incompleto (sube `auto`) |
| `auto` | ≈0 | ruta de dibujo sin taggear (**canario**) |
| saltos `>100` con `lerp=1` | ≈0 | pares erróneos o saltos reales (spawns van `lerp=0`) |
| `--models` partes unpaired/snapped | 0 | piezas de un modelo emparejadas mal |

**Regla de oro**: que `auto`≈0 y no suban los unpaired/snap. Si aparece un artefacto, el log dice si es
(a) objeto sin id, (b) pareado erróneo (salto grande con `lerp=1`), (c) spawn (salto grande `lerp=0`,
inocuo) o (d) cámara. No se toca nada sin esto.

## 5. Recetario: portarlo a otro proyecto (N64Recomp + RT64)

1. **Oráculo primero** (§3). Engancha en `GameFrame::match` (tras `matchScenes`); recorre
   `frameMap.workloads[w].transforms[t]` (`mapped`, `prevTransformIndex`, `rigidBody`); la traslación
   es la fila 3 de `drawData.worldTransforms[t]`; el `id` sale de
   `transformGroups[worldTransformGroups[t]].matrixId`. Escribe `F/T/U/S` por frame.
   `patches/rt64/hh-fase-b-experimental.patch` es nuestra versión.
2. **Lector** (§3). `tools/analysis/pairing_log.py`.
3. **Tagging por categorías**, no por bug. En HH: traversal `func_800068C0` → dispatch
   `func_800069A8` (tipos 1–13) → emisores; pass-2 `C768`. En los port de referencia se hace con
   `patches/*_transform_tagging.c` + un `transform_ids.h` de rangos por categoría
   (cámara/actor/efecto/terreno/2D…). **El grupo debe emitirse donde está la geometría** (mismo
   workload RSP) o no materializa. En HH el único que materializaba era C768.
4. **Identidad de piezas** (modelos multiparte): id desde la **dirección estable de la matriz**
   (re-expresar la dirección directa entre los dos búferes dobles; ver `TRANSFORM-PAIRING.md` §5),
   `translation=INTERPOLATE`, y **skip si una pieza saltó >150 u** o es nueva.
5. **Cámara**: cortar por **predicción de velocidad** (`eye`/`at`), no por umbral de distancia
   (`camera_transform_tagging.c::should_interpolate_perspective`); parear escenas por
   **región de pantalla + slot de framebuffer** (`TRANSFORM-PAIRING.md` §3).
6. **Límite de pareja** en `computeTransformMatch`: rechazar pares a más de N unidades (p. ej. 150 u)
   antes de puntuar la velocidad. General: mata “objetos que planean”. Código en `TRANSFORM-PAIRING.md` §4.

## 6. Verificar sin ojo

- **A la tasa del juego** (sin interpolar): lo que sobreviva al apagar la interpolación **no** es
  interpolación.
- **Ejercitar todo el contenido** con el oráculo (en HH: `IR A ÁREA` / jugar el área entera) y mirar el
  **canario** por zona; así el % medido pasa de “lo jugado” a “todo el juego”.
- **Probar con cámara moviéndose** y durante un tramo, no unos frames.

## 7. Referencias

- `pilotwings-64-recomp`: `docs/PORTING.md` §Frame interpolation, `patches/interpolation.c/h`.
- `wr3` (Wave Race): `docs/TRANSFORM-PAIRING.md` (manual + recetario), `docs/PORTING.md` §Interpolation,
  `tools/patch_rt64.py`, `tools/pairing_log.py`.
- `zelda`/`waverace` (MM): `patches/*_transform_tagging.c`, `camera_transform_tagging.c`
  (`should_interpolate_perspective`), `transform_ids.h`.
- HH: `notes/2026-10-05-fase-b-materializacion-c768.md`,
  `notes/2026-10-05-fase-b-cobertura-sesiones.md`,
  `notes/2026-10-03-fps-tagging-dobj-y-handoff.md` §3c.
