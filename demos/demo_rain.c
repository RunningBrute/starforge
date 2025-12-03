#include <unistd.h>

#include "starforge_engine.h"
#include "starforge_frontend_ascii.h"
#include "starforge_emitter_rain.h"

#define MAX_PARTICLES 3000
#define MAX_SYSTEMS   4

int main(void)
{
    static StarforgeParticle pool[MAX_PARTICLES];

    StarforgeEngine* engine =
        starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);

    /* Global world config */
    StarforgeWorldForces* world =
        starforge_engine_world(engine);

    starforge_world_set_wind(world, 3.0f, 0.0f);

    /* Particle system */
    StarforgeParticleSystem* system =
        starforge_engine_create_system(engine);

    /* Rain emitter */
    StarforgeEmitter rain;
    StarforgeRainEmitterConfig cfg = {
        .x_min = -40.0f,
        .x_max =  40.0f,
        .rate  =  80
    };

    starforge_emitter_rain_create(&rain, &cfg);
    starforge_particlesystem_set_emitter(system, &rain);

    /* ASCII frontend */
    StarforgeFrontend ascii;
    starforge_frontend_ascii_create(&ascii);
    ascii.init(&ascii);

    const float dt = 0.05f;

    for (;;)
    {
        starforge_engine_update(engine, dt);
        starforge_engine_render(engine, &ascii);

        usleep(50000);
    }

    ascii.shutdown(&ascii);
    starforge_engine_destroy(engine);
    return 0;
}
