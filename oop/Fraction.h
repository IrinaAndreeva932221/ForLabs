#pragma once
class Fraction
{
public:
	Fraction Sum(const Fraction a);
	Fraction Sub(const Fraction a);
	Fraction Multiplication(const Fraction a);
	void Print();
	int numerator;
	int denominator;

public:
	Fraction();
	~Fraction();
};

