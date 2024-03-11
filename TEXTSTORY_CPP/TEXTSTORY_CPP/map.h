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

	bool mapcheck(int position);
		
	
		

	

private:
	char* newMap[5][5];

};

