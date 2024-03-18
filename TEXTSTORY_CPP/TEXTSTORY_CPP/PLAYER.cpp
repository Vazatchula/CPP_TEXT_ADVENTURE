#include "PLAYER.h"
#include "String.h"
#include "map.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
bool gameRunning;
extern bool inventoryOpen;
void enemy(const char* enemy);
bool ratfight;
bool playerAlive;

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
	if (health <= 0) gameRunning = false;
	else gameRunning = true;
	
	
}


player::~player()
{
	
}

void player::healthCheck() {
	cout << "HEALTH: " << health << endl;
	cout << "ATTACK: " << attack << endl;
	cout << "MANA: " << mana << endl;
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
	
	if (health <= 0) {
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


void player::enemyRATS()
{
	int rathealth = 50;
	bool alive = true;
	bool player = true;

	char* input;
	input = new char[12];

	cout << "ENEMY HP: " << health << endl;

	while ((alive == true) || (player == true)) {
		

		cout << ">> The [CANCEROUS RAT] bites you for 10 DAMAGE" << endl;
		damage(10);

		cout << "What will you do?" << endl;
		cout << R"(
          //-- "menu" to open the menu --\\

//-- ACTIONS: "punch", "kick", "taunt", "fireball" --\\

)";

		cout << ">> "; cin >> input;

		if (strcmp(input, "menu") == 0) {
			inventoryOpen = true;

			while (inventoryOpen) {
				inventory();
			}

			return;
		}
		if (strcmp(input, "punch") == 0) {
			cout << ">> You punch the [CANCEROUS RAT] for 10 DAMAGE." << endl;
			health -= 10;
			cout << "ENEMY HP: " << health << endl;
		}
		if (strcmp(input, "kick") == 0) {
			cout << ">> You kick the [CANCEROUS RAT] for 30 DAMAGE." << endl;
			health -= 30;
			cout << "ENEMY HP: " << health << endl;
		}
		if (strcmp(input, "taunt") == 0) {
			cout << ">> You taunt the [CANCEROUS RAT] for 5 DAMAGE." << endl;
			cout << ">> The [CANCEROUS RAT] gets pissed. You take 5 DAMAGE from rat curses." << endl;
			health -= 5;
			cout << "ENEMY HP: " << health << endl;
			damage(5);
		}
		if (strcmp(input, "fireball") == 0) {
			cout << ">> You cast fireball on the [CANCEROUS RAT] for 60 DAMAGE." << endl;
			cout << "You take 10 DAMAGE due to the explosion." << endl;
			health -= 60;
			cout << "ENEMY HP: " << health << endl;
			damage(10);
		}
		if (health <= 0) {
			cout << "The [CANCEROUS RAT] eats your corpse." << endl;
			player = false;
			break;
		}

		if (rathealth <= 0) {
			cout << ">> You obliterated the [CANCEROUS RAT]" << endl;
			cout << "Press any key to continue\n>> "; cin >> input; cout << endl;

			cout << ">> Rummaging through the [CANCEROUS RAT]'s corpse, you find [TOAST]\n\n>> You dont question it." << endl;
			alive = false;
			
			return;
		}
	}
}

void enemy(const char* enemy)
{
	if (strcmp(enemy, "rat") == 0) {
		ratfight = true;
		return;
	}
}
