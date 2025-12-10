#include "starforge_emitter_fire.h"
#include "starforge_particlesystem.h"

#include <stdlib.h>

typedef struct
{
    StarforgeFireEmitterConfig cfg;
} FireEmitterData;

static void fire_emit(
    StarforgeEmitter* self,
    StarforgeParticleSystem* system,
    float dt)
{
    (void)dt;

    if (!self->enabled)
        return;

    FireEmitterData* data = (FireEmitterData*)self->context;

    float x = data->cfg.x;
    float y =  data->cfg.y;
    int count = data->cfg.rate;

    while (system->max_particles && count > 0)
    {
        StarforgeParticle proto = {
            .alive = 1,
            .type = STARFORGE_PARTICLE_FIRE,
            .x = x,
            .y = y,
            .vx = 0.0f,
            .vy = -5.0f,
            .life = 5.0f,
            .max_life = 3.0f,
            .size = 1.0f
        };

        system->backend->spawn(system->backend, &proto);
        count--;
    }
}

void starforge_emitter_fire_create(
    StarforgeEmitter* out_emitter,
    const StarforgeFireEmitterConfig* config)
{
    FireEmitterData* data =
        (FireEmitterData*)malloc(sizeof(FireEmitterData));

    data->cfg = *config;

    out_emitter->emit    = fire_emit;
    out_emitter->enabled = 1;
    out_emitter->context = data;
}
