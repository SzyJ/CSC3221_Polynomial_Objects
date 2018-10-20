#pragma once
#include <vector>

struct PolynomialTerm {
	int exponent;
	int coefficient;

	PolynomialTerm(int exponent, int coefficient)
		: exponent(exponent), coefficient(coefficient) {}


	PolynomialTerm& operator!();
private:
	PolynomialTerm() {}
};

std::ostream& operator<<(std::ostream& outStream, const PolynomialTerm& term);

class Polynomial {
private:
	std::vector<PolynomialTerm>* polynomial;
	std::vector<PolynomialTerm> getSortedTermList();
	
public:
	// Constructors
	Polynomial();
	Polynomial(const int& polynomialDegree);
	Polynomial(const Polynomial& other);
	~Polynomial();

	// Methods
	int computeValue(int& xValue);
	void addTerm(int exponent, int coefficient);
	int getCoefficient(int& exponent);


	// Operator Overloads
	Polynomial& operator+(const PolynomialTerm& otherTerm);
	Polynomial& operator-(const PolynomialTerm& otherTerm);
	Polynomial& operator+(const Polynomial& otherPolynomial);
	Polynomial& operator-(const Polynomial& otherPolynomial);
	Polynomial& operator*(const Polynomial& otherPolynomial);

	Polynomial& operator+=(const Polynomial& otherPolynomial);
	Polynomial& operator-=(const Polynomial& otherPolynomial);
	Polynomial& operator*=(const Polynomial& otherPolynomial);
	
	bool operator==(const Polynomial& otherPolynomial);
	bool operator!=(const Polynomial& otherPolynomial);
};

std::istream& operator>>(std::istream& inStream, Polynomial& polynomial);
std::ostream& operator<<(std::ostream& outStream,  const Polynomial& polynomial);