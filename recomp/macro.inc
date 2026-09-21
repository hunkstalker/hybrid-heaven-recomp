/* Macros de ensamblador para la salida de splat (vía ELF, ADR 0011).
 *
 * Es NUESTRO y se versiona: no vive en asm/ (generado, gitignored, borrado en cada re-split). El
 * build-elf pone este directorio en el include path del ensamblador (-I recomp).
 *
 * El generador del YAML usa asm_data_macro: dlabel y asm_jtbl_label_macro: jlabel, de modo que solo
 * las funciones reales quedan @function; los datos y las jump-tables, @object.
 */

.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro dlabel label
    .global \label
    .type \label, @object
    \label:
.endm

.macro enddlabel label
    .size \label, . - \label
.endm

/* La jump-table está en un objeto de datos; el código que la usa, en uno de texto. */
.macro jlabel label
    .global \label
    .type \label, @object
    \label:
.endm

/* spimdisasm emite `nonmatching <name>, <size>` antes de cada etiqueta; para una función, ese tamaño
 * es su longitud real. Es el ÚNICO sitio donde aparece el tamaño de una función (enddlabel cierra
 * datos, pero nada cierra una función), así que aquí es donde un símbolo func_ recibe su st_size.
 *
 * Importa más de lo que parece: N64Recomp solo recompila una función cuyas palabras de sección no
 * estén vacías, y las deriva del tamaño del símbolo. Sin este macro, todas las funciones quedan de
 * tamaño 0 y el recompilador no emite nada (ni error ni aviso).
 *
 * El tamaño es opcional porque las etiquetas de datos se anuncian igual sin él; esas toman su
 * tamaño real de enddlabel más abajo (que sobreescribe el 0 puesto aquí).
 */
.macro nonmatching name, size=0
    .size \name, \size
.endm

.macro sizeof name, size
    .size \name, \size
.endm
