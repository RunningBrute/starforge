#ifndef STARFORGE_PARTICLE_POOL_H
#define STARFORGE_PARTICLE_POOL_H

#include "starforge_particle_type.h"
#include "starforge_particle.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticlePool StarforgeParticlePool;

StarforgeParticlePool* starforge_particle_pool_create(int max_particles);

float get_x(StarforgeParticlePool* pool, int index);
float get_y(StarforgeParticlePool* pool, int index);
float get_vx(StarforgeParticlePool* pool, int index);
float get_vy(StarforgeParticlePool* pool, int index);
float get_life(StarforgeParticlePool* pool, int index);
float get_max_life(StarforgeParticlePool* pool, int index);
float get_size(StarforgeParticlePool* pool, int index);
StarforgeParticleType get_type(StarforgeParticlePool* pool, int index);
int get_alive(StarforgeParticlePool* pool, int index);

void starforge_particle_pool_destroy(StarforgeParticlePool* pool);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_POOL_H */