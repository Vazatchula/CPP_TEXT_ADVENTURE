#include "PLAYER.h"
#include "String.h"

#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
extern bool gameRunning;

player::player(int HP, int ATTK, int MN)
{
	cout << "+++ player constructor +++" << endl;
	health = HP;
	attack = ATTK;
	mana = MN;
	xPosition = 0; yPosition = 0;
	playerAlive = true;
	cout << "HEALTH: " << health << endl;
	cout << "ATTACK: " << attack << endl;
	cout << "MANA: " << mana << endl;
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
		cout << "You move up to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "down") == 0) {
		yPosition--;
		//cout << yPosition;
		cout << "You move down to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "left") == 0) {
		xPosition--;
		//cout << xPosition;
		cout << "You move left to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "right") == 0) {
		xPosition++;
		//cout << xPosition;
		cout << "You move right to the next room" << endl;
		return;
	}
	else if (strcmp(movement, "stay") == 0) {
		//cout << xPosition;
		cout << "You decide to wait in this room" << endl;
		return;
	}
	else cout << "INVALID OPTION" << endl;
}

void player::damage(const int& dmg)
{
	int damage = dmg;
	health -= damage;
	cout << "PLAYER HEALTH: " << health << endl;
	
	if ((health == 0) || (health < 0)) {
		playerAlive = false;
		cout << "YOU HAVE DIED." << endl;
		gameRunning = false;
	}
	return;

}


