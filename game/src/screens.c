//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : screen.c                                                      //
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
#include "../include/screens.h"
// Game
#include "../include/splash_screen.h"
#include "../include/intro_screen.h"
#include "../include/game_screen.h"
#include "../include/game_over_screen.h"


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Extern
screen_init_func_t screen_init_func = 0;
screen_run_func_t  screen_run_func  = 0;
screen_end_func_t  screen_end_func  = 0;
// Static
static screen_type_t _current_screen;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
change_screen_to(screen_type_t s)
{

    _current_screen = s;
    if(s == SCREEN_TYPE_SPLASH) {
        screen_init_func = splash_screen_init;
        screen_run_func  = splash_screen_run;
        screen_end_func  = splash_screen_end;
    } else if(s == SCREEN_TYPE_SPLASH_INTRO) {
        screen_init_func = intro_screen_init;
        screen_run_func  = intro_screen_run;
        screen_end_func  = intro_screen_end;
    } else if(s == SCREEN_TYPE_GAME) {
        screen_init_func = game_screen_init;
        screen_run_func  = game_screen_run;
        screen_end_func  = game_screen_end;
    } else if(s == SCREEN_TYPE_GAME_OVER) {
        screen_init_func = game_over_screen_init;
        screen_run_func  = game_over_screen_run;
        screen_end_func  = game_over_screen_end;
    }

    screen_init_func();
}
