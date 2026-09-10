# Cómo abordar el scheduler del motor Konami con Ghidra

Objetivo: encontrar quién envía la **primera tarea** a la cola principal (0x8005BF30) del thread
principal (FUN_8002AEA0) en Hybrid Heaven, para desbloquear el deadlock de Fase 2.

## Por qué Ghidra y no el enfoque actual
- El scheduler es **lógica del motor Konami** (código específico del juego), no un os function.
- El byte-matching con Goemon **no sirve** para funciones de juego (difieren entre juegos).
- Ghidra ya tiene el ROM analizado con nombres de funciones, referencias cruzadas y decompiler:
  el proyecto está en **`work/ghidra/proj`** con `baserom.us.z64` importado y analizado.
- Scripts Ghidra existentes en `tools/analysis/`: `ghidra_loader.java` (decompile a 0x...),
  `ghidra_recon.java` (busca patrones), `ghidra_code_zone.java`, `ghidra_blocks.java`.

## Pasos

### 1. Abrir el proyecto y el programa
- Ghidra 12.1.3 está en `toolchain/ghidra/ghidra_12.1.3_PUBLIC` (JDK 21).
- Abrir proyecto `work/ghidra/proj`, programa `baserom.us.z64`.

### 2. Localizar la cola principal (0x8005BF30)
- Ir a la dirección `0x8005BF30` en el listing. Es un struct `OSMesgQueue` (debe tener un
  comentario o ser referencia de `osCreateMesgQueue`).
- Ghidra: `R` (references) sobre 0x8005BF30 → **todos los accesos** a esa cola. Ahí aparecerá:
  - Quién la crea (`osCreateMesgQueue`).
  - Quién hace `osSendMesg`/`osJamMesg` hacia ella (**el emisor que buscamos**).
  - Quién hace `osRecvMesg` (el thread principal).

### 3. Encontrar el emisor (la clave)
- En las referencias a 0x8005BF30, buscar las **llamadas a `osSendMesg`** (o `osJamMesg`) que pasan
  esa cola como argumento. El emisor es la función que las contiene.
- Seguir ese emisor hacia atrás: ¿por qué no corre? ¿Está bloqueado en otro `osRecvMesg`? ¿No se
  crea su thread? → **cadena del deadlock**.

### 4. Entender el scheduler
- La función emisora es (parte de) el **scheduler de tareas**. Con el decompiler de Ghidra:
  - `Ctrl+E` / script `ghidra_loader.java` para decompilar esa función a C legible.
  - Ver cómo estructura las tareas (el struct con `[task+0x14]`, `[task+0]`, `[task+4]` que lee el
    main thread) y cómo las encola.
- Buscar el thread del scheduler: quién hace `osCreateThread` con la función emisora como entry.

### 5. Cruzar con el runtime (opcional)
- Con la función emisora identificada, comprobar si depende de un os function aún sin mapear
  (los os funcs se mapean fiable con el método Goemon de la nota Fase 2 ACT.4). Si el scheduler
  llama a `osViSetEvent`/`osSpTaskStartGo`/`osContInit`/`osCreatePiManager` sin mapear, eso puede
  ser la causa de que no envíe la primera tarea.

## Objetivos de referencia (ya confirmados)
- Cola principal: `0x8005BF30` (count=200), creada por el setup; el main thread (FUN_8002AEA0)
  hace `osRecvMesg(BLOCK)` en ella como primera acción.
- Thread principal: FUN_8002AEA0 (bloqueado). Thread 5: FUN_800011b0 (bloqueado en 0x800CD4D8).
- El evento VI se conecta a 0x800CD4B0 (no a la cola principal) → el VI no alimenta la cola principal.
- Funciones ya mapeadas (no tocar): osSendMesg=0x80026300, osJamMesg=0x80030A10,
  osRecvMesg=0x800266B0, osSetEventMesg=0x8002FB60, osCreateThread=0x80028260,
  osStartThread=0x80034C90, osCreateMesgQueue=0x80030610, osSetThreadPri=0x80030B60,
  osGetThreadId=0x80030C40, osStopThread=0x80029580, osCreateViManager=0x80032220,
  osViSetMode=0x80032360.

## Herramientas auxiliares (no Ghidra)
- `/tmp/mips_dis.py <rom> <vram> <n>` — disassembler capstone (ROM por defecto = HH).
- `/tmp/match_os3.py` — emparejar os funcs de Goemon→HH por bytes.
- `/tmp/find_viset.py`, `/tmp/find_hh_event.py`, `/tmp/find_mainq.py` — escaneos de patrones.

## Nota
El scheduler es la tarea pendiente más grande de Fase 2. Este plan con Ghidra (referencias cruzadas
a 0x8005BF30 → emisor) es el camino más directo. El resto del trabajo (os funcs, método Goemon)
ya está consolidado y versionado.

---

## ACTUALIZACIÓN — Ghidra headless operativo (2026-09-10)

Se instaló Java 21 (`apk add openjdk21` + `bash`) y se ejecutó `analyzeHeadless` correctamente.

**Comando:**
```
export JAVA_HOME=/usr/lib/jvm/openjdk21
export PATH=$JAVA_HOME/bin:$PATH
toolchain/ghidra/ghidra_12.1.3_PUBLIC/support/analyzeHeadless work/ghidra/proj HH \
  -process -scriptPath <dir> -postScript <Script.java>
```

**Scripts (en `tools/analysis/ghidra_scripts/`):** FindMainQ (refs a 0x8005BF30),
FindSender (callers de osSendMesg/osJamMesg), DecompFns/DecompSetup/DecompMain/DecompBoot/Decomp1078.

**Hallazgos del flujo de boot (decompile):**
- ramMain(0x80000400) → FUN_80001078: osInitialize + crea thread 1 (FUN_80001124).
- Thread 1 (FUN_80001124): crea cola principal 0x8005BF30, crea thread 5 (FUN_800011b0), gira infinito.
- Thread 5 (FUN_800011b0): crea colas 0x8005c268/0x8005c288, osRecvMesg(BLOCK) en 0x8005c288.
- Callers de osSendMesg: FUN_8002add0/FUN_8002ae64 (envían a 0x800CD4D8).

**Pendiente:** el emisor de la cola principal (0x8005BF30) usa puntero (solo FUN_80001124 la referencia
directamente). El decompile de Ghidra es parcial (el main thread id=0 no aparece en el flujo visible).

**Nota:** los scripts .java deben tener la clase pública con el MISMO nombre que el archivo; Ghidra
cachea la compilación (si falla "class could not be found", renombrar el archivo o recompilar).
