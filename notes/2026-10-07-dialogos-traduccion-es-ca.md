# 2026-10-07 — Traducción del diálogo (es/ca): tandas 12-17 y fix de espacios extremos

> Evidencia de la sesión. Normativa: `docs/traduccion.md`; decisión: ADR `0016`. Handoff: `RETOMAR.md`.

## Resultado

- **Traducidos completos (es + ca)**: módulos **12, 13, 14, 16, 17**.
- **Parcial**: módulo **27** (46/109 mensajes, de la sesión previa).
- **Cobertura (solo diálogo, 27 escenas)**: **262/872 mensajes ≈ 30.0 %**; **668/2173 líneas únicas
  ≈ 30.7 %**.
- Validado con `tools/text/check_dialogue_fit.py` (`es`/`ca`): **0 problemas** en los módulos hechos.

## Fix del motor (bug de cobertura)

- **Síntoma**: 26 líneas del alcance traen **espacios al inicio/final** en la ROM (p. ej. módulo 12
  `changers are top secret, `). El parser de `.txt` (`load_file`) **recorta** las claves, pero
  `translate_euc()` no recortaba la clave decodificada → **no casaban** y quedaban en inglés.
- **Fix**: recorte de espacios extremos en `translate_euc()` (`src/subsystems/text.cpp`) y en
  `check_dialogue_fit.py` (mismo criterio; espacios interiores intactos). **Compila en Linux**.
- **Repaso in-game pendiente**: verificar `changers are top secret, ` (m12) y representativas
  (`    in the end.` m38, `An intelligent, ` m14) en la validación visual del mantenedor.

## Decisiones de localización (mantenedor)

- **Registro**: seguir el **DE/FR oficial por personaje** — Mr. Diaz formal (*Sie/vous* → usted/vostè);
  villanos, Gargatuan y Navigator informales (*Du/tu* → tú/tu).
- **Catalán formal**: **`vostè`** (no `vós`); corregido el catalán de Mr. Diaz.
- **Términos** (regla: traducir si DE/FR lo hacen): **`Gargatuan`** se mantiene; **Navigator →
  Navegante/Navegant** (el FR lo traduce; el DE lo mantiene); **Hybrid → Híbrido/híbrid** (DE/FR);
  **Master → Maestro/Mestre**; **`defuser`** se mantiene (DE/FR no lo traducen); **`OPTIONS`** se
  mantiene. **Créditos (m14 m79) y la línea m17 m39 quedan en inglés** (por indicación del mantenedor).
- **Presupuesto A+ estricto** (= caracteres del mensaje inglés). Muchas propuestas del mantenedor
  exceden; se aplican **versiones concisas** y sus textos completos quedan volcados en
  **`/app/dialogos.txt`** (fuera del repo) junto con la versión aplicada.

## Herramientas / artefactos

- **`/app/dialogos.txt`**: volcado EN/ES/CA de los módulos 12, 13, 14, 16, 17 con las **correcciones del
  mantenedor** (texto principal) y, cuando no caben, la **versión aplicada**.

## Pendiente

- Módulos **18, 19, 20, 21, 26, 28, 29, 30, 31, 32, 33, 37, 38, 40, 42, 43, 44, 45, 47, 48, 50, 52, 53**
  y **terminar el 27**.
- **Validación visual en Windows** (mantenedor): tildes/ñ/¿/¡ correctos, sin inglés mezclado.
