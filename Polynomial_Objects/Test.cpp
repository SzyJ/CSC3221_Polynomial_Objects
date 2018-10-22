#include <iostream>
#include "Quadratic.h"
#include "TermList.h"

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

void testTermList() {
	TermList terms;

	std::cout << "Empty Polynomial" << std::endl;
	std::cout << terms << std::endl;

	std::cout << std::endl << "Adding terms to Polynomial" << std::endl;
	terms.addTerm(3, 6);
	terms.addTerm(7, 2);
	terms.addTerm(1, -1);
	terms.addTerm(0, 9);

	std::cout << terms << std::endl;

	std::cout << std::endl << "Inserting term into the middle of Polynomial" << std::endl;
	terms.addTerm(5, 1);
	std::cout << terms << std::endl;

	std::cout << std::endl << "Removing Term from Polynomial" << std::endl;
	terms.addTerm(3, -6);
	std::cout << terms << std::endl;

	std::cout << std::endl << "Removing the highest and lowest exponent term" << std::endl;
	terms.addTerm(7, -2);
	terms.addTerm(0, -9);
	std::cout << terms << std::endl;

	std::cout << std::endl << "Removing all terms" << std::endl;
	terms.addTerm(5, -1);
	terms.addTerm(1, 1);
	std::cout << terms << std::endl;

}

int main() {
	//testQuadratcic();

	testTermList();

	std::cin.get();
}