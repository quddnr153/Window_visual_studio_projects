#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"
#include "Position.h"
class matrix
{
private:
	double Matrix3by3[DIMENSION][DIMENSION];
	vector v[DIMENSION];
public:
	//Constructor
	matrix();
	matrix(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
	matrix(double a[DIMENSION][DIMENSION]);
	matrix(const vector& v1, const vector& v2, const vector& v3);
	//Inquiry functions
	double		x1()const { return Matrix3by3[0][0]; }
	double		y1()const { return Matrix3by3[0][1]; }
	double		z1()const { return Matrix3by3[0][2]; }
	double		x2()const { return Matrix3by3[1][0]; }
	double		y2()const { return Matrix3by3[1][1]; }
	double		z2()const { return Matrix3by3[1][2]; }
	double		x3()const { return Matrix3by3[2][0]; }
	double		y3()const { return Matrix3by3[2][1]; }
	double		z3()const { return Matrix3by3[2][2]; }
	//Set functions
	void		setValue(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
	void		setValue(double a[DIMENSION][DIMENSION]);
	void		set_x1(double x1) { Matrix3by3[0][0] = x1; }
	void		set_y1(double y1) { Matrix3by3[0][1] = y1; }
	void		set_z1(double z1) { Matrix3by3[0][2] = z1; }
	void		set_x2(double x2) { Matrix3by3[1][0] = x2; }
	void		set_y2(double y2) { Matrix3by3[1][1] = y2; }
	void		set_z2(double z2) { Matrix3by3[1][2] = z2; }
	void		set_x3(double x3) { Matrix3by3[2][0] = x3; }
	void		set_y3(double y3) { Matrix3by3[2][1] = y3; }
	void		set_z3(double z3) { Matrix3by3[2][2] = z3; }
	//Algebraic functions
	friend matrix	operator+(const matrix& m1, const matrix& m2);
	friend matrix	operator-(const matrix& m1, const matrix& m2);
	friend matrix	operator*(const double& k, const matrix& m1);
	friend matrix	operator*(const matrix& m1, const double k);
	friend matrix	operator*(const matrix& m1, const matrix& m2);
	friend vector	operator*(const matrix& m1, const vector& v1);
	friend position	operator*(const matrix& m1, const position& p1);
	friend matrix	operator/(const double& c, const matrix& m1);
	friend matrix	operator/(const matrix& m1, const double c);
	//IOstream functions
	friend ostream& operator<<(ostream& mout, const matrix& m1);
	friend istream& operator>>(istream& min, matrix& m1);
	//vvTranspose and the Dual Matrix for Cross Product
	friend matrix	vvT(const vector& v1, const vector& v2);
	friend matrix	vX(const vector& v1);
};

#endif