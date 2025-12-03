#include "starforge_particlesystem.h"
#include <stdlib.h>
#include "starforge_emitter.h"

struct StarforgeParticleSystem
{
    StarforgeParticle* pool;
    int max_particles;
    StarforgeEmitter* emitter;
};

StarforgeParticleSystem* starforge_particlesystem_create(
    StarforgeParticle* pool,
    int max_particles)
{
    StarforgeParticleSystem* sys =
        (StarforgeParticleSystem*)malloc(sizeof(StarforgeParticleSystem));

    sys->pool = pool;
    sys->max_particles = max_particles;
    sys->emitter = NULL;

    for (int i = 0; i < max_particles; ++i)
        pool[i].alive = 0;

    return sys;
}

void starforge_particlesystem_destroy(StarforgeParticleSystem* system)
{
    free(system);
}

void starforge_particlesystem_emit_rain(
    StarforgeParticleSystem* system,
    float x_min,
    float x_max,
    int count)
{
    for (int i = 0; i < system->max_particles && count > 0; ++i)
    {
        if (!system->pool[i].alive)
        {
            StarforgeParticle* p = &system->pool[i];

            p->alive = 1;
            p->type = STARFORGE_PARTICLE_RAIN;

            p->x = x_min + (float)rand() / (float)RAND_MAX * (x_max - x_min);
            p->y = 50.0f;

            p->vx = 0.0f;
            p->vy = -5.0f;

            p->life = 3.0f;
            p->max_life = 3.0f;

            p->size = 1.0f;

            p->r = 0.4f;
            p->g = 0.6f;
            p->b = 1.0f;
            p->a = 1.0f;

            count--;
        }
    }
}

void starforge_particlesystem_update(
    StarforgeParticleSystem* system,
    const StarforgeWorldForces* world,
    float dt)
{
    if (system->emitter && system->emitter->emit)
    {
        system->emitter->emit(system->emitter, system, dt);
    }

    for (int i = 0; i < system->max_particles; ++i)
    {
        StarforgeParticle* p = &system->pool[i];
        if (!p->alive)
            continue;

        /* Apply global forces */
        p->vx += world->gravity_x * dt;
        p->vy += world->gravity_y * dt;

        p->vx += world->wind_x * dt;
        p->vy += world->wind_y * dt;

        /* Integrate */
        p->x += p->vx * dt;
        p->y += p->vy * dt;

        /* Life decay */
        p->life -= dt;

        if (p->life <= 0.0f || p->y < -50.0f)
            p->alive = 0;
    }
}

const StarforgeParticle* starforge_particlesystem_particles(
    const StarforgeParticleSystem* system,
    int* out_count)
{
    *out_count = system->max_particles;
    return system->pool;
}

void starforge_particlesystem_set_emitter(
    StarforgeParticleSystem* system,
    StarforgeEmitter* emitter)
{
    system->emitter = emitter;
}

void starforge_particlesystem_emit_single(
    StarforgeParticleSystem* system,
    float x,
    float y,
    float vx,
    float vy)
{
    for (int i = 0; i < system->max_particles; ++i)
    {
        StarforgeParticle* p = &system->pool[i];

        if (!p->alive)
        {
            p->alive = 1;
            p->x = x;
            p->y = y;
            p->vx = vx;
            p->vy = vy;
            p->life = 3.0f;
            return;
        }
    }
}
