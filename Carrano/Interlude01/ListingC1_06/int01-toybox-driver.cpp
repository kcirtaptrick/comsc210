//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "ToyBox.h"

int main()
{

   std::string favoriteToy = "Jack-in-the-Box";
   ToyBox<std::string> myToyCase(favoriteToy, RED); // A red toy box
   
   std::string oldToy = myToyCase.getItem();        // oldToy is a Jack-in-the-Box
   std::cout << "myToyCase.getItem() = " << oldToy << std::endl;
   
   favoriteToy = "Spinning Top";
   myToyCase.setItem(favoriteToy);             // myToyCase now holds a Spinning Top  
   std::cout << "myToyCase.getItem() = " << myToyCase.getItem() << std::endl;
   
   return 0;
} // end main

/*
 myToyCase.getItem() = Jack-in-the-Box
 myToyCase.getItem() = Spinning Top
*/
