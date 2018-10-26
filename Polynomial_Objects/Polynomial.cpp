#include "Polynomial.h"
#include <iostream>

// Constructors
Polynomial::Polynomial() 
	:terms() {}

Polynomial::Polynomial(const Polynomial& polyCopy) {
	Polynomial();

	for (TermNode* currentNode = polyCopy.terms.getHeadNode(); currentNode != nullptr; currentNode = currentNode->nextNode) {
		addTerm(currentNode->data);
	}
}

// Methods
int Polynomial::computeValue(int x) {
	int comulitativeTotal = 0;
	for (TermNode* currentNode = terms.getHeadNode(); currentNode != nullptr; currentNode = currentNode->nextNode) {
		comulitativeTotal += (currentNode->data.coefficient * pow(x, currentNode->data.exponent));
	}

	return comulitativeTotal;
}

void Polynomial::addTerm(PolynomialTerm polynomialTerm) {
	addTerm(polynomialTerm.coefficient, polynomialTerm.exponent);
}

void Polynomial::addTerm(int coefficient, int exponent) {
	terms.addTerm(exponent, coefficient);
}

// Operator Overloads
Polynomial Polynomial::operator+(const Polynomial& other) {
	Polynomial poly = *this;

	for (TermNode* currentNode = other.terms.getHeadNode(); currentNode != nullptr; currentNode = currentNode->nextNode) {
		poly.addTerm(currentNode->data);
	}
	return poly;
}

Polynomial Polynomial::operator-(const Polynomial& other) {
	Polynomial poly = *this;

	for (TermNode* currentNode = other.terms.getHeadNode(); currentNode != nullptr; currentNode = currentNode->nextNode) {
		poly.addTerm(currentNode->data * -1);
	}
	return poly;
}

Polynomial Polynomial::operator*(const Polynomial& other) {
	Polynomial poly = *this;

	poly.terms *= other.terms;

	return poly;
}


Polynomial& Polynomial::operator+=(const Polynomial& other) {
	for (TermNode* currentNode = other.terms.getHeadNode(); currentNode != nullptr; currentNode = currentNode->nextNode) {
		addTerm(currentNode->data);
	}

	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
	for (TermNode* currentNode = other.terms.getHeadNode(); currentNode != nullptr; currentNode = currentNode->nextNode) {
		addTerm(currentNode->data * -1);
	}

	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
	*this *= other;

	return *this;
}


bool Polynomial::operator==(const Polynomial& other) {
	if (terms.getTermCount() != other.terms.getTermCount()) {
		return false;
	}

	TermNode* thisNode = terms.getHeadNode();
	TermNode* otherNode = other.terms.getHeadNode();
	while (thisNode != nullptr && otherNode != nullptr) {
		if (thisNode->data != otherNode->data) {
			return false;
		}

		thisNode = thisNode->nextNode;
		otherNode = otherNode->nextNode;
	}

	return true;
}

bool Polynomial::operator!=(const Polynomial& other) {
	return !(*this == other);
}

Polynomial Polynomial::operator=(const Polynomial& other) {
	if (this == &other) {
		return *this;
	}

	Polynomial newPoly(other);

	return newPoly;
}

std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial) {
	outStream << polynomial.terms;

	return outStream;
}

std::istream& operator>>(std::istream& inStream, Polynomial& polynomial) {
	int newExponent = 0;
	int newCoefficient = 0;
	bool valid;
	
	std::cout << "Enter as many terms as you wish. Use a non-number to finish" << std::endl;
	do {
		std::cout << "Enter the Coefficient of the new term: ";
		std::cin >> newCoefficient;

		valid = !std::cin.fail();
		if (valid) {
			std::cout << "Enter the Exponent for the " << newCoefficient << " coeffiecient: " << newCoefficient << "x^";
			std::cin >> newExponent;

			valid = !std::cin.fail();
			if (valid) {
				polynomial.addTerm(newCoefficient, newExponent);
			}
		}
	} while (valid);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return inStream;
}