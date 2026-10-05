# Fase B — cobertura de emparejamiento por sesión (oráculo `HH_PAIRING_LOG`)

> Registro acumulado. Cada sesión de juego deja un log con **nombre fijo** (`hh_pair.log`); el
> análisis lo **mueve a `work/pairing/`** (gitignored) y añade una línea aquí. Así una re-run no
> sobreescribe ni deja copias: el nombre fijo se libera al archivar.
> Herramienta: `tools/analysis/pairing_log.py` (adaptada de `wr3/tools/pairing_log.py`).

**Cómo leer la tabla**
- `paired/total`: transforms con pareja / dibujados. El resto son **primeras apariciones** (normal).
- `by id`: parejas por id explícita (nuestro tagging) vs heurística (`auto`). **`auto`≈0 es el canario**
  de que no hay caminos de dibujo sin taggear.
- `>100`: parejas con salto >100 u (spawns desde el origen son normales, `lerp=0`).

## Sesiones

| Sesión / zona | frames | transforms | paired/total | by id | auto | unpaired | >100 (lerp=1) | log |
|---|---|---|---|---|---|---|---|---|
| prueba (láser+elevador+inicio, 2026-10-05) | 7572 | 490182 | 98.18% | 481202 | 69 | 8911 | 64 | `hh_pair_20261005_prueba-laser-elevador-inicio.log` |
| **Área 1 completa** (hasta 2-1, 2026-10-05) | 49895 | 3528465 | 98.23% | 3465770 | **195** | 62500 | **1** | `hh_pair_20261005_area1_completa.log` |
| Elevador+cámara (2026-10-05) | 8484 | 476857 | 97.96% | 467025 | 123 | 9709 | **0** | `hh_pair_20261005_elevador-camara.log` |

Cámara (`hh_cam_20261005_elevador-camara.log`, `tools/analysis/camera_log.py`): 8472 frames, **11
cortes, todos teletransportes de 1 frame** (90–707 u; p. ej. elevador f4398→f4399: quieta 7 frames,
salta 95 u, luego baja suave 1,3/frame). La cámara está **quieta** el resto (`|v|` p99=7.4) → **sin
falsos positivos** por movimiento sostenido. El umbral 90 los caza y son discontinuidades reales.
**Ni el emparejamiento de objetos ni la detección de cortes explican los artefactos restantes** →
siguiente test decisivo: apagar **interpolación (F9)** en el artefacto (lo que sobreviva NO es
interpolación).

**Lectura**: cobertura de objetos del área 1 ≈ **completa**. `by id` 99.994%, `auto` 195/3.47M
(0.006%), y **1 solo** par interpolado >100 u en toda el área. Modelos multiparte: 267 en movimiento,
26 con una parte sin pareja/snap (piezas que aparecen/desaparecen, normal), 5797/5808 por identidad.
El ~1.8% sin pareja son primeras apariciones. Los saltos grandes son spawns (`lerp=0`, snap).
**Conclusión: el emparejamiento de objetos del área 1 está cubierto; los artefactos restantes
(láser/elevador) apuntan a CÁMARA, que el log aún no mide.**
