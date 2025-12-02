#include <stdio.h>
#include <stdlib.h>

#include "starforge_frontend_ascii.h"
#include "starforge_engine.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

#define WORLD_X_MIN  -40.0f
#define WORLD_X_MAX   40.0f
#define WORLD_Y_MIN  -10.0f
#define WORLD_Y_MAX   50.0f

typedef struct
{
    int dummy;
} AsciiFrontendData;

static void clear_screen(void)
{
    printf("\x1b[2J\x1b[H");
}

static void ascii_init(StarforgeFrontend* self)
{
    self->context = malloc(sizeof(AsciiFrontendData));
}

static void ascii_shutdown(StarforgeFrontend* self)
{
    free(self->context);
}

static void ascii_render(
    StarforgeFrontend* self,
    const StarforgeEngine* engine)
{
    (void)self;

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

    printf("Alive particles: %d\n", alive);
}

void starforge_frontend_ascii_create(StarforgeFrontend* out_frontend)
{
    out_frontend->init     = ascii_init;
    out_frontend->render   = ascii_render;
    out_frontend->shutdown = ascii_shutdown;
    out_frontend->context  = NULL;
}
