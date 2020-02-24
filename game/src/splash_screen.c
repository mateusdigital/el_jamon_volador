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
#include "../include/splash_screen.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/constants.h"

#include "../include/screens.h"
#include "../include/fade.h"

#include "../include/background.h"
// Res
#include "../include/res/sprites.h"


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
static U16 fade_state = 0;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
splash_screen_init()
{
    //
    // Load the sprites.
    load_splash_background();

    //
    // Reset the fade animation.
    SET_FADE_0();
    fade_state = 1;
    reset_fade_status(FADE_DURATION);

    //
    // Make sure that background isn't moving.
    background_speed_x = 0;
}

//------------------------------------------------------------------------------
BOOL
splash_screen_run()
{
    // Fading in...
    if(fade_state == 1 && fade_in() && joypad() & JOYPAD_ACTION) {
        fade_state = 2;
        reset_fade_status(FADE_DURATION);

        return TRUE;
    }
    // Fade out...
    else if(fade_state == 2 && fade_out()) {

        return FALSE;
    }

    return TRUE;
}

//------------------------------------------------------------------------------
void
splash_screen_end()
{
    change_screen_to(SCREEN_TYPE_SPLASH_INTRO);
}
