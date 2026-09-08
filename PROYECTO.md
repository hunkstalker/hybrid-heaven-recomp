# PROYECTO — Hybrid Heaven: Recompiled (Contexto maestro)

> **ESTE ARCHIVO ES LA FUENTE DE CONTEXTO PRINCIPAL DEL PROYECTO.**
> Cada sesión debe leerlo y actualizarlo con TODA la información relevante que obtenga
> (hallazgos, decisiones, estado, rutas, herramientas, problemas).
> Vive en la raíz del proyecto: `/app/hybrid-heaven-recomp/PROYECTO.md`.
> Los documentos detallados viven en `docs/` (ver sección 8 "Estructura de documentación").

Actualizado por última vez: **2026-09-05** (3ª sesión: asset map RZ011 + toolchain + repos clonados).

---

## 1. Objetivo del proyecto

Construir un **port a PC nativo** de **Hybrid Heaven** (N64, Konami Computer Entertainment
Osaka, 1999) mediante **recompilación estática**, en la línea de Mario 64 EX/Coop,
Zelda64Recomp, Goemon64Recomp, Lighthouse (Banjo), etc.

**Sub-objetivo obligatorio:** extraer TODO el texto del juego y poder **traducirlo**
(pipeline de extracción → traducción → re-inserción en el port).

**Plataformas objetivo (REQUISITO del usuario):** el port debe funcionar en
**Windows, Linux y Steam Deck** (build multiplataforma desde el primer día;
tres binarios desde el mismo código, sin bifurcar).

El resultado debe funcionar **sin emulador**, leyendo solo la ROM del usuario
(en el estilo de Zelda64Recomp: los assets se cargan de la ROM al primer arranque).

---

## 2. Entorno de trabajo

| Ítem | Valor |
|---|---|
| Diretorio de trabajo actual | `/app` |
| Proyecto | `/app/hybrid-heaven-recomp/` |
| SO del entorno | Alpine Linux 3.24.1 (ligero; gestor de paquetes `apk`) |
| Workspace del proyecto | Todo vive en este repo (ver §8): `work/` y `toolchain/` se generan/descargan y están gitignored |
| ROM USA | `/app/baserom.us.z64` (16 MB, big-endian/z64, ID NHVE) |
| ROM Europa | `/app/baserom.eu.z64` (16 MB, big-endian/z64, ID NHVP) |
| MD5 US | `da861c4d9202f661575466450a27c412` |
| MD5 EU | `c47e95bb32ab132c41d67bd243f9e02a` |
| Red a internet | OK (GitHub, repos Alpine accesibles) |
| Toolchain instalada | python3 3.14, pip, git, binutils, file, wget, xxd/od/hexdump, **gcc/g++ 15.2.0, cmake 4.2.3, ninja, SDL2 2.32.10** + **JDK 21 + Ghidra 12.1.3 + N64LoaderWV** |
| Toolchain FALTA | emulador de referencia (Ares/Mupen64Plus + dump RDRAM para overlays), `mingw-w64` (build Windows), cargo/rust (solo si abandonamos el shim Python de `lzkn64`) |
| Repos clonados (en `toolchain/src/`) | N64Recomp, N64ModernRuntime, RT64, Zelda64Recomp, Goemon64Recomp (con mnsg, mnsg_syms) |
| Extracción de assets | ✅ `rommy.py` (Konami Nisitenma-Ichigo): US y EU descomprimidas; manifests en `notes/` |
| Análisis Ghidra US | ✅ Ghidra 12.1.3 (JDK 21) + N64LoaderWV → importación + análisis de `baserom.us.z64` completados (2026-09-05); proyecto en `work/ghidra/proj` |

> Las ROMs son **uso personal/legal propio del usuario**; NO se suben al repo ni se
> versionan. El repo debe quedar limpio de assets (modelo No-Intro).

---

## 3. Decisiones de arquitectura (confirmadas)

