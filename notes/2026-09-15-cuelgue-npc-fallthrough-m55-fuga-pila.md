# Cuelgue del NPC (ronda 7): fuga de pila 0x48/frame por fallthrough sin encadenar en el modulo 55

Fecha: 2026-09-15 (noche). Antecedentes: `…-stack-overflow-y-sombra-hilos.md`.

## Sintoma

- La sombra `hh_sh_*` elimina el cuelgue inmediato, pero:
  - pila del hilo 5 baja `0x27F0` cada 5 s (≈`0x48`/frame) y a los ~10 s queda aparcado para
    siempre en `osRecvMesg(mq=0x8005C288)`;
  - el objeto del NPC solo rota (no escala) y la caja de texto no desaparece.

## Evidencia (runs del usuario)

1. `hh_cmds.log` (recv de `0x8005C288`): `sp` baja **exactamente `0x48` por ciclo** de forma
   perfectamente lineal (≈444 saltos; `sp=8005BEE0 → 80054200`) desde que arranca la secuencia.
2. `hh_ring2_{3,4,5,7}.log` (volcado por paron, 60000 llamadas `target+sp`):
   - el bucle ocioso es estable (sp constante por iteracion);
   - la pila baja `0x48` **una vez por ciclo** (~21300 llamadas) y el unico candidato que aparece
     una vez por ciclo en todos los volcados es **`M55_FUN_80379690`** (sp −0x48 en cada frame:
     p. ej. dump5 `80058B98 → 80058B50`).
3. Analisis de tail-calls del recompilado (`LOOKUP_FUNC(x); return;`): dos objetivos con net −0x48
   en modulo 55 (`0x803798D8`, `0x80379798`), ambos *mid-entries* de `M55_FUN_803796e4`.

## Causa raiz

`RecompiledFuncs/funcs_106.c`: `M55_FUN_80379690` (entry 0x80379690) hace `addiu sp,sp,-0x48` y su
cuerpo termina en 0x803796E0 **cayendo a 0x803796E4** (continuacion = `M55_FUN_803796e4`), pero el
codigo generado terminaba en `;}` **sin encadenar la continuacion** → la funcion retornaba a su
llamador sin restaurar `sp` (fuga `0x48`) y **sin ejecutar la animacion del objeto**.

La continuacion `M55_FUN_803796e4` (432 lineas) es la logica de escala/animacion:
floats `0x4120`=10.0, `0x4361`=225.0, `0x42A0`=80.0, y escribe el contador de fase global
`0x8039-0x764C` (el mismo que `M55_FUN_80379690` compara con `0x14`/`0x33`). De ahi que el objeto
solo rotase y el texto no avanzase.

`tools/analysis/fix_fallthroughs.py` no lo detectaba: su heuristica era `has_ret = any("return;")`
en todo el cuerpo, y esta funcion tiene `return;` en ramas (`LOOKUP_FUNC(...); return;`) aunque al
final cae. Las funciones afectadas se iteran por direccion: 0x803796E0 + 4 = 0x803796E4 (entry de la
continuacion, misma seccion).

## Fix

`tools/analysis/fix_fallthroughs.py` (idempotente):

- La decision mira **solo la ultima sentencia real** (ignorando `}` de cierre):
  `is_ft = not term_ret and not term_goto and not tail_call`.
- Se exige ademas que la continuacion sea exactamente la instruccion siguiente:
  `func_addr(cont) == last_addr + 4` (evita encadenar a *mid-entries*).

Resultado de la pasada: `fallthrough functions found: 1953; chained: 1921; skipped: 32`.
Total de cadenas `// @fallthrough-fix` en el arbol: 2343. El caso conocido:

```c
// 0x803796E0: ldc1 $f0, -0x6AE8($at)
ctx->f0.u64 = LD(ctx->r1, -0X6AE8);
// @fallthrough-fix: split fallthrough -> chain to continuation
M55_FUN_803796e4(rdram, ctx);
```

