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
	xPosition = 0; yPosition = 0;
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
		yPosition++;
		//cout << yPosition;
		cout << name << ": You move up to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "down") == 0) {
		yPosition--;
		//cout << yPosition;
		cout << name << ": You move down to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "left") == 0) {
		xPosition--;
		//cout << xPosition;
		cout << name << ": You move left to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "right") == 0) {
		xPosition++;
		//cout << xPosition;
		cout << name << ": You move right to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "stay") == 0) {
		//cout << xPosition;
		cout << name << ": You decide to wait in this room" << endl;
		return;
	}
	else cout << "INVALID OPTION" << endl;

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


