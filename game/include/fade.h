//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : fade.h                                                        //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//    Handles the fade in/out.                                                //
//---------------------------------------------------------------------------~//

#ifndef __FADE_H__
#define __FADE_H__

//
#include "types.h"

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define FADE_DURATION 20

#define FADE_0 0xFFU
#define FADE_1 0xFEU
#define FADE_2 0xF9U
#define FADE_3 0xE4U


//----------------------------------------------------------------------------//
// MACROS                                                                     //
//----------------------------------------------------------------------------//
#define SET_FADE_0() do { BGP_REG = 0xFFU; } while(0);
#define SET_FADE_1() do { BGP_REG = 0xFEU; } while(0);
#define SET_FADE_2() do { BGP_REG = 0xF9U; } while(0);
#define SET_FADE_3() do { BGP_REG = 0xE4U; } while(0);


//----------------------------------------------------------------------------//
// Public Functions                                                           //
//----------------------------------------------------------------------------//
void reset_fade_status(U16 totalFrames);
BOOL is_fade_completed();

BOOL fade_in ();
BOOL fade_out();

#endif // __FADE_H__
