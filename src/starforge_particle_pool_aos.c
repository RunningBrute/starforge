#include "starforge_particle_pool_aos.h"

StarforgeParticlePool* starforge_particle_pool_aos_create(int max_particles)
{
    StarforgeParticlePool* pool = (StarforgeParticlePool*)malloc(sizeof(StarforgeParticlePool));

    pool->pool = (StarforgeParticle*)malloc(sizeof(StarforgeParticle));
    pool->max_particles = max_particles;
    
    return pool;
}

void starforge_particle_pool_aos_destroy(StarforgeParticlePool* pool)
{
    free(pool->pool);
    free(pool);
}