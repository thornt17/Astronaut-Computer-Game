#ifndef ALIEN_H
#define ALIEN_H

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

class Alien : public Game_Object
{
private:
	int attack_strength;
	double range;
	Person * target;
	Cart_Point destination;
	Cart_Vector delta;

protected:
	bool update_location();

	void setup_destination(Cart_Point dest);

public:
	Alien();

	Alien(int in_id, Cart_Point in_loc);

	~Alien();

	double speed; //made public to change gravity

	void start_attack(Person * in_target);

	bool update();

	void show_status();

	void start_moving(Cart_Point dest);

	void stop();

};

#endif