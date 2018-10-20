#include <iostream>
#include "Quadratic.h"

void testQuadratcic() {
	Quadratic test1(0, -9, 0);
	Quadratic test2(5, 9, 9);
	Quadratic add = test1 + test2;
	Quadratic sub = test1 - test2;

	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << add << std::endl;
	std::cout << sub << std::endl;

	Quadratic myQuad;
	std::cin >> myQuad;
	std::cout << myQuad;
}
int main() {
	testQuadratcic();


	std::cin.get();
}