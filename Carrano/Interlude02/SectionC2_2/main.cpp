//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Section C2.2

#include <iostream>
#include <string>
#include "PlainBox.h"
#include "MagicBox.h"


void placeInBox(PlainBox<std::string>& theBox, std::string theItem)
{
   theBox.setItem(theItem);
} // end placeInBox

int main()
{
   std::string specialItem = "Riches beyond compare!";
   std::string otherItem = "Hammer";
   
   PlainBox<std::string> myPlainBox;
   placeInBox(myPlainBox, specialItem);
   
   MagicBox<std::string> myMagicBox;
   placeInBox(myMagicBox, otherItem);
   placeInBox(myMagicBox, specialItem);     // specialItem is stored!
   
   std::cout << myMagicBox.getItem() << std::endl;    // "Riches beyond compare!"
   
   PlainBox<std::string> mySpecialBox = MagicBox<std::string>();
   mySpecialBox.setItem(otherItem);
   mySpecialBox.setItem(specialItem);      // specialItem is stored!
   std::cout << mySpecialBox.getItem() << std::endl; // "Riches beyond compare!"
   
   return 0;
}  // end main

/*
 Riches beyond compare!
 Riches beyond compare!

*/
