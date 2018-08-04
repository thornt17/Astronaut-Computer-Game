#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include <iostream>
#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"

using namespace std;

void do_move_command(Model& m1, int id1, double x1, double y1);

void do_work_a_depot_command(Model& m1, int id1, int id2);

void do_deposit_moonstones_command(Model& m1, int id1, int id2);

void do_stop_command(Model& m1, int id1);

void do_lock_in_at_station_command(Model& m1, int id1, int id2);

void do_go_command(Model& m1);

void do_run_command(Model& m1);

void do_attack_command(Model& m1, int id1, int id2);

#endif