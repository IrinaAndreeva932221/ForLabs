#include "pch.h"
#include "Fraction.h"
#include <iostream>

Fraction Fraction::Sum(const Fraction a)
{
	Fraction sumOfFractions;
	sumOfFractions.numerator = numerator * a.denominator + a.numerator * denominator;
	sumOfFractions.denominator = a.denominator * denominator;
	return sumOfFractions;
}

Fraction Fraction::Sub(const Fraction a)
{
	Fraction subOfFractions;
	subOfFractions.numerator = numerator * a.denominator - a.numerator * denominator;
	subOfFractions.denominator = a.denominator * denominator;
	return subOfFractions;
}

Fraction Fraction::Multiplication(const Fraction a)
{
	Fraction mulOfFractions;
	mulOfFractions.numerator = numerator * a.numerator;
	mulOfFractions.denominator = a.denominator * denominator;
	return mulOfFractions;
}

void Fraction::Print()
{
	std::cout << numerator << '/' << denominator<<std::endl;
}


Fraction::Fraction()
{
	
}


Fraction::~Fraction()
{
}
