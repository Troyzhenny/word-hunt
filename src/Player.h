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

class Player
{
    private:
        std::string playerName;
        std::vector<std::string> inventory;

    public:
        void setName(const std::string& name);
        std::string getName() const;

        void addItem(const std::string& item);
};


/*TODO*
    [] Level system
    [] stats that increase
    [] Story progression
    [] unlockable items [no unlocakble areas, whole island is accesible and open world]
*/
