#include "screen.h"

int main(int argc, char *argv[])
{
    screen_create();

    for (;;)
    {
        screen_clear(0x000000);

        screen_update();
    }

    return 0;
}