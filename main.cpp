#include <iostream>
#include <fstream>
#include "InputHandler.h"
#include "Player.h"
#include "Levels.h"
using namespace std;

int main(){
    char userChoiceStart;
    cout << "Welcome to a game of chance. The odds are against you, but with some skill and good decision making, you can make it to the end." << endl;
    cout << "Would you like to begin? (Y/N)" << endl;
    getYNChoice();
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
            if (target->getType() == "Skeleton"){
                skeleton *target = dynamic_cast<skeleton*>(target);
            }

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
                    cout << "Skeleton tries for a hit and succeeds!" << endl;
                    cout << "You take " << target->getAttack() - newPlayer.getArmor() << " points of dmg" << endl;
                    newPlayer.takeDamage(target->getAttack());
                }
                playerTurn = true;
            }
        }
            if (newLevel.checkIfCleared()){
                cout << "You cleared this floor! Now, claim your treasure!" << endl;
            }
            else{
                cout << "Game over." << endl;
            }
        
        depth++;
    }
}