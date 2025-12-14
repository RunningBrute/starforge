#include <benchmark/benchmark.h>

#include "starforge_engine.h"
#include "starforge_particlesystem.h"
#include "starforge_emitter_rain.h"

#define MAX_PARTICLES 2000000
#define MAX_SYSTEMS   1

static void benchmark_AoS(benchmark::State& state)
{
    static StarforgeParticle pool[MAX_PARTICLES];
    StarforgeEngine* engine = starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);
    
    StarforgeWorldForces* world = starforge_engine_world(engine);
    starforge_world_set_wind(world, 3.0f, 0.0f);
    
    StarforgeParticleSystem* system =
        starforge_engine_create_system(engine, BackendType::STARFORGE_BACKEND_AOS);

    StarforgeEmitter rain;
    StarforgeRainEmitterConfig cfg;
    cfg.x_min = -40.0f;
    cfg.x_max =  40.0f;
    cfg.rate  =  80;

    starforge_emitter_rain_create(&rain, &cfg);
    starforge_particlesystem_set_emitter(system, &rain);

    for (auto _ : state) starforge_engine_update(engine, 0.016f);

    starforge_engine_destroy(engine);
}
BENCHMARK(benchmark_AoS);

static void benchmark_SoA(benchmark::State& state)
{
    static StarforgeParticle pool[MAX_PARTICLES];
    StarforgeEngine* engine = starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);
    
    StarforgeWorldForces* world = starforge_engine_world(engine);
    starforge_world_set_wind(world, 3.0f, 0.0f);
    
    StarforgeParticleSystem* system =
        starforge_engine_create_system(engine, BackendType::STARFORGE_BACKEND_SOA);

    StarforgeEmitter rain;
    StarforgeRainEmitterConfig cfg;
    cfg.x_min = -40.0f;
    cfg.x_max =  40.0f;
    cfg.rate  =  80;

    starforge_emitter_rain_create(&rain, &cfg);
    starforge_particlesystem_set_emitter(system, &rain);

    for (auto _ : state) starforge_engine_update(engine, 0.016f);

    starforge_engine_destroy(engine);
}
BENCHMARK(benchmark_SoA);

static void benchmark_AVX2(benchmark::State& state)
{
    static StarforgeParticle pool[MAX_PARTICLES];
    StarforgeEngine* engine = starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);
    
    StarforgeWorldForces* world = starforge_engine_world(engine);
    starforge_world_set_wind(world, 3.0f, 0.0f);
    
    StarforgeParticleSystem* system =
        starforge_engine_create_system(engine, BackendType::STARFORGE_BACKEND_AVX2);

    StarforgeEmitter rain;
    StarforgeRainEmitterConfig cfg;
    cfg.x_min = -40.0f;
    cfg.x_max =  40.0f;
    cfg.rate  =  80;

    starforge_emitter_rain_create(&rain, &cfg);
    starforge_particlesystem_set_emitter(system, &rain);

    for (auto _ : state) starforge_engine_update(engine, 0.016f);

    starforge_engine_destroy(engine);
}
BENCHMARK(benchmark_AVX2);

BENCHMARK_MAIN();
