//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "SortedListIsA.h" // ADT sorted list operations

void displayList(std::shared_ptr<SortedListIsA<std::string>> listPtr)
{
	std::cout << "The sorted list contains " << std::endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      std::cout << listPtr->getEntry(pos) << " ";
   } // end for
	std::cout << std::endl << std::endl;
}  // end displayList

void copyConstructorTester()
{
   auto list = std::make_shared<SortedListIsA <std::string>>();
   std::string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; i++)
   {
		std::cout << "Adding " << items[i] << std::endl;
      list->insertSorted(items[i]);
	}
    displayList(list);
   
   auto copyOfList(list);
   std::cout << "Copy of list: ";
   displayList(copyOfList);
   
   std::cout << "The copied list: ";
   displayList(list);
}  // end copyConstructorTester

void sortedListTester(std::shared_ptr<SortedListIsA<std::string>> listPtr)
{
   std::string luke = "Luke";
   std::string brent = "Brent";
   std::string donna = "Donna";
   std::string tom = "Tom";
   std::string sue = "Sue";
   std::string jerry = "Jerry";
   
   std::cout << "\nTest isEmpty with an empty list:" << std::endl;
   if (listPtr->isEmpty())
      std::cout << "OK" << std::endl;
   else
      std::cout << "isEmpty() error" << std::endl;
	
   listPtr->insertSorted(luke);
   listPtr->insertSorted(brent);
   listPtr->insertSorted(donna);
   listPtr->insertSorted(tom);
   listPtr->insertSorted(sue);
   listPtr->insertSorted(jerry);
   
   // display the list
   std::cout << "List should contain\nBrent, Donna, " <<
   "Jerry, Luke, Sue, Tom" << std::endl;
   std::cout << "\nList actually contains:" << std::endl;
   displayList(listPtr);
   std::cout << std::endl;
   
   // test getPosition
   std::cout << "\nTest getPosition:\n" << std::endl;
   
   // These names are in the list
   std::cout << "Brent is at position " << listPtr->getPosition(brent) << std::endl;
   std::cout << "Donna is at position " << listPtr->getPosition(donna) << std::endl;
   std::cout << "Jerry is at position " << listPtr->getPosition(jerry) << std::endl;
   std::cout << "Luke is at position "  << listPtr->getPosition(luke) << std::endl;
   std::cout << "Sue is at position "   << listPtr->getPosition(sue) << std::endl;
   std::cout << "Tom is at position "   << listPtr->getPosition(tom) << std::endl;
   
   // These names are not in the list
   std::string missy = "Missy";
   std::cout << "Missy belongs at position " << listPtr->getPosition(missy) << std::endl;
   std::string zeke = "Zeke";
   std::cout << "Zeke belongs at position " << listPtr->getPosition(zeke) << std::endl;
   std::string aaron = "Aaron";
   std::cout << "Aaron belongs at position " << listPtr->getPosition(aaron) << std::endl;
   
   // test getLength and getEntry
   std::cout << "\nTest getLength and getEntry:\n" << std::endl;
   
   std::cout << "\nList has " << listPtr->getLength() << " entries, as follows:\n" << std::endl;
   for (int i = 1; i <= listPtr->getLength(); i++)
      std::cout << i << ": " << listPtr->getEntry(i) << std::endl;
   
   
   // test remove
   std::cout << "\nTest remove:\n" << std::endl;
   
   // remove first entry
   std::cout << "\nRemoving first item (Brent): " << listPtr->removeSorted(brent) << "; should be 1 (true)" << std::endl;
   std::cout << "\nAfter removing Brent, list contains " << listPtr->getLength()
   << " items, as follows:" << std::endl;
   displayList(listPtr);
   
   // remove interior
   std::cout << "\nRemoving interior item (Luke): " << listPtr->removeSorted(luke) << "; should be 1 (true)" << std::endl;
   std::cout << "\nAfter removing Luke, list contains " << listPtr->getLength()
   << " items, as follows:" << std::endl;
   displayList(listPtr);
   
   // remove last
   std::cout << &"\nRemoving last item (Tom): " [ listPtr->removeSorted(tom)] << "; should be 1 (true)" << std::endl;
   std::cout << "\nAfter removing last item, list contains " << listPtr->getLength()
   << " items, as follows:" << std::endl;
   displayList(listPtr);
   
   std::cout << "\nRemoving a missing item (Brent): " << listPtr->removeSorted(brent) << "; should be 0 (false)" << std::endl;
   std::cout << "\nRemoving a missing item (Luke): " << listPtr->removeSorted(luke) << "; should be 0 (false)" << std::endl;
   std::cout << "\nRemoving a missing item (Tom): " << listPtr->removeSorted(tom) << "; should be 0 (false)" << std::endl;
   
   std::cout << "\nThe list contains " << listPtr->getLength()
   << " items, as follows:" << std::endl;
   displayList(listPtr);
   
   // test clear()
   std::cout << "\nTest clear():\n" << std::endl;
   listPtr->clear();
   
   if (listPtr->isEmpty())
      std::cout << "\nThe list is empty after invoking clear()." << std::endl;
   else
      std::cout << "\nclear() error" << std::endl;
} // end sortedListTester

