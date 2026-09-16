# 2026-09-16 — Limpieza de rutas/referencias y pipeline de compilación (ejecución del plan)

Nota de sesión. Ejecuta el plan consolidado
`notes/2026-09-16-plan-proxima-sesion-limpieza-rutas-y-build.md` por bloques 1 → 7; el bloque 8.B
(reescritura de identidad, destructivo) se prepara al final y los `force-push` los lanza el usuario.
Decisión estructural: **ADR 0006** (`docs/adr/0006-politica-de-rutas-relativas-y-contenido-externo.md`).

## Bloque 1 — Rutas y referencias

**Regla aplicada**: en todo lo publicado (docs vivos, `notes/`, `config/`, mensajes) se usan **rutas
relativas al repo**; se elimina cualquier ruta absoluta del entorno, ruta temporal del sistema,
unidad Windows, identidad local del entorno de desarrollo y nombres de fichero del proyecto de
referencia de Konami. Los forks se citan por **URL pública** y `docker/` conserva lo relativo a la
imagen Docker del proyecto.

Hecho:

- `AGENTS.md`: la regla de persistencia ya no cita rutas ni el entorno; ahora dice que **lo importante
  vive dentro del repo, bien clasificado** y que lo que deba conservarse se guarda en el repo.
- `PROYECTO.md`: se quitan las filas de identidad de la ROM (rutas/hashes) y se generaliza §4.
- `notes/` + `notes/archive/` (32 ficheros): rutas absolutas → relativas; rutas temporales →
  `work/debug/`; identidades locales → redacción neutra; "contenedor" narrativo → "entorno de
  desarrollo"; nombres de fichero del proyecto de referencia → frase neutra.
- `config/us_module*.syms.toml`: cabeceras `# Módulo: ...` con ruta relativa.
- `tools/README.md`, `docs/workflows.md`, `work/README_captura.md`: ejemplos relativos.
- `.dockerignore`: eliminada la entrada del tooling local; **`.opencode/` borrado del repo**
  (`git rm -r`). Cero cadenas de ese tooling en lo publicado.
- `docs/documentation.md`: nota sobre datos generados (se producen localmente y no se versionan).

Pendiente en bloques siguientes: los scripts (`tools/analysis/*`, `work/*.sh`) y el runtime
(`events.cpp`) llevan raíz derivada del propio fichero / rutas relativas (Bloque 4).
