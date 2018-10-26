#pragma once
#include "TermList.h"

/*!
	Class for manipulation and creation of Polynomials.
	Polynomial Terms are stored on the Heap in a Linked List
 */
class Polynomial {
public:
	TermList terms;

	Polynomial();
	Polynomial(const Polynomial& polyCopy);

	//! Adds the provided term to the current polynomial structure.
	//! If the newly added value results in the coefficient of the
	//! given exponent to be 0, it will be removed from the structure.
	/*!
	  \param polynomialTerm The representation of the term to be added to this Polynomial.
	*/
	void addTerm(PolynomialTerm polynomialTerm);

	//! Adds the provided term to the current polynomial structure.
	//! If the newly added value results in the coefficient of the
	//! given exponent to be 0, it will be removed from the structure.
	/*!
	  \param coefficient The coefficient for the new term to be added.
	  \param exponent The exponent for the new term to be added.
	*/
	void addTerm(int coefficient, int exponent);

	//! Calculates the value of the polynomial if the given value for x
	//! was the variable used.
	/*!
	  \param x The value for x in the polynomial.
	  \return The result of the calculation.
	*/
	int computeValue(int x);

	// Operator Overloads
	Polynomial operator+(const Polynomial& other);
	Polynomial operator-(const Polynomial& other);
	Polynomial operator*(const Polynomial& other);

	Polynomial& operator+=(const Polynomial& other);
	Polynomial& operator-=(const Polynomial& other);
	Polynomial& operator*=(const Polynomial& other);

	Polynomial operator=(const Polynomial& other);
	
	bool operator==(const Polynomial& other);
	bool operator!=(const Polynomial& other);
};

std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial);
std::istream& operator>>(std::istream& inStream, Polynomial& polynomial);