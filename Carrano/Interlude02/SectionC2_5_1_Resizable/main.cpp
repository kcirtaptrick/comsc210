//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArrayBag.h"

void displayBag(ArrayBag<std::string>& bag)
{
	std::cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << std::endl;
    std::vector<std::string> bagItems = bag.toVector();
   
    int numberOfEntries = (int) bagItems.size();
    for (int i = 0; i < numberOfEntries; i++)
    {
        std::cout << bagItems[i] << " ";
    }  // end for
	std::cout << std::endl << std::endl;
}  // end displayBag

int main()
{
	ArrayBag<std::string> bag;
	std::string items[] = {"one", "two", "three", "four", "five", "six"};
    std::cout << "Add 6 items to the bag: " << std::endl;
	for (int i = 0; i < 6; i++)
    {
		bag.add(items[i]);
	}  // end for
   
    displayBag(bag);
   
    // Bag needs to resize at next addition
    bag.add("seven");
    bag.add("eight");
    displayBag(bag);
   
    return 0;
}  // end main

/*
 Add 6 items to the bag:
 The bag contains 6 items:
 one two three four five six
 
 The bag contains 8 items:
 one two three four five six seven eight  */