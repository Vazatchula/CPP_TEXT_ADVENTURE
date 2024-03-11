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

bool map::mapcheck(int position) {

	cout << "---MAPCHECK---" << endl;
	//cout << "Position is: x " << x << ", y " << y << endl;

	mapGlobalPos = position;
	



	/*if ((mapX >= 3) && (mapY != 5)) {
		cout << "MAX X MOVEMENT 3: " << mapX << endl;
		mapY == 4;
		return false;
	} else if ((mapY >= 5) && (mapX != 3)) {
		cout << "MAX Y MOVEMENT 5: " << mapY << endl;
		mapY == 4;
		return false;
	} else if ((mapX >= 3) && (mapY >= 5)) {
		cout << "MAX X AND Y MOVEMENT REACHED. GO BACK. " << mapX << endl;
		mapX == 2;
		mapY == 4;
		return false;
	}
	*/
	else return true;

	
	
	
}