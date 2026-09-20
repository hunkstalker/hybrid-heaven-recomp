# 2026-09-20 (noche-5) — Origen del nodo `0x8005BF14` y captura del pisado

> Continuación de `2026-09-19-causa-raiz-cadencia-frames.md` §13-§16. Aquí se **corrige** el
> mecanismo de `FUN_80000934` (el nodo NO lo asigna `FUN_800267F0`) y se **identifica el origen**
> del nodo corrupto: es un **local de pila** del bucle principal `FUN_800011b0` (hilo 5). Se añade
> instrumentación nueva (`[NODEWATCH]`, `[BCORRUPT]`) y se documenta que la reproducción headless
> actual ya **no** da la corrupción con el comando de `RETOMAR` (sí da un deadlock plano).

## 0. RESUMEN (TL;DR)

**Qué estaba pasando.** En el CaC, el port entra en la **cadena del disable** (evento temporizado
`scheduler 0x39` → instala el callback "veneno" `0xFFFF84CD`), que el **emulador nunca ejecuta**. Al
ejecutarla, sus funciones **mid-entry** (`M55_FUN_80379410/424/444/464`, sin prólogo `-0x58` pero con
el **epílogo compartido `0x8037948C`** que suma `+0x58`) y el **dispatcher de callbacks
`FUN_80005270`** devuelven `sp` **+0x58 por llamada**. El `sp` del hilo 5 **trepa ~0x58/frame** hasta
**pisar el marco de `FUN_800011b0`**, donde vive el nodo de suscriptores `0x8005BF14` (su `next`/`q`
se sobrescriben con datos de esos marcos). Eso corrompía la lista de suscriptores del event-dispatch →
`[BADMQ]` (envíos a colas basura) → hilos bloqueados en `osRecvMesg` → **freeze/softlock**.

**Qué se ha resuelto.** La **fuga de pila** (y con ella la corrupción del nodo, el `[BADMQ]` y el
deadlock de colas). Fix: `HH_M55SPFIX=1` restaura `sp` en el cluster M55 y en el dispatcher
`FUN_80005270` (candidato runtime; el arreglo limpio definitivo sería corregir las fronteras de
símbolos). **Validado en Windows**: el nodo `0x8005BF14` ya **no se pisa** (`[NODEWATCH]` solo vi=32,
sin `[BCORRUPT]`, lista `80095FF8 → 8005BF14 (q=8005C288, next=0)` intacta en el dump del cuelgue) y
el juego **llega al CaC con el HUD de combate apareciendo**.

**Qué queda.** El port **sigue entrando en la cadena del disable** (el "veneno" aún se instala) y
ahora hace un **livelock** de tid 5 en código M10/M12 del CaC (`M10_FUN_80228298`, `ra=000000FE`)
justo con el HUD apareciendo. El arreglo de raíz es impedir esa rama (upstream: por qué el port
despacha el evento `0x39` y el emulador no), o resolver el livelock.

**Instrumentación clave** (todas opt-in): `[NODEWATCH]`/`[BCORRUPT]`, `[B280CALL]`, `[SPCHK]`
(balance de `sp`), `HH_M55SPFIX` (`[M55SPFIX]`/`[DISP-SPFIX]`), `[DISP]` (callbacks del dispatcher),
`HH_DRWATCH`, `HH_TRACE_EXEC` (emulador). Bats: `port/run_node_drwatch.bat`.

> **ACTUALIZACIÓN (noche-5, tarde) — causa raíz REAL: extracción incompleta.** La "fuga de pila" es
> un **síntoma** de que el port resuelve `0x80379410` al **fichero 56** (exploración) cuando debería
> ser el **fichero 57** (combate): la extracción inicial solo tomaba **11 módulos** de los **625** de
> la tabla Nisitenma y **omitió el índice 56 = fichero 57**, que se carga con el **loader streamed
> `FUN_80004838`** (no por `file_load`). Ver **§12**. Con el fichero 57 recompilado y registrado al
> cargarse, la fuga **desaparece sin `HH_M55SPFIX`** (pendiente de validar en Windows).

## 1. Mecanismo real de `FUN_80000934` (estático, corregido)

`FUN_80000934(obj, a1, a2)` (funcs_0.c:964):

1. `__osSetGlobalIntMask`-like: `FUN_800267F0(1)` (funcs_10.c:1263) — NO es un allocator: lee
   `cop0 Status` y el registro de máscara `0xA430000C` (MI) y devuelve la máscara anterior.
