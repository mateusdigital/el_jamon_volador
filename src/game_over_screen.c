// Header
#include "../include/game_over_screen.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/constants.h"
#include "../include/math.h"

#include "../include/screens.h"
#include "../include/fade.h"
#include "../include/shake.h"

#include "../include/background.h"
#include "../include/pipe.h"
#include "../include/player.h"
#include "../include/score.h"
// Res
#include "../include/res/sprites.h"


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
game_over_screen_init()
{
    //
    // Reset stuff
    reset_fade_status(FADE_DURATION);
    reset_shake();

    // Make sure that background stops moving.
    background_speed_x = 0;
}

//------------------------------------------------------------------------------
BOOL
game_over_screen_run()
{
    // Shaking...
    if(update_shake() == FALSE) {
        draw_pipe  ();
        draw_player();
        draw_score ();

        return TRUE;
    }

    if(fade_out()) {
        reset_player_position();
        reset_pipe           ();

        draw_pipe  ();
        draw_player();

        return FALSE;
    }

    return TRUE;
}

//------------------------------------------------------------------------------
void
game_over_screen_end()
{
    change_screen_to(SCREEN_TYPE_SPLASH_INTRO);
}
