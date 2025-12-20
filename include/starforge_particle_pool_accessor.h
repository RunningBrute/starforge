#ifndef STARFORGE_PARTICLE_POOL_ACCESSOR_H
#define STARFORGE_PARTICLE_POOL_ACCESSOR_H

#include "starforge_particle_type.h"
#include "starforge_particle.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticlePoolAccessor
{
    float (*x)(void* pool, int index);
    float (*y)(void* pool, int index);
    float (*vx)(void* pool, int index);
    float (*vy)(void* pool, int index);
    float (*life)(void* pool, int index);
    float (*max_life)(void* pool, int index);
    float (*size)(void* pool, int index);
    StarforgeParticleType (*type)(void* pool, int index);
    int (*alive)(void* pool, int index);
} StarforgeParticlePoolAccessor;

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_ACCESSOR_H */