2. Con el **`a1` del llamante** (no el retorno): `[a1+4] = a2` (mq), `[a1+0] = [obj+0x888]` (next),
   `[obj+0x888] = a1` (nueva cabeza).
3. Restaura la máscara.

⇒ El **nodo lo aporta el llamante** (`a1`), típicamente en su **pila**. `FUN_80000984` hace el pop
(simétrico). El wrapper de diagnóstico del port (`[PUSH]`, `node = ctx->r5`, `q = ctx->r6`) es
correcto; la hipótesis de la nota §15 (“nodo de `FUN_800267F0(1)`”) era **incorrecta**.

## 2. Origen del nodo corrupto `0x8005BF14`

En el árbol recompilado, el **único** sitio que empuja `node=sp+0x34` con `q=0x8005C288` es
`FUN_800011b0` (bucle principal, funcs_0.c:2593), en `0x800012C8`:

```
0x800012B4: sw zero, 0x7730 (0x80037730)
0x800012CC: addiu a1, sp, 0x34        ; node = sp+0x34
0x800012C8: jal 0x80000934            ; obj=a0=0x8005C4B0, q=a2=0x8005C288
```

Después entra en el bucle infinito `L_800013B0` que recibe en la cola `0x8005C288`
(`FUN_800266B0`) usando el buffer `sp+0x30` (adyacente al nodo). **`FUN_800011b0` nunca retorna**
(todos los caminos vuelven a `L_800013B0`), así que el nodo debería ser persistente.

Otros empujes de nodos de pila (todos del hilo 5/19, con pop o no):
- `FUN_8001fba8` (tid 19): `node=sp+0x48`, `q=0x80091DA0` (`0x8001FBF4`). Persistente.
- `FUN_80000bf0` (`node=sp+0x50`) y `FUN_80000dc8` (`node=sp+0x48`): push+pop transitorios.

**Confirmado en `work/debug/cac/bizhawk1/consola_off100.log`**: el nodo `0x8005BF14` se empuja
**una sola vez** (línea 5, `q=8005C288`); **no hay ningún `[PUSH] node=8005BF14` posterior**.
⇒ El nodo se **pisa en el sitio**, no se re-empuja mal.

## 3. Forma del pisado (dumps de cuelgue)

Lista de suscriptores de `obj=0x8005C4B0` (`[obj+0x888]`):

```
normal : head=80095FF8 -> 8005BF14 (q=8005C288) -> 0
roto   : head=80095FF8 -> 8005BF14 -> 8005C088(q=BF3851EC) -> 0          (bizhawk1/VI=20526)
roto   : head=80095FF8 -> 8005BF14 -> 8008DA88 -> 802521E0 -> 8025157C -> ... (Sep20/VI≈20948)
```

- En `hh_hang_rdram_5485_0.bin` (VI≈20948) los campos del nodo son
  `next=8008DA88`, `q=80063DF0`. `8008DA88` y la cadena `0x8025xxxx` (paso 0x34) son **otra
  estructura/lista** (datos de módulo), no colas: el broadcast sigue un `next` basura hacia una
  lista ajena de objetos.
- En `hh_hang_rdram_20526_0.bin` (bizhawk1) son `next=8005C088`, `q=8005C084`, valores **del área
  de globals/objeto** (`0x8005C4B0` aparece en la región de pila `0x8005BF30`).
- ⇒ La región de pila del nodo (marco de `FUN_800011b0`) está **reutilizada por otros marcos/funciones**
  (los campos pasan a ser punteros de globals/listas), no un simple float suelto.

## 4. Qué precede a la corrupción (orden real del log)

En `consola_off100.log` (líneas 63171→63419), **justo antes** de que `[BCAST]` vea el nodo roto:

1. `[CHN] 801257DC a0=00000039 a1=80358820` → tarea `0x39` del scheduler (disable).
2. `[SETCB] obj=802497F0 cb=8021B280`, `[SETCB] obj=8024A1C8 cb=FFFF84CD` (**veneno**).
3. `Failed to find function at 0xFF7F84CD ... r5=8008DA88` (el veneno no existe; **`r5=8008DA88`
   es exactamente el `next` que tendrá el nodo**).
4. `[S0FIX] r16 00000000 -> 80037748` **repetido**, y a continuación una cascada de `[BADMQ]` cuyos
   `mq` son **valores de registro** (`00040000`, `C0000830`, `3F3851EC`, `42F00000`, `420C0000`,
   `BB8F06C7`) — no punteros de cola guardados.

