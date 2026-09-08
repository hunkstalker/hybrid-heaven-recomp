# Hybrid Heaven: Recompiled — Plan Maestro (documentación detallada)

> Port a PC por **recompilación estática** (N64 → C → nativo) siguiendo el modelo de proyectos como
> Mario 64 EX/Coop, Zelda64Recomp, Goemon64Recomp, Banjo (Lighthouse), etc.
> **Objetivo adicional:** extraer y traducir todos los textos del juego.
>
> ⚠️ **El contexto maestro vive en `../../PROYECTO.md` (raíz del proyecto).** Este documento es el
> plan detallado; `PROYECTO.md` es la fuente de contexto canónica que se actualiza cada sesión.

---

## 0. Resumen ejecutivo

Se va a construir un port nativo a PC del juego **Hybrid Heaven (N64, Konami KCEO, 1999)**.
El método elegido es la **recompilación estática**: el código MIPS de la ROM se traduce
automáticamente a código C (literal), se compila para PC y se ejecuta sobre un *runtime*
que reimplementa el hardware N64 (vídeo, audio, input, memoria) mediante librerías modernas.

**Este port permitirá:**
- Resolución arbitraria / widescreen / ultrawide
- Frame rate desbloqueado (o mejorado)
- Guardado a disco (reemplaza Controller Pak)
- Controles modernos (XInput, DualShock, mando, teclado+ratón)
- **Traducción completa del texto mediante reemplazo del sistema de texto**

**ROM compatible requerida:** Hybrid Heaven (USA) retail, 16 MB. El port **no incluye la ROM**: el
usuario aporta su copia, que debe coincidir con el checksum.
- SHA-1: `16dbc21620b52deab5c5abf8a309ac60adfbee85`
- SHA-256: `5476523049dd35c287cf05e0cc743cf5942dbc88d29bd7c351c220257bd18790`
- XXH3-64 (el que valida el port internamente): `0x0F6A72F2C36A216D`

---

## 1. Decisiones de arquitectura

| Decisión | Opción elegida | Por qué |
|---|---|---|
| Enfoque | **Recompilación estática** con `N64Recomp` | No requiere decompilación completa; se logra un port jugable con mucho menos esfuerzo que un decomp. Es el método de Zelda64Recomp, Goemon, Lighthouse, etc. |
| Render | **RT64** | Renderer moderno (D3D12/Vulkan/Metal) capaz de emular fielmente el RDP del N64, incluyendo framebuffer effects, dithering, etc. Es el estándar de la comunidad N64Recomp. |
| Runtime base | **N64ModernRuntime** (parte del ecosistema N64Recomp) | Provee las macros y funciones del runtime (memoria RDRAM, llamadas OS, etc.) |
| Referencia de port no-Zelda | **Goemon64Recomp** | Port de un juego de Konami coetáneo con la misma época, ya resuelve muchos problemas generales (videomodes del juego, cámara, etc.). Fork lógico de partida |
| Idioma del port | **Versión USA** | El user la prefiere: solo inglés → texto plano y jugable; el selector de idioma de EU desaparece → menos código que parchear |

> **Nota sobre idiomas EU vs USA:** La versión europea trae EN/FR/DE y una pantalla extra de
> selección de idioma + texto embebido en UTF-16LE para esos selectores. La USA trae solo inglés.
> Para la **traducción a otro idioma**, partir de la USA simplifica la extracción (un solo idioma).

---

## 2. Fases del proyecto

### Fase 0 — Preparación del entorno (semanas 0-1)
- [ ] Clonar `N64Recomp`, `N64ModernRuntime`, `RT64`, `Zelda64Recomp` (referencia), `Goemon64Recomp` (referencia clave)
- [ ] Verificar checksums de las ROMs (SHA-1 vs No-Intro)
- [ ] Instalar toolchain: CMake ≥3.20, compilador C++20, Ghidra, python3
- [ ] Configurar emulador de referencia con debugger (Ares o Mupen64Plus+Rice) para comparación frame-a-frame
- [ ] Establecer convención de nombres y estructura de repo (Git + no subir ROM ni assets)

### Fase 1 — Análisis estático profundo de la ROM (semanas 1-6)
Objetivo: **construir el mapa de segmentos + tabla de símbolos inicial**, máxime porque
Hybrid Heaven **incluye símbolos de debug del compilador** (paths como `/game/source/...`).

