#include "Matrix.h"
//Constructor
matrix::matrix()
{
	Matrix3by3[0][0] = 0, Matrix3by3[0][1] = 0, Matrix3by3[0][2] = 0;
	Matrix3by3[1][0] = 0, Matrix3by3[1][1] = 0, Matrix3by3[1][2] = 0;
	Matrix3by3[2][0] = 0, Matrix3by3[2][1] = 0, Matrix3by3[2][2] = 0;
}
matrix::matrix(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
	Matrix3by3[0][0] = x1, Matrix3by3[0][1] = y1, Matrix3by3[0][2] = z1;
	Matrix3by3[1][0] = x2, Matrix3by3[1][1] = y2, Matrix3by3[1][2] = z2;
	Matrix3by3[2][0] = x3, Matrix3by3[2][1] = y3, Matrix3by3[2][2] = z3;
}
matrix::matrix(double a[DIMENSION][DIMENSION])
{
	Matrix3by3[0][0] = a[0][0], Matrix3by3[0][1] = a[0][1], Matrix3by3[0][2] = a[0][2];
	Matrix3by3[1][0] = a[1][0], Matrix3by3[1][1] = a[1][1], Matrix3by3[1][2] = a[1][2];
	Matrix3by3[2][0] = a[2][0], Matrix3by3[2][1] = a[2][1], Matrix3by3[2][2] = a[2][2];
}
matrix::matrix(const vector& v1, const vector& v2, const vector& v3)
{
	Matrix3by3[0][0] = v1.x(), Matrix3by3[0][1] = v1.y(), Matrix3by3[0][2] = v1.z();
	Matrix3by3[1][0] = v2.x(), Matrix3by3[1][1] = v2.y(), Matrix3by3[1][2] = v2.z();
	Matrix3by3[2][0] = v3.x(), Matrix3by3[2][1] = v3.y(), Matrix3by3[2][2] = v3.z();
}
//Set function
void matrix::setValue(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
	Matrix3by3[0][0] = x1, Matrix3by3[0][1] = y1, Matrix3by3[0][2] = z1;
	Matrix3by3[1][0] = x2, Matrix3by3[1][1] = y2, Matrix3by3[1][2] = z2;
	Matrix3by3[2][0] = x3, Matrix3by3[2][1] = y3, Matrix3by3[2][2] = z3;
}
void matrix::setValue(double a[DIMENSION][DIMENSION])
{
	Matrix3by3[0][0] = a[0][0], Matrix3by3[0][1] = a[0][1], Matrix3by3[0][2] = a[0][2];
	Matrix3by3[1][0] = a[1][0], Matrix3by3[1][1] = a[1][1], Matrix3by3[1][2] = a[1][2];
	Matrix3by3[2][0] = a[2][0], Matrix3by3[2][1] = a[2][1], Matrix3by3[2][2] = a[2][2];
}
//Algebraic functions
matrix operator+(const matrix& m1, const matrix& m2)
{
	matrix result;
	result.setValue(m1.Matrix3by3[0][0] + m2.Matrix3by3[0][0], m1.Matrix3by3[0][1] + m2.Matrix3by3[0][1], m1.Matrix3by3[0][2] + m2.Matrix3by3[0][2],
		m1.Matrix3by3[1][0] + m2.Matrix3by3[1][0], m1.Matrix3by3[1][1] + m2.Matrix3by3[1][1], m1.Matrix3by3[1][2] + m2.Matrix3by3[1][2],
		m1.Matrix3by3[2][0] + m2.Matrix3by3[2][0], m1.Matrix3by3[2][1] + m2.Matrix3by3[2][1], m1.Matrix3by3[2][2] + m2.Matrix3by3[2][2]);
	return result;
}
matrix operator-(const matrix& m1, const matrix& m2)
{
	matrix result;
	result.setValue(m1.Matrix3by3[0][0] - m2.Matrix3by3[0][0], m1.Matrix3by3[0][1] - m2.Matrix3by3[0][1], m1.Matrix3by3[0][2] - m2.Matrix3by3[0][2],
		m1.Matrix3by3[1][0] - m2.Matrix3by3[1][0], m1.Matrix3by3[1][1] - m2.Matrix3by3[1][1], m1.Matrix3by3[1][2] - m2.Matrix3by3[1][2],
		m1.Matrix3by3[2][0] - m2.Matrix3by3[2][0], m1.Matrix3by3[2][1] - m2.Matrix3by3[2][1], m1.Matrix3by3[2][2] - m2.Matrix3by3[2][2]);
	return result;
}
matrix operator*(const double& k, const matrix& m1)
{
	matrix result;
	result.setValue(k * m1.Matrix3by3[0][0], k * m1.Matrix3by3[0][1], k * m1.Matrix3by3[0][2],
		k * m1.Matrix3by3[1][0], k * m1.Matrix3by3[1][1], k * m1.Matrix3by3[1][2],
		k * m1.Matrix3by3[2][0], k * m1.Matrix3by3[2][1], k * m1.Matrix3by3[2][2]);
	return result;
}
matrix operator*(const matrix& m1, const double& k)
{
	matrix result;
	result.setValue(k * m1.x1(), k * m1.y1(), k * m1.z1(),
		k * m1.x2(), k * m1.y2(), k * m1.z2(),
		k * m1.x3(), k * m1.y3(), k * m1.z3());
	return result;
}
matrix operator*(const matrix& m1, const matrix& m2)
{
	matrix result;
	result.setValue((m1.Matrix3by3[0][0] * m2.Matrix3by3[0][0]) + (m1.Matrix3by3[0][1] * m2.Matrix3by3[1][0]) + (m1.Matrix3by3[0][2] * m2.Matrix3by3[2][0]),
		(m1.Matrix3by3[0][0] * m2.Matrix3by3[0][1]) + (m1.Matrix3by3[0][1] * m2.Matrix3by3[1][1]) + (m1.Matrix3by3[0][2] * m2.Matrix3by3[2][1]),
		(m1.Matrix3by3[0][0] * m2.Matrix3by3[0][2]) + (m1.Matrix3by3[0][1] * m2.Matrix3by3[1][2]) + (m1.Matrix3by3[0][2] * m2.Matrix3by3[2][2]),
		(m1.Matrix3by3[1][0] * m2.Matrix3by3[0][0]) + (m1.Matrix3by3[1][1] * m2.Matrix3by3[1][0]) + (m1.Matrix3by3[1][2] * m2.Matrix3by3[2][0]),
		(m1.Matrix3by3[1][0] * m2.Matrix3by3[0][1]) + (m1.Matrix3by3[1][1] * m2.Matrix3by3[1][1]) + (m1.Matrix3by3[1][2] * m2.Matrix3by3[2][1]),
		(m1.Matrix3by3[1][0] * m2.Matrix3by3[0][2]) + (m1.Matrix3by3[1][1] * m2.Matrix3by3[1][2]) + (m1.Matrix3by3[1][2] * m2.Matrix3by3[2][2]),
		(m1.Matrix3by3[2][0] * m2.Matrix3by3[0][0]) + (m1.Matrix3by3[2][1] * m2.Matrix3by3[1][0]) + (m1.Matrix3by3[2][2] * m2.Matrix3by3[2][0]),
		(m1.Matrix3by3[2][0] * m2.Matrix3by3[0][1]) + (m1.Matrix3by3[2][1] * m2.Matrix3by3[1][1]) + (m1.Matrix3by3[2][2] * m2.Matrix3by3[2][1]),
		(m1.Matrix3by3[2][0] * m2.Matrix3by3[0][2]) + (m1.Matrix3by3[2][1] * m2.Matrix3by3[1][2]) + (m1.Matrix3by3[2][2] * m2.Matrix3by3[2][2]));
	return result;
}
vector operator*(const matrix& m1, const vector& v1)
{
	vector result;
	result.setValue((m1.Matrix3by3[0][0] * v1.x()) + (m1.Matrix3by3[0][1] * v1.y()) + (m1.Matrix3by3[0][2] * v1.z()),
		(m1.Matrix3by3[1][0] * v1.x()) + (m1.Matrix3by3[1][1] * v1.y()) + (m1.Matrix3by3[1][2] * v1.z()),
		(m1.Matrix3by3[2][0] * v1.x()) + (m1.Matrix3by3[2][1] * v1.y()) + (m1.Matrix3by3[2][2] * v1.z()));
	return result;
}