⇒ El “campo queue” corrupto proviene de un **registro/base corrupto** (el `s0` del work del bucle
principal), coherente con la corrupción de control de flujo del disable, **no** con una escritura
aislada a `0x8005BF14`.

Dato adicional de los `hh_hang.log`: aparece un contexto con `queue=8005BF30` (¡una dirección
**dentro** de la pila del bucle principal!) y `0x800011B0` en registros de hilo. Refuerza que la
zona de pila de `FUN_800011b0` se está usando como si fuera otra estructura/cola.

## 5. Instrumentación añadida (runtime NMR, sin commitear)

En `librecomp/src/recomp.cpp` (bajo `HH_DEBUG_TOOLS`):

- `hh_nodewatch_set(addr)` + `hh_nodewatch_check()`: mini-canary de los nodos **persistentes**
  (registrados desde `[PUSH]` cuando `obj==0x8005C4B0 && q∈{0x8005C288,0x80091DA0}`). Compara
  `next`/`q` una vez por VI y, al cambiar, escribe `hh_nodewatch.log` con **la ventana de llamadas de
  todos los hilos** (`hh_dump_thread_rings`). Evita el SEGV del watchpoint por acceso (nodo en pila).
- Se llama desde `hh_canary_tick()` (hilo VI), funciona también sin `HH_CANARY`.

En `librecomp/src/overlays.cpp`, wrapper `[BCAST]` (`FUN_80000A0C`):

- Recorre la lista **acotada (64)** y **detecta ciclos / punteros no válidos / `q` no-cola**
  (`hh_q_ok`: `validCount`/`first`/`msgCount`/`msg` coherentes). Vuelca a `hh_bcorrupt.log` el
  **camino completo** (`node`, `next`, `q`, `qok`) + el anillo del hilo. Sustituye el walk sin cota
  que colgaba si aparecía un ciclo.

## 6. Estado de reproducción (importante)

Con el comando de `RETOMAR` (`cac_full` + `HH_REPLAY_MODE=poll` + `HH_CHAINTRACE=1`) la corrupción
del nodo **ya no se reproduce** en el árbol actual: las corridas acaban en un **deadlock plano**
(todos los hilos bloqueados en `osRecvMesg`, ver `hh_slice.log`) **sin `[BADMQ]` ni nodo pisado**.

- La reproducción de `consola_off100.log` (y `hh_hang_rdram_20526_0.bin`) usó el
  **`hh_replay_off100.txt` antiguo** (ronda bizhawk1, modo `vi`). El fichero se **regeneró** el
  2026-09-17 (`replay-mode-vi-vis-negativo` §14) y el actual **no** reproduce.
- Las corridas con el off100 actual (modo `vi` o `poll`) se detienen en `[BCAST] n≈7000-17800` con
  deadlock, sin corrupción.

**Siguiente experimento decisivo**: usar el **watchpoint de HARDWARE de Windows**
(`HH_DRWATCH=0x8005BF14`, ya implementado en `recomp.cpp`) junto con `HH_CHAINTRACE=1` en la pasada
en vivo del mantenedor (donde el freeze es ~100 %): da la **instrucción/RIP exacta** y la pila host
de quien escribe el nodo, sin los problemas del watchpoint por acceso. Alternativa: `HH_CANARY`
sobre `0x8005BF14:8` en la corrida que **sí** corrompa (hace falta un replay fiel reproducible).

## 7. Conclusión de la sesión

- El nodo corrupto es un **local de pila del bucle principal** (`FUN_800011b0`, hilo 5), empujado una
  vez; se **pisa en el sitio** al reutilizarse su región de pila/estado, con valores que apuntan a
  globals/objetos y a otras listas.
- El pisado va **precedido** por la cadena del disable (veneno `0xFF7F84CD`) y `[S0FIX]` repetido: el
  “queue pointer” corrupto arrastra valores de **registro** (`s0`). Hay que confirmar si el veneno es
  desencadenante o coincidente (la nota §13 dice que hay `[BADMQ]` sin veneno).
- Hace falta un **replay/harness fiel que reproduzca** o el `HH_DRWATCH` de Windows para cerrar
  “quién pisa”.

## 8. CAPTURA EN VIVO (Windows, 2026-09-20 13:14) — `run_node_drwatch.bat`

Pasada real del mantenedor con `HH_DRWATCH` + `HH_CHAINTRACE=1`. Artefactos en
`build_win/bin/Release/logs_nodewatch_20260920_131432/`. **Se reproduce y se cierra “quién pisa”.**

