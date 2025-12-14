#include "starforge_engine.h"
#include "starforge_emitter_rain.h"
#include "starforge_frontend_raylib.h"

#define MAX_PARTICLES 5000
#define MAX_SYSTEMS   4

int main(void)
{
    static StarforgeParticle pool[MAX_PARTICLES];

    StarforgeEngine* engine =
        starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);

    StarforgeWorldForces* world =
        starforge_engine_world(engine);

    starforge_world_set_wind(world, 4.0f, 0.2f);

    StarforgeParticleSystem* system =
        starforge_engine_create_system(engine, STARFORGE_BACKEND_AOS);

    StarforgeEmitter rain;
    StarforgeRainEmitterConfig cfg = {
        .x_min = -50.0f,
        .x_max =  50.0f,
        .rate  =  4
    };

    starforge_emitter_rain_create(&rain, &cfg);
    starforge_particlesystem_set_emitter(system, &rain);

    StarforgeFrontend frontend;
    starforge_frontend_raylib_create(&frontend);
    frontend.init(&frontend);

    const float dt = 0.016f;

    while (!WindowShouldClose())
    {
        starforge_engine_update(engine, dt);
        starforge_engine_render(engine, &frontend);
    }

    frontend.shutdown(&frontend);
    starforge_engine_destroy(engine);
    return 0;
}
