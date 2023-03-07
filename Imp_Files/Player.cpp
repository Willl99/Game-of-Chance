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
    int Player::getMP(){
        return this->magicPoints;
    }

    void Player::setHealth(int hp){ //Setter functions for player attributes
        this->health = hp;
    }
    void Player::setArmor(int ar){
        this->armor = ar;
    }
    void Player::setMagicApt(int mDMG){
        this->magicApt = mDMG;
    }
    void Player::setMagicPoints(int mp){
        this->magicPoints = mp;
    }
    void Player::setSTR(int strength){
        this->STR = strength;
    }
    void Player::setClass(std::string myClass){
        this->playerClass = myClass;
    }
    void Player::setALL(int hp, int ar, int mDMG, int mp, int strength, string Name, string myClass){ //Setter functions for player attributes
        this->health = hp;
        this->armor = ar;
        this->magicApt = mDMG;
        this->magicPoints = mp;
        this->STR = strength;
        this->playerClass = myClass;
        this->name = Name;
    }
    