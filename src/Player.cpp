#include "Player.h"
#include "terminal_colors.h"
#include <iostream>


void Player::handleMenuOption(MenuOption option)
{
    switch(option)
    {
        case MenuOption::NEW_GAME:
            // do something
            break;

        case MenuOption::CONTINUE:
            // do something
            break;

        case MenuOption::CREDITS:
            // do something
            break;

        default:
            std::cout << LIGHT_RED << "Invalid Option" << RESET << std::endl;
            break;
    }
}


void Player::setName(const std::string& name)
{
    if (name.empty()) {
        playerName = "Unknown";
    } else {
        playerName = name;
    }
}

std::string Player::getName() const
{
    return playerName;
}


void Player::addItem(const std::string& item)
{
    inventory.push_back(item);
}

// show inventory
