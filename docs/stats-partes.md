# Subida de stats por nivel de parte (Hybrid Heaven) — referencia

> **MEDIDO** del C recompilado (`func_80376D48`, `file_057`/`funcs_74.c:42045-44396`) y cruzado con
> una captura real (`HH_CANARY`). Fuente de las tablas: ELF, vaddr `0x80388410` (fichero
> `0x1508410`). Ver `notes/2026-09-28-stats-recompute-correccion.md` §6 para el razonamiento.

## Cómo funciona

Al **acabar cada combate**, `func_803840A4` llama a **`func_80376D48`**, que recorre **6 partes**
(independientes). Cada parte tiene **nivel**, **progreso/EXP** y su par de tablas:

> Terminología: el "progreso" es una **barra de EXP por atributo** (como el EXP de un RPG). Se llena
> con `reward × ref / stat` cada combate y, al cruzar el umbral, el atributo sube 1 nivel y gana
> `incremento[nivel]` de stat. Hay 6 barras de EXP independientes (una por atributo).

| Parte | Parte del cuerpo (editor) | Stat asociado | Nivel (byte) | EXP/Progreso (u16) | Tabla incremento | Tabla umbral |
|---|---|---|---|---|---|---|
| 0 | CABEZA | **HP** (`+0x00`/`+0x02`) | `+0x04` | `+0x06` | `80388B06` | `80388A40` |
| 1 | CUERPO | **STAMINA** (`+0x08`) | `+0x0A` | `+0x0C` | `80388C92` | `80388BCC` |
| 2 | BRAZO DERECHO | **OFFENSE** (`+0x40`) | `+0x52` | `+0x4A` | `803884D6` | `80388410` |
| 3 | BRAZO IZQUIERDO | **DEFENSE** (`+0x42`) | `+0x53` | `+0x4C` | `80388662` | `8038859C` |
| 4 | PIERNA DERECHA | **REFLEX** (`+0x46`) | `+0x55` | `+0x50` | `8038897A` | `803888B4` |
| 5 | PIERNA IZQUIERDA | **SPEED** (`+0x44`) | `+0x54` | `+0x4E` | `803887EE` | `80388728` |

> El par `stat ↔ nivel ↔ tablas` está **verificado** en el código (`func_80378D84`/`func_80378E3C`/
> `func_80376D48`). Los nombres de parte del cuerpo son los del editor (validados por el mantenedor
> con el word-swap).

### ¿HP sube con DEFENSE? `[MEDIDO en código / PENDIENTE empírico]`

En `func_80376D48` los bloques están **separados**: el de HP usa nivel `+0x04` y escribe `+0x00/+0x02`;
el de DEFENSE usa `+0x53` y escribe `+0x42`; **no se leen entre sí**. En la captura `HP +5` y `DEFENSE
+24` salieron **juntos** porque subieron **dos sub-niveles a la vez** (`+0x04` 0→1 → `+5`; `+0x53` 0→1
→ `+24`).

**Ojo**: el mantenedor reporta que subir la **DEFENSE del brazo derecho** le subió el **HP**. Puede ser
(a) coincidencia de que en ese combate subieran ambos sub-niveles, o (b) una dependencia real que aún
no vemos (el progreso de cada sub-nivel usa una "recompensa" `*(unit+0x334)` que **no** hemos
resuelto; podría enlazar acciones/partes con varios atributos). **Test decisivo**: en el editor,
ESTADO→NIVEL subir **solo `DEFENSIVO`** (+1), guardar, cargar y mirar STATUS: ¿cambia también HP?

### Dos sistemas que NO hay que confundir (capturas del mantenedor, 2026-09-28)

1. **Niveles de PARTE del cuerpo** (la pantalla STATUS con **OFENSIVO** o **DEFENSIVO** seleccionado):
   HEAD, RIGHT ARM, LEFT ARM, RIGHT LEG, LEFT LEG, BODY. Son **niveles** (no contadores): suben al
   atacar (OFENSIVO, `+0x10+part*2`) y al **GUARDAR** (DEFENSIVO, `+0x1C+part*2`) con esa parte
   `[confirmado por el mantenedor: guardar sube el DEFENSIVO de la parte]`. Alimentan la **potencia de
   combate** (`func_8022DB40` usa los 6 niveles ofensivos, `func_8022F0E0` los defensivos). **No**
   eligen qué atributo global sube. `func_80232A80` incrementa `entidad+0x8E+part*2` (nivel defensivo).
   **HIT COUNT** (`+0x68`) y **DAMAGE COUNT** (`+0x76`) SÍ son **contadores** de uso.
