#include "Quadratic.h"

// Constructors
Quadratic::Quadratic()
	: a(0), b(0), c(0) {}

Quadratic::Quadratic(int iA, int iB, int iC)
	: a(iA), b(iB), c(iC) {}

Quadratic::~Quadratic() {}

// Operators Overloads
Quadratic Quadratic::operator+(const Quadratic& other) {
	return Quadratic(a + other.a, b + other.b, c + other.c);
}

Quadratic Quadratic::operator-(const Quadratic& other) {
	return Quadratic(a - other.a, b - other.b, c - other.c);
}

Quadratic Quadratic::operator*(const int& other) {
	return Quadratic(a * other, b * other, c * other);
}

Quadratic Quadratic::operator/(const int& other) {
	return Quadratic(a / other, b / other, c / other);
}


std::istream& operator>>(std::istream& inStream, Quadratic& quadratic) {

}

std::ostream& operator<<(std::ostream& outStream, const Quadratic& quadratic) {
	//outStream << quadratic.a << "x^2";
	//if (b == 0) {

	//}
}

int main() {
	Quadratic test1(4, 9, 3);
	Quadratic test2(7, 1, 9);
}