# ADR 0006 — Política de rutas relativas y contenido externo

- **Estado**: Aceptado (2026-09-16).
- **Fecha**: 2026-09-16
- **Contexto relacionado**: ADR 0005, `../../AGENTS.md`, `../../PROYECTO.md`,
  `../../docs/documentation.md`, `../../notes/2026-09-16-plan-proxima-sesion-limpieza-rutas-y-build.md`.

## Contexto

El repositorio es **público y comunitario**. Distintos documentos y scripts arrastraban rutas
absolutas del entorno de desarrollo (raíz de trabajo, temporales del sistema, unidades Windows) e
identidades locales, además de ficheros de un proyecto de referencia del mismo motor. Eso hace que lo
publicado no sea reproducible por terceros y filtra detalles que no aportan al proyecto.

## Decisión

1. **Rutas relativas a la raíz del repo** en todo lo publicado (docs vivos, `notes/`, `config/`,
   scripts, mensajes). Los scripts derivan la raíz de la ubicación del propio fichero; los ejemplos de
   los documentos usan rutas relativas.
2. **Lo importante vive dentro del repo, bien clasificado.** Los artefactos temporales pueden quedar
   fuera, pero lo que deba conservarse se guarda en el repo (`work/debug/` para diagnóstico). No se
   publican referencias a rutas temporales del sistema ni a identidades locales del entorno.
3. **Datos externos/fuera del repo**:
   - La **ROM** la aporta el usuario y se busca en `rom/baserom.us.z64` (carpeta `rom/`, junto al
     ejecutable) con **una** salvaguarda `baserom.us.z64` junto al `.exe`. Se elimina la búsqueda en el
     directorio de lanzamiento (CWD). Refina el punto 6 de ADR 0005.
   - Los cambios del runtime viven en **forks** citados por URL pública; no se citan rutas locales.
   - El proyecto de referencia de Konami se cita sin nombres de fichero.
   - Los **datos generados** (manifiestos, listas de funciones) no se versionan.
4. **Tooling local del asistente fuera del repo**; no se publican cadenas con su nombre.

## Consecuencias

- Un tercero puede clonar y compilar sin depender de rutas de la máquina del autor.
- Un único sitio (el lock y los scripts) fija las dependencias; los documentos solo describen.
- El contenido de datos del juego sigue fuera del repo (ADR 0005); esta decisión no lo altera.

## Alternativas descartadas

- Mantener rutas absolutas por comodidad: rompe la reproducibilidad y filtra el entorno.
- Mover los datos generados al repo: son derivados de la ROM y no hacen falta para compilar/jugar.

## Criterio de salida

- `git grep` no encuentra rutas absolutas del entorno, temporales del sistema, unidades Windows,
  identidades locales ni nombres de fichero del proyecto de referencia en ficheros publicados.
- `tools/build_linux.sh`, `port/build_windows.bat` y el arranque del binario funcionan con rutas
  relativas y `rom/baserom.us.z64`.
