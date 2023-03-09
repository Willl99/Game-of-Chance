#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>
class enemy{
    protected:
        int hp;
        int attack;
        int armor;
        std::string type;
    public:
        void reduceHP(int);
        bool Killed();
        int getHP();
        std::string getType();
        enemy(int, int, int, std::string);
};

class skeleton : public enemy{
    public:
        skeleton() : enemy(5, 1, 3, "Skeleton") {}
};
#endif