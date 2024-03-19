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
Cool description here. Really cool. Description very cool description
very cool description. Description.

Cool description here. Really cool. Description very cool description
very cool description. Description. Cool description here. Really cool.
Description very cool description very cool description. Description. 
Cool description here. Really cool. Description very cool description
very cool description. Description. Cool description here. Really cool. 
Description very cool description very cool description. Description.

)";

    //map* MAP = new map();
    player* TESTPLAYER = new player(input, 100, 20, 10);
    // String* location = new String(input);
    

    while (gameRunning == true) {

       
        TESTPLAYER->healthCheck();
        cout << R"(
       //-- "menu" to open the menu --\\

//-- MOVEMENT: "up", "down", "left", "right" --\\
)";
     
       
        cout << ">> "; cin >> input;
        cout << "\n";

        if (strcmp(input, "q") == 0) {
            gameRunning = false;
            break;
        }

        if (strcmp(input, "menu") == 0) {
            inventoryOpen = true;

            while (inventoryOpen) {
                TESTPLAYER->inventory();
            }
            

        } else TESTPLAYER->move(input);
        //TESTPLAYER->damage(20);
        if (ratfight == true) TESTPLAYER->enemyRATS();

        


    } 
    
    
}

