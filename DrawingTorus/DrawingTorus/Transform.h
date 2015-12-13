#pragma once
#ifndef TRANSF_H
#define TRANSF_H
#include "Vector.h"
#include "Matrix.h"
class transf
{
private:
	matrix m;
	vector v;
public:
	//Constructor
	transf();
	transf(const matrix& m1, const vector& v1);
	//Inquiry functions
	matrix	getMatrix();
	transf& operator=(const transf& t1);
	//S, R, T functions
	friend transf scale_transf(double x, double y, double z);
	friend transf rotate_transf(double theta, const vector& v1);
	friend transf translate_transf(double x, double y, double z);
	//Implement transformation operations
	friend transf	operator*(const transf& t1, const transf& t2);
	friend position	operator*(const transf& t1, const position& p1);
	friend vector	operator*(const transf& t1, const vector& v1);
	//IOstream functions
	friend ostream& operator<<(ostream& tout, const transf& t1);
};

#endif