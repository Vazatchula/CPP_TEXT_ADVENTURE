#include "map.h"
#include "String.h"
#include <string>
#include <iostream>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
bool noWall = true;
extern void enemy(const char* enemy);

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

	char* input;
	input = new char[12];

	if (xpos == 3) cout << "A wall blocks your path to the right." << endl;
	if (ypos == 5) cout << "A wall blocks your path from the front." << endl;
	if (ypos == 0) cout << "A wall blocks your path from the back." << endl;
	if (xpos == 0) cout << "A wall blocks your path to the left." << endl;
	if ((xpos == 1) && (ypos == 3)) {
		sRoom_1();
		return;
	}
	if ((xpos == 2) && (ypos == 1)) {
		sRoom_2();
		return;
	}
	
	cout << "COOL ROOM DESCRIPTION. COOL ROOM DESCRIPTION. COOL ROOM DESCRIPTION.\n\n" << endl;


	cout << "Press any key to continue" << endl;
	cout << ">> "; cin >> input;
}

void map::enemyPLAYER() {
	cout << "-- FIGHT --" << endl;
	enemy("rat");
}

void map::sRoom_1() // silver key room. unlocks room 4
{
	char* input;
	input = new char[12];

	cout << R"(

The trees are denser here. Dark, dangerous. The branches seem to curl in 
towards you. You dont feel safe here. 


>> Go further in? (y/n)
)";

	cout << ">> "; cin >> input; cout << "\n";

	if (strcmp(input, "y") == 0) {
		cout << "You go deeper in. The trees seem about to swallow you whole. \nYou find a silver key on the ground." << endl;
		cout << "\nOBTAINED: SILVER KEY" << endl;
		key = true;
		return;
	} 
	if (strcmp(input, "n") == 0) {
		cout << "You decide to go elsewhere." << endl;
		return;
	} 
}

void map::sRoom_2() // enemy room, [OVERSIZED RATS] 50hp, 20 dmg
{
	char* input;
	input = new char[12];

	cout << R"(

You hear noises deeper in. Growling and snarling. You might find something
good deeper in. Do you dare risk such a task? 


>> Go further in? (y/n)
)";

	cout << ">> "; cin >> input; cout << "\n";

	if (strcmp(input, "y") == 0) {
		cout << "You go deeper in. The growling gets louder. \nYou come across a nest of [CANCEROUS RAT]." << endl;

		cout << R"(
     
                              ____    .-.
                          .-"`    `",( __\_
           .-==:;-._    .'         .-.   \_`'.
         .'      `"-:'-/          (  \} -=a  .)
        /            \/       \,== `-  __..-'`
     '-'              |       |   |  .'\ `;
                       \    _/---'\ (   `"`
                      /.`._ )      \ `;
                      \`-/.'        `"`
                       `"\`-.
                          `"`

>> It is very angry.
)";
		
		enemyPLAYER();
		

		// battle mechanics idk
		// wait yes i do know


		
	} 


	if (strcmp(input, "n") == 0) {
		cout << "You decide to go elsewhere." << endl;
		return;
	} 
	return;
}

void map::sRoom_3()
{
	char* input;
	input = new char[12];

	cout << R"(

The trees are denser here. Dark, dangerous. The branches seem to curl in 
towards you. You dont feel safe here. 


>> Go further in? (y/n)
)";

	cout << ">> "; cin >> input; cout << "\n";

	if (strcmp(input, "y") == 0) {
		cout << "You go deeper in. The trees seem about to swallow you whole. \nYou find a silver key on the ground." << endl;
		cout << "\nOBTAINED: SILVER KEY" << endl;
	} return;
	if (strcmp(input, "n") == 0) {
		cout << "You decide to go elsewhere." << endl;
	} return;
}

void map::sRoom_4()
{
	char* input;
	input = new char[12];

	cout << R"(

The trees are denser here. Dark, dangerous. The branches seem to curl in 
towards you. You dont feel safe here. 


>> Go further in? (y/n)
)";

	cout << ">> "; cin >> input; cout << "\n";

	if (strcmp(input, "y") == 0) {
		cout << "You go deeper in. The trees seem about to swallow you whole. \nYou find a silver key on the ground." << endl;
		cout << "\nOBTAINED: SILVER KEY" << endl;
	} return;
	if (strcmp(input, "n") == 0) {
		cout << "You decide to go elsewhere." << endl;
	} return;
}

void map::sRoom_5()
{
	char* input;
	input = new char[12];

	cout << R"(

The trees are denser here. Dark, dangerous. The branches seem to curl in 
towards you. You dont feel safe here. 


>> Go further in? (y/n)
)";

	cout << ">> "; cin >> input; cout << "\n";

	if (strcmp(input, "y") == 0) {
		cout << "You go deeper in. The trees seem about to swallow you whole. \nYou find a silver key on the ground." << endl;
		cout << "\nOBTAINED: SILVER KEY" << endl;
	} return;
	if (strcmp(input, "n") == 0) {
		cout << "You decide to go elsewhere." << endl;
	} return;
}


