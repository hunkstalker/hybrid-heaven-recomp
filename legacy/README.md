# legacy/ — documentación y artefactos del enfoque anterior (archivado)

Este directorio guarda la documentación y piezas del **enfoque de recompilación anterior**, que
resultó estar basado en una **extracción incompleta** (11 de 91 ficheros de código) y en decisiones
que provocaron una larga cadena de bugs (fugas de pila, corrupción de listas de suscriptores,
deadlocks en el combate, livelocks…).

**No es la fuente de verdad.** El proyecto se está **reconstruyendo con recompilación per-file
completa** (ver `../RETOMAR.md` y la documentación nueva en `../docs/`).

## Por qué se conserva
1. **Evidencia**: las notas documentan cómo se llegó a cada conclusión y con qué herramientas.
2. **Lecciones**: muchos errores y métodos son reutilizables al recompilar otros juegos.
3. **Trazabilidad**: el árbol actual conserva código/runtime válido; aquí queda el contexto de por qué.

## Contenido
- `RETOMAR.md` — punto de retomada del enfoque anterior (última sesión 2026-09-20).
- (irán llegando: `docs/`, `notes/`, `config/` obsoletos, `tools/` en desuso, bats de diagnóstico…)

## Lo que NO va aquí
Código o herramientas que sigan sirviendo con cambios mínimos (runtime del juego, `lzkn64`,
diagnóstico de RDRAM/emulador, bats de build, etc.). Eso se queda en el proyecto activo.

> La nota nueva `../notes/2026-09-20-lecciones-recompilacion-per-file.md` explica el error y la
> metodología correcta para futuras recompilaciones.
