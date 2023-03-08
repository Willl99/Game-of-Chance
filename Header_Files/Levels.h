#ifndef LEVELS_H
#define LEVELS_H
#include <string>
class level{
    private:
        int enemyCount;
        int treasureChestCount;
        int type;
        std::string description;
    public:
        int getEnemyCount();
        int getTreasure();
        int getType();
        void setLevelAttributes(int, int, int, std::string); //Only need a single method for setting attributes since they're set at the same time

};

#endif