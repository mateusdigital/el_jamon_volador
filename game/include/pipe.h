//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : pipe.h                                                        //
//  Project   : flappy_gb                                                     //
//  Date      : May 08, 2019                                                  //
//  License   : GPLv3                                                         //
//  Author    : stdmatt <stdmatt@pixelwizards.io>                             //
//  Copyright : stdmatt - 2019                                                //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#ifndef __PIPE_H__
#define __PIPE_H__

// Game
#include "types.h"

//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define INVALID_PIPE_X   -30
#define PIPE_OPENESS_MIN  25


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
extern I16 pipe_x;
extern I16 pipe_y;
extern I16 pipe_openess;
extern I16 pipe_speed_x;
extern I16 pipe_generated;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
void reset_pipe   ();
void generate_pipe();

void load_pipe_sprites();
void draw_pipe        ();

#endif // __PIPE_H__