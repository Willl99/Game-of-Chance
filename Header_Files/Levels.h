#ifndef LEVELS_H
#define LEVELS_H
#include <string>
#include <vector>
#include "Enemies.h"
#include "Treasure.h"
class level{
    private:
        int enemyCount;
        int type;
        std::string description;
        std::vector<enemy*> enemies;
        std::vector<TreasureChest*> chests;
    public:
        int getEnemyCount();
        int getTreasureCount();
        int getType();
        virtual std::string getDescription();
        void setLevelAttributes(int, int, std::string); //Only need a single method for setting attributes since they're set at the same time
        void generateLevel();
        bool checkIfCleared();
        void removeEnemy();
        enemy* chooseEnemy();
        TreasureChest* chooseChest();
        void removeChest();
        virtual ~level() {}
};


#endif