`M55_FUN_803796e4` a su vez cae a `M55_FUN_80379904` (tambien encadenado), asi que la cadena de
animacion completa queda operativa. No se toco `build_windows.bat` (no recompila; usa el arbol).

## Verificacion

- Build Linux `build_dbg` OK; smoke 45 s con Xvfb: arranca, menus, sin crashes ni `Failed to find`.
- `hh_cmds.log` del smoke: `sp=8005BEE0` **constante** (mismo valor en todos los comandos), sin fuga.
- Pendiente: validacion en Windows (rebuild + `run_watch.bat`).

## Nota para el futuro

Tras `tools/recomp.py` hay que re-ejecutar `python3 tools/analysis/fix_fallthroughs.py`. Si se
regenera `RecompiledFuncs/`, comprobar que el numero de cadenas sigue siendo del orden de miles y
que `grep -c "@fallthrough-fix" funcs_106.c` incluye el caso 80379690.

## Ronda 8: mid-entry 0x80379954 y reconstrucción de syms

Tras el fix de fallthroughs, el juego ya **ejecutaba** la animación y crasheó en el siguiente
eslabón: `Failed to find function at 0x80379954` (rama dentro de `M55_FUN_803796e4`). Es el patrón
mid-entry: `0x80379954` está dentro de `M55_FUN_80379904` (tamaño 0x60 → había que partirlo en
`80379904` (0x50) + `80379954` (0x10)). Se añadieron a `config/module_extras.json` (módulo 55):

- `0x80379798`, `0x803798D8` (dentro de `803796e4`) y `0x80379954`.

Además de `0x80380010`/`0x803800A0` (fix de la ronda 5, que estaban en el árbol de trabajo pero no
commiteados y se perdieron al regenerar).

### Lección: los extras pueden disparar un cascado de `auto_mid`

Añadir 74 extras (todos los LOOKUP sin registrar de los módulos) hizo que `--self-pointer-mid-entries`
detectase más mid-entry dentro de los nuevos rangos → funciones nuevas en **datos** → N64Recomp
emitió `0 = cop0_register_read(ctx, 0);` (data como código) y el build falló en
`M12_FUN_8024567c` (texto SJIS). `fix_fallthroughs`/`validate_syms` no filtran esto.

### Reconstrucción fiable de los syms (método a recordar)

Los `.obj` de la build Release del usuario (`build_win/HybridHeavenRecomp.dir/Release/*.obj`) son la
**huella exacta** de los syms que compilaban: `strings *.obj | grep -oE "M\d+_FUN_[0-9a-f]{8}"`.
Con eso se reconstruyen los `us_moduleNN.syms.toml` (tamaños = siguiente dirección − dirección,
respetando overrides `0xADDR:0xSIZE` de los extras) y se llama a `setup_module.merge_syms()`. Después
`tools/recomp.py --config config/game_combined.toml --fix-syms` (el `--fix` es necesario: la plana
tiene ramas cruzadas que el combinado previo ya tenía fusionadas).

Estado resultante: `us_combined.syms.toml` reconstruido + cadena de animación registrada; build Linux
y smoke OK (`sp` constante en `hh_cmds.log`).

### Huecos conocidos (evidencia: análisis de `LOOKUP_FUNC` no registrados)

- Módulo 55: 27 direcciones (p. ej. `0x80380078`, `0x8037F570`, `0x8037A94C`). Dos de ellas
  (`0x8037C50C`, `0x8037C530`) son **casos de jump-table fusionada**: registrarlas parte el switch.
- Módulos 7/9/10/12/23/54: 4/4/1/6/8/34 direcciones. Planas: 43 (incluye las `ignored` del config).
- 8 direcciones de módulo son **delay slots** de un salto: no registrables sin romper el salto previo.
- Si el juego crashea con `Failed to find function at 0x...`, añadir esa dirección a
  `config/module_extras.json` del módulo **y regenerar con cuidado** (evitar el cascado: añadir solo
  las necesarias y comprobar que el build no revienta por datos).

## Ronda 9: rol del módulo 55 y registro completo de sus mid-entries

