# Visión y roadmap — Hybrid Heaven: Recompiled

> **Documento de visión (no vinculante).** Describe *hacia dónde* va el proyecto a largo plazo.
> El estado y las fases actuales están en `../PROYECTO.md`; las tareas, en `../TODO.md`; el modelo
> técnico, en `architecture.md`.
>
> ⚠️ **La estrategia de cobertura nativa NO es todavía una decisión formal.** Cuando se adopte, se
> registrará como **ADR 0009** (ver `TODO.md`). Hasta entonces, esto es una guía, no un contrato.

## 1. Objetivo

Port nativo a PC de **Hybrid Heaven** (N64, Konami/KCEO, 1999) por **recompilación estática**
(N64Recomp + RT64 + N64ModernRuntime), leyendo la ROM del usuario. Sub-objetivo obligatorio:
**extraer y traducir todos los textos**. Plataformas: Windows + Linux + Steam Deck.

**Visión a largo plazo:** ir sustituyendo progresivamente el **código recompilado** (derivado de la
ROM) por **C propio, moderno y entendible**, función a función, hasta que el código original deje de
ser necesario. Es el modelo que siguieron OpenTTD (Transport Tycoon) u OpenRCT2: se reescribe por
partes hasta poder prescindir del original.

## 2. Estrategia: cobertura nativa progresiva

El recomp es el **andamiaje**; encima se sustituyen piezas:

1. **Funciones reimplementadas** (`reimplemented_funcs` del toolchain, ADR 0002): sustituir una
   función guest por C nativo.
2. **Hooks / wrappers** (runtime, `get_function`): interceptar funciones y sustituir cuerpo o salida.
3. **Runtime** (`N64ModernRuntime`): reimplementa el hardware/libultra; cada vez más lógica vive aquí.
4. **Port** (`port/HybridHeavenRecomp/src/`): glue y módulos que sacan el juego de la ROM
   (p. ej. la Fase B: `trans_cache.cpp` reemplaza el loader `FUN_80003824`).

Ejemplo de referencia: la **Fase B** ya bypassa un bloque grande de lógica del juego con C nativo.

## 3. Modelo legal (código vs datos)

Lo que sostiene el proyecto y hay que preservar:

- **No se distribuyen la ROM ni assets del juego.** El usuario aporta su copia (checksum en
  `README.md` del repo).
- **Datos derivados = locales.** El cache/formato convertido se genera en la máquina del usuario al
  primer arranque y **no se versiona ni se distribuye** (`.gitignore`).
- **El código sí es derivado.** El C recompilado (y lo reimplementado *a partir* de él) es obra
  derivada del código de la ROM; exigir la ROM cubre los **datos**, no el **código**.
- **Norte para desacoplar el código:** reimplementación **clean-room** (a partir de comportamiento,
  sin derivar del original). Es el único camino que hace el código independiente.

> No es asesoría legal. Para un release público, revisión legal y, si procede, priorizar clean-room.

## 4. Criterios para decidir qué se reimplementa primero

1. **Rendimiento**: bucles calientes (p. ej. el decodificador `0x80015A64`/`0x80016xxx`).
2. **Corrección/bloqueos**: donde el recomp diverge del original (CaC, etc.).
3. **Valor de producto**: subsistemas que el objetivo necesita (texto/traducción, audio, guardado).
4. **Desacople**: piezas necesarias para reducir dependencia de la ROM.
5. **Riesgo**: empezar por funciones con contrato claro (entrada/salida verificable).

## 5. Métrica y manifiesto (a definir)

Para no perder el hilo entre sesiones:

- **Manifiesto de funciones reimplementadas** (dirección → estado → nota/ADR).
- **Métrica de cobertura nativa** (p. ej. % de llamadas servidas por código propio).
- Se concretarán al adoptar el ADR 0009.

## 6. Qué NO hacer

- ❌ Editar a mano el C generado (`RecompiledFuncs/`): se regenera.
- ❌ Distribuir ROM, assets o datos derivados.
- ❌ Añadir capas sin documentar el "por qué" en `notes/`.
- ❌ Reimplementar sin criterio (hay que priorizar por §4).

## 7. Enlaces

- Estado y fases: `../PROYECTO.md` · Tareas: `../TODO.md`
- Modelo técnico: `architecture.md` · Decisiones: `adr/`
- Cómo documentar: `documentation.md`
- Plan maestro histórico (congelado): `../notes/archive/2026-09-18-plan-maestro-legacy.md`
