#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"

using namespace std;

class Person : public Game_Object
{
private:
	Cart_Point destination;
	Cart_Vector delta;

protected:
	bool update_location();

	void setup_destination(Cart_Point dest);

	int health;

public:
	Person();

	Person(char in_code);

	double speed; //made public to change gravity

	virtual ~Person();

	Person(Cart_Point in_loc, int in_id, char in_code);

	void start_moving(Cart_Point dest);

	void stop();

	void show_status();

//all three functions are virtual to be used in astronaut
	virtual void start_supplying(Oxygen_Depot* inputDepot);

	virtual void start_depositing(Space_Station* inputStation);

	virtual void go_to_station(Space_Station* inputStation);

	bool is_alive();

	void take_hit(int atttack_strength);

};

#endif