**El módulo 55 (sección 11, base `0x803757E0`, blob ROM `src 0x68FF2C`) es el overlay de la secuencia
de obtención de objeto del NPC.** Evidencia:

- `hh_ovl.log` (run del usuario): `t=13.168 module src=68FF2C section=11 ... ram=803757E0 funcs=261`
  — se carga **bajo demanda** justo al iniciar la interacción con el NPC (los menús no lo cargan).
- La cadena que arreglamos vive aquí: `80379690 → 80379798 → 803798D8 → 80379904 → 80379954`
  (floats `10.0/225.0/80.0` de escala/posición y el contador de fase global `0x8039-0x764C`).
- Todos los `Failed to find function` del bug del NPC son de este módulo: `0x80380010` (ronda 5),
  `0x80379954` (ronda 8), `0x803798E8` (ronda 9).
- Documentado en `docs/architecture.md` §2.2 (tabla de roles por módulo).

### Registro masivo de las entradas pendientes del módulo 55

Para no ir eslabón a eslabón, se registraron **de una vez** las 22 direcciones válidas del módulo 55
(las 5 restantes de su lista son delay slots de un salto: no registrables). Método:

1. Verificación en el blob de que la instrucción anterior no es un salto (descarta delay slots).
2. **Edición directa** de `config/us_module55.syms.toml` y `config/us_combined.syms.toml` (split en
   las 22 direcciones, tamaños = siguiente − dirección). Así se evita `setup_module.py` (y su cascado
   de `auto_mid`, que ya metió datos como código en este bug).
3. `python3 tools/recomp.py --config config/game_combined.toml --force`: el validador fusiona dos
   splits (`0x80378BB0`, `0x80379464`) por "ramas cruzadas" locales, pero sus `LOOKUP` vienen de
   **otra** función (epílogos compartidos) → hay que saltarse el validador.
   **Nota para la próxima sesión: recompilar requiere `--force`; sin él, la validación aborta.**

Resultado: 22/22 registradas (incluidas `0x8037C50C`/`0x8037C530`, antes inalcanzables por la fusión
de jump-tables de `gen_module_syms`). Build Linux + smoke OK (`sp` constante en `hh_cmds.log`).

### Huecos restantes (no bloquean la secuencia actual)

- Módulo 55: 5 delay slots (`0x80376CCC`, `0x80378020`, `0x80378EBC`, `0x80379230`, `0x8037F410`).
- Módulos 7/9/10/12/23/54: 4/4/1/6/8/34 direcciones sin registrar.
- Plana: 43 direcciones (incluye las `ignored` del config).

## Ronda 10 (REGRESIÓN, corregida): splits dentro de un switch con jump-table

Síntoma reportado: **bajar las primeras escaleras crashea** (`Failed to find function at
0x8037C8E4`), antes funcionaba.

Causa: en la ronda 9 forcé los splits `0x8037C50C` y `0x8037C530`, que **están dentro de un rango
fusionado por jump-table** (`M55_FUN_8037be10` = `0x8037BE10..0x8037C8F8`). Al partir el rango, el
switch perdió sus casos como etiquetas locales y N64Recomp empezó a emitir `LOOKUP_FUNC(caso)`; al
ejecutarse el switch (las escaleras usan ese dispatch) saltó a `0x8037C8E4`, no registrada → exit.

Fix: revertir esos dos splits (función fusionada restaurada a `0x8037BE10` size `0xAE8`) y sacarlos
de `keep_syms.txt`/`module_extras.json`. Recompilado con `--force`; verificado: `0x8037C8E4` ya **no**
es destino de `LOOKUP` y la cadena del objeto (79798/798e8/79954) sigue registrada. Build + smoke OK.

**Regla**: no partir nunca una función dentro de un rango de `merge_jump_tables`. Para detectarlo,
`tools/analysis/add_mid_entry.py` ahora **rechaza** direcciones dentro de un switch fusionado (usa
`gen_module_syms.merge_jump_tables` con los starts del propio syms). De las 22 entradas de la ronda 9
solo esas dos eran peligrosas; las otras 20 son seguras.