position operator*(const matrix& m1, const position& p1)
{
	position result;
	result.setValue((m1.Matrix3by3[0][0] * p1.x()) + (m1.Matrix3by3[0][1] * p1.y()) + (m1.Matrix3by3[0][2] * p1.z()),
		(m1.Matrix3by3[1][0] * p1.x()) + (m1.Matrix3by3[1][1] * p1.y()) + (m1.Matrix3by3[1][2] * p1.z()),
		(m1.Matrix3by3[2][0] * p1.x()) + (m1.Matrix3by3[2][1] * p1.y()) + (m1.Matrix3by3[2][2] * p1.z()));
	return result;
}

matrix operator/(const double& d, const matrix& m1)
{
	matrix result;
	result.setValue(m1.Matrix3by3[0][0] / d, m1.Matrix3by3[0][1] / d, m1.Matrix3by3[0][2] / d,
		m1.Matrix3by3[1][0] / d, m1.Matrix3by3[1][1] / d, m1.Matrix3by3[1][2] / d,
		m1.Matrix3by3[2][0] / d, m1.Matrix3by3[2][1] / d, m1.Matrix3by3[2][2] / d);
	return result;
}
matrix operator/(const matrix& m1, const double& d)
{
	matrix result;
	result.setValue(m1.x1() / d, m1.y1() / d, m1.z1() / d,
		m1.x2() / d, m1.y2() / d, m1.z2() / d,
		m1.x3() / d, m1.y3() / d, m1.z3() / d);
	return result;
}
//IOstream functions
ostream& operator<<(ostream& mout, const matrix& m1)
{
	mout << "( ( " << m1.Matrix3by3[0][0] << " , " << m1.Matrix3by3[0][1] << " , " << m1.Matrix3by3[0][2] << " ) ";
	mout << " , ( " << m1.Matrix3by3[1][0] << " , " << m1.Matrix3by3[1][1] << " , " << m1.Matrix3by3[1][2] << " ) ";
	mout << " , ( " << m1.Matrix3by3[2][0] << " , " << m1.Matrix3by3[2][1] << " , " << m1.Matrix3by3[2][2] << " ) )";
	return mout;
}
istream& operator>>(istream& min, matrix& m1)
{
	min >> m1.Matrix3by3[0][0] >> m1.Matrix3by3[0][1] >> m1.Matrix3by3[0][2];
	min >> m1.Matrix3by3[1][0] >> m1.Matrix3by3[1][1] >> m1.Matrix3by3[1][2];
	min >> m1.Matrix3by3[2][0] >> m1.Matrix3by3[2][1] >> m1.Matrix3by3[2][2];
	return min;
}
//vvTranspose and the Dual Matrix for Cross Product
matrix vvT(const vector& v1, const vector& v2)
{
	matrix result;
	result.setValue(v1.x() * v2.x(), v1.x() * v2.y(), v1.x() * v2.z(),
		v1.y() * v2.x(), v1.y() * v2.y(), v1.y() * v2.z(),
		v1.z() * v2.x(), v1.z() * v2.y(), v1.z() * v2.z());
	return result;
}
matrix vX(const vector& v1)
{
	matrix result;
	result.setValue(0, -v1.z(), v1.y(),
		v1.z(), 0, -v1.x(),
		-v1.y(), v1.x(), 0);
	return result;
}