#pragma once
#include "PolynomialTerm.h"

struct TermNode {
private:
	TermNode();
	TermNode(TermNode& other);

public:
	TermNode* nextNode;
	PolynomialTerm data;
	
	// Constructors
	TermNode(int exponent, int coefficient, TermNode* nextNode);
	~TermNode();
};