#include "starforge_particle_pool.h"

typedef struct StarforgeParticlePool
{
    float* x;
    float* y;
    float* vx;
    float* vy;
    float* life;
    float* max_life;
    float* size;
    StarforgeParticleType* type;
    int* alive;

    StarforgeParticlePoolAccessor* accessor;
    int max_particles;
} StarforgeParticlePool;

static float soa_get_x(StarforgeParticlePool* pool, int index)
{
    return pool->x[index];
}

static float soa_get_y(StarforgeParticlePool* pool, int index)
{
    return pool->y[index];
}

static float soa_get_vx(StarforgeParticlePool* pool, int index)
{
    return pool->vx[index];
}

static float soa_get_vy(StarforgeParticlePool* pool, int index)
{
    return pool->vy[index];
}

static float soa_get_life(StarforgeParticlePool* pool, int index)
{
    return pool->life[index];
}

static float soa_get_max_life(StarforgeParticlePool* pool, int index)
{
    return pool->max_life[index];
}

static float soa_get_size(StarforgeParticlePool* pool, int index)
{
    return pool->size[index];
}

static StarforgeParticleType soa_get_type(StarforgeParticlePool* pool, int index)
{
    return pool->type[index];
}

static int soa_get_alive(StarforgeParticlePool* pool, int index)
{
    return pool->alive[index];
}

static struct StarforgeParticlePoolAccessor soa_accessor = {
    .x = soa_get_x,
    .y = soa_get_y,
    .vx = soa_get_vx,
    .vy = soa_get_vy,
    .life = soa_get_life,
    .max_life = soa_get_max_life,
    .size = soa_get_size,
    .type = soa_get_type,
    .alive = soa_get_alive
};

StarforgeParticlePool* starforge_particle_pool_soa_create(int max_particles)
{
    StarforgeParticlePool* pool = (StarforgeParticlePool*)malloc(sizeof(StarforgeParticlePool));

    pool->x        = (float*)calloc(max_particles, sizeof(float));
    pool->y        = (float*)calloc(max_particles, sizeof(float));
    pool->vx       = (float*)calloc(max_particles, sizeof(float));
    pool->vy       = (float*)calloc(max_particles, sizeof(float));
    pool->life     = (float*)calloc(max_particles, sizeof(float));
    pool->max_life = (float*)calloc(max_particles, sizeof(float));
    pool->type     = (StarforgeParticleType*)calloc(max_particles, sizeof(StarforgeParticleType));
    pool->alive    = (int*)calloc(max_particles, sizeof(int));

    pool->accessor = &soa_accessor;
    pool->max_particles = max_particles;

    return pool;
}

void starforge_particle_pool_soa_destroy(StarforgeParticlePool* pool)
{
    free(pool->x);
    free(pool->y);
    free(pool->vx);
    free(pool->vy);
    free(pool->life);
    free(pool->max_life);
    free(pool->size);
    free(pool->type);
    free(pool->alive);
    free(pool);
}