- [ ] Analizar el **boot**: entry point `0x80000400`, código de arranque, trampolín a `__osInitialize`
- [ ] Detectar **librerías N64 SDK utilizadas** (libultra versión, microcode RSP)
- [ ] **Microcode gráfico**: detectado `F3DEX2 fifo 2.06` (Nintendo 1998). Confirmar si es el único o hay variaciones por nivel
- [ ] Localizar la **tabla de segmentos** (overlays) del juego
- [ ] Mapear **funciones OS a direcciones**: `osInitialize`, `osCreateThread`, `osViSetMode`, `osAiSetNextBuffer`, `osContStartReadData`, etc.
- [ ] **Extraer y documentar los símbolos de debug** del compilador. Esto acelera muchísimo el mapeo (nombres de funciones/labels)
- [ ] Localizar el **sistema de texto** (ver doc `03-extraccion-traduccion-textos.md`)

Entregables: `config.toml` + primeros `overlays`/symbols para N64Recomp, mapa de memoria.

### Fase 2 — Recompilación del código base (semanas 4-10)
- [ ] Crear `game.toml` de N64Recomp (config init, paths, funciones)
- [ ] Obtener/detectar **ELF con símbolos** (o generar symbol map) — N64Recomp requiere un ELF

  > N64Recomp acepta un ELF con símbolos y relocaciones. Se puede producir un ELF *ad-hoc*
  > mediante scripts (ver PLAN detallado en `02-recompilacion-estatica.md`) o usar símbolos de plugins Ghidra.

- [ ] Compilar el C recompilado contra el runtime (N64ModernRuntime)
- [ ] Boot loop mínimo: inicializar memoria, ejecutar game loop, sistema de vídeo DENTRO de la ventana
- [ ] **Primer hito jugable**: título + pantalla de modo select renderizada nativamente
- [ ] Implementar **input** (SDL Controller), reemplazando `osContStartReadData`

### Fase 3 — Integración RT64 (render) (semanas 8-16)
- [ ] Implementar el adaptador microcode F3DEX2 → RT64 (que RT64 ya entiende nativamente)
- [ ] Manejar los **modos de vídeo del juego**: 3 resoluciones (Low, High Normal, High Letterbox) según Expansion Pak
- [ ] Revisar efectos especiales de Hybrid Heaven: transparencias, blending, sprites 2D del HUD/menús, escenas cinemáticas
- [ ] Comprobar los **efectos framebuffer** (HD la cámara del film noir que usa el juego)
- [ ] Widescreen/ultrawide + HUD

### Fase 4 — Audio (semanas 12-18)
- [ ] Identificar el **microcode de audio** (ABI) usado (buscar el "audio ABI" en la ROM)
- [ ] Emular el RSP de audio o traducir la secuencia MIDI
- [ ] Implementar salida con miniaudio/SDL
- [ ] Reproducir / enlazar los datos de sonido/música del juego (posible compresión tipo Konami)

### Fase 5 — Control de guardado (semanas 14-20)
- [ ] Reimplementar las rutinas de **Controller Pak** (53 páginas) → archivos de guardado en disco
- [ ] Sistema de guardado múltiple (4 slots) + export/import
- [ ] **Rumble Pak** → vibración del mando moderno

### Fase 6 — Extracción y traducción de textos (semanas 12-24, paralela a 4-5)
Ver doc `03-extraccion-traduccion-textos.md`:
- [ ] Localizar encodings y tablas de caracteres
- [ ] Dump completo del script de diálogo + menús + nombres + subtítulos
- [ ] Construir editor de traducción + **build del texto traducido reinsertado en el runtime recompilado**
- [ ] (Opcional) Fuentes rediseñadas para el idioma destino (tildes, ñ, etc.)

### Fase 7 — Robustez, enhacements y empaquetado (meses 4-8)
- [ ] Cobertura de ~2 playthroughs completos, comparación con emulador frame-a-frame
- [ ] Fix de bugs de recompilación (delay slots, endianness, TLB, overlays)
- [ ] HUD escala para resolución moderna, opciones de calidad
- [ ] Builds: Windows + Linux (+macOS opcional)
- [ ] Empaquetado sin ROM: el juego lee assets de la ROM del usuario al arrancar (modelo Zelda64Recomp)

---

## 3. Stack tecnológico detallado

### 3.1 N64Recomp (recompilador)
- Repo: `github.com/N64Recomp/N64Recomp`, compilado con CMake ≥3.20, C++20
- Traduce instrucción a instrucción a C literal (`ctx->r4 = ADD32(...)`)
- Maneja *branch delay slots* duplicando instrucciones
- Soporta **overlays estáticos y relocatables** (`LOOKUP_FUNC`, `RELOC_HI16/LO16`)
- Config vía `toml`

