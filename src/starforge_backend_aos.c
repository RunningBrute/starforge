#include <stdlib.h>
#include "starforge_particlesystem.h"
#include "starforge_backend_aos.h"
#include "starforge_backend.h"

typedef struct
{
    StarforgeParticleSystem* system;
} StarforgeBackendAosData;

static void backend_aos_update(
    StarforgeBackend* self,
    float dt,
    const StarforgeWorldForces* world)
{
    StarforgeBackendAosData* data = self->userdata;
    StarforgeParticleSystem* system = data->system;

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

static StarforgeParticleView backend_aos_view(
    StarforgeBackend* self)
{
    StarforgeBackendAosData* d = self->userdata;
    StarforgeParticleSystem* s = d->system;

    int count = 0;
    for (int i = 0; i < s->max_particles; i++)
        if (s->pool[i].alive)
            count++;

    StarforgeParticleView v;
    v.particles = s->pool;
    v.count = count;
    return v;
}

static void backend_aos_spawn(
    StarforgeBackend* self,
    const StarforgeParticle* proto)
{
    StarforgeBackendAosData* d = self->userdata;
    StarforgeParticleSystem* system = d->system;

    for (int i = 0; i < system->max_particles; ++i)
    {
        if (!system->pool[i].alive)
        {
            system->pool[i] = *proto;
            system->pool[i].alive = 1;
            return;
        }
    }
}

static void backend_aos_destroy(StarforgeBackend* self)
{
    StarforgeBackendAosData* d = self->userdata;
    free(d);
    free(self);
}

StarforgeBackend* starforge_backend_aos_create(
    StarforgeParticleSystem* system)
{
    StarforgeBackend* backend = malloc(sizeof(StarforgeBackend));
    StarforgeBackendAosData* data = malloc(sizeof(StarforgeBackendAosData));

    data->system = system;

    backend->userdata = data;
    backend->update   = backend_aos_update;
    backend->view     = backend_aos_view;
    backend->spawn    = backend_aos_spawn;
    backend->destroy  = backend_aos_destroy;

    return backend;
}
