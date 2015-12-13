#include "Transform.h"


//Constructor
transf::transf() {}
transf::transf(const matrix& m1, const vector& v1)
{
	m = m1;
	v = v1;
}
//Inquiry functions
matrix	transf::getMatrix()
{
	return m;
}
transf& transf::operator=(const transf& t1)
{
	m = t1.m;
	v = t1.v;
	return *this;
}
//S, R, T functions
transf scale_transf(double x, double y, double z)
{
	return transf(matrix(x, 0, 0, 0, y, 0, 0, 0, z), vector(0, 0, 0));
}
transf translate_transf(double x, double y, double z)
{
	return transf(matrix(1, 0, 0, 0, 1, 0, 0, 0, 1), vector(x, y, z));
}
transf rotate_transf(double theta, const vector& v1)
{//Axis-angle rotation
	vector unit_v(v1.x() / v1.length(), v1.y() / v1.length(), v1.z() / v1.length());
	matrix vvt = vvT(unit_v, unit_v);
	matrix vx = vX(unit_v);
	matrix unit_m(1, 0, 0, 0, 1, 0, 0, 0, 1);
	double		sintheta = sin(theta), costheta = cos(theta);
	matrix	R_theta = vvt + costheta * (unit_m - vvt) + sintheta * vx;
	return transf(R_theta, vector(0, 0, 0));
}
//Implement transfomation operations
transf operator*(const transf& t1, const transf& t2)
{
	transf result(t1.m * t2.m, t1.m * t2.v + t1.v);
	return result;
}
position operator*(const transf& t1, const position& p1)
{
	position tmp1, result;
	tmp1.setValue((t1.m.x1() * p1.x()) + (t1.m.y1() * p1.y()) + (t1.m.z1() * p1.z()),
		(t1.m.x2() * p1.x()) + (t1.m.y2() * p1.y()) + (t1.m.z2() * p1.z()),
		(t1.m.x3() * p1.x()) + (t1.m.y3() * p1.y()) + (t1.m.z3() * p1.z()));
	result = tmp1 + t1.v;
	return result;
}
vector operator*(const transf& t1, const vector& v1)
{
	matrix tmp = t1.m;
	vector result;
	result = tmp * v1;
	return result;
}
//IOstream functions
ostream& operator<<(ostream& tout, const transf& t1)
{
	tout << " ( ( " << t1.m.x1() << " , " << t1.m.y1() << " , " << t1.m.z1() << " ) , ( ";
	tout << t1.m.x2() << " , " << t1.m.y2() << " , " << t1.m.z2() << " ) , ( ";
	tout << t1.m.x3() << " , " << t1.m.y3() << " , " << t1.m.z3() << " ) ) +";
	tout << " ( " << t1.v.x() << " , " << t1.v.y() << " , " << t1.v.z() << " )";
	return tout;
}