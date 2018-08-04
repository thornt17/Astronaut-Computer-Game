#ifndef CARTPOINT_H
#define CARTPOINT_H

#include <iostream>

#include "Cart_Vector.h"

using namespace std;

class Cart_Point
{
	public:
		double x;
		double y;

		Cart_Point();
		Cart_Point(double inputx, double inputy);


};


double cart_distance(Cart_Point p1, Cart_Point p2);

ostream& operator<<(ostream& out, const Cart_Point& cp);

Cart_Point operator+(const Cart_Point &, const Cart_Vector &);

Cart_Vector operator-(const Cart_Point &, const Cart_Point &);


#endif