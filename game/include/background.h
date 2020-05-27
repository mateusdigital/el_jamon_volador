//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : background.h                                                  //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//    Handles the background / splash screen of the game.                     //
//---------------------------------------------------------------------------~//

#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

// Game
#include "types.h"

//----------------------------------------------------------------------------//
// Public Vars                                                                //
//----------------------------------------------------------------------------//
extern I16 background_speed_x;


//----------------------------------------------------------------------------//
// Public Functions                                                           //
//----------------------------------------------------------------------------//
void load_splash_background();
void load_game_background  ();

void move_game_background();


#endif // __BACKGROUND_H__
