# 2026-09-16 — Sesión: B en menús + mid-entry CaC `0x8037948C` + corrupción al entrar en combate

Resumen de la sesión para retomar. Estado del build, cambios de runtime y por dónde seguir.

## Lo arreglado

1. **B físico = atrás en menús (VALIDADO por el usuario)**. El perfil `[menu]` solo se activaba con el
   flag de UI in-game `0x802690D0` (pausa/mapa), que no se activa en el título/menú principal; allí
   el B físico salía como **Z** (que confirma). Fix en `port/.../src/game/input.cpp`: se detecta
   también el **front-end** por el directorio de recursos del juego en `0x8008DFC0` (pocas entradas
   antes de GAME START; ~30 en gameplay) y se fija al entrar en gameplay. Override de diagnóstico:
   `HH_PAD_CONTEXT=menu|juego`. Nota: `notes/2026-09-16-fix-menu-b-fisico-atras.md`.

2. **Crash al iniciar CaC: `Failed to find function at 0x8037948C`**. Era el **epílogo compartido**
   de `M55_FUN_80379464` (`addiu sp,sp,0x58; jr ra`), al que saltan tres `b` que el recompilador
   emitía como `LOOKUP_FUNC(0x8037948C)`. Mid-entry (split `0x34→0x28` + `M55_FUN_8037948c` `0xC`),
   `recomp --force` + build OK. Nota: `notes/2026-09-16-fix-combate-midentry-m55-8037948c.md`.

## Lo que bloquea: corrupción de estado al entrar en CaC

Tras arreglar lo anterior, al entrar en combate aparece `Failed to find function at 0xFF7F84CD` y
luego cuelgue por corrupción. Cronología y evidencia:

- El objeto `0x8024A990` (state machine de módulo 7) acaba con `+0x1C=0xFFFF84CD` (centinela;
  el dispatcher `FUN_80005270` se lo salta por el bit 23), pero **el bit 23 se pierde
  (`0xFF7F84CD`)** y el dispatcher intenta llamarlo. El emulador (`work/debug/dump_gameplay.bin`)
  tiene ahí `0x80135320` (válido).
- Watch de `+0x8C` y de la región `+0x18..+0x8C`: la escritura que cambia el valor **no pasa por
  `MEM_*`** (invisible al watchpoint). Causa: `do_send` (runtime) escribe el mensaje **directamente**
  en RDRAM (`TO_PTR(OSMesg, mq->msg)[last] = msg`) y hace `% mq->msgCount`.
- Con la guardia de campos de `OSMesgQueue` en `do_send` se ve la cadena: el juego envía el objeto
  RSP (`msg=0x8005C4B0`) a una **lista de "colas" corrupta** (`FUN_80000774` → `FUN_80000a0c`,
  lista `[struct+0x888]`): los nodos contienen floats (`0x3F3851EC`, `0xC2C80000`), el frame
  (`0x80037748`), etc. → el recorrido se **pasa del final** (terminador pisado). Sin la guardia,
  `do_send` dividía por cero (`msgCount=0`, `code=C0000094`).
- `hh_state.log`: `polls` se congela a t≈141 mientras `audio` sube → hilo de juego atascado.

**Conclusión**: no es un símbolo ausente, es **corrupción de memoria** (wild write que pisa un
terminador/estructura). Detalle: `notes/2026-09-16-crash-combate-centinela-ff7f84cd.md` y
`notes/2026-09-16-combate-corrupcion-estado-8024a990.md`.

## Cambios de runtime (fork, SOLO LOCALES — sin push)

En `port/HybridHeavenRecomp/lib/N64ModernRuntime` (rama `hybrid-heaven`, **después** de `feae2d5`):

- `e9a178f` — `get_function`: no-op para targets fuera de 0x80000000..0x807FFFFF (centinelas/punteros
  corruptos), + diagnóstico del llamante (`host_ret`) y `hh_badlookup.log`.
- `efc5f17` — watchpoint: registra el valor y admite `HH_WATCH_SIZE`; tope del log a 500k.
- `0806e19` — `do_send`: valida puntero y campos de `OSMesgQueue` (`msgCount`/`msg`) → evita la
  división por cero y la escritura salvaje; avisa `[BADMQ] fields ...`.

`port/runtime.lock` sigue en el pin publicado **`feae2d5`**. Por tanto, una build limpia / CI **no**
incluye estas mitigaciones (no rompen la compilación; el bloqueo del combate persiste). Para usarlas
en Windows: `port\build_windows.local.bat` (compila `lib\` tal cual, sin git). **No** usar
`--force-libs` (resetea `lib\` al pin).

## Commits del repo principal (esta sesión)

`fbacef2` (verificación/estado), `f87c2e9` (guardado validado), `28fb9db` (mid-entry `0x8037948C`),
`f39532c` (fix B), y varios `docs(cac)`. Fast-forward sobre `origin/main`.

## Cómo seguir

1. **Validar en Windows** (con `build_windows.local.bat`): el B en menús y el mid-entry `0x8037948C`
   (entrar en combate y aguantar).
2. **Bloqueante**: la corrupción al entrar en CaC. Vías:
   - Comparación con el **emulador en el mismo frame** (alinear por VI, diff RDRAM) para hallar la
     primera divergencia.
   - Cazar el **wild write** con watchpoints sobre la estructura concreta (el `struct` de la lista de
     broadcast es dinámico; hay que identificarlo).
3. Decidir si se publican las mitigaciones de runtime (fork + `runtime.lock`) o se dejan locales.
4. Pendientes varios: teardown SEGV al cerrar, limpieza de instrumentación y botón **X** de los menús
   de combate (`TODO.md`).
