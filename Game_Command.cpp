#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Model.h"
#include "Person.h"
#include "Astronaut.h"
#include "Game_Command.h"
#include "Alien.h"

using namespace std;

void do_move_command(Model& m1, int id1, double x1, double y1) //calls start_moving
{
	char type;
	do
	{
	cout << "Are you moving an astronaut (a) or alien (x)?";
	cin >> type;
	}while (type != 'a' && type != 'x');
	
	if (type == 'a')
	{
		Person* ptr1 = m1.get_Person_ptr(id1);
		Cart_Point cp(x1,y1);
		ptr1 -> start_moving(cp);
	}
	else
	{
		Alien* ptr1 = m1.get_Alien_ptr(id1);
		Cart_Point cp(x1,y1);
		ptr1 -> start_moving(cp);
	}


	cout << "moving " << id1 << " to (" << x1 << "," << y1 << ")" << endl;
}

void do_work_a_depot_command(Model& m1, int id1, int id2) //calls start_supplying
{


	Person* ptr1 = m1.get_Person_ptr(id1);
	Oxygen_Depot* ptr2 = m1.get_Oxygen_Depot_ptr(id2);

	ptr1 -> start_supplying(ptr2);

}

void do_deposit_moonstones_command(Model& m1, int id1, int id2) //calls start_deposting
{
	Person* ptr1 = m1.get_Person_ptr(id1);
	Space_Station* ptr2 = m1.get_Space_Station_ptr(id2);

	ptr1 -> start_depositing(ptr2);

}

void do_stop_command(Model& m1, int id1) //calls stop
{
	char type;
	do
	{
	cout << "Are you moving an astronaut (a) or alien (x)? ";
	cin >> type;
	}while (type != 'x' && type != 'a');
	
	if (type == 'a')
	{
		Person* ptr1 = m1.get_Person_ptr(id1);
		ptr1 -> stop();
	}
	else
	{
		Alien* ptr1 = m1.get_Alien_ptr(id1);
		ptr1 -> stop();
	}


	cout << "stopping " << id1 << endl;
}

void do_lock_in_at_station_command(Model& m1, int id1, int id2) //calls go_to_station
{
	Person* ptr1 = m1.get_Person_ptr(id1);
	Space_Station* ptr2 = m1.get_Space_Station_ptr(id2);

	ptr1 -> go_to_station(ptr2);

	cout << "locking " << id1 << " to station " << id2 << endl;
}

void do_go_command(Model& m1) //advances on tick, calls update
{
	bool bl1 = m1.update();
}

void do_run_command(Model& m1) // calls update, advances 5 ticks or until update returns true aka next event
{
	bool bl1;
	for (int i = 0; i < 5; i++)
	{
		bl1 = m1.update();
		if (bl1 == true)
		{
			return;
		}
	}
}

void do_attack_command(Model& m1, int id1, int id2)
{
	Alien * ptr1 = m1.get_Alien_ptr(id1);
	Person * ptr2 = m1.get_Person_ptr(id2);

	cout << id1 << " attacking " << id2 << endl;

	ptr1 -> start_attack(ptr2);

}


