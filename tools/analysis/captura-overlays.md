# Ejecucion guiada (captura del mapa overlay->RAM)

## Que entrega
- `work/libmupen64plus-debug.so`  core con debugger (write-breakpoints funcionando),
  SIN instrumentacion ruidosa.
- `work/r64dump`                     harness: ventana opcional, dumps RDRAM, bpx.
- `tools/analysis/play.sh`          lanzamiento con ventana + teclado (input-sdl).
- Config de input ya mapeada en `la config de input de mupen64plus`.

## Como
1. En un entorno con display: `tools/analysis/play.sh 180 work/scratch/live`
2. Juegue/avance por los menus; cada registro de overlay produce
   `[dbg] stop pc=... valid=YES ... loader pc=... (wrote phys ...)` y actualiza `live.dir.bin`.
3. Al terminar, enviarme `live.session.log`, `live.dir.bin` y los `live.tN.bin`.

## Que haré con los datos
Con la secuencia ids+base capturada y la logica del loader ya documentada
(entrada 8B: id16 halfword-alto + base32 = prev+size; dumps word-swapped => bswap32),
derivo el mapa completo overlay->RAM para N64Recomp (#3).

## Notas
- Los dumps RDRAM vienen word-swapped: aplicar bswap32 por palabra.
- El watts-por-branch del warmup del dir (zerofill de boot) se salta solo en el harness.
- Si el video no abre ventana: probar con `mupen64plus-video-rice.so` en VIDEO_PLUGIN.