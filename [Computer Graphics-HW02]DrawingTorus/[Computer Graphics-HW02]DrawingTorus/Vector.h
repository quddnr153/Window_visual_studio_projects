#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#define DIMENSION 3
using namespace std;
class position;
class Transformation;
class vector
{
private:
	double xyz[DIMENSION];
public:
	//Constructor
	vector();
	vector(double x, double y, double z);
	vector(double a[3]);
	//Inquiry functions
	double&		operator[](int i);
	double		operator[](int i)const;
	double		x()const;
	double		y()const;
	double		z()const;
	double		length()const;
	vector		unit() const;
	//Set functions
	void		setValue(double x, double y, double z);
	void		setValue(double a[DIMENSION]);
	void		set_x(double x);
	void		set_y(double y);
	void		set_z(double z);
	//Algebraic functions
	friend vector operator-(const vector& v1, const vector& v2);
	friend vector operator+(const vector& v1, const vector& v2);
	friend vector operator*(const vector& v1, const vector& v2);//Cross Product
	friend vector operator*(const double k, const vector& v1);	//Scalar *
	friend vector operator*(const vector& v1, const double k);	//Scalar *
	friend vector operator/(const vector& v1, const double k);  //Scalar /
	friend vector operator/(const double k, const vector& v1);	//Scalar /
	friend double operator%(const vector& v1, const vector& v2);//Dot Product
	friend vector& operator+=(vector& v1, const vector& v2);
	friend vector& operator-=(vector& v1, const vector& v2);
	friend vector operator-(const vector& v1);
	//IOstream functions
	friend ostream& operator<<(ostream& vout, const vector& v1);
	friend istream& operator>>(istream& vin, vector& v1);
};
#endif