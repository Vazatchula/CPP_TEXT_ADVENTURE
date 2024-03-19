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
	void enemyPLAYER();
	
	void sRoom_1();
	void sRoom_2();
	void sRoom_3();
	void sRoom_4();
	void sRoom_5();

	bool key = false;
	bool keyactivate = false;
	bool toast = false;
	bool toastactivate = false;
	bool donuts = false;
	bool donutsactivate = false;

		
	bool xLimit;
	bool yLimit;
		
	
	

private:
	char* newMap[5][5];

};

