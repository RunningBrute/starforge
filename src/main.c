#include "starforge_engine.h"

int main(void)
{
    StarforgeEngine* engine = starforge_engine_create();

    if (!engine)
        return 1;

    for (int i = 0; i < 5; ++i)
        starforge_engine_update(engine);

    starforge_engine_destroy(engine);
    return 0;
}
