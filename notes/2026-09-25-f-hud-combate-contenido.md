# HUD de combate: anclaje por CONTENIDO, no por dirección (issue #3)

> Fix de `hunkstalker/hybrid-heaven-recomp#3` («A partir del 2º combate — HUD de combate
> desplazado»). Headless + tests deterministas; **falta validar en Windows 1º/2º combate**.

## Síntoma (del issue)

Con widescreen, el HUD de combate debe anclarse **entero** a la izquierda. En el **1er combate** sí;
**desde el 2º**, solo se anclan los **rellenos** (barras POWER/STAMINA) y el resto (franjas/estructura
y etiquetas) se queda en 4:3.

## Causa

`hud_rewrite::class_of()` (`src/hooks/hud_rewrite.cpp`) ancla un elemento solo si su *identity* casa
con una tabla fija. Las identidades de textura son `tex:<dirección>#<hash64B>` (`include/hh/hudid.h`):
incluyen la **dirección RDRAM**. El módulo de combate (file 57) se **carga/descarga en cada
encuentro** y sus gráficos viven en memoria dinámica → la dirección **cambia por combate** → la
identity deja de casar → el elemento no se ancla. Los rellenos se salvan por usar identity
**posicional** (`fill:color@coords`). La referencia ya lo avisa: *"direct/arena addresses are not
identities"*.

## Fix (Vía A del issue)

Clasificar las texturas del HUD de combate por el **hash de contenido** (primeros 64 B de la imagen),
que es lo que identifica el gráfico, **ignorando la dirección**.

- `include/hh/hudid.h`:
  - `texture_hash(rdram, phys)`: FNV-1a de los primeros 64 B (extraído de `texture()`).
  - `parse_hash(identity, out)`: extrae el sufijo `#hhhhhhhh`.
  - `texture()` sigue devolviendo `tex:<dirección>#<hash>` (la dirección se conserva para el trace).
- `src/hooks/hud_rewrite.cpp` (`class_of`): las 6 texturas de combate POWER/STAMINA se sacan de la
  tabla exacta y se clasifican por **hash de contenido** (solo para identidades `tex:`). El radar
  (`tex:`/`dl:`), el mapa (`fill:`/`dl:`) y el prefijo posicional de los rellenos siguen igual.

## Verificación (headless, determinista)

- `class_of`: los 6 hashes de combate en dirección vieja y en direcciones nuevas (arbitrarias) →
  `kLeft`; radar/mapa/fills intactos; `tex`/`dl` desconocidos → `kAuto`.
- `texture_hash`/`parse_hash`: mismo contenido en direcciones distintas → mismo hash; contenido
  distinto → hash distinto; `texture()` mantiene la dirección en la cadena.
- Build Linux OK.

## Pendiente / riesgo

- **Validar en Windows**: 1º y 2º combate (que el HUD se ancle entero), más una escena de control
  (intro / Expansion Pak) para descartar falsos positivos. Con `HH_HUD_REWRITE_TRACE=1` se ven las
  identidades clasificadas (dirección nueva + hash) en cada combate.
- **Over-match**: si otra imagen compartiera los primeros 64 B, se colaría. Con estos hashes es
  improbable; si apareciera, endurecer exigiendo además la **extensión 320x240** del draw (como el
  prefijo de los rellenos). La infraestructura ya expone el hash por separado.
- Si el contenido del gráfico también cambiara por combate, habría que ir a las vías C/D del issue
  (hook del loader / clasificación posicional).

## Alternativas (del issue)

B (caché dinámica hash→dirección), C (hook del loader), D (clasificación posicional). Se eligió A por
no añadir estado en runtime ni acoplarse al pipeline de carga. No se crea ADR: el **formato** de las
identidades no cambia, solo se añade una clave de clasificación por contenido (mismo patrón que la
fase 07, documentada en notas).
