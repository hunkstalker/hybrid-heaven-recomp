cmake_minimum_required(VERSION 3.20)
project(HybridHeavenRecomp LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(MSVC)
    # Required for correct recompiled function callbacks.
    add_compile_options(/EHsc)
    # Mapa de enlazado: permite resolver un crash "exe+0xNNNN" a la funcion recompilada.
    add_link_options("/MAP:${CMAKE_BINARY_DIR}/HybridHeavenRecomp-$<CONFIG>.map")
else()
    # Recompiled MIPS code needs x64 baseline instructions.
    # SSSE3 lo requiere la implementacion VU del runtime RSP (rsp_vu_impl.hpp, _mm_shuffle_epi8).
    # -fno-strict-aliasing: el C recompilado usa los punteros MEM_W/H/B del mismo rdram con tipos
    # distintos (sw seguido de lhu del mismo slot); sin esto GCC reordena el load antes del store
    # y lee basura (los ports de referencia tambien lo ponen).
    add_compile_options(-O2 -msse4.1 -fno-strict-aliasing)
endif()

# Optionally build a static runtime (recommended for easier distribution).
set(PORT_HYBRID_HEAVEN_RECOMP_STATIC ON CACHE BOOL "Build with static libraries where possible")
if(PORT_HYBRID_HEAVEN_RECOMP_STATIC)
    set(RT64_STATIC ON CACHE BOOL "Build RT64 as a static library" FORCE)
endif()

if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

set(RT64_SDL_WINDOW_VULKAN ON)
add_subdirectory(lib/rt64)

# Shaders del port (overlay A2). Las funciones build_vertex_shader/build_pixel_shader viven en el
# scope de lib/rt64 y no son visibles desde el scope padre: hay que re-declarar aqui las variables
# DXC* (mismo patron que Goemon) y usar el mismo DXC. Ver lib/rt64/CMakeLists.txt.
set(DXC_COMMON_OPTS "-I${PROJECT_SOURCE_DIR}/src")
set(DXC_SPV_OPTS "-spirv" "-fspv-target-env=vulkan1.0" "-fvk-use-dx-layout")
set(DXC_VS_OPTS "${DXC_COMMON_OPTS}" "-E" "VSMain" "-T" "vs_6_3" "-fvk-invert-y")
set(DXC_PS_OPTS "${DXC_COMMON_OPTS}" "-E" "PSMain" "-T" "ps_6_3")
if(WIN32)
    set(DXC "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc.exe")
elseif(APPLE)
    set(DXC "DYLD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/arm64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/arm64/dxc-macos")
else()
    if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
        set(DXC "LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/x64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxc-linux")
    else()
        set(DXC "LD_LIBRARY_PATH=${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/lib/arm64" "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/arm64/dxc-linux")
    endif()
endif()

if(WIN32)
    # Use the vendored SDL2 that RT64 is already built against.
    set(SDL2_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3/include")
    set(SDL2_LIBRARY "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3/lib/x64/SDL2.lib")
    link_directories("${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3/lib/x64")
    add_library(SDL2::SDL2 UNKNOWN IMPORTED)
    set_target_properties(SDL2::SDL2 PROPERTIES
        IMPORTED_LOCATION "${SDL2_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${SDL2_INCLUDE_DIRS}")
else()
    find_package(SDL2 REQUIRED NO_MODULE)
    if(NOT TARGET SDL2::SDL2)
        add_library(SDL2::SDL2 INTERFACE IMPORTED)
        set_target_properties(SDL2::SDL2 PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${SDL2_INCLUDE_DIRS}"
            INTERFACE_LINK_LIBRARIES "${SDL2_LIBRARIES}")
    endif()
endif()

add_subdirectory(lib/N64ModernRuntime)

# MSVC: silenciar los avisos de las DEPENDENCIAS (terceros), que no son codigo nuestro. El port
# (src/) conserva sus avisos. En Linux (GCC/Clang) no aplica (el ruido es especifico de MSVC).
if(MSVC)
    target_compile_options(rt64 PRIVATE /W0)
    target_compile_options(ultramodern PRIVATE /W0)
    target_compile_options(librecomp PRIVATE /W0)
endif()

file(GLOB RECOMPILED_FUNCS CONFIGURE_DEPENDS build/recomp/RecompiledFuncs/funcs_*.c)

# El C recompilado es obra derivada del binario del juego y NO se versiona (ADR 0009). Se regenera
# una vez desde TU ROM con `tools/regenerate.py` (via ELF/splat; ver docs/workflows.md).
if(NOT RECOMPILED_FUNCS)
    message(FATAL_ERROR
        "Faltan build/recomp/RecompiledFuncs/funcs_*.c. El C recompilado NO se versiona (ADR 0009).\n"
        "Regenera con TU ROM (una vez):\n"
        "  python3 tools/regenerate.py\n"
        "  (requiere splat+spimdisasm y LLVM MIPS; ver tools/install_splat.sh y docs/workflows.md)")
endif()
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/build/recomp/rsp/hh_aspMain.cpp")
    message(FATAL_ERROR
        "Falta build/recomp/rsp/hh_aspMain.cpp (microcodigo RSP recompilado, tambien derivado).\n"
        "Se regenera con tools/regenerate.py (RSPRecomp de tu ROM).")
endif()

# MSVC: el C recompilado (N64Recomp) y el microcodigo RSP (RSPRecomp) son GENERADOS (no editables a
# mano): silenciar sus avisos. Nuestro `src/` conserva los avisos por defecto.
if(MSVC)
    set_source_files_properties(
        ${RECOMPILED_FUNCS}
        build/recomp/RecompiledFuncs/lookup.cpp
        build/recomp/rsp/hh_aspMain.cpp
        PROPERTIES COMPILE_OPTIONS "/W0")
endif()

# Fuente Work Sans (SIL OFL-1.1, Wei Huang): se INCRUSTA el .ttf en el ejecutable para no distribuir
# el fichero suelto; el overlay la carga de memoria. Licencia/copyright en assets/fonts/OFL.txt.
# El .cpp con el array de bytes se genera en configure (sin Python). Ver src/subsystems/ttf.cpp.
# Peso: **SemiBold** (medido contra el original). Es el UNICO .ttf que se conserva.
set(WS_TTF "${PROJECT_SOURCE_DIR}/assets/fonts/WorkSans-SemiBold.ttf")
if(EXISTS "${WS_TTF}")
    file(READ "${WS_TTF}" WS_HEX HEX)
    string(REGEX REPLACE "(..)" "0x\\1," WS_BYTES "${WS_HEX}")
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/worksans_ttf.cpp"
        "// Generado por CMake desde assets/fonts/WorkSans-SemiBold.ttf (Work Sans, OFL-1.1). No editar.\n"
        "extern const unsigned char kWorkSansTtf[];\n"
        "extern const unsigned long kWorkSansTtfSize;\n"
        "extern const unsigned char kWorkSansTtf[] = {${WS_BYTES}};\n"
        "extern const unsigned long kWorkSansTtfSize = sizeof(kWorkSansTtf);\n")
    set(WS_TTF_CPP "${CMAKE_CURRENT_BINARY_DIR}/worksans_ttf.cpp")
    # Se anade a las fuentes del target mas abajo (en la lista de add_executable).
else()
    message(STATUS "assets/fonts/WorkSans-SemiBold.ttf no presente: sin fuente Work Sans embebida")
    set(WS_TTF_CPP "")
endif()

add_executable(HybridHeavenRecomp
    # platform: harness (SDL, RT64, arranque)
    src/platform/main.cpp
    src/platform/icon.cpp
    src/platform/rt64_render_context.cpp
    src/platform/spin_yield.cpp
    src/platform/support.cpp
    src/platform/config_ini.cpp
    src/platform/overlay.cpp
    src/platform/menu_sfx.cpp
    # hooks: capa de interceptacion (loaders, registro por direccion)
    src/hooks/sections.cpp
    src/hooks/dl_snap.cpp
    src/hooks/hud_rewrite.cpp
    src/hooks/hh_menu.cpp
    src/hooks/text_glyphs.cpp
    src/hooks/menu_overlay.cpp
    src/hooks/model_tagging.cpp
    # subsystems: piezas del juego portadas (input, trans, firmware)
    src/subsystems/input.cpp
    src/subsystems/trans_cache.cpp
    src/subsystems/text.cpp
    src/subsystems/font.cpp
    src/subsystems/ttf.cpp
    src/subsystems/menu.cpp
    src/subsystems/save_edit.cpp
    src/subsystems/subtitles.cpp
    src/subsystems/firmware.c

    # Recompiled functions.
    ${RECOMPILED_FUNCS}
    build/recomp/RecompiledFuncs/lookup.cpp

    # Microcodigo RSP recompilado (generado con RSPRecomp; no editar a mano).
    build/recomp/rsp/hh_aspMain.cpp

    # Fuente Work Sans embebida (generada en configure; vacio si no esta el .ttf).
    ${WS_TTF_CPP}
)

# Shaders del overlay (A2): se compilan a SPIRV (y DXIL/MSL segun plataforma) y se embeben como
# blobs. Los .spirv.h/.dxil.h se generan en ${CMAKE_BINARY_DIR}/shaders (ver target_include_directories).
build_vertex_shader(HybridHeavenRecomp "shaders/OverlayVS.hlsl" "shaders/OverlayVS.hlsl")
build_pixel_shader(HybridHeavenRecomp "shaders/OverlayPS.hlsl" "shaders/OverlayPS.hlsl")

if(MSVC)
    # Subsistema Windows: consola solo en Debug (terminal para depurar); en el resto de configs
    # (Release/RelWithDebInfo) el .exe es GUI -> una sola ventana, sin consola de fondo.
    # El punto de entrada es main() (SDL_MAIN_HANDLED), no WinMain -> /ENTRY:mainCRTStartup.
    target_link_options(HybridHeavenRecomp PRIVATE
        $<$<CONFIG:Debug>:/SUBSYSTEM:CONSOLE>
        $<$<NOT:$<CONFIG:Debug>>:/SUBSYSTEM:WINDOWS>
        $<$<NOT:$<CONFIG:Debug>>:/ENTRY:mainCRTStartup>
    )
endif()

target_include_directories(HybridHeavenRecomp PRIVATE
    include
    build/recomp/RecompiledFuncs
    ${CMAKE_BINARY_DIR}
    lib/rt64/include
    lib/rt64/src
    lib/rt64/src/contrib
    lib/rt64/src/contrib/imgui
    lib/rt64/src/contrib/hlslpp/include
    lib/N64ModernRuntime/N64Recomp/include
    lib/N64ModernRuntime/librecomp/include
    lib/N64ModernRuntime/ultramodern/include
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(HybridHeavenRecomp PRIVATE
    rt64
    ultramodern
    librecomp
    SDL2::SDL2
)

# Nombre del archivo de salida (sin afectar al nombre interno del target).
set_target_properties(HybridHeavenRecomp PROPERTIES OUTPUT_NAME "Hybrid Heaven Recomp")

# Datos del port junto al ejecutable: `assets/` (lang/logos/sounds), `licences/` (licencias) y
# `saves/` (datos del usuario). Ver AGENTS.md y docs/architecture.md.

# Tablas de idioma "de serie": copiar assets/lang a assets/lang/<code>.txt. Los idiomas extra se
# aportan como mods (mods/*/lang/<code>.txt). Ver src/subsystems/text.cpp.
add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets/lang"
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/lang")

# Subtítulos de las secuencias sin texto (intro/final): timing (independiente del idioma) en
# assets/subtitles/. Los textos van con las tablas de idioma (assets/lang/subtitles_<code>.txt).
# Ver src/subsystems/subtitles.cpp.
add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets/subtitles"
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/subtitles")

# Copia SIEMPRE los datos editables (lang + subtitles) junto al ejecutable. El POST_BUILD de arriba
# solo se dispara cuando el target se relinkea; si únicamente cambias un .txt (p. ej. una traducción)
# y recompilas sin cambios de código, no se copiaba. Este target se ejecuta en cada build.
add_custom_target(hh_copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets/lang"
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/lang"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets/subtitles"
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/subtitles"
    COMMENT "Copiando assets/lang + assets/subtitles junto al ejecutable")
add_dependencies(hh_copy_assets HybridHeavenRecomp)

# Licencias de terceros junto al ejecutable (licences/). La fuente Work Sans va INCRUSTADA; la OFL
# exige acompañar la licencia/copyright (licences/OFL.txt). Aquí irán las futuras.
add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/licences"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/assets/fonts/OFL.txt"
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/licences/OFL.txt")

# Efectos de sonido del menú: copiar solo los WAV a assets/sounds/*.wav. Los .mp3 de origen no van a
# la release. Ver src/platform/menu_sfx.cpp.
file(GLOB MENU_SFX_WAVS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/assets/sounds/*.wav")
add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/sounds"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${MENU_SFX_WAVS}
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/sounds")

# Logos de la intro en HD (KONAMI/KCEO): copiar assets/logos a assets/logos/*.png. Son assets de
# PRODUCTO (derivados de la ROM, pero obra del port); el overlay los dibuja. Ver src/hooks/sections.cpp.
file(GLOB INTRO_LOGO_PNGS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/assets/logos/*.png")
add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/logos"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${INTRO_LOGO_PNGS}
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/assets/logos")

# Plantillas de partida a `saves/templates/` (las usa EXTRAS -> ELEGIR NIVEL -> IR A NIVEL sin
# partida). `skip_indices.txt` NO se copia: lo crea el port si falta y el usuario lo edita.
# Ver src/subsystems/save_edit.cpp (load_template) y notes/2026-09-29-editor-area-parte-plan.md.
add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets/saves/templates"
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/saves/templates")

# NOTA: `skip_indices.txt` NO se copia en el build: lo crea el propio port con la lista por defecto
# embebida si no existe, y el usuario lo edita. Asi no se pisa nunca. Ver src/subsystems/menu.cpp.

if(WIN32)
    target_compile_definitions(HybridHeavenRecomp PRIVATE
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
    )

    # timeBeginPeriod (pacing preciso del replay en Windows; ver main.cpp).
    target_link_libraries(HybridHeavenRecomp PRIVATE winmm)

    # Embed the app icon into the .exe as a Windows resource (assets/HybridHeaven.ico,
    # versionado en el repo). Si falta, se compila sin icono embebido.
    set(APP_ICON "${PROJECT_SOURCE_DIR}/assets/HybridHeaven.ico")
    if(EXISTS "${APP_ICON}")
        enable_language(RC)
        configure_file(
            "${PROJECT_SOURCE_DIR}/assets/app.rc.in"
            "${CMAKE_CURRENT_BINARY_DIR}/app.rc"
            @ONLY
        )
        target_sources(HybridHeavenRecomp PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/app.rc")
    else()
        message(STATUS "assets/HybridHeaven.ico no presente: se compila sin icono embebido")
    endif()

    # Copy the SDL2 and DXC runtime DLLs next to the executable.
    add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/mupen64plus-win32-deps/SDL2-2.26.3/lib/x64/SDL2.dll"
            $<TARGET_FILE_DIR:HybridHeavenRecomp>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxcompiler.dll"
            $<TARGET_FILE_DIR:HybridHeavenRecomp>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${PROJECT_SOURCE_DIR}/lib/rt64/src/contrib/dxc/bin/x64/dxil.dll"
            $<TARGET_FILE_DIR:HybridHeavenRecomp>
    )
elseif(UNIX AND NOT APPLE)
    # The SDL window must be created as a Vulkan window so RT64 can create a
    # Vulkan surface from it (matches RT64_SDL_WINDOW_VULKAN, which is ON above).
    target_compile_definitions(HybridHeavenRecomp PRIVATE RT64_SDL_WINDOW_VULKAN)

    find_package(Threads REQUIRED)
    target_link_libraries(HybridHeavenRecomp PRIVATE Threads::Threads)

    # Desktop integration: install a .desktop entry + icon.
    set(APP_DISPLAY_NAME "Hybrid Heaven Recomp")
    set(APP_ICON_NAME "hybrid-heaven-recomp")
    configure_file(
        "${PROJECT_SOURCE_DIR}/assets/hybridheaven.desktop.in"
        "${CMAKE_CURRENT_BINARY_DIR}/hybridheaven.desktop"
        @ONLY
    )
    install(TARGETS HybridHeavenRecomp RUNTIME DESTINATION bin)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/hybridheaven.desktop"
            DESTINATION share/applications)
    if(EXISTS "${PROJECT_SOURCE_DIR}/assets/HybridHeaven.png")
        install(FILES "${PROJECT_SOURCE_DIR}/assets/HybridHeaven.png"
                DESTINATION share/icons/hicolor/256x256/apps
                RENAME "${APP_ICON_NAME}.png")
    endif()
endif()