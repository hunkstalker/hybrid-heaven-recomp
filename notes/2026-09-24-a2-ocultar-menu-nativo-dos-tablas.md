# A2 — Ocultar el menú NATIVO: el juego tiene DOS tablas de etiquetas idénticas

> Sesión 2026-09-24 (continuación). Resuelve el bloqueante de `RETOMAR.md` §PROBLEMA ABIERTO:
> "el menú nativo del juego se sigue viendo ~1 s al entrar al título". **Validado en headless
> Linux** (replay + captura); pendiente la validación visual del mantenedor en Windows.

## 1. Síntoma

Al entrar al menú de título, el menú nativo del juego (CONTINUE / NEW GAME / BATTLE MODE / SOUND /
RESOLUTION) se veía; F6 lo alternaba (la 1.ª pulsación no hacía nada porque ya estaba visible y la
2.ª lo ocultaba). Objetivo: nativo **oculto por defecto**, F6 al instante, overlay del port visible.

## 2. Causa raíz (MEDIDA)

El módulo del título (`id=24`, ROM `0x5F1190`, VRAM de enlace `0x801BF1A0`) contiene **dos tablas de
etiquetas byte-idénticas**, una por ruta de entrada al menú:

| set | base | la compone | notas |
|---|---|---|---|
| **A** | `0x801CEBB4` | `func_801C18FC` (update, al pulsar START) | la que cubría el filtro |
| **B** | `0x801CEC6C` | `func_801C1C44` (2.ª entrada / desde el título) | **NO cubierta** |

Ambas con la misma estructura: `idx0` = flecha de cursor (gaiji `A1FC`), `idx1..5` = entradas de
16 B (` NEW GAME`, ` CONTINUE`, ` BATTLE MODE`, ` SOUND`, ` RESOLUTION`), `idx6` = variante
`%p RESOLUTION`. El handler `func_801C1DB8` re-registra la flecha en `0x801CECFC` cada frame.

Evidencia del desensamblado (`build/recomp/asm/file_024.s`):
- `func_801C18FC` → `func_8001B204` con `a3` en `0x801CEBB4..0x801CEC04` (set A).
- `func_801C1C44` → `func_8001B204` con `a3` en `0x801CEC6C..0x801CECBC` (set B).
- Volcado del módulo decodificado (LZKN64): los dos rangos son idénticos byte a byte.

El filtro (`filter_native_text`, override de `0x8001B204`) solo miraba
`[0x801CEBB4, 0x801CEC14)`, así que el **set B no se blankeaba**. F6 sí lo ocultaba porque fuerza la
recomposición del **set A** (con blancos) sobre los mismos slots `0..5` del motor de texto.

## 3. Arreglo

`src/hooks/menu_overlay.cpp` (`hh_menu_overlay`):
- `kNativeLabelAddrA = 0x801CEBB4`, `kNativeLabelAddrB = 0x801CEC6C`, `kNativeArrowAddr = 0x801CECFC`,
  `kNativeLabelsLen = 7*16` (`idx0..6`).
- `kNativeRanges` (para `suppress_native`: backup/restore) cubre los dos sets + la flecha.
- `filter_native_text` reconoce ambos sets.

Sin cambios en el resto del flujo (override de `0x8001B204`, `suppress_native` en carga y en el
handler, F6 con re-registro forzado).

## 4. Validación (headless Linux, Xvfb + lavapipe)

Replay que **no toca nada hasta ~t=60 s** y luego pulsa START (`0x1000`) cada ~2 s
(`HH_REPLAY=… HH_REPLAY_PACE=1`). Los pulsos tempranos desvían a otra ruta y el headless no llega
al menú (el `hh_replay_title_hold.txt` de la sesión anterior pulsaba demasiado pronto).

- **Antes**: `[native] filter first text=801CECFC` (la flecha; el set B nunca se filtraba).
- **Después**: `[native] filter first text=801CEC6C` (set B) y captura `menu_native_off.png` con
  **solo el overlay del port** (CONTINUAR / NUEVA PARTIDA / MODO COMBATE / AJUSTES) y **sin** el
  5.º renglón nativo ni duplicados.

`[entry] 0x8001B204 #300 a3=801CECFC` confirma que la flecha también pasa por el filtro.

## 5. Pendiente

- **Validar en Windows** (build release) que el nativo está oculto por defecto y F6 alterna.
- El overlay aún pliega acentos a ASCII y no dibuja valores de selectores (paso 4/6 de `hh_menu`).
