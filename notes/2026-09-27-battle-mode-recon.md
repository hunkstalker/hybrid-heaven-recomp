# 2026-09-27 — `MODO COMBATE` (BATTLE MODE): reconocimiento nativo y reproducción del SEGV

> Sesión `menu-nativo`. Objetivo del mantenedor: reconocer la secuencia NATIVA de BATTLE MODE,
> intentar reproducir/acotar el SEGV `FUN_80026f58` (aparcado 2026-09-16) y decidir cómo exponerlo en
> el overlay (confirmar diseño antes de dibujar UI). Detalle de código **medido** sobre el C
> recompilado (`build/recomp/RecompiledFuncs/`, no se versiona) y prueba **headless** Linux.

## 1. Resumen

- La entrada `MODO COMBATE` del overlay está **deshabilitada** (`src/subsystems/menu.cpp:255`) y el
  nativo la tiene como `sel=2` de `func_801C1DB8` (`0x801CC8C4`). Confirmado.
- **Todo el menú de título** (raíz **y** el submenú BATTLE MODE) vive en **`file_024`**
  (base `0x801BF1A0`, size `0x10B50`; `recomp_overlays.inl:16150`). `docs/menu.md` /
  `notes/2026-09-23-a2-plan-…` lo llamaban "módulo 23" (numeración legacy); el id Nisitenma real es
  **24**. Las etiquetas están en `funcs_68.c` y el data en `file_024_data.data.s`.
- El submenú `CREATURE BATTLE` y `DATA EDIT` cargan escenas/setups propios; `VS MODE` pasa por un
  stub inmediato. **DEMO SELECT** (0x801CF674) está en **`file_025`**, no en el submenú de batalla.
- **El SEGV NO se reprodujo** en la build Linux actual por ninguna de las tres ramas
  (VS MODE / CREATURE BATTLE / DATA EDIT), con el harness headless (detalle §4). Hipótesis: ya no
  existe (arreglado por el trabajo posterior de símbolos/pipeline, p. ej. mid-entries) o requiere un
  escenario que el harness no monta (2.º mando / Windows). Pendiente confirmar en Windows.

## 2. Mapa de la secuencia nativa (medido)

Handler raíz del título = `func_801C1DB8` (`funcs_68.c:17240`). Lee `sel` @ **`0x801CC8C4`**
(`0x801D0000-0x373C`), lo mueve con `func_801C1340` (direcciones: UP `0x800` / DOWN `0x400`, decrece
0→4 / incrementa 4→0) y al pulsar A/START (`func_801C1334` & `0xB000`) salta por el switch
(`jr_addend` tabla `0x801CF264`), 6 casos:

| `sel` | rama | destino (callback `func_800058DC`) | significado |
|---|---|---|---|
| 0 | `L_801C1F10` | `0x801C3940` → `0x801C3A40` | NEW GAME / GAME START (ya cableado en el overlay) |
| 1 | `L_801C1F30` | `0x801C3CDC` | CONTINUE (ya cableado) |
| **2** | `L_801C1F58` | **`0x801C40F8`** | **BATTLE MODE (setup)** |
| 3 | `L_801C1F70` | `0x801C4960` | SOUND (reemplazado por CONFIGURACIÓN en el overlay) |
| 4 | `L_801C1F88` | `0x801C5108` (si `0x80037754 & 1`) | RESOLUTION |
| — | `L_801C1FB4` | `0x801C2050` | attract / demos (idle `obj+0x3C` a 0) |

### BATTLE MODE

- **Setup** `func_801C40F8` (`funcs_68.c:18807`): resetea el cursor de batalla **`0x801CC8C8`**
  (`0x801D0000-0x3738`), compone título + 4 entradas vía `0x8001B204` y fija callback
  **`0x801C4200`**. Etiquetas (`file_024_data.data.s`):

  | addr | texto | cursor |
  |---|---|---|
  | `0x801CEDA4` | cabecera (gaiji `A1FC20…`) | — |
  | `0x801CEDB8` | ` VS MODE        ` | 0 |
  | `0x801CEDCC` | ` CREATURE BATTLE` | 1 |
  | `0x801CEDE0` | ` DATA EDIT      ` | 2 |
  | `0x801CEDF4` | ` EXIT           ` | 3 |

