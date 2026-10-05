# 2026-10-05 — Fase A: cobertura libultra (recompilar vs delegar al runtime)

> Rama `fase-a-libultra`, **mergeada en `main`** (ff). Auditoría + fix. **MEDIDO** salvo lo marcado.
> **VALIDADO en Windows (2026-10-05, mantenedor)**: lógica a 30 Hz (`hh_tick.log` 30,09 ticks/s, `d2`
> dominante), sin errores de lookup; velocidad/música normales. Excepción: una **regresión de cámara**
> **previa** (de las modificaciones de emparejamiento de ids), no de esta tarea → ver §Fase B (0).
>
> Continúa la línea de verificación de base iniciada en `2026-10-05-verificacion-base-jumptables.md`
> y `2026-10-05-lzkn64-compresor.md`. **Ver también Fase B al final** (interpolación; no se pierde).

## El riesgo

N64Recomp **no recompila** una función cuyo nombre está en sus listas `ignored_funcs`/
`reimplemented_funcs`: emite `<name>_recomp` y delega en el runtime. Si la función **no está nombrada**
en el ELF, N64Recomp la trata como código de juego y **recompila la copia del ROM**, que se ejecuta.

- N64Recomp conoce **361** nombres (ignored+reimplemented); nuestro ELF reconocía **47**.
- De esos 361, **129** tienen `_recomp` en librecomp (el runtime los provee → seguros de nombrar) y
  **232** no (nombrarlos reabriría el hueco → se dejan).

## Medición (tools/verify/audit_libultra.py, fingerprint_libultra.py)

- Fingerprint **conservador** (match único + mismo tamaño) contra mnsg: **138** nombres mapeados.
  (La versión laxa daba falsos positivos, p. ej. `__osPiGetAccess`.)
- De los 129 seguros: **67 con dirección** (47 ya conocidas + 20 del fingerprint), **57 alcanzables**
  (`LOOKUP_FUNC(0xV)` presente en el C generado).
- **11 son NUEVOS, alcanzables y seguros** — y son justo la clase peligrosa (cop0/cache/TLB):
  `__ll_mul`, `__osSetFpcCsr`, `__ull_div`, `__ull_to_d`, `osGetCount`, `osInvalDCache`,
  `osInvalICache`, `osSetIntMask`, `osUnmapTLBAll`, `osWritebackDCache`, `osWritebackDCacheAll`.

## Fix

- Añadidos los **11 nombres** a `recomp/symbol_addrs.txt` (todos confirmados por el fingerprint
  conservador y por el oráculo público de libultra).
- `recomp/hybrid-heaven.us.toml`: se **retira el stub** `func_800304A0_310A0` (TLB); al nombrarlo
  `osUnmapTLBAll` N64Recomp ya lo reconoce y delega.

## Validación

- `tools/regenerate.py`: gate **ELF ↔ imagen expandida byte a byte OK**.
- Build Linux: **OK**.
- `verify_roundtrip.py`: fases 1–3 **OK**; `find_latent_jumptable_crashes.py`: **0 crashes latentes**.
- El ELF expone los nombres (`osSetIntMask`, `osUnmapTLBAll`, …) y el C emite `<name>_recomp`
  (`reimplemented_decls.h`). `gen_runtime_func_table.py`: `_recomp` registradas **58** (47+11).
- **Pendiente**: run Windows (arranque/menú/guardado/combate) para confirmar que delegar no regresa.

### Efecto medido en Windows (2026-10-05, mantenedor)

- `[MEDIDO]` Tras el fix, el port **sube mucho los fps**: alcanza con facilidad **144** y las bajadas
  apenas llegan a **80**, cuando antes la media era ~80.
- `[INFERIDO]` Causa: las 11 libultra estaban **recompiladas y ejecutándose como código del juego** en
  caminos calientes (`__ull_to_d` con **173** call sites, `osGetCount`, cache `osInval*`/
  `osWriteback*`, `__ull_div`/`__ll_mul`, `osSetIntMask`, `__osSetFpcCsr`). Al delegarlas al runtime
  nativo baja el coste por frame.
- **Validado en Windows (mantenedor, 2026-10-05)**: velocidad de juego/audio **normales**; `hh_tick.log`
  **30,09 ticks/s**, `d2` dominante (2 VI/tick) → **lógica a 30 Hz, sin acelerar**; `hh.log` sin
  `Failed to find function` ni crash. La subida de fps es de render/present, no de lógica.

## Residual (documentado, no bloqueante)

- **76** nombres `_recomp` sin dirección en el ELF: N64Recomp los conoce pero **HH no los contiene**
  (no se llaman) → sin riesgo.
- **232** sin `_recomp`: no se nombran (rompería el enlace); si alguno se alcanza y toca hardware,
  necesitaría runtime/stub. Sin síntoma observado.
- **`renamed_funcs`**: 83, **0** reconocidas → revisar aparte.
- **6** seguros con dirección pero **no alcanzables** (`__f_to_ll`, `__ll_div`, `__ll_lshift`,
  `__ll_to_f`, `__ull_rshift`, `__ull_to_f`): no urgentes.

## Fase B — interpolación (siguiente, NO se pierde)

El método estándar está documentado en `danielgomesvieira2000/pilotwings-64-recomp`
(`patches/interpolation.c`, MIT, el mismo autor del tooling ELF/splat que usamos): **taggear cada
punto de dibujo 3D** con `gEXMatrixGroup(id)` donde `id = FNV(kind, objeto, modelo, LOD, generación de
cámara)`; **2D** con `G_EX_ID_IGNORE`; `LINEAR` para mallas y `AUTO` para efectos; grupos de proyección
“near”. Nosotros lo hacemos **parcialmente** (hook de traversal + `stable_slot` generacional; LOD=0; sin
2D-ignore). Plan Fase B:
1. Enumerar los sitios de dibujo 3D de HH y taggear cada uno por `kind`.
2. Localizar el **campo LOD** y meterlo en el id (A2.4).
3. **2D `ID_IGNORE`** en la proyección ortográfica (cuidado widescreen).
4. `ORDER AUTO` por tipo de efecto; proyecciones “near” si aplican.
5. Validar con `HH_PAIRING` + `paircap`.

## Herramientas

- `tools/verify/audit_libultra.py` — cobertura (seguros/seguros con dirección/alcanzables).
- `tools/verify/fingerprint_libultra.py` — nombre mnsg → dirección HH (conservador).
