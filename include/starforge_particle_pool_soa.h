#ifndef STARFORGE_PARTICLE_POOL_SOA_H
#define STARFORGE_PARTICLE_POOL_SOA_H

#include "starforge_particle_pool.h"
#include "starforge_particle_type.h"
#include "starforge_particle_pool_accessor.h"

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
    float* size;
    StarforgeParticleType* type;
    int* alive;

    StarforgeParticlePoolAccessor* accessor;
    int max_particles;
};

StarforgeParticlePool* starforge_particle_pool_soa_create(int max_particles);

StarforgeParticlePoolAccessor* starforge_particle_pool_accessor_get(StarforgeParticlePool* pool);

void starforge_particle_pool_soa_destroy(StarforgeParticlePool* pool);


#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_SOA_H */