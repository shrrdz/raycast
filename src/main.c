#include "def.h"
#include "tick.h"
#include "input.h"
#include "screen.h"
#include "raycast.h"

int main(int argc, char *argv[])
{
    screen_create();

    for (;;)
    {
        input();
        tick();

        screen_clear(0x000000);

        raycast();

        screen_update();
    }

    return 0;
}