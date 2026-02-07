 #include "GameState.h"


/*
    controller for the state of the game, we switch between each state 
    as needed by the player using the menu and commands, which results in a flow... game flow.
*/

std::string gameStateToString(GameState state)
{
	switch (state)
	{
        case GameState::MAIN_MENU:    return "Main Menu";
        case GameState::NEW_GAME:     return "New Game";
        case GameState::HIGH_SCORES:  return "High Scores";
        case GameState::ROLL_CREDITS: return "Credits";
        case GameState::SAVE_SCORE:   return "Save Score";
        case GameState::EXIT_GAME:    return "Exit";
        default:                      return "Unknown";
	}
}