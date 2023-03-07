#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player{
    private:
        int health;
        int armor;
        int magicApt;
        int STR;
        int magicPoints;
        std::string name;
        std::string playerClass;
    public:
        Player() : health(0), armor(0), magicApt(0), STR(0), magicPoints(0), name("Default"), playerClass("Default") {}
        Player(int hp, int ar, int mDMG, int pDMG, int mp, std::string myName, std::string myPlayerClass) : health(hp), armor(ar), magicApt(mDMG), STR(pDMG), magicPoints(mp), name(myName), playerClass(myPlayerClass) {}
        ~Player() {}
        int getHealth();
        int getArmor();
        int getMagicApt();
        int getSTR();
        int getMP();
        std::string getName();
        std::string getClass();
        void setHealth(int);
        void setArmor(int);
        void setMagicApt(int);
        void setMagicPoints(int);
        void setSTR(int);
        void setClass(std::string myClass);
        void setALL(int, int, int, int, int, std::string, std::string);
};

#endif