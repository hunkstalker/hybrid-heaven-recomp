# 2026-09-16 — Guardado en cápsula VALIDADO en Windows

Cierre del hito de guardado (Controller Pak). El fix descrito en
`notes/2026-09-16-guardado-capsula-pak-y-crash-cac-8021d8d0.md` queda **validado por el usuario en
Windows**: el guardado desde la cápsula funciona de principio a fin (100 %).

## Qué se corrigió

La causa raíz era `osPfsFindFile`: la libultra del ROM devuelve **5** con `*file_no = -1` cuando no
existe el fichero (no 10). El wrapper del juego (`FUN_80002DBC`) trata **cualquier retorno >= 6 como
éxito sin rellenar el `file_no`**, así que con 10 el juego creía que su fichero existía y escribía
con un `file_no` basura (95/233/237) → `PFS_ERR_INVALID` → "Could not save".

Fix en el fork del runtime (commit reescrito `0619945…`):

- `osPfsFindFile`: no encontrado → `*file_no = -1` y retorno **5**.
- `osPfsDeleteFile`: no encontrado → **5**.
- `osPfsAllocateFile`: sin espacio → **9**.

(El intento previo de "pak virgen → `PFS_ERR_NEW_PACK`" quedó descartado y opt-in con
`HH_PAK_NEWPACK=1`.)

## Verificación

- **Windows (usuario)**: en la cápsula sale la **UI de slots** y el guardado **completa**; el `.pak`
  queda en `saves\` junto al `.exe`.
- Marcadores esperados (instrumentación `hh_pak.log`, activa por defecto): `osPfsInitPak -> 0`,
  `osPfsFindFile -> 5` cuando no hay fichero y `osPfsAllocateFile ... size=13568` al crear el fichero.

## Referencias

- Diagnóstico original: `notes/2026-09-16-guardado-capsula-pak-y-crash-cac-8021d8d0.md`.
- Estado y tareas: `TODO.md`, `PROYECTO.md`, `RETOMAR.md`.
