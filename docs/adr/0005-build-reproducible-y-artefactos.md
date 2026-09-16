# ADR 0005 — Runtime en forks propios y build reproducible

- **Estado**: Aceptado (2026-09-16).
- **Fecha**: 2026-09-16
- **Contexto relacionado**: ADR 0001, ADR 0002, `../../PROYECTO.md` §2/§5, `../../tools/build_linux.sh`,
  `../../port/build_windows.bat`, `../../port/runtime.lock`, `../../Dockerfile`,
  `../../.github/workflows/`, `../../CREDITS.md`,
  `../../notes/2026-09-16-runtime-en-forks-y-build-reproducible.md`.

## Contexto

El port modifica **dos repos de terceros** que no se versionan aquí (gitignored):

- **N64ModernRuntime**: 23 commits locales (VI desde la ROM, registro dinámico de módulos,
  mesgqueue/threads, Controller Pak, `MEM_*` seguro para direcciones no mapeadas, instrumentación de
  diagnóstico y el fix `s0`).
- **N64Recomp** (submódulo de NMR que `librecomp` **compila** dentro del port): `include/recomp.h`
  (`MEM_*` seguro + watchpoint) y `src/symbol_lists.cpp` (PFS reimplementado).

La receta original era “clonar upstream + `checkout fd6b0d0` + aplicar
`windows_runtime_changes.patch`”. Al preparar el build reproducible se comprobó que **`fd6b0d0` es un
commit local** (nunca publicado; `origin/main` es su ancestro), así que **ningún clon limpio podía
reproducirla**, y que el patch (`diff fd6b0d0..HEAD`, generado con `--ignore-submodules=all`) **no
cubría los cambios del submódulo N64Recomp**. Además, los 23 commits locales vivían en un **HEAD
detached** (sólo alcanzables por reflog).

Por otro lado, el port no debe distribuir **datos del juego**: el repo llegó a versionar imágenes
del juego (capturas, iconos/logo) y **datos extraídos de la ROM** (manifiestos, mapa de assets, dump
de símbolos). Eso se ha **purgado de todo el historial**. El **código del port** (incluido el C
recompilado y el ucode, que son el propio programa) **sí se versiona**, para poder compilar el `.exe`
sin la ROM (modelo de Zelda64Recomp/Goemon64Recomp): el `.exe` obtiene los datos de la ROM del usuario
en runtime.

## Decisión

1. Publicar los cambios como **forks reales** de GitHub, con **`main` = upstream** (lineage y crédito
   intactos): `hunkstalker/N64ModernRuntime` (rama `hybrid-heaven`) y `hunkstalker/N64Recomp`
   (rama `hybrid-heaven`).
2. El build **clona por URL+SHA fijados en `port/runtime.lock`** (las variables de entorno
   `NMR_URL`/`NMR_COMMIT` permiten apuntar a otro fork). **Sin patch y sin snapshot**; los submódulos
   se resuelven recursivamente (`N64Recomp` desde el fork vía `.gitmodules`; `thirdparty`, de upstream).
3. **`rt64`** no se modifica: se clona de su upstream en un commit fijo.
4. La **ROM nunca** entra en el repo, la imagen, los artefactos ni el CI: la aporta el usuario.
5. Las herramientas de **regeneración** (`toolchain/src/N64Recomp`, 13 archivos modificados) quedan
   fuera del build; si se quiere reproducir la regeneración, se añadirá una segunda rama
   (`hybrid-heaven-tool`) en el fork de N64Recomp.
6. **No versionar datos del juego** (ROM, imágenes/capturas, textos/manifiestos extraídos). Sí se
   versiona **el código del port** (incluido `RecompiledFuncs/` y `rsp/hh_aspMain.cpp`), de modo que el
   `.exe` **se compila sin la ROM**. El binario, **al ejecutarse, busca la ROM del usuario**
   (`rom/baserom.us.z64` o junto al ejecutable/CWD) y extrae de ella los datos. Los datos de fuentes
   (símbolos) se regeneran con la ROM solo cuando un mantenedor toca los símbolos.

## Consecuencias

- Repositorio **sin datos del juego** (ROM/assets/textos extraídos) y **con el código del port**: el
  `.exe` se compila sin ROM; para **jugar** basta con descargar el binario de *Releases* y aportar la
  ROM. Nadie está obligado a compilar.
- **Un solo flujo de compilación** ("build once, promote"): `ci.yml` compila (Linux por Docker y
  Windows) y sube **artefactos**; `release.yml` los descarga y publica (exige un run de CI **verde**
  de ese commit) más la imagen `ghcr.io` montada desde el propio binario. No se compila dos veces
  (ahorra minutos, que en repo privado cuentan).
- Crédito y lineage conservados: los forks muestran “forked from …”, incluyen su `COPYING`
  (NMR, GPL-3.0) y se documentan en `CREDITS.md`.
- Mantenimiento: los cambios del runtime se hacen en el árbol local y se **pushean al fork**, y luego
  se actualiza el SHA del lock. Actualizar desde upstream = `merge upstream/main` en el fork.
- El primer clon necesita red (los forks son públicos). Para offline habría que cachear el clon.
- Los binarios enlazan NMR (**GPL-3.0**): la distribución debe cumplir la licencia (fuente + avisos).
  Pendiente decidir/añadir el `LICENSE` del proyecto (`TODO.md`).

## Alternativas descartadas

- **Patch con base local** (estado previo): no reproducible (commit nunca publicado) e incompleto
  (no cubre el submódulo N64Recomp).
- **Snapshot vendorizado** (`.tar.gz` en el repo): reproducible y offline, pero es un artefacto
  derivado (+8,6 MB) que hay que regenerar; se implementó y se descartó en favor de los forks.
- **Repo mirror sin fork**: pierde el vínculo “forked from …” y el crédito.
- **Clonar upstream + patch contra un commit publicado**: frágil ante rewrites de upstream y
  necesitaría un segundo patch para N64Recomp.
- **Refactor para no tocar N64Recomp** (mover los macros `MEM_*` a una cabecera propia): obliga a
  envolver `recomp.h` y arriesga la portabilidad MSVC.

## Criterio de salida

- `tools/build_linux.sh` y `port\build_windows.bat` compilan **sin ROM**, clonando las dependencias
  por `port/runtime.lock`.
- El `.exe`/binario arranca pidiendo la ROM (`rom/baserom.us.z64` o junto al ejecutable/CWD).
- `git log --name-only` no muestra datos del juego (assets/capturas/manifiestos/dumps).
- CI compila Linux (Docker) y Windows y sube artefactos; un tag `v*` (o el lanzamiento manual)
  publica `.zip`/`.tar.gz` e imagen `ghcr.io` reutilizando esos artefactos (sin recompilar).
- **Pendiente**: para que terceros regeneren el C (si tocan símbolos), publicar la rama
  `hybrid-heaven-tool` del toolchain; y, opcional, selector de ROM tipo menú (hoy `rom/`).
