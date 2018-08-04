#include <iostream>
#include "Cart_Point.h"
#include <cmath>
#include "Cart_Vector.h"

using namespace std;

Cart_Point::Cart_Point()
{
	x = 0.0;
	y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2)
{
	return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}

ostream& operator<<(ostream& out, const Cart_Point& cp)
{
	out << "(" << cp.x << "," << cp.y << ")";
	return out;
}

Cart_Point operator+(const Cart_Point & p1, const Cart_Vector & v1)
{
	Cart_Point newcp;
	newcp.x = p1.x + v1.x;
	newcp.y = p1.y + v1.y;
	return newcp;
}

Cart_Vector operator-(const Cart_Point & p1, const Cart_Point & p2)
{
	Cart_Vector newcv;
	newcv.x = p1.x - p2.x;
	newcv.y = p1.y - p2.y;
	return newcv;
}