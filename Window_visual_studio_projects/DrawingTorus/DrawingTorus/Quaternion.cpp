#include "Quaternion.h"

//Constructor
quater::quater()
{
	qt[0] = 0;
	qt[1] = 1;
	qt[2] = 1;
	qt[3] = 1;
}
quater::quater(double w, double x, double y, double z)
{
	qt[0] = w;
	qt[1] = x;
	qt[2] = y;
	qt[3] = z;
}
quater::quater(double w, const vector& v)
{
	qt[0] = w;
	qt[1] = v.x();
	qt[2] = v.y();
	qt[3] = v.z();
}
//Inquiry functions
quater& quater::operator=(const quater& q)
{
	qt[0] = q[0];
	qt[1] = q[1];
	qt[2] = q[2];
	qt[3] = q[3];
	return *this;
}
double	quater::magnitude()const
{
	vector v(qt[1], qt[2], qt[3]);
	return sqrt((qt[0] * qt[0]) + (v % v));
}
quater	quater::inverse()const
{
	return quater(qt[0] / magnitude(), -qt[1] / magnitude(), -qt[2] / magnitude(), -qt[3] / magnitude());
	//	return quater(qt[0], -qt[1], -qt[2], -qt[3]);
}
//Set functions
void quater::setValue(double w, double x, double y, double z)
{
	qt[0] = w;
	qt[1] = x;
	qt[2] = y;
	qt[3] = z;
}
void quater::setValue(double w, const vector& v)
{
	qt[0] = w;
	qt[1] = v.x();
	qt[2] = v.y();
	qt[3] = v.z();
}
//Algebraic functions
quater operator+(const quater& p1, const quater& p2)
{
	quater result;
	result.qt[0] = p1.qt[0] + p2.qt[0];
	result.qt[1] = p1.qt[1] + p2.qt[1];
	result.qt[2] = p1.qt[2] + p2.qt[2];
	result.qt[3] = p1.qt[3] + p2.qt[3];
	return result;
}
quater operator-(const quater& p1, const quater& p2)
{
	quater result;
	result.qt[0] = p1.qt[0] - p2.qt[0];
	result.qt[1] = p1.qt[1] - p2.qt[1];
	result.qt[2] = p1.qt[2] - p2.qt[2];
	result.qt[3] = p1.qt[3] - p2.qt[3];
	return result;
}
quater operator*(const quater& p1, const quater& p2)
{
	double s1 = p1.qt[0], s2 = p2.qt[0];
	vector v1(p1.qt[1], p1.qt[2], p1.qt[3]);
	vector v2(p2.qt[1], p2.qt[2], p2.qt[3]);
	quater result;
	result.setValue((s1 * s2) - (v1 % v2), (s1 * v2) + (s2 * v1) + (v1 * v2));
	return result;
}
matrix Quater2Matrix(const quater& q)
{
	double s = q.qt[0], a = q.qt[1], b = q.qt[2], c = q.qt[3];
	matrix result(1 - (2 * b*b) - (2 * c*c), (2 * a*b) - (2 * s*c), (2 * a*c) + (2 * s*b),
		(2 * a*b) + (2 * s*c), 1 - (2 * a*a) - (2 * c*c), (2 * b*c) - (2 * s*a),
		(2 * a*c) - (2 * s*b), (2 * b*c) + (2 * s*a), 1 - (2 * a*a) - (2 * b*b));
	return result;
}
//IOstream functions
ostream& operator<<(ostream& qout, const quater& q)
{
	qout << " ( " << q.qt[0] << " , " << q.qt[1] << " , " << q.qt[2] << " , " << q.qt[3] << " )";
	return qout;
}