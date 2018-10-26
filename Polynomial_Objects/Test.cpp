#include <iostream>
#include "Quadratic.h"
#include "TermList.h"
#include "Polynomial.h"

void testQuadratcic() {
	Quadratic test1(0, -9, 0);
	Quadratic test2(5, 9, 9);
	Quadratic add = test1 + test2;
	Quadratic sub = test1 - test2;

	std::cout << test1 << std::endl;
	std::cout << "When x=2 : " << test1.computeValue(2) << std::endl;

	std::cout << test2 << std::endl;
	std::cout << "When x=2 : " << test2.computeValue(2) << std::endl;

	std::cout << add << std::endl;
	std::cout << "When x=2 : " << add.computeValue(2) << std::endl;

	std::cout << sub << std::endl;
	std::cout << "When x=2 : " << sub.computeValue(2) << std::endl;

	Quadratic myQuad;
	std::cin >> myQuad;
	std::cout << myQuad;
	std::cin.get();
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

	std::cout << std::endl << "Test Converting to ArrayList" << std::endl;
	const PolynomialTerm* array = terms.toArrayList();
	std::cout << "[" << array[0];
	for (int i = 1; i < terms.getTermCount(); i++) {
		std::cout << ", " << array[i];
	}
	std::cout << "] size: " << terms.getTermCount() << std::endl;
	delete[] array;

	std::cout << std::endl << "Removing the highest and lowest exponent term" << std::endl;
	terms.addTerm(7, -2);
	terms.addTerm(0, -9);
	std::cout << terms << std::endl;

	std::cout << std::endl << "Removing all terms" << std::endl;
	terms.addTerm(5, -1);
	terms.addTerm(1, 1);
	std::cout << terms << std::endl;

}

void testPolynomials() {
	Polynomial polynomial;

	std::cout << "Empty Polynomial" << std::endl;
	std::cout << polynomial << std::endl;

	std::cout << std::endl << "Adding terms to Polynomial" << std::endl;
	polynomial.addTerm(6, 3);
	polynomial.addTerm(2, 7);
	polynomial.addTerm(-1, 1);
	polynomial.addTerm(9, 0);
	std::cout << polynomial << std::endl;
	std::cout << "Value for x=0: " << polynomial.computeValue(0) << std::endl;
	std::cout << "Value for x=1: " << polynomial.computeValue(1) << std::endl;
	std::cout << "Value for x=2: " << polynomial.computeValue(2) << std::endl;


	std::cout << std::endl << "Inserting term into the middle of Polynomial" << std::endl;
	polynomial.addTerm(1, 5);
	std::cout << polynomial << std::endl;
	std::cout << "Value for x=0: " << polynomial.computeValue(0) << std::endl;
	std::cout << "Value for x=1: " << polynomial.computeValue(1) << std::endl;
	std::cout << "Value for x=2: " << polynomial.computeValue(2) << std::endl;


	std::cout << std::endl << "Removing Term from Polynomial" << std::endl;
	polynomial.addTerm(-6, 3);
	std::cout << polynomial << std::endl;
	std::cout << "Value for x=0: " << polynomial.computeValue(0) << std::endl;
	std::cout << "Value for x=1: " << polynomial.computeValue(1) << std::endl;
	std::cout << "Value for x=2: " << polynomial.computeValue(2) << std::endl;


	std::cout << std::endl << "Removing the highest and lowest exponent term" << std::endl;
	polynomial.addTerm(-2, 7);
	polynomial.addTerm(-9, 0);
	std::cout << polynomial << std::endl;
	std::cout << "Value for x=0: " << polynomial.computeValue(0) << std::endl;
	std::cout << "Value for x=1: " << polynomial.computeValue(1) << std::endl;
	std::cout << "Value for x=2: " << polynomial.computeValue(2) << std::endl;


	std::cout << std::endl << "Removing all terms" << std::endl;
	polynomial.addTerm(-1, 5);
	polynomial.addTerm(1, 1);
	std::cout << polynomial << std::endl;
	std::cout << "Value for x=0: " << polynomial.computeValue(0) << std::endl;
	std::cout << "Value for x=1: " << polynomial.computeValue(1) << std::endl;
	std::cout << "Value for x=2: " << polynomial.computeValue(2) << std::endl;
}

void testPolynomialInput() {
	Polynomial polynomial;
	std::cin >> polynomial;
	std::cout << "Polynomial: " << polynomial << std::endl;
	
	int x = 0;
	std::cout << "Enter a value for x: ";
	std::cin >> x;

	std::cout << "Polynomial value when x = " << x << ": " << polynomial.computeValue(x);
	std::cin.get();
}

int main() {
	int choice = 0;
	std::cout << "1. Test Quadratic" << std::endl;
	std::cout << "2. Test TermList" << std::endl;
	std::cout << "3. Test Polynomials" << std::endl;
	std::cout << "4. Test Polynomial Input" << std::endl;
	std::cout << "Enter number: ";
	std::cin >> choice;
	std::cin.get();
	
	switch (choice) {
	case 1:
		testQuadratcic();
		break;
	case 2:
		testTermList();
		break;
	case 3:
		testPolynomials();
		break;
	case 4:
		testPolynomialInput();
		break;
	}

	std::cin.get();
}