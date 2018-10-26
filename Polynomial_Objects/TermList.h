#pragma once
#include "TermNode.h"

/*!
	Class storing logic for creating a linked list out of TermNodes.
	This class stores the head node for the start of the list.

	Head = Highest exponent
	Tail = Exponent 0
 
	When the term list is created, it is initialised with a term of coefficient 0 and exponent 0.
	There is always a sentinel value of exponent 0 at the end of the list.
 */
class TermList {
private:
	int termCount;
	TermNode* head;

public:
	// Constructors
	TermList();
	TermList(const TermList& termList);
	~TermList();
	
	//! Adds the provided term to the current linked list structure.
	//! If the newly added value results in the coefficient of the
	//! given exponent to be 0, this node will be deleted.
	/*!
	  \param polynomialTerm The representation of the term to be added to this Polynomial.
	*/
	void addTerm(PolynomialTerm polynomialTerm);

	//! Adds the provided term to the current linked list structure.
	//! If the newly added value results in the coefficient of the
	//! given exponent to be 0, this node will be deleted.
	/*!
	  \param coefficient The coefficient for the new term to be added.
	  \param exponent The exponent for the new term to be added.
	*/
	void addTerm(int exponent, int coefficient);

	//! Generates a new array of PolynomialTerms on the heap from the
	//! current state of the linked list.
	//! It is recommended that you do this when you dont plan on adding
	//! more terms to the polynomial for faster iteration.
	//! The array will be sorted from the highest exponent to x^0.
	//! An element for x^0 will always be present even if it's coefficient is 0.
	/*!
	  \return Pointer to the largest exponent term in the PolynomialTerm Array
	*/
	const PolynomialTerm* toArrayList() const;

	//! Returns the amount of terms that exist in the linked list
	/*!
	  \return The amount of terms in the linked list
	*/
	int getTermCount() const;

	//! Returns the pointer to the first node in the linked list.
	//! The head node will always be the highest exponent.
	//! If the linked list is empty, this will retrn a node contining 0x^0
	/*!
	  \return The pointer to the first node in the linked list.
	*/
	TermNode* getHeadNode() const;

	// Operator Overloads
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