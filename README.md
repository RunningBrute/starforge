# Star Forge

Experimental particle simulation engine written in pure C.

---

## Build & Test

![CI](https://github.com/RunningBrute/starforge/actions/workflows/ci.yml/badge.svg)

---

## Requirements

To build and run Star Forge you need just:

- clang
- git
- standard shell (sh)

On Termux / Linux:

pkg install clang git

On Ubuntu:

sudo apt install clang git

---

## Build

Build binary:

./build.sh

The output binary will be placed in:

bin/starforge

---

## Run

After building:

./bin/starforge

---

## Unit Tests

Unit tests are written using the Unity testing framework for C.

Tests are executed automatically as part of the build:

./build.sh

Test binary is located in:

./bin/tests_run

---

## Visualization using ASCII art

./bin/starforge_ascii

---

## Testing Framework (Unity)

This project uses the Unity unit testing framework for the C language:

https://github.com/ThrowTheSwitch/Unity

Unity source files are included in this repository under:

tests/unity/

All rights remain with the original authors.

---