void listOpsTester(std::shared_ptr<SortedListIsA<std::string>> listPtr)
{
   std::string luke = "Luke";
   std::string brent = "Brent";
   std::string donna = "Donna";
   std::string tom = "Tom";
   std::string sue = "Sue";
   std::string jerry = "Jerry";
   
   listPtr->insertSorted(luke);
   listPtr->insertSorted(brent);
   listPtr->insertSorted(donna);
   listPtr->insertSorted(tom);
   listPtr->insertSorted(sue);
   listPtr->insertSorted(jerry);
   
   displayList(listPtr);
   
   std::cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << std::endl;
   std::cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << std::endl;
   
   std::cout << "remove(2): returns " << listPtr->remove(2) << "; should be 1 (true)" << std::endl;
   std::cout << "remove(1): returns " << listPtr->remove(1) << "; should be 1 (true)" << std::endl;
   std::cout << "remove(6): returns " << listPtr->remove(6) << "; should be 0 (false)" << std::endl;
   displayList(listPtr);
   std::cout << "getLength returns : " << listPtr->getLength() << "; should be 4" << std::endl;
   std::cout << "clear: " << std::endl;
   listPtr->clear();
   std::cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << std::endl;
   
   try
   {
      std::cout << "Attempt an illegal retrieval from position 6: " << std::endl;
      listPtr->getEntry(6);
   }
   catch(PrecondViolatedExcep e)
   {
      std::cout << e.what() << std::endl;
   }  // end try/catch
} // end listOpsTester

int main()
{
   copyConstructorTester();

   auto listPtr = std::make_shared<SortedListIsA<std::string>>();
	std::cout << "Testing the Link-Based Sorted List:" << std::endl;
	sortedListTester(listPtr);
   std::cout << "======================================" << std::endl;
   
	std::cout << "\nTesting the List Operations:" << std::endl;
	listOpsTester(listPtr);

   return 0;
}  // end main

/*
 Adding zero
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 The sorted list contains
 five four one three two zero
 
 Copy of list: The sorted list contains
 five four one three two zero
 
 The copied list: The sorted list contains
 five four one three two zero
 
 Testing the Link-Based Sorted List:
 
 Test isEmpty with an empty list:
 OK
 List should contain
 Brent, Donna, Jerry, Luke, Sue, Tom
 
 List actually contains:
 The sorted list contains
 Brent Donna Jerry Luke Sue Tom
 
 
 
 Test getPosition:
 
 Brent is at position 1
 Donna is at position 2
 Jerry is at position 3
 Luke is at position 4
 Sue is at position 5
 Tom is at position 6
 Missy belongs at position -5
 Zeke belongs at position -7
 Aaron belongs at position -1
 
 Test getLength and getEntry:
 
 
 List has 6 entries, as follows:
 
 1: Brent
 2: Donna
 3: Jerry
 4: Luke
 5: Sue
 6: Tom
 
 Test remove:
 
 
 Removing first item (Brent): 1; should be 1 (true)
 
 After removing Brent, list contains 5 items, as follows:
 The sorted list contains
 Donna Jerry Luke Sue Tom
 
 
 Removing interior item (Luke): 1; should be 1 (true)
 
 After removing Luke, list contains 4 items, as follows:
 The sorted list contains
 Donna Jerry Sue Tom
 
 Removing last item (Tom): ; should be 1 (true)
 
 After removing last item, list contains 3 items, as follows:
 The sorted list contains
 Donna Jerry Sue
 
 
 Removing a missing item (Brent): 0; should be 0 (false)
 
 Removing a missing item (Luke): 0; should be 0 (false)
 
 Removing a missing item (Tom): 0; should be 0 (false)
 
 The list contains 3 items, as follows:
 The sorted list contains
 Donna Jerry Sue
 
 
 Test clear():
 
 
 The list is empty after invoking clear().
 ======================================
 
 Testing the List Operations:
 The sorted list contains
 Brent Donna Jerry Luke Sue Tom
 
 isEmpty: returns 0; should be 0 (false)
 getLength returns : 6; should be 6
 remove(2): returns 1; should be 1 (true)
 remove(1): returns 1; should be 1 (true)
 remove(6): returns 0; should be 0 (false)
 The sorted list contains
 Jerry Luke Sue Tom
 
 getLength returns : 4; should be 4
 clear:
 isEmpty: returns 1; should be 1 (true)
 Attempt an illegal retrieval from position 6:
 Precondition Violated Exception: getEntry() called with an empty list or invalid position.


*/
