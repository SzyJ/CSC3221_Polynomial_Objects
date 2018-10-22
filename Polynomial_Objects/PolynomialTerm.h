#pragma once
#include <ostream>

struct PolynomialTerm {
	int exponent;
	int coefficient;

	PolynomialTerm(int exponent, int coefficient);

	int addToCoefficient(int conefficientChange);

	PolynomialTerm& operator*(const PolynomialTerm& otherTerm);
	PolynomialTerm& operator*=(const PolynomialTerm& otherTerm);

private:
	PolynomialTerm() {}
};

std::ostream& operator<<(std::ostream& outStream, const PolynomialTerm& term);