| Decisión | Elección | Razón |
|---|---|---|
| Enfoque | Recompilación estática con **N64Recomp** | Port sin decompilación completa; método probado (Zelda64Recomp, Goemon, Lighthouse) |
| Render | **RT64** (Vulkan/D3D12/Metal) | Emula RDP N64 fielmente, ya soporta microcode F3DEX2 |
| Runtime | **N64ModernRuntime** | Provee macros/funciones del runtime del recompilado |
| Port de referencia clave | **Goemon64Recomp** (klorfmorf) | Juego de Konami coetáneo, no-Zelda → problemas de port muy similares |
| ROM base del port | **USA** (`baserom.us.z64`) | 1 solo idioma (inglés), sin selector de idioma → menos código a parchear y extracción de textos más simple |
| Guardado | Reemplazar Controller Pak por archivos en disco | Elimina dependencia de hardware |
| Input | SDL2 GameController + teclado/ratón | Estándar en estos ports |
| Plataformas | **Windows + Linux + Steam Deck** (mismo código, 3 builds) | Requisito del usuario; SDL2 + RT64 (Vulkan/D3D12) ya es multiplataforma |

---

## 4. Hallazgos técnicos de la ROM (análisis 2026-09-05)

### 4.1 Datos básicos
- Formato **z64 nativo (big-endian)** — NO requiere conversión de byte order.
- Tamaño **16 MB (128 Mbit)** — cartucho expandido.
- Entry point boot: **`0x80000400`** (estándar libultra).
- Título interno US: `HYBRID HEAVEN USA`; EU: `HYBRID HEAVEN PAL`.
- Código interno (bytes 0x3B-0x3E): **NHVE** (USA) / **NHVP** (PAL).
- CRC1/CRC2 (US): `0x102888BF` / `0x434888CA`. (EU): `0x641D3A7F` / `0x86820466`.

### 4.2 Microcode / librerías
- Microcode gráfico: **`RSP Gfx ucode F3DEX2 fifo 2.06 — Yoshitaka Yasumoto 1998 Nintendo`**
  (detectado por strings en ambas ROMs). → RT64 lo entiende nativamente. ✅
- Presencia de llamadas libultra estándar a confirmar por detalle en Fase 1
  (`osInitialize`, `osCreateThread`, `osViSetMode`, `osContStartReadData`, etc.).
- El juego usa **segments/overlays**: el string `trans.c seg_RomDecode_sep` y rutas
  `/game/source/...` sugieren carga de segmentos (posible TLB) → **riesgo** ver sección 7.1.

### 4.3 Símbolos de debug presentes (HALLAZGO CRÍTICO)
El binario conserva **nombres de archivos fuente del proyecto original** de KCE Osaka:

```
/game/source/expansionram.c
/game/source/titlescreen.c
/game/source/auto_sub.c
/game/source/democamera.c
/game/source/a02_s05demo.c, a03_s02capdemo.c, a04_s05demo.c, a05demo.c,
/game/source/a08demo.c, a09elevatordemo.c, a10_s01_explodedemo.c, area6to8demo.c
/game/source/device/alarm.c, device/bridge.c, device/kugutu.c, device/messenger.c
/game/source/enemy/e_n40.c, enemy/wanderer.c
/game/source/ground/door.c, ground/door_demo.c
/game/source/player/battle_...
trans.c (menciona Lzss, pic, seg_RomDecode_sep)
cam_change.c, _operation.c, _demo_cam.c, _demo_sub.c
titlescreen.c
```

**Implicación:** el compilador IDO dejó símbolos → localizar estos strings en la ROM y
usarlos como anclas de funciones para el mapa de símbolos. Acelera muchísimo la Fase 1.
Ruta de strings principal: zona `0x0530000-0x06D0000` (ver nota completa 4.5).

### 4.4 Sistemas de hardware del juego
- **Guardado:** Controller Pak externo, **53 páginas**, 4 slots de guardado.
  (La versión japonesa usaba EEPROM interno; USA/EU usan Controller Pak.)
