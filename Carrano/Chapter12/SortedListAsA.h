//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT sorted list using ADT list.
 Listing 12-5.
 @file SortedListAsA.h */

#ifndef _SORTED_LIST_AS_A
#define _SORTED_LIST_AS_A

#include <memory>
#include "SortedListInterface.h"
#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SortedListAsA : public SortedListInterface<ItemType>, private LinkedList<ItemType>
{
public:
   SortedListAsA();
   SortedListAsA(const SortedListAsA<ItemType>& sList);
   virtual ~SortedListAsA();

   bool insertSorted(const ItemType& newEntry) override;
   bool removeSorted(const ItemType& anEntry) override;
   int getPosition(const ItemType& newEntry) const override;
   
   // The following methods are inherited and have the same 
   // specifications as given in ListInterface:
   bool isEmpty() const override;
   int getLength() const override;
   bool remove(int position) override;
   void clear() override;
   ItemType getEntry(int position) const throw(PrecondViolatedExcep) override;
}; // end SortedListAsA

#include "SortedListAsA.cpp"
#endif 
