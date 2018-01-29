//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** Listing C1-9.
 @file BoxInterface.h */

#include "../ListingC1_04/PlainBox.h"

#ifndef BOX_INTERFACE_
#define BOX_INTERFACE_

template <class ItemType>
class BoxInterface
{
public:
   virtual void setItem(const ItemType& theItem) = 0;
   virtual ItemType getItem() const = 0;
   // virtual ~BoxInterface() = { }
}; // end BoxInterface

#endif