// TEXTSTORY_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "String.h"
#include "map.h"
#include "PLAYER.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
bool gameRunning = true;

int main()
{
    char* input;
    input = new char[12];
    
    cout << "What should I call you?" << endl;
    cin >> input;

    map* MAP = new map();
    player* TESTPLAYER = new player(input, 100, 20, 10);
    // String* location = new String(input);
    

    while (gameRunning) {
        cout << "Which direction will you go?\n'up', 'down', 'left', 'right'" << endl;
        cin >> input;
        TESTPLAYER->move(input);
        TESTPLAYER->damage(20);
        

        


    } 
    
    
}

