//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : game_over_screen.h                                            //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//    Handles the game when it's in the SCREEN_TYPE_GAME_OVER.                //
//---------------------------------------------------------------------------~//

#ifndef __GAME_OVER_SCREEN_H__
#define __GAME_OVER_SCREEN_H__

// Game
#include "types.h"

//----------------------------------------------------------------------------//
// Public Functions                                                           //
//----------------------------------------------------------------------------//
void game_over_screen_init();
BOOL game_over_screen_run ();
void game_over_screen_end ();

#endif //__GAME_OVER_SCREEN_H__
