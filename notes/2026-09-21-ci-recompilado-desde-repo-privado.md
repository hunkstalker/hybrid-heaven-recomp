# 2026-09-21 — CI con el C recompilado desde un repo privado de secretos

> Nota de decisión/implementación. Cierra el fallo de `ci.yml` tras ADR 0009 (el C recompilado dejó
> de versionarse) y el choque con ADR 0005 §6 (el CI compilaba porque el C estaba versionado).

## 1. El fallo

`docker build` fallaba en CMake:

```
CMake Error: Faltan build/recomp/RecompiledFuncs/funcs_*.c. El C recompilado NO se versiona (ADR 0009).
```

El `.exe`/binario **se compila sin la ROM**, pero el **C** que hay que compilar es obra derivada que
no se versiona (ADR 0009). El CI no tenía de dónde sacarlo.

## 2. Cómo lo hacen otros (verificado en sus repos)

- **Zelda64Recomp** (`validate.yml`): clona un **repo privado** (`secrets.ZRE_REPO_WITH_PAT`), compila
  N64Recomp+RSPRecomp en el runner y **recompila** desde la ROM/ELF del repo privado.
- **Goemon64Recomp** (`validate.yml`): `git clone secrets.G64RS_REPO_WITH_PAT` → `cp ./…Secrets/* ./`.
- La referencia no tiene CI; publica binarios de forma manual.

Patrón común: **repo privado + PAT** (no un secret de Actions: el límite de un secret es **48 KB** y la
ROM/C no caben).

## 3. Decisión (implementada)

- `ci.yml`: los jobs `linux`/`windows` **traen** `RecompiledFuncs/` de un repo privado de secretos,
  clonado con un PAT, y lo copian a `build/recomp/RecompiledFuncs`.
- Configuración: variable `HH_SECRETS_REPO` (por defecto `hunkstalker/hh-recomp-secrets`) + secreto
  `HH_SECRETS_PAT` (fine-grained, `Contents:Read` sobre ese repo).
- **Sin PAT, los builds se saltan** con `::warning` (CI verde); el job `docs` sigue validando.
- `.dockerignore`: excepción `!build/recomp/RecompiledFuncs` para que el C entre en el contexto de la
  imagen (va después de las reglas que excluyen `build`).
- Legal: el repo privado almacena ROM/C (no se distribuye); el repo público queda sin datos del juego.

## 4. Setup (mantenedor, una vez)

1. Crear el repo **privado** `hunkstalker/hh-recomp-secrets`.
2. Generar el C localmente (`python3 tools/regenerate.py`) y **publicar** en ese repo:
   ```sh
   cd build/recomp
   # copiar RecompiledFuncs/ al clon del repo privado y push
   ```
   (También se puede subir la ROM y regenerar en CI; aquí se publica el C para que el CI sea rápido.)
3. Crear un **PAT fine-grained** con `Contents: Read` sobre ese repo.
4. En el repo público: **Settings → Secrets and variables → Actions**
   - Variable: `HH_SECRETS_REPO` = `hunkstalker/hh-recomp-secrets` (opcional si se usa el nombre por
     defecto).
   - Secreto: `HH_SECRETS_PAT` = el PAT.
5. Re-lanzar el workflow (push o `workflow_dispatch`).

## 5. Mantenimiento

Cada vez que cambien símbolos/config de recompilación: `tools/regenerate.py` local → re-publicar
`RecompiledFuncs/` en el repo privado → push. El CI tomará la versión nueva.

Pendiente (opcional): script `tools/publish_recompiled.sh` que automatice la publicación; un job de CI
que regenere desde una ROM del repo privado en vez de usar el C pregenerado.
