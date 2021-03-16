#include "tile.h"

static Context ctx;

void init()
{
    SDLX_Start();
    ctx.display = SDLX_DisplayGet();
    ctx.level   = 0;
    ctx.moves = 2;
    ctx.mul = 1;
}

Context *GetContext(){return &ctx;}

int main(void)
{
    int delay;

    SDLX_Display *display;

    init();
    display = SDLX_DisplayGet();
    ctx.display = display;
    
    CreateButtons();
    delay = 0;
    while(1)
    {
        PollInput(ctx.turn, &ctx);
        RenderButtons();
        SDLX_RenderQueueDisplay(SDLX_RenderQueueFetch(NULL)[0], display);
        SDL_RenderPresent(display->renderer);
        if (ctx.turn == 0)
        {
            if (!delay)
                ComputerTurn(&ctx);
            // SDL_Delay(250);
            delay ^= 1;
        }
        else
            PlayerTurn(&ctx);
        SDLX_FPSAdjust();
    }
}