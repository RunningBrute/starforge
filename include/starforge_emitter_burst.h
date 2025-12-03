#ifndef STARFORGE_EMITTER_BURST_H
#define STARFORGE_EMITTER_BURST_H

#include "starforge_emitter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float x;
    float y;
    int   count;       /* how many particles in one burst */
    float speed_min;
    float speed_max;
} StarforgeBurstEmitterConfig;

void starforge_emitter_burst_create(
    StarforgeEmitter* out_emitter,
    const StarforgeBurstEmitterConfig* config
);

void starforge_emitter_burst_trigger(StarforgeEmitter* emitter);

#ifdef __cplusplus
}
#endif

#endif
