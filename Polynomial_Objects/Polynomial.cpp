#include "Polynomial.h"
#include <ostream>
#include <algorithm>
#include <functional>

Polynomial::Polynomial() {
	polynomial = new std::vector<PolynomialTerm>;
}

Polynomial::Polynomial(const int& polynomialDegree) {
	int* test = new int[polynomialDegree];

	polynomial = new std::vector<PolynomialTerm>;
	polynomial->reserve(polynomialDegree);
}

Polynomial::Polynomial(const Polynomial& other) {
	// TODO
}

Polynomial::~Polynomial() {
	delete polynomial;
}

int Polynomial::computeValue(int& xValue) {
	int cumulativeTotal = 0;
	for (PolynomialTerm term : *polynomial) {
		cumulativeTotal += (term.coefficient * pow(xValue, term.exponent));
	}

	return cumulativeTotal;
}

void Polynomial::addTerm(int exponent, int coefficient) {
	for (int i = 0; i < polynomial->size(); i++) {

		PolynomialTerm* thisTerm = &(polynomial->at(i));

		if (thisTerm->exponent == exponent) {
			int newCoefficientValue = thisTerm->coefficient += coefficient;
			if (newCoefficientValue == 0) {
				polynomial->erase(polynomial->begin() + i);
			}

			return;
		}
	}

	polynomial->emplace_back(coefficient, exponent);

	
//	std::sort(polynomial->begin, polynomial->end,
//		[](const PolynomialTerm a)->bool {
//			return a.exponent > b.exponent;
//		}
//	);
}

int Polynomial::getCoefficient(int& exponent) {
	for (int i = 0; i < polynomial->size(); i++) {

		if (polynomial->at(i).exponent == exponent) {
			return polynomial->at(i).coefficient;
		}
	}

	return 0;
}

// Operator Overloads
Polynomial& Polynomial::operator+(const PolynomialTerm& otherTerm) {
	this->addTerm(otherTerm.exponent, otherTerm.coefficient);
}
Polynomial& Polynomial::operator-(const PolynomialTerm& otherTerm) {
	this->addTerm(otherTerm.exponent, -1 * otherTerm.coefficient);
}
Polynomial& Polynomial::operator+(const Polynomial& other) {

}
Polynomial& Polynomial::operator-(const Polynomial& other) {

}
Polynomial& Polynomial::operator*(const Polynomial& other) {

}
Polynomial& Polynomial::operator+=(const Polynomial& other) {

}
Polynomial& Polynomial::operator-=(const Polynomial& other) {

}
Polynomial& Polynomial::operator*=(const Polynomial& other) {

}
bool Polynomial::operator==(const Polynomial& other) {

}
bool Polynomial::operator!=(const Polynomial& other) {

}
std::istream& operator>>(std::istream& inStream, Polynomial& polynomial) {

}
std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial) {
	

	return outStream;
}

// Polynomial Term Operators
std::ostream& operator<<(std::ostream& outStream, const PolynomialTerm& term) {
	outStream << term.coefficient << "x^" << term.exponent;
	return outStream;
}
PolynomialTerm& PolynomialTerm::operator!() {
	coefficient * -1;
	return *this;
}