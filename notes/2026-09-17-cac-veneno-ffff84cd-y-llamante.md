# 2026-09-17 — CaC: veneno `0xFFFF84CD` del objeto 0x8024A990 — escritor y cadena exacta

> Continúa `2026-09-17-cac-ownership-resuelto.md`. Tarea: identificar **quién** escribe el callback
> inválido en el objeto del CaC y **por qué**. Método: diferencial port↔emulador con el **mismo input**
> (replay) + watchpoints en ambos lados. Evidencia en `work/debug/cac/emu_longreplay_*`,
> `work/debug/cac/linux_m7_trace`, `work/debug/cac/linux_gdb_poison`.

## 1. Ground truth del emulador (replay largo completo, 380 s)

Watchpoint del core `work/libmupen64plus-wplog.so` sobre el callback `0x8024A9AC`
(`HH_WPLO=0x24A980 HH_WPHI=0x24A9C0`, direcciones **físicas**; imprime vaddr):

```
wr 0x8024A9AC val=0x80133AC0 pc=0x80005BC0     (setter)
wr 0x8024A9AC val=0x80133B00 pc=0x800058E4     (setter)
wr 0x8024A9AC val=0x80135320 pc=0x800058E4     (setter, = M7_FUN_80135320)
wr 0x8024A9AC val=0x80135320 pc=0x8012E7FC  x8560  (rearm por frame, M7_FUN_8012e774)
```
- **Cero** apariciones de `0xFFFF84CD` (y de `0x8024xxxx`) en 380 s de replay.
- Dump final (`emu_longreplay_end2/emu`): `0x8024A990=0x8024AAF8`, `+0x1C=0x80135320`, sano.
- Nota: `r64dump` consume ~28 muestras/s; el replay largo (8846) se agota hacia ~316-380 s.

## 2. Port: watchpoint nativo del propio runtime

`HH_WATCH_ADDR=0x8024A9AC HH_WATCH_SIZE=4` (replay corto, `linux_m7_trace/hh_watch.log`). Secuencia del
campo (val = valor visto antes del acceso; `ret` = sitio nativo del acceso):

| t (s) | valor escrito | escritor (ret) |
|---|---|---|
| 14.324 | `0x80133AC0` | setter |
| 14.329 | `0x80133B00` | setter |
| 14.363 | `0x80135320` | `M7_FUN_8012e774` (rearm, exe+0x31C90E) |
| 27.286 … 78.565 | `0x8024160C`, `0x80241948`, …, **`0x802425F4`** | `M7_FUN_8012e774` (copia `+0x8C`) |
| **136.241** | **`0xFFFF84CD`** | **`FUN_800058dc`** (exe+0x9F2E5) |
| 136.276+ | `FFFF84CD` ↔ `FF7F84CD` por frame | rearm (máscara bit 23) |

El port **sí** ejecuta módulo 7: `M7_rearm` 61.328 entradas, `M7_stub` (0x80135320) 7.908
(`linux_m7_trace/consola.log`).

## 3. Escritor y cadena exacta (gdb, breakpoint condicional)

`break FUN_800058dc if *(u32*)($rsi+0x28)==0xFFFF84CD` → `linux_gdb_poison/gdb.log`:

```
r4(a0)=8024a990 r5(a1)=ffff84cd r6(a2)=801bc23a r7(a3)=801bbbf0 r29=8005bdd8
#0 FUN_800058dc            (jr $ra; sw $a1,0x1C($a0)  → escribe el callback)
#1 M55_FUN_80379410        (a1 = a1 - 0x7B34; a0 = [sp+0x58]; jal 0x800058DC)
#2 M10_FUN_8022c7ac
#3 M10_FUN_8021b280
#4 FUN_80005270
#5 FUN_80001454
#6 FUN_800011b0            (hilo del juego)
#7 run_thread_function     (runtime)
```

**Aritmética del “veneno”**: `M55_FUN_80379410` hace `a1 = a1 - 0x7B34`. El llamante pasa **`a1 = 1`**:
`1 - 0x7B34 = 0xFFFF84CD`. No es basura aleatoria: es la **codificación de `a1=1` por el trampolín**.

## 4. Gate en el código (M10_FUN_8022c7ac, 0x8022CA90)

