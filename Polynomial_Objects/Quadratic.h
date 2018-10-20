#pragma once
#include <iostream>

class Quadratic {
private:
	int a, b, c;
public:
	// Constructors
	Quadratic();
	explicit Quadratic(int iA, int iB, int iC);
	Quadratic(const Quadratic& other);
	~Quadratic();

	// Methods
	int computeValue(int& x);

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
};

std::istream& operator>>(std::istream& inStream, Quadratic& quadratic);
std::ostream& operator<<(std::ostream& outStream, const Quadratic& quadratic);