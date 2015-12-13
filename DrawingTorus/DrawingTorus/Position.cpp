#include "Position.h"

//Constructor
position::position()
{
	xyz[0] = 0;
	xyz[1] = 0;
	xyz[2] = 0;
}
position::position(double x, double y, double z)
{
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
}
position::position(double a[DIMENSION])
{
	xyz[0] = a[0];
	xyz[1] = a[1];
	xyz[2] = a[2];
}
//Inquiry functions
double& position::operator[](int i) { return xyz[i]; }
double	position::x()const { return xyz[0]; }
double	position::y()const { return xyz[1]; }
double	position::z()const { return xyz[2]; }
//Set functions
void	position::setValue(double x, double y, double z)
{
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
}
void	position::setValue(double a[DIMENSION])
{
	xyz[0] = a[0];
	xyz[1] = a[1];
	xyz[2] = a[2];
}
void	position::set_x(double x) { xyz[0] = x; }
void	position::set_y(double y) { xyz[1] = y; }
void	position::set_z(double z) { xyz[2] = z; }
//Algebraic functions
position operator+(const position& p1, const vector& v1)
{
	position result;
	result.setValue(p1.xyz[0] + v1.x(), p1.xyz[1] + v1.y(), p1.xyz[2] + v1.z());
	return result;
}
//IOstream funstions
ostream& operator<<(ostream& pout, const position& p1)
{
	pout << " ( " << p1.xyz[0] << " , " << p1.xyz[1] << " , " << p1.xyz[2] << " )";
	return pout;
}
/*
istream& operator>>(istream& pin, const position&p1)
{
pin >> p1.xyz[0] >> p1.xyz[1] >> p1.xyz[2];
return pin;
}
*/