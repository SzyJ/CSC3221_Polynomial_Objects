#pragma once
#include <ostream>

/*!
	Struct representing one term of the polynomial (i.e. Ax^B).
*/
struct PolynomialTerm {
	int exponent;
	int coefficient;

	PolynomialTerm();
	PolynomialTerm(int exponent, int coefficient);

	//! Used to modify the coefficient of this term.
	/*!
	  \param conefficientChange Integer representing the change to be applied to the coefficient
	  \return The new coefficient of the term.
	*/
	int addToCoefficient(int conefficientChange);

	PolynomialTerm operator*(const PolynomialTerm& otherTerm);
	PolynomialTerm operator*(const int& multiple);
	PolynomialTerm& operator*=(const PolynomialTerm& otherTerm);
	PolynomialTerm& operator*=(const int& multiple);

	bool operator==(const PolynomialTerm& otherTerm);
	bool operator!=(const PolynomialTerm& otherTerm);
};

std::ostream& operator<<(std::ostream& outStream, const PolynomialTerm& term);
