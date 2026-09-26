# Logos de intro en HD (KONAMI/KCEO) + código Konami durante el logo

> Tarea (2026-09-26), rama `menu-nativo`. **Descripción del mantenedor** + reconocimiento técnico y
> plan. Estado: **en curso** (insumos resueltos; punto de parada: composición de los logos; ver §Plan).
>
> **Esta nota NO documenta instrumentación de análisis**: cualquier utilidad de volcado/decodificación
> es **externa y no se versiona** (`/tmp` o `work/`; regla `AGENTS.md`). Aquí solo va el conocimiento de
> tarea (secuencia, enfoque, diagnóstico de paridad, plan, insumos y reglas).

## Objetivo (lo que pide el mantenedor)

- Mostrar los logos de **KONAMI** y **KCEO** de la intro en **alta definición (4K)**, en lugar de los
  originales, **imitando** la secuencia del juego y el **skip con START**.
- **Fondo BLANCO** mientras se muestran los logos (el original es **negro**), el mismo blanco del logo.
- Aprovechar el momento del **logo KONAMI** para integrar el **código Konami → `EXTRAS`**:
  - al pulsar el **primer `arriba`** de la secuencia suena un **SFX** (lo indicará el mantenedor);
  - el juego **espera ~2 s** a que el jugador siga la secuencia;
  - si se equivoca: **SFX de fallo** y **2 s** para retomar;
  - si el tiempo expira: la introducción **retoma el comportamiento normal**.
- (Idea de fondo) **tomar el control de la secuencia de inicio** facilita tanto los logos HD como el
  código Konami.

## Decisión de enfoque: OVERLAY (recomendado)

No es reemplazo de texturas del juego, sino una **capa propia por encima**, como el menú moderno:

- El requisito de **fondo blanco** (el juego limpia en negro) descarta el simple *texture replacement*:
  habría que cambiar el clear/framebuffer del juego.
- Necesitamos **control de la secuencia** (timing, skip con START) y **capturar input durante el
  logo KONAMI** → es justo lo que da el overlay.
- El *texture-pack* de RT64 existe (`lib/rt64/TEXTURE-PACKS.md`), pero es para **texturas muestreadas
  (RDP/S2DEX)**, no para framebuffers/VI, y **el port no tiene enganche** (solo carga manual desde el
  Inspector en modo dev; `appConfig.useConfigurationFile = false`). **Descartado** para esta tarea;
  útil a futuro como soporte de packs HD general.

## Reconocimiento

### Overlay actual (reutilizable)
- `src/platform/overlay.cpp` ya **sube texturas RGBA8 arbitrarias**: `upload_texture()` +
  `make_texture_set()`; dibuja en **unidades virtuales del juego** y hay una **capa en píxeles de
  ventana** (el indicador de FPS, `set_fps_indicator`) → se puede pintar un **quad blanco full-screen**
  + las imágenes de logo a resolución de ventana.
- Assets: se copian junto al `.exe` por `CMakeLists.txt` (patrón de `assets/lang` y `assets/sounds`).

### Secuencia de arranque (evidencia existente)
- `notes/2026-09-08-overlay-directory.md` **§8.4** (línea de tiempo anotada por el mantenedor):
  - `t=2-5 s`: negro → **logo Konami** → (KCEO se salta por timing del emulador);
  - `t=8-11`: escenas Controller Pak (solo con setup previo);
  - `t=12-41`: negro esperando **Press Start**; `t=42-44`: animación de menú → título.
  - §8.1: `f004 START → Konami logo`, `f005 START → KCEO logo`.
- En la ROM (ASCII) **no hay** "KONAMI"/"KCEO" → los logos son **imágenes/texturas**, no texto.

### Paridad del harness headless (BUG abierto)
En el **harness headless** (Xvfb) el arranque **salta directo al título** (`HYBRID HEAVEN`) sin mostrar
KONAMI/KCEO. **El mantenedor confirma (2026-09-26) que en su build de Windows SÍ salen los logos** y
todo es normal hasta el menú moderno. **El headless debe comportarse como el port de Windows** → es un
**BUG de paridad** a investigar/cerrar (no un "artefacto" que se pueda ignorar).

