#pragma once
#include <string>
#include "String.h"

class player{

public:
	player(int HP, int ATTK, int MN);

	~player();

	void move(const String& direction);
	void damage(String& dmg);
	bool alive();




};

