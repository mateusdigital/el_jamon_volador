//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : shake.c                                                       //
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
#include "../include/shake.h"
// Game
#include "../include/math.h"

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define SHAKE_ANIMATION_LOOP_MAX 6
#define SHAKE_ANIMATION_FRAMES   5

//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Extern
I16 shake_x;
I16 shake_y;
// Static
static I16 shake_animation_frame;
static I16 shake_animation_total_frames;

//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
reset_shake()
{
    shake_x                      = 0;
    shake_y                      = 0;

    shake_animation_frame        = 0;
    shake_animation_total_frames = SHAKE_ANIMATION_FRAMES * SHAKE_ANIMATION_LOOP_MAX;
}

//------------------------------------------------------------------------------
BOOL
update_shake()
{
    ++shake_animation_frame;
    if(shake_animation_frame <= shake_animation_total_frames) {
        if(shake_animation_frame % SHAKE_ANIMATION_FRAMES == 0) {
            shake_x = M_rand() % 4;
            shake_y = M_rand() % 4;
        }

        return FALSE;
    }

    return TRUE;
}
