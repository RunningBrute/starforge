#ifndef STARFORGE_EMITTER_RAIN_H
#define STARFORGE_EMITTER_RAIN_H

#include "starforge_emitter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float x_min;
    float x_max;
    int   rate;
} StarforgeRainEmitterConfig;

void starforge_emitter_rain_create(
    StarforgeEmitter* out_emitter,
    const StarforgeRainEmitterConfig* config
);

#ifdef __cplusplus
}
#endif

#endif
