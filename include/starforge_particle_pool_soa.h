#ifndef STARFORGE_PARTICLE_POOL_SOA_H
#define STARFORGE_PARTICLE_POOL_SOA_H

#include "starforge_particle_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float* x;
    float* y;
    float* vx;
    float* vy;
    float* life;
    float* max_life;
    StarforgeParticleType* type;
    int* alive;

    int max_particles;
} StarforgeParticlePoolSoA;

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_SOA_H */