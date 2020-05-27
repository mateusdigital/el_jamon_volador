//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : screen.h                                                      //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#ifndef __SCREENS_H__
#define __SCREENS_H__

// Games
#include "types.h"

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define SCREEN_TYPE_SPLASH       0
#define SCREEN_TYPE_SPLASH_INTRO 1
#define SCREEN_TYPE_GAME         2
#define SCREEN_TYPE_GAME_OVER    3


//----------------------------------------------------------------------------//
// Typedefs                                                                   //
//----------------------------------------------------------------------------//
typedef void (*screen_init_func_t)();
typedef BOOL (*screen_run_func_t )();
typedef void (*screen_end_func_t )();

typedef U16 screen_type_t;


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
extern screen_init_func_t screen_init_func;
extern screen_run_func_t  screen_run_func;
extern screen_end_func_t  screen_end_func;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
void change_screen_to(screen_type_t screen);

#endif // __SCREENS_H__
