#include "starforge_emitter_fire.h"
#include "starforge_particlesystem.h"

#include <stdlib.h>
#include "starforge_math.h"

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
            .vx = frand(-10.0f, 10.0f),
            .vy = frand(40.0f, 80.0f),
            .life = frand(0.4f, 0.8f),
            .max_life = 0.8,
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
