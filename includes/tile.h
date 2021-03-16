#ifndef TILE_H
# define TILE_H

#include "SDLX/SDLX.h"

struct  Button;
typedef struct Button Button;

typedef struct Button
{
    SDLX_Sprite sprite;
    int         color;
    int         id;
    void (*OnClick)(Button *button, int correct);
    void (*OnHover)(Button *button);
}               Button;
// Might have texture / animated / invisible buttons at some point
// but assume this is just a colored button

typedef struct Context
{
    int         turn;
    int         x;
    int         y;
    int         level;
    int         click;
    int         mul;
    int         moves;
    int         nbuttons;
    int         order[100];     
    Button      buttons[100];
    SDLX_Display*display;
}               Context;


Context *GetContext();
void    CreateButtons();
void PollButtons(int x, int y, int clicked);
void PollInput(int turn, Context *ctx);
void OnHover(Button *button);
void OnClick(Button *button, int correct);
void RenderButtons();
void ComputerTurn(Context *ctx);
void PlayerTurn(Context *ctx);
void AIClick(Button *button);

#endif