```c
t7 = *(u8*)0x8017DD92;                 // flag
if (t7 != 0) goto fin;                 // si flag != 0, NO llama
a1 = 1;
M55_FUN_80379410(a0 = [sp+0x48], a1);  // -> 0xFFFF84CD
```
- El flag `0x8017DD92` vale **0** en el dump final del port **y** en el del emulador.
- En el emulador **no hay ninguna escritura** de `0xFFFF84CD` en 380 s (WP del callback).

## 5. Rearm `M7_FUN_8012e774` (módulo 7, 0x8012E774)

- Camino 1 (objeto activo): `+0x1C = +0x8C`; `+0x20 |= 0x80000000`.
- Camino 2: `+0x1C &= 0xFF7FFFFF`; `+0x20 &= 0xFF7FFFFF` → por eso el ping-pong `FFFF84CD↔FF7F84CD`
  (máscara del bit 23, no del 31).
- El progreso M12 del port (`0x80241948…0x802425F4`) entra por el camino 1 → el campo `+0x8C` del objeto
  avanzó por la state machine del combate en el port.

## 6. Qué hace el runtime con `0xFF7F84CD`

`get_function(0xFF7F84CD)` → `Failed to find function at 0xFF7F84CD` (r4=8024A990 r5=8008DA88 r6=4) y
luego `[LOOKUP] target fuera de rango FF7F84CD -> no-op (posible centinela)`. El runtime **ya** lo
mitiga como centinela: no es ahí donde crashea.

## 7. El cuelgue real

Al final: cascada `[BADMQ]` (p. ej. `mq=420C0000` = bits del float 35.0; 35 apariciones también en el
dump del emulador → patrón de datos normal, no único), objeto con `+0x0=0`, `+0x1C=0xFFFF84CD` (único
en 8 MB), watchdog `[HANG] … VI=9191/10346`.

## 8. Conclusión y siguiente paso (provisional; superado por §9-§10)

- La escritura de `0xFFFF84CD` es **una ruta de diseño** (`a1=1` por el trampolín con `flag==0`), no un
  overflow: el port la ejecuta para el objeto 0x8024A990 a t=136.2; el emulador **no** la ejecuta para
  ese objeto (o no la ejecuta en absoluto) en el mismo input.
- Preguntas abiertas: (a) ¿ejecuta el emulador el gate `0x8022CA90` alguna vez en el replay?; (b) ¿con
  qué objeto / en qué estado de `+0x8C`?; (c) ¿por qué el port itera ese objeto con `flag==0`?
- **Siguiente**: medir el gate en el emulador (`HB_TRACE_EXEC=0x8022CAA4`/`0x80379410` o WP sobre el
  flag `0x17DD92`) y, si no aparece, el problema está aguas arriba (lista/estado del objeto `+0x8C`),
  no en el trampolín.

## 9. Segunda ronda de diferencial: el emulador NUNCA ejecuta el gate ni los callbacks de módulo

`HB_TRACE_EXEC` sobre el **setter** (main-exec, no relocalizable), replay largo completo:
- 11.159 llamadas a `FUN_800058DC` y **ninguna con `a1=0xFFFF84CD`**.
- **Ninguna** con `a1` en rango `0x8021xxxx–0x8024xxxx` (módulos 9/10/12): el emulador **no arma ningún
  objeto con callbacks de esos módulos por `+0x1C`** en toda la partida.
- Objeto `0x8024A990`: sólo `ra=0x80133AF0→0x80133B00` y `ra=0x8013530C→0x80135320` (vi=3751, t≈62,8 s);
  el resto de sus `+0x1C` son rearm directo de `M7_FUN_8012e774` (8560 escrituras).
- Nunca se pasa `0x801C45C8` (callback que el port sí instala desde `0x801C45A0`, el llamante del flag).

Trace de PCs del gate (`HB_TRACE_EXEC=0x8022CAA4,0x80379410,0x8022CA9C`): **0 stops** en 380 s
(inconcluyente por relocación de `.module10`, pero consistente con lo anterior).

**Conclusión**: el port ejecuta state machines de módulo (M12 `0x80241948…0x802425F4` y el gate de
módulo 10) que el emulador **no** ejecuta con el mismo input (al menos no por `+0x1C`). El veneno
`0xFFFF84CD` es el final de una cadena que arranca en esa divergencia de módulo/estado, no la causa
raíz. El flag `0x8017DD92` se escribe en `M7_FUN_80152cf8` (`flag = a0+1`, llamante único `0x801C45A0`
con `a0=[0x801CC8C8]`, dato de blob de módulo — misma zona que `0x801CC8C4`); su valor era 0 en ambos
dumps finales.

