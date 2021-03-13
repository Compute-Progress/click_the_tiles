# click_the_tiles
Click them in the right order


# About

Fairly simple tile clicker game;
Computer does a set of moves and you have to repeat them;

This project is a prototype for an assortment of button structs and functions that I would later add to SDLX

The real challenge is to make it all work smoothly with SDLX's rendering and input

NOTES:

Need :
    - Button change color when clicked;
    - Button default color
    - Button edges colored when hovered

SDLX Renders using SDLX_Sprites which are really just textures with additional info(like rotation, position, flip, etc..)
Edges and Fill need to be trasnlated into textures
Though the above is really more of a problem for the user since they are supposed to make their own function, I am only providing the means fo them to exucute said function when x or y button is clicked;