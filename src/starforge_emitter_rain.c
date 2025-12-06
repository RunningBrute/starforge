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

    while (system->max_particles && count > 0)
    {
        float x_proto = x_min + (float)rand() / (float)RAND_MAX * (x_max - x_min);
        
        StarforgeParticle proto = {
            .alive = 1,
            .type = STARFORGE_PARTICLE_RAIN,
            .x = x_proto,
            .y = 50.0f,
            .vx = 0.0f,
            .vy = -5.0f,
            .life = 3.0f,
            .max_life = 3.0f,
            .size = 1.0f
        };
        
        system->backend->spawn(system->backend, &proto);
        count--;
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
