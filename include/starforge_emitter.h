#ifndef STARFORGE_EMITTER_H
#define STARFORGE_EMITTER_H

#ifdef __cplusplus
extern "C" {
#endif

struct StarforgeParticleSystem;

typedef struct StarforgeEmitter StarforgeEmitter;

struct StarforgeEmitter
{
    void (*emit)(
        StarforgeEmitter* self,
        struct StarforgeParticleSystem* system,
        float dt
    );

    int enabled;     /* 1 = active, 0 = paused */
    void* context;
};

#ifdef __cplusplus
}
#endif

#endif
