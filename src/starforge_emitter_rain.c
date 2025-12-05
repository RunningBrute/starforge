#include "starforge_emitter_rain.h"
#include "starforge_particlesystem.h"

#include <stdlib.h>

typedef struct
{
    StarforgeRainEmitterConfig cfg;
} RainEmitterData;

static void rain_emit(
    StarforgeEmitter* self,
    StarforgeParticleSystem* system,
    float dt)
{
    (void)dt;

    if (!self->enabled)
        return;

    RainEmitterData* data = (RainEmitterData*)self->context;

    float x_min = data->cfg.x_min;
    float x_max =  data->cfg.x_max;
    int count = data->cfg.rate;

    for (int i = 0; i < system->max_particles && count > 0; ++i)
    {
        if (!system->pool[i].alive)
        {
            StarforgeParticle* p = &system->pool[i];

            p->alive = 1;
            p->type = STARFORGE_PARTICLE_RAIN;

            p->x = x_min + (float)rand() / (float)RAND_MAX * (x_max - x_min);
            p->y = 50.0f;

            p->vx = 0.0f;
            p->vy = -5.0f;

            p->life = 3.0f;
            p->max_life = 3.0f;

            p->size = 1.0f;

            p->r = 0.4f;
            p->g = 0.6f;
            p->b = 1.0f;
            p->a = 1.0f;

            count--;
        }
    }
}

void starforge_emitter_rain_create(
    StarforgeEmitter* out_emitter,
    const StarforgeRainEmitterConfig* config)
{
    RainEmitterData* data =
        (RainEmitterData*)malloc(sizeof(RainEmitterData));

    data->cfg = *config;

    out_emitter->emit    = rain_emit;
    out_emitter->enabled = 1;
    out_emitter->context = data;
}