- **`hh_drwatch.log`**: solo capturó **escrituras de arranque** (slot 0-3, `old=0 new=3148EE33`
  … `rip=exe+0x828234`), no la corrupción del CaC. El watchpoint de hardware no fue fiable aquí
  (posible pérdida de DR al cambiar el hilo host / ventana de 250 ms). **La respuesta la da el
  `[NODEWATCH]`** (canary por VI), que sí la capturó.

- **`hh_nodewatch.log`**: el nodo `0x8005BF14` empieza a pisarse en **vi=18281** y evoluciona cada
  VI: `next/q` pasan por `8005C4F0/8005C458`, `8005C4B0/80037748`, `0/80037748`, floats
  (`BF800000`, `C2C80000`, `3F3851EC`…), `8005BF48`, `A1A7A1A8`, y finalmente `8008DA88/80063DF0`
  (vi=18292) — exactamente lo visto en los dumps. **El `tid` es 5**, y su anillo repite
  `80026E58 80026F58 80031190 80034AB8 80034C24` (helpers libultra de tiempo/división: `80031190` =
  `osGetTime`).

- **`hh_venom.log` (12 venenos)**: `FUN_800058dc(cb=0xFFFF84CD)`. **Los 12 son del MISMO objeto**
  (`obj=8024A990` en la run del 13:42, cargando partida) y sus `sp` **escalan la pila +0x58**:

  ```
  #1 8005BDD8  #2 8005BE30  #3 8005BE88  #4 8005BEE0  #5 8005BF38  #6 8005BF90
  #7 8005BFE8  #8 8005C040  #9 8005C098  #10 8005C0F0 #11 8005C148 #12 8005C1A0
  ```

  **CORRECCIÓN IMPORTANTE**: el “12” es el **tope del instrumento** (`hh_dump_venom`: `vn >= 12`), no
  el número real de iteraciones. La cadena se **reinvoca en bucle sobre el mismo objeto, escalando la
  pila ~0x58 por iteración** (hasta `sp≈8005C300` en el cuelgue). El **#4 (`sp=0x8005BEE0`) coincide
  con el `sp` de `FUN_800011b0`** ⇒ su marco contiene `node=sp+0x34=0x8005BF14` y lo pisa.

- **`hh_venom.log` → `ring2-last512`** (run 13:42): el **driver** `FUN_80006214`/`FUN_8001f718`
  (+ `M7_FUN_8012c9c0/ce10/b1e4/bfa0`, `M7_FUN_801277b0`) se ejecuta a **`sp` constante dentro de un
  nivel** y la cadena `M10_FUN_8021b280 → M10_FUN_8022c7a4 → … → M55_FUN_80379410 → FUN_800058dc` se
  reinvoca a **`sp+0x58` por nivel**. Es **reinvocación anidada del mismo callback**, no 12 objetos.

- **`hh_chain.log`** (run 13:42): `b1A8`(vi 7895) → `b200`(7897) → `b240` tickeando (7899-7924), con
  `a1=8008DA88`; `[SCHED] a0=0x39` (vi=7924). **La corrupción del nodo arranca en vi=7929** (5 VI
  después). En la run del 13:14 era `b1A8` vi 18248 → `a0=0x39` vi 18276 → corrupción vi 18281.

- **`hh_s0fix.log`**: 12 `[S0FIX] r16 00000000 -> 80037748`. **`hh_badlookup.log`**: fallo de
  `0xFF7F84CD` con `r5=8008DA88` (el valor que acaba de `next` del nodo).

**Conclusión (quién pisa)**: el nodo lo pisa el **propio hilo 5, con los marcos de la cadena del
disable**, que se **reinvoca en bucle sobre el mismo objeto** y **escala la pila ~0x58 por iteración**
hasta solaparse con el marco de `FUN_800011b0` (`sp=0x8005BEE0` ⇒ `node=sp+0x34`). No es una
escritura aislada: es **reutilización/desbordamiento de pila** disparado por la reinvocación de la
cadena. El nodo es **colateral**.

**Siguiente paso**: medir la reinvocación **sin tope** (`vn >= 12` → 64) y con un contador por objeto
(`[B280CALL]`/`[SETCB] count=N`), y localizar **quién vuelve a llamar al callback del objeto** en el
driver `FUN_80006214`/`FUN_8001f718` + `M7_FUN_801277b0`/`M7_FUN_8012c9c0…`. Objetivo: **cortar el
bucle de reinvocación**; el nodo se arregla solo.

