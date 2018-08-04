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
#include "View.h"
#include "Alien.h"
#include "Input_Handling.h"

using namespace std;

//EXTRA CREDIT DONE: STEP 7 CHANGE GRAVITY/SPEED


int main()
{
	Model m; //model object created

	View v; //view object created

	char command, type; //variables for user input initialized
	int id1, id2;
	double x1, y1;

	m.show_status();	

	do //loops while command does not equal q for quit
	{

		m.display(v); //prints the display graph

		cout << "Enter a command ";
		cin >> command;

		try
		{

		switch(command)
		{
			case 'm':
				cin >> id1 >> x1 >> y1;
				
				if(cin.fail())
				{
					throw Invalid_Input("Invalid command parameters");
				}

				do_move_command(m,id1,x1,y1);
				

			break;

			case 'w':
				cin >> id1 >> id2;

				if(cin.fail())
				{
					throw Invalid_Input("Invalid command parameters");
				}
				
				do_work_a_depot_command(m, id1, id2);
				

			break;

			case 'd':

				cin >> id1 >> id2;

				if(cin.fail())
				{
					throw Invalid_Input("Invalid command parameters");
				}

				do_deposit_moonstones_command(m, id1, id2);
				

			break;

			case 's':
				cin >> id1;
				if(cin.fail())
				{
					throw Invalid_Input("Invalid command parameters");
				}

				do_stop_command(m, id1);
				
			break;

			case 'l':
				cin >> id1 >> id2;

				if(cin.fail())
				{
					throw Invalid_Input("Invalid command parameters");
				}

				do_lock_in_at_station_command(m, id1, id2);
				

			break;

			case 'g':

				cout << "Advaning one tick" << endl;
				do_go_command(m);
				m.show_status();

			break;

			case 'r':

				cout << "Advancing to next event" << endl;
				do_run_command(m);
				m.show_status();

			break;

			case 'a':

				cin >> id1 >> id2;

				if(cin.fail())
				{
					throw Invalid_Input("Invalid command parameters");
				}

				do_attack_command(m, id1, id2);
				

			break;

			case 'n':

				cin >> type >> id1 >> x1 >> y1;

				if(cin.fail())
				{
					throw Invalid_Input("Invalid command parameters");
				}
				

				switch(type)
				{
					case 'd':
						m.handle_new_command(type, id1, x1, y1);

					break;

					case 's':
						m.handle_new_command(type, id1, x1, y1);

					break;

					case 'a':
						m.handle_new_command(type, id1, x1, y1);
					break;

					case 'x':
						m.handle_new_command(type, id1, x1, y1);
					break;

					default:
						cin.clear();
						throw Invalid_Input("Invalid type");
					break;
				}

			break;

			case 'q':
			break;

			default:

				cin.clear();
				throw Invalid_Input("Invalid command");

			break;
		}
	}
		catch(Invalid_Input& except)
		{
			cout << "Invalid_Input - " << except.msg_ptr << endl;
			//actions to be taken if the input is wrong
		}


	} while(command != 'q');

	
	return 0;

}

