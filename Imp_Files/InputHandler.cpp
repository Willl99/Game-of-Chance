#include <iostream>
#include "InputHandler.h"
using namespace std;

void getYNChoice(){
    bool isInputAccepted = false;
    while (!isInputAccepted){
        char userChoice;
        cin >> userChoice;
        if (userChoice == 'Y' || userChoice == 'N' || userChoice == 'y' || userChoice == 'n'){
            isInputAccepted = true;
        }
        else{
            cout << "Please choose Y or N." << endl;
        }
    }
}

int getTripleChoice(){
    
    while (true){
        char userChoice;
        cin >> userChoice;
        if (userChoice == '1' || userChoice == '2' || userChoice == '3'){
           return userChoice;
        }
        else{
            cout << "Please choose Y or N." << endl;
        }
    }
}