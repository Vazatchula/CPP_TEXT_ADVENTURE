#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "String.h"
#include "map.h"

class player : public map{

public:
	player(const char* NAME, int HP, int ATTK, int MN);

	~player();

	void move(const String& direction);
	void damage(const int& dmg);
	void inventory();
	char* name;
protected:
	int xPosition = 0;
	int yPosition = 0;

private:
	
	int health;
	int attack;
	int mana;
	bool playerAlive;
	
	//char* playerName;

};

