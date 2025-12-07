#ifndef STARFORGE_BACKEND_SOA_AVX2_H
#define STARFORGE_BACKEND_SOA_AVX2_H

#include "starforge_backend.h"
#include "starforge_particlesystem.h"

#ifdef __cplusplus
extern "C" {
#endif

StarforgeBackend* starforge_backend_soa_avx2_create(
    StarforgeParticleSystem* system);

#ifdef __cplusplus
}
#endif

#endif
