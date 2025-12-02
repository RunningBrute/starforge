#include "starforge_engine.h"
#include <stdlib.h>

struct StarforgeEngine
{
    StarforgeWorldForces world;

    StarforgeParticle* global_pool;
    int max_particles;

    StarforgeParticleSystem** systems;
    int max_systems;
    int system_count;
};

StarforgeEngine* starforge_engine_create(
    StarforgeParticle* global_pool,
    int max_particles,
    int max_systems)
{
    StarforgeEngine* engine =
        (StarforgeEngine*)malloc(sizeof(StarforgeEngine));

    starforge_world_init(&engine->world);

    engine->global_pool = global_pool;
    engine->max_particles = max_particles;

    engine->systems =
        (StarforgeParticleSystem**)malloc(
            max_systems * sizeof(StarforgeParticleSystem*)
        );

    engine->max_systems = max_systems;
    engine->system_count = 0;

    return engine;
}

void starforge_engine_destroy(StarforgeEngine* engine)
{
    for (int i = 0; i < engine->system_count; ++i)
        starforge_particlesystem_destroy(engine->systems[i]);

    free(engine->systems);
    free(engine);
}

StarforgeWorldForces* starforge_engine_world(StarforgeEngine* engine)
{
    return &engine->world;
}

StarforgeParticleSystem* starforge_engine_create_system(
    StarforgeEngine* engine)
{
    if (engine->system_count >= engine->max_systems)
        return NULL;

    StarforgeParticleSystem* sys =
        starforge_particlesystem_create(
            engine->global_pool,
            engine->max_particles
        );

    engine->systems[engine->system_count++] = sys;
    return sys;
}

void starforge_engine_update(StarforgeEngine* engine, float dt)
{
    for (int i = 0; i < engine->system_count; ++i)
    {
        starforge_particlesystem_update(
            engine->systems[i],
            &engine->world,
            dt
        );
    }
}

const StarforgeParticle* starforge_engine_particles(
    const StarforgeEngine* engine,
    int* out_count)
{
    *out_count = engine->max_particles;
    return engine->global_pool;
}
