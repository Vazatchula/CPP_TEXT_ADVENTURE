#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "String.h"

class player{

public:
	player(int HP, int ATTK, int MN);

	~player();

	void move(const String& direction);
	void damage(String& dmg);
	bool alive();

private:
	int xPosition;
	int yPosition;


};

