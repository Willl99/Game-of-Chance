#include <iostream>
#include "Player.h"
using namespace std;

    int Player::getHealth(){ //Getter functions for player attributes
        return this->health;
    }
    int Player::getArmor(){
        return this->armor;
    }
    int Player::getMagicApt(){
        return this->magicApt;
    }
    int Player::getSTR(){
        return this->STR;
    }
    string Player::getName(){
        return this->name;
    }
    string Player::getClass(){
        return this->playerClass;
    }

    void Player::setHealth(int hp){ //Setter functions for player attributes
        this->health = hp;
    }
    void Player::setArmor(int ar){
        this->armor = ar;
    }
    void Player::setmagicApt(int mDMG){
        this->magicApt = mDMG;
    }
    void Player::setSTR(int strength){
        this->STR = strength;
    }
    void Player::setClass(std::string myClass){
        this->playerClass = myClass;
    }