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
        int getAttack();
        std::string getType();
        enemy(int, int, int, std::string);
        virtual ~enemy() {delete this;}
        virtual int doAction() {}

};

class skeleton : public enemy{
    public:
        skeleton() : enemy(5, 10, 3, "Skeleton") {}
        int doAction();
};
#endif