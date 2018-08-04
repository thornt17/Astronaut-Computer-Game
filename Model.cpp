#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include <stdio.h>
#include <stdlib.h>
#include "View.h"
#include "Model.h"
#include "Input_Handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

Model::Model()
{
	mytime = 0;
	count_down = 10;

	Cart_Point cp(5,1);

	//all objects created on the heap

	Person *ptr1 = new Astronaut(1, cp);
	object_ptrs.push_back(ptr1);
	active_ptrs.push_back(ptr1);
	person_ptrs.push_back(ptr1);
	cp.x = 10;
	cp.y = 1;
	Person *ptr2 = new Astronaut(2, cp);
	object_ptrs.push_back(ptr2);
	active_ptrs.push_back(ptr2);
	person_ptrs.push_back(ptr2);

	cp.x = 1;
	cp.y = 20;
	Oxygen_Depot *ptr3 = new Oxygen_Depot(cp,1);
	object_ptrs.push_back(ptr3);
	active_ptrs.push_back(ptr3);
	depot_ptrs.push_back(ptr3);
	cp.x = 10;
	cp.y = 20;
	Oxygen_Depot *ptr4 = new Oxygen_Depot(cp,2);
	object_ptrs.push_back(ptr4);
	active_ptrs.push_back(ptr4);
	depot_ptrs.push_back(ptr4);

	cp.x = 0;
	cp.y = 0;
	Space_Station *ptr5 = new Space_Station();
	object_ptrs.push_back(ptr5);
	active_ptrs.push_back(ptr5);
	station_ptrs.push_back(ptr5);
	cp.x = 5;
	cp.y = 5;
	Space_Station *ptr6 = new Space_Station(cp,2);
	object_ptrs.push_back(ptr6);
	active_ptrs.push_back(ptr6);
	station_ptrs.push_back(ptr6);

	cp.x = 7;
	cp.y = 14;
	Alien * ptr7 = new Alien(1, cp);
	alien_ptrs.push_back(ptr7);
	active_ptrs.push_back(ptr7);
	object_ptrs.push_back(ptr7);
	cp.x = 7;
	cp.y = 5;
	Alien * ptr8 = new Alien(2, cp);
	alien_ptrs.push_back(ptr8);
	active_ptrs.push_back(ptr8);
	object_ptrs.push_back(ptr8);

	alive_astronauts = 2; //both astronauts are alive at the start

	cout << "Model default constructed" << endl;
}

Model::~Model()
{
	//all objects deleted from the heap

	for(list<Game_Object *>::iterator it = object_ptrs.begin(); it!= object_ptrs.end(); ++it)
	{
		delete *it;
	}

	cout << "Model destructed" << endl;
}

Person * Model::get_Person_ptr(int id)
{
	for(list<Person *>::iterator it = person_ptrs.begin(); it!= person_ptrs.end(); ++it)
	{
		if ((*it) -> get_id() == id)
		{
			return *it;
		}
	}
	return 0;
}

Oxygen_Depot * Model::get_Oxygen_Depot_ptr(int id)
{
	for(list<Oxygen_Depot *>::iterator it = depot_ptrs.begin(); it!= depot_ptrs.end(); ++it)
	{
		if ((*it) -> get_id() == id)
		{
			return *it;
		}
	}
	return 0;
}

Space_Station * Model::get_Space_Station_ptr(int id)
{
	for(list<Space_Station *>::iterator it = station_ptrs.begin(); it!= station_ptrs.end(); ++it)
	{
		if ((*it) -> get_id() == id)
		{
			return *it;
		}
	}
	return 0;
}

Alien * Model::get_Alien_ptr(int id)
{
	for(list<Alien *>::iterator it = alien_ptrs.begin(); it!= alien_ptrs.end(); ++it)
	{
		if ((*it) -> get_id() == id)
		{
			return *it;
		}
	}
	return 0;
}

