#ifndef STARFORGE_BACKEND_H
#define STARFORGE_BACKEND_H

#include "starforge_backend.h"
#include "starforge_particle_pool_accessor.h"
#include "starforge_world.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeBackend StarforgeBackend;

typedef struct
{
    const StarforgeParticlePoolAccessor* particles;
    int count;
} StarforgeParticleView;

struct StarforgeBackend
{
    void (*update)(
        StarforgeBackend* self,
        float dt,
        const StarforgeWorldForces* world);

    StarforgeParticleView (*view)(StarforgeBackend* self);

    void (*spawn)(StarforgeBackend* self,
                  const StarforgeParticle* proto);

    void (*destroy)(StarforgeBackend* self);

    void* userdata;
};

#ifdef __cplusplus
}
#endif

#endif
