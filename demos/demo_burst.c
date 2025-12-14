#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "starforge_engine.h"
#include "starforge_frontend_ascii.h"
#include "starforge_emitter_burst.h"

#define MAX_PARTICLES 3000
#define MAX_SYSTEMS   4

int main(void)
{
    static StarforgeParticle pool[MAX_PARTICLES];

    StarforgeEngine* engine =
        starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);

    StarforgeWorldForces* world =
        starforge_engine_world(engine);

    starforge_world_set_wind(world, 0.0f, 0.0f);

    StarforgeParticleSystem* system =
        starforge_engine_create_system(engine, STARFORGE_BACKEND_AOS);

    /* Burst emitter */
    StarforgeEmitter burst;
    StarforgeBurstEmitterConfig cfg = {
        .x = 0.0f,
        .y = 0.0f,
        .count = 120,
        .speed_min = 5.0f,
        .speed_max = 20.0f
    };

    starforge_emitter_burst_create(&burst, &cfg);
    starforge_particlesystem_set_emitter(system, &burst);

    /* ASCII frontend */
    StarforgeFrontend ascii;
    starforge_frontend_ascii_create(&ascii);
    ascii.init(&ascii);

    const float dt = 0.05f;

    int timer = 0;

    for (;;)
    {
        timer++;

        /* Trigger explosion every ~2 seconds */
        if (timer % 40 == 0)
        {
            starforge_emitter_burst_trigger(&burst);
        }

        starforge_engine_update(engine, dt);
        starforge_engine_render(engine, &ascii);

        #ifdef _WIN32
            Sleep(50);       // milliseconds
        #else
            usleep(50000);  // microseconds
        #endif
    }

    ascii.shutdown(&ascii);
    starforge_engine_destroy(engine);
    return 0;
}
