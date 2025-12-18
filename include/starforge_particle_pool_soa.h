#ifndef STARFORGE_PARTICLE_POOL_SOA_H
#define STARFORGE_PARTICLE_POOL_SOA_H

#include "starforge_particle_pool.h"
#include "starforge_particle_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticlePool
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
};

StarforgeParticlePool* starforge_particel_pool_soa_create(int max_particles);

void starforge_particel_pool_soa_destroy(StarforgeParticlePool* pool);


#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_SOA_H */