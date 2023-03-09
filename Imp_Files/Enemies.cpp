#include "Enemies.h"

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