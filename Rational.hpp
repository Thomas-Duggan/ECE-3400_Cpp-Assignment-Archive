// Rational Fraction Calculator  Copyright (c) 2025  Thomas Duggan
// This work is licensed under CC BY-SA 4.0 


#pragma once
#include <iostream>

using namespace std;

class Rational
{
public:
	typedef int Integer;

	Rational(Integer numerator = 0, Integer denominator = 1);

	Rational(Rational&& other);

	Rational(const Rational& other);

	Rational& operator=(const Rational& other);

	Rational& operator=(const Rational&& other);

	Rational operator+(const Rational& other);	
	
	Rational operator-(const Rational& other);
	
	Rational operator*(const Rational& other);

	Rational operator/(const Rational& other);	

	Rational& operator+=(const Rational& other);

	Rational& operator-=(const Rational& other);
	
	Rational& operator*=(const Rational& other);

	Rational& operator/=(const Rational& other);

	ostream& print(ostream& Out)
	{
	    Out << numerator << "/" << denominator;
	    return Out;
	}
	    
	istream& scan(istream& In)
	{   
	    In >> numerator;
	    In.ignore(1);
	    In >> denominator;
	    return In;
	}

	double toDouble();

	// Should use the provided print method
	friend ostream& operator<<(ostream& out, Rational& rational);

	// Should use the provided scan method
	friend istream& operator>>(istream& in, Rational& rational);

private:
	Integer numerator;
	Integer denominator;
};