**Implementado (noche-5, pendiente de pasada Windows)**: tope de `hh_dump_venom` a 64 y wrapper de
`M10_FUN_8021b280` con `depth` (thread_local) + `objcount` por objeto en **`hh_b280call.log`**
(`[B280CALL] n=… vi=… depth=… obj=… sp=… ra=… objcount=…`). Si `depth` crece → recursión real; si
`depth=1` siempre pero `sp` sube → **fuga de pila** (una función no restaura `sp`). Repetir
`run_node_drwatch.bat` (recompilar con `build_windows.local.bat`).

## 9. Nota sobre el `HH_DRWATCH` (por qué no valió)

- `hh_drwatch.log` solo registró 16 escrituras de **arranque** (`rip=exe+0x828234`, `new=3148EE33…`,
  stack sin inicializar). No capturó la corrupción: el nodo se pisa por **reutilización de pila** (el
  writer es la propia ejecución del hilo 5 al recolocarse `sp`), no por un store identificable a una
  dirección estable. El `[NODEWATCH]` (canary por VI) sí lo capturó y dio el `tid` y la ventana de
  llamadas.
- El `ra` guardado de tid 5 en el cuelgue es **`8005C3A2`** (dirección de pila) ⇒ el retorno también
  se pisó: **smash de pila**, no escritura puntual.

## 10. CAUSA RAIZ de la fuga: `b` al epílogo compartido compilado como llamada

**Evidencia (`hh_spchk.log`, 2026-09-20 14:06)**: la fuga `+0x58` (delta=+88) está en
**`M55_FUN_80379410`** (y su llamante `M10_FUN_8022c7a4`, que la hereda). `depth=1` ⇒ no recursión.

**Mecanismo (desensamblando `work/scratch/module55_be.bin`, base `0x803757E0`)**:

```
0x80379244: addiu sp, sp, -0x58     <- prólogo del CONTENEDOR (M55_FUN_80379244)
...
0x80379400: beqz $at, 0x80379424
0x80379408: sh a2, 0x12(t0)
0x8037940C: lui a1, 0x8038
0x80379410: addiu a1, a1, -0x7b34   <- mid-entry 0x80379410 (sin prólogo)
0x80379414: jal 0x800058dc
0x80379418: lw a0, 0x58(sp)
0x8037941C: b 0x8037948c           <- salto al EPÍLOGO COMPARTIDO
...
0x8037948C: addiu sp, sp, 0x58      <- epílogo compartido
0x80379490: jr ra
```

- El epílogo `0x8037948C` (`sp += 0x58; jr ra`) es **compartido** por varias ramas internas.
- El recompilador emite la rama `b 0x8037948C` (que cruza la frontera de símbolo) como
  **`LOOKUP_FUNC(0x8037948C)` = una LLAMADA**. Con el ticket de 2026-09-16
  (`add_mid_entry 0x8037948C`) se registró como mid-entry para evitar el crash
  `Failed to find function at 0x8037948C`, pero eso convirtió el epílogo en una **función**.
- Cuando `M55_FUN_80379410` se entra **directamente** (callback del objeto: `ra=0`; o `jal 0x80379410`
  desde M10), no ejecuta el prólogo `-0x58`, pero sí el epílogo vía la llamada `+0x58` ⇒ **fuga neta
  de 0x58 por invocación** (una por frame) → a los ~14 frames pisa el marco de `FUN_800011b0` (nodo
  `0x8005BF14`) y el `ra` (smash).
- El fallthrough interno de `M55_FUN_80379244` llama a `M55_FUN_80379410` como **llamada C directa**
  (`M55_FUN_80379410(rdram, ctx);`, no `LOOKUP_FUNC`), así que **no pasa por el wrapper**; ese camino
  sí tenía el prólogo y estaba balanceado.

**Nota histórica**: `notes/2026-09-16-fix-combate-midentry-m55-8037948c.md` documenta el crash que se
arregló (registrando `0x8037948C`) y `notes/2026-09-15-cuelgue-npc-fallthrough-m55-fuga-pila.md` la
misma clase de bug (fuga por fallthrough sin encadenar, entonces `0x48`/frame). Aquí el epílogo
compartido se volvió una llamada.

**Dos hipótesis de arreglo**:
1. **Syms**: fusionar `0x80379410..0x80379498` en una sola función (el `.fixed` de
   `us_module55.syms.fixed.syms.toml` ya lo hace: `M55_FUN_80379410 size=0x88`, eliminando
   80379424/44/64/8c) para que el `b` sea un `goto` interno. **No elimina la fuga del entry directo**
   (sigue sin prólogo), pero elimina la llamada-con-epílogo.
