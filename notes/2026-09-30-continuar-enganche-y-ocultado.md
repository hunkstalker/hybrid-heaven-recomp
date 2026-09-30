# CONTINUAR → F8 pinta el `BATTLE DATA LOAD`: causa raíz (compositor equivocado) y fix

> Sesión 2026-09-30 (2ª). Rama `menu-carga-guardado-partida`. Tarea: "arreglar el enganche de
> CONTINUAR / el ocultado (F8) analizando el código (NO revertir)".
>
> **Resultado**: causa raíz localizada y **corregida** en `src/hooks/sections.cpp`
> (`hh_file_select_hook`). Reproducción del mantenedor: entrar en CONTINUAR, pulsar **F8**, pulsar
> **A** → el fondo muestra `BATTLE DATA LOAD` (dos columnas, `1P/2P CONTROLLER`) en vez del `DATA LOAD`
> de una columna.

## 1. Causa raíz `[MEDIDO]`

El commit **`69b5ed9`** (Fase 3) añadió al hook del file-select una **recomposición del nativo al
cambiar la visibilidad (F8)**. Llamaba a DOS compositores:

```c
func_801426B0_103AE80(rdram, &t);   // comentado "título DATA LOAD + CONTROLLER PAK + caja"
func_80142840_103B010(rdram, &t);   // comentado: mensaje "Select play data..."   <-- FALSO
```

El comentario de `func_80142840` es **incorrecto**. Volcando la RDRAM (`work/debug/rdram_menu.bin`,
word-swap 32-bit) y decodificando las tablas de texto EUC-JP que pasa cada compositor como `a3`:

| Compositor | `a3` | Texto de la tabla | Pantalla |
|---|---|---|---|
| `func_801426B0` | `0x8018F16C` | `ＤＡＴＡ　ＬＯＡＤ` + `CONTROLLER PAK` | **DATA LOAD (CONTINUE)** ✅ |
| `func_80142778` | `0x8018F1BC` | `ＤＡＴＡ　ＳＡＶＥ` + `CONTROLLER PAK` | DATA SAVE |
| `func_80142840` | `0x8018F20C`/`0x8018F230` | `ＢＡＴＴＬＥ　ＤＡＴＡ　ＬＯＡＤ` + `1P CONTROLLER` / `2P CONTROLLER` | **BATTLE DATA LOAD (VS)** ❌ |

Es decir: al pulsar **F8**, el hook re-componía el título y las cabeceras del **BATTLE DATA LOAD**.
Por eso el fondo sale `BATTLE DATA LOAD` con dos columnas. La "A" del repro simplemente hace avanzar
el file-select nativo (ya visible tras F8) y lo pinta.

**Confirmación nativa**: en el flujo real del CONTINUE, `func_8013E7C0` (setup, file_008) llama a
`func_801426B0` (correcto) y a `func_8014307C` (cajas); **nunca** llama a `func_80142840`. Este último
pertenece a la cadena `func_801C5824` (VS) → `func_8013EF54`.

**Relación con el reporte original de "CONTINUAR carga BATTLE"**: el enganche de CONTINUAR en sí
(llamada directa `func_800058DC(obj, 0x801C3CDC)`, commit `7dacb58`) **es correcto**: ruta a
`func_801C3D50/801C3D84` → `DATA LOAD` de una columna. El aspecto de BATTLE lo introducía el
**recompositor de F8**, no el enganche.

## 2. Fix aplicado

`src/hooks/sections.cpp`, `hh_file_select_hook`: se **elimina** la llamada a `func_80142840` y se deja
solo `func_801426B0` (el setup real del `DATA LOAD`):

```c
if (hh::menu_overlay::native_toggle_pending()) {
    recomp_context t = *ctx;
    func_801426B0_103AE80(rdram, &t);   // SETUP del DATA LOAD (CONTINUE)
}
```

Con esto, F8 re-compone el `DATA LOAD` de una columna (título + `CONTROLLER PAK` + caja + mensaje), no
el `BATTLE DATA LOAD`.

## 3. Nota metodológica (headless)

- La reproducción headless del flujo de menú es **frágil**: el timing del intro/boot varía entre
  arranques y la inyección por tiempo de `HH_PRESS_SEQ` cae en frames de juego distintos (y el menú
  nativo descarta A si cae en el mismo frame). Por eso **no** se pudo cerrar la validación visual del
  fix en headless en esta sesión; se hizo por **análisis de código + volcado RDRAM** (decisivo) y queda
  **pendiente de validar en Windows**.
- El enganche/fix no cambia ninguna dirección de hook ni la ROM; es una llamada menos en el
  recompositor de F8.

## 4. Propuesta de siguiente paso

1. **Validar en Windows**: CONTINUAR → F8 → A: debe verse el `DATA LOAD` de una columna (no BATTLE).
2. **Ocultado (tema aparte)**: sigue colándose el prompt nativo `Please connect Controller Pak…` por
   detrás de nuestras cajas cuando el nativo está oculto (sin F8). Localizar su vía de dibujo (no pasa
   por `func_8001B204`).
3. Commit del fix (un tema = un commit) cuando se valide.
