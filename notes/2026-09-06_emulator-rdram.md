# 2026-09-06 (parte 2) — RSP-hle real + overlays detectados en RAM

## Gran avance: juego corre headless CON gráficos
Fixed la causa real del crash al adjuntar rsp-hle:
- El core `mupen64plus-core` NO llama `PluginStartup` del plugin; eso lo hace
  el FRONTEND antes de `CoreAttachPlugin`. Sin esa llamada, rsp-hle tiene
  sus callbacks internos a NULL y crashea dentro de `InitiateRSP`
  (`call *0x1d690(%rip)` en `InitiateRSP+0x107`).
- Fix en `r64dump`: tras `dlopen(rsp-hle)` y lograr el handle, llamar
  `PluginStartup(core_handle, NULL, dbg_cb)` ANTES de `CoreAttachPlugin(M64PLUGIN_RSP, handle)`.
- Orden correcto de adjunto: plugins SIEMPRE DESPUES de `M64CMD_ROM_OPEN`
  (antes devuelve M64ERR_INVALID_STATE=10).
- Con `RSP_PLUGIN=/usr/lib/mupen64plus/mupen64plus-rsp-hle.so` el juego corre
  estable, renderizando con el RDP software del core (cada snapshot de RAM difiere
  del anterior = animación/avance real; con dummy RSP los dumps eran ESTÁTICOS).

## Chunks persistentes en RAM (candidatos a overlays cargados en boot/title)
Aparecen entre t0(~4s) y t1(~15s) y ya no cambian (dumps hh3):
- 0x801BB000  (0x27000, ~159KB)
- 0x801FA000  (0x25000, ~151KB)  <- OJO: paradoja con t0: aparece también en run hh_att
- 0x8008D000  (0x5000)
Además heap ocupado 0x80154000-0x80190000 (video/buffers).
Posible correspondencia de tamaños con índices del manifest: 0x24E70~0x25000 (f008);
pero NO confirmado — la extracción de overlays sigue siendo inválida (ver parte 1).

## Dead-end confirmado
- `DebugMemRead32` del debugger API NO lee registros MMIO (VI/SP/DP/MI = 0).
  Solo RDRAM. No se puede leer el framebuffer vía VI_DRAM_ADDR de esa forma
  (alternativa: dumps por diffs de RDRAM o plugin de video real bajo Xvfb).

## Para el mapa definitivo overlay→RAM base (próximo)
1. Extracción ground-truth: conseguir el LZ real emparejando streams comprimidos
   del ROM con las copias descomprimidas AHORA visibles en RAM (0x801BB000, etc.)
   — usarlas como oráculo del descompresor.
2. Alternativa: encontrar en RAM la tabla del loader (bases como u32 BE no
   aparecieron en scan; probar LE/desplazados o el .bss del boot).
3. Identificar cada chunk a su índice de manifest por orden de aparición temporal
   y por tamaño.
4. Con el mapa: recomp static con N64Recomp + ucode de audio.

## Comandos usados hoy
```
CORE_SO=/usr/lib/libmupen64plus.so.2 RSP_PLUGIN=/usr/lib/mupen64plus/mupen64plus-rsp-hle.so \
HH_SCHED="t:mask;..." HH_DUMP_TIMES="4,15,22,..." \
./work/r64dump work/roms/us_dec.z64 work/scratch/hh3 70
```
(dumps => work/scratch/hh3.t*.bin; `/tmp/hh_keys.bin` lo escribe el harness;
dummy_input parcheado).