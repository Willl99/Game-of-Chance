#include "Enemies.h"
#include <iostream>

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

std::string enemy::getType(){
    return this->type;
}

enemy::enemy(int health, int attackPoints, int armorPoints, std::string typeOfEnemy){
    this->hp = health;
    this->attack = attackPoints;
    this->armor = armorPoints;
    this->type = typeOfEnemy;
}
