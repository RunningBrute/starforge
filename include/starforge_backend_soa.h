#ifndef STARFORGE_BACKEND_SOA_H
#define STARFORGE_BACKEND_SOA_H

#include "starforge_backend.h"
#include "starforge_particlesystem.h"

#ifdef __cplusplus
extern "C" {
#endif

StarforgeBackend* starforge_backend_soa_create(
    StarforgeParticleSystem* system);

#ifdef __cplusplus
}
#endif

#endif
