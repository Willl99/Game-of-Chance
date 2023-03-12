#include "Treasure.h"
#include <random>

int TreasureChest::getGoldCount(){
    return this->goldCount;
}

TreasureChest::TreasureChest(int levelDepth){
    float treasureChance = static_cast<float>(rand() / static_cast <float> (RAND_MAX)) + (levelDepth * .1);
    if (treasureChance >= .99){
        this->lootLevel = 5;
        this->chestName = "Hero's Chest";
    }
    else if (treasureChance >= .9 && treasureChance < .99){
        this->lootLevel = 4;
        this->chestName = "Adventurer's Chest";
    }
    else if (treasureChance >= .75 && treasureChance < .9){
        this->lootLevel = 3;
        this->chestName = "Pathfinder's Chest";
    }
    else if (treasureChance >= .5 && treasureChance < .75){
        this->lootLevel = 2;
        this->chestName = "Novices' Chest";
    }
    else if (treasureChance < .5){
        this->lootLevel = 1;
        this->chestName = "Commoner's Chest";
    }

    this->goldCount = (rand() % 50) * lootLevel;
}

std::string TreasureChest::getChestName(){
    return this->chestName;
}