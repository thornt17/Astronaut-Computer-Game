#ifndef SPACESTATION_H
#define SPACESTATION_H

#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Space_Station : public Game_Object
{
private:
	double amount_moonstones;

	int number_astronauts;

public:
	Space_Station();

	Space_Station(Cart_Point inputLoc, int inputId);

	~Space_Station();

	void deposit_moonstones(double deposit_amount);

	bool add_astronaut();

	int get_astronauts();

	bool update();

	void show_status();
};

#endif