cmake_minimum_required (VERSION 3.10)

# installation setup
set (INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set (INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set (INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
if (WIN32 AND NOT CYGWIN)
    set (DEF_INSTALL_CMAKE_DIR CMake)
else ()
    set (DEF_INSTALL_CMAKE_DIR lib/CMake/ArcticWolf)
endif ()
set (INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute
foreach (p LIB BIN INCLUDE CMAKE)
    set (var INSTALL_${p}_DIR)
    if (NOT IS_ABSOLUTE "${${var}}")
        set (${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
    endif ()
endforeach ()

# build type selection
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

# notify of the build type in use
message (STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# project definition
set (ArcticWolf_VERSION_MAJOR 0)
set (ArcticWolf_VERSION_MINOR 0)
set (ArcticWolf_VERSION_PATCH 0)
project (
    ArcticWolf
    VERSION ${ArcticWolf_VERSION_MAJOR}.${ArcticWolf_VERSION_MINOR}.${ArcticWolf_VERSION_PATCH}
    DESCRIPTION "high-performance 2D C++/OpenGL game engine"
)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
set (CMAKE_CXX_FLAGS_DEBUG "-g -Og")
set (CMAKE_CXX_FLAGS_RELEASE "-O3")
configure_file (
    ${PROJECT_SOURCE_DIR}/include/ArcticWolf.hpp.in
    ${PROJECT_SOURCE_DIR}/include/ArcticWolf.hpp
)
include_directories (
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
)

# debug mode testing/analysis
unset (CMAKE_CXX_CPPCHECK CACHE)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message (STATUS "Testing/Analysis Enabled")
    find_program (CMAKE_CXX_CPPCHECK NAMES cppcheck)
    if (CMAKE_CXX_CPPCHECK)
        list (APPEND CMAKE_CXX_CPPCHECK
            "--enable=warning"
            "--inconclusive"
            "--force"
            "--inline-suppr"
        )
    else ()
        message (WARNING "Could not find CPPCheck executable. CPPCheck testing disabled.")
    endif ()
else ()
    message (STATUS "Testing/Analysis Disabled")
    set (CMAKE_CXX_CPPCHECK)
endif ()

# documentation
configure_file (
    ${PROJECT_SOURCE_DIR}/Doxyfile.in
    ${PROJECT_SOURCE_DIR}/Doxyfile
    @ONLY
)

# list of sources (just for compilation)
list (APPEND SOURCES

    # bundled libraries
    ${PROJECT_SOURCE_DIR}/lib/FastNoise/FastNoise.cpp

    # game engine
    ${PROJECT_SOURCE_DIR}/src/AssetStore.cpp
    ${PROJECT_SOURCE_DIR}/src/Button.cpp
    ${PROJECT_SOURCE_DIR}/src/Console.cpp
    ${PROJECT_SOURCE_DIR}/src/ConsoleLogObserver.cpp
    ${PROJECT_SOURCE_DIR}/src/Controller.cpp
    ${PROJECT_SOURCE_DIR}/src/Entity.cpp
    ${PROJECT_SOURCE_DIR}/src/EntityComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/File.cpp
    ${PROJECT_SOURCE_DIR}/src/FileLogObserver.cpp
    ${PROJECT_SOURCE_DIR}/src/FunctionLogObserver.cpp
    ${PROJECT_SOURCE_DIR}/src/GameLoop.cpp
    ${PROJECT_SOURCE_DIR}/src/GameState.cpp
    ${PROJECT_SOURCE_DIR}/src/GameStateManager.cpp
    ${PROJECT_SOURCE_DIR}/src/GameStateStore.cpp
    ${PROJECT_SOURCE_DIR}/src/Keybinding.cpp
    ${PROJECT_SOURCE_DIR}/src/Layer.cpp
    ${PROJECT_SOURCE_DIR}/src/Log.cpp
    ${PROJECT_SOURCE_DIR}/src/LogObserver.cpp
    ${PROJECT_SOURCE_DIR}/src/LoopKeybinding.cpp
    ${PROJECT_SOURCE_DIR}/src/ProgressBar.cpp
    ${PROJECT_SOURCE_DIR}/src/Renderable.cpp
    ${PROJECT_SOURCE_DIR}/src/Renderer.cpp
    ${PROJECT_SOURCE_DIR}/src/Scene.cpp
    ${PROJECT_SOURCE_DIR}/src/SceneStore.cpp
    ${PROJECT_SOURCE_DIR}/src/SpriteComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/SpriteLayer.cpp
    ${PROJECT_SOURCE_DIR}/src/SpriteRenderable.cpp
    ${PROJECT_SOURCE_DIR}/src/TileLayer.cpp
    ${PROJECT_SOURCE_DIR}/src/TileSet.cpp
    ${PROJECT_SOURCE_DIR}/src/TileType.cpp
    ${PROJECT_SOURCE_DIR}/src/UIElement.cpp
    ${PROJECT_SOURCE_DIR}/src/UILayer.cpp
    ${PROJECT_SOURCE_DIR}/src/UIRenderable.cpp
    ${PROJECT_SOURCE_DIR}/src/Window.cpp

)

# list of header file (the public API)
list (APPEND HEADERS

    # config code
    ${PROJECT_SOURCE_DIR}/include/ArcticWolf.hpp

    # bundled libraries
    ${PROJECT_SOURCE_DIR}/lib/args/args.hxx
    ${PROJECT_SOURCE_DIR}/lib/FastNoise/FastNoise.h

    # game engine
    ${PROJECT_SOURCE_DIR}/include/AssetStore.hpp
    ${PROJECT_SOURCE_DIR}/include/Button.hpp
    ${PROJECT_SOURCE_DIR}/include/Console.hpp
    ${PROJECT_SOURCE_DIR}/include/ConsoleLogObserver.hpp
    ${PROJECT_SOURCE_DIR}/include/Controller.hpp
    ${PROJECT_SOURCE_DIR}/include/Entity.hpp
    ${PROJECT_SOURCE_DIR}/include/EntityComponent.hpp
    ${PROJECT_SOURCE_DIR}/include/File.hpp
    ${PROJECT_SOURCE_DIR}/include/FileLogObserver.hpp
    ${PROJECT_SOURCE_DIR}/include/FunctionLogObserver.hpp
    ${PROJECT_SOURCE_DIR}/include/GameLoop.hpp
    ${PROJECT_SOURCE_DIR}/include/GameState.hpp
    ${PROJECT_SOURCE_DIR}/include/GameStateManager.hpp
    ${PROJECT_SOURCE_DIR}/include/GameStateStore.hpp
    ${PROJECT_SOURCE_DIR}/include/Keybinding.hpp
    ${PROJECT_SOURCE_DIR}/include/Layer.hpp
    ${PROJECT_SOURCE_DIR}/include/Log.hpp
    ${PROJECT_SOURCE_DIR}/include/LogLevel.hpp
    ${PROJECT_SOURCE_DIR}/include/LogObserver.hpp
    ${PROJECT_SOURCE_DIR}/include/LoopKeybinding.hpp
    ${PROJECT_SOURCE_DIR}/include/PointerGreater.hpp
    ${PROJECT_SOURCE_DIR}/include/PointerLess.hpp
    ${PROJECT_SOURCE_DIR}/include/PriorityVector.hpp
    ${PROJECT_SOURCE_DIR}/include/ProgressBar.hpp
    ${PROJECT_SOURCE_DIR}/include/Renderable.hpp
    ${PROJECT_SOURCE_DIR}/include/Renderer.hpp
    ${PROJECT_SOURCE_DIR}/include/Scene.hpp
    ${PROJECT_SOURCE_DIR}/include/SceneStore.hpp
    ${PROJECT_SOURCE_DIR}/include/SpriteComponent.hpp
    ${PROJECT_SOURCE_DIR}/include/SpriteLayer.hpp
    ${PROJECT_SOURCE_DIR}/include/SpriteRenderable.hpp
    ${PROJECT_SOURCE_DIR}/include/TileLayer.hpp
    ${PROJECT_SOURCE_DIR}/include/TilePlane.hpp
    ${PROJECT_SOURCE_DIR}/include/TileRenderable.hpp
    ${PROJECT_SOURCE_DIR}/include/TileSet.hpp
    ${PROJECT_SOURCE_DIR}/include/TileType.hpp
    ${PROJECT_SOURCE_DIR}/include/UIElement.hpp
    ${PROJECT_SOURCE_DIR}/include/UILayer.hpp
    ${PROJECT_SOURCE_DIR}/include/UIRenderable.hpp
    ${PROJECT_SOURCE_DIR}/include/Window.hpp

)

# library output
set (LIBRARY_NAME "ArcticWolf")
add_library (${LIBRARY_NAME} SHARED ${SOURCES})
set_target_properties (${LIBRARY_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties (${LIBRARY_NAME} PROPERTIES SOVERSION ${ArcticWolf_VERSION_MAJOR})
set_target_properties (${LIBRARY_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")
set_target_properties (${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
configure_file (
    ${PROJECT_SOURCE_DIR}/ArcticWolf.pc.in
    ${PROJECT_SOURCE_DIR}/ArcticWolf.pc
    @ONLY
)

# find_package stuff
export (
    TARGETS ${LIBRARY_NAME}
    FILE ${PROJECT_BINARY_DIR}/ArcticWolfTargets.cmake
)
export (PACKAGE ArcticWolf)
file (RELATIVE_PATH REL_INCLUDE_DIR ${INSTALL_CMAKE_DIR}
    ${INSTALL_INCLUDE_DIR}
)
set (CONF_INCLUDE_DIRS
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_BINARY_DIR}
)
configure_file (
    ${PROJECT_SOURCE_DIR}/ArcticWolfConfig.cmake.in
    ${PROJECT_SOURCE_DIR}/ArcticWolfConfig.cmake
    @ONLY
)
set (CONF_INCLUDE_DIRS
    ${REL_INCLUDE_DIR}
)
configure_file (
    ${PROJECT_SOURCE_DIR}/ArcticWolfConfig.cmake.in
    ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/ArcticWolfConfig.cmake
    @ONLY
)
configure_file (
    ${PROJECT_SOURCE_DIR}/ArcticWolfConfigVersion.cmake.in
    ${PROJECT_SOURCE_DIR}/ArcticWolfConfigVersion.cmake
    @ONLY
)

# cmake modules
set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules ${CMAKE_MODULE_PATH})

# dependencies
find_package (SFML 2 REQUIRED audio graphics window system)
if (SFML_FOUND)
    include_directories (${SFML_INCLUDE_DIR})
    target_link_libraries (${LIBRARY_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# installation
include (GNUInstallDirs)
install (TARGETS ${LIBRARY_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ArcticWolf
)
install (
    FILES ${CMAKE_BINARY_DIR}/ArcticWolf.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)
install (
    FILES
        ${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/ArcticWolfConfig.cmake
        ${PROJECT_BINARY_DIR}/ArcticWolfConfigVersion.cmake
    DESTINATION ${INSTALL_CMAKE_DIR}
    COMPONENT dev
)

# packaging
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE ${PROJECT_SOURCE_DIR}/LICENSE)
set (CPACK_RESOURCE_VERSION_MAJOR ${ArcticWolf_VERSION_MAJOR})
set (CPACK_RESOURCE_VERSION_MINOR ${ArcticWolf_VERSION_MINOR})
set (CPACK_RESOURCE_VERSION_PATCH ${ArcticWolf_VERSION_PATCH})
include (CPack)
