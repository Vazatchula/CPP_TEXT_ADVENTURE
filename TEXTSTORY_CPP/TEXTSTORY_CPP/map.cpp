#include "map.h"
#include "String.h"
#include <string>
#include <iostream>
#include "PLAYER.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

map::map()
{
	mapcheck(0,0);
} 

map::~map()
{
}

void map::mapcheck(const int x, const int y) {

	if (xPosition > 3) {
		cout << name << ": You try your best, but you can't seem to find a way to go any further" << endl;
		xPosition = 3;
	}
	if (yPosition > 5) {
		cout << name << ": You try your best, but you can't seem to find a way to go any further" << endl;
		xPosition = 5;
	}
}