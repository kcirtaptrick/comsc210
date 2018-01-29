//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file GoodMemory.h 
    Listing C2-2 */

#include "ToyBox.h"

class GoodMemory
{
private:
   ToyBox<double>* someBoxPtr;
public:
   GoodMemory(); // Default constructor
   virtual ~GoodMemory(); // Destructor
   void fixedLeak(const double& someItem);
}; // end GoodMemory