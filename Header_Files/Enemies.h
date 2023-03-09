#ifndef ENEMIES_H
#define ENEMIES_H

class enemy{
    private:
    int hp;
    int attack;
    int armor;
    public:
    void reduceHP(int);
    bool Killed();
    int getHP();
};

class skeleton : public enemy{
    int hp = 5;
    int attack = 1;
    int armor = 0;
};

#endif