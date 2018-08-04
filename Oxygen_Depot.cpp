#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"

using namespace std;

Oxygen_Depot::Oxygen_Depot() : Game_Object('O')
{
	display_code = 'O';
	state = 'f';
	cout << "Oxygen Depot constructed" << endl;
}

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId) : Game_Object(inputLoc, inputId, 'O')
{
	id_num = inputId;
	location = inputLoc;
	amount_oxygen = 50;
}

Oxygen_Depot::~Oxygen_Depot()
{
	cout << "Oxygen_Depot destructed" << endl;
}

bool Oxygen_Depot::isempty()
{
	if (amount_oxygen == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
	if (amount_oxygen >= amount_to_extract)
	{
		amount_oxygen -= amount_to_extract;
		return amount_to_extract;
	}
	else
	{
		amount_oxygen = 0;
		return amount_oxygen;

	}
}

bool Oxygen_Depot::update()
{
	if(amount_oxygen == 0 && state != 'e')
	{
		state = 'e';
		display_code = 'o';
		cout << "Oxygen_Depot" << id_num << " has been depleted" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Oxygen_Depot::show_status()
{
	cout << display_code << id_num << " at location " << location << " contains " << amount_oxygen << " oxygen." << endl;
}