2. **Sub-niveles de atributo** (los muestran la pantalla de **resultado de combate** y `func_80376D48`):
   HP, STAMINA, OFFENSE, DEFENSE, REFLEX, SPEED. Son los que, al subir, aumentan las stats globales.

Captura `155158`: STATUS con HIT COUNT → `LEFT LEG = 6` (contador). Captura `155109`: resultado del
combate → `HP 100→105`, `DEFENSE 50→74`.

**Confirmado con traza `[STATEXP]` + `HH_CANARY` (2026-09-28)**:

- La **"recompensa" de progreso es estática**: la fila aplicada es siempre `0x8023C940` (fila 0 de la
  tabla de partes) y sus valores (`OFF/DEF/SPD/REF/HP/STAM`) son **idénticos en todos los combates**.
  → la parte usada, el reparto de golpes y el nº de hits **no** cambian la recompensa.
- La subida se aplica **al acabar cada combate** (`func_80376D48`, una vez), y sube el sub-nivel cuya
  **suma de progreso** cruza su umbral. Ej.: combate 2 → HP 100→105 y DEFENSE 50→74 (sub-niveles HP y
  DEF 0→1); combate 3 → HP +10, OFFENSE +36, DEFENSE +6; combate 4 → DEFENSE 80→86.
- Por tanto **el "umbral de 6 hits" no es la causa**: cualquier combate terminado aplica la misma
  recompensa; el nº de golpes solo determina cuándo acaba la pelea.
- La hipótesis "la parte usada elige el atributo" queda **refutada** (golpeando solo pierna izq subió
  HP/DEF; golpeando mezclado, lo mismo).

**Los contadores de ESTADO** (OFENSIVO/DEFENSIVO/HIT COUNT/DAMAGE por parte) **no** son niveles de
atributo: son potencia de combate (y probablemente el nº de golpes/combo de cada ataque). La relación
"subir el contador de cabeza → más golpes por cabezazo" es una mecánica **aparte**, de potencia, no de
subida de stats; ver pendiente en `TODO.md`.

### Escalado del enemigo `[MEDIDO en partida, NO concluyente]`

La comunidad dice que la dificultad sube con el **nivel de las partes**. En el código, el "otro"
(`func_8022CAFC`) se compone de los **stats crudos** del jugador (`+0x40/+0x42`) × factores de tabla
(`0x8023C940`) — no de los niveles de parte. Prueba del mantenedor: subió las partes del cuerpo **al
máximo** y **el enemigo seguía cayendo de 1 golpe** → no se observa (al menos de forma dominante) un
escalado por niveles de parte. Queda medir `[COMPOSE]` (vanilla vs OFFENSE=410) para ver con qué
escala exactamente el `B(0x801BC3D8) o50`.

> La "recompensa" de progreso de cada sub-nivel (`func_80376D48`) sale de
> `*(0x801BBBF0+0xB1C)` = `*(0x801BC3D8+0x334)`, que `func_8022CAFC` apunta a una **fila de la tabla
> de partes `0x8023C940`** (offsets `+0`=OFF, `+2`=DEF, `+4`=SPEED, `+6`=REFLEX, `+8`=HP, `+0xA`=STAMINA).
> La fila se elige por `unit+0x36`; **quedó sin resolver** si ese campo depende de la parte/movimiento
> usado (sería lo que hiciera que la parte usada importe), así que **pendiente de verificar**.

### Algoritmo por parte

```
progreso += round( reward_parte * referencia / stat_actual )   # rendimientos decrecientes
mientras (nivel < tope) y (progreso >= umbral[nivel]):
    stat += incremento[nivel]
    nivel += 1
# tope = 0x4F/0x59/0x63 (79/89/99 según dificultad, func_80376D10)
# stat se topa en 0x270F (9999); progreso en 0xFFFF
```

### `ref_i` (la "referencia") `[MEDIDO]`

`func_80376D48` lee `ref_i` de la stat correspondiente del **combatiente compuesto `0x801BC3D8`**
(que `func_8022CAFC` deriva de ti con los campos **cruzados** OFF↔DEF):

| atributo | `ref_i` | valor que le da `func_8022CAFC` |
|---|---|---|
| HP | `+0x00` | tu HP × factor |
| STAMINA | `+0x08` | tu STAMINA + factor |
| OFFENSE | `+0x58` | **tu DEFENSE** × K |
| DEFENSE | `+0x5A` | **tu OFFENSE** × K |
| REFLEX | `+0x5C` | tu REFLEX + factor |
| SPEED | `+0x52` | tu SPEED + factor |

