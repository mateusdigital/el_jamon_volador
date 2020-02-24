//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : player.c                                                      //
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
#include "../include/player.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/constants.h"
#include "../include/shake.h"
// Res
#include "../include/res/sprites.h"


//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define PLAYER_ANIMATION_FRAMES_MAX 10
#define PLAYER_ANIMATION_MAX_FRAME   1


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Extern
I16 player_x = 0;
I16 player_y = 0;
// Static
static U16 _curr_anim_frame_index  = 0;
static U16 _animation_frames_count = 0;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
reset_player_animation()
{
    _curr_anim_frame_index  = 0;
    _animation_frames_count = 0;
}

//------------------------------------------------------------------------------
void
reset_player_position()
{
    player_x = -SPRITE_SIZEx2;
    player_y =  SCREEN_MIDDLE_Y;
}

//------------------------------------------------------------------------------
void
load_player_sprites()
{
    VBK_REG = 1;

    set_sprite_data(0, 23, FLAPPY);

    set_sprite_tile(SPRITE_NO_PLAYER,     0);
    set_sprite_tile(SPRITE_NO_PLAYER + 1, 1);
    set_sprite_tile(SPRITE_NO_PLAYER + 2, 2);
    set_sprite_tile(SPRITE_NO_PLAYER + 3, 3);

    VBK_REG = 0;
}

//------------------------------------------------------------------------------
void
draw_player()
{
    I16 x, y;

    x = player_x + shake_x;
    y = player_y + shake_y;

    if(++_animation_frames_count > PLAYER_ANIMATION_FRAMES_MAX) {
        set_sprite_tile(SPRITE_NO_PLAYER + 2, 4);
        set_sprite_tile(SPRITE_NO_PLAYER + 3, 5);
        _curr_anim_frame_index++;
        if(_curr_anim_frame_index > PLAYER_ANIMATION_MAX_FRAME) {
            _curr_anim_frame_index = 0;
            set_sprite_tile(SPRITE_NO_PLAYER + 2, 2);
            set_sprite_tile(SPRITE_NO_PLAYER + 3, 3);
        }
        _animation_frames_count = 0;
    }

    move_sprite(SPRITE_NO_PLAYER,     x,               y              );
    move_sprite(SPRITE_NO_PLAYER + 1, x,               y + SPRITE_SIZE);
    move_sprite(SPRITE_NO_PLAYER + 2, x - SPRITE_SIZE, y              );
    move_sprite(SPRITE_NO_PLAYER + 3, x - SPRITE_SIZE, y + SPRITE_SIZE);
}
