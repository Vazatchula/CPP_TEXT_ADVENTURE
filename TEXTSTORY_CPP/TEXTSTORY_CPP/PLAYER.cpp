#include "PLAYER.h"

#include <vector>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS


using namespace std;
bool gameRunning;
extern bool inventoryOpen;
void enemy(const char* enemy);

bool ratfight;
bool playerAlive;
extern int donutamount;
extern int magicactivate;
vector<string> Magic;

player::player(const char* NAME, int HP, int ATTK, int MN)
{
	
	name = new char[strlen(NAME)];
	name[0] = '\0';
	strcat(name, NAME);

	//cout << "+++ player constructor: " << name << " +++" << endl;


	health = HP;
	attack = ATTK;
	mana = MN;
	mapX = 0; mapY = 0;
	playerAlive = true;
	cout << "HEALTH: " << health << endl;
	cout << "ATTACK: " << attack << endl;
	cout << "MANA: " << mana << endl;
	
	if (health <= 0) gameRunning = false;
	else gameRunning = true;
	
	donuts = true;

	Magic.push_back("fire");
	Magic.push_back("ice");
	Magic.push_back("water");
	Magic.push_back("air");



}


player::~player()
{
	
}

void player::healthCheck() {
	cout << "HEALTH: " << health << endl;
	cout << "ATTACK: " << attack << endl;
	cout << "MANA: " << mana << endl;
	if (health <= 0) gameRunning = false;
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
	if (damage < 0) cout << name << " gained health!" << endl;
	else cout << name << " took damage!" << endl;
	health -= damage;
	
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

	

	cout << "1. "; 
	if (key == true) cout << "SILVER KEY. "; else cout << "EMPTY. ";
	cout << "2. ";
	if (toast == true) cout << "TOAST. "; else cout << "EMPTY. ";
	cout << "3. ";
	if (donuts == true) cout << "DONUTS[?]. "; else cout << "EMPTY. ";


		cout << ">> "; cin >> input;
		if (strcmp(input, "1") == 0) {

			inventoryKey();

			return;
		}
		else if (strcmp(input, "2") == 0) {

			inventoryToast();

			return;
		}
		else if (strcmp(input, "3") == 0) {
			inventoryDonuts();
			cout << ">> "; cin >> input; cout << "\n \n";
			if ((strcmp(input, "y") == 0) && (donutsactivate == true)) {
				damage(-20);
				donutamount = donutamount - 1;
			}
			if ((strcmp(input, "y") == 0) && (donutsactivate == false)) {
				
				cout << "Desperate, you try to lick the frosting and crumbs from the box.\n\nWhat is wrong with you." << endl;
				
			}
			else if ((strcmp(input, "n") == 0) && (donutsactivate != false)) {

				cout << "You decide to diet today.\n" << endl;
			}
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


	cout << "ENEMY HP: " << rathealth << endl;


	while ((alive == true) || (player == true)) {
		
		if (health <= 0) {
			cout << "The [CANCEROUS RAT] eats your corpse." << endl;

			player = false;


			break;
		}

		cout << ">> The [CANCEROUS RAT] bites you for 10 DAMAGE" << endl;
		damage(10);
		cout << "ENEMY HP: " << rathealth << endl;

		if (health > 0) {
					cout << "What will you do?" << endl;
		cout << R"(
          //-- "menu" to open the menu --\\

//-- ACTIONS: "punch", "kick", "taunt", "magic" --\\

)";

		cout << ">> "; cin >> input;
		}



		if ((strcmp(input, "menu") == 0) && (ratfight == true) && (health > 0)) {
			inventoryOpen = true;

			while (inventoryOpen) {
				inventory();
			}


		}
		if ((strcmp(input, "punch") == 0) && (health > 0)) {
			cout << ">> You punch the [CANCEROUS RAT] for 10 DAMAGE." << endl;
			rathealth = rathealth - 10;

			
		}
		if ((strcmp(input, "kick") == 0) && (health > 0)) {
			cout << ">> You kick the [CANCEROUS RAT] for 30 DAMAGE." << endl;
			rathealth = rathealth - 30;
			
		}
		if ((strcmp(input, "taunt") == 0) && (health > 0)) {
			cout << ">> You taunt the [CANCEROUS RAT] for 5 DAMAGE." << endl;
			cout << ">> The [CANCEROUS RAT] gets pissed. You take 5 DAMAGE from rat curses." << endl;
			rathealth = rathealth - 5;
			
			damage(5);
		}
		if ((strcmp(input, "magic") == 0) && (health > 0)) {

			String* MAGIC = new String("fire, ice, water, air");


			char* input;
			input = new char[12];

			cout << ">> You cast: "; cin >> input; cout << endl;
			

			String* choice = new String(input);
			magicUse();






			//switch (magicactivate) {

			//case 1:
			//	cout << "fire magic" << endl;
			//	cout << ">> You explode the [CANCEROUS RAT] for " << mana << " DAMAGE." << endl;
			//	rathealth = rathealth - mana;
			//	break;

			//case 2:
			//	cout << "ice magic" << endl;
			//	cout << ">> You freeze the [CANCEROUS RAT] for " << mana << " DAMAGE." << endl;
			//	rathealth = rathealth - mana;
			//	break;

			//case 3:
			//	cout << "water magic" << endl;
			//	cout << ">> You drown the [CANCEROUS RAT] for " << mana << " DAMAGE." << endl;
			//	rathealth = rathealth - mana;
			//	break;

			//case 4:
			//	cout << "air magic" << endl;
			//	cout << ">> You send the [CANCEROUS RAT] flying into the air for " << mana << " DAMAGE." << endl;
			//	rathealth = rathealth - mana;
			//	break;

			//case 5:
			//	cout << "INCORRECT OPTION." << endl;
			//	magicUse();

			//default:
			//	cout << "INCORRECT OPTION." << endl;
			//	magicUse();
			//}

			/*cout << ">> You cast fireball on the [CANCEROUS RAT] for 60 DAMAGE." << endl;
			cout << "You take 10 DAMAGE due to the explosion." << endl;
			rathealth = rathealth - 60;*/
			
			// damage(10);
		}


		if (rathealth <= 0) {
			cout << ">> You obliterated the [CANCEROUS RAT]" << endl;
			cout << "Press any key to continue\n>> "; cin >> input; cout << endl;

			cout << ">> Rummaging through the [CANCEROUS RAT]'s corpse, you find [TOAST]\n\n>> You dont question it." << endl;
			alive = false;
			toast = true;
			ratfight = false;
			
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





