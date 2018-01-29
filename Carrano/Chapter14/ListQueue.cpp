//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT queue: ADT list implementation.
 Listing 14-2.
 @file ListQueue.cpp */

#include <memory>
#include "ListQueue.h"  // header file

template<class ItemType>
ListQueue<ItemType>::ListQueue()
   : listPtr(std::make_unique<LinkedList<ItemType>>())
{     }  // end default constructor

template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue)
                        : listPtr(aQueue.aList)
//: listPtr(std::make_unique<LinkedList<ItemType>>())
{
//	// Add items to default constructed list using public methods
//	for(int position = 1; position <= aQueue.listPtr->getLength(); position++)
//	{
//		listPtr->insert(position, aQueue.listPtr->getEntry(position));
//	}  // end for
}  // end copy constructor

template<class ItemType>
ListQueue<ItemType>::~ListQueue()
{
}  // end destructor

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const
{
   return listPtr->isEmpty();
}  // end isEmpty

template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   return listPtr->insert(listPtr->getLength() + 1, newEntry);
}  // end enqueue

template<class ItemType>
bool ListQueue<ItemType>::dequeue()
{
   return listPtr->remove(1);
}  // end dequeue

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("peekFront() called with empty queue.");

   // Queue is not empty; return front
   return listPtr->getEntry(1);
}  // end peekFront
// End of implementation file.
