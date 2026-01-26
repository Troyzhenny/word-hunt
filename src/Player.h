#pragma once
#include <string>
#include <vector>


enum class Items
{
    MedKit,
    Water,
    Hammer,
    Machete
};

enum class Foods
{
    Coconut,
    Mango,
    Fish,
    Crab,
    Crayfish
};

enum class Shelter
{
    Bamboo,
    Leaves,
    Vines,
    Rock,
    Stone
};

enum class MenuOption
{
    NEW_GAME,
    CONTINUE,
    CREDITS
};


class Player
{
    private:
        std::string playerName;
        std::vector<std::string> inventory;

    public:
        void setName(const std::string& name);
        std::string getName() const;

        void addItem(const std::string& item);

        void handleMenuOption(MenuOption option);
};


/*TODO*
    [] Level system (story based leveling)
    [] Story progression (tied to dialogue and the script)
    [] stats that increase
    [] unlockable items [no unlocakble areas, whole island is accesible and open world]
*/
