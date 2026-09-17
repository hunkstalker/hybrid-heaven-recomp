# Ralentizaciones en puertas y 30 Hz lógicos vs refresco (pendiente, posterior al CaC)

> Registro de una observación del mantenedor (2026-09-17) para atacar **después** de las tareas en
> curso (bloqueante CaC). No es la causa del freeze del combate: el freeze persiste con la cadencia
> ya corregida (`notes/2026-09-17-validacion-windows-pacing-y-cac.md`).

## 1. Lo observado

- Percepción al cruzar puertas: tirones/ralentización, y sensación de "menos de 60".
- Datos de la pasada limpia de Windows (RTX 4080, `logs_pacing_20260917_123210`):
  - `polls`: mediana **28,4/s**, máximo **29,6/s** (nunca llega a 30), con dips a **21-25/s**
    (p.ej. t≈330-385 y t≈500); `audio` y `VI` clavados a 60,0/s.
  - El stutter visible aparece cuando un frame lógico se pasa de 33 ms y se muestra 50 ms (3 VI).

## 2. Aclaración de conceptos (para no confundir objetivos)

- **Lógica/tick**: HH corre a **30 Hz** (medido en Fase 0: frame y dispatcher cada 2 VI). Es diseño
  del original.
- **Refresco/VI**: 60 Hz (RT64 presenta a 60; también el N64).
- **Imágenes distintas por segundo**: solo hay imagen nueva cuando la lógica genera un frame (el
  display list se construye del estado). Ver 60 imágenes/s exigiría animar/renderizar a 60 Hz
  (interpolación) → **otro proyecto**; el objetivo del port es 30 estables + 60 de refresco, como el
  original.
- **Hitch de puerta**: parte es auténtica (el juego descomprime módulos `trans`/LZSS al transicionar;
  en `hh_ovl.log` se ven ráfagas de cargas de secciones 7/8/9/11 en ~1 s), pero si dura más que en el
  original es overhead nuestro.

## 3. Plan de medición (cuando toque)

1. Pasada Windows: `run_pacing.bat trace` + `HH_DIAG=1` cruzando 3-4 puertas → `hh_trace.log` (gaps
   con `t=`) + `hh_ovl.log` (cargas con `t=`); correlacionar gap ↔ carga y separar "hitch de carga"
   de "frame que pierde el deadline de 2 VI".
2. Alternativa determinista: grabar un replay cruzando una puerta (`HH_RECORD`) y reproducirlo en
   Linux con traza (RMSE=0) para medir sin ruido de la máquina del mantenedor.
3. Re-medir `cd4c` en limpio (con la cadencia correcta) para ver si vuelve a 0/1 o sigue en 1-2;
   puede explicar el ~5% sistemático.

## 4. Fixes candidatos (uno por pasada, tras medir)

- **Carga de módulos**: precarga/caché o decode en hilo host (el loader es guest-driven; acelerarlo
  no cambia el orden lógico).
- **Enganche a VI del bucle de lógica**: afinar para no perder el deadline de 2 VI (knobs
  `HH_NO_MQYIELD`/`HH_MQYIELD` ya disponibles; medir antes/después).
- **Reparto de CPU**: comprobar que el hilo de lógica no compite con gfx en escenas cargadas
  (en el contenedor llvmpipe lo agrava; en Windows con la 4080 no debería).

## 5. Prioridad

Después de: (a) bloqueante CaC (Parte B del plan), (b) cierre de tareas pendientes de la sesión
(teardown SEGV, mando X, limpieza). No bloquea jugar.
