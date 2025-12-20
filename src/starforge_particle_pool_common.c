#include "starforge_particle_pool.h"

typedef struct StarforgeParticlePool
{
    void* pool;
    StarforgeParticlePoolAccessor* accessor;
    int max_particles;
} StarforgeParticlePool;

const StarforgeParticlePoolAccessor* starforge_particle_pool_accessor_get(const StarforgeParticlePool* pool)
{
    return pool->accessor;
}