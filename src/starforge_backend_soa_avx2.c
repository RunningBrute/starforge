#include <stdlib.h>
#include <immintrin.h>
#include "starforge_particlesystem.h"
#include "starforge_backend_soa_avx2.h"
#include "starforge_backend_soa_cpu.h"
#include "starforge_backend.h"

static void backend_soa_avx2_update(
    StarforgeBackend* self,
    float dt,
    const StarforgeWorldForces* world)
{
    StarforgeBackendSoAData* p = self->userdata;

    const int n = p->max_particles;
    const __m256 dtv = _mm256_set1_ps(dt);
    const __m256 gxv = _mm256_set1_ps(world->gravity_x);
    const __m256 gyv = _mm256_set1_ps(world->gravity_y);
    const __m256 wxv = _mm256_set1_ps(world->wind_x);
    const __m256 wyv = _mm256_set1_ps(world->wind_y);
    const __m256 zerov = _mm256_set1_ps(0.0f);

    int i = 0;
    for (; i <= n - 8; i += 8)
    {
        __m256 alive = _mm256_cvtepi32_ps(
            _mm256_load_si256((__m256i*)&p->alive[i])
        );

        __m256 mask = _mm256_cmp_ps(alive, zerov, _CMP_GT_OQ);
        if (_mm256_movemask_ps(mask) == 0)
            continue;

        __m256 vx = _mm256_load_ps(&p->vx[i]);
        __m256 vy = _mm256_load_ps(&p->vy[i]);
        __m256 x  = _mm256_load_ps(&p->x[i]);
        __m256 y  = _mm256_load_ps(&p->y[i]);
        __m256 life = _mm256_load_ps(&p->life[i]);

        vx = _mm256_add_ps(vx, _mm256_mul_ps(gxv, dtv));
        vy = _mm256_add_ps(vy, _mm256_mul_ps(gyv, dtv));
        vx = _mm256_add_ps(vx, _mm256_mul_ps(wxv, dtv));
        vy = _mm256_add_ps(vy, _mm256_mul_ps(wyv, dtv));

        x = _mm256_add_ps(x, _mm256_mul_ps(vx, dtv));
        y = _mm256_add_ps(y, _mm256_mul_ps(vy, dtv));

        life = _mm256_sub_ps(life, dtv);

        _mm256_store_ps(&p->vx[i], vx);
        _mm256_store_ps(&p->vy[i], vy);
        _mm256_store_ps(&p->x[i],  x);
        _mm256_store_ps(&p->y[i],  y);
        _mm256_store_ps(&p->life[i], life);
    }

    for (; i < n; ++i)
    {
        if (!p->alive[i]) continue;

        p->vx[i] += world->gravity_x * dt;
        p->vy[i] += world->gravity_y * dt;
        p->vx[i] += world->wind_x * dt;
        p->vy[i] += world->wind_y * dt;
        p->x[i]  += p->vx[i] * dt;
        p->y[i]  += p->vy[i] * dt;
        p->life[i] -= dt;

        if (p->life[i] <= 0.0f || p->y[i] < -50.0f)
            p->alive[i] = 0;
    }
}

StarforgeBackend* starforge_backend_soa_avx2_create(
    StarforgeParticleSystem* system)
{
    StarforgeBackend* backend = starforge_backend_soa_create(system);
    backend->update = backend_soa_avx2_update;
    return backend;
}
