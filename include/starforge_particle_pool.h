#ifndef STARFORGE_PARTICLE_POOL_H
#define STARFORGE_PARTICLE_POOL_H

#include "starforge_particle_type.h"
#include "starforge_particle.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticlePool StarforgeParticlePool;

StarforgeParticlePool* starforge_particel_pool_create(int max_particles);

float get_x(StarforgeParticlePool* pool);
float get_y(StarforgeParticlePool* pool);
float get_vx(StarforgeParticlePool* pool);
float get_vy(StarforgeParticlePool* pool);
float get_life(StarforgeParticlePool* pool);
float get_max_life(StarforgeParticlePool* pool);
float get_size(StarforgeParticlePool* pool);
StarforgeParticleType get_type(StarforgeParticlePool* pool);
int get_alive(StarforgeParticlePool* pool);

void starforge_particel_pool_destroy(StarforgeParticlePool* pool);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_AOS_H */