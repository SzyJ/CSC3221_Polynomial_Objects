#include "PolynomialTerm.h"

// Constructors
PolynomialTerm::PolynomialTerm(int exponent, int coefficient)
	: exponent(exponent), coefficient(coefficient) {}

// Methods
int PolynomialTerm::addToCoefficient(int conefficientChange) {
	return coefficient += conefficientChange;
}

// Operator Overloads
PolynomialTerm& PolynomialTerm::operator*(const PolynomialTerm& otherTerm) {
	return *(new PolynomialTerm(exponent + otherTerm.exponent, coefficient * otherTerm.coefficient));
}

PolynomialTerm& PolynomialTerm::operator*=(const PolynomialTerm& otherTerm) {
	exponent += otherTerm.exponent;
	coefficient *= otherTerm.coefficient;

	return *this;
}

std::ostream& operator<<(std::ostream& outStream, const PolynomialTerm& term) {
	if (term.coefficient == 0) {
		outStream << "0";
		return outStream;
	}

	if (term.coefficient == -1) {
		outStream << "-";
	} else if (term.coefficient != 1) {
		outStream << term.coefficient;
	}

	if (term.exponent > 0) {
		outStream << "x";
	}
	if (term.exponent > 1) {
		outStream << "^" << term.exponent;
	}
	
	if (term.coefficient == -1 && term.exponent == 0) {
		outStream << "1";
	}

	return outStream;
}