#include <stdio.h>
#include <stdlib.h>

#include "starforge_world.h"
#include "starforge_particlesystem.h"

#define MAX_PARTICLES 2000

int main(void)
{
    StarforgeWorldForces world;
    starforge_world_init(&world);

    starforge_world_set_wind(&world, 2.0f, 0.0f);

    static StarforgeParticle pool[MAX_PARTICLES];

    StarforgeParticleSystem* rain =
        starforge_particlesystem_create(pool, MAX_PARTICLES);

    for (int frame = 0; frame < 60; ++frame)
    {
        starforge_particlesystem_emit_rain(rain, -20.0f, 20.0f, 40);
        starforge_particlesystem_update(rain, &world, 0.016f);

        int alive = 0;
        for (int i = 0; i < MAX_PARTICLES; ++i)
            if (pool[i].alive)
                alive++;

        printf("Frame %d | alive particles: %d\n", frame, alive);
    }

    starforge_particlesystem_destroy(rain);
    return 0;
}
