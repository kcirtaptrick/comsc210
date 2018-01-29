//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 @file ArrayStack.h */

#ifndef ARRAY_STACK_EXCEPTIONS
#define ARRAY_STACK_EXCEPTIONS

#include "../StackInterface.h"
// #include "PrecondViolatedExcep.h" // for c9, TC
#include "PrecondViolatedExcep.cpp"

const int MAX_STACK = 5;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
	ItemType items[MAX_STACK]; // Array of stack items
	int      top;              // Index to top of stack
	
public:
	 ArrayStack();
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop();
	 ItemType peek() const throw(PrecondViolatedExcep);	
}; // end ArrayStack

#include "ArrayStack.cpp"
#endif