- **Rumble Pak:** soportado para feedback de daño/defensa.
- **Expansion Pak:** soportado; **3 resoluciones**: Low / High Normal / High Letterbox.
  Presente el string `expansion_memory_fg %x` y `EXPANSION_PAK_`.
- **Modo widescreen:** el juego original ya es uno de los pocos del N64 con 16:9 → favorece el port.

### 4.5 Estructuras de texto detectadas (clave para la traducción)
- **USA:** texto en un **encoding custom** (no ASCII puro), localizado en varias zonas.
  Ejemplos de anclas: `WASHINGTON D.C.` @ `0x061CD7A` (US) / `0x0635DDC` (EU);
  `PLEASE SELECT` @ `0x05FB543`; `%pPLEASE SELECT.GAME S...`; menú `BATTLE` @ `0x05FAF4C`;
  `ITEM...WEAPON` @ `0x06C33AF`; `DEMO SELECT` @ `0x06DC878`; `attack selection` @ `0x06C3566`.
- **EU:** selector de idioma con strings **UTF-16LE interleaved con datos**: `ENGLISH`,
  `GERMAN`, `FRENCH` (N rodeado por bytes de métricas). El manual confirma
  "English, German and French" como los 3 idiomas de la versión PAL.
- Zonas con alta densidad de texto ASCII (ambas ROMs, window de 64KB):
  `0x0400000, 0x0410000, 0x0420000, 0x0440000, 0x0470000, 0x0530000, 0x05F-0x06D.., 0x0700000-0x0730000`.
- Rutinas/estructura del sistema de texto: **pendiente de desentrañar** (Fase 6).

### 4.6 Compresión — **FORMATO KONAMI CONFIRMADO (LZKN64 + tabla Nisitenma-Ichigo)**
- Ambos ROMs contienen la firma ASCII **`Nisitenma-Ichigo`** (US @0x39BE0 → tabla @0x39BF0;
  EU @0x3AA30 → tabla @0x3AA40). Es la **tabla de archivos de todos los N64 de Konami**,
  exactamente la que maneja `rommy.py` del repo mnsg (Goemon).
- **Formato de tabla**: entradas de **4 bytes BE**: bits [0-30] = offset en ROM, bit31 =
  flag de compresión **LZKN64**; el final del fichero N es el inicio de N+1; termina en `0x00000000`.
- **Verificado en ambas ROMs**: la 1ª entrada comprimida descomprime con LZKN64 a exactamente
  **4096 bytes (0x1000)**. → El algoritmo `lzkn64_decompress` de Goemon64Recomp y la librería
  `pip install lzkn64` funcionan **sin cambios** con Hybrid Heaven. ✅
- Ejemplo (US): `[0] off=0x4E5F40 comp=1 → 2664 bytes → 4096 decod.; [7] off=0x4E69A8 comp=1 size=351700…`.
- **El código principal NO está comprimido** (evidencia: densidad MIPS uniforme 0.74–1.0 en todo
  el ROM; cola de ceros ~1.6 MiB al final). Goemon, en cambio, comprimía TODO su código con LZKN64
  (16 MiB → 64 MiB). En HH solo se comprimen **assets/datos** (texturas PIC, niveles, etc.).
- `trans.c` (strings de debug @0x4C6E0-0x4CD00) referencia el sistema de carga segmentado:
  `seg_RomDecode_sep`, `romNo[%d]`, `seginfo_Tail`, `split_seginfo`, `trans_to_malloc64_sep(s)`,
  y las variantes **`LZSS 5 %x %x %x` / `LZSS 7 %x %x %x`** (LZSS de Konami en offsets de 5/7 bits)
  → el cargador `trans` soporta LZKN64 Y LZSS propio; hay que mapear ambos en Fase 1.

### 4.8 Motor compartido con Goemon (hallazgo de la 2ª sesión)
- **Confirmado**: Goemon N64 (Mystical Ninja Starring Goemon / Ganbare Goemon 2) y **Hybrid Heaven
  son ambos de Konami Computer Entertainment Osaka (KCEO)** → motor/librerías de la misma casa.
