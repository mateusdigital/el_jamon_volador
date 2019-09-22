//~---------------------------------------------------------------------------//
//                        _      _                 _   _                      //
//                    ___| |_ __| |_ __ ___   __ _| |_| |_                    //
//                   / __| __/ _` | '_ ` _ \ / _` | __| __|                   //
//                   \__ \ || (_| | | | | | | (_| | |_| |_                    //
//                   |___/\__\__,_|_| |_| |_|\__,_|\__|\__|                   //
//                                                                            //
//  File      : fade.c                                                        //
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
#include "../include/fade.h"
// GBDK
#include <gb/gb.h>
#include <stdio.h>
// Game
#include "../include/types.h"


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Static
static BOOL _fade_completed    = FALSE;
static U16   _fade_frames_total = 0;
static U16   _fade_frames       = 0;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
reset_fade_status(U16 totalFrames)
{
    _fade_frames       = 0;
    _fade_frames_total = totalFrames;
    _fade_completed    = FALSE;
}

//------------------------------------------------------------------------------
BOOL
is_fade_completed()
{
    return _fade_completed;
}

//------------------------------------------------------------------------------
BOOL
fade_in()
{
    U16 i;

    //
    // We already completed all the frames of the fade animation.
    if(_fade_frames > _fade_frames_total) {
        _fade_completed = TRUE;
        return TRUE;
    }

    //
    // Fade animation has 4 stages, so we need to divide the total frames
    // to actually know in which step of the animation we are in.
    i = (_fade_frames_total / 4);
    ++_fade_frames;

    //
    // Just set the background pallet register
    if     (_fade_frames < i    ) { SET_FADE_0(); }
    else if(_fade_frames < i * 2) { SET_FADE_1(); }
    else if(_fade_frames < i * 3) { SET_FADE_2(); }
    else if(_fade_frames < i * 4) { SET_FADE_3(); }

    return FALSE;
}

//------------------------------------------------------------------------------
BOOL
fade_out()
{
    U16 i;

    //
    // We already completed all the frames of the fade animation.
    if(_fade_frames > _fade_frames_total) {
        _fade_completed = TRUE;
        return TRUE;
    }

    //
    // Fade animation has 4 stages, so we need to divide the total frames
    // to actually know in which step of the animation we are in.
    i = (_fade_frames_total / 4);
    ++_fade_frames;

    // Just set the background pallette register
    if     (_fade_frames < i    ) { SET_FADE_3(); }
    else if(_fade_frames < i * 2) { SET_FADE_2(); }
    else if(_fade_frames < i * 3) { SET_FADE_1(); }
    else if(_fade_frames < i * 4) { SET_FADE_0(); }

    return FALSE;
}
