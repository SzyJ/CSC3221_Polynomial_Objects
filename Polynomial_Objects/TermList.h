#pragma once
#include "TermNode.h"

/*
 * Head = Highest exponent
 * Tail = Exponent 0
 * 
 * When the term list is created, it is initialised with a term of coefficient 0 and exponent 0
 */
class TermList {
private:
	int termCount;
	TermNode* head;

public:
	TermList();
	TermList(const TermList& termList);
	~TermList();
	
	void addTerm(PolynomialTerm polynomialTerm);
	void addTerm(int exponent, int coefficient);
	const PolynomialTerm* toArrayList() const;
	int getTermCount() const;
	TermNode* getHeadNode() const;

	TermList operator+(const TermList& termList);
	TermList operator+(const int& addition);
	TermList operator-(const int& subtraction);
	TermList operator*(const TermList& termList);
	TermList operator*(const int& multiple);

	TermList& operator+=(const TermList& termList);
	TermList& operator+=(const int& addition);
	TermList& operator-=(const TermList& termList);
	TermList& operator-=(const int& subtraction);
	TermList& operator*=(const TermList& termList);
	TermList& operator*=(const int& multiple);
};

std::ostream& operator<<(std::ostream& outStream, const TermList& terms);