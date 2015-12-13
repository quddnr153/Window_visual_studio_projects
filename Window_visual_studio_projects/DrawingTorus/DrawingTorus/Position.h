#pragma once
#ifndef POSITION_H
#define POSITION_H
#include "Vector.h"
class position
{
private:
	double xyz[DIMENSION];
public:
	//Constructor
	position();
	position(double x, double y, double z);
	position(double a[DIMENSION]);
	//Inquiry functions
	double& operator[](int i);
	double x()const;
	double y()const;
	double z()const;
	//Set functions
	void setValue(double x, double y, double z);
	void setValue(double a[DIMENSION]);
	void set_x(double x);
	void set_y(double y);
	void set_z(double z);
	//Algebraic functions
	friend position operator+(const position& p1, const vector& v1);
	//	friend vector	operator*(const vector& v1, const position& p1);
	//	friend Vector	p2v(const Position& p1);
	//IOstream functions
	friend ostream& operator<<(ostream& pout, const position& p1);
	//	friend istream& operator>>(istream& pin, const position&p1);
};

#endif