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

    starforge_particlesystem_emit_rain(
        system,
        data->cfg.x_min,
        data->cfg.x_max,
        data->cfg.rate
    );
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
