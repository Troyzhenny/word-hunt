#pragma once
#include <string>




class Player
{
    private:
        std::string playerName;
        int myScore;

    public:
        void setName(const std::string& name);
        std::string getName() const;

};
