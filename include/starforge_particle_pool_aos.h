#ifndef STARFORGE_PARTICLE_POOL_AOS_H
#define STARFORGE_PARTICLE_POOL_AOS_H

#include "starforge_particle_type.h"
#include "starforge_particle.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    StarforgeParticle* pool;

    int max_particles;
} StarforgeParticlePoolAoS;

StarforgeParticlePoolAoS starforge_particel_pool_aos_create(int max_particles);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_AOS_H */