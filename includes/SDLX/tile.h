#ifndef TILE_H
# define TLE_H

#include "SDLX/SDLX.h"

typedef void (*lambdaFunc)(void *);

typedef struct Button
{
    SDLX_Sprite sprite;
    int         color;
    lambdaFunc  OnClick;
    lambdaFunc  OnHover;
}               Button;
// Might have texture / animated / invisible buttons at some point
// but assume this is just a colored button

typedef struct Context
{
    int         nbuttons;
    Button      *buttons;
    SDLX_Display   display;
}               Context;

#endif