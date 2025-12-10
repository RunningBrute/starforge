#ifndef STARFORGE_EMITTER_FIRE_H
#define STARFORGE_EMITTER_FIRE_H

#include "starforge_emitter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float x;
    float y;
    int   rate;
} StarforgeFireEmitterConfig;

void starforge_emitter_fire_create(
    StarforgeEmitter* out_emitter,
    const StarforgeFireEmitterConfig* config
);

#ifdef __cplusplus
}
#endif

#endif
