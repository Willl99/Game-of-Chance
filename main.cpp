#include <iostream>
#include <fstream>
#include "InputHandler.h"
#include "Player.h"
#include "Levels.h"
#include <chrono>

using namespace std;
using namespace chrono;



int main(){
    char userChoiceStart;
    cout << "Welcome to a game of chance. The odds are against you, but with some skill and good decision making, you can make it to the end." << endl;
    cout << "Would you like to begin? (Y/N)" << endl;
    getYNChoice();
    uint64_t seed = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); //These seeds are crappy for fast combat, replace with something else thats more random
    srand(seed);
    Player newPlayer;
    string playerName;
    cout << "Select your class (1 or 2): \n 1. Warrior  2. Mage" << endl;
    int myClass = getTripleChoice();
    cout << "And Enter a name" << endl;
    cin >> playerName;
    switch(myClass){ //Case statement for class assignment, 
        case '1': 
        {
            newPlayer.setALL(100, 0, 1, 10, 3, playerName, "Warrior");
            cout << "      /| ________________ " << endl;
            cout << "O|===|* >________________>" << endl;
            cout << "      \\| " << endl;                  
            cout << "You are " << newPlayer.getName() << " the Warrior!\nYou're starting stats are:" << endl;
            cout << "Health: " << newPlayer.getHealth() << endl;
            cout << "Magical Aptitude: " << newPlayer.getMagicApt() << endl;
            cout << "Strength: " << newPlayer.getSTR() << endl;
            cout << "Magic Points: " << newPlayer.getMP() << endl;
            cout << endl;
            break;
        }
        case '2': 
        {
            newPlayer.setALL(50, 0, 10, 1, 10, playerName, "Mage");
            cout << "You are " << newPlayer.getName() << " the Mage!\nYou're starting stats are:" << endl;
            cout << "Health: " << newPlayer.getHealth() << endl;
            cout << "Magical Aptitude: " << newPlayer.getMagicApt() << endl;
            cout << "Strength: " << newPlayer.getSTR() << endl;
            cout << "Magic Points: " << newPlayer.getMP() << endl;
            cout << endl;
            break;
        }
    }
    
    cout << "You enter the dungeon through a small door, the noises you hear within cause you to falter for a moment, but you steel your resolve and enter..." << endl;
    int depth = 1;
    while (depth < 2){ //This is the main game loop 
        level newLevel;
        bool playerTurn = true;
        newLevel.generateLevel();

        cout << newLevel.getDescription() << endl;
        cout << endl;
        cout << "You enter the dungeon to see " << newLevel.getEnemyCount() << " skeletons blocking your path..." << endl;
        cout << endl;
        while(!newLevel.checkIfCleared() || newPlayer.getHealth() == 0){ //This is the level combat loop
            int battleChoice;
            enemy * target = newLevel.chooseEnemy();

            if (playerTurn){
                cout << "Status: " << "HP: " << newPlayer.getHealth() << endl;
                cout << "What will you do?" << endl;
                cout << "1. Attack   2. Wait   3. Die" << endl;
                battleChoice = getTripleChoice();
                switch(battleChoice){
                    case '1':
                        {
                            target->reduceHP(newPlayer.getSTR());
                            if (target->Killed()){
                                cout << "You killed the " << target->getType() << "!" << endl;
                                newLevel.removeEnemy();
                            }
                            break;
                        }
                    case '2':
                        {
                            break;
                        }
                    case '3':
                        {
                            exit(0);
                        }
                }
                playerTurn = false;
            }
            else{
                int damageGiven = target->doAction();
                if (damageGiven > 0){
                    cout << target->getType() << " tries for a hit and succeeds!" << endl;
                    int playerDamageTaken = target->getAttack() - newPlayer.getArmor();
                    cout << "You take " << playerDamageTaken << " points of dmg" << endl;
                    newPlayer.takeDamage(playerDamageTaken);
                }
                else{
                    cout << "Skeleton tries for a hit and fails!" << endl;
                }
                playerTurn = true;
            }
        }
            if (newLevel.checkIfCleared()){
                cout << "You cleared this floor! Now, claim your treasure!" << endl;
                while (newLevel.getTreasureCount() > 0){
                    TreasureChest* chosenChest = newLevel.chooseChest();
                    cout << "You found a " << chosenChest->getChestName() << "!" << endl;
                    cout << "You got " << (chosenChest)->getGoldCount() << " gold!" << endl;
                    newLevel.removeChest();
                }
            }
            else{
                cout << "Game over." << endl;
            }
        
        depth++;
    }
}