// #include "GameLayout.h"
#include <iostream>
#include "terminal_colors.h"

void mainMenu()
{
    std::cout << " ==========================" << std::endl;
    std::cout << "|         STRANDED         |" << std::endl;
    std::cout << " ==========================" << std::endl;
    std::cout << "|      [1] NEW GAME        |" << std::endl;
    std::cout << "|      [2] CONTINUE        |" << std::endl;
    std::cout << "|      [3] CREDITS         |" << std::endl;
    std::cout << " ==========================" << std::endl;
}

// TODO: for each menu, if there's no new game, continue is disabled

// game start function
void startGame()
{
    std::cout << GREEN << "Game Started" << RESET << std::endl;
}

// gane end function

// continue game function

// show credits function
