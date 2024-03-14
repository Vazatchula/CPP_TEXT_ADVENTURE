#include "PLAYER.h"
#include "String.h"
#include "map.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
extern bool gameRunning;
extern bool inventoryOpen;


player::player(const char* NAME, int HP, int ATTK, int MN)
{
	name = new char[strlen(NAME)];
	name[0] = '\0';
	strcat(name, NAME);

	//name = NAME.CStr();
	//cout << "+++ player constructor: " << name << " +++" << endl;
	health = HP;
	attack = ATTK;
	mana = MN;
	mapX = 0; mapY = 0;
	playerAlive = true;
	cout << "HEALTH: " << health << endl;
	cout << "ATTACK: " << attack << endl;
	cout << "MANA: " << mana << endl;
	//cout << name;
	
	
}

player::~player()
{
	
}

void player::move(const String& direction)
{
	const char* movement = direction.CStr();
	

	
		if (strcmp(movement, "up") == 0) {
			if (yLimit == true) {
				cout << "You cant move any further\n" << endl;
				return;
			}
			else {
				mapY++;
				cout << ">> " << name << ": You move up to the next room\n" << endl;
			}
			roomDescription(mapX, mapY);
			mapcheck(mapX, mapY);
			
			return;
		}
		else if (strcmp(movement, "right") == 0) {
			if (xLimit == true) {
				cout << "You cant move any further\n" << endl;
				return;
			}
			else {
				mapX++;
				cout << ">> " << name << ": You move right to the next room\n" << endl;
			}
			roomDescription(mapX, mapY);
			mapcheck(mapX, mapY);
			
			return;
		}
		else if (strcmp(movement, "down") == 0) {
			mapY--;
			if (mapY < 0) {
				mapY = 0;
				cout << "You cant move any further\n" << endl;
				return;
			}
			else cout << ">> " << name << ": You move down to the next room\n" << endl;
			roomDescription(mapX, mapY);
			mapcheck(mapX, mapY);
			
			return;
		}
		else if (strcmp(movement, "left") == 0) {
			mapX--;
			if (mapX < 0) {
				mapX = 0;
				cout << "You cant move any further\n" << endl;
				return;
			}
			else cout << ">> " << name << ": You move left to the next room\n" << endl;
			roomDescription(mapX, mapY);
			mapcheck(mapX, mapY);
			
			return;
		}
	
		if (strcmp(movement, "down") == 0) {
			mapY--;
			if (mapY < 0) {
				mapY = 0;
				cout << "You cant move any further\n" << endl;
				return;
			}
			else cout << ">> " << name << ": You move left to the next room\n" << endl;
			roomDescription(mapX, mapY);
			mapcheck(mapX, mapY);
			
			return;
		}
		else if (strcmp(movement, "left") == 0) {
			mapX--;
			if (mapX < 0) {
				mapX = 0;
				cout << "You cant move any further\n" << endl;
				return;
			}
			else cout << ">> " << name << ": You move left to the next room\n" << endl;
			//cout << xPosition;
			roomDescription(mapX, mapY);
			mapcheck(mapX, mapY);
			//cout << &mapcheck;
			return;
		}
	
	else if (strcmp(movement, "stay") == 0) {
		//cout << xPosition;
		cout << ">> " << name << ": You decide to wait in this room\n" << endl;
		//roomDescription(mapX, mapY);
		mapcheck(mapX, mapY);
		//cout << &mapcheck;
				return;
	}
	else {
		cout << "INVALID OPTION. OPTIONS ARE:" << endl;
		cout << "'up', 'down', 'left', 'right', 'stay'\n" << endl;
		//cout << mapcheck;
	}

	

}

void player::damage(const int& dmg)
{
	int damage = dmg;
	health -= damage;
	cout << name << " took damage!" << endl;
	cout << "PLAYER HEALTH: " << health << endl;
	
	if ((health == 0) || (health < 0)) {
		playerAlive = false;
		cout << name << " has died" << endl;
		gameRunning = false;
	}
	return;

}

void player::inventory()
{
	cout << "-- INVENTORY --" << endl;
	char input[12];

	

		cout << "1. cat\n2. toast\n3. empty" << endl;
		cout << ">> "; cin >> input;
		if ((strcmp(input, "cat") == 0 ) || (strcmp(input, "1") == 0)) {
			cout << R"(
meow meow meow meow meow meow meow meow meow meow meow meow meow 
meow meow meow meow meow meow meow meow meow meow meow meow meow 
meow meow meow meow meow meow meow meow meow meow meow meow meow 
meow meow meow meow meow meow meow meow meow meow meow meow meow 
meow meow meow meow meow meow meow meow meow meow meow meow meow 
                                     -__________-  
                                               \   |\__/,|   (`\ 
                                                ^_.|o o  |_   ) ) 
                                                -(((---(((--------

>> what the fuck.
)";
			return;
		}
		else if ((strcmp(input, "toast") == 0) || (strcmp(input, "2") == 0)) {
			cout << R"(


                                                                  
                                       ==                         
                  =:.   .      #=:  =   .%%#*%*+**#**             
             ...  .-::   :          *%*  #=*::*%#%%*%%%*%**       
            *                      =%%+ =*%*==*#%%+##*%%%#%#      
            -                      %%%* -*%==+#%=*##*#%%%%%%      
                                  -%%%=*%%*=.*****=*%#*%#%#%      
           :                      %*#*:#%*=:--#=%+##=#***###      
             .                   .*#%=+**% .+**=**-*++=*#***      
          + .                    ##%+=*=+%:.=***+#*++****#*#      
                                .%%%===*++::=*:*==+*+=+*****      
         :                      +%**=-==*-=.=+%++++*+*+*##*       
        +                      .%*%*:==**=:::-+%+#*#=#**#*#       
        .                      :***+.=**#+-::*%#%####=*%%**       
       :                       **%*-:***%+==:*%#%%+#%#**%#%       
       =:==*==+-===::.    .   .***%=-=+***+=:*#%%%%*#****%%       
         %@%@@%%%%%%%%%%%#*%*****@%%*#***#****##%%%%%%%%%@========
                           =@@##%@@@@%**+========                
                                                                  
                                                                  
>> It's cold. Darn
)";
			return;
		}
		else if ((strcmp(input, "empty") == 0) || (strcmp(input, "3") == 0)) {
			cout << "EMPTY" << endl;
			return;
		}
		else if ((strcmp(input, "back") == 0)) {
			inventoryOpen = false;
			return;
		}
		else cout << "NO ITEM FOUND. PLEASE TRY AGAIN." << endl;

	
}