Lecturas medidas: `0x7E8(a3)`, `-0x3C20`, `-0x3BD0`, `-0x3BCE`, `-0x3BCC`, `-0x3BD6`.

**Solo se cruzan OFFENSE↔DEFENSE** (`[MEDIDO]`): `ref_OFFENSE` sale de tu DEFENSE y `ref_DEFENSE` de
tu OFFENSE. **REFLEX y SPEED usan su propia stat** como referencia (`+0x5C`←`+0x46`, `+0x52`←`+0x44`),
no se cruzan entre sí. HP y STAMINA también usan su propio valor.

### Fórmula EXACTA de la EXP por combate (fila 0, id 81) `[MEDIDO]`

`ref_i = min(transformada(stat), tope)` (¡es un **tope**, no un suelo!) y `EXP_i = round(reward_i ×
ref_i / stat_i)`, con `reward_i = {OFF:20, DEF:14, SPD:10, REF:1, HP:1, STAM:2}`:

| atributo | transformada de `ref` | tope (fila+offset) |
|---|---|---|
| OFFENSE | `DEF × 84/100` | `160` (`+0x0C`) |
| DEFENSE | `OFF × 100/100` | `150` (`+0x10`) |
| SPEED | `SPD − 15` | `280` (`+0x18`) |
| REFLEX | `REF` | `120` (`+0x14`) |
| HP | `HP × 120/100` | `300` (`+0x1C`) |
| STAMINA | `STAM` | `200` (`+0x20`) |

Esto permite **simular combates** exactos: `EXP_i += round(reward_i × ref_i / stat_i)` y luego el
bucle de subida. Verificado: vanilla (OFF=DEF=50) → `EXP_DEF=14`; con OFF=410 → `ref_DEF` tope 150 →
`EXP_DEF=14×150/50=42` (idéntico al log).

> La tabla de **umbrales por nivel** está en **`docs/stats-partes-umbrales.md`** (tabla por nivel
> 0→1 … 98→99, con EXP acumulada, EXP incremental y stat ganado por nivel). No se mete en el editor
> (demasiada información para la UI); queda como referencia para un futuro panel de progreso.

### Ejemplo medido: EXP/combate en una partida vanilla base

Con HP=100, STAMINA=100, OFF=DEF=50, SPEED=REFLEX=100 y sub-niveles 0 (de la traza `HH_CANARY`):
`EXP/combate = { HP:1, STAMINA:2, OFFENSE:17, DEFENSE:14, REFLEX:1, SPEED:9 }`.
Umbrales a nivel 0: `{2, 11, 51, 24, 5, 108}` ⇒ combates para subir: `{2, 6, 3, **2**, 5, 12}`.
**Por eso DEFENSE (y HP) suben primero**: `EXP_DEF = reward_DEF(14) × ref_DEF(50)/DEFENSE(50) = 14`,
que cruza el umbral 24 al 2º combate.

`reward_parte` = u16 de `*(0x801BBBF0+0xB1C)` en el offset de la tabla de abajo. `[MEDIDO con traza]`:
`*(0x801BBBF0+0xB1C)` es **siempre la fila 0 de `0x8023C940`** (`row=8023C940`) y sus valores son
**constantes** entre combates → la recompensa NO depende de la parte usada ni del nº de golpes.
`referencia` = valor de referencia por atributo (probablemente la stat correspondiente del rival
compuesto, `0x801BC3D8`; `[INFERIDO]`).

**El divisor es la propia stat** → **rendimientos decrecientes fuertes**: cuanto más alta, menos
progreso por combate.

> **Confirmado en partida (mantenedor, 2026-09-28)**: con `OFFENSE=410` puesto a mano en ATRIBUTOS,
> el **OFFENSE dejó de subir** (su ganancia `≈ 1/stat` se hace ~0) mientras el resto seguía subiendo
> (p.ej. DEFENSE 50→80 en el primer combate). Es decir: **inflar una stat a mano frena su propia
> subida natural**.

| Parte | `reward` offset (`*(+0xB1C)`) | `referencia` (`0x801BC3D8+`) | divisor |
|---|---|---|---|
| 0 HP | `+0x08` | `+0x00` (HP) | HP `+0x00` |
| 1 STAMINA | `+0x0A` | `+0x08` (STAMINA) | STAMINA `+0x08` |
| 2 OFFENSE | `+0x00` | `+0x40` (`[INFERIDO]`) | OFFENSE `+0x40` |
| 3 DEFENSE | `+0x02` | `+0x42` (`[INFERIDO]`) | DEFENSE `+0x42` |
| 4 REFLEX | `+0x06` | `+0x46` (`[INFERIDO]`) | REFLEX `+0x46` |
| 5 SPEED | `+0x04` | `+0x44` (`[INFERIDO]`) | SPEED `+0x44` |

