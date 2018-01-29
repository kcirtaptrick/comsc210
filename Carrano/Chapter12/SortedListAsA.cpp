//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class SortedListAsA.
 @file SortedListAsA.cpp */

#include "SortedListAsA.h"  // Header file
#include <cassert>
#include <cmath>
  
template<class ItemType>
SortedListAsA<ItemType>::SortedListAsA()
{
}  // end default constructor

template<class ItemType>
SortedListAsA<ItemType>::SortedListAsA(const SortedListAsA<ItemType>& sList)
		:LinkedList<ItemType>(static_cast<LinkedList<ItemType>>(sList))
{
	
}  // end copy constructor

template<class ItemType>
SortedListAsA<ItemType>::~SortedListAsA()
{
    clear();
}  // end destructor

template<class ItemType>
bool SortedListAsA<ItemType>::insertSorted(const ItemType& newEntry)
{
   int newPosition = abs(getPosition(newEntry));
   return LinkedList<ItemType>::insert(newPosition, newEntry);
}  // end insertSorted

template<class ItemType>
bool SortedListAsA<ItemType>::removeSorted(const ItemType& anEntry)
{
   bool ableToDelete = false;
   // if (!this->isEmpty())
   if (!LinkedList<ItemType>::isEmpty())
   {
      int position = getPosition(anEntry);
             
      ableToDelete = position > 0;
      if (ableToDelete)
      {
         ableToDelete = LinkedList<ItemType>::remove(position);
//       ableToDelete = this->remove(position);
      }  // end if
   }  // end if

   return ableToDelete;
}  // end removeSorted

template<class ItemType>
int SortedListAsA<ItemType>::getPosition(const ItemType& anEntry) const
{
   int position = 1;
   int length = LinkedList<ItemType>::getLength();
   // int length = this->getLength();
   
   // while ( (position <= length) && (anEntry > this->getEntry(position)) )
   while ( (position <= length) && 
          (anEntry > LinkedList<ItemType>::getEntry(position)) )
   {
      position++;
   }  // end while
   
   // if ( (position > length) || (anEntry != this->getEntry(position)) )
   if ( (position > length) || 
       (anEntry != LinkedList<ItemType>::getEntry(position)) )
   {
      position = -position;
   }  // end if
   
   return position;
}  // end getPosition

//=====================
// List operations:
template<class ItemType>
void SortedListAsA<ItemType>::clear()
{
    LinkedList<ItemType>::clear();
}  // end clear


template<class ItemType>
bool SortedListAsA<ItemType>::isEmpty() const
{
    return LinkedList<ItemType>::isEmpty();
}  // end isEmpty

template<class ItemType>
int SortedListAsA<ItemType>::getLength() const
{
    return LinkedList<ItemType>::getLength();
}  // end getLength

template<class ItemType>
bool SortedListAsA<ItemType>::remove(int position)
{
    return LinkedList<ItemType>::remove(position);
}

template<class ItemType>
ItemType SortedListAsA<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    return LinkedList<ItemType>::getEntry(position);
}
