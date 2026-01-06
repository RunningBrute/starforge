#ifndef STARFORGE_PARTICLE_POOL_ACCESSOR_H
#define STARFORGE_PARTICLE_POOL_ACCESSOR_H

#include "starforge_particle_type.h"
#include "starforge_particle.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticlePool StarforgeParticlePool;

typedef struct StarforgeParticlePoolAccessor
{
    /* getters */
    float (*x)(StarforgeParticlePool* pool, int index);
    float (*y)(StarforgeParticlePool* pool, int index);
    float (*vx)(StarforgeParticlePool* pool, int index);
    float (*vy)(StarforgeParticlePool* pool, int index);
    float (*life)(StarforgeParticlePool* pool, int index);
    float (*max_life)(StarforgeParticlePool* pool, int index);
    float (*size)(StarforgeParticlePool* pool, int index);
    StarforgeParticleType (*type)(StarforgeParticlePool* pool, int index);
    int (*alive)(StarforgeParticlePool* pool, int index);

    /* setters */
    void (*set_x)(StarforgeParticlePool* pool, int index, float value);
    void (*set_y)(StarforgeParticlePool* pool, int index, float value);
    void (*set_vx)(StarforgeParticlePool* pool, int index, float value);
    void (*set_vy)(StarforgeParticlePool* pool, int index, float value);
    void (*set_life)(StarforgeParticlePool* pool, int index, float value);
    void (*set_max_life)(StarforgeParticlePool* pool, int index, float value);
    void (*set_size)(StarforgeParticlePool* pool, int index, float value);
    void (*set_type)(StarforgeParticlePool* pool, int index, StarforgeParticleType value);
    void (*set_alive)(StarforgeParticlePool* pool, int index, int value);
} StarforgeParticlePoolAccessor;

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_ACCESSOR_H */
