#include "starforge_backend.h"
#include "starforge_particlesystem.h"
#include <stdlib.h>

typedef struct
{
    StarforgeParticleSystem* system;
} StarforgeBackendAosData;

static void backend_aos_update(
    StarforgeBackend* self,
    float dt,
    const StarforgeWorldForces* forces)
{
    StarforgeBackendAosData* d = self->userdata;
    starforge_particlesystem_update(d->system, dt, forces);
}

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
    starforge_particlesystem_emit_proto(d->system, proto);
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
    backend->update  = backend_aos_update;
    backend->view    = backend_aos_view;
    backend->spawn   = backend_aos_spawn;
    backend->destroy = backend_aos_destroy;

    return backend;
}
