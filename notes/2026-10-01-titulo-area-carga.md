# TÍTULO DEL ÁREA al cargar partida — plan y evidencia

> Sesión 2026-10-01 (2.ª de la jornada). Rama **`menu-carga-guardado-partida`**. Tarea de `RETOMAR.md`
> (TAREA ACTUAL) y `TODO.md`. Continúa `notes/2026-10-01-cargar-partida-continuar.md` (UI de CARGAR y
> carga real). Todo `[MEDIDO]` del C recompilado (`build/recomp/asm/file_024.s`,
> `RecompiledFuncs/funcs_68.c`, `funcs_56.c`) salvo lo marcado `[INFERIDO]`.

## 0. Objetivo

Al cargar un slot (`CONTINUAR` → elegir partida), el juego debe mostrar **pantalla negra** con el
**título del Área en blanco** (solo el nombre, **sin números**) durante unos segundos, y ese título
se quita con un botón/tecla (o esperando). Después ya se ve el gameplay (PJ saliendo de la cápsula).

En el port hoy: **solo negro** y luego el gameplay. **Falta que se visualice el título.**

## 1. Hallazgo clave `[MEDIDO estático]`: el título es TEXTO, no imagen

La rama de ÉXITO de `func_801C3D84` (ret==1) es:

```
func_80142570()  +  func_800179B0(0)  +  func_801C11BC(0xA)  +  func_800058DC(obj, func_801C3E24)
```

(la replica el port en `hh_do_load_game`; ver `notes/2026-10-01-cargar-partida-continuar.md` §3).

`func_801C3E24` (con `D_801CC8CC==2`), en su rama que NO es 0xFF:

1. `func_8013EA54()` → **índice de escena** del slot (`v0`; 0xFF = caso de cancelar).
2. Lee `lbu 0x30($sp + índice)` de una **tabla copiada** de `D_801CCAE0` (`0x801D-0x3520`) → `t0`.
3. Llama `func_80146208(...)` (primitiva de dibujo/caja con colores) y `func_80006214(obj)`.
4. Fija como callback `func_801C3F48` (`func_800058DC(obj, 0x801C3F48)`).

`func_801C3F48` (el callback que se ejecuta después) compone el título:

```
func_8001B204(a0=0, a1=0x7D0, a2=0x55, a3=0x801CED98, [sp+0x10]=0, [sp+0x14]=índice, [sp+0x18]=tabla[índice])
```

`func_8001B204` es **el compositor de texto del juego** (`funcs_53.c:func_8001B204_1BE04`), el MISMO
que el port ya envuelve en `hh_entry_register_hook` (`src/hooks/sections.cpp`) para ocultar/traducir
el texto nativo. Por tanto **el título del Área es texto del Sistema de Texto del juego**, no una
imagen/splash. `a3=0x801CED98` es la dirección de enlace del campo de texto que compone.

### Por qué el port lo pierde `[INFERIDO del código; a confirmar con traza]`

`hh_entry_register_hook` **salta por completo** `func_8001B204` cuando
`file_select_text_skip()` es true (= `!native_visible && g_file_select_active`). La categoría
FILE-SELECT la activa el port al entrar en CONTINUAR y la desactiva en `hh_do_load_game` **al final**.
Si el callback `func_801C3F48` corre mientras la categoría sigue activa (o el nativo oculto), el
compositor se salta y **el título no se compone ni se dibuja**. Hipótesis alternativa: el título SÍ se
compone pero la UI nativa está oculta (F8) y no lo publicamos.

**Nota del mantenedor:** si es texto, además será **sencillo traducirlo** con `hh::text`
(`lang/<code>.txt`), a diferencia de una imagen.

## 2. Plan numerado (con criterio de validación)

1. **Medir** (traza, no inferir): envolver `func_801C3F48` (y `func_8013EA54`) con un hook de
   diagnóstico `HH_AREA_TRACE` que registre: si el callback corre, el `a3` que pasa a `func_8001B204`,
   el índice de escena y `file_select_text_skip()`. Extender `hh_entry_register_hook` para loguear
   `a3=0x801CED98` con su `skip` aunque `g_load_enter` ya esté a 0.
   - *Criterio:* en `hh_trace.log` (build Windows/Linux) se ve si `func_801C3F48` se ejecuta tras
     `[load] CARGAR slot N` y si su composición viene `skip=1` (saltada) o `skip=0` (compuesta).
2. **Determinar la causa** con la traza: (a) compositor saltado por FILE-SELECT aún activo; (b) nativo
   oculto (no se publica); (c) el callback no llega a correr.
3. **Fix mínimo según causa**:
   - (a) Desactivar la categoría FILE-SELECT **antes** de que corra el callback de ÉXITO (o dejar pasar
     `a3=0x801CED98` en el hook como excepción), asegurando que el texto del Área se compone.
   - (b) Publicar la pantalla negra + título por el overlay propio (fuente del juego) mientras dura el
     estado de carga, y quitarlo con **botón/tecla o espera**; el gameplay arranca después.
4. **Traducir** el nombre del Área con `hh::text` si el texto pasa por el sistema de traducción (nueva
   entrada en `lang/*.txt`), sin romper el layout.
5. **Validar en Windows** (lo hace el mantenedor): cargar → **pantalla negra con el título del Área**
   (solo nombre) → botón/tecla (o espera) → gameplay saliendo de la cápsula.

## 3. Fix aplicado `[MEDIDO del código]`

En `src/hooks/sections.cpp` → `hh_entry_register_hook`: el compositor `func_8001B204` se saltaba
**entero** cuando `file_select_text_skip()` era true (categoría FILE-SELECT activa + nativo oculto).
El título del Área se compone por ese compositor con `a3=0x801CED98`, así que se perdía.

Fix: **excepción para `a3 == 0x801CED98`** (el campo de enlace del título del Área). Esa composición
pasa siempre al compositor original y NO se blankea (no está en las tablas de blankeo), así que el
Sistema de Texto del juego compone y dibuja el nombre del Área. La pantalla negra ya la pinta el propio
juego (por eso hoy se ve negro); el título se quita por el mismo flujo nativo (espera/input).

Traza añadida (con `HH_LOAD_TRACE=1`): `[load-trace] AREA TITLE compose a3=801CED98 (dejar pasar)`.

## 4. Pendiente / validación

- [ ] **Validar en Windows** (mantenedor): cargar → **pantalla negra con el título del Área** (solo
      nombre) → botón/tecla (o espera) → gameplay saliendo de la cápsula.
- [ ] Confirmar que el texto compuesto es el **nombre** (sin números) y valorar **traducirlo** con
      `hh::text` (`lang/<code>.txt`) si procede.
- [ ] Si la pantalla negra no apareciera por sí sola, publicar telón negro por el overlay durante el
      estado de carga (la capa `set_screen_blackout` ya existe).

## 4. Referencias

- `notes/2026-10-01-cargar-partida-continuar.md` §3 (flujo de ÉXITO y `hh_do_load_game`).
- `src/hooks/sections.cpp`: `hh_entry_register_hook`, `hh_do_load_game`, `feed_load_flow`.
- C recompilado: `func_801C3E24`/`func_801C3F48`/`func_8013EA54` en `RecompiledFuncs/funcs_68.c` y
  `funcs_56.c`; compositor `func_8001B204` en `funcs_53.c`.
