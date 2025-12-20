#include <stdlib.h>
#include "starforge_particlesystem.h"
#include "starforge_particle_pool.h"
#include "starforge_emitter.h"
#include "starforge_backend.h"
#include "starforge_backend_aos.h"
#include "starforge_backend_soa_cpu.h"
#include "starforge_backend_soa_avx2.h"

StarforgeParticleSystem* starforge_particlesystem_create(
    StarforgeParticle* pool,
    int max_particles,
    BackendType backend_type)
{
    StarforgeParticleSystem* sys =
        (StarforgeParticleSystem*)malloc(sizeof(StarforgeParticleSystem));

    sys->pool = pool;
    sys->max_particles = max_particles;
    sys->emitter = NULL;

    switch (backend_type)
    {
        case STARFORGE_BACKEND_AOS:
            sys->backend = starforge_backend_aos_create(sys);
            sys->particles_pool = starforge_particle_pool_aos_create(max_particles);
            break;
        case STARFORGE_BACKEND_SOA:
            sys->backend = starforge_backend_soa_cpu_create(sys);
            sys->particles_pool = starforge_particle_pool_soa_create(max_particles);
            break;
        case STARFORGE_BACKEND_AVX2:
            sys->backend = starforge_backend_soa_avx2_create(sys);
            sys->particles_pool = starforge_particle_pool_soa_create(max_particles);
            break;
    }

    for (int i = 0; i < max_particles; ++i)
        pool[i].alive = 0;

    return sys;
}

void starforge_particlesystem_destroy(StarforgeParticleSystem* system)
{
    starforge_particle_pool_aos_destroy(system->particles_pool);
    free(system);
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

    system->backend->update(system->backend, dt, world);
}

const StarforgeParticle* starforge_particlesystem_particles(
    const StarforgeParticleSystem* system,
    int* out_count)
{
    StarforgeParticleView view =
        system->backend->view(system->backend);

    *out_count = view.count;
    return view.particles;
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
    StarforgeParticleView view =
            system->backend->view(system->backend);

    for (int i = 0; i < view.count; ++i)
    {
        StarforgeParticle* p = &view.particles[i];

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