**Diagnóstico (medido)**: la secuencia de logos la crea `func_801C1624`, invocada por `func_801C1508`
**solo si el flag de arranque `D_801CC8CC == 2`**. En headless el flag hace `00 → 01 → 02` una vez y
**vuelve a `01`**, de modo que `func_801C1508` (que corre 71 frames con `boot=01`) **nunca** crea la
secuencia (`func_801C1624` no se llama). El contador del estado (`obj+0x3C`) avanza bien.

**Causa raíz (medida)** — carrera entre dos callbacks por un tick de más:

- `func_801C33C8` (callback por-hijo): escribe el flag **2** si `func_801C1088(obj+0x30, obj+0x90) != 0`,
  o **1** si devuelve 0.
- `func_801C3410` ("ptick"): llama a `func_801C33C8` y con ello **suele dejar el flag en 1**.
- `func_801C1508` ("bootstate"): crea la secuencia (`func_801C1624`) **solo si lee el flag == 2**.

Orden observado en un frame del port: `ptick → children → bootstate`. El flag está en **2** tras
`ptick`, pero el **siguiente** `bootstate` ya lo lee en **1** porque el `ptick` de ese frame lo bajó
**antes**. Además `ptick` corre **una vez de más** que el resto (84 vs 83), lo que confirma el desfase.

**Evidencia del oráculo (emulador, watchpoint `0x801CC8CC`)**: el emulador escribe el flag en los
mismos PCs (`0x801C33F4`/`0x801C33FC` y `0x801C3458`), VI≈622-646; el juego real **también** alterna
1↔2, pero el orden/timing dentro del frame hace que `bootstate` **sí** lo capture.

**Arreglo (dirección)**: alinear el orden/tick del arranque del port con el emulador. El flag no debe
bajarse antes de que `bootstate` lo consuma. Opciones:
1. **Localizar el tick de más** (por qué `func_801C3410` corre una vez extra) — lo correcto.
2. Si es un desfase de orden de callbacks del boot, corregir el registro/orden en el port.

**Consecuencia**: la escena de logos **existe**; la tarea es **sustituirla** (overlay). El envolver los
handlers (abajo) permite ocultar los sprites y pintar el overlay **sin depender** de este bug; la
captura de framebuffer sí requeriría resolverlo antes.

## Secuencia de logos en código (MEDIDO)

Traza de rango del módulo 23 (Título) al arranque (sin input → KONAMI autoavanza a KCEO a los 2 s por
el timer `obj+0x3C`). Handlers (C recompilado, `funcs_68.c`):

| dir (VRAM) | función | papel |
|---|---|---|
| `0x801C1624` | `func_801C1624` | **crea la secuencia de logos**: 2 sprites (`func_80005670` con `0x801D0C50`/`0x801D0C78`), llama `0x8011AAF4`, `func_801C125C` (fija modo), `func_801C1160` (cambia a pantalla), y setea callback `func_801C1764`. `START`/A/B (`0xB000`) → `func_801C1A30`. |
| `0x801C1764` | `func_801C1764` | **logo KONAMI**: `B000` → `func_801C1A30`; `lbu 0x801D0C8C` (flag 1º-logo) == 0 → `obj+0x3C=0x30` (~2 s) y callback `func_801C17C8`. |
| `0x801C17C8` | `func_801C17C8` | **logo KCEO**: `B000` → `func_801C1A30`; al expirar `obj+0x3C` registra texto y callback `func_801C184C`. |
| `0x801C184C` | `func_801C184C` | **pantalla de espera**: `B000` → registra texto + callback `func_801C27DC` + `obj+0x3C=0x1E`. |
| `0x801C1160` | `func_801C1160` | transición de pantalla (libera `0x80145390`, callback `func_801C258C`). |
| `0x801C125C` | `func_801C125C` | `func_800058DC(obj+0x30, func_801C3410)` + `sb` de un byte (0x90). |
| `0x801C1040/1088/10DC` | helpers | recorren la **lista de hijos** (`obj+0x30` → `+0x10`) y fijan `+0xB` (alpha/valor). |
| `0x801C3410` | `func_801C3410` | por-hijo: `func_801C1088(obj+0x30, obj+0x90)`; si 0 → limpia flags y `func_80005700`. |
| `0x801C1A30` | `func_801C1A30` | **skip**: salta la escena de logos (va a `0x801C258C`, la espera de Press Start). |

