cmake_minimum_required(VERSION 3.16)
project(starforge C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ---------------------------------------
# Core library (engine + world + systems)
# ---------------------------------------

add_library(starforge_core

    src/starforge_engine.c
    src/starforge_world.c
    src/starforge_particlesystem.c

    src/starforge_emitter_rain.c
    src/starforge_emitter_burst.c
)

target_include_directories(starforge_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(starforge_core m)

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
# Main app
# ---------------------------------------

add_executable(starforge_core_app
    src/main.c
)

target_link_libraries(starforge_core_app
    starforge_core
)

# ---------------------------------------
# Demo: Rain
# ---------------------------------------

add_executable(starforge_demo_rain
    demos/demo_rain.c
)

target_link_libraries(starforge_demo_rain
    starforge_core
    starforge_frontend_ascii
)

# ---------------------------------------
# Demo: Burst
# ---------------------------------------

add_executable(starforge_demo_burst
    demos/demo_burst.c
)

target_link_libraries(starforge_demo_burst
    starforge_core
    starforge_frontend_ascii
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
