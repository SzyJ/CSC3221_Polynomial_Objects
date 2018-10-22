#pragma once
#include "TermNode.h"

/*
 * Head = Highest exponent
 * Tail = Exponent 0
 * 
 * When the term list is created, it is initialised with a term of coefficient 0 and exponent 0
 */
class TermList {
public:
	TermNode* head;

	TermList();
	~TermList();
	
	void addTerm(int exponent, int coefficient);
};

std::ostream& operator<<(std::ostream& outStream, const TermList& terms);