# Hybrid Heaven Recomp (N64 → PC port)

Port a PC de **Hybrid Heaven** (N64, Konami Computer Entertainment Osaka, proyecto interno
**RZ011**) por **recompilación estática** con el stack N64Recomp + RT64 + N64ModernRuntime.
Plataformas objetivo: **Windows, Linux y Steam Deck**.

- **`PROYECTO.md`** → contexto maestro: motor Konami confirmado (tabla Nisitenma-Ichigo +
  LZKN64), mapa de la ROM, decisiones de arquitectura, roadmap y riesgos. **_Actualizar aquí
  en cada sesión._**
- **`docs/README.md`** → plan maestro, fases, stack y riesgos (detallado).
- **`notes/`** → notas de sesión e manifests de extracción (US/EU).
- **`tools/`** → herramientas propias (extracción de assets, shim LZKN64, análisis); ver
  `tools/README.md`.
- **`work/`** y **`toolchain/`** → artefactos derivados y herramientas, **gitignored**
  (ROMs del usuario descomprimidas, proyecto Ghidra, toolchain). El repo versionado queda
  limpio de assets (modelo No-Intro): el port requiere la ROM del usuario en runtime.

Estado actual (2026-09-10): portado/recompilación en curso (Fase 2) — el port **compila y hace boot**
(Linux y Windows) con el set unificado; el juego **aún no renderiza**: thread 5 (game loop) se clava en
`osRecvMesg(0x8005be40)`. **Causa raíz confirmada (herramienta `n64sym`)**: la syms solo mapea 11 os
funcs; la mayoría de los os funcs libultra están como `FUN_xxx`, por lo que el recompilador los compila
como código de juego y el juego usa su propio `osSetTimer` (mecanismo cop0 Compare no emulado por el
runtime) → el timer no dispara → thread 5 colgado. **Solución**: renombrar los `FUN_xxx` → os funcs con
los vrams de `n64sym`. Para el estado exacto y TODO, leer **`sesion.md` §16 primero**; detalle:
`notes/2026-09-10-n64sym-osfuncs-rootcause.md` y `notes/reference/n64sym_osfuncs_us_retail.txt`.