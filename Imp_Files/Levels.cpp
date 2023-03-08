#include "Levels.h"
#include <chrono>
#include <sysinfoapi.h>
#include <fstream>
#include <Libraries/jsoncpp/json/json.h>
using namespace std::chrono;

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

void level::generateLevel(level curLevel){ //Simple level generator using rng, enemy and treasrue count is based on depth, while type is random with weights
    int enemiesGen;
    int treasureCount;
    int curType;
    int memTaker = 3908;
    std::string desc;
    std::string curTypeString;
    uint64_t seed1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    uint64_t seed2 = milliseconds(GetTickCount64()).count();
    srand(seed1);
    enemiesGen = rand() % depth;
    srand(seed2);
    treasureCount = rand() % depth;
    srand((int)((void*)&memTaker)); //I THINK this is using memory location for a random seed...I hope
    curType = ((rand() % 100) * depth) % 2; //Type of level is determined partially by depth, as some areas will be harder, 1 = cave, 2 = dungeon
    std::ifstream desc_file("../Content/Descriptions.json", std::ifstream::binary);
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
    this->description = (descriptions["levels"][curTypeString]["Description"]).asString();

}