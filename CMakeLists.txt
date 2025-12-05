cmake_minimum_required(VERSION 3.16)
project(starforge C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)


if(STARFORGE_BUILD_RAYLIB)
   include(FetchContent)

   set(RAYLIB_VERSION 5.5)

   FetchContent_Declare(
     raylib
     URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
     DOWNLOAD_EXTRACT_TIMESTAMP OFF
   )

   FetchContent_MakeAvailable(raylib)
endif()

# ---------------------------------------
# Core library (engine + world + systems)
# ---------------------------------------

add_library(starforge_core

    src/starforge_engine.c
    src/starforge_world.c
    src/starforge_particlesystem.c

    src/starforge_backend_aos.c

    src/starforge_emitter_rain.c
    src/starforge_emitter_burst.c
)

target_include_directories(starforge_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(NOT WIN32)
    target_link_libraries(starforge_core m)
endif()

# ---------------------------------------
# ASCII frontend
# ---------------------------------------

add_library(starforge_frontend_ascii
    src/starforge_frontend_ascii.c
)

target_link_libraries(starforge_frontend_ascii
    starforge_core
)

# ---------------------------------------
# Raylib frontend
# ---------------------------------------
add_library(starforge_frontend_raylib
    src/starforge_frontend_raylib.c
)

target_link_libraries(starforge_frontend_raylib
    starforge_core
    raylib
)

# ---------------------------------------
# Main app
# ---------------------------------------

add_executable(starforge_core_app
    src/main.c
)

target_link_libraries(starforge_core_app
    starforge_core
)

# ---------------------------------------
# ASCII rain demo
# ---------------------------------------

add_executable(starforge_demo_rain
    demos/demo_rain.c
)

target_link_libraries(starforge_demo_rain
    starforge_core
    starforge_frontend_ascii
)

# ---------------------------------------
# ASCII burst demo
# ---------------------------------------

add_executable(starforge_demo_burst
    demos/demo_burst.c
)

target_link_libraries(starforge_demo_burst
    starforge_core
    starforge_frontend_ascii
)

# ---------------------------------------
# Raylib rain demo
# ---------------------------------------
add_executable(starforge_demo_raylib_rain
    demos/demo_raylib_rain.c
)

target_link_libraries(starforge_demo_raylib_rain
    starforge_core
    starforge_frontend_raylib
)

# ---------------------------------------
# Tests
# ---------------------------------------

add_executable(starforge_tests

    tests/test_engine.c
    tests/unity/unity.c
)

target_link_libraries(starforge_tests
    starforge_core
)
