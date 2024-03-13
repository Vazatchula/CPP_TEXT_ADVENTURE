#include "map.h"
#include "String.h"
#include <string>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
bool noWall = true;

map::map()
{
	mapcheck(0,0);
} 

map::~map()
{
}

void map::mapcheck(int xposition, int yposition) {

	cout << "---MAPCHECK---" << endl;
	cout << "Position is: x " << xposition << ", y " << yposition << endl;

	mapX = xposition;
	mapY = yposition;
	
	xLimit = false;
	yLimit = false;

	if ((mapX >= 3) && (mapY != 5)) {
		cout << "MAX X MOVEMENT 3: " << mapX << endl;
		mapY == 4;
		if ((mapX >= 3) && (mapY != 5)) xLimit = true;
		
	} else if ((mapY >= 5) && (mapX != 3)) {
		cout << "MAX Y MOVEMENT 5: " << mapY << endl;
		mapY == 4;
		if ((mapY >= 5) && (mapX != 3)) yLimit = true;

	}else if ((mapY >= 5) && (mapX >= 3)) {

		cout << "MAX X MOVEMENT 3: " << mapX << endl;
		cout << "MAX Y MOVEMENT 5: " << mapY << endl;
		xLimit = true;
		yLimit = true;

	} return;

	cout << "\n";

	return;

	
	
	
}

void map::roomDescription(int xpos, int ypos) {

	cout << "COOL ROOM DESCRIPTION. COOL ROOM DESCRIPTION. COOL ROOM DESCRIPTION.\n\n" << endl;
}