#include "unity.h"

void test_engine_create(void);
void test_engine_tick(void);

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_engine_create);
    RUN_TEST(test_engine_tick);

    return UNITY_END();
}
