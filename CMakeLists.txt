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

add_executable(HybridHeavenRecomp
    # platform: harness (SDL, RT64, arranque)
    src/platform/main.cpp
    src/platform/icon.cpp
    src/platform/rt64_render_context.cpp
    src/platform/spin_yield.cpp
    src/platform/support.cpp
    src/platform/overlay.cpp
    # hooks: capa de interceptacion (loaders, registro por direccion)
    src/hooks/sections.cpp
    src/hooks/dl_snap.cpp
    src/hooks/hud_rewrite.cpp
    src/hooks/hh_menu.cpp
    src/hooks/text_glyphs.cpp
    src/hooks/menu_overlay.cpp
    # subsystems: piezas del juego portadas (input, trans, firmware)
    src/subsystems/input.cpp
    src/subsystems/trans_cache.cpp
    src/subsystems/text.cpp
    src/subsystems/font.cpp
    src/subsystems/firmware.c

    # Recompiled functions.
    ${RECOMPILED_FUNCS}
    build/recomp/RecompiledFuncs/lookup.cpp

    # Microcodigo RSP recompilado (generado con RSPRecomp; no editar a mano).
    build/recomp/rsp/hh_aspMain.cpp
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

# Tablas de idioma "de serie": copiar assets/lang junto al ejecutable (lang/<code>.txt). Los idiomas
# extra se aportan como mods (mods/*/lang/<code>.txt). Ver src/subsystems/text.cpp.
add_custom_command(TARGET HybridHeavenRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets/lang"
        "$<TARGET_FILE_DIR:HybridHeavenRecomp>/lang")

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