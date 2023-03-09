#include "Enemies.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

void enemy::reduceHP(int damageTaken){
    this->hp = this->hp - damageTaken;
}

bool enemy::Killed(){
    if (this->hp <= 0){
        return true;
    }
    else{
        return false;
    }
}

int enemy::getHP(){
    return this->hp;
}

int enemy::getAttack(){
    return this->attack;
}

std::string enemy::getType(){
    return this->type;
}

enemy::enemy(int health, int attackPoints, int armorPoints, std::string typeOfEnemy){
    this->hp = health;
    this->attack = attackPoints;
    this->armor = armorPoints;
    this->type = typeOfEnemy;
}

int skeleton::doAction(){
    uint64_t seed = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    srand(seed);
    float hitChance = static_cast<float>(rand() / static_cast <float> (RAND_MAX));
    if (hitChance >= .3){
        return this->attack; //This should mean that the skeleton has a 70% chance to land a hit as if hitchance > .5 it should return the attack dmg amount
    }
    else{
        return 0;
    }
    
}

/*enemy::~enemy(){
    delete this;
} */