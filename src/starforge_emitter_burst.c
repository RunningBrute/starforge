#include "starforge_emitter_burst.h"
#include "starforge_particlesystem.h"

#include <stdlib.h>
#include <math.h>

typedef struct
{
    StarforgeBurstEmitterConfig cfg;
    int pending;
} BurstEmitterData;

static float randf(void)
{
    return (float)rand() / (float)RAND_MAX;
}

static void burst_emit(
    StarforgeEmitter* self,
    StarforgeParticleSystem* system,
    float dt)
{
    (void)dt;

    if (!self->enabled)
        return;

    BurstEmitterData* data =
        (BurstEmitterData*)self->context;

    if (data->pending <= 0)
        return;

    data->pending--;

    for (int i = 0; i < data->cfg.count; ++i)
    {
        float angle = randf() * 2.0f * 3.1415926f;
        float speed =
            data->cfg.speed_min +
            randf() * (data->cfg.speed_max - data->cfg.speed_min);

        float vx = cosf(angle) * speed;
        float vy = sinf(angle) * speed;

        starforge_particlesystem_emit_single(
            system,
            data->cfg.x,
            data->cfg.y,
            vx,
            vy
        );
    }
}

void starforge_emitter_burst_create(
    StarforgeEmitter* out_emitter,
    const StarforgeBurstEmitterConfig* config)
{
    BurstEmitterData* data =
        (BurstEmitterData*)malloc(sizeof(BurstEmitterData));

    data->cfg = *config;
    data->pending = 0;

    out_emitter->emit     = burst_emit;
    out_emitter->enabled  = 1;
    out_emitter->context = data;
}

void starforge_emitter_burst_trigger(
    StarforgeEmitter* emitter)
{
    BurstEmitterData* data =
        (BurstEmitterData*)emitter->context;

    data->pending++;
}
