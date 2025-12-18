#ifndef STARFORGE_PARTICLE_POOL_H
#define STARFORGE_PARTICLE_POOL_H

#include "starforge_particle_type.h"
#include "starforge_particle.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticlePool StarforgeParticlePool;

StarforgeParticlePool* starforge_particel_pool_create(int max_particles);

void starforge_particel_pool_destroy(StarforgeParticlePool* pool);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_AOS_H */