- Evidencia compartida verificada: mismo entrypoint (0x80000400), mismo microcode gfx F3DEX2
  fifo 2.06, y el **mismo formato de tabla de archivos Nisitenma-Ichigo + LZKN64**.
- Microcode de audio: NO encontrada la firma estándar de Nintendo (`aspMain` `LDV/LBV` inicial)
  → **PENDIENTE identificar** (posible ucode custom KCEO; verificarlo con Ghidra/emulador).
- **Qué NO se reutiliza de Goemon64Recomp tal cual**: su `decompress_mnsg`/descompresión de ROM
  completa (innecesaria en HH: el código es plano). Nuestro pipeline N64Recomp arranca directo
  sobre el ROM sin paso de descompresión (como Zelda64Recomp).
- **Qué SÍ se reutiliza**: scaffolding del port (main.cpp/GameEntry, integración RT64 +
  N64ModernRuntime), formato de tomas `mnsg.toml`/`patches/*.toml`, sistema de parches por
  instrucción, y `rommy.py` + `lzkn64` para extracción de assets (Fase 0/1 y 6).

### 4.9 Mapa de assets y nombre interno **RZ011** (3ª sesión)
- **Nombre interno del proyecto KCEO: `RZ011`** — build path: `/hdisk1/u/nu64/rz011_usa/...`.
- **62 archivos fuente `.c` únicos** conservados (solo módulos con `-g`: demo/player/camera/device/
  enemy/ground/titlescreen/expansionram). Lista completa en `notes/2026-09-05_asset-map.md`.
- **325+ archivos** en la tabla Nisitenma-Ichigo (US y EU extraídas con `rommy.py`): 482 comprimidos
  LZKN64 → **462 overlays de código** (13.9 MB) + tablas de datos (floats/animación), texturas PIC, textos.
- **Boot/BSS/SP**: limpia 0x80DC0 bytes en 0x8004DBD0..0x800D5880; SP=0x80057BD0; salta a 0x80001078.
- **Mapeo RAM del código principal = ROM_offset + 0x80000000.** (Los overlays usan sus propias RAM
  bases vía `trans` — PENDIENTE mapearlas con Ghidra/emulador.)
- Anclas de texto en overlays 262/264/303 (además de la zona pre-tabla).
- Herramientas persistidas en `tools/` (`rommy.py`, paquete shim `lzkn64/`); manifests en `notes/`.

### 4.7 Códigos / referencias externas
- GameHacking.org: códigos para debug camera (existen códigos "debug info" → el juego
  tiene equipo de debug interno). Código maestro: `F102C164 2400` (Action Replay).
- Cheatsheet de libretro para Hybrid Heaven (Japan) existe → útil para tests.
- Título japonés: ハイブリッドヘヴン (release JP 1999-08-05, US 1999-08-31, EU 1999-09-24).

---

## 5. Dependencias a instalar (pendientes)

Ya instaladas (2026-09-05): `build-base` (gcc/g++ 15.2.0), `cmake` 4.2.3, `ninja`, `sdl2-dev`
(2.32.10), `linux-headers`.

Pendientes:
- Java JDK (para Ghidra) — Ghidra descargable; también plugin N64LoaderWV
- `mingw-w64` para build **Windows desde Linux** (NO opcional: Windows es plataforma objetivo)
- Un emulador de referencia para comparación frame-a-frame: **Ares** o **Mupen64Plus+**
  (Mupen más fácil de scriptear; Ares más preciso).

**Build multiplataforma (Windows + Linux + Steam Deck):**
- Mismo código base, 3 binarios: Linux nativo (dev/release), Windows (cross via `mingw-w64`
  en CI o release local), Steam Deck = binario **Linux x86_64** + controles SDL2 GameController
  (perfil Gamepad). Verificar estado de build de SteamDeck en Fase 7 (empaquetado).
