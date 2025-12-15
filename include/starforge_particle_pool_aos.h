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

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_AOS_H */