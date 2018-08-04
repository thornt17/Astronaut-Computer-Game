#ifndef CARTVECTOR_H
#define CARTVECTOR_H

#include <iostream>

using namespace std;

class Cart_Vector
{
public:
	double x;
	double y;

	Cart_Vector();

	Cart_Vector(double inputx, double inputy);
};

Cart_Vector operator*(const Cart_Vector &, double);

Cart_Vector operator/(const Cart_Vector &, double);

ostream& operator<<(ostream& out, const Cart_Vector&);


#endif