#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Space_Station.h"

using namespace std;

Space_Station::Space_Station() : Game_Object('s')
{
	display_code = 's';
	state = 'o';
	amount_moonstones = 0;
	number_astronauts = 0;
	cout << "Space_Station default constructed" << endl;
}

Space_Station::Space_Station(Cart_Point inputLoc, int inputId) : Game_Object(inputLoc, inputId, 's')
{
	id_num = inputId;
	location = inputLoc;
	cout << "Space_Station constructed" << endl;
	amount_moonstones = 0;
	number_astronauts = 0;
}

Space_Station::~Space_Station()
{
	cout << "Space_Station destructed" << endl;
}

void Space_Station::deposit_moonstones(double deposit_amount)
{
	amount_moonstones = amount_moonstones + deposit_amount;
}

bool Space_Station::add_astronaut()
{
	if (state == 'u')
	{
		number_astronauts++;
		return true;
	}
	else
	{
		return false;
	}
}

int Space_Station::get_astronauts()
{
	return number_astronauts;
}

bool Space_Station::update()
{
	if (amount_moonstones >= 10 && state != 'u')
	{
		state = 'u';
		display_code = 'S';
		cout << display_code << id_num << " has been upgraded" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Space_Station::show_status()
{
	Game_Object::show_status();
	if (state == 'u')
	{
		cout << "Space_Station has been upgraded" << endl;
	}
	else
	{
		cout << "Space_Station has not been upgraded" << endl;
	}
	cout << "Space_Station contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts" << endl;
}





