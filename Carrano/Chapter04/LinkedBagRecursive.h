//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation - RECURSIVE VERSION.
    @file LinkedBagRecursive.h 
    Listing 4-3 */
#ifndef LINKED_BAG_RECURSIVE_
#define LINKED_BAG_RECURSIVE_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBagRecursive : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Fills the vector bagContents with the data in the nodes of
   // the linked chain to which curPtr points.
   void fillVector(std::vector<ItemType>& bagContents, Node<ItemType>* curPtr) const;
   
   // Locates a given entry within this bag.
   // Returns either a pointer to the node containing a given entry or
   // the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target,
                                Node<ItemType>* curPtr) const;
   
   // Counts the frequency of occurrence of a given entry in this bag.
   int countFrequency(const ItemType& anEntry, int counter,
                      Node<ItemType>* curPtr) const;

   // Deallocates all nodes assigned to this bag
   void deallocate(Node<ItemType>* nextNodePtr);
   
public:
   LinkedBagRecursive();
   LinkedBagRecursive(const LinkedBagRecursive<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBagRecursive();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
}; // end LinkedBagRecursive

#include "LinkedBagRecursive.cpp"
#endif