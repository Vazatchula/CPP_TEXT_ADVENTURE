#include "PLAYER.h"

#include <vector>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS


using namespace std;
bool gameRunning;
extern bool inventoryOpen; // item class. Keeps the inventory looping until closed by player
void enemy(const char* enemy); // i dont remember i think its just a loop to jump through the different files because it was ass

bool ratfight;
bool playerAlive;
extern int donutamount; // from item class
extern int magicactivate; // ^
vector<string> Magic; // the vector itself is here, though
extern bool knownMagic; // item class

player::player(const char* NAME, int HP, int ATTK, int MN)
{
	// making the name usuable in the class. annoying
	name = new char[strlen(NAME)];
	name[0] = '\0';
	strcat(name, NAME);


	// ignore this
	//cout << "+++ player constructor: " << name << " +++" << endl;


	// assign every value to something useable in the class. imporant //
	health = HP;
	attack = ATTK;
	mana = MN;
	mapX = 0; mapY = 0;
	playerAlive = true;
	cout << "HEALTH: " << health << endl;
	cout << "ATTACK: " << attack << endl;
	cout << "MANA: " << mana << endl;
	
	// I have so many ways to turn off this bool and it does nothing still :skull:
	if (health <= 0) gameRunning = false;
	else gameRunning = true;
	
	// didnt implement a way to collect the healing item, turned it on at spawn-in
	donuts = true;


	// for the magic binary search. It was actually a lot easier than I thought
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
	if (health <= 0) gameRunning = false; // an attempt to make the game shut off faster when the player dies...
}

void player::move(const String& direction)
{
	const char* movement = direction.CStr(); // taking the input into a useable value
	

	
		if (strcmp(movement, "up") == 0) {
			if (yLimit == true) {
				cout << "You cant move any further\n" << endl;
				return; // no more noclipping through the walls sorry guys
			}
			else {
				mapY++; // moves the coords up
				cout << ">> " << name << ": You move up to the next room\n" << endl;
			}
			roomDescription(mapX, mapY); // these both go to map file
			mapcheck(mapX, mapY); // "
			
			return;
		}
		else if (strcmp(movement, "right") == 0) {
			if (xLimit == true) {
				cout << "You cant move any further\n" << endl;
				return; // no noclipping this way either soz
			}
			else {
				mapX++; // moves the coords up
				cout << ">> " << name << ": You move right to the next room\n" << endl;
			}
			roomDescription(mapX, mapY);
			mapcheck(mapX, mapY);
			
			return;
		}
		else if (strcmp(movement, "down") == 0) {
			mapY--; // moves the coords down
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
			mapX--; // moves the coords down
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


	
	
	
	else if (strcmp(movement, "stay") == 0) { // not much point to this rn but i did have events planned that needed you to wait so. its handy

		//cout << xPosition;
		cout << ">> " << name << ": You decide to wait in this room\n" << endl;
		//roomDescription(mapX, mapY);
		mapcheck(mapX, mapY);
		//cout << &mapcheck;
				return;
	}
	else { // room for mistakes :)
		cout << "INVALID OPTION. OPTIONS ARE:" << endl;
		cout << "'up', 'down', 'left', 'right', 'stay'\n" << endl;
		//cout << mapcheck;
	}

	

}

void player::damage(const int& dmg)
{
	int damage = dmg;
	if (damage < 0) cout << name << " gained health!" << endl; // different message for healing, simply putting in a negative dmg value will print this
	else cout << name << " took damage!" << endl;
	health -= damage; // only one of these. health minus a minus simply heals. quickmath
	
	cout << "PLAYER HEALTH: " << health << endl; // damage counter
	
	if (health <= 0) {
		playerAlive = false; // supposed to stop the game but doesnt idk
		cout << name << " has died" << endl; // this works tho.
		gameRunning = false; // also supposed to stop the game but doesnt :*(
		
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


void player::enemyRATS() // ignore the mess 
{
	int rathealth = 50;
	bool alive = true;
	bool player = true;

	char* input;
	input = new char[12];


	cout << "ENEMY HP: " << rathealth << endl;


	while ((alive == true) || (player == true)) {
		
		if (health <= 0) {
			cout << "The [CANCEROUS RAT] eats your corpse." << endl; // rip lil bro

			player = false;


			break;
		}

		cout << ">> The [CANCEROUS RAT] bites you for 10 DAMAGE" << endl; // rat gets first turn cause its just better
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
			inventoryOpen = true; // begin inv. loop

			while (inventoryOpen) {
				inventory(); // inv. loop is closed in here
			}


		}
		if ((strcmp(input, "punch") == 0) && (health > 0)) {
			cout << ">> You punch the [CANCEROUS RAT] for 10 DAMAGE." << endl;
			rathealth = rathealth - 10; // owWW

			
		}
		if ((strcmp(input, "kick") == 0) && (health > 0)) {
			cout << ">> You kick the [CANCEROUS RAT] for 30 DAMAGE." << endl;
			rathealth = rathealth - 30; // YEEEOUCH
			
		}
		if ((strcmp(input, "taunt") == 0) && (health > 0)) {
			cout << ">> You taunt the [CANCEROUS RAT] for 5 DAMAGE." << endl;
			cout << ">> The [CANCEROUS RAT] gets pissed. You take 5 DAMAGE from rat curses." << endl;
			rathealth = rathealth - 5; // owie
			
			damage(5);
		}
		if ((strcmp(input, "magic") == 0) && (health > 0)) {

			//String* MAGIC = new String("fire, ice, water, air");


			char* input;
			input = new char[12];

			cout << ">> You cast: "; cin >> input; cout << endl;
			

			String* choice = new String(input);


			magicUse(input); // spells are fire, air, ice, water

			if (knownMagic == true) {
				cout << "You blast the [CANCEROUS RAT] with " << input << " for " << mana << " damage!!" << endl;
				rathealth = rathealth - mana;
			}

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





