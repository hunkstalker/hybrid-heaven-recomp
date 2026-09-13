cmake_minimum_required(VERSION 3.20)
project(HybridHeavenRecomp LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(MSVC)
    # Required for correct recompiled function callbacks.
    add_compile_options(/EHsc)
    add_link_options(/SUBSYSTEM:CONSOLE)
else()
    # Recompiled MIPS code needs x64 baseline instructions.
    # SSSE3 lo requiere la implementacion VU del runtime RSP (rsp_vu_impl.hpp, _mm_shuffle_epi8).
    add_compile_options(-O2 -msse4.1)
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

file(GLOB RECOMPILED_FUNCS CONFIGURE_DEPENDS RecompiledFuncs/funcs_*.c)

add_executable(HybridHeavenRecomp
    src/main/main.cpp
    src/main/icon.cpp
    src/main/rt64_render_context.cpp
    src/main/register_overlays.cpp
    src/main/support.cpp
    src/game/input.cpp
    src/game/firmware.c

    # Recompiled functions.
    ${RECOMPILED_FUNCS}
    RecompiledFuncs/lookup.cpp

    # Microcodigo RSP recompilado (generado con RSPRecomp; no editar a mano).
    rsp/hh_aspMain.cpp
)

target_include_directories(HybridHeavenRecomp PRIVATE
    include
    RecompiledFuncs
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

if(WIN32)
    target_compile_definitions(HybridHeavenRecomp PRIVATE
        NOMINMAX
        _CRT_SECURE_NO_WARNINGS
    )

    # Embed the app icon into the .exe as a Windows resource.
    enable_language(RC)
    set(APP_ICON "${PROJECT_SOURCE_DIR}/assets/HybridHeaven.ico")
    configure_file(
        "${PROJECT_SOURCE_DIR}/assets/app.rc.in"
        "${CMAKE_CURRENT_BINARY_DIR}/app.rc"
        @ONLY
    )
    target_sources(HybridHeavenRecomp PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/app.rc")

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
    install(FILES "${PROJECT_SOURCE_DIR}/assets/HybridHeaven.png"
            DESTINATION share/icons/hicolor/256x256/apps
            RENAME "${APP_ICON_NAME}.png")
endif()