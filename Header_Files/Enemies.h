#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>
class enemy{
    private:
        int hp;
        int attack;
        int armor;
        std::string type;
    public:
        void reduceHP(int);
        bool Killed();
        int getHP();
        std::string getType();
        enemy(int);
};


#endif