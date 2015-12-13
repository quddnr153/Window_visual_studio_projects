#pragma once
#ifndef QUATER_H
#define QUATER_H
#include "Vector.h"
#include "Matrix.h"
class quater
{
private:
	double qt[4];
public:
	//Constructor
	quater();
	quater(double w, double x, double y, double z);
	quater(double w, const vector& v);
	//Inquiry functions
	double&		operator[](int i) { return qt[i]; }
	double		operator[](int i)const { return qt[i]; }
	quater&		operator=(const quater& q);
	quater		inverse()const;
	double		magnitude()const;
	double		w()const { return qt[0]; }
	double		x()const { return qt[1]; }
	double		y()const { return qt[2]; }
	double		z()const { return qt[3]; }
	//Set functions
	void		setValue(double w, double x, double y, double z);
	void		setValue(double w, const vector& v);
	void		set_w(double w) { qt[0] = w; }
	void		set_x(double x) { qt[1] = x; }
	void		set_y(double y) { qt[2] = y; }
	void		set_z(double z) { qt[3] = z; }
	//Algebraic functions
	friend quater operator+(const quater& p1, const quater& p2);
	friend quater operator-(const quater& p1, const quater& p2);
	friend quater operator*(const quater& p1, const quater& p2);
	friend matrix Quater2Matrix(const quater& q);
	//	friend position rotate(const quater& q, const position& p);
	//IOstream functions
	friend ostream& operator<<(ostream& qout, const quater& q);
};

#endif