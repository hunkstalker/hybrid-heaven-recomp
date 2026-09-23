# Texto EUC-JP, gaiji europeos de la PAL y por qué USA no trae acentos

> Sesión 2026-09-23. Investigación para traducir ES/CA/FR/DE con acentos. Complementa
> `notes/2026-09-23-spike-traduccion-charset-y-sustitucion.md`.

## 1. Encoding real: **EUC-JP**

El motor codifica el texto en **EUC-JP**, no ASCII puro ni Shift-JIS:

- ASCII (`0x20-0x7E`) = 1 byte (igual que ya usamos).
- Japonés: kanji/kana de 2 bytes en el rango EUC `0xA1-0xFE`. Ejemplo verificado: los strings
  japoneses de debug decodifican bien (`ヘルプＲＯＭの読み込み…`).
- Europeo: caracteres acentuados = **2 bytes** (gaiji; ver §2).

## 2. Gaiji europeos de la PAL (bloque JIS fila 16)

La PAL **sustituye los primeros ~42 kanji** (códigos EUC `B0A1`…`B0CA`, o sea `亜 唖 娃 …以`)
por glifos latinos acentuados. Hay una **tabla de glifos** en la imagen PAL (`eu_dec.z64`):

```
0x01EA30: 34 01 A2 A7 54 61 00 03 | 34 01 A1 FC 24 05 00 55
          34 01 A1 FC 54 61 00 03 | 34 01 B0 A1 24 05 00 56
          34 01 B0 A1 54 61 00 03 | 34 01 B0 A2 24 05 00 57
          ...
```

Entradas de 8 bytes `34 01 <código EUC BE> <props> <índice interno>`; los índices van `0x55..0x7F`.

### Mapeo código → glifo (deducido del texto de ayuda DE/FR de la PAL)

Extraído de las zonas `0x8BE200` (alemán) y `0x8BF240` (francés):

| EUC | glifo | ejemplo |
|---|---|---|
| `B0 B2` | **ä** | `aufl[ä]dst` |
| `B0 B3` | **â** | `d[â]g[â]ts` |
| `B0 B4` | **à** | `[à] la page`, `d[â]…` |
| `B0 B7` | **ê** | `m[ê]me`, `[ê]tes` |
| `B0 B8` | **è** | `derri[è]re`, `premi[è]re` |
| `B0 B9` | **é** | `s[é]lection`, `d[é]placer` |
| `B0 BA` | **ü** | `dr[ü]ckst`, `f[ü]nften` |
| `B0 BF` | **ö** | `gr[ö]ßte` |
| `B0 C1` | **ç** | `con[ç]ue` |
| `B0 CA` | **ß** | `Fu[ß]tritten`, `gr[ö][ß]te` |
| `A1 AD` | **'** (apóstrofo) | `l[']ennemi` |

(La PAL tiene además extensas ayudas de combate en alemán y francés localizadas; los menús
principales quedaron en inglés.)

## 3. **Hallazgo crítico: el ROM USA NO trae estos glifos**

Busqué el patrón de la tabla (`34 01 b0 b2 54 61` / `34 01 b0 a1 24 05`) en USA: **0 apariciones**
(en PAL, 42). USA sí tiene su propia tabla de glifos especiales (p. ej. ROM `0x01E0D8`, con códigos
`D1DB/D9C7/E6AB…`) y el mismo formato `34 01 <code> <props>`, pero **sin los gaiji europeos**.

→ Consecuencia: para poner **acentos** en el texto del juego (ES/CA/FR/DE) hay que **añadir glifos a
la fuente USA** (o transplantar de la PAL). El japonés, en cambio, ya funciona out-of-the-box.

## 4. Plan propuesto (dos vías)

- **A. Menús/UI propios del port (ADR 0008)** — usar una **fuente propia** (overlay ImGui/RT64) para
  el menú PC y el selector de idioma. Aquí los acentos y cualquier idioma salen gratis, sin tocar la
  fuente del juego. Desbloquea el objetivo de 6 idiomas para nuestra UI.
- **B. Texto propio del juego (diálogos/menús internos)** — **transplantar los gaiji de la PAL**:
  1. Localizar la **textura de fuente** en USA y PAL (misma fuente JIS; PAL sobrescribe 42 tiles).
  2. En runtime, copiar los 42 tiles europeos de la PAL a la fuente USA y registrar las entradas de
     la tabla (`B0xx` → glifo) para poder usar los códigos de §2.
  3. Con eso, ES/CA/FR/DE pueden usar los glifos existentes (ä â à ê è é ü ö ç ß…) y los propios de
     español que falten (`á í ó ú ñ ¿ ¡`) habría que **dibujarlos** o comprobar si la fuente PAL ya
     los incluye (la tabla tiene ~42 slots; no se ha visto `ñ/¿/¡` en texto PAL por no haber español).

## 5. Siguiente paso concreto

Localizar la **textura de fuente** (asset) y la rutina que traduce `código EUC → tile`, para poder
mapear los 42 glifos visualmente (extraer el bitmap y leerlo) y así saber exactamente qué glifos hay
(y si `á/í/ó/ú/ñ/¿/¡` están entre ellos).
