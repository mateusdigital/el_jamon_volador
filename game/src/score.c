//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : score.c                                                       //
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
#include "../include/score.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/constants.h"


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Extern
U16 score = 0;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
load_score_sprites()
{
    U16 i;
    U16 temp_score = score;
    for(i = 2; i >= 0; --i) {
        set_sprite_tile(SPRITE_NO_SCORE + i, 12 + (temp_score % 10));
        temp_score /= 10;
    }
}


//------------------------------------------------------------------------------
void
reset_score()
{
    score = 0;
}

//------------------------------------------------------------------------------
void
draw_score()
{
    move_sprite(SPRITE_NO_SCORE,     SCREEN_MIDDLE_X - SPRITE_SIZEx2, 25);
    move_sprite(SPRITE_NO_SCORE + 1, SCREEN_MIDDLE_X - SPRITE_SIZE,   25);
    move_sprite(SPRITE_NO_SCORE + 2, SCREEN_MIDDLE_X,                 25);
}
