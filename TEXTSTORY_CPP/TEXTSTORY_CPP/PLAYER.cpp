#include "PLAYER.h"
#include "String.h"
#include "String.cpp"
#include <iostream>
using namespace std;

player::player(int HP, int ATTK, int MN)
{
	cout << "+++ player constructor +++" << endl;
	int health = HP;
	int attack = ATTK;
	int mana = MN;
	int x = 0; int y = 0;
	cout << "HEALTH: " << health << endl;
	cout << "ATTACK: " << attack << endl;
	cout << "MANA: " << mana << endl;
}

player::~player()
{
	delete
}

void player::move(const String& direction)
{
	string command;
	command.ReadFromConsole(); // waits for input from console.

	if (command.ToLower().Equals("move south") == true)
	{
		// TODO: Process Move South Command
	}
}

void player::damage(String& dmg)
{

}

bool player::alive()
{
	return false;
}
