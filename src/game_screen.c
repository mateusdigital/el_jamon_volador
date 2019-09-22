//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : game_screen.c                                                 //
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
#include "../include/game_screen.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/constants.h"
#include "../include/math.h"

#include "../include/screens.h"

#include "../include/background.h"
#include "../include/player.h"
#include "../include/pipe.h"
#include "../include/score.h"


//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
// World Physics

// Pipe
#define PIPE_SAFE_AREA  4


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Static
static I16   _player_speed_y        = 0;
static I16   _player_acceleration_y = 0;
static BOOL _button_down           = FALSE;
static I16   _impulse               = 0;
static U16   _input                 = 0;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
game_screen_init()
{
    //
    // Vars.
    _button_down = 0;
    _impulse     = 0;

    // Pipe.
    load_pipe_sprites();
    reset_pipe       ();
    generate_pipe    ();

    //
    // Score.
    reset_score       ();
    load_score_sprites();

    //
    // Move background layer.
    background_speed_x = 1;
}

//------------------------------------------------------------------------------
BOOL
game_screen_run()
{
    // _input = joypad();
    // if(_input & J_LEFT) {
    //     player_x -= 1;
    // }
    // if(_input & J_RIGHT) {
    //     player_x += 1;
    // }
    // if(_input & J_UP) {
    //     player_y -= 1;
    // }
    // if(_input & J_DOWN) {
    //     player_y += 1;
    // }

    // _impulse = 0;

    #define GRAVITY            +1
    #define IMPULSE           -10
    #define MAX_SPEED          +3

    //
    // Player - Input
    _input = joypad();
    if(_button_down == 0 && (_input & JOYPAD_ACTION)) {
        _button_down = 1;
        _impulse     = IMPULSE;
    } else if(!(_input & JOYPAD_ACTION)){
        _button_down = 0;
    }

    //
    // Player - Physics
    _player_acceleration_y = (GRAVITY + _impulse);
    _impulse += 1;
    if(_impulse > 0) {
        _impulse = 0;
    }

    _player_speed_y = M_clamp(_player_speed_y + _player_acceleration_y, -MAX_SPEED, MAX_SPEED);
    player_y += _player_speed_y;

    //
    // Pipe - Move
    pipe_x -= pipe_speed_x;
    if(pipe_x <= INVALID_PIPE_X) {
        generate_pipe();
    }


    if(player_x >= (pipe_x + SPRITE_SIZEx2) && pipe_generated == TRUE) {
        pipe_generated = FALSE;

        ++score;
        load_score_sprites();
    }

    //
    // Player - Collision Ground
    if(player_y + SPRITE_SIZE > SCREEN_Y2) {
        player_y = SCREEN_Y2 - SPRITE_SIZE;
        return FALSE;
    }

    //
    // Player - Collision Pipe
    if(player_x >= pipe_x &&
       player_x                 <= pipe_x + SPRITE_SIZEx2) {
        // We are inside of the pipe, let's check if we are colliding with it!
        // Top pipe
        if(player_y < (pipe_y - pipe_openess - PIPE_SAFE_AREA + SPRITE_SIZE)) {
            return FALSE;
        }
        // Bottom pipe
        else if(player_y + SPRITE_SIZEx2 > (pipe_y + pipe_openess + PIPE_SAFE_AREA)){
            return FALSE;
        }
    }


    //
    // Draw
    move_game_background();

    draw_pipe  ();
    draw_player();
    draw_score ();

    return TRUE;
}

void
game_screen_end()
{
    change_screen_to(SCREEN_TYPE_GAME_OVER);
}
