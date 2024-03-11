#include "PLAYER.h"
#include "String.h"
#include "map.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
extern bool gameRunning;


player::player(const char* NAME, int HP, int ATTK, int MN)
{
	name = new char[strlen(NAME)];
	name[0] = '\0';
	strcat(name, NAME);

	//name = NAME.CStr();
	cout << "+++ player constructor: " << name << " +++" << endl;
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

	if (mapcheck(mapX, mapY) == true) {
		if (strcmp(movement, "up") == 0) {
			mapY++;
			//cout << yPosition;
			cout << name << ": You move up to the next room" << endl;
			mapcheck(mapX, mapY);
			//cout << &mapcheck;
			return;
		}
		else if (strcmp(movement, "right") == 0) {
			mapX++;
			mapcheck(mapX, mapY);
			//cout << xPosition;
			cout << name << ": You move right to the next room" << endl;
			//cout << &mapcheck;
			return;
		}
		else if (strcmp(movement, "down") == 0) {
			mapY--;
			//cout << yPosition;
			cout << name << ": You move down to the next room" << endl;
			mapcheck(mapX, mapY);
			//cout << &mapcheck;
			return;
		}
		else if (strcmp(movement, "left") == 0) {
			mapX--;
			//cout << xPosition;
			cout << name << ": You move left to the next room" << endl;
			mapcheck(mapX, mapY);
			//cout << &mapcheck;
			return;
		}
	}
	else if (mapcheck(mapX, mapY) == false) {
		if (strcmp(movement, "down") == 0) {
			mapY--;
			//cout << yPosition;
			cout << name << ": You move down to the next room" << endl;
			mapcheck(mapX, mapY);
			//cout << &mapcheck;
			return;
		}
		else if (strcmp(movement, "left") == 0) {
			mapX--;
			//cout << xPosition;
			cout << name << ": You move left to the next room" << endl;
			mapcheck(mapX, mapY);
			//cout << &mapcheck;
			return;
		}
	}
	else if (strcmp(movement, "stay") == 0) {
		//cout << xPosition;
		cout << name << ": You decide to wait in this room" << endl;
		mapcheck(mapX, mapY);
		//cout << &mapcheck;
				return;
	}
	else {
		cout << "INVALID OPTION. OPTIONS ARE:" << endl;
		cout << "'up', 'down', 'left', 'right', 'stay'" << endl;
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