- Stack ya compatible: SDL2 (input), RT64 (Vulkan/D3D12/Metal), N64ModernRuntime (C++ portable).
- Considerar `GitHub Actions` multi-OS para builds de release (Windows/Linux/macOS) en Fase 7.

---

## 6. Estado de avance (checklist viviente)

| Fase | Estado | Notas |
|---|---|---|
| 0. Preparación del entorno | En curso | Doc + análisis inicial OK; toolchain core instalada; repos clonados; assets US/EU extraídos ✅ |
| 1. Análisis estático profundo | Pendiente | Símbolos de debug (RZ011) + tabla Nisitenma-Ichigo localizada y extraída → gran ventaja |
| 2. Recompilación código base | Pendiente | Requiere mapa de símbolos + RAM bases de overlays + ELF; SIN descompresión de ROM |
| 3. Integración RT64 (render) | Pendiente | Microcode F3DEX2 ✅ favorable |
| 4. Audio | Pendiente | ABI de audio a identificar (ucode custom?) |
| 5. Guardado | Pendiente | Controller Pak → disk |
| 6. Textos y traducción | Pendiente | Zonas de texto mapeadas en parte (overlays 262/264/303) |
| 7. Robustez/empaquetado | Pendiente | **3 builds: Windows + Linux + Steam Deck** (requisito) |

Detalle de las fases: `docs/README.md`.

---

## 7. Riesgos y problemas conocidos

### 7.1 Riesgos técnicos
1. **Overlays/TLB:** comprobar cómo carga el juego los segmentos (posible TLB mapping).
   N64Recomp tiene soporte de relocaciones TLB en desarrollo; existe fork
   `RevoSucks/N64Recomp_New` con TLB support. **Verificar en Fase 1.**
2. **Microcode custom:** el ucode de audio no matchea `aspMain` de Nintendo (firma LBV/LDV no
   presente) → posible ucode de audio propio KCEO. Identificar en Fase 1/4.
3. **Compresión LZKN64 + LZSS ("LZSS 5"/"LZSS 7")**: ya resuelto el descompresor LZKN64
   (reutilizable de rommy/lzkn64); mapear las variantes LZSS del cargador `trans` de HH.
4. **Efectos framebuffer** (el juego usa cinematografía): verificar en RT64.
5. **Endianness:** RDRAM 32-bit BE → runtime lo maneja; vigilar rendimiento.

### 7.2 Riesgo legal/ético
- No distribuir ROM ni assets. Distribuir solo el port que **requiere la ROM del usuario**.
- Proyecto fan sin ánimo de lucro; no comercializar. Mantener repo privado durante desarrollo.

### 7.3 Requisitos transversales del usuario
- **Windows + Linux + Steam Deck**: mantener el código portable desde el inicio (sin
  dependencias solo-Windows, paths relativos a la ROM del usuario, nada de assumir directorio
  de instalación). El binario de Steam Deck es el mismo Linux con perfil Gamepad; validar TDP/
  folio (RT64 Vulkan) y SteamInput en Fase 7.

---

## 8. Estructura de documentación

