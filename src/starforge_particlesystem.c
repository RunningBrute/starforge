#include <stdlib.h>
#include "starforge_particlesystem.h"
#include "starforge_emitter.h"
#include "starforge_backend.h"
#include "starforge_backend_aos.h"
#include "starforge_backend_soa_cpu.h"
#include "starforge_backend_soa_avx2.h"

StarforgeParticleSystem* starforge_particlesystem_create(
    StarforgeParticle* pool,
    int max_particles)
{
    StarforgeParticleSystem* sys =
        (StarforgeParticleSystem*)malloc(sizeof(StarforgeParticleSystem));

    sys->pool = pool;
    sys->max_particles = max_particles;
    sys->emitter = NULL;
    sys->backend = starforge_backend_aos_create(sys);
    //sys->backend = starforge_backend_soa_cpu_create(sys);
    //sys->backend = starforge_backend_soa_avx2_create(sys);

    for (int i = 0; i < max_particles; ++i)
        pool[i].alive = 0;

    return sys;
}

void starforge_particlesystem_destroy(StarforgeParticleSystem* system)
{
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
