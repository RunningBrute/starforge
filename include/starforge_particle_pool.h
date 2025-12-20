#ifndef STARFORGE_PARTICLE_POOL_H
#define STARFORGE_PARTICLE_POOL_H

#include "starforge_particle_type.h"
#include "starforge_particle.h"
#include "starforge_particle_pool_accessor.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticlePool StarforgeParticlePool;

StarforgeParticlePool* starforge_particle_pool_aos_create(int max_particles);

StarforgeParticlePool* starforge_particle_pool_soa_create(int max_particles);

const StarforgeParticlePoolAccessor* starforge_particle_pool_accessor_get(const StarforgeParticlePool* pool);

void starforge_particle_pool_aos_destroy(StarforgeParticlePool* pool);

void starforge_particle_pool_soa_destroy(StarforgeParticlePool* pool);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_H */