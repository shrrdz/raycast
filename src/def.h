#pragma once

#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

//-----------------------------------------------------//

#define TRUE            1
#define FALSE           0

#define MIN(x, y)       (x < y) ? x : y
#define MAX(x, y)       (x > y) ? x : y

typedef int             bool;

//-----------------------------------------------------//

#define GRAY            0x717171
#define DARKGRAY        0x383838

//-----------------------------------------------------//

#define WIDTH           800
#define HEIGHT          600

#define ASPECT_RATIO    (float) WIDTH / HEIGHT

#define FPS             60
#define TARGET_TICK     (float) 1000 / FPS

//-----------------------------------------------------//

#define SIDE_X              0
#define SIDE_Y              1

#define LEVEL_SIZE          16

//-----------------------------------------------------//

#define SENSITIVITY         1.6F

#define SPEED               4
#define SPRINT_SPEED        8

//-----------------------------------------------------//

typedef struct { float x, y; } vector2;

//-----------------------------------------------------//

float previous_tick, delta_tick;

extern vector2 view;
extern vector2 direction;
extern vector2 plane;

//-----------------------------------------------------//