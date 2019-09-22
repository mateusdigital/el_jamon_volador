//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : background.c                                                  //
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
#include "../include/background.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/shake.h"
// Res
#include "../include/res/sprites.h"

//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Extern
I16 background_speed_x = 0;
// Static
I16 background_x = 0;


//----------------------------------------------------------------------------//
// Public Functions                                                           //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
load_splash_background()
{
    set_bkg_data(0, 81, TileData);

    set_bkg_tiles(0, 0, 20, 18, MapData);
    set_bkg_tiles(12, 0, 20, 18, MapData);
}

//------------------------------------------------------------------------------
void
load_game_background()
{
    set_bkg_data(0, 81, TileData);

    set_bkg_tiles(0, 0, 20, 18, MapData);
    set_bkg_tiles(12, 0, 20, 18, MapData);
}

//------------------------------------------------------------------------------
void
move_game_background()
{
    move_bkg(++background_x + shake_x, shake_y);
}
