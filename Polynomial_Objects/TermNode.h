#pragma once
#include "PolynomialTerm.h"

/*!
	A node of a linked list containing the polynomial term and a link to the next node.
	If a node's next node is a nullptr, this is the last node in the list.
*/
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