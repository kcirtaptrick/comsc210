//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class SortedListIsA.
 @file SortedListIsA.cpp */

#include "SortedListIsA.h"  // Header file
#include <cassert>
#include <cmath>
 
template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA()
{
}  // end default constructor

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA(const SortedListIsA<ItemType>& sList)
	:LinkedList<ItemType>(sList)
{
}  // end copy constructor

template<class ItemType>
SortedListIsA<ItemType>::~SortedListIsA()
{
}  // end destructor

template<class ItemType>
bool SortedListIsA<ItemType>::insertSorted(const ItemType& newEntry)
{
   int newPosition = std::abs(getPosition(newEntry));
   
   // We need to call the LinkedList version here since the
	// SortedListIsA version does nothing but return false
     LinkedList<ItemType>::insert(newPosition, newEntry);
   // this->insert(newPosition, newEntry); // WRONG as it calls the overriding version
   return true;
}  // end insertSorted

template<class ItemType>
bool SortedListIsA<ItemType>::removeSorted(const ItemType& anEntry)
{
   int position = getPosition(anEntry);
   bool ableToRemove = position > 0;

   if (ableToRemove)
   {
      ableToRemove = LinkedList<ItemType>::remove(position);
   }  // end if

   return ableToRemove;
}  // end removeSorted

template<class ItemType>
int SortedListIsA<ItemType>::getPosition(const ItemType& anEntry) const
{
   int position = 1;
   int length = LinkedList<ItemType>::getLength();
   
   while ( (position <= length) && 
           (anEntry > LinkedList<ItemType>::getEntry(position)) )
   {
      position++;
   }  // end while
   
   if ( (position > length) || 
        (anEntry != LinkedList<ItemType>::getEntry(position)) )
   {
      position = -position;
   }  // end if
   
   return position;
}  // end getPosition

template<class ItemType>
bool SortedListIsA<ItemType>::insert(int newPosition, const ItemType& newEntry)
{ 
	return false;
} // end insert

template<class ItemType>
void SortedListIsA<ItemType>::replace(int position, const ItemType& newEntry)  throw(PrecondViolatedExcep)
{ 
	throw PrecondViolatedExcep("This is an illegal action!"); 
} // end replace

//  End of implementation file.
