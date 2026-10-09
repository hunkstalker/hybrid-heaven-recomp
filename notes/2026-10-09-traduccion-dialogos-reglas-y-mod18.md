# Traducción del diálogo es+ca — reglas de método y arranque del módulo 18

> Evidencia de la sesión **2026-10-09**. Estado: **no validado en Windows** (contenido sin volcar aún).
> Rama: `traduccion-dialogos-es-ca` (desde `main`). Handoff: `../RETOMAR.md`; guía: `../docs/traduccion.md` §5.1.

## 1. Reglas de método acordadas con el mantenedor

1. **Método**: presentar antes de tocar ficheros la tabla **EN | ES | CA a nivel de MENSAJE** (EN =
   mensaje inglés completo; ES/CA = traducción) y esperar revisión.
2. **Registro `tú`/`usted`**: se decide **frase a frase según el original**, no por módulo. Fuente
   **principal = inglés**; **de/fr de la ROM EU = contexto** (`Du/Sie`, `tu/vous`). Directo,
   contracciones o `Johnny` a secas → **tú**; `please`/distancia → **usted**.
3. **Cotejo con otros idiomas**: contrastar **cada mensaje con DE/FR** (`work/dialogues/us_de_fr.tsv`)
   **antes de traducir** para desambiguar. El inglés manda; el `--pair` **no alinea 1:1** (fusiona/
   desplaza filas) → DE/FR son contexto, no fuente.

## 2. Aclaración del mecanismo de ficheros (confusión resuelta)

- **`(tú)` no es el pronombre**: es la etiqueta de `assets/dialogos.txt` para la **versión completa**
  ("tu versión"), que **antes no cabía** en el presupuesto A+. `ES aplicado:`/`CA aplicado:` = versión
  corta que acabó en `es.txt`.
- `build_dialogue_messages.py` usa la larga **solo** si el tag es `ES (tú):`/`CA (tú):`; si no,
  recompone el mensaje con las líneas de `es.txt` (versión corta).
- **Overlay sin límite de caracteres**: la traducción completa va como `(tú)`; las líneas se hornean
  con `\n` (~32 chars/línea, `MAX_CHARS`). En la tabla no se muestran los saltos, pero deben
  **conservarse o inferirse** al escribir los ficheros.

## 3. Módulo 18 (51 mensajes / 136 líneas) — decisiones

- **Registro**: informal en todo el módulo (DE `Du/Dir/Dich`; FR `tu/te/tes`) → **tú/tu**.
- **`Navigator` → Navegante / Navegant** (fijado por el mantenedor). Contexto: DE usa `Navigator`
  —palabra alemana para "navegante", no préstamo— y FR lo traduce (`navigateur`). Pendiente unificar
  el mod 27, donde quedó `Navigator` sin traducir en la sección MENSAJES.
- **`Traitor` → Traidor / Traïdor** (DE `Verräter`, FR `traître`); **`Master` → Maestro / Mestre**
  (FR `Maître`).
- Otros términos: `starship`→nave/nau · `shelter`→refugio/refugi · `hideout`→guarida/cau ·
  `ally`→aliado/aliat · `planetary stay facility`→instalación planetaria de estancia /
  instal·lació planetària d'estada.

## 4. Correcciones del mantenedor aplicadas al borrador

- **m0** `The President is becoming more aware.` → ES `El Presidente va recobrando la consciencia.` /
  CA `El President va recobrant la consciència.` (DE *das Bewußtsein kommt zurück*, FR *reprend
  conscience*).
- **m18** "hundreds of years" = cientos/centenars (no siglos/segles).
- **m20** CA `No saps quant ho sentim.`
- **m22** ES `…lo único que hay que hacer es reactivar` / CA `…l'única cosa que cal fer és reactivar`.
- **m23** ES `nuestra nave espacial, que ahora mismo no funciona.` / CA `la nostra nau espacial, que
  ara mateix no funciona.`
- **m47** ES `Asegúrate de tener cuidado.` / CA `Assegura't d'anar amb compte.`

## 5. Estado

- **Volcado el mod 18** (2026-10-09): 51 mensajes a `assets/lang/es.txt`/`ca.txt` (per-line) y
  `assets/dialogos.txt` (`[m18]` con `ES (tú)`/`CA (tú)` completos, sin recortar), `18` añadido a
  `COVERED`, `build_dialogue_messages.py` ejecutado (es + ca). `check_translations` OK; cobertura
  `check_dialogue_fit` 271→326 traducidos. `check_dialogue_fit` reporta "problemas" por superar el
  viejo presupuesto A+ (esperado: overlay sin límite).
- **Pendiente**: **validación visual en Windows** (mantenedor). Excepción acordada: se commitea antes
  de esa validación porque el mantenedor revisa los textos por tabla y confirma que se integran bien.
- Unificar `Navigator` → Navegante/Navegant en el mod 27.

## 6. Regla "sin límite" (actualización 2026-10-09)

Se corrige la regla heredada de **acortar para caber en el presupuesto A+**: con el overlay, lo que
**se ve** no tiene límite de longitud → se traduce **completo, sin acortar** (versión `(tú)`). El
**presupuesto A+** (suma de chars del mensaje inglés) solo afecta al **render nativo** (fallback y
`HH_DLG_KEEP_ORIGINAL=1`); `check_dialogue_fit.py` pasa a ser **informativo** y `aplicado` deja de ser
obligatorio. Actualizado en `docs/traduccion.md` §2/§5/§5.1, `RETOMAR.md` y `TODO.md`. Se conserva el
histórico de la transición A+ → overlay (notas `2026-10-06-dialogos-*` y
`2026-10-07-experimento-overlay-dialogo.md`).