2. **Runtime (mid-entry con marco)**: el fallthrough interno no pasa por el wrapper, así que envolver
   `M55_FUN_80379410` (vía `get_function`) afecta **solo** a las entradas externas (callback/`jal`).
   Un wrapper que haga `sp -= 0x58` antes de la función real reproduce el prólogo ausente en esas
   entradas.

**Punto a verificar con el emulador**: si el `jal 0x80379410` de M10 (`0x8022CAA4`) es real en ROM
(lo es en la reconstrucción), el emulador ejecutaría el mismo `+0x58` y también fugaría; como no se
cuelga, hay que confirmar si el emulador entra por `0x80379244` (con prólogo) o si la reconstrucción
de M55 está desplazada. Traza sugerida: `HB_TRACE_EXEC=0x80379410,0x80379244,0x8037948c`.

### Traza del emulador (2026-09-20, `emu_ref.sh`)

- `HB_TRACE_EXEC=0x80379244,0x80379410` **armados** (índices 0/1) pero **0 impactos en 220 s**
  (`work/debug/emu_m55b`), aunque el **módulo M55 está cargado** (el RDRAM del emu, word-swapped,
  contiene exactamente las mismas instrucciones: `27bdffa8` en `0x80379244`, `24a584cc` en
  `0x80379410`, `27bd0058; 03e00008` en `0x8037948c`). ⇒ **La reconstrucción es fiel** y el emulador
  **no ejecuta** este camino (es específico de la cadena del disable, que el emu no corre).
- Control positivo: `HB_TRACE_EXEC=0x80001454` → 623 impactos en 15 s (el mecanismo y el boot
  funcionan).
- ⇒ El emulador **no puede validar** la convención del mid-entry aquí.

### Arreglo candidato B implementado (testable)

`HH_M55SPFIX=1`: wrapper de `M55_FUN_80379410` (vía `get_function`; el fallthrough interno **no** pasa
por él) que **restaura `sp`** tras la función real (`hh_m55spfix.log`), neutralizando la fuga.
Activado en `port/run_node_drwatch.bat`. Si el CaC progresa, es la vía; si no, escalar a corregir el
upstream (por qué el port entra en la cadena).

### Resultado de la pasada con `HH_M55SPFIX` (2026-09-20 14:58)

- El fix **funcionó localmente**: `hh_m55spfix.log` con **1** restauración (vi=7636) y `hh_spchk.log`
  con **1** sola fuga (`M55_FUN_80379410` delta=+0x58) — frente a las 24 alternantes de antes.
- Pero **la corrupción persiste**: `[NODEWATCH]` sigue pisando `0x8005BF14` desde vi=7645 y el hilo 5
  deriva `sp` **+0x58/frame** hasta `ctx_sp=8005C300` (cuelgue VI=8285). ⇒ **hay una segunda fuga**,
  no en `M55_FUN_80379410`.
- El anillo del hilo 5 en el pisado es el bucle `osGetTime` (`80031190`) + helpers div/cvt
  (`80026E58/F58`, `80034AB8/C24`), llamados desde **`FUN_80001454`** (el frame).

**Instrumentación añadida (pendiente de pasada)**: `[SPCHK]` sobre `FUN_80001454` (ya envuelto) y sus
**llamantes directos** (`FUN_80000ec8/80001060/80001b30/bc0/d5c/800021b4/8000433c/80006790/80006af0/
8001e978/eaa4/80026e58/f58/80029fa0/80032890/80034ab8/c24/80126744/80126944/8012fe50/80133aa0`),
para localizar la segunda fuga en una pasada.

### Resultado 15:29 — segunda fuga localizada

- `hh_spchk.log`: **`FUN_80001454` (el frame) fuga +0x58 en cada llamada** (13 veces seguidas,
  `8005BEE0→…→8005C300`) mientras **sus callees directos instrumentados NO filtran**.
- La causa es un **caller indirecto**: `FUN_80001454` llama a **`FUN_80005270`** (el *dispatcher* de
  callbacks de objeto: `jalr [obj+0x18/0x1C/0x20]`, y antes `FUN_80006214`/`FUN_8001F718`/`FUN_8001F76C`).
  Si el callback es otro **mid-entry del cluster M55** (0x80379424/0x80379444/0x80379464), hereda la
  misma fuga +0x58.
