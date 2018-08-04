#include <iostream>
#include "Game_Object.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Astronaut.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

Astronaut::Astronaut() : Person('A')
{
	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	health = 5;
	cout << "Astronaut default constructed" << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc) : Person(in_loc, in_id, 'A')
{

	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	health = 5;
	cout << "Astronaut constructed" << endl;
}

Astronaut::~Astronaut()
{
	cout << "Astronaut destructed" << endl;
}

bool Astronaut::update()
{
	bool bl1, bl2, bl3, bl4, bl5;
	double myamount;

	if (health <= 3)
	{
		display_code = 'a';
	}

	if (amount_oxygen == 0) // checks if amount oxygen is zero
	{
		state = 'x';
		show_status();
		return true;
	}

	switch(state) //updates for each case, if state changes true is returned
	{
		case 's':
			return false;
			break;

		case 'm':
			bl1 = update_location();
			if (bl1 == true)
			{
				state = 's';
				return true;
			}
			else
			{
				amount_oxygen--;
				amount_moonstones++;
				return false;
			}
			break;

		case 'o':
			bl2 = update_location();
			if(bl2 == true)
			{
				state = 'g';
				return true;
			}
			else
			{
				amount_oxygen--;
				amount_moonstones++;
				return false;
			}
			break;

		case 'g':
			myamount = depot -> extract_oxygen(20);
			cout << display_code << id_num << ": Got " << myamount << " oxygen" << endl;
			state = 's';
			return true;
			break;

		case 'i':
			bl3 = update_location();
			if(bl3 == true)
			{
				state = 'd';
				return true;
			}
			else
			{
				amount_oxygen--;
				amount_moonstones++;
				return false;
			}
			break;

		case 'd':
			cout << display_code << id_num << ": Deposit " << amount_moonstones << " of moonstones" << endl;
			home -> deposit_moonstones(amount_moonstones);
			amount_moonstones = 0;
			state = 's';
			return true;
			break;

		case 'l':
			bl4 = update_location();
			if (bl4 == true)
			{
				bl5 = home -> add_astronaut();
				return true;
			}
			else
			{
				amount_oxygen--;
				amount_moonstones++;
				return false;
			}
			break;
		case 'x':
			return false;
			break;

		default:
			return false;
			break;

	}
}

void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
	if (state == 'x')
	{
		cout << "Astronaut " << id_num << " is dead" << endl;
		return;
	}

	setup_destination(inputDepot -> get_location());
	int myid = inputDepot -> get_id();
	state = 'o';
	cout << "Astronaut " << id_num << " supplying at Oxygen_Depot " << myid << "." << endl;
	cout << display_code << id_num << " Yes, my lord." << endl;
	depot = inputDepot;
}

void Astronaut::start_depositing(Space_Station* inputStation)
{
	if (state == 'x')
	{
		cout << "Astronaut " << id_num << " is dead" << endl;
		return;
	}

	setup_destination(inputStation -> get_location());
	state = 'i';
	cout << "Astronaut " << id_num << " deposting to Space_Station " << inputStation -> get_id() << "." << endl;
	cout << display_code << id_num << " Yes, my lord." << endl;
	home = inputStation;
}

void Astronaut::go_to_station(Space_Station* inputStation)
{
	if (state == 'x')
	{
		cout << "Astronaut " << id_num << " is dead" << endl;
		return;
	}

	cout << "Astronaut" << id_num << " locking in at Space_Station" << inputStation -> get_id() << "." << endl;
	setup_destination(inputStation -> get_location());
	home = inputStation;
}

void Astronaut::show_status()
{
	cout << "Astronaut status: "; //shows status for each case
	Person::show_status();
	switch(state)
	{
		case 's':
			cout << "Stopped with " << amount_oxygen << " oxygen and " << amount_moonstones << " moonstones." << endl;
			break;

		case 'm':
			cout << endl;
			break;

		case 'o':
			cout << "is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
			break;

		case 'g':
			cout << "Getting Oxygen from Depot" << endl;
			break;

		case 'i':
			cout << " is inbound to home with load: " << amount_moonstones << " moonstones and " << amount_oxygen << " oxygen." << endl;
			break;

		case 'd':
			cout << "Depositing " << amount_moonstones << " moon stones." << endl;
			break;

		case 'l':
			if (amount_oxygen == 0)
			{
				cout << "Out of oxygen" << endl;
			}
			else
			{
				cout << " is locked at Space Station" << endl;
			}
			break;

	}
}




