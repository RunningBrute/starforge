#!/bin/sh

echo "Building Star Forge main..."
clang src/main.c \
      src/starforge_world.c \
      src/starforge_particlesystem.c \
      src/starforge_engine.c \
      -Iinclude -o bin/starforge

echo "Building ASCII demo..."
clang src/ascii_demo.c \
      src/frontend_ascii.c \
      src/starforge_world.c \
      src/starforge_particlesystem.c \
      src/starforge_engine.c \
      -Iinclude -o bin/starforge_ascii

echo "Building engine test..."
clang tests/test_engine.c tests/unity/unity.c \
     src/starforge_engine.c \
     src/starforge_world.c \
     src/starforge_particlesystem.c \
     -Iinclude -Itests/unity -o bin/tests_run

echo "Running tests..."
./bin/tests_run
