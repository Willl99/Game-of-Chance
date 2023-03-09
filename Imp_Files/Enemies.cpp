#include "Enemies.h"
#include <iostream>

void enemy::reduceHP(int damageTaken){
    this->hp = this->hp - damageTaken;
}

bool enemy::Killed(){
    if (this->hp <= 0){
        delete this;
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

enemy::enemy(int typeOfEnemy){
    switch(typeOfEnemy){
        case 1: //Skeleton
        { 
            hp = 5;
            attack = 1;
            armor = 0;
            type = "Skeleton";
            break;
        }
    }
}