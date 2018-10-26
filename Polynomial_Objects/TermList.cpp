#include "TermList.h"
#include "TermNode.h"

//Constructors
TermList::TermList() {
	termCount = 0;
	head = new TermNode(0, 0, nullptr);
}

TermList::TermList(const TermList& termList) {
	TermList();
	
	for (TermNode* currentNode = termList.getHeadNode(); (currentNode != nullptr); currentNode = currentNode->nextNode) {
		addTerm(currentNode->data);
	}
}

TermList::~TermList() {
	delete head;
}

void TermList::addTerm(PolynomialTerm polynomialTerm) {
	addTerm(polynomialTerm.exponent, polynomialTerm.coefficient);
}

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
			
			if (exponent == 0 && newCoefficientValue == 0) {
				termCount -= 1;
			} else if (exponent == 0 && newCoefficientValue != 0) {
				termCount += 1;
			}

			if (newCoefficientValue == 0 && exponent != 0) {
				(lastNode == nullptr ? head : lastNode->nextNode) = currentNode->nextNode;
				currentNode->nextNode = nullptr;
				termCount -= 1;
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
			termCount += 1;
			return;
		}

		lastNode = currentNode;
		currentNode = currentNode->nextNode;
	}
}

const PolynomialTerm* TermList::toArrayList() const {
	PolynomialTerm* termArray = new PolynomialTerm[termCount];
	int stepper = 0;
	for (TermNode* currentNode = head; (currentNode != nullptr); currentNode = currentNode->nextNode) {
		termArray[stepper] = currentNode->data;
		stepper++;
	}

	return termArray;
}

int TermList::getTermCount() const {
	return termCount;
}

TermNode* TermList::getHeadNode() const {
	return head;
}

std::ostream& operator<<(std::ostream& outStream, const TermList& terms) {
	if (terms.getHeadNode()->data.coefficient == 0 && terms.getHeadNode()->data.exponent == 0) {
		return outStream << "0";
	}

	for (TermNode* currentNode = terms.getHeadNode(); (currentNode != nullptr); currentNode = currentNode->nextNode) {
		if (currentNode->data.coefficient == 0) {
			continue;
		}
		if (currentNode != terms.getHeadNode() && currentNode->data.coefficient >= 0) {
			outStream << "+";
		}
			outStream << currentNode->data;
	}

	return outStream;
}

TermList TermList::operator+(const TermList& termList) {
	TermList newList(*this);
	
	for (TermNode* currentNode = termList.head; (currentNode != nullptr); currentNode = currentNode->nextNode) {
		newList.addTerm(currentNode->data);
	}

	return newList;
}

TermList TermList::operator+(const int& addition) {
	TermList newList(*this);

	newList.addTerm(0, addition);

	return newList;
}

TermList TermList::operator-(const int& subtraction) {
	TermList newList(*this);

	newList.addTerm(0, subtraction * -1);

	return newList;
}

TermList TermList::operator*(const TermList& termList) {
	TermList newList(*this);

	for (TermNode* newListNode = newList.head; (newListNode != nullptr); newListNode = newListNode->nextNode) {
		for (TermNode* termListNode = termList.head; (termListNode != nullptr); termListNode = termListNode->nextNode) {
			newListNode->data *= termListNode->data;
		}
	}

	return newList;
}

TermList TermList::operator*(const int& multiple) {
	TermList newList(*this);

	for (TermNode* currentNode = newList.head; (currentNode != nullptr); currentNode = currentNode->nextNode) {
		currentNode->data * multiple;
	}

	return newList;
}

TermList& TermList::operator+=(const TermList& termList) {
	for (TermNode* currentNode = termList.head; (currentNode != nullptr); currentNode = currentNode->nextNode) {
		addTerm(currentNode->data);
	}

	return *this;
}

TermList& TermList::operator+=(const int& addition) {
	addTerm(0, addition);
	return *this;
}

TermList& TermList::operator-=(const TermList& termList) {
	for (TermNode* currentNode = termList.head; (currentNode != nullptr); currentNode = currentNode->nextNode) {
		addTerm(currentNode->data * -1);
	}

	return *this;
}

TermList& TermList::operator-=(const int& subtraction) {
	addTerm(0, subtraction * -1);
	return *this;
}

TermList& TermList::operator*=(const TermList& termList) {
	for (TermNode* currentNode = head; (currentNode != nullptr); currentNode = currentNode->nextNode) {
		for (TermNode* termListNode = termList.head; (termListNode != nullptr); termListNode = termListNode->nextNode) {
			currentNode->data *= termListNode->data;
		}
	}

	return *this;
}

TermList& TermList::operator*=(const int& multiple) {
	for (TermNode* currentNode = head; (currentNode != nullptr); currentNode = currentNode->nextNode) {
		currentNode->data * multiple;
	}

	return *this;
}