# 2026-09-13 — Cadena de boot y progreso `fe00` (port vs emulador)

> Evidencia de la tarea "rastrear el callback de progreso del módulo 23". Continúa
> `2026-09-13-vi-opcion-a-implementada.md`.

## 1. Resultado: la cadena de callbacks ya no diverge

Con el subsistema VI arreglado (ADR 0003), la secuencia del setter `FUN_800058DC` del port es
**idéntica** a la del emulador:

```
obj=801BF1B0 cb=80107864, 801078A4, 801078E0, 80107968
obj=801BF1B0 cb=803839DC ; obj=801BF264 cb=80383AD4
obj=801CFE20 cb=801243DC ; 80124AF0 ; obj=801CFED4 cb=8010DD4C ; obj=801CFF88 cb=8012798C
obj=801D0744 cb=801C33C8 ; 801D003C cb=80127918 ; 801D00F0 cb=8001B0B0 ; ...
```

El nodo de boot `0x801D03C0` apunta a `0x801D0474` (`+0x1C=0x801BF1CC`), igual en ambos.
`FUN_801BF1CC` es un setter diminuto (`[0x801CFCF4]=a0`) que el dispatcher llama cada frame.
Con ello, el estado del objeto a **port VIS 5400** == **emulador VIS 2700/3600**
(`obj@0x801D0474: 00000000 801D03C0 801D0528 801CFF88 00000000 80000000 00000000 801C184C…`).

## 2. Primera divergencia real: el progreso `fe00`

- Emulador (referencia, sin breakpoints salvo `HB_EXEC` de reanudación): `fe00=0` en VIS 2700/3600
  y **`fe00=0x801E, fe02=30, 1D1E00=8` al final (~90 s)**. Entre VIS 3600 y ~5400 el juego avanza la
  carga y escribe **código/datos en `0x801D03C0`/`0x801CFE20`** (decode/reloc de un módulo).
- Port: `fe00=0` a **VIS 7200 (120 s)** y `0x801D03C0`/`0x801CFE20` **a cero**.
- El port va ~2× más lento en trabajo de juego: el dispatcher `FUN_80005270` corre ~9,5/s en el port
  vs ~36/s en el emulador, porque el gate `[0x8005CD4C]>=2` cierra ~la mitad de los frames (el
  contador descansa en 1-2 en el port y en 0-1 en el emulador). El ritmo de `fe00` depende de estos
  callbacks, no de VIS.

## 3. Loader del emulador (90 s, 34 cargas) — ninguna escribe la divergencia

`FUN_80003824` en el emulador: 11 cargas hasta t=10,5 s (idx7, idx0, idx54, idx23, id114, …) y luego
cargas de assets a `0x8023xxxx-0x8029xxxx` (vi 3817-4595, t=63-77 s) y una desde RDRAM
(`a0=0x59310`). El código que aparece en `0x801D03C0` **no** viene de una llamada directa al loader
en esa ventana → parece un decode anidado (`trans_to_malloc64`) o una copia/reloc del juego.

## 4. Fix aplicado

Split de `FUN_80022a84` (mid-entry real `0x80022B6C`, tras `jr $ra`): ahora
`FUN_80022a84` (0xE8) + `FUN_80022b6c` (0x120) en ambas syms. Con esto, un run de 150 s con
`HH_SOFT_LOOKUP=1` no reporta **ningún** símbolo faltante y el port corre 210 s sin abortar.

## 5. Siguiente

1. **Emparejar el ritmo del gate** (`0x8005CD4C`): entender por qué en el port el contador descansa
   en 1-2 (t17 espera el sync `+0x158` por task) mientras el emulador queda 0-1; si se corrige, el
   port alcanzará el mismo progreso a la misma VIS.
2. **Trazar el evento de progreso** entre VIS 3600-5400 del emulador (qué callback/copia escribe
   `0x801D03C0` y dispara `FUN_801CBE88`) y compararlo con el port en su VIS equivalente
   (~5400-7600).
