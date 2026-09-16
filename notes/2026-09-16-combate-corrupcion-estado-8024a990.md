# 2026-09-16 — Combate CaC: corrupción de estado (objeto 0x8024A990 y colas)

Continuación de `notes/2026-09-16-crash-combate-centinela-ff7f84cd.md`. Con la mitigación (`get_function`
no-op para targets fuera de rango) ya no revienta en `FF7F84CD`, pero el combate **se cuelga** y
aparecen más síntomas de corrupción:

```
[LOOKUP] target fuera de rango FF7F84CD -> no-op (posible centinela)
[BADMQ] osSendMesg mq=00040000 ra=00000000
[BADMQ] osSendMesg mq=C0000830 ra=00000000
[SEGV] code=C0000094  (divide by zero) en exe+0x80C13F (do_send +0x48F)
```

- `hh_state.log`: `polls` se congela a t≈141 (polls 3772→3783) mientras `audio` sigue subiendo →
  el hilo de juego deja de pedir input (estado atascado), no es solo el watchdog.
- `hh_crash.log`: el divide-by-zero está en `do_send` (runtime) llamado desde `FUN_80000774` →
  `FUN_80000a0c` → `osSendMesg`. `hh_check_mq` **solo avisa** y sigue; `do_send` revienta con la mq
  basura. `FUN_80000a0c` recorre la lista `[struct+0x888]` y hace `osSendMesg([nodo+0x4], ...)`; los
  nodos tienen la mq corrupta.

## Objeto 0x8024A990 (state machine de módulo 7)

| Campo | Puerto (cuelgue) | Emulador (`dump_gameplay.bin`) |
|---|---|---|
| +0x18 | 8012E584 | 8012E584 |
| +0x1C | **FFFF84CD** (centinela) | **80135320** (válido) |
| +0x20 | 8012E654 | 8012E654 |
| +0x8C | 00000000 | 00000000 |

El emulador tiene un handler válido en +0x1C; el puerto acaba con el centinela `0xFFFF84CD`
(`M55_FUN_80379410` con `a1=1` → `1-0x7B34`; bit23 = "deshabilitado"). El crash previo fue con el
bit23 perdido (`0xFF7F84CD`).

Watch sobre `+0x8C` (`hh_watch.log`, 74 líneas): al arrancar se pone a 0 (`FUN_8001f160`), y a
t=5.2/89.3 lo escribe a `F0F0F0F8` una rutina de copia (`FUN_80015798`, `a0=80268008`), dato que en el
dump aparece como **dato del juego** (paleta/textura), no relleno del runtime. `M7_FUN_8012e774`
copia `+0x8C` a `+0x1C`.

## Lectura

No es un símbolo ausente: es **corrupción de estado/estructuras** al entrar en combate (callbacks,
luego nodos de lista con mq basura). Hay varios candidatos: una copia con destino indebido
(`FUN_80015798` escribiendo en `0x8024A9xx`), el bit23 perdido del centinela, o la corrupción de
pila/frame ya conocida (el `[S0FIX]` sigue disparando). Requiere una investigación dedicada
(comparar con el emulador en el mismo frame y vigilar las estructuras corruptas).

## Estado

- **Mitigación** (runtime, local `e9a178f`): no-op para targets fuera de rango; evita el crash pero el
  combate se queda atascado.
- Pendiente: localizar la escritura que corrompe `+0x1C`/`+0x8C`/los nodos de mq, o el consumo del
  centinela.
