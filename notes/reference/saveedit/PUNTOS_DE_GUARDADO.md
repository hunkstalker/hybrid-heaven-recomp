# Puntos de guardado aportados por el mantenedor (seguimiento)

> **Documento vivo de referencia.** El mantenedor aporta `.pak` con **slots guardados jugando** en
> puntos de guardado reales (estado de zona + stats que el propio juego generó). Cada vez que aporte
> uno nuevo, **registrarlo aquí** (fila en la tabla) y **guardar el `.pak`** en esta carpeta. Sirven
> para:
> 1. **Verificar** el mapeo de índices de escena (`idx`) y la carga con `CONTINUAR`.
> 2. **Ser las plantillas** del futuro `EDICIÓN DE PARTIDA -> "mover mi partida a una Área-Parte"`
>    (plantilla de la zona + atributos/estado/items/habilidades del jugador). Ver
>    `../../2026-09-29-editor-area-parte-plan.md` §6bis.
>
> **Nomenclatura**: `N-P` = área N (1..10), punto de guardado P (1..). Los `N-0` (inicio de nivel) NO
> son guardables (no hay slot posible); se llega por transición. Ver la nota maestra.

## Plantillas guardadas (en `assets/save/templates/<N-P>.bin`, 0xD00 cada una)

| plantilla | Área-Parte | `0x564` (LE) | origen | notas |
|---|---|---|---|---|
| `1-1.bin` | **1-1** | **0** | `hh.us.bin.pak` slot0 (guardado jugando) | real; stats de inicio |
| `1-2.bin` | **1-2** | **2** | `hh.us.bin.pak` slot1 (guardado jugando) | real |

- `[MEDIDO]` `0x564`: **1-1 -> 0**, **1-2 -> 2** = `(area-1)*10 + (sub-1)*2`. (El `10` que se vio en
  un slot con cabecera "1-2" era un **2-0**; la cabecera se desincroniza al editar.)
- Aportados por el mantenedor; los slot3/4 del `.pak` se ignoran (ELIMINAR del editor aún no funciona,
  ver `TODO.md`).

> **Cobertura por área** (para saber qué falta para las plantillas): ✅ con plantilla · ⬜ falta.
> - Área 1: 1-1 ✅, 1-2 ✅ (**área 1 completa**).
> - Área 2: 2-1 ⬜ · Área 3: 3-1..3-7 ⬜ · Área 4: 4-1..4-3 ⬜ · Área 5: 5-1,5-2 ⬜ ·
>   Área 6: 6-1..6-7 ⬜ · Área 7: 7-1..7-3 ⬜ · Área 8: 8-1..8-3 ⬜ · Área 9: 9-1 ⬜.

## Cómo registrar uno nuevo (checklist)

1. Copiar el `.pak` a esta carpeta con nombre `YYYY-MM-DD-hh.us.bin.pak.<resumen>.pak`.
2. Extraer cada slot bueno a **plantilla** `assets/save/templates/<N-P>.bin` (0xD00 B):
   ```python
   d = open(".../hh.us.bin.pak","rb").read(); HDR=0x1B; SLOT=0xD00; slot=0
   s = d[HDR+0x100+slot*SLOT : HDR+0x100+(slot+1)*SLOT]
   open(f"assets/save/templates/{name}.bin","wb").write(s)
   ```
3. Añadir fila a la tabla (Área-Parte + `0x564` = `s[0x564] | s[0x565]<<8`) y actualizar la cobertura.
4. Si aporta un área nueva completa, anotarlo en `TODO.md` (avance de "plantillas por punto").

## Recordatorio técnico (medido, ver nota maestra)

- **Campo de escena** = `0x564` (u16 **LE**) del slot. `1-1 -> 0`, `1-2 -> 10`.
- **Cabecera** (bswapped): `+1` AREA N, `+2` AREA P (rótulo de la lista `DATA LOAD`).
- **Slot → estructura**: `0x000..0x09D` personaje (u16 LE, word-swapped), `0x09E..0x19F` técnicas,
  `0x1A0..0x1CC` items, `0x300..0x363` flags de historia, `0x364..` bloque de estado, `0x564` escena.
- **Checksum del slot** = `sum(0..0xCFB)` en `0xCFC`.
