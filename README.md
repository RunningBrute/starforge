# StarForge

Modular particle simulation engine written in pure C with pluggable emitters and frontends.

Supported features:
- Continuous emitters (Rain)
- Event-based emitters (Burst / Explosions)
- ASCII frontend
- Portable build using CMake (Linux, Termux, Windows)

---

## Build Status

![CI](https://github.com/RunningBrute/starforge/actions/workflows/ci.yml/badge.svg)

---

## Requirements

### Termux / Linux
`pkg install clang cmake make git`

### Ubuntu
`sudo apt install clang cmake make git`

### Windows
Visual Studio with CMake

---

## Build (CMake)

```
git clone https://github.com/RunningBrute/starforge.git
cd starforge
```

### Termux / Linux

```
mkdir build 
cd build
cmake ..
make
```

### Windows

```
mkdir build
cd build
cmake -G Ninja ..
ninja
```

---

## Run demos

```
Rain demo:
./starforge_demo_rain

Burst / Explosion demo:
./starforge_demo_burst
```

---

## Run tests

```
./starforge_tests
```

---

## Project structure

`include/`        - Engine API  
`src/`            - Core engine, emitters and frontends  
`demos/`          - Showcase applications  
`tests/`         - Unit tests (Unity)  
`build/`          - CMake build output  

---

## Termux support

StarForge builds and runs directly on Android using Termux with Clang and CMake.

---
