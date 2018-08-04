#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include <math.h>

using namespace std;

Person::Person() : Game_Object('p')
{
	speed = 5.0;
	cout << "Person default constructed" << endl;
	Cart_Point destination;
	health = 5;

}

Person::Person(char in_code) : Game_Object(in_code)
{
	display_code = in_code;
	speed = 5.0;
	state = 's';
	health = 5;
	cout << "Person constructed" << endl;
	Cart_Point destination;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code) : Game_Object(in_loc,in_id,in_code)
{
	speed = 5;
	cout << "Person constructed" << endl;
	Cart_Point destination;
}

Person::~Person()
{
	cout << "Person destructed" << endl;
}

void Person::start_moving(Cart_Point dest)
{
	if (state == 'x')
	{
		cout << "Astronaut " << id_num << " is dead" << endl;
		return;
	}
	setup_destination(dest);
	state = 'm';
	cout << "Moving " << display_code << id_num << " to " << dest << endl;
	cout << display_code << id_num << ": On my way" << endl;
}

void Person::stop()
{
	if (state == 'x')
	{
		cout << "Astronaut " << id_num << " is dead" << endl;
		return;
	}
	state = 's';
	cout << "Stopping " << id_num << endl;
	cout << display_code << id_num << ": All right." << endl;
}

void Person::show_status()
{
	Game_Object::show_status();

	if(state == 'x')
	{
		cout << " is dead " << endl;
	}
	else
	{
		if (state == 'l')
		{
			cout << "is locked" << endl;
		}
		else if (state == 's')
		{
			cout << "is stopped " << endl;
		}
		else
		{
			cout << "Moving at speed " << speed << " to " << destination << " amounts on each step are " << delta << "." << endl;
		}
		cout << "Health is " << health << endl;
	}
}

bool Person::update_location()
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

void Person::setup_destination(Cart_Point dest)
{
	destination = dest;
	delta = (destination - location) * (speed / cart_distance(destination, location));
}

void Person::start_supplying(Oxygen_Depot* inputDepot)
{
	cout << "Sorry, I can't work a depot" << endl;
}

void Person::start_depositing(Space_Station* inputStation)
{
	cout << "Sorry, I can't work a station" << endl;
}

void Person::go_to_station(Space_Station* inputStation)
{
	cout << "Sorry, I can't lock into a station" << endl;
}

bool Person::is_alive()
{
	if (state == 'x')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Person::take_hit(int atttack_strength)
{
	health = health - atttack_strength;
	if (health <= 0)
	{
		cout << "Gasp!" << endl;
		state = 'x';
	}
	else
	{
		cout << "Ouch!" << endl;
	}
}







