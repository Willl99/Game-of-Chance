#ifndef LEVELS_H
#define LEVELS_H
#include <string>
#include <vector>
#include "Enemies.h"
class level{
    private:
        int enemyCount;
        int treasureChestCount;
        int type;
        std::string description;
        std::vector<enemy*> enemies;
    public:
        int getEnemyCount();
        int getTreasure();
        int getType();
        std::string getDescription();
        void setLevelAttributes(int, int, int, std::string); //Only need a single method for setting attributes since they're set at the same time
        void generateLevel();
        bool checkIfCleared();
        void removeEnemy();
        enemy* chooseEnemy();
};

#endif