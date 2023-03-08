#include "Levels.h"

using namespace std;

int level::getEnemyCount(){
    return this->enemyCount;
}

int level::getTreasure(){
    return this->treasureChestCount;
}

int level::getType(){
    return this->type;
}

void level::setLevelAttributes(int enemies, int chests, int curType, std::string desc){
    this->enemyCount = enemies;
    this->treasureChestCount = chests;
    this->type = curType;
    this->description = desc;
}