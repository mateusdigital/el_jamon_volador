//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : pipe.c                                                        //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../include/pipe.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/constants.h"
#include "../include/math.h"
#include "../include/shake.h"
// Res
#include "../include/res/sprites.h"

//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Extern
I16 pipe_x         = 0;
I16 pipe_y         = 0;
I16 pipe_openess   = 0;
I16 pipe_speed_x   = 0;
I16 pipe_generated = 0;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
reset_pipe()
{
    pipe_x         = INVALID_PIPE_X;
    pipe_y         = 0;
    pipe_openess   = 0;
    pipe_speed_x   = 1;
    pipe_generated = FALSE;
}

//------------------------------------------------------------------------------
void
generate_pipe()
{
    pipe_x         = SCREEN_X2 + 10;
    pipe_y         = SCREEN_MIDDLE_Y + (M_rand() / 8);
    pipe_openess   = PIPE_OPENESS_MIN  + M_abs(M_rand() / 10);
    pipe_generated = TRUE;
}

//------------------------------------------------------------------------------
void
load_pipe_sprites()
{

    int i;
    VBK_REG = 1;

    //
    // top bottom
    set_sprite_tile(SPRITE_NO_PIPES,     6);
    set_sprite_tile(SPRITE_NO_PIPES + 1, 7);

    //
    // top top
    set_sprite_tile(SPRITE_NO_PIPES + 2, 10);
    set_sprite_tile(SPRITE_NO_PIPES + 3, 11);


    //
    // bases
    for(i = 0; i < SPRITE_NO_PIPES_COUNT + 2; i += 2) {
        set_sprite_tile(SPRITE_NO_PIPES + 4 + i, 8);
        set_sprite_tile(SPRITE_NO_PIPES + 5 + i, 9);
    }

    VBK_REG = 0;
}



//------------------------------------------------------------------------------
void
draw_pipe()
{
    I16 x, y, i, ty, by, pipe_index;

    x = pipe_x + shake_x;
    y = pipe_y + shake_y;

    ty = y - pipe_openess;
    by = y + pipe_openess;

    pipe_index = 4;

    move_sprite(SPRITE_NO_PIPES + 0, x,               by);
    move_sprite(SPRITE_NO_PIPES + 1, x + SPRITE_SIZE, by);

    move_sprite(SPRITE_NO_PIPES + 2, x,               ty);
    move_sprite(SPRITE_NO_PIPES + 3, x + SPRITE_SIZE, ty);

    for(i = 1; i < 10; ++i) {
        move_sprite(SPRITE_NO_PIPES + pipe_index++, x,               ty - (SPRITE_SIZE * i));
        move_sprite(SPRITE_NO_PIPES + pipe_index++, x + SPRITE_SIZE, ty - (SPRITE_SIZE * i));

        move_sprite(SPRITE_NO_PIPES + pipe_index++, x,               by + (SPRITE_SIZE * i));
        move_sprite(SPRITE_NO_PIPES + pipe_index++, x + SPRITE_SIZE, by + (SPRITE_SIZE * i));
    }
}
