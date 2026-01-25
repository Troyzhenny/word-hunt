#include "Player.h"

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


// Player :: add item (for inventory)
void Player::addItem(const std::string& item)
{
    inventory.push_back(item);
}
