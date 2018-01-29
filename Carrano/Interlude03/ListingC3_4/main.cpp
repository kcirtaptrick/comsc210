//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <exception>
#include <string>
#include <iostream>
#include "PlainBox.h"

class logic_error // : public exception 
{
   std::string reason;
public:
   explicit logic_error (const std::string& what_arg)
      {reason = what_arg;}
   std::string what() { return reason; };
};

// Listing C3-3
PlainBox<std::string> findBox(PlainBox<std::string> boxes[], int size,
      std::string target) throw(logic_error)
{
   int index = 0;
   bool found = false;
   while (!found && (index < size))
   {
      found = (target == boxes[index].getItem());
      if(!found)
         index++;
   }  // end while
   
   if (!found)
      throw logic_error("Target not found in a box!");
   return boxes[index];
} // end findBox

int main()
{
   // Listing C3-4
   // Create and initialize an array of boxes
   PlainBox<std::string> myBoxes[5]; // Array of PlainBox objects
   myBoxes[0] = PlainBox<std::string>("ring");
   myBoxes[1] = PlainBox<std::string>("hat");
   myBoxes[2] = PlainBox<std::string>("shirt");
   myBoxes[3] = PlainBox<std::string>("sock");
   myBoxes[4] = PlainBox<std::string>("shoe");
   PlainBox<std::string> foundBox;
   
   // Try to find a box containing glasses
   try
   {
      foundBox = findBox(myBoxes, 5, "glasses");
   }
   catch(logic_error logErr)
   {
      std::cout << logErr.what() << std::endl;          // Display error message to user
      foundBox = PlainBox<std::string>("nothing"); // Fix problem
   } // end try-catch
     // Because we catch the exception and fix the problem, the following
     // statement should work even if the target is not found
   std::cout << foundBox.getItem();
   
   return 0;
}
/*
 Target not found in a box!
 nothing
 */
