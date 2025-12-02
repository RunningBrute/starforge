#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "starforge_engine.h"

#define MAX_PARTICLES 2000
#define MAX_SYSTEMS   4

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

#define WORLD_X_MIN  -40.0f
#define WORLD_X_MAX   40.0f
#define WORLD_Y_MIN  -10.0f
#define WORLD_Y_MAX   50.0f

static void clear_screen(void)
{
    printf("\x1b[2J\x1b[H");
}

int main(void)
{
    static StarforgeParticle pool[MAX_PARTICLES];

    StarforgeEngine* engine =
        starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);

    /* Configure global world */
    StarforgeWorldForces* world =
        starforge_engine_world(engine);

    starforge_world_set_wind(world, 4.0f, 0.0f);

    /* Create rain system inside engine */
    StarforgeParticleSystem* rain =
        starforge_engine_create_system(engine);

    const float dt = 0.05f;

    for (int frame = 0; frame < 400; ++frame)
    {
        starforge_particlesystem_emit_rain(
            rain, WORLD_X_MIN, WORLD_X_MAX, 80
        );

        starforge_engine_update(engine, dt);

        char buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

        for (int y = 0; y < SCREEN_HEIGHT; ++y)
            for (int x = 0; x < SCREEN_WIDTH; ++x)
                buffer[y][x] = ' ';

        int count;
        const StarforgeParticle* particles =
            starforge_engine_particles(engine, &count);

        int alive = 0;

        for (int i = 0; i < count; ++i)
        {
            const StarforgeParticle* p = &particles[i];
            if (!p->alive)
                continue;

            alive++;

            float nx = (p->x - WORLD_X_MIN) / (WORLD_X_MAX - WORLD_X_MIN);
            float ny = (WORLD_Y_MAX - p->y) / (WORLD_Y_MAX - WORLD_Y_MIN);

            int sx = (int)(nx * (SCREEN_WIDTH - 1));
            int sy = (int)(ny * (SCREEN_HEIGHT - 1));

            if (sx < 0 || sx >= SCREEN_WIDTH ||
                sy < 0 || sy >= SCREEN_HEIGHT)
                continue;

            buffer[sy][sx] = '/';
        }

        clear_screen();

        for (int y = 0; y < SCREEN_HEIGHT; ++y)
        {
            for (int x = 0; x < SCREEN_WIDTH; ++x)
                putchar(buffer[y][x]);
            putchar('\n');
        }

        printf("Frame %d | alive particles: %d\n", frame, alive);
        fflush(stdout);

        usleep(50000);
    }

    starforge_engine_destroy(engine);
    return 0;
}
