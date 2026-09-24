# A2 — Ocultar el menú NATIVO: el juego tiene VARIAS tablas de etiquetas idénticas

> Sesión 2026-09-24 (continuación). Resuelve el bloqueante de `RETOMAR.md` §PROBLEMA ABIERTO
> ("el menú nativo se ve al entrar al título") y el **bug 2** posterior ("al volver atrás de una
> opción reaparece el menú original"). **Validado en headless Linux** (replay + captura); pendiente
> la validación visual del mantenedor en Windows.

## 1. Síntoma

Al entrar al menú de título, el menú nativo (CONTINUE / NEW GAME / BATTLE MODE / SOUND / RESOLUTION)
se veía; F6 lo alternaba (la 1.ª pulsación no hacía nada porque ya estaba visible y la 2.ª lo
ocultaba). Objetivo: nativo **oculto por defecto**, F6 al instante, overlay del port visible.
Más tarde: **al entrar en una opción y volver atrás, el menú nativo reaparecía**.

## 2. Causa raíz (MEDIDA)

El módulo del título (`id=24`, ROM `0x5F1190`, VRAM de enlace `0x801BF1A0`) contiene **varias copias
byte-idénticas** de la tabla de etiquetas del menú raíz, una por ruta de entrada y por función de
"atrás":

| set | base | la compone | cuándo |
|---|---|---|---|
| **A** | `0x801CEBB4` | `func_801C18FC` | update del título, al pulsar START |
| **B** | `0x801CEC6C` | `func_801C1C44` | 2.ª entrada / desde el propio título |
| **C** | `0x801CF110` | `func_801C56B8` | **"atrás" desde un submenú** (bug 2) |

Todas con la misma estructura: `idx0` = flecha de cursor (gaiji `A1FC`), `idx1..5` = entradas de
16 B (` NEW GAME`, ` CONTINUE`, ` BATTLE MODE`, ` SOUND`, ` RESOLUTION`), `idx6` = variante
`%p RESOLUTION`. El handler `func_801C1DB8` re-registra la flecha en `0x801CECFC` cada frame.
`func_801C56B8` es el handler de "atrás" compartido por **todos** los submenús (9 referencias en el
módulo), así que el set C cubre todos los "atrás".

Evidencia (`build/recomp/asm/file_024.s` + volcado LZKN64 del módulo):
- `func_801C18FC` → `a3` en `0x801CEBB4..0x801CEC04` (set A).
- `func_801C1C44` → `a3` en `0x801CEC6C..0x801CECBC` (set B).
- `func_801C56B8` → `a3` en `0x801CF110..0x801CF160` (set C).
- Los tres rangos son idénticos byte a byte.

El filtro (`filter_native_text`, override de `0x8001B204`) solo miraba `[0x801CEBB4, 0x801CEC14)`,
así que los sets B y C **no se blankeaban**. F6 sí ocultaba porque fuerza la recomposición del set A
(con blancos) sobre los mismos slots `0..5` del motor de texto.

## 3. Arreglo

`src/hooks/menu_overlay.cpp` (`hh_menu_overlay`):
- `kNativeLabelAddrs[] = { 0x801CEBB4, 0x801CEC6C, 0x801CF110 }` (sets A/B/C);
  `kNativeArrowAddr = 0x801CECFC`; `kNativeLabelsLen = 7*16` (`idx0..6`).
- `kNativeRanges` (para `suppress_native`: backup/restore) cubre los tres sets + la flecha.
- `filter_native_text` reconoce cualquiera de los tres sets.

Sin cambios en el resto del flujo (override de `0x8001B204`, `suppress_native` en carga y en el
handler, F6 con re-registro forzado).

## 4. Validación (headless Linux, Xvfb + lavapipe)

Replay que **no toca nada hasta ~t=60 s** y luego pulsa START (`0x1000`) cada ~2 s
(`HH_REPLAY=… HH_REPLAY_PACE=1`). Los pulsos tempranos desvían a otra ruta y el headless no llega
al menú (el `hh_replay_title_hold.txt` de la sesión anterior pulsaba demasiado pronto).

- **Antes**: `[native] filter first text=801CECFC` (la flecha; ni B ni C se filtraban).
- **Después**: `[native] filter first text=801CEC6C` (set B) y captura con **solo el overlay del
  port** (CONTINUAR / NUEVA PARTIDA / MODO COMBATE / AJUSTES) y **sin** el 5.º renglón nativo.
- Con la traza de `a3` distintos (`[entry] … (nuevo)`) se ve que la entrada usa el set B
  (`0x801CEC6C`) y el submenú de NUEVA PARTIDA usa `0x801CED10`; el "atrás" (`func_801C56B8`)
  compone el set C (`0x801CF110`), ya cubierto por el filtro.
- **Nota**: en headless no se logró disparar el "atrás" con el replay (el registro de botones del
  submenú no reaccionó a los pulsos de B); el arreglo se sostiene en el desensamblado. Validar en
  Windows.

## 5. Pendiente

- **Validar en Windows** (build release): nativo oculto por defecto, F6 alterna, y **atrás desde un
  submenú** no reexpone el nativo.
- El overlay aún pliega acentos a ASCII y no dibuja valores de selectores (paso 4/6 de `hh_menu`).
