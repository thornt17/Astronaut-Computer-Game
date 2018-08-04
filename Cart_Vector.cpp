#include <iostream>
#include "Cart_Vector.h"

using namespace std;

Cart_Vector::Cart_Vector()
{
	x = 0.0;
	y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
}

Cart_Vector operator*(const Cart_Vector & v1, double d)
{
	Cart_Vector v2;
	v2.x = v1.x * d;
	v2.y = v1.y * d;
	return v2;
}

Cart_Vector operator/(const Cart_Vector & v1, double d)
{
	Cart_Vector v2;
	v2.x = v1.x / d;
	v2.y = v2.y / d;
	return v2;
}

ostream& operator<<(ostream& out, const Cart_Vector& v1)
{
	out << "<" << v1.x << "," << v1.y << ">";
	return out;
}