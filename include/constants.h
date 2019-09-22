//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : constants.h                                                   //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//    Constants that are used by the whole game.                              //
//---------------------------------------------------------------------------~//

#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

//----------------------------------------------------------------------------//
// Screen                                                                     //
//----------------------------------------------------------------------------//
// @improve(stdmatt): Should be a better way to find those values...
#define SCREEN_X1 8
#define SCREEN_Y1 16
#define SCREEN_X2 160
#define SCREEN_Y2 152

#define SCREEN_MIDDLE_X 88 //(SCREEN_X2 + SCREEN_X1) / 2
#define SCREEN_MIDDLE_Y 84 //(SCREEN_Y2 + SCREEN_Y1) / 2


//----------------------------------------------------------------------------//
// Sprites                                                                    //
//----------------------------------------------------------------------------//
#define SPRITE_SIZEd2    4
#define SPRITE_SIZE      8
#define SPRITE_SIZEx2    16
#define SPRITE_SIZEx3    24
#define SPRITE_SIZEx4    32


#define SPRITE_NO_PLAYER       0
#define SPRITE_NO_PLAYER_COUNT 4
#define SPRITE_NO_PLAYER_MAX   (SPRITE_NO_PLAYER + SPRITE_NO_PLAYER_COUNT -1)

#define SPRITE_NO_PIPES       (SPRITE_NO_PLAYER_MAX + 1)
#define SPRITE_NO_PIPES_COUNT ((7 * 2) * 2) + 4
#define SPRITE_NO_PIPES_MAX   (SPRITE_NO_PIPES + SPRITE_NO_PIPES_COUNT -1)

#define SPRITE_NO_SCORE       (SPRITE_NO_PIPES_MAX + 1)
#define SPRITE_NO_SCORE_COUNT 10
#define SPRITE_NO_SCORE_MAX   (SPRITE_NO_SCORE + SPRITE_SCORE_NO_COUNT -1)

#define JOYPAD_ACTION J_A

#endif // __CONSTANTS_H__
