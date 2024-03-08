#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "String.h"

class player{

public:
	player(const char* NAME, int HP, int ATTK, int MN);

	~player();

	void move(const String& direction);
	void damage(const int& dmg);
	char* name;
protected:
	int xPosition;
	int yPosition;

private:
	
	int health;
	int attack;
	int mana;
	bool playerAlive;
	
	//char* playerName;

};

