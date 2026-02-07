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
