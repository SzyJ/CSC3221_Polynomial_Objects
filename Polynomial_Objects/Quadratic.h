#pragma once
#include <iostream>

/*!
	A class representing a polynomial of degree 2.
*/
class Quadratic {
private:
	int a, b, c;
public:
	// Constructors
	Quadratic();
	explicit Quadratic(int iA, int iB, int iC);
	Quadratic(const Quadratic& other);
	~Quadratic();

	//! Calculates the value of the quadratic if the given value for x
	//! was the variable used.
	/*!
	  \param x The value for x in the polynomial.
	  \return The result of the calculation.
	*/
	int computeValue(int x);

	// Getters
	int getA() const;
	int getB() const;
	int getC() const;

	// Setters
	void setA(const int a);
	void setB(const int b);
	void setC(const int c);

	//Operator Overloading
	Quadratic operator+(const Quadratic& other);
	Quadratic operator-(const Quadratic& other);
	Quadratic operator*(const int& other);
	Quadratic operator/(const int& other);

	bool operator==(const Quadratic& other);
	bool operator!=(const Quadratic& other);
	Quadratic& operator+=(const Quadratic& other);
	Quadratic& operator-=(const Quadratic& other);
};

std::istream& operator>>(std::istream& inStream, Quadratic& quadratic);
std::ostream& operator<<(std::ostream& outStream, const Quadratic& quadratic);