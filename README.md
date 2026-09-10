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
(Linux y Windows) con el set unificado; el juego **aún no renderiza**. **Progreso clave**: se
identificó la causa raíz (la syms solo mapeaba 11 os funcs; la mayoría de os funcs libultra estaban
como `FUN_xxx` → el recompilador los compilaba como código de juego → el juego usaba su propio
osSetTimer no emulado → thread 5 colgado en `osRecvMesg(0x8005be40)`). **Fix aplicado**: se mapearon
46 os funcs (vrams de `n64sym`) + `use_lookup_for_all_function_calls=false` → **thread 5 se desbloqueó**.
El boot progresa más pero crashea en el allocator de heap (límites de función del auto-detector).
Detalle: `notes/2026-09-10-n64sym-osfuncs-rootcause.md` (§5/§8) y
`notes/reference/n64sym_osfuncs_us_retail.txt`.