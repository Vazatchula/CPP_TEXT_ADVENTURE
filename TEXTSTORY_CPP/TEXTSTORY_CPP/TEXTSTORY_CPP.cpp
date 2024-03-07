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
    map* MAP = new map();
    player* TESTPLAYER = new player(100, 20, 10);
    char* input;
    input = new char[12];
    // String* location = new String(input);
    

    while (gameRunning) {
        cin >> input;
        TESTPLAYER->move(input);
        TESTPLAYER->damage(20);
        

        


    } 
    
    
}

