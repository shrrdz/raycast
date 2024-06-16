#pragma once

#include "def.h"

uint32_t palette_lookup(int index)
{
    switch (index)
    {
        case 0: return 0x000000; // black
        case 1: return 0x2020FF; // red
        case 2: return 0x20FF20; // green
        case 3: return 0xFF2020; // blue
        case 4: return 0x20FFFF; // yellow
        case 5: return 0xFF20FF; // magenta
        case 6: return 0xFFFF20; // cyan
    }
}