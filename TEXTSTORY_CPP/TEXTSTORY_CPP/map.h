#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include "PLAYER.h"
class map : public player{
public:
	map();

	~map();

	void mapcheck(const int x, const int y);

	

	

private:
	char* newMap[5][5];
};

