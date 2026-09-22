# Notas de release

Un fichero por tag: `docs/releases/<tag>.md` (p. ej. `v0.3.0.md` para el tag `v0.3.0`).

- La **primera línea** debe ser un encabezado `# <título del Release>`; `release.yml` lo usa como
  **título** del Release.
- El resto del fichero son las **notas** (markdown), que se publican tal cual.
- Si **no** existe el fichero para un tag, el workflow genera notas automáticas y titula con el tag.

**Convención de título**: `vX.Y.Z - <descripción corta>` (evitar "anchor" en vez de "anchoring";
`sentence case`; `&` permitido).

Estos ficheros son **documentación** (se versionan); editar el de un tag ya publicado **no** cambia
el Release existente (habría que editarlo en GitHub).
