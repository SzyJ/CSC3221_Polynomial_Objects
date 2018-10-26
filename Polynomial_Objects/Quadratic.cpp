#include "Quadratic.h"

// Constructors
Quadratic::Quadratic()
	: a(0), b(0), c(0) {}

Quadratic::Quadratic(int iA, int iB, int iC)
	: a(iA), b(iB), c(iC) {}

Quadratic::Quadratic(const Quadratic& other)
	: a(other.a), b(other.b), c(other.c) {}

Quadratic::~Quadratic() {}

int Quadratic::computeValue(int x) {
	return (a * pow(x, 2)) + (b * x) + c;
}

// Setters
int Quadratic::getA() const {
	return a;
}

int Quadratic::getB() const {
	return b;
}

int Quadratic::getC() const {
	return c;
}

// Setters
void Quadratic::setA(int a) {
	this->a = a;
}
void Quadratic::setB(int b) {
	this->b = b;
}
void Quadratic::setC(int c) {
	this->c = c;
}

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

bool Quadratic::operator==(const Quadratic& other){
	return getA() == other.getA()
		&& getB() == other.getB()
		&& getC() == other.getC();
}

bool Quadratic::operator!=(const Quadratic& other){
	return !(*this == other);
}

Quadratic& Quadratic::operator+=(const Quadratic& other){
	a += other.getA();
	b += other.getB();
	c += other.getC();
	
	return *this;
}

Quadratic& Quadratic::operator-=(const Quadratic& other){
	a -= other.getA();
	b -= other.getB();
	c -= other.getC();

	return *this;
}


std::istream& operator>>(std::istream& inStream, Quadratic& quadratic) {
	int a, b, c;

	std::cout << "Please enter a co-efficient for the term x^2: ";
	inStream >> a;
	quadratic.setA(a);

	std::cout << "Please enter a co-efficient for the term x^1: ";
	inStream >> b;
	quadratic.setB(b);

	std::cout << "Please enter a co-efficient for the term x^0: ";
	inStream >> c;
	quadratic.setC(c);

	return inStream;
}

std::ostream& operator<<(std::ostream& outStream, const Quadratic& quadratic) {
	const int aCoefficient = quadratic.getA();
	const int bCoefficient = quadratic.getB();
	const int cCoefficient = quadratic.getC();

	if (aCoefficient != 0) {
		if (aCoefficient == -1) {
			outStream << "-";
		} else if (aCoefficient > 1) {
			outStream << aCoefficient;
		}
		outStream << "x^2";
	}
	
	if (bCoefficient > 0) {
		if (bCoefficient != 1) {
			if (aCoefficient != 0) {
				outStream << " + " << bCoefficient;
			} else {
				outStream << bCoefficient;
			}
		}

		outStream << "x";
	} else if (bCoefficient < 0) {
		if (bCoefficient == -1) {
			outStream << "-";
		} else if (aCoefficient != 0) {
			outStream << " - " << (bCoefficient * -1);
		} else {
			outStream << bCoefficient;
		}
		outStream << "x";
	}

	if (cCoefficient > 0) {
		if ((aCoefficient != 0 || bCoefficient != 0)) {
			outStream << " + " << cCoefficient;
		} else {
			outStream << cCoefficient;
		}
	}
	else if (cCoefficient < 0) {
		if (aCoefficient != 0 || bCoefficient != 0) {
			outStream << " - " << (cCoefficient * -1);
		} else {
			outStream << cCoefficient;
		}
	}

	return outStream;
}