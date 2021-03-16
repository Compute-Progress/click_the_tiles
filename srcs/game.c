#include "tile.h"

void PollInput(int turn, Context *ctx)
{
    SDL_Event event;
    int x, y;

    ctx->click  = 0;
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
			exit(0);
        if (event.type == SDL_MOUSEBUTTONDOWN)
            ctx->click = 1;
    }
    SDL_GetMouseState(&ctx->x, &ctx->y);
}

void PlayerTurn(Context *ctx)
{
    static int i;
    int correct;
    int id;
    int x;
    int y;

    x = ctx->x / (WIN_W / ctx->mul);
    y = ctx->y / (WIN_H / ctx->mul);
    id = x + y * ctx->mul;
    correct = (id == ctx->order[i]);

    i++;
    if (i >= ctx->moves)
    {
        i = 0;
        ctx->level++;
        ctx->turn = 0;

        if (ctx->moves++ == (ctx->mul * ctx->mul))
            CreateButtons();
        return ;
    }
    // if (!ctx->click)
    // {
    //     OnHover((&ctx->buttons[id]));
    //     return ;
    // }
    // else
    // {
    //     OnClick(&(ctx->buttons[id]), correct);
    //     if (correct)
    //     {
    //         i++;
    //         return ;
    //     }
    //     else
    //         exit(0);
    // }
}
   

void ComputerTurn(Context *ctx)
{
    static int i;

    if (i < ctx->moves)
    {
        SDL_Log(" i %d, moves %d",i, ctx->moves);
        ctx->order[i] = rand() % (ctx->mul * ctx->mul);
        AIClick(&(ctx->buttons[ctx->order[i]]));
        i++;
    }
    else
    {
        i = 0;
        ctx->turn++;
    }
}