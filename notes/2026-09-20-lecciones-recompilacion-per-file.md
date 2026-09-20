# Lecciones: recompilación per-file (y cómo abordar otros juegos)

> **Nota de método, no de un bug concreto.** Resume el error que nos costó cientos de commits de
> parches y la metodología correcta para recompilar un juego N64 con N64Recomp. Reutilizable para
> futuros proyectos. Fecha: 2026-09-20.

## 1. El error (resumen)

El primer enfoque recompiló **11 de 91** ficheros de código de la tabla de assets y construyó la
capa de overlays a mano:

1. **Extracción incompleta**: `setup_module.py` tenía una **lista hardcodeada** de 11 módulos de las
   **625** entradas de la tabla Nisitenma (91 de ellas son código). Faltaban 80, incluido el fichero
   de combate (57).
2. **Un solo loader envuelto**: el juego tiene **dos loaders** (normal `file_load` y **streamed**
   `FUN_80004838`). Al no envolver el streamed, los ficheros cargados así nunca se **registraban**.
3. **Símbolos por heurística** (prólogo + `jal` + `jr ra`) en vez de fronteras reales → mid-entries,
   splits y **datos-como-código** (`syscall`/`mthi`/`break`).
4. **`.text` plano de Ghidra** con funciones **dentro de rangos de overlay** que **solapaban** el
   código correcto.
5. **Reconstrucción circular**: los syms se "reconstruían desde la build Release", que a su vez se
   compiló con esos mismos syms incompletos → el método **no puede** revelar lo que falta.

**Síntoma final**: `0x80379410` (inicio de función del fichero 57, pero mid-función del 56) resolvía
al **código equivocado** → fuga de pila → corrupción de una lista → deadlock. Se parcheó el síntoma
(`HH_M55SPFIX`), cuando la causa era la extracción.

## 2. Cómo se debe hacer (metodología per-file)

1. **Enumerar TODOS los ficheros de código** desde las tablas del juego (Nisitenma + tabla de VRAM).
   Nunca una lista a mano.
2. **Extraer cada fichero** (descompresión propia del juego; aquí LZKN64).
3. **Desensamblar por fichero** con un desensamblador real (Ghidra `analyzeHeadless`, o una decomp)
   que dé **fronteras de función exactas**. Una entrada de código = una sección.
4. **Syms por sección** (`rom`/`vram`/`size` + funciones) y `relocatable_sections_path` con la lista
   completa.
5. **Notificar el runtime en TODOS los loaders**: implementar `recomp_load_overlays`/
   `recomp_unload_overlays` y llamarlos cuando el juego carga/descarga un fichero. Los overlays
   **se solapan y se intercambian**; el mapa de funciones debe actualizarse en ambos sentidos.
6. **El código residente** (`.text`) se recompila **excluyendo todos** los rangos de overlay.
7. **Versionar el C recompilado** → quien clona y compila **no** necesita el recompilador ni el
   desensamblador (solo el compilador + deps + ROM).
8. **Checks de completitud** (en CI si posible):
   - nº de secciones == nº de ficheros de código;
   - todo `jal`/`jalr` resuelve (sin `do_break`/stubs);
   - sin solapes no declarados entre `.text` y overlays;
   - sin "datos-como-código" (heurística de entropía/decodificación).
9. **Empezar por el runtime genérico** (N64ModernRuntime + RT64) y añadir por juego solo lo custom:
   microcódigos RSP propios, loaders/compresión propios, comportamientos de motor.

## 3. Sobre "necesito el motor recompilado del mismo estudio"

No es un requisito. N64Recomp **traduce código** de forma genérica; el runtime genérico cubre
libultra. Reutilizar un repo del **mismo motor** (p. ej. Goemon para el motor Nisitenma-Ichigo de
Konami) ahorra tiempo, pero **no** sustituye el trabajo per-file del juego propio. Cualquier juego
N64 es **técnicamente recompilable**; el esfuerzo depende de cuánto código custom tenga
(microcódigos, loaders, scheduling).

## 4. Señales de alarma (si aparecen, revisar el enfoque)

- "Solo necesito estos N ficheros" → verifica contra la tabla.
- `Failed to find function` intermitente al avanzar de escena → seguramente falta un overlay.
- Funciones que retornan con `sp` distinto (fugas) → fronteras/mid-entries mal cortados.
- `do_break`/`syscall`/`mthi` en regiones raras → datos-como-código.
- Parches por dirección (`add_mid_entry`, `module_extras`) acumulándose → síntoma de base incompleta.
- Un overlay parece "funcionar mal" solo a veces → solape de bases no gestionado.

## 5. Checklist de arranque para un juego nuevo

- [ ] Extraer tabla de assets + tabla de VRAM (bases por fichero).
- [ ] Instalar runtime genérico (N64ModernRuntime + RT64) desde un proyecto del mismo motor o base.
- [ ] Enumerar y extraer **todos** los code files.
- [ ] Desensamblar per-file (Ghidra/decomp) → syms por sección.
- [ ] `relocatable_sections_path` completo + hooks de loader (todos).
- [ ] Resident `.text` sin solapes.
- [ ] Checks de completitud.
- [ ] Versionar el C recompilado.
- [ ] Documentar deps de **build** vs de **recompilación** por separado.
