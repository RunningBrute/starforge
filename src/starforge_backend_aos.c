#include <stdlib.h>
#include "starforge_particlesystem.h"
#include "starforge_backend_aos.h"
#include "starforge_backend.h"

typedef struct
{
    StarforgeParticleSystem* system;
} StarforgeBackendAosData;

static StarforgeParticleView backend_aos_view(
    StarforgeBackend* self)
{
    StarforgeBackendAosData* d = self->userdata;

    StarforgeParticleView v;
    v.particles = d->system->pool;
    v.count     = d->system->max_particles;
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
    backend->view    = backend_aos_view;
    backend->spawn   = backend_aos_spawn;
    backend->destroy = backend_aos_destroy;

    return backend;
}
