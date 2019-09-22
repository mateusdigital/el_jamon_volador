//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : intro_screen.h                                                //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//    Handles the game when it's in the SCREEN_TYPE_SPLASH_INTRO.             //
//---------------------------------------------------------------------------~//

#ifndef __INTRO_SCREEN_H__
#define __INTRO_SCREEN_H__

// Game
#include "types.h"

//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
void intro_screen_init();
BOOL intro_screen_run ();
void intro_screen_end ();

#endif //__INTRO_SCREEN_H__
