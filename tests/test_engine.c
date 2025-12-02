#include "unity.h"
#include "starforge_engine.h"
#include "starforge_world.h"

#define MAX_PARTICLES 256
#define MAX_SYSTEMS   4

static StarforgeParticle pool[MAX_PARTICLES];
static StarforgeEngine* engine = NULL;
static StarforgeParticleSystem* rain = NULL;

void setUp(void)
{
    engine = starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);
    rain = starforge_engine_create_system(engine);
}

void tearDown(void)
{
    starforge_engine_destroy(engine);
}

void test_engine_updates_particles(void)
{
    StarforgeWorldForces* world =
        starforge_engine_world(engine);

    starforge_world_set_wind(world, 1.0f, 0.0f);

    starforge_particlesystem_emit_rain(rain, -10.0f, 10.0f, 10);
    starforge_engine_update(engine, 0.1f);

    int count;
    const StarforgeParticle* particles =
        starforge_engine_particles(engine, &count);

    int alive = 0;
    for (int i = 0; i < count; ++i)
        if (particles[i].alive)
            alive++;

    TEST_ASSERT_TRUE(alive > 0);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_engine_updates_particles);
    return UNITY_END();
}