**Opción 1 ejecutada**: `HB_TRACE_EXEC=0x800058E4,0x800058EC` (setters `+0x18`/`+0x20`) → **0 stops** en
todo el replay: esas entradas **nunca se ejecutan** en el emulador (no son la vía alternativa). El
emulador no instala callbacks de módulos 9/10/12 en objetos por el setter `FUN_800058DC` ni por sus
entradas vecinas.

**Siguiente (provisional; ver §10, que es la pista buena)**:
1. Comparar el **estado de módulos residentes** (port: `loaded_sections`/HH_DIAG; emulador: dump) en el
   momento del combate, para ver si el port tiene residente/activo un módulo que el emulador no.
2. **Eliminar la ambigüedad de objeto**: conseguir que el emulador juegue el **replay corto desde el
   mismo guardado** (requiere un `.mpk` de mupen con el guardado del port; el `.pak` del port es formato
   propio → o se convierte, o se genera el guardado en el emulador y se lanza el replay corto con
   `HH_KEYS_BASE`). Con eso la comparación es estado-contra-estado y el desvío cae solo.

(La comparación de módulos residentes acabó en §10: **la secuencia de cargas coincide 1:1 hasta la #21**;
el desvío real es la ráfaga de recursos #22 que el port no pide.)

## 10. Tercera ronda: historia de cargas del loader — primera divergencia real

Traza del loader `FUN_80003824` (ra fijo `0x80004778`; args a0=src ROM, a1=dst, a2=size, a3=fin):
port con `HH_TBLTRACE=1` (`[LD384]`) y emulador con `HB_TRACE_EXEC=0x80003824`, **ambos con el replay
largo**.

- Las **21 primeras cargas coinciden exactamente** (módulo7, módulo54, sección a `0x801BF1A0`/`0x801FA948`,
  y toda la cadena de módulos del combate: `0x80227FF8`, `0x80233C78`, `0x8023D808`, `0x80242EE8`,
  `0x80252E68`, `0x8025D168`). El sistema de módulos del port es fiel hasta ahí.
- **Primera divergencia (índice 22)**:
  - Emulador (`vi=2195, t≈36,60 s`): ráfaga de recursos a `0x8025D168`…`0x8029B5A8` (fuentes
    `0x00B7BAF0`, `0x007F375C`, `0x00B7C55A`, … `0x007554BE`), es decir, carga de la **escena siguiente**.
  - Port: **no pide esa ráfaga**; salta directo a la cadena de módulos `0x0053C77C @0x801BF1A0`
    (0x19078), `0x005557F4 @0x801E4AA0`, `0x0057A3B2 @0x8021B150`, `0x00599670 @0x802408F0`… que en el
    emulador son las cargas **#35–38** (t≈60,1 s).
- Es decir: el port **se salta ~34 s de flujo de escena** (la ráfaga de recursos de t≈36,6 s) y sigue
  en la cadena siguiente. A partir de ahí todo el estado diverge (state machine M12, gate, veneno).
- Coherente con que en el emulador el setter **nunca** ve `0xFFFF84CD` y el port sí (t=136,2).
- Los `SETCB` posteriores confirman: el port arma callbacks M12 sobre `0x8024A990`; el emulador no.

**Siguiente**: identificar qué dispara la carga #22 en el emulador (tabla/estado que procesa el
dispatcher `0x80004778`) y por qué el port no la pide. Es el primer desvío de flujo y probable causa
raíz aguas arriba del veneno. Alternativa de apoyo: save de mupen en el mismo punto (`.mpk`, **no**
savestate) para comparación estado-contra-estado.

## Evidencia

- Emulador: `work/debug/cac/emu_longreplay_wp2/` (WP, 17528 escrituras), `emu_longreplay_end{,2}/`
  (dumps finales), `work/debug/wptest/` (validación del WP).
- Port: `work/debug/cac/linux_m7_trace/` (`consola.log`, `consola_watch.log`, `hh_watch.log`),
  `work/debug/cac/linux_gdb_poison/` (`gdb.log` + dump de RDRAM en el veneno).
- Hangs: `port/HybridHeavenRecomp/build_dbg/hh_hang_*_10346_0.bin`, `hh_hang.log`.