- **Ampliado el fix**: `HH_M55SPFIX` cubre ahora todo el cluster (`80379410/424/444/464`; **no** el
  epílogo `8037948C`, que romperia el camino interno) y se instrumenta el balance de `FUN_80005270`.
- Pendiente: pasada Windows; se espera `hh_spchk.log` con delta=0 y/o el nombre del callback que
  quedaba.

### Resultado 15:39 — tercera fuga (callback del dispatcher)

- `hh_spchk.log`: `FUN_80005270` fuga +0x58 y `FUN_80001454` la hereda (alternando). `M55SPFIX` solo
  arregló `M55_FUN_80379410` (`n=1`). ⇒ El callback que despacha `FUN_80005270` es **otro** mid-entry
  (no del cluster que arreglamos).
- Añadido log `hh_disp.log` (`[DISP]`, gated `HH_M55SPFIX`): lista `[0x80089378+0x18/0x1C/0x20]` para
  identificar el callback exacto. Balance también de `FUN_8001F76C`.
- **Nota**: en M55 hay más mid-entries con el patrón (`M55_FUN_8037907c`, `M55_FUN_8037890c`,
  `M55_FUN_8037948c` tienen `+0x58` sin `-0x58`). La solución general es corregir las **fronteras de
  símbolos** (fusionar los mid-entries en su contenedor) en vez de parchear uno a uno — ver candidato A.

### Resultado 15:45 — el handler del dispatcher

- `hh_disp.log`: el dispatcher despacha `[obj+0x1C]=0x80124C54` (`M7_FUN_80124C54`) sobre
  `head=8024A558`. Pero `M7_FUN_80124C54` es un **stub sin frame** (cae a `M7_FUN_80124c68`, que hace
  `-0x18`/`+0x18`) ⇒ balanceado. El callback que fuga parece ser **otro** (u otro objeto).
- **Fix pragmático**: como `FUN_80005270` debe tener neto `sp=0` (prólogo `-0x40`/epílogo `+0x40`),
  se **restaura `sp` en el dispatcher** (bajo `HH_M55SPFIX`, log `[DISP-SPFIX]` en `hh_m55spfix.log`).
  Esto neutraliza la fuga del handler sea cual sea. Si con esto `FUN_80001454` queda en delta=0 y el
  CaC progresa, es la vía; el arreglo limpio definitivo sería corregir las fronteras (candidato A).

## 11. SOLUCIÓN VALIDADA (2026-09-20 16:01) — fuga de pila resuelta

Pasada Windows (`logs_nodewatch_20260920_155731`, `run_node_drwatch.bat` con `HH_M55SPFIX=1`).

**La fuga de pila (y con ella la corrupción/`[BADMQ]`/deadlock) queda resuelta**:
- `hh_m55spfix.log`: `[DISP-SPFIX]` restaurando `sp` cada frame (vi 7985-7995; `8005BE78→8005BED0`).
- `hh_spchk.log`: `FUN_80001454` **ya no fuga** (desaparece de las fugas de frame); solo aparece la
  fuga *interna* del dispatcher, que el `DISP-SPFIX` neutraliza.
- `hh_nodewatch.log`: el nodo `0x8005BF14` **solo** se registra (vi=32); **no hay `[BCORRUPT]`**.
- Dump del cuelgue (`hh_hang_rdram_30484_0.bin`): lista de suscriptores **sana**
  (`80095FF8 → 8005BF14 (q=8005C288, next=0)`).
- **El juego llega al CaC y aparece el HUD de combate** (captura del mantenedor:
  `Referencias screenshots/Captura de pantalla 2026-09-20 160114.png`: arena, gauge circular, barras
  de salud/stamina apareciendo).

**Mecanismo resuelto (resumen causal)**:
`cadena del disable (scheduler 0x39, veneno 0xFFFF84CD)` →
`M55_FUN_80379410/424/444/464` (mid-entries sin prólogo, epílogo compartido `+0x58`) y
`FUN_80005270` (dispatcher `jalr [obj+0x18/1C/20]`) devuelven `sp +0x58` →
`sp` del hilo 5 trepa `~0x58/frame` → pisa el marco de `FUN_800011b0` →
nodo `0x8005BF14` corrompido → lista de suscriptores basura → `[BADMQ]` → deadlock.
**Fix `HH_M55SPFIX`**: restaurar `sp` en esos wrappers (el fallthrough interno de `M55_FUN_80379244`
no pasa por el wrapper, así que no se rompe).

