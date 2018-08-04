#ifndef MODEL_H
#define MODEL_H


#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "View.h"
#include "Alien.h"
#include <list>

using namespace std;

class Model
{
private:
	int mytime;
	int count_down;
	list<Game_Object*> object_ptrs;
	list<Game_Object*> active_ptrs;
	list<Person*> person_ptrs;
	list<Oxygen_Depot*> depot_ptrs;
	list<Space_Station*> station_ptrs;
	list<Alien*> alien_ptrs;
	int alive_astronauts; //number of living astronauts

public:
	Model();

	~Model();

	Person * get_Person_ptr(int id);

	Oxygen_Depot * get_Oxygen_Depot_ptr(int id);

	Space_Station * get_Space_Station_ptr(int id);

	Alien * get_Alien_ptr(int id);

	bool update();

	void display(View &view);

	void show_status();

	void handle_new_command(char type, int id1, double x1, double y1);
};

#endif