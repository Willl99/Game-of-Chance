#include "Levels.h"
#include <sysinfoapi.h>
#include <fstream>
#include <json.h>

#include <iostream>


int depth = 1;

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

std::string level::getDescription(){
    return this->description;
}

void level::generateLevel(){ //Simple level generator using rng, enemy and treasrue count is based on depth, while type is random with weights
    int enemiesGen;
    int treasureCount;
    int curType;
    int memTaker = 3908;
    std::string desc;
    std::string curTypeString;

    enemiesGen = rand() % depth + 1;
    treasureCount = rand() % depth + 1;
    srand(reinterpret_cast<uint64_t>(((void*)&memTaker))); //I THINK this is using memory location for a random seed...I hope
    curType = ((rand() % 100) * depth) % 2 + 1; //Type of level is determined partially by depth, as some areas will be harder, 1 = cave, 2 = dungeon

    std::ifstream desc_file("C:\\Users\\Will\\Documents\\Game of Chance\\Content\\Descriptions.json", std::ifstream::binary); //Read in descriptions from description JSON
    Json::Value descriptions;
    desc_file >> descriptions;
    
    this->enemyCount = enemiesGen;
    this->treasureChestCount = treasureCount;
    this->type = curType;
    switch(curType){
        case 1:
        {
            curTypeString = "Cave";
            break;
        }
        case 2:
        {
            curTypeString = "Dungeon";
            break;
        }
    };
    this->description = (descriptions[curTypeString][0]["Description1"]).asString(); //For now this only uses the first of many possible descriptions until I feel like implementing a way to track which descriptions have been used so far.
    for(int i = 0; i < this->enemyCount; i++){
        enemy * myEnemy = new skeleton();
        this->enemies.push_back(myEnemy);
    }
    depth++; //This may not work, if rng values are weird then its probably this.
}

void level::removeEnemy(){
    this->enemies.pop_back();
}

bool level::checkIfCleared(){
    if (this->enemies.size() == 0){
        return true;
    }
    else{
        return false;
    }
}

enemy* level::chooseEnemy(){
    return this->enemies.back();
}