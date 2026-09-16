# 2026-09-16 — Fix del estado de caída: fallthrough M55 `0x8037A6F4` → `0x8037A884` (fuga `0x38`/frame)

> Continúa `2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md` (ronda 14). Ahí quedó: láser
> arreglado (`HH_S0FIX`) y medido un hundimiento de pila del hilo principal durante la caída
> (`sp` −0x38/frame) con el personaje que no se levanta. **Ronda 15 = causa raíz encontrada,
> corregida y validada en Windows por el usuario.**

## Síntoma

- Tras el impacto del láser (ya sin cuelgue) el personaje cae pero **no se levanta** (debería en
  1-2 s); los input polls se congelan (~t=80-85) y el watchdog volca y sale.
- El `sp` del main desciende exactamente `0x38` por frame durante el estado de caída.

## Método (dumps `hh_ring2` de `run_watch`)

Los `hh_ring2_3..8.log` son 60000 pares `target sp` (sp = del **llamante** en el momento del
`get_function`) volcados al bloquearse el main en la cola C288 con `sp < 0x8005B000`. Localización
por **niveles de sp**:

- `F` = `FUN_80001454` (frame) se llama desde el bucle principal con `sp = S`; dentro llama a
  `P = FUN_80005270` (base `S−0x68`), el dispatcher de objetos que invoca cada update por `jalr`.
- En la ventana de cada frame, `P` llama **una vez** a `0x8037A6F4` y **al volver de esa llamada su
  base queda 0x38 más abajo** (dos frames consecutivos del dump 6):
  - `[3983] 8037A6F4 @80059630 → [3984] 8037B9F0 @800595F8`
  - `[18495] 8037A6F4 @800595F8 → [18496] 8037B9F0 @800595C0`
  - después, los helpers de `P` siguen a la base hundida (p. ej. `[18720] 80006214 @800595C0`) →
    confirma que el retorno de `0x8037A6F4` dejó la pila 0x38 abajo.
- `grep 0x8037A888|0x8037A94C|0x8037A950 hh_ring2_6.log` = **0 coincidencias**: la continuación y
  el epílogo compartido **nunca se ejecutan**.

## Causa raíz

`M55_FUN_8037a6f4` (`funcs_106.c`) termina así:

```c
// 0x8037A880: beq         $v0, $zero, L_8037A94C
if (ctx->r2 == 0) {
        LOOKUP_FUNC(0x8037A94C)(rdram, ctx);
return;
}
;}
```

- En la ROM, el camino `v0 != 0` ejecuta el delay slot `0x8037A884: lui $t3,0x8018` y **continúa en
  `0x8037A888`** (cuerpo del símbolo contiguo `M55_FUN_8037a884`, que comparte código: usa `s0` del
  llamante, `lw ra,0x24($sp)` y desemboca en el **epílogo compartido**
  `0x8037A94C: lw ra,0x24(sp)` → `0x8037A950: lw s0,0x20(sp); addiu sp,sp,0x38; jr ra`).
- En el port ese camino cae al `;}` del cuerpo C: `return` **sin epílogo** →
  - fuga exacta de `0x38` (= tamaño del frame de `a6f4`) por frame, y
  - **no ejecuta la lógica de la continuación** (`0x8037A888..0x8037A92C`: fija timers/estados del
    objeto —`sw 0x1C(v0) = 0x1900074/0x1900076`— y llama a `0x80020744`, `0x800058DC`,
    `0x8013A28C`) → el estado de caída no avanza → el personaje no se levanta.
- Por qué el tool no lo vio: `fix_fallthroughs.py` decidía por la **última sentencia C** y el
  `return;` (dentro del `if` final) se consideraba terminador.

## Fix

- `tools/analysis/fix_fallthroughs.py`: nueva regla — si la **última instrucción ROM** de la
  función es una **rama condicional** (`beq/bne/beql/bnel/bgtz/...`) hay fall-through aunque la
  última sentencia C sea `return`/`goto` (dentro del `if`); se encadena si la continuación está en
  `last_addr + 4` (los 31 candidatos restantes se descartan por no cumplirlo: son fragmentos
  internos sin continuación real).
- Re-ejecución del tool → **1 cadena nueva** (`M55_FUN_8037a6f4` → `M55_FUN_8037a884`), idempotente
  (2ª pasada: 0). Encadenar a la continuación ejecuta también el delay slot `lui $t3` (primera
  instrucción del símbolo contiguo), fiel a la ROM.

## Validación

- Build Linux (`cmake --build build2`) OK; `port/windows_runtime_changes.patch` en sincronía (no
  hubo cambios de runtime: este fix es solo C recompilado).
- **Usuario en Windows: "Arreglado"** — tras el láser el personaje cae y se levanta.

## Comandos

```sh
python3 tools/analysis/fix_fallthroughs.py            # idempotente; --dry-run para revisar
python3 tools/analysis/fix_fallthroughs.py --dry-run
```

## Lecciones

- En M55 hay **epílogos compartidos** (`0x8037A94C` + `0x8037A950`) usados por varios símbolos con
  frame `0x38`; los símbolos contiguos pueden compartir el delay slot como primera instrucción
  (`0x8037A884`). La regla de ramas condicionales finales cubre este patrón.
- El método de **niveles de sp en `hh_ring2`** (buscar la llamada tras la que la base del llamante
  baja) vuelve a ser la vía rápida para fugas de pila; no hizo falta runtime nuevo.
- La fuga `0x38`/frame era el **síntoma**; el bug funcional era la **lógica saltada** (la caída no
  avanzaba). Mismo patrón que el fallthrough del objeto del NPC (ronda 7): cadena ausente al final
  de símbolo.

## Commits

- `fix(recomp): encadenar fallthrough M55_FUN_8037a6f4->8037a884 (fuga 0x38/frame en la caida)`
- `docs: ronda 15 (fix de la caida validado; heuristica de ramas condicionales)`
