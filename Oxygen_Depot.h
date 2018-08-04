#ifndef OXYGENDEPOT_H
#define OXYGENDEPOT_H

#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Oxygen_Depot : public Game_Object
{
private:
	double amount_oxygen;

public:
	Oxygen_Depot();

	Oxygen_Depot(Cart_Point inputLoc, int inputId);

	~Oxygen_Depot();

	bool isempty();

	double extract_oxygen(double amount_to_extract = 20);

	bool update();

	void show_status();
};

#endif