### Representación de los logos (MEDIDO)
- El bucle del título llama cada frame: `0x801C1340` (direcciones), `0x801C1334` (A/B/START), el
  handler del estado actual, `func_801C1088` y `func_800058DC`.
- `func_801C1624` crea **2 objetos** vía `func_80005670(obj, D_801CC9F8)` y `(obj, D_801CCA20)`
  (handles en `0x801CC8B4`/`0x801CC8B8`). `D_801CC9F8`/`D_801CCA20` son **descriptores** (5 words);
  el callback real es `func_801C3090` (**KONAMI**) y `func_801C205C` (**KCEO**).
- El **dibujo** del sprite se resuelve con `func_80146208` (y `func_80145348/CC`): indexa una tabla de
  recursos en `0x80171CEC` (módulo 8) → `D_80170F58` = words `0x03001DF0`/`0x03000000`/`0x03002B60`.
  El **prefijo `0x03`** indica un recurso del loader `trans` (LZKN64) → la imagen del logo es un
  **asset empaquetado del juego**, no una textura generada en runtime.
- **El logo NO existe como textura única**: la N64 tenía **4 KB de TMEM**, así que un logo grande no
  cabía: se **compone por muchos fragmentos/tiles** (se observa un patrón tipo "KONAMI" repetido +
  barras). Vía elegida para el asset: **componer** el logo desde los fragmentos (ver §Plan, A1).

### Implicación para la implementación
- **Enfoque elegido**: **ocultar** los sprites nativos (por el `obj`/handles, como con el menú
  nativo) y **pintar nuestro overlay** (blanco + logo 4K) mientras el estado sea
  `func_801C1764`/`func_801C17C8`; **mutear el input nativo** (`g_mute_native_input`) para que `START`
  no dispare el skip nativo `func_801C1A30`, y gestionarlo nosotros.
- **Código Konami**: leer la entrada en nuestros hooks durante esos estados; al pulsar el 1er `↑`,
  **pausar el timer nativo** (`obj+0x3C` a tope, como en `hh_title_menu_hook`); al fallar/expirar,
  restaurarlo y dejar que la intro retome.

## Plan (A–F)

**A. Assets (logos 4K)** — elegir una vía:
- **A1 (elegida por el mantenedor): componer** KONAMI y KCEO desde los fragmentos. Analizar
  `func_801C205C` (KCEO) y `func_801C3090` (KONAMI): cada llamada a `func_80146208` coloca un tile
  (los args `a2`/`a3` y la tabla indexada dan tamaño/posición); reconstruir el rectángulo de cada
  fragmento y pegarlos en un lienzo del tamaño del logo. El resultado → `assets/logos/konami.png`,
  `kceo.png` (y opcional 4K por chaiNNer).
- **A2 (fallback)**: captura del framebuffer del juego real en Windows durante el logo (requiere el BUG
  de paridad resuelto si se hace headless) y reescalar.
- Los PNG finales son **assets de producto** → sí van al repo (`assets/logos/`), a diferencia de las
  utilidades y volcados de análisis.

**B. Capa de imagen del overlay** (implementada en `55fd951`; reaplicar en commit limpio):
`hh::overlay::set_screen_image(path)` / `clear_screen_image()`; sube el PNG en el render thread y lo
dibuja a pantalla completa con aspecto *contain*, independiente del frame del menú. **Falta** quizá:
fondo **blanco** detrás del logo → panel blanco a pantalla completa antes de la imagen.

**C. Control de la secuencia de logos** (hook, patrón de `hh_title_menu_hook`):
- Envolver el handler del título y detectar el estado activo `func_801C1764` (KONAMI) /
  `func_801C17C8` (KCEO). Mientras esté activo: **publicar la imagen** (KONAMI o KCEO según estado),
  **ocultar los sprites nativos** (por el `obj`/handles) y **mutear el input nativo**
  (`g_mute_native_input`) para gestionar el **skip con START** nosotros (`func_801C1A30` es el skip
  nativo; podemos reenviarlo o forzarlo).
- **Pausar el timer nativo** (`obj+0x3C`, como ya se hace con el menú) mientras el código Konami esté
  en curso, para no avanzar la intro.
