#pragma once

#include <SDL.h>
#include <stdio.h>

//-----------------------------------------------------//

#define WIDTH           800
#define HEIGHT          600

#define FPS             60
#define TARGET_TICK     (float) 1000 / FPS

//-----------------------------------------------------//

float previous_tick, delta_tick;

//-----------------------------------------------------//