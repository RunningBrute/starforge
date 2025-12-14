#include "starforge_engine.h"
#include "starforge_particlesystem.h"
#include "starforge_backend.h"
#include "starforge_frontend.h"
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
    StarforgeEngine* engine,
    BackendType backend_type)
{
    if (engine->system_count >= engine->max_systems)
        return NULL;

    StarforgeParticleSystem* sys =
        starforge_particlesystem_create(
            engine->global_pool,
            engine->max_particles,
            backend_type
        );

    engine->systems[engine->system_count++] = sys;
    return sys;
}

void starforge_engine_update(StarforgeEngine* engine, float dt)
{
    for (int i = 0; i < engine->system_count; ++i)
    {
        StarforgeParticleSystem* system = engine->systems[i];
        starforge_particlesystem_update(
            system,
            &engine->world,
            dt
        );
    }
}

const StarforgeParticle* starforge_engine_particles(
    const StarforgeEngine* engine,
    int* out_count)
{
    StarforgeParticleSystem* system = engine->systems[0];

    StarforgeParticleView view =
        system->backend->view(system->backend);

    *out_count = view.count;
    return view.particles;
}

void starforge_engine_render(
    const StarforgeEngine* engine,
    StarforgeFrontend* frontend)
{
    if (frontend && frontend->render)
        frontend->render(frontend, engine);
}
