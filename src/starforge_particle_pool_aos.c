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

static void aos_set_x(StarforgeParticlePool* pool, int index, float value)
{
    pool->pool[index].x = value;
}

static void aos_set_y(StarforgeParticlePool* pool, int index, float value)
{
    pool->pool[index].y = value;
}

static void aos_set_vx(StarforgeParticlePool* pool, int index, float value)
{
    pool->pool[index].vx = value;
}

static void aos_set_vy(StarforgeParticlePool* pool, int index, float value)
{
    pool->pool[index].vy = value;
}

static void aos_set_life(StarforgeParticlePool* pool, int index, float value)
{
    pool->pool[index].life = value;
}

static void aos_set_max_life(StarforgeParticlePool* pool, int index, float value)
{
    pool->pool[index].max_life = value;
}

static void aos_set_size(StarforgeParticlePool* pool, int index, float value)
{
    pool->pool[index].size = value;
}

static void aos_set_type(StarforgeParticlePool* pool, int index, StarforgeParticleType value)
{
    pool->pool[index].type = value;
}

static void aos_set_alive(StarforgeParticlePool* pool, int index, int value)
{
    pool->pool[index].alive = value;
}

static struct StarforgeParticlePoolAccessor aos_accessor = {
    /* getters */
    .x = aos_get_x,
    .y = aos_get_y,
    .vx = aos_get_vx,
    .vy = aos_get_vy,
    .life = aos_get_life,
    .max_life = aos_get_max_life,
    .size = aos_get_size,
    .type = aos_get_type,
    .alive = aos_get_alive

    /* setters */
    .set_x = aos_set_x,
    .set_y = aos_set_y,
    .set_vx = aos_set_vx,
    .set_vy = aos_set_vy,
    .set_life = aos_set_life,
    .set_max_life = aos_set_max_life,
    .set_size = aos_set_size,
    .set_type = aos_set_type,
    .set_alive = aos_set_alive
};

StarforgeParticlePool* starforge_particle_pool_aos_create(int max_particles)
{
    StarforgeParticlePool* pool = (StarforgeParticlePool*)malloc(sizeof(StarforgeParticlePool));

    pool->pool = (StarforgeParticle*)malloc(
        sizeof(StarforgeParticle) * max_particles
    );
    pool->accessor = &aos_accessor;
    pool->max_particles = max_particles;

    return pool;
}

void starforge_particle_pool_aos_destroy(StarforgeParticlePool* pool)
{
    free(pool->pool);
    free(pool);
}
