//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "MagicBox.h"

int main()
{

   std::string rabbit = "Rabbit";
   std::string wand = "Wand";
   
   MagicBox<std::string> magicHat;
   magicHat.setItem(rabbit);
   std::cout << "magicHat.getItem() = " << magicHat.getItem() << std::endl;
   
   magicHat.setItem(wand);
   // magicHat still holds the rabbit
   std::cout << "magicHat.getItem() = " << magicHat.getItem() << std::endl;
   
   return 0;
} // end main

/*
 magicHat.getItem() = Rabbit
 magicHat.getItem() = Rabbit
*/
