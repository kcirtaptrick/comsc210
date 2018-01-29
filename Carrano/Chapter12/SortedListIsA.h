//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT sorted list using ADT list.
 Listing 12-4.
 @file SortedListIsA.h */

#ifndef _SORTED_LIST_IS_A
#define _SORTED_LIST_IS_A

#include <memory>
#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SortedListIsA : public LinkedList<ItemType>// , public SortedListInterface<ItemType>
{
public:
   SortedListIsA();
   SortedListIsA(const SortedListIsA<ItemType>& sList);
   virtual ~SortedListIsA();

   bool insertSorted(const ItemType& newEntry);
   bool removeSorted(const ItemType& anEntry);
   int getPosition(const ItemType& anEntry) const;
   
   // The inherited methods remove, clear, getEntry, isEmpty, and
   // getLength have the same specifications as given in ListInterface.
/*
   bool remove(int position);
   void clear();
   ItemType getEntry(int position) const throw(PrecondViolatedExcep);
   bool isEmpty() const;
   int getLength() const;
*/
   // The following methods must be overridden to disable their
   // effect on a sorted list:
   bool insert(int newPosition, const ItemType& newEntry) override;
	void replace(int position, const ItemType& newEntry)
                              throw(PrecondViolatedExcep) override;
}; // end SortedListIsA

#include "SortedListIsA.cpp"
#endif 
