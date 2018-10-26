#pragma once
#include <ostream>

struct PolynomialTerm {
	int exponent;
	int coefficient;

	PolynomialTerm();
	PolynomialTerm(int exponent, int coefficient);

	int addToCoefficient(int conefficientChange);

	PolynomialTerm operator*(const PolynomialTerm& otherTerm);
	PolynomialTerm operator*(const int& multiple);
	PolynomialTerm& operator*=(const PolynomialTerm& otherTerm);
	PolynomialTerm& operator*=(const int& multiple);

	bool operator==(const PolynomialTerm& otherTerm);
	bool operator!=(const PolynomialTerm& otherTerm);
};

std::ostream& operator<<(std::ostream& outStream, const PolynomialTerm& term);
