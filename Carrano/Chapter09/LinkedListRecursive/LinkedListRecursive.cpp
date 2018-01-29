//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class LinkedListRecursive.
 @file LinkedListRecursive.cpp */

// #include "LinkedListRecursive.h"  // Header file
#include <cassert>
  
template<class ItemType>
LinkedListRecursive<ItemType>::LinkedListRecursive() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

// NB: See LinkedSortedList in Chapter 12 for a recursive version of a copy constructor.
template<class ItemType>
LinkedListRecursive<ItemType>::LinkedListRecursive(const LinkedListRecursive<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedListRecursive<ItemType>::~LinkedListRecursive()
{
   deallocate(headPtr);
   headPtr = nullptr;
   itemCount = 0;
   // OR simply call clear().
}  // end destructor

template<class ItemType>
bool LinkedListRecursive<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedListRecursive<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedListRecursive<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
      headPtr = insertNode(newPosition, newNodePtr, headPtr);
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedListRecursive<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
      headPtr = deleteNode(position, headPtr);
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedListRecursive<ItemType>::clear()
{
   deallocate(headPtr);
   headPtr = nullptr;
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType LinkedListRecursive<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position, headPtr);
      return nodePtr->getItem();
   }
   else
      throw(PrecondViolatedExcep("getEntry() called with an empty list or invalid position."));
}  // end getEntry

template<class ItemType>
void LinkedListRecursive<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position, headPtr);
      nodePtr->setItem(newEntry);
   }
   else
      throw(PrecondViolatedExcep("replace() called with an invalid position."));
}  // end replace

// =======================================================================================
// PRIVATE METHODS:

// RECURSIVE
template<class ItemType> 
Node<ItemType>* LinkedListRecursive<ItemType>::getNodeAt(int position, Node<ItemType>* curPtr) const
{
   assert( (position >= 1) && (position <= itemCount) );
   
   if (position == 1)
      return curPtr;
   else 
      return getNodeAt(position - 1, curPtr->getNext());
}  // end getNodeAt

// RECURSIVE
template<class ItemType> 
Node<ItemType>* LinkedListRecursive<ItemType>::insertNode(int position, Node<ItemType>* newNodePtr, 
                                                 Node<ItemType>* subChainPtr)
{
   if (position == 1)
   {
      // Insert new node at beginning of subchain
      newNodePtr->setNext(subChainPtr); 
      subChainPtr = newNodePtr;
      itemCount++;  // Increase count of entries
   }
   else
   {
      Node<ItemType>* afterPtr = insertNode(position - 1, newNodePtr, subChainPtr->getNext());
      subChainPtr->setNext(afterPtr);
   }  // end if
      
   return subChainPtr;
}  // end insertNode

// RECURSIVE
template<class ItemType>
Node<ItemType>* LinkedListRecursive<ItemType>::deleteNode(int position, Node<ItemType>* curPtr)
{
   if (position == 1)
   {
      // Delete the node and return it to the system
      Node<ItemType>* deleteNodePtr = curPtr;
      curPtr = curPtr->getNext();
      itemCount--;  // Decrease count of entries

      deleteNodePtr->setNext(nullptr);
      delete deleteNodePtr;
      deleteNodePtr = nullptr;
   }
   else
   {
      Node<ItemType>* afterPtr = deleteNode(position - 1, curPtr->getNext());
      curPtr->setNext(afterPtr);
   }  // end if
   
   return curPtr;
}  // end deleteNode

// RECURSIVE
template<class ItemType>
void LinkedListRecursive<ItemType>::deallocate(Node<ItemType>* nextNodePtr)
{
   if (nextNodePtr != nullptr)
   {
      Node<ItemType>* nodeToDeletePtr = nextNodePtr;
      nextNodePtr = nextNodePtr->getNext();
      delete nodeToDeletePtr;
      deallocate(nextNodePtr);
   }  // end if
}  // end deallocate

//  End of implementation file.
