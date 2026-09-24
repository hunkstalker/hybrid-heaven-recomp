# Cómo documentar este proyecto (guía de documentación)

> **Documento vivo y normativo.** Define *dónde* y *cómo* se documenta todo a partir de ahora.
> Toda sesión nueva debe leerlo junto con `../AGENTS.md`. Si algo contradice esta guía, gana esta guía.

## 1. Principio

Documentamos para **recuperación**, no para completitud: pocos documentos vivos, enlazados, y un
histórico que no compite con la verdad actual. El objetivo es que una sesión nueva arranque con
**3 archivos cortos** y que el detalle profundo se lea solo al investigar un tema concreto.

**Una sola fuente de verdad por tema.** Si un dato está en dos sitios, se borra de uno y se enlaza.

## 2. Dónde va cada cosa (fuente de verdad)

| Tema | Documento | Naturaleza |
|---|---|---|
| Arranque de sesión (reglas, comandos, orden de lectura) | `../AGENTS.md` | vivo, corto |
| Contexto, estado y roadmap del proyecto | `../PROYECTO.md` | vivo, ≤2 pantallas |
| Tareas (única lista priorizada) | `../TODO.md` | vivo, corto |
| Punto de retomada de la sesión actual | `../RETOMAR.md` | vivo, corto (handoff) |
| Modelo técnico (memoria, `trans`, runtime) | `architecture.md` | vivo |
| Visión y roadmap a largo plazo (no vinculante) | `README.md` | vivo (puede quedar genérico) |
| Índice de toda la documentación | `INDEX.md` | **generado** (`tools/analysis/docs_index.py`) |
| Decisiones de arquitectura | `adr/NNNN-*.md` | **inmutable** |
| Evidencia, diagnósticos, sesiones | `../notes/YYYY-MM-DD-*.md` | **histórico, no se edita** |
| Docs legacy congelados | `../notes/archive/` | histórico |
| Datos generados (syms, manifests) | `../notes/reference/` | generado |

Los **datos generados** (manifiestos, listas de funciones, etc.) se producen localmente a partir de la
ROM que aporta el usuario y **no se versionan**: no hacen falta para compilar ni para jugar.

Regla: **`../notes/` nunca es fuente operativa.** No se corrige una nota antigua; se escribe una nueva.

## 3. Ciclo de sesión

**Al empezar** (solo esto):
1. `../AGENTS.md` → 2. `../RETOMAR.md` (tarea de la sesión) → 3. `../PROYECTO.md` → 4. `../TODO.md`
→ 5. `architecture.md` si hay trabajo técnico. Bajo demanda: `adr/`, `../notes/` (solo la relevante).

**Durante**: los hallazgos van a la **nota del día** (`../notes/YYYY-MM-DD-<tema>.md`), no a los docs
vivos. Las decisiones, a un ADR (ver §4). Los cambios de estado, a `../PROYECTO.md`/`../TODO.md`.

**Al cerrar** (checklist):
- [ ] `../TODO.md`: marcar lo hecho y añadir lo nuevo (priorizado).
- [ ] `../PROYECTO.md`: actualizar estado/fecha si cambió.
- [ ] Una **nota fechada** con el detalle (evidencia), aunque no haya éxito.
- [ ] Si hubo una decisión estructural → **nuevo ADR**.
- [ ] Si un doc vivo creció demasiado → dividir y archivar (§6).
- [ ] No commitear salvo que el usuario lo pida.

## 4. Cuándo crear un ADR

Un ADR (`adr/NNNN-titulo.md`) es para decisiones que **afectan estructura, contratos o
plataforma** y son **costosas de revertir** (p. ej. modelo de módulos, pipeline de símbolos, elección
de runtime). Formato: *Estado · Contexto · Decisión · Consecuencias · Alternativas · Criterio de salida*.

- Un ADR **aceptado no se edita**; se supersede con otro que lo referencie.
- Una idea o plan no es un ADR hasta que se decide. Si se prevé una decisión futura (p. ej. la
  estrategia de cobertura nativa en `README.md`), se anota como **tarea en `../TODO.md`** ("definir
  ADR NNNN cuando…") y el ADR se crea el día que se decide. No se crean ADRs "en borrador".

## 5. Estilo y tamaño

- `../PROYECTO.md` ≤ ~2 pantallas; `../TODO.md` corto y priorizado; ADR ~1 página (guía editorial, sin
  verificación automática por fichero).
- **Presupuesto de arranque (lo único verificado)**: el **total** de los docs que se leen al empezar
  sesión (`AGENTS`+`RETOMAR`+`PROYECTO`+`TODO`+`documentation`+`architecture`, ver `../AGENTS.md`
  §Lee esto) no debe superar `STARTUP_BUDGET_TOKENS` (def. 30k tokens ≈ 120 KB) en
  `tools/analysis/docs_index.py`; si se supera, `--check` falla. Objetivo: no volver a consumir un %
  alto del contexto al ponerse al día (hubo una época con ~30 %).
- Preferir tablas y listas; un dato, un sitio.
- Enlazar con rutas relativas; **no dejar enlaces colgantes** (si borras/mueves un archivo, corrige
  las referencias en los docs vivos).
- No pegar logs enteros en docs vivos; van a `../notes/` y se resume.

## 6. Consolidación y archivo

Cuando un doc vivo se congestione: se **recorta** (queda la verdad actual) y el contenido previo se
**congela** en `../notes/archive/FECHA-<nombre>-legacy.md` con una cabecera `> ARCHIVO HISTÓRICO`.
Precedente: consolidación del 2026-09-11 (`../notes/archive/2026-09-11-sesion-legacy.md`,
`../notes/archive/2026-09-11-proyecto-legacy.md`).

## 7. Anti-patrones (evitar)

- ❌ Duplicar estado en varios sitios (p. ej. un `sesion.md` gigante en paralelo a `../PROYECTO.md`).
- ❌ Apéndices infinitos: añadir sección tras sección a un doc vivo.
- ❌ Editar notas históricas para "actualizarlas".
- ❌ Editar a mano el C generado (`RecompiledFuncs/`); todo fix va a `config/*.syms.toml`.
- ❌ Dejar enlaces a documentos eliminados.
- ❌ Documentos que solo tienen sentido leyendo otro en tiempo real (handoffs monolíticos).
