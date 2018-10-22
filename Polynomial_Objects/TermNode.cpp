#include "TermNode.h"

// Constructors
TermNode::TermNode(int exponent, int coefficient, TermNode* nextNode)
	:data(PolynomialTerm(exponent, coefficient)), nextNode(nextNode) {}

TermNode::~TermNode() {
	delete nextNode;
}