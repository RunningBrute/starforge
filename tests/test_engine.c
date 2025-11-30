#include "unity.h"
#include "starforge_engine.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_engine_create(void)
{
    StarforgeEngine* engine = starforge_engine_create();
    TEST_ASSERT_NOT_NULL(engine);
    starforge_engine_destroy(engine);
}

void test_engine_tick(void)
{
    StarforgeEngine* engine = starforge_engine_create();
    TEST_ASSERT_NOT_NULL(engine);

    starforge_engine_update(engine);
    starforge_engine_update(engine);

    TEST_PASS();

    starforge_engine_destroy(engine);
}