**Pendiente (nuevo bloqueo)**: el port **sigue instalando el veneno** y ahora sufre un **livelock** de
tid 5 en código M10/M12 del CaC (`M10_FUN_80228298`, `ra=000000FE`, `queue=00000000`,
`ctx_sp=8005BE18` sano), justo con el HUD apareciendo. Próximo análisis:
- ¿el livelock es consecuencia del veneno? Test con `HH_NO_B280=1`/`HH_NO_DISABLE=1` **con** la pila ya
  sana.
- Arreglo de raíz: por qué el port despacha el evento temporizado `0x39` (scheduler `FUN_80004bb0`) y
  el emulador no.

**Arreglo limpio definitivo (candidato A, futuro)**: corregir las **fronteras de símbolos** para que
los mid-entries sean internos a su contenedor (elimina la clase entera de fugas), en vez de restaurar
`sp` en runtime.

## 12. CAUSA RAÍZ REAL (noche-5, tarde): extracción incompleta — falta el fichero 57

Tras revisar el port de referencia (danielgomesvieira2000/hybrid-heaven-recomp, issue 001
"first battle crash") y confirmarlo en nuestra ROM:

- La tabla **Nisitenma-Ichigo** (ROM US `0x39BF0`) tiene **625 entradas**. `tools/setup_module.py`
  extraía solo **11** (lista `MODULES` hardcodeada): índices 7,8,9,10,12,23,24,25,54,55,99.
- **Faltaba el índice 56 = fichero 57 (código de combate)**, `rom=0x69E416`, descomprimido
  `0x343A0` (CRC `0x050812FF`), base `0x80358820`. Verificado: en `0x80379410` tiene exactamente
  `afa50004 30a500ff 14a00010 00001025` (`func_80379410` del fichero 57), que **NO** está en ningún
  bin extraído; `module55_be.bin` ahí tiene la continuación de `func_80379244` (fichero 56).
- El fichero 57 se carga con un **segundo loader** `FUN_80004838(id, dest)` (un trozo por llamada,
  descompresor `0x80003F44`), **no** por `file_load` (`0x8000469C`/`FUN_80003824`). Nuestro port
  solo envolvía `FUN_80003824`, así que **el fichero 57 nunca se registraba** en `func_map`.
- El juego (fichero 11/M10) llama `jal 0x80379410` en el combate (byte `0x8017DD92 == 0`). Sin el 57
  registrado, el port resuelve a `M55_FUN_80379410` (mid-entry del 56, sin prólogo) → `sp +0x58`.

### Fix aplicado
1. `tools/setup_module.py`: añadido el módulo índice 56 (`vram 0x80358820`, `rom_off 0xC000000`,
   `src_rom 0x69E416`, crc `0x050812FF`).
2. Extraído `work/scratch/module56_be.bin` (lzkn64) y generado `config/us_module56.syms.toml`
   (`M56_FUN_80379410` size `0x4C`, función propia). Añadido a `config/us_combined.syms.toml` y a
   `module_sources.inc` (`{0x69E416, 0xC000000}`).
   **OJO**: el `setup_module.py` completo aborta en un `[ERROR] ramas cruzadas` preexistente de
   module55 (se resuelve con `--force`); el 56 se añadió a mano. Pipeline pendiente de arreglar.
3. Recompilado (`tools/recomp.py --config config/game_combined.toml --force`): 136 `funcs_*.c`,
   `M56_FUN_80379410` en `section_12_module56_funcs`.
4. `recomp_syscall_handler` (stub) en `recomp.cpp` porque módulo 56 tiene **datos mal decodificados
   como código** (`syscall`/`mthi`/`break` en `0x80386E80..0x8038xxxx`) — pendiente filtrar esa
   región como datos.
5. **Runtime**: wrapper de `FUN_80004838` en `overlays.cpp` que, al completarse (`r2 != 0`), registra
   el módulo (`load_module_by_source(0x69E416, dst)`). Bat `port/run_fix57.bat` (sin `HH_M55SPFIX`).

### Implicación sobre los parches previos
`HH_M55SPFIX` (restaurar `sp`) era un **parche de síntoma**. Con el fichero 57, `0x80379410` resuelve
a `M56_FUN_80379410` (función con prólogo, balanceada) → la fuga y el livelock podrían desaparecer
sin parche. **Re-evaluar** todos los workarounds (`HH_M55SPFIX`, `HH_NO_B280`, `HH_NO_DISABLE`,
`HH_VI_EVERY`) tras esta corrección.
