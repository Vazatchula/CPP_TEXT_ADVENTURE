#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

class map {
public:
	map();

	~map();
		
	int mapX = 0;
	int mapY = 0;
	int mapGlobalPos = 0;

	void mapcheck(int pxosition, int yposition);
	void roomDescription(int xpos, int ypos);
		
	bool xLimit;
	bool yLimit;
		
	
	

private:
	char* newMap[5][5];

};

