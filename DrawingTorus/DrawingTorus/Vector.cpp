#include "Vector.h"

//Constructor
vector::vector()
{
	xyz[0] = 0;
	xyz[1] = 0;
	xyz[2] = 0;
}
vector::vector(double x, double y, double z)
{
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
}
vector::vector(double a[3])
{
	xyz[0] = a[0];
	xyz[1] = a[1];
	xyz[2] = a[2];
}
//Inquiry functions
double&		vector::operator[](int i) { return xyz[i]; }
double		vector::operator[](int i)const { return xyz[i]; }//check again later
double		vector::x()const { return xyz[0]; }
double		vector::y()const { return xyz[1]; }
double		vector::z()const { return xyz[2]; }
double		vector::length()const
{
	return sqrt((xyz[0] * xyz[0]) + (xyz[1] * xyz[1]) + (xyz[2] * xyz[2]));
}
vector		vector::unit()const
{
	return vector(xyz[0] / length(), xyz[1] / length(), xyz[2] / length());
}
//Set functions
void vector::setValue(double x, double y, double z)
{
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
}
void vector::setValue(double a[3])
{
	xyz[0] = a[0];
	xyz[1] = a[1];
	xyz[2] = a[2];
}
void vector::set_x(double x) { xyz[0] = x; }
void vector::set_y(double y) { xyz[1] = y; }
void vector::set_z(double z) { xyz[2] = z; }
//Algebraic functions
vector operator-(const vector& v1, const vector& v2)
{
	vector result;
	result.xyz[0] = v1.xyz[0] - v2.xyz[0];
	result.xyz[1] = v1.xyz[1] - v2.xyz[1];
	result.xyz[2] = v1.xyz[2] - v2.xyz[2];
	return result;
}
vector operator+(const vector& v1, const vector& v2)
{
	vector result;
	result.xyz[0] = v1.xyz[0] + v2.xyz[0];
	result.xyz[1] = v1.xyz[1] + v2.xyz[1];
	result.xyz[2] = v1.xyz[2] + v2.xyz[2];
	return result;
}
vector operator*(const vector& v1, const vector& v2)
{
	vector result;
	double tmp[DIMENSION];
	tmp[0] = (v1.xyz[1] * v2.xyz[2]) - (v1.xyz[2] * v2.xyz[1]);
	tmp[1] = (v1.xyz[2] * v2.xyz[0]) - (v1.xyz[0] * v2.xyz[2]);
	tmp[2] = (v1.xyz[0] * v2.xyz[1]) - (v1.xyz[1] * v2.xyz[0]);
	result.setValue(tmp[0], tmp[1], tmp[2]);
	return result;
}//Cross Product
vector operator*(const double k, const vector& v1)
{
	vector result;
	result.xyz[0] = k * v1.xyz[0];
	result.xyz[1] = k * v1.xyz[1];
	result.xyz[2] = k * v1.xyz[2];
	return result;
}//Scalar *
vector operator*(const vector& v1, const double k)
{
	vector result;
	result.xyz[0] = k * v1.xyz[0];
	result.xyz[1] = k * v1.xyz[1];
	result.xyz[2] = k * v1.xyz[2];
	return result;
}//Scalar *
vector operator/(const vector& v1, const double k)
{
	vector result;
	result.xyz[0] = v1.xyz[0] / k;
	result.xyz[1] = v1.xyz[1] / k;
	result.xyz[2] = v1.xyz[2] / k;
	return result;
}//Scalar /
vector operator/(const double k, const vector& v1)
{
	vector result;
	result.xyz[0] = v1.xyz[0] / k;
	result.xyz[1] = v1.xyz[1] / k;
	result.xyz[2] = v1.xyz[2] / k;
	return result;
}//Scalar /
double operator%(const vector& v1, const vector& v2)
{
	double result;
	result = (v1.xyz[0] * v2.xyz[0]) + (v1.xyz[1] * v2.xyz[1]) + (v1.xyz[2] * v2.xyz[2]);
	return result;
}//Dot Product
vector& operator+=(vector& v1, const vector& v2)
{
	double tmp[DIMENSION];
	tmp[0] = v1.xyz[0] + v2.xyz[0];
	tmp[1] = v1.xyz[1] + v2.xyz[1];
	tmp[2] = v1.xyz[2] + v2.xyz[2];
	v1.setValue(tmp[0], tmp[1], tmp[2]);
	return v1;
}
vector operator-(const vector& v1)
{
	vector result;
	result.setValue(-v1.xyz[0], -v1.xyz[1], -v1.xyz[2]);
	return result;
}
vector& operator-=(vector& v1, const vector& v2)
{
	double tmp[DIMENSION];
	tmp[0] = v1.xyz[0] - v2.xyz[0];
	tmp[1] = v1.xyz[1] - v2.xyz[1];
	tmp[2] = v1.xyz[2] - v2.xyz[2];
	v1.setValue(tmp[0], tmp[1], tmp[2]);
	return v1;
}
//IOstream functions
ostream& operator<<(ostream& vout, const vector& v1)
{
	vout << " ( " << v1.xyz[0] << " , " << v1.xyz[1] << " , " << v1.xyz[2] << " )";
	return vout;
}
istream& operator>>(istream& vin, vector& v1)
{
	vin >> v1.xyz[0] >> v1.xyz[1] >> v1.xyz[2];
	return vin;
}