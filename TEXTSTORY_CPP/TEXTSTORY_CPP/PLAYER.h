#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "String.h"

class player{

public:
	player(int HP, int ATTK, int MN);

	~player();

	void move(const String& direction);
	void damage(const int& dmg);
	

private:
	int xPosition;
	int yPosition;
	int health;
	int attack;
	int mana;
	bool playerAlive;


};

