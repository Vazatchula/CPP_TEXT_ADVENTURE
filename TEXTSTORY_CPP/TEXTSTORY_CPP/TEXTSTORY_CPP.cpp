// TEXTSTORY_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "String.h"
#include "map.h"
#include "PLAYER.h"
#include "item.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
extern bool gameRunning;
bool inventoryOpen = true;
extern bool ratfight;
extern bool playerAlive;

int main(){
    char* input;
    input = new char[12];

    cout << R"( 
               
  
              ___.                         __                 
  _____ ______\_ |__   ___________   _____/  |_ __ __  _____  
  \__  \\_  __ \ __ \ /  _ \_  __ \_/ __ \   __\  |  \/     \ 
   / __ \|  | \/ \_\ (  <_> )  | \/\  ___/|  | |  |  /  Y Y  \
  (____  /__|  |___  /\____/|__|    \___  >__| |____/|__|_|  /
       \/          \/                   \/                 \/ 
  
 
)";

    
    cout << "What should I call you?" << endl;
    cout << ">> "; cin >> input; cout << "\n \n";

    cout << R"(
   
                    WELCOME TO THE GARDEN.

            ,,,                      ,,,
           {{{}}    ,,,             {{{}}    ,,,
        ,,, ~Y~    {{{}},,,      ,,, ~Y~    {{{}},,, 
       {{}}} |/,,,  ~Y~{{}}}    {{}}} |/,,,  ~Y~{{}}}
        ~Y~ \|{{}}}/\|/ ~Y~  ,,, ~Y~ \|{{}}}/\|/ ~Y~  ,,,
        \|/ \|/~Y~  \|,,,|/ {{}}}\|/ \|/~Y~  \|,,,|/ {{}}}
        \|/ \|/\|/  \{{{}}/  ~Y~ \|/ \|/\|/  \{{{}}/  ~Y~
        \|/\\|/\|/ \\|~Y~//  \|/ \|/\\|/\|/ \\|~Y~//  \|/
        \|//\|/\|/,\\|/|/|// \|/ \|//\|/\|/,\\|/|/|// \|/
       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
)";

    cout << R"(
You find yourself in a dense forest. There doesnt seem to be any proper
paths to lead you.

The trees don't seem to have any defining features. The wood is smooth
like plastic, almost looking artificial. How strange. 

)";


    player* TESTPLAYER = new player(input, 100, 20, 10); // creates player stats + name
    
    

    while (gameRunning == true) {

       
        TESTPLAYER->healthCheck();
        cout << R"(
       //-- "menu" to open the menu --\\
            //-- "q" to quit. --\\

//-- MOVEMENT: "up", "down", "left", "right" --\\

x2 and y1 for ratfight
x1 and y3 for silver key
)";
     
       
        cout << ">> "; cin >> input;
        cout << "\n";

        if (strcmp(input, "q") == 0) {
            gameRunning = false; // game exit code
            break;
        }

        if ((strcmp(input, "menu") == 0) && (ratfight == false)) {
            inventoryOpen = true;

            while (inventoryOpen) {
                TESTPLAYER->inventory(); // opens the inventory infinitely until closed
            }
            

        } else TESTPLAYER->move(input);
       
        if (ratfight == true) TESTPLAYER->enemyRATS();

        


    } 
    
    
}

