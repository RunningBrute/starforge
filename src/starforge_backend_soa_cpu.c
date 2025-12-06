#include <stdlib.h>
#include "starforge_particlesystem.h"
#include "starforge_backend_soa_cpu.h"
#include "starforge_backend.h"

typedef struct {
    float* x;
    float* y;
    float* vx;
    float* vy;
    float* life;
    float* max_life;
    StarforgeParticleType* type;
    int* alive;

    StarforgeParticle* view_buffer;
    int max_particles;
} StarforgeBackendSoAData;

static void backend_soa_update(
    StarforgeBackend* self,
    float dt,
    const StarforgeWorldForces* world)
{
    StarforgeBackendSoAData* p = self->userdata;

    for (int i = 0; i < p->max_particles; ++i)
    {
        if (!p->alive[i]) continue;

        /* Apply global forces */
        p->vx[i] += world->gravity_x * dt;
        p->vy[i] += world->gravity_y * dt;

        p->vx[i] += world->wind_x * dt;
        p->vy[i] += world->wind_y * dt;

        /* Integrate */
        p->x[i] += p->vx[i] * dt;
        p->y[i] += p->vy[i] * dt;

        /* Life decay */
        p->life[i] -= dt;

        if (p->life[i] <= 0.0f || p->y[i] < -50.0f)
            p->alive[i] = 0;
    }
}

static StarforgeParticleView backend_soa_view(
    StarforgeBackend* self)
{
    StarforgeBackendSoAData* d = self->userdata;

    int count = 0;

    for (int i = 0; i < d->max_particles; ++i)
    {
        if (!d->alive[i])
            continue;

        StarforgeParticle* p = &d->view_buffer[count++];

        p->x = d->x[i];
        p->y = d->y[i];
        p->vx = d->vx[i];
        p->vy = d->vy[i];
        p->life = d->life[i];
        p->max_life = d->max_life[i];
        p->type = d->type[i];
        p->alive = 1;
    }

    StarforgeParticleView view;
    view.particles = d->view_buffer;
    view.count = count;
    return view;
}

static void backend_soa_spawn(
    StarforgeBackend* self,
    const StarforgeParticle* proto)
{
    StarforgeBackendSoAData* data = self->userdata;

    for (int i = 0; i < data->max_particles; ++i)
    {
        if (!data->alive[i])
        {
            data->x[i] = proto->x;
            data->y[i] = proto->y;
            data->vx[i] = proto->vx;
            data->vy[i] = proto->vy;
            data->life[i] = proto->life;
            data->max_life[i] = proto->max_life;
            data->type[i] = proto->type;
            data->alive[i] = 1;
            return;
        }
    }
}

static void backend_soa_destroy(StarforgeBackend* self)
{
    StarforgeBackendSoAData* d = self->userdata;
    free(d->x);
    free(d->y);
    free(d->vx);
    free(d->vy);
    free(d->life);
    free(d->max_life);
    free(d->type);
    free(d->alive);
    free(d->view_buffer);
    free(d);
    free(self);
}

StarforgeBackend* starforge_backend_soa_create(
    StarforgeParticleSystem* system)
{
    StarforgeBackend* backend = malloc(sizeof(StarforgeBackend));
    StarforgeBackendSoAData* data = malloc(sizeof(StarforgeBackendSoAData));

    data->x        = calloc(system->max_particles, sizeof(float));
    data->y        = calloc(system->max_particles, sizeof(float));
    data->vx       = calloc(system->max_particles, sizeof(float));
    data->vy       = calloc(system->max_particles, sizeof(float));
    data->life     = calloc(system->max_particles, sizeof(float));
    data->max_life = calloc(system->max_particles, sizeof(float));
    data->type     = calloc(system->max_particles, sizeof(StarforgeParticleType));
    data->alive    = calloc(system->max_particles, sizeof(int));

    data->max_particles = system->max_particles;
    data->view_buffer = malloc(sizeof(StarforgeParticle) * data->max_particles);

    backend->userdata = data;
    backend->update   = backend_soa_update;
    backend->view     = backend_soa_view;
    backend->spawn    = backend_soa_spawn;
    backend->destroy  = backend_soa_destroy;

    return backend;
}
