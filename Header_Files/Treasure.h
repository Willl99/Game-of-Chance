#ifndef TREASURE_H
#define TREASURE_H
#include <string>

class TreasureChest{
    private:
        int goldCount;
        int lootLevel;
        std::string chestName;
    public:
        int getGoldCount();
        std::string getChestName();
        TreasureChest(int);
        ~TreasureChest() {delete this;}


};


#endif