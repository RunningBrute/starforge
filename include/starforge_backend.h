#ifndef STARFORGE_BACKEND_H
#define STARFORGE_BACKEND_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeBackend StarforgeBackend;

typedef struct
{
    const StarforgeParticle* particles;
    int count;
} StarforgeParticleView;

struct StarforgeBackend
{
    void (*update)(StarforgeBackend* self,
                   float dt,
                   const StarforgeWorldForces* world);

    StarforgeParticleView (*view)(StarforgeBackend* self);

    void (*destroy)(StarforgeBackend* self);

    void* userdata;
};

#ifdef __cplusplus
}
#endif

#endif
