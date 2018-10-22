#include "TermList.h"
#include "TermNode.h"

//Constructors
TermList::TermList() {
	head = new TermNode(0, 0, nullptr);
}

TermList::~TermList() {
	delete head;
}


// Methods
void TermList::addTerm(int exponent, int coefficient) {
	if (coefficient == 0 || exponent < 0) {
		return;
	}

	TermNode* lastNode = nullptr;
	TermNode* currentNode = head;
	
	while (currentNode != nullptr) {
		PolynomialTerm* nodeData = &(currentNode->data);
		int nodeExponent = nodeData->exponent;

		// Update already existing node
		if (nodeExponent == exponent) {
			int newCoefficientValue = (nodeData->addToCoefficient(coefficient));

			if (newCoefficientValue == 0 && exponent != 0) {
				(lastNode == nullptr ? head : lastNode->nextNode) = currentNode->nextNode;
				currentNode->nextNode = nullptr;
				delete currentNode;
			}
			return;
		}

		// Add new node
		if (nodeExponent < exponent) {
			if (lastNode == nullptr) {
				head = new TermNode(exponent, coefficient, head);
			}
			else {
				lastNode->nextNode = new TermNode(exponent, coefficient, currentNode);
			}

			return;
		}

		lastNode = currentNode;
		currentNode = currentNode->nextNode;
	}
}

std::ostream& operator<<(std::ostream& outStream, const TermList& terms) {
	if (terms.head->data.coefficient == 0 && terms.head->data.exponent == 0) {
		return outStream << "0";
	}

	for (TermNode* currentNode = terms.head; (currentNode != nullptr); currentNode = currentNode->nextNode) { 
		if (currentNode->data.coefficient == 0) {
			continue;
		}
		if (currentNode != terms.head && currentNode->data.coefficient >= 0) {
			outStream << "+";
		}
			outStream << currentNode->data;
	}

	return outStream;
}