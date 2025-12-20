#include "starforge_particle_pool.h"

typedef struct StarforgeParticlePool
{
    StarforgeParticle* pool;
    StarforgeParticlePoolAccessor* accessor;
    int max_particles;
} StarforgeParticlePool;

static float aos_get_x(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].x;
}

static float aos_get_y(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].y;
}

static float aos_get_vx(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].vx;
}

static float aos_get_vy(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].vy;
}

static float aos_get_life(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].life;
}

static float aos_get_max_life(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].max_life;
}

static float aos_get_size(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].size;
}

static StarforgeParticleType aos_get_type(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].type;
}

static int aos_get_alive(StarforgeParticlePool* pool, int index)
{
    return pool->pool[index].alive;
}

static struct StarforgeParticlePoolAccessor aos_accessor = {
    .x = aos_get_x,
    .y = aos_get_y,
    .vx = aos_get_vx,
    .vy = aos_get_vy,
    .life = aos_get_life,
    .max_life = aos_get_max_life,
    .size = aos_get_size,
    .type = aos_get_type,
    .alive = aos_get_alive
};

StarforgeParticlePool* starforge_particle_pool_aos_create(int max_particles)
{
    StarforgeParticlePool* pool = (StarforgeParticlePool*)malloc(sizeof(StarforgeParticlePool));

    pool->pool = (StarforgeParticle*)malloc(sizeof(StarforgeParticle));
    pool->accessor = &aos_accessor;
    pool->max_particles = max_particles;
    
    return pool;
}

void starforge_particle_pool_aos_destroy(StarforgeParticlePool* pool)
{
    free(pool->pool);
    free(pool);
}