El **resultado es el mismo mecanismo para las 6**: STAMINA/REFLEX/SPEED suben por su nivel de parte
con su tabla (`2,2,2…` / `4,1,1…` / `10,5,5…`), igual que HP/OFFENSE/DEFENSE. La única "penalización"
conocida es la de **DEFENSE** (su valor entra en la OFFENSE del rival, ver abajo); SPEED/REFLEX/
STAMINA no alimentan al enemigo.

Cada **+1 de nivel** de una parte suma `incremento[nivel]` a su stat (y HP también a HP máx).
La dirección es: **sube la parte → sube su stat → (como consecuencia) sube el NIVEL GLOBAL**.

### Nivel global

```
nivel_global = round( (nivel[0]+nivel[1]+nivel[2]+nivel[3]+nivel[4]+nivel[5] + 6) / 6 )
```
(`func_8037865C`, guarda en `+0x48` solo si es mayor). Es decir, **media de las 6 partes + 1**,
redondeada. Sube de 1 en 1 cuando la **suma** cruza el umbral; **no** es 1:1 por parte (hacen falta
~6 puntos de suma por cada +1). No alimenta ninguna stat.

### Penalización de DEFENSE (observación de la comunidad)

`[MEDIDO en código; identidad "enemigo" INFERIDA]` En `func_8022CAFC` (`funcs_60.c:36306`) se
compone un combatiente con los campos **cruzados**:

```
OFFENSE_ente = DEFENSE_jugador(+0x42) × u8(tabla_partes[+0x0E]) / 100
DEFENSE_ente = OFFENSE_jugador(+0x40) × u8(tabla_partes[+0x12]) / 100
```
La tabla de partes es `0x8023C940` (stride `0xA0`). Si ese ente es el rival, subir DEFENSE sube la
OFFENSE enemiga (dificultad dinámica). La fórmula de daño `func_80230DD4` es una **resta**
`max(0, Of − Def)·modificadores`, no una razón; queda por confirmar con oráculo la identidad del
ente y la cuantía de los coeficientes.

## Tablas completas (niveles 1..99)

### HP
- incremento: 5,10,10,15,15,15,20,20,20,20,25,25,25,25,25,30,30,30,30,30,35,35,35,35,35,40,40,40,40,40,45,45,45,45,45,50,50,50,50,50,55,55,55,55,55,60,60,60,60,60,65,65,65,65,65,70,70,70,70,70,75,75,75,75,75,80,80,80,80,80,85,85,85,85,85,90,90,90,90,90,95,95,95,95,95,100,100,100,100,100,105,105,105,105,105,110,110,110,110
- umbral: 2,3,5,6,8,10,12,14,16,19,21,24,28,31,35,39,44,49,54,60,67,74,81,90,99,109,120,132,144,159,174,191,209,229,250,274,300,328,358,391,428,467,510,557,609,664,725,792,864,943,1029,1122,1224,1336,1457,1589,1733,1890,2061,2248,2451,2673,2915,3178,3465,3778,4119,4491,4896,5338,5820,6344,6916,7540,8220,8961,9768,10648,11608,12653,13793,15036,16390,17866,19475,21229,23141,25224,27496,29971,32670,35611,38817,42312,46121,50273,54798,59731,65108

### STAMINA
- incremento: 2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8,10,10,10,10,10,10,10,10,10,10,12,12,12,12,12,12,12,12,12,12,14,14,14,14,14,14,14,14,14,14,16,16,16,16,16,16,16,16,16,16,18,18,18,18,18,18,18,18,18,18,20,20,20,20,20,20,20,20,20,20
- umbral: 11,17,23,30,38,46,54,63,73,83,95,107,119,133,148,163,180,198,217,237,259,283,308,335,363,394,427,462,500,540,583,629,678,731,788,848,913,982,1056,1135,1220,1311,1408,1512,1623,1742,1869,2005,2151,2306,2473,2652,2842,3047,3265,3499,3749,4017,4304,4610,4938,5289,5665,6066,6496,6956,7449,7975,8539,9142,9787,10477,11216,12006,12852,13757,14725,15762,16870,18056,19326,20684,22137,23692,25355,27136,29040,31078,33259,35593,38089,40761,43620,46678,49951,53453,57200,61209,65499

