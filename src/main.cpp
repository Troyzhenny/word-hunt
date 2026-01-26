#include <iostream>
#include "terminal_colors.h"
#include "Player.h"
#include "GameLayout.h"

int main()
{
    mainMenu();
    startGame();

    Player player;
    std::string name;

    std::cout << LIGHT_YELLOW << "Enter your name: " << RESET << std::endl;
    std::cin>> name;

    player.setName(name);

    std::cout << LIGHT_PURPLE << "Hello, " << player.getName() << "!" << RESET << std::endl;

    return 0;
}
