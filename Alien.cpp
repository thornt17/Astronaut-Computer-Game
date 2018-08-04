#include <iostream>
#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Alien.h"
#include <math.h>

using namespace std;

Alien::Alien() : Game_Object('X')
{
	attack_strength = 2;
	range = 2.0;
	target = NULL;
	speed = 5;
	cout << "Alien default constructed" << endl;
}

Alien::Alien(int in_id, Cart_Point in_loc) : Game_Object(in_loc,in_id,'X')
{
	attack_strength = 2;
	range = 2.0;
	target = NULL;
	speed = 5;
	cout << "Alien constructed" << endl;
}

Alien::~Alien()
{
	cout << "Alien destructed" << endl;
}

void Alien::start_attack(Person * in_target)
{
	if (cart_distance(location, in_target -> get_location()) <= range)
	{
		cout << "Smash!" << endl;
		target = in_target;
		state = 'a';
	}
	else
	{
		cout << "Target is out of range" << endl;
	}
}

bool Alien::update()
{
	switch(state)
	{
		bool bl1;

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
				return false;
			}
			break;

		case 'a':
			if (cart_distance(location, target -> get_location()) > range)
			{
				cout << "Out of range" << endl;
				state = 's';
				return true;
			}
			else
			{
				if (target -> is_alive() == true)
				{
					cout << "Destroy!" << endl;
					target -> take_hit(attack_strength);
					return false;
				}
				else
				{
					cout << "I triumph!" << endl;
					state = 's';
					return true;
				}
			}

		default:
			return false;
			break;

	}
}

void Alien::show_status()
{
	cout << "Alien status";
	
	Game_Object::show_status();

	if (state == 'a')
	{
		cout << "is attacking" << endl;
	}
	else if (state == 's')
	{
		cout << "is stopped " << endl;
	}
	else
	{
		cout << "Moving at speed " << speed << " to " << destination << " amounts on each step are " << delta << "." << endl;
	}
}

void Alien::start_moving(Cart_Point dest)
{
	setup_destination(dest);
	state = 'm';
	cout << "Moving " << display_code << id_num << " to " << dest << endl;
	cout << display_code << id_num << ": On my way" << endl;
}

void Alien::stop()
{
	state = 's';
	cout << "Stopping " << id_num << endl;
	cout << display_code << id_num << ": All right." << endl;
}

bool Alien::update_location()
{
	if (location.x == destination.x && location.y == destination.y) //prevents seg fault if you try to move to same location in main.cpp
	{
		cout << "I'm already there!" << endl;
		return true;
	}
	if( fabs(destination.x - location.x) <= fabs(delta.x) || fabs(destination.y - location.y) <= fabs(delta.y)) //checks if step is smaller than delta
	{
		location = destination;
		cout << display_code << id_num << ": There" << endl;
		return true;
	}
	else
	{
		location = location + delta;
		cout << display_code << id_num << ": step..." << endl;
		return false;
	}
}

void Alien::setup_destination(Cart_Point dest)
{
	destination = dest;
	delta = (destination - location) * (speed / cart_distance(destination, location));
}




