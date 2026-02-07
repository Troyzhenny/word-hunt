#pragma once
#include <string>



enum class GameState // decides what code runs, what state we're in, obviously...
{
    MAIN_MENU,
    NEW_GAME,
    HIGH_SCORES,
    ROLL_CREDITS,
    SAVE_SCORE,
    EXIT_GAME
};

std::string gameStateToString(GameState state); // we convert the state to string and use it for debugging