```
/app/hybrid-heaven-recomp/
├── PROYECTO.md          ← ESTE ARCHIVO (contexto maestro, se actualiza cada sesión)
├── docs/
│   ├── README.md        ← Plan maestro + fases + stack + riesgos (detallado)
│   ├── 01-analisis-rom  ← (pendiente) análisis profundo de la ROM
│   ├── 02-recompilacion ← (pendiente) arquitectura N64Recomp/RT64
│   └── 03-textos        ← (pendiente) pipeline de extracción/traducción
├── tools/               ← scripts propios (parsing, textos, build)
│   ├── rommy.py         ← extracción/compresión Nisitenma-Ichigo
│   ├── lzkn64/           ← paquete shim `lzkn64` (LZKN64, API decompress/compress)
│   ├── lzkn64/           ← paquete shim `lzkn64` (import lzkn64 con PYTHONPATH=tools)
│   ├── analysis/         ← scripts de análisis de ROM (densidad MIPS, escaneos LZKN64)
│   └── README.md        ← guía de uso de las herramientas
├── notes/               ← notas de sesión sueltas + manifests Nisitenma
├── work/                ← GITIGNORED: derivados del usuario (ROMs del usuario descomprimidas,
│   │                       proyecto Ghidra, artefacts temporales) — NUNCA versionar
│   ├── roms/            ← us_dec.z64 / eu_dec.z64 (assets descomprimidos, derivados)
│   ├── ghidra/proj/     ← proyecto Ghidra con baserom.us.z64 importado y analizado
│   └── scratch/         ← salidas temporales de scripts
└── toolchain/           ← GITIGNORED: herramientas descargables (no versionar)
    ├── ghidra/          ← Ghidra 12.1.3 (install + zip)
    ├── venv/            ← virtualenv Python (PyYAML, etc.)
    ├── ext/             ← N64LoaderWV (zip + fuente extraída)
    └── src/             ← repos fuente: N64Recomp, N64ModernRuntime, RT64,
                           Zelda64Recomp, Goemon64Recomp (+ mnsg, mnsg_syms)
```

**Nota:** la extensión N64LoaderWV se instala a nivel de usuario
(`~/.config/ghidra/ghidra_12.1.3_PUBLIC/Extensions/`), independiente de dónde viva
`toolchain/ghidra/`.

**Regla de oro:** al finalizar/hacer-hallazgos durante cada sesión, actualizar este
`PROYECTO.md` para que la siguiente sesión arranque con todo el contexto necesario.

---

## 9. Próximos pasos inmediatos

1. ~~Instalar toolchain core~~ ✅ (gcc/g++, cmake, ninja, SDL2 — 2026-09-05).
2. ~~Clonar repos base~~ ✅ N64Recomp, N64ModernRuntime, RT64, Zelda64Recomp, Goemon64Recomp.
3. ~~Instalar JDK y montar **Ghidra + N64LoaderWV**~~ ✅ (2026-09-05: JDK 21 + Ghidra 12.1.3 +
   extensión N64LoaderWV; ROM US importada y analizada). ~~Derivar de Ghidra el mapa de RAM bases
   de overlays (cargador `trans`)~~ **SUPERADO por un método mejor**: el directorio `trans` se
   observa EN VIVO en runtime — write-bp sobre `0x8008DFC0` (§5, vía emulador) y volcado por
   script BizHawk (tarea #3, EN CURSO; ver `sesion.md` §1/§15 + `notes/2026-09-08-overlay-directory.md`).
4. Construir el **mapa de símbolos inicial**: anclar funciones por archivo fuente (`/game/source/*.c`,
   proyecto RZ011) usando referencias `lui/ori` a sus strings (requiere RAM bases de overlays).
5. ~~Extraer tabla Nisitenma-Ichigo (US+EU)~~ ✅ 625 archivos; manifests en `notes/`; `tools/rommy.py`.
6. Identificar el **microcode de audio** (ucode custom vs asp).
7. Empezar Fase 2: generar ELF del código principal (0x1000+0x80000000) con N64Recomp y probar
   el build Linux → RT64 (código principal plano favorece el arranque temprano del render).
7. Empezar pipeline de extracción de textos (doc 03).
8. **Tarea #3 (EN CURSO) — mapa overlay→RAM de todo el juego por runtime**: pipeline BizHawk
   funcional (script **v5** en `work/gameplay screenshots/`, volcado de directorio + F12 PNG/txt
   emparejados por wall-clock). **Confirmados con capturas**: combate por turnos
   (`010F`+`01AA…01B8`+`0125/0127`) y menú pausa (`0113…0121`) → `notes/…-overlay-directory.md` §10.7.
   Pendiente: pasar la partida larga al contenedor, etiquetar sets sueltos, arreglar registro del
   stick. Índice operativo y pendientes: `sesion.md` §1/§12/§15.