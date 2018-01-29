//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Link-based implementation.
    Listing 7-x.  
    @file LinkedStack.h */

#ifndef LINKED_STACK_EXCEPTIONS
#define LINKED_STACK_EXCEPTIONS

#include "../StackInterface.h"
#include "../Node.h"
#include "PrecondViolatedExcep.h"

/** ADT stack - Linked implementation. */

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
	
private:
	Node<ItemType>* topPtr; // Pointer to first node in the chain;
                           // this node contains the stack's top

public:
// Constructors and destructor:
	LinkedStack();                                     // Default constructor
	LinkedStack(const LinkedStack<ItemType>& aStack);  // Copy constructor
	virtual ~LinkedStack();                            // Destructor
	
// Stack operations:
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();

   /** @throw PrecondViolatedExcep if the stack is empty */
	ItemType peek() const throw(PrecondViolatedExcep);
}; // end LinkedStack

#endif

