// Header
#include "../include/intro_screen.h"
// GBDK
#include <gb/gb.h>
// Game
#include "../include/constants.h"
#include "../include/math.h"

#include "../include/screens.h"
#include "../include/fade.h"
#include "../include/shake.h"

#include "../include/background.h"
#include "../include/player.h"
#include "../include/pipe.h"
#include "../include/score.h"
// Res
#include "../include/res/sprites.h"


//----------------------------------------------------------------------------//
// Constants                                                                  //
//----------------------------------------------------------------------------//
#define AUTO_FLY_SIN_DELAY_MAX 10


//----------------------------------------------------------------------------//
// Vars                                                                       //
//----------------------------------------------------------------------------//
// Auto fly
static I16 _auto_fly_sin_input;
static U16  _auto_fly_sin_delay;


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
void
intro_screen_init()
{
    //
    // Load the sprites.
    load_game_background();
    load_player_sprites ();
    load_pipe_sprites   ();

    //
    // Reset the objects.
    reset_player_animation();
    reset_player_position ();
    reset_pipe            ();
    reset_score           ();
    reset_shake           ();

    //
    // Auto fly.
    _auto_fly_sin_input = 0;
    _auto_fly_sin_delay = AUTO_FLY_SIN_DELAY_MAX;

    //
    // Reset Fade.
    SET_FADE_0();
    reset_fade_status(FADE_DURATION);

    //
    // Move background layer.
    background_speed_x = 1;
}

//------------------------------------------------------------------------------
BOOL
intro_screen_run()
{
    if(fade_in() == FALSE) {
        return TRUE;
    }

    //
    // Make the Player oscillates into the middle of the screen
    // giving the impression that it's flying...
    if(++_auto_fly_sin_delay >= AUTO_FLY_SIN_DELAY_MAX) {
        ++_auto_fly_sin_input;
        _auto_fly_sin_delay = 0;

        player_y = SCREEN_MIDDLE_Y + (M_sin(_auto_fly_sin_input) * 2 / 500) - (SPRITE_SIZEx2);
    }

    //
    // Makes the player goes towards the middle of the screen.
    if(player_x < SCREEN_MIDDLE_X - (SPRITE_SIZEx2)) {
        player_x += 1;
    }
    //
    // Player is already on the target position... waits for the keypress.
    else if(joypad() & JOYPAD_ACTION) {
        return FALSE;
    }

    //
    // Draw
    move_game_background();

    draw_player();
    draw_pipe  ();

    return TRUE;
}

//------------------------------------------------------------------------------
void
intro_screen_end()
{
    change_screen_to(SCREEN_TYPE_GAME);
}
