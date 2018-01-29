//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Iterative version. */
void writeBackward(std::string s)
{
   size_t length = s.size();
   while (length > 0)
   {
      std::cout << s.substr(length - 1, 1);
      length--;
   }  // end while
}  // end writeBackward