#ifndef STARFORGE_BACKEND_SOA_CPU_H
#define STARFORGE_BACKEND_SOA_CPU_H

#include "starforge_backend.h"
#include "starforge_particlesystem.h"

#ifdef __cplusplus
extern "C" {
#endif

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

StarforgeBackend* starforge_backend_soa_cpu_create(
    StarforgeParticleSystem* system);

#ifdef __cplusplus
}
#endif

#endif
