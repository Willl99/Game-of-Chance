#include <iostream>
#include <fstream>
#include "InputHandler.h"
#include "Player.h"
using namespace std;

int main(){
    char userChoiceStart;
    cout << "Welcome to a game of chance. The odds are against you, but with some skill and good decision making, you can make it to the end." << endl;
    cout << "Would you like to begin? (Y/N)" << endl;
    getYNChoice();

    string playerName;
    cout << "Select your class (1 or 2): \n 1. Warrior  2. Mage" << endl;
    int myClass = getTripleChoice();
    cout << "And Enter a name" << endl;
    cin >> playerName;
    switch(myClass){
        case '1': 
        {
            Player newPlayer(100, 0, 1, 10, 3, playerName, "Warrior");
            cout << "Warrior selected!\nYou're starting stats are:" << endl;
            cout << "Health: " << newPlayer.getHealth() << endl;
            cout << "Magical Aptitude: " << newPlayer.getMagicApt() << endl;
            cout << "Strength: " << newPlayer.getSTR() << endl;
            cout << "Magic Points: " << newPlayer.getMP() << endl;
            break;
        }
        case '2': 
        {
            Player newPlayer(50, 0, 10, 1, 10, playerName, "Mage");
            cout << "Mage selected!\nYou're starting stats are:" << endl;
            cout << "Health: " << newPlayer.getHealth() << endl;
            cout << "Magical Aptitude: " << newPlayer.getMagicApt() << endl;
            cout << "Strength: " << newPlayer.getSTR() << endl;
            cout << "Magic Points: " << newPlayer.getMP() << endl;
            break;
        }
    }
    
    
}