#include "starforge_particle_pool_aos.h"

StarforgeParticlePool* starforge_particle_pool_aos_create(int max_particles)
{
    StarforgeParticlePool* pool = (StarforgeParticlePool*)malloc(sizeof(StarforgeParticlePool));

    pool->pool = (StarforgeParticle*)malloc(sizeof(StarforgeParticle));
    pool->max_particles = max_particles;
    
    return pool;
}

float get_x(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].x;
}

float get_y(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].y;
}

float get_vx(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].vx;
}

float get_vy(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].vy;
}

float get_life(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].life;
}

float get_max_life(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].max_life;
}

float get_size(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].size;
}

StarforgeParticleType get_type(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].type;
}

int get_alive(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].alive;
}

void starforge_particle_pool_aos_destroy(StarforgeParticlePool* pool)
{
    free(pool->pool);
    free(pool);
}