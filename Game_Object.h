#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Cart_Point.h"

class Game_Object
{
protected:
	Cart_Point location;
	int id_num;
	char display_code;
	char state;


public:
	Game_Object(char in_code);

	Game_Object(Cart_Point in_loc, int in_id, char in_code);

	virtual ~Game_Object(); //virtual destructor

	Cart_Point get_location();

	int get_id();

	char get_state();

	virtual void show_status(); //virtual show status

	virtual bool update() = 0; //pure virtual update function

	void drawself(char* ptr);

	virtual bool is_alive();

};

#endif