- **Update** `func_801C4200` (`funcs_68.c:22055`): mueve `0x801CC8C8` (0..3) y con A/START:
  - cursor 0 = **VS MODE** → `func_800023A8(0)` + `func_80020718(0xA)` + `func_8012FE50(0x14,0xBE,1,1,0)`
    + callback **`0x801C43B0`** (stub: solo guarda args y `jr $ra`). Probable 2P versus (carga
    asset/datos 262/303) pero **sin lógica propia** en este build.
  - cursor 1 = **CREATURE BATTLE** → callback **`0x801C43BC`**: resetea `0x801CC8C8`, compone
    `%mCREATURE BATTLE` + opciones y fija update **`0x801C44C4`** (2 opciones; A →
    `func_80152CF8(cursor)` + callback `0x801C45C8` → `0x801C4640` → **`0x801C4674`** (setup de escena;
    espera `func_801403F8()==1`). Strings: `0x801CEE44 " 5 MATCHES"`, `0x801CEE50 " SURVIVAL "`.
  - cursor 2 = **DATA EDIT** → callback **`0x801C47D0`**: libera objetos, `func_80005670` +
    callback **`0x801C4840`** → `0x801C48A4` → `0x801C3934`.
  - cursor 3 = **EXIT** → callback **`0x801C56B8`** (`funcs_68.c:20597`): recompone las etiquetas del
    **título** (set C `0x801CF110`, + variante si `0x80037754==1`) y fija callback de vuelta a
    **`0x801C1DB8`**.

- **DEMO SELECT** (`0x801CF674`, `%mDEMO SELECT`) lo compone `func_801CAA68` en **`file_025`**
  (`recomp_overlays.inl:16151`); es del flujo de attract/demos, no de este submenú.

## 3. Interacción con el overlay (para el diseño)

- `hh_title_menu_hook` (`src/hooks/sections.cpp:783`) **solo envuelve `func_801C1DB8`**. Al entrar en
  BATTLE MODE el callback pasa a `0x801C40F8`/`0x801C4200` y **el hook deja de correr** → la
  navegación nativa (con `HH_OVERLAY=0` o tras un disparo puntual) manda, y el overlay deja de
  publicar (se oculta por timeout de `g_publish_counter`).
- La supresión de texto nativo (`src/hooks/menu_overlay.cpp:42`) cubre **solo** las tablas de la raíz
  (`0x801CEBB4`/`0x801CEC6C`/`0x801CF110`) + flecha. Las etiquetas del submenú BATTLE
  (`0x801CEDxx`…) **no** están suprimidas → **la UI nativa se vería** (hand-off limpio).
- `EXIT` re-registra la raíz (`0x801C56B8`) → el hook vuelve a correr y el overlay se republica solo.

## 4. Intento de reproducción del SEGV (headless)

Receta (harness Linux; Xvfb + lavapipe):

```sh
cd build/linux
DISPLAY=:99 SDL_VIDEODRIVER=x11 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.x86_64.json \
  SDL_AUDIODRIVER=dummy HH_OVERLAY=0 HH_MENU_TRACE=1 \
  HH_REPLAY=<replay> HH_REPLAY_MODE=vi HH_REPLAY_SYNC=vi timeout 85 "./Hybrid Heaven Recomp"
```

El replay (formato `<t> <vis> <btn> <x> <y>`, guardado en `work/debug/hh_replay_battle.txt`, no
versionado) replica el camino real:

1. `START` (~vis 2160) → menú de título (`func_801C1DB8`).
2. stick **abajo** (`y=-1`) ×2 → `sel=2` (BATTLE MODE). **Ojo**: la navegación nativa usa el
   **stick** (`func_801C1340` lee direcciones decodificadas); inyectar el **bit** D-pad `0x400` en el
   replay **no** mueve el cursor. El replay debe poner `y=-1.0` (un pulso por movimiento; el juego
   no repite).
3. `A` (`0x8000`) → `goto 801C40F8` → `goto 801C4200`.
4. `A` (o abajo + `A`) para cada rama.

Resultado **medido** (`hh.log`, `[menu] goto`):

- VS MODE: `801C40F8 → 801C4200 → 801C43B0`. Sin crash.
- CREATURE BATTLE: `801C43BC → 801C44C4 → 801C45C8 → 801C4640 → 801C4674`. Sin crash (se queda en
  `801C4674` esperando `func_801403F8()==1`).
- DATA EDIT: `801C47D0 → 801C4840 → 801C48A4 → 801C3934`. Sin crash.
- `hh_badlookup.log` / `hh_missing.log` vacíos; salida limpia (`recomp::start returned`).

**No reproducido.** El `FUN_80026f58` del reporte (`funcs_61.c:2107`) es un helper de
multiplicación 64→32 (`(a0*a1)>>32`) llamado por p. ej. `func_801C0B8C` (chequeo de tiempo); el
`ra=0` apunta a un callback invocado sin dirección de retorno válida. No ocurre en las ramas
probadas con la build actual (runtime pin `503957d`).

## 5. Decisión de diseño (pendiente de confirmar)

Dos vías, ambas requieren **acuerdo del mantenedor** (regla `AGENTS.md` / `docs/menu.md`):

- **(a) Disparo puntual / hand-off**: habilitar `MODO COMBATE` y, con A, fijar `sel=2` + inyectar A
  (patrón `CONTINUAR`/`EMPEZAR PARTIDA`, `src/hooks/sections.cpp`). El juego dibuja su submenú nativo
  (no suprimido → visible) y el overlay se retira; al `EXIT` vuelve la raíz y el overlay se
  republica. Mínimo código y **no inventa UI**; pero deja el menú de batalla con el aspecto nativo
  (texto sin localizar).
- **(b) Subpantalla propia**: reproducir `VS MODE / CREATURE BATTLE / DATA EDIT / EXIT` en `hh::menu`
  y despachar cada acción nativa. Da control total y localización, pero es una tarea mayor y las
  pantallas internas siguen siendo nativas → inconsistente salvo que se reimplementen.

## 6. Implementado (2026-09-27, diseño confirmado por el mantenedor)

Decisión del mantenedor: **recrear** los submenús de MODO COMBATE con nuestro menú (para traducir
los rótulos), empezando por **habilitar** la entrada. Primer incremento:

- `src/subsystems/menu.cpp` / `include/hh/menu.h`: `MODO COMBATE` **habilitado** (`make_submenu(…,
  Action::BattleMode)`); pantalla `ScreenId::BattleMode` con `MODO VS` / `LUCHA DE CRIATURAS` /
  `EDITAR DATOS` (`Action::BattleModeVs` / `…Creature` / `…DataEdit`). **Sin `SALIR`**: se sale con
  **B**, que dispara el `EXIT` nativo (cursor 3).
- `kMenuTr`: traducciones en/ca/fr/de de los 3 rótulos nuevos.
- `src/hooks/sections.cpp`: **despacho nativo cableado**:
  - al confirmar `MODO COMBATE` en la raíz se dispara el submenú nativo (`sel=2` + A inyectada) para
    que exista su estado (`func_801C40F8` → callback `func_801C4200`);
  - nuevo `hh_battle_menu_hook` (envuelve `func_801C4200`, registrado en `register_title_menu_hook`):
    la subpantalla la dibuja el overlay; el original corre con input muteado y recibe el **cursor**
    `0x801CC8C8` + **A inyectada** que fija `feed_menu_navigation` (`A` = entrada resaltada, `B` =
    `EXIT` cursor 3). Al cambiar el callback (VS/CREATURE/DATA) el hook deja de correr y la pantalla
    interna la dibuja el juego; al volver a la raíz, `hh_title_menu_hook` **resincroniza** la pila.
  - `menu_overlay.cpp`: se ocultan también las etiquetas/flecha del submenú de batalla
    (`0x801CEDA4..+0x64`, `0x801CEE10`), **no** las internas de CREATURE BATTLE.
- **Verificado headless** (replay `work/debug/hh_replay_battle_full.txt`): raíz → `sel=2` →
  `801C40F8` → `801C4200` → `dispatch cursor=1` → `801C43BC` → `801C44C4` (CREATURE BATTLE nativo) →
  `B` → `801C56B8` → `801C1DB8` (raíz), con `[menu-nav] depth` coherente y **sin SEGV**. El test
  headless aborta **al cerrar** por `vkDestroyDescriptorPool: Invalid device` (teardown Vulkan
  headless, reproducido también sin navegar), ajeno a este cambio.

**Pendiente (siguiente incremento)**:
1. **Recrear las pantallas internas**: `LUCHA DE CRIATURAS` (`func_801C43BC`/`func_801C44C4`, con
   `5 MATCHES` / `SURVIVAL` en `0x801CEE44`/`0x801CEE50`) + `func_801C45C8`/`4640`/`4674`, y
   `EDITAR DATOS` (`func_801C47D0..`). Hooks propios + etiquetas suprimidas + acciones por cursor.
2. Validar en Windows (con/sin 2.º mando) y localizar/reproducir allí el SEGV original.

## 7. Comandos/artefactos

- Reproducción: `work/debug/hh_replay_battle.txt` (gitignored) + receta §4.
- Trazas: `HH_MENU_TRACE=1` (ya registra `[menu] goto pantalla=…` vía `func_800058DC` y `sel` de la
  raíz); no hizo falta instrumentación nueva.
- Mapa de overlays: `build/recomp/RecompiledFuncs/recomp_overlays.inl` (secciones 39/41 = files
  024/025), `include/hh/file_table.h`.