- Al terminar (o sin código Konami), dejar que la intro continúe normal.
- **Anclajes ya existentes** (`src/hooks/sections.cpp`): `hh_title_menu_hook` (envuelve `0x801C1DB8`
  por `add_loaded_function`), `g_mute_native_input` y `g_inject_native_a` (`hh_native_dir_input`
  `0x801C1340` / `hh_native_ab_input` `0x801C1334`), y el patrón `MEM_H(0x3C, obj)=0x384` para el timer.
  Reutilizar exactamente este mecanismo (quizá envolver también `0x801C1764`/`0x801C17C8` con
  `add_loaded_function`).

**D. Código Konami** (input propio durante el logo KONAMI):
- Secuencia `↑ ↑ ↓ ↓ ← → ← → B A`. Estado: índice actual + timestamp del último input.
- Leer input con los lectores del juego (`func_801C1340` direcciones / `func_801C1334` A/B) o el input
  del port (mando+teclado).
- **Primer `↑`**: pausa la intro + SFX `KonamiCorrect`.
- Acierto de tecla: `KonamiCorrect`. Fallo: `KonamiError` + reinicio de secuencia (reintentos
  **infinitos**). **Timeout 2 s** por input: sin pulsar en 2 s → cancela y la intro **retoma por donde
  se pausó** (no reinicia la intro).
- Secuencia completa: SFX `KonamiUnlock` + desbloquear el menú **`EXTRAS`**.
- SFX: `hh::menu_sfx::Sfx::KonamiCorrect/Error/Unlock` (commit `0784b5b`, **aún sin reaplicar**).
  Respetan `MENÚ SFX = NO`.

**E. Menú `EXTRAS`** (desbloqueado por el código): entrada en la raíz (encima de `SALIR`), oculta o
deshabilitada hasta desbloquear. Editará partida (nivel y habilidades) — alcance por definir con el
mantenedor. Persistencia del desbloqueo (¿`config.ini`/save?).

**F. Validar en Windows** (mando y teclado): logos en HD con fondo blanco, skip con START, código
Konami (SFX, timeout, reintentos), desbloqueo de `EXTRAS`, e intro normal si no se completa.

## Insumos (resueltos 2026-09-26)
- **Assets**: hay que **reescalar los originales** (no hay 4K oficiales). Upscaler candidato:
  **chaiNNer**. Salida → `assets/logos/`.
- **SFX** (`.mp3` en `sonidos-codigo-konami/`, fuera del repo): **convertidos a WAV 48 kHz/S16/estéreo
  (2026-09-26)** y añadidos a `assets/sounds/` (CMake los copia junto al `.exe`):
  - cada **acierto** de tecla/botón: `correct.mp3` → `konami-correct.wav`
  - **fallo** de secuencia: `error.mp3` → `konami-error.wav`
  - **secuencia completa**: `unlock.mp3` → `konami-unlock.wav`
  - Cargados en `hh::menu_sfx` (enum `Sfx::KonamiCorrect/KonamiError/KonamiUnlock` en `include/hh.h`,
    `src/platform/menu_sfx.cpp`); respetan `MENÚ SFX = NO`.
- **Secuencia**: clásica **`↑ ↑ ↓ ↓ ← → ← → B A`**. Comportamiento:
  - al pulsar el **primer `arriba`** la secuencia de intro **se pausa** (queda "congelada" para el
    código) y suena el SFX de acierto;
  - cada acierto suena `correct`; cada fallo suena `error` y **reinicia la secuencia** (reintentos
    **infinitos**);
  - **timeout de 2 s** por input: si no se pulsa nada en 2 s, se **cancela** y la intro **retoma por
    donde se pausó**;
  - al completar `BA` suena `unlock` y se **desbloquea el menú `EXTRAS`**.
- **Nombres**: **KONAMI** y **KCEO** (la errata "KACEO" queda descartada).

## Nombre del menú a desbloquear — DECIDIDO: `EXTRAS`
El menú editará la partida (nivel y habilidades). Nombre acordado con el mantenedor (2026-09-26):
**`EXTRAS`** (corto, neutro, localizable; encaja en el estilo 1:1). `TRUCOS` queda descartado.

## Referencias
- `notes/2026-09-08-overlay-directory.md` §8.1/§8.4 (timeline y skip).
- `lib/rt64/TEXTURE-PACKS.md` (texture packs, alternativa descartada).
- `docs/menu.md` §Acciones nativas (patrón de overlay + control de la UI nativa).