bool Model::update()
{
	int count = 0; //stores amount of stations upgraded
	int count2 = 0; //stores amount of astronauts locked
	int count3 = 0; //stores amount of stations with at least 1 astronaut
	int count4 = 0; //stores number of dead astronauts
	int count5 = 0; //for indexing in a loop
	int count6 = 0; //for indexing in a loop
	double myspeed; //speed changing with gravity
	mytime++;
	bool bls[active_ptrs.size()]; //creates arrays of bools for calling update functions on the pointers
	alive_astronauts = 0; //resets so it can be recounted in the function

	for(list<Space_Station *>::iterator it = station_ptrs.begin(); it!= station_ptrs.end(); ++it) //adds to a count1 if station is upgraded, adds to count3 if there is more than one astronaut
	{
		if((*it) -> get_state() == 'u')
		{
			count++;
		}
		if((*it) -> get_astronauts() >= 1)
		{
			count3++;
		}
	}

	for(list<Person *>::iterator it = person_ptrs.begin(); it!= person_ptrs.end(); ++it) //adds to count to if astronaut is locked
	{
		if ((*it) -> get_state() == 'l')
		{
			count2++;
		}
		if((*it) -> is_alive() == true) // finds the number of alive astroanuts
		{
			alive_astronauts++;
		}
		else
		{
			count4++;
		}
	}


	//These three for loops store the return values of the update function for each pointer type
	for(list<Game_Object *>::iterator it = active_ptrs.begin(); it!= active_ptrs.end(); ++it)
	{
		if((*it) -> get_state() == 'x')
		{
			active_ptrs.erase(it);
			cout << "Dead Object Removed";
		}
		else
		{
			bls[count5] = (*it) -> update();
		}
		count5++;
	}
	
	//countdown is decremented if all stations are upgraded and there is not at least one astronaut at each station
	if(count == station_ptrs.size() && count3 != station_ptrs.size())
	{
		count_down--;
	}

	if(count4 == person_ptrs.size())
	{
		exit(0);
	}

	if (count_down == 0) //program exits if countdown = 0
	{
		exit(0);
	}
	
	if (count2 == person_ptrs.size() && count != station_ptrs.size()) //program exits if all astronauts are locked and not at stations, aka out of oxygen
	{
		exit(0);
	}

	//THIS IS WHERE GRAVITY CHANGES, DEPENDING ON A RANDOM NUMBER SPEED CAN BE 4, 5, OR 6
	srand(time(NULL));
	int mynum = rand() % 3;
	if (mynum == 0)
	{
		cout << "Gravity does not change the speed" << endl;
	}
	else if(mynum == 1)
	{
		for(list<Person *>::iterator it = person_ptrs.begin(); it!= person_ptrs.end(); ++it)
		{
			(*it) -> speed = 6;
		}
		for(list<Alien *>::iterator it = alien_ptrs.begin(); it!= alien_ptrs.end(); ++it)
		{
			(*it) -> speed = 6;
			myspeed = (*it) -> speed;
		}
		cout << "Gravity changes speed to " << myspeed << endl;
	}
	else if(mynum == 2)
	{
		for(list<Person *>::iterator it = person_ptrs.begin(); it!= person_ptrs.end(); ++it)
		{
			(*it) -> speed = 4;
		}
		for(list<Alien *>::iterator it = alien_ptrs.begin(); it!= alien_ptrs.end(); ++it)
		{
			(*it) -> speed = 4;
			myspeed = (*it) -> speed;
		}
		cout << "Gravity changes speed to " << myspeed << endl;
	}


// These three for loops check if any update functions return true, if so the Model::update() function returns true
	for(list<Game_Object *>::iterator it = active_ptrs.begin(); it!= active_ptrs.end(); ++it)
	{
		if(bls[count6] == true)
		{
			return true;
		}
		count6++;
	}
	return false;
}

void Model::display(View &view) //displays the time and graph
{
	cout << "Time: " << mytime << endl;
	view.clear();

		for(list<Game_Object *>::iterator it = active_ptrs.begin(); it!= active_ptrs.end(); ++it)
		{
			view.plot(*it);
		}

		view.draw();
}

void Model::show_status() //shows status for each pointer in object_ptrs
{
	for(list<Game_Object *>::iterator it = object_ptrs.begin(); it!= object_ptrs.end(); ++it)
	{
		(*it) -> show_status();
	}
}

void Model::handle_new_command(char type, int id1, double x1, double y1)
{
	Oxygen_Depot * ptr9;
	Space_Station * ptr10;
	Person * ptr11;
	Alien * ptr12;
	Cart_Point cp;

	switch(type)
	{
		case 'd':
			if(get_Oxygen_Depot_ptr(id1) != 0)
			{
				throw Invalid_Input("Object already exists");
				return;
			}
			cp.x = x1;
			cp.y = y1;
			ptr9 = new Oxygen_Depot(cp, id1);
			object_ptrs.push_back(ptr9);
			active_ptrs.push_back(ptr9);
			depot_ptrs.push_back(ptr9);

		break;

		case 's':
			if(get_Space_Station_ptr(id1) != 0)
			{
				throw Invalid_Input("Object already exists");
				return;
			}
			cp.x = x1;
			cp.y = y1;
			ptr10 = new Space_Station(cp, id1);
			object_ptrs.push_back(ptr10);
			active_ptrs.push_back(ptr10);
			station_ptrs.push_back(ptr10);

		break;

		case 'a':
			if(get_Person_ptr(id1) != 0)
			{
				throw Invalid_Input("Object already exists");
				return;
			}
			cp.x = x1;
			cp.y = y1;
			ptr11 = new Astronaut(id1, cp);
			object_ptrs.push_back(ptr11);
			active_ptrs.push_back(ptr11);
			person_ptrs.push_back(ptr11);

		break;
		case 'x':
			if(get_Alien_ptr(id1) != 0)
			{
				throw Invalid_Input("Object already exists");
				return;
			}
			cp.x = x1;
			cp.y = y1;
			ptr12 = new Alien(id1, cp);
			object_ptrs.push_back(ptr12);
			active_ptrs.push_back(ptr12);
			alien_ptrs.push_back(ptr12);

		break;

		default:

			throw Invalid_Input("Invalid Object type");

		break;
	}
}






