#include "tick.h"
#include "input.h"
#include "screen.h"

int main(int argc, char *argv[])
{
    screen_create();

    for (;;)
    {
        input();
        tick();

        screen_clear(0x000000);

        screen_update();
    }

    return 0;
}