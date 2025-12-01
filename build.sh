#!/bin/sh

echo "Building Star Forge..."
clang src/main.c \
      src/starforge_world.c \
      src/starforge_particlesystem.c \
      src/starforge_engine.c \
      -Iinclude -o bin/starforge

echo "Building tests..."
clang tests/test_main.c tests/test_engine.c tests/unity/unity.c \
     src/starforge_engine.c \
     -Iinclude -Itests/unity -o bin/tests_run

echo "Running tests..."
./bin/tests_run