### 3.2 N64ModernRuntime (runtime)
- Implementa: macros del recompilado (`ADD32`, `LOOKUP_FUNC`, etc.), RDRAM, registros HW
- Se enlaza con SDL2 y provee el contexto de ejecución del juego

### 3.3 RT64 (renderer)
- Emulación completa del **RDP del N64** sobre Vulkan/D3D12/Metal
- Ya soporta microcode **F3DEX / F3DEX2 / F3DEX2fifo** nativamente
- Efectos: framebuffer, decals, dithering de N64, texturas
- Permite desbloquear resolución, widescreen y mejoras

### 3.4 Herramientas de análisis
| Herramienta | Uso |
|---|---|
| Ghidra + N64LoaderWV | Desensamblado/decompilado estático interactivo |
| splat / n64 split | Dividir binario en secciones |
| rabbitizer | Decodificación de instrucciones MIPS |
| Ares / Mupen64Plus | Emulador de referencia con tools de debugging |
| python3 + scripts | Parsing de ROM, extracción de textos |

### 3.5 Toolchain de build
CMake, gcc/clang C++20, ninja, SDL2, Vulkan/D3D12 headers, miniaudio/SDL_mixer.

---

## 4. Riesgos técnicos específicos de Hybrid Heaven

1. **Overlays y TLB**: si el juego mapea código a través de TLB, N64Recomp requiere soporte de relocaciones TLB (parcialmente disponible; existe fork `RevoSucks/N64Recomp_New` con TLB support). **A verificar en Fase 1.**
2. **Microcode gráfico**: si algún nivel usa un microcode custom (no F3DEX2), el adaptador RT64 necesitará trabajo extra.
3. **Compresión de datos** (`trans.c` menciona `Lzss`): hay datos comprimidos (texturas, archivos por nivel). Habrá que reimplementar los descompresores para el pipeline RT64 y para el extractor de textos.
4. **Audio Konami**: los bancos musicales de Konami de esta época pueden usar formatos propietarios; requerirá ingeniería inversa o traducción a MIDI.
5. **Símbolos de debug presentes** (paths `/game/source/*.c`): son una gran ventaja, pero hay que limpiarlos (puede incluirse debugging del propio código original).
6. **Endianness/alto rendimiento**: todos los accesos a memoria son 32-bit big-endian → el runtime lo convierte; la eficiencia dependerá de RT64/RDRAM mapping.

---

## 5. Legal y distribución

- **El port no incluye assets ni ROM.** El usuario proporciona su copia de la ROM USA (o la que corresponda).
- El juego corre leyendo el binario/base de datos del usuario al primer arranque (modelo de Zelda64Recomp).
- No comercial: proyecto fan/sin ánimo de lucro a nivel personal. Mantener en privado mientras se desarrolla.
- La documentación técnica y herramientas propias (scripts de parsing, análisis) son trabajo original.

---

## 6. Mapa de rutas / enlaces de referencia

| Link | Relevancia |
|---|---|
| `github.com/N64Recomp/N64Recomp` | El recompilador |
| `github.com/N64Recomp/N64ModernRuntime` | Runtime |
| `github.com/rt64/rt64` | Renderer |
| `github.com/Zelda64Recomp/Zelda64Recomp` | Port de referencia (MM/OoT) |
| `github.com/klorfmorf/Goemon64Recomp` | **Port de referencia clave** (Konami, no-Zelda) |
| `github.com/HarbourMasters/Lighthouse` | Banjo (otra referencia de recomp multi-overlay) |
| `github.com/Zelda64Recomp/RecompPrime` | estructura de branching de un port nuevo |
| `github.com/zeroKilo/N64LoaderWV` | Loader Ghidra N64 |
| `github.com/blackgamma7/n64_ghidra` | Scripts Ghidra N64 |
| `github.com/zznop/splat` | Splitting de binarios |

---

## 7. Estado actual (checklist de progreso)

- [x] Confirmación del checksum de la ROM compatible (SHA-1 `16dbc21620b52deab5c5abf8a309ac60adfbee85`)
- [x] Análisis inicial: header, byte order, entry point, microcode gfx (F3DEX2 2.06), strings de idioma, sistema de guardado (Controller Pak + Expansion Pak + Rumble)
- [x] Creación del archivo de contexto maestro en la raíz: `PROYECTO.md`
- [ ] Fase 0 (entorno)
- [ ] Fase 1 (análisis estático completo) — en curso tras este doc
- [ ] Fases 2-7 (ver sección 2)

---

## 8. Sesión futura

**Antes de arrancar cualquier tarea nueva, leer `PROYECTO.md` y actualizarlo con los hallazgos de la sesión anterior.**