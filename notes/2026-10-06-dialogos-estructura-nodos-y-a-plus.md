# Diálogos: estructura real (nodos con texto inline) y reparto por mensaje (A+)

> Sesión 2026-10-06. **Corrige** `notes/2026-10-06-dialogos-guion-punteros-y-ruta-a.md` y descarta
> lo descrito en `notes/2026-10-06-dialogos-ruta-b-arena.md`. Evidencia: volcado RDRAM de Windows con
> el primer diálogo en pantalla (`HH_DUMP_RDRAM_AT`).

## 1. Estructura real (medida en el volcado)

El texto **no** está apuntado por los "punteros a texto" que creí: va **inline** en un "nodo":

```
80243CE0 (file_013 +0x33F0):
  +00 00001804
  +04 00000001
  +08 80244034        <- puntero al SIGUIENTE nodo (no al texto de este)
  +0C 000A1E03
  +10 00000000
  +14 F000FC00
  +18 00000000
  +1C texto "Ｍｒ．Ｄｉａｚ，…"   <- el texto empieza aquí, embebido
80244034 (+0x3744): 000A1E03 00000000 F000FC00 00000000 <texto "Excuse me.">
```

- La conversación se referencia desde una **tabla en otro módulo**: `0x803884B8 → 80243CE0, 80244368,
  8024478C, 80244AEC…`.
- Por eso los "16 punteros a texto" eran una coincidencia (los reales apuntan a nodos, no al texto).

**Consecuencia**: la **longitud libre moviendo datos** (ruta B) exigiría reconstruir nodos y parchear
las tablas/enlaces que los referencian, que viven en **otros módulos** → descartada.

## 2. La vía viable: A+ (reparto por MENSAJE)

No hace falta mover nada. Cada **mensaje** ocupa un tramo de tamaño fijo (de su primera línea al
opcode de fin `fa 00`). Dentro del tramo se pueden **mover los saltos de línea** y repartir el texto
mientras el total no crezca (la última línea se rellena). El "esperar botón" es por mensaje, así que
repartir líneas no altera nada. Verificado en la primera conversación (ES ≤ EN en todos los mensajes:

| mensaje | EN (chars) | ES (chars) |
|---|---|---|
| 0 | 75 | 72 |
| 1 | 92 | 84 |
| 2 | 63 | 49 |
| 3 | 76 | 60 |
| 4 | 59 | 52 |

## 3. Implementación (`src/subsystems/text.cpp`)

- `translate_euc` ahora **agrupa líneas en mensajes** (hasta un `fa 00`/`fe 00` en el hueco hacia la
  siguiente línea) y:
  - si el total traducido cabe en el tramo y la última línea es de texto → **A+**: reescribe el
    mensaje con los saltos de línea recolocados y rellena la cola;
  - si no → **fallback ruta A** por línea (solo si cabe en su tramo).
- Se retiró el código de la ruta B (arena + parcheo de punteros).
- `assets/lang/es.txt`: mensaje 1 de prueba con la frase peninsular completa (línea 1 = 30 chars,
  **excede** su original de 26 → demuestra A+).

## 4. Validación

- Compila (`cmake --build build/linux -j`).
- Simulación offline sobre `módulo 12`: 5/5 mensajes traducidos; el mensaje 1 sale
  `Sr.Diaz, puede que ya lo sepa, / pero hay una cosa de la que / debo informarle.`
- **Pendiente**: validación **visual en Windows** (sin variables; es el camino por defecto).

## 5. Límite que queda

El **ancho de la caja** (~30-32 chars/línea) y el nº de líneas visibles; no el tamaño del bloque.
Se resuelve redactando en español conciso y cortando las líneas para que quepan.
