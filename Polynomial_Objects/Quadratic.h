#pragma once
#include <iostream>

class Quadratic {
private:
	int a, b, c;
public:
	// Constructors
	Quadratic();
	explicit Quadratic(int iA, int iB, int iC);
	~Quadratic();

	//Operator Overloading
	Quadratic operator+(const Quadratic& other);
	Quadratic operator-(const Quadratic& other);
	Quadratic operator*(const int& other);
	Quadratic operator/(const int& other);
};

std::istream& operator>>(std::istream& inStream, Quadratic& quadratic);
std::ostream& operator<<(std::ostream& outStream, const Quadratic& quadratic);