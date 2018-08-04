#include <iostream>
#include "View.h"
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

View::View()
{
	size = 11;
	scale = 2;
	Cart_Point origin(0,0);
}

void View::clear() //sets all grid square to ". "
{
	for (int i = 0; i < view_maxsize; i++)
	{
		for (int j = 0; j < view_maxsize; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::plot(Game_Object* p1) //stores pointer code and ids in grid, if two are in same stop it stores "* " in grid
{
	int x1;
	int y1;

	if (get_subscripts(x1,y1, p1 -> get_location()) == true)
	{
		if(grid[x1][y1][0] == '.')
		{
			char * p2 = new char;
			p1 -> drawself(p2);
			grid[x1][y1][0] = *p2;
			grid[x1][y1][1] = *(p2 + 1);
			delete p2;
		}
		else
		{
			grid[x1][y1][0] = '*';
			grid[x1][y1][1] = ' ';
		}
	}
}

void View::draw() //draws graph
{
	int myarray[view_maxsize/2 + 1]; //creates an array of size 11 aka size
	for(int i = 0; i < (view_maxsize/2); i++) //stores i*2 in each cell
	{
		myarray[i] = i*2;
	}
	myarray[view_maxsize/2] = view_maxsize; //stores 20 in last cell

	for(int j = size - 1; j >= 0; j--) //if modulus = 0, the cell is printed, if not an extra space
	{
		if (j%2 == 0)
		{
			cout << myarray[j]; //prints labels for y axis
			if (myarray[j] < 10) //formats for second digit if necessary
			{
				cout << " ";
			}
			
		}
		else 
		{
			cout << "  ";
		}
		for (int k = 0; k < size; k++) //prints contents of grid
		{
			cout << grid[k][j][0] << grid[k][j][1];
		}
		cout << endl;
	}

	cout << "  ";

	for(int j = 0; j <= size; j++) //prints labels for x axis
	{
		if (j%2 == 0)
		{
			cout << myarray[j];
			if (myarray[j] < 10)
			{
				cout << "   ";
			}
			else
			{
				cout << "  ";
			}
		}
	}
	cout << endl;
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location) //puts the input x and y in proper scale, outputs if not in display and returns false if so
{
	ix = (location.x - origin.x) / scale;
	iy = (location.y - origin.y) / scale;

	if (view_maxsize >= ix || view_maxsize >= iy)
	{
		return true;
	}
	else
	{
		cout <<"An object is outside the display" << endl;
		return false;
	}
}