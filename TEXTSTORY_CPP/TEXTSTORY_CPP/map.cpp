#include "map.h"
#include "String.h"
#include <string>
#include <iostream>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
bool noWall = true;
extern void enemy(const char* enemy);
extern bool gameRunning;

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
	if ((xpos == 3) && (ypos == 5)) {
		sRoom_3();
		return;
	}

	srand(time(NULL));

	int shuffle;
	shuffle = rand() % 3;

	switch (shuffle) {
	case 1:
		cout << "Trees surround you. There doesnt seem to be anything interesting here.\nAsides from a dense fog, perhaps.\n\n" << endl;
		break;

	case 2:
		cout << "More trees. There is still nothing interesting in this area.\nMaybe check somewhere else?\n\n" << endl;
		break;
	case 3:
		cout << "A scream echoes into the distance. You dont know what it is. You dont\nintend to go looking for an explanation.\n\n" << endl;
		break;
	default:
		cout << "Trees. So many trees.\n\n" << endl;
	}
	
	


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

You are in a corner. The trees are thick enough to almost form a wall 
blocking you from going any further. You follow this wall for a few metres
before coming across a door.

Maybe if you had a key... 


)";
	if (key == true) {
		cout << "Use [SILVER KEY]? (y/n)" << endl;
		cout << ">> "; cin >> input; cout << "\n";

		if (strcmp(input, "y") == 0) {
			cout << "You use the [SILVER KEY] on the door.\nIt opens with a slow groan, filling the room with light." << endl;
			cout << "Do you enter? (y/n)" << endl;
			cout << ">> "; cin >> input; cout << "\n";
			if (strcmp(input, "y") == 0) {
				cout << "You enter the light. The trees can trap you no longer." << endl;
				cout << R"(

                     .___   
    ____   ____    __| _/   
  _/ __ \ /    \  / __ |    
  \  ___/|   |  \/ /_/ |    
   \___  >___|  /\____ | /\ 
       \/     \/      \/ \/ 
  

)";
				cout << "Press 'q' to exit the game." << endl;
				cout << ">> "; cin >> input; cout << "\n";
				if (strcmp(input, "q") == 0) {
					gameRunning = false;
					
				}
			}
			if (strcmp(input, "n") == 0) {
				cout << "You chicken out." << endl;
				return;
			}


			
		} return;
		if (strcmp(input, "n") == 0) {
			cout << "You decide to go elsewhere." << endl;
		} return;
	}
	
	else {
		cout << "Press any key to continue" << endl;
		cout << ">> "; cin >> input;
	}

	
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