### OFFENSE
- incremento: 36,8,8,6,7,6,6,5,6,6,5,6,5,5,6,5,6,5,6,5,6,6,6,6,6,6,6,6,7,6,7,6,7,7,7,7,8,7,8,8,8,8,8,9,9,9,9,9,9,10,10,10,11,10,11,11,12,11,12,12,13,1,1,1,2,2,3,5,5,6,7,9,11,12,14,17,19,22,25,29,33,37,42,48,54,61,68,76,87,96,108,121,135,151,169,188,209,233,260
- umbral: 51,79,108,139,171,204,240,277,316,357,400,445,492,542,594,649,706,767,830,897,966,1040,1117,1198,1283,1372,1466,1564,1668,1776,1890,2010,2135,2267,2405,2551,2704,2864,3032,3209,3394,3589,3794,4008,4234,4471,4719,4981,5255,5542,5845,6162,6495,6845,7212,7598,8003,8428,8875,9344,9836,10353,10896,11466,12064,12692,13352,14045,14772,15536,16338,17180,18064,18992,19967,20990,22065,23193,24378,25622,26928,28300,29740,31252,32839,34506,36257,38095,40025,42051,44179,46413,48758,51221,53808,56523,59374,62368,65512

### DEFENSE
- incremento: 24,6,6,4,5,4,4,5,4,4,4,4,4,4,4,4,5,4,4,5,4,5,4,5,5,5,5,5,5,6,5,6,6,6,6,6,6,7,7,6,8,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,12,12,12,13,13,13,14,14,15,1,1,2,2,4,5,6,8,10,11,15,17,20,25,28,33,39,46,52,61,70,80,93,106,122,139,159,181,207,235,268,304
- umbral: 24,37,51,65,81,97,115,133,153,174,196,219,244,270,298,327,359,392,427,464,503,545,589,636,686,739,795,854,917,984,1054,1129,1209,1293,1382,1476,1576,1683,1795,1915,2041,2175,2317,2468,2627,2797,2976,3166,3368,3582,3808,4048,4303,4572,4858,5161,5483,5823,6184,6567,6973,7403,7858,8341,8853,9396,9972,10582,11228,11913,12640,13410,14226,15091,16008,16980,18011,19103,20261,21488,22789,24168,25629,27179,28821,30562,32407,34363,36436,38634,40964,43433,46051,48826,51767,54884,58189,61692,65405

### REFLEX
- incremento: 4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,2,1,2,2,1,2,2,2,2,2,2,3,2,2,3,3,2,3,3,3,3,3,4,3,4,4,4,4,4,5,4,5,5,5,6,5,6,6,6,7,7,7,7,7,8,9,8,9,9,10,10,10,11,11,11,12,13,13,13,14,15,15,16,16,17,18,18,19
- umbral: 5,8,11,14,17,21,25,30,34,40,45,51,58,65,72,80,89,99,109,120,132,145,159,174,190,208,227,247,270,294,319,347,378,410,445,483,524,569,617,668,724,784,850,920,996,1078,1167,1262,1366,1477,1598,1728,1869,2020,2184,2362,2553,2760,2983,3224,3484,3765,4069,4396,4751,5133,5546,5992,6474,6994,7556,8163,8818,9526,10291,11116,12008,12971,14011,15134,16347,17657,19072,20601,22251,24033,25959,28038,30283,32708,35327,38156,41210,44510,48073,51921,56077,60566,65413

### SPEED
- incremento: 10,5,5,6,6,6,6,7,7,7,7,8,8,8,9,9,9,10,10,11,11,11,12,12,13,13,14,15,15,15,17,16,18,18,19,20,20,22,22,23,24,25,26,27,28,29,31,31,33,34,36,37,38,40,42,43,45,47,49,50,53,54,57,60,61,64,67,69,72,75,78,81,84,88,91,94,99,102,107,111,115,120,125,129,135,141,145,152,158,164,171,177,185,192,199,208,216,224,234
- umbral: 108,165,225,287,351,418,487,560,635,713,795,880,968,1059,1155,1254,1357,1464,1575,1691,1812,1937,2067,2203,2344,2491,2643,2802,2967,3138,3317,3502,3695,3896,4105,4322,4548,4783,5027,5281,5545,5820,6105,6402,6711,7033,7367,7715,8076,8452,8843,9250,9673,10112,10570,11045,11540,12055,12590,13146,13725,14327,14953,15604,16281,16985,17717,18479,19271,20095,20951,21842,22769,23733,24735,25777,26861,27988,29161,30380,31648,32967,34339,35765,37249,38792,40396,42065,43800,45605,47482,49435,51465,53576,55772,58056,60431,62901,65470
