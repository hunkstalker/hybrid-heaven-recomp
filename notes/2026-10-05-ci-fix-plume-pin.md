# 2026-10-05 — CI roto por pin de plume no publicado (release v0.7.0) — ARREGLADO

> Estado: **arreglado** (pendiente push: primero el fork RT64, luego `main`). Ámbito: **dependencias/CI**,
> no código de juego. **MEDIDO** con `git ls-remote`/`git ls-tree` y los logs de CI.

## Síntoma

El CI (Linux Docker y Windows) fallaba al clonar limpio:

- Linux: `fatal: remote error: upload-pack: not our ref 71fd3442...`, en `src/contrib/plume`.
- Windows: configure de CMake incompleto (RT64 sin `plume`).

## Causa (cadena de pins)

```
main ──(gitlink + runtime.lock)──► hunkstalker/rt64 @ 7c46232    [publicado ✓]
                                    └─ .gitmodules: src/contrib/plume → renderbag/plume (upstream)
                                       gitlink de plume = 71fd344    [NO existe ahí ✗]
```

- `7c46232` (gate de escala #6) es hijo de `5b11988`, que fijó el submódulo `plume` al commit
  `71fd344` del fork `hunkstalker/plume`, **nunca publicado** (404), sin actualizar `.gitmodules`
  (que sigue apuntando a `renderbag/plume`).
- En local no se notó porque el submódulo ya estaba en disco; CI clona limpio → falla.
- v0.6.2 no fallaba porque fijaba RT64 `a8f0a70`, cuyo plume era **upstream** `d890ac8`.

## Fix (B: volver plume a upstream)

En el fork `lib/rt64`, commit `234151a` (hijo de `7c46232`): `src/contrib/plume` vuelve a `d890ac8`
(upstream, el plume que ya usaba v0.6.2). **No** se toca el gate de escala ni el código de
interpolación. `main` sube el pin (`lib/rt64` gitlink + `runtime.lock RT64_COMMIT`) a `234151a`.

**Por qué no A**: conservar el parche de plume (`71fd344`, 9 líneas, cierre limpio) exigiría publicar un
fork de plume y repuntar `.gitmodules`; se evita un 4.º fork. El cierre limpio no depende de ese parche:
v0.6.2 se publicó sin él (`_exit(0)` en `src/platform/main.cpp`), y `README.md` ya lo afirmaba entonces.
El commit `71fd344` **no se borra**: sigue en la rama local `hybrid-heaven` de plume por si se publica
un fork público y se reincorpora (tarea futura).

## Validación / siguiente

- `docs_index.py --check` OK; build Linux incremental OK.
- **Push (orden)**: `git -C lib/rt64 push fork hybrid-heaven` → `git push origin main`. El pin de
  `main` (`234151a`) no existirá en el fork hasta el primer push.
- Pendiente reincorporar el fix de shutdown de plume (opción A) cuando se cree el fork público.
