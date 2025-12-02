#include <stdio.h>

#include "starforge_engine.h"

#define MAX_PARTICLES 2000
#define MAX_SYSTEMS   4

int main(void)
{
    static StarforgeParticle pool[MAX_PARTICLES];

    StarforgeEngine* engine =
        starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);

    /* Configure global world */
    StarforgeWorldForces* world =
        starforge_engine_world(engine);

    starforge_world_set_wind(world, 2.0f, 0.0f);

    /* Create rain system */
    StarforgeParticleSystem* rain =
        starforge_engine_create_system(engine);

    const float dt = 0.016f;

    for (int frame = 0; frame < 60; ++frame)
    {
        starforge_particlesystem_emit_rain(
            rain, -20.0f, 20.0f, 40
        );

        starforge_engine_update(engine, dt);

        int alive = 0;
        const StarforgeParticle* particles =
            starforge_engine_particles(engine, &alive);

        int count = 0;
        for (int i = 0; i < alive; ++i)
            if (particles[i].alive)
                count++;

        printf("Frame %d | alive particles: %d\n", frame, count);
    }

    starforge_engine_destroy(engine);
    return 0;
}
