#ifndef INCLUDE_POLYNOMIALS_H_
#define INCLUDE_POLYNOMIALS_H_

#include <iostream>
#include <string>
#include"List.h"

using namespace std;

const int var = 3;
const int MaxDegree = 10;

class monomial
{
	int coeff;
	int degree;
	
public:
	monomial();
	monomial(int _coeff, int indx, int indy, int indz);
	monomial(int _coeff, int _degree);

	int getDegree()
	{
		return degree;
	}

	monomial& operator =(const monomial& m);

	bool operator==(const monomial& m) const;
	bool operator!=(const monomial& m) const;

	friend const monomial operator -(const monomial& m);
	friend monomial operator +(const monomial& m1, const monomial& m2);
	friend monomial operator -(const monomial& m1, const monomial& m2);
	friend monomial operator *(const monomial& m1, const monomial& m2);
};

 class polinomial:public monomial
 {
	 List<monomial> Pol;
	 listIterator<monomial> it;

 public:
	 polinomial()
	 {
		
	 }

	 void addmonom(const monomial& m);
	
	 polinomial operator +(const polinomial& p);
	 polinomial operator -(const polinomial& p);
	 polinomial operator *(const polinomial& p);
	 
 };
#endif  // INCLUDE_ROMAN_H_