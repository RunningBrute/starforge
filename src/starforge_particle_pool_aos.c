#include "starforge_particle_pool_aos.h"

StarforgeParticlePoolAoS starforge_particel_pool_aos_create(int max_particles)
{
    StarforgeParticlePoolAoS pool;

    pool.pool = (StarforgeParticle*)malloc(sizeof(StarforgeParticle));
    pool.max_particles = max_particles;
    
    return pool;
}
