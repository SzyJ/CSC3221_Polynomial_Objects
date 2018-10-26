#pragma once
#include "TermList.h"

class Polynomial {
public:
	TermList terms;

	Polynomial();
	Polynomial(const Polynomial& polyCopy);

	void addTerm(PolynomialTerm polynomialTerm);
	void addTerm(int coefficient, int exponent);

	int computeValue(int x);

	// Operator Overloads
	Polynomial operator+(const Polynomial& other);
	Polynomial operator-(const Polynomial& other);
	Polynomial operator*(const Polynomial& other);

	Polynomial& operator+=(const Polynomial& other);
	Polynomial& operator-=(const Polynomial& other);
	Polynomial& operator*=(const Polynomial& other);

	bool operator==(const Polynomial& other);
	bool operator!=(const Polynomial& other);
};

std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial);
std::istream& operator>>(std::istream& inStream, Polynomial& polynomial);