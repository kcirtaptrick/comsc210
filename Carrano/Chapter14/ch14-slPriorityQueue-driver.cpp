//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include <memory>
#include "SL_PriorityQueue.h" // ADT Priority Queue operations

void copyConstructorTester();
std::unique_ptr<PriorityQueueInterface<std::string>> pqTester(std::unique_ptr<PriorityQueueInterface<std::string>> pqPtr);


int main()
{
   std::cout << "Testing the priority queue:" <<std::endl;
   copyConstructorTester();
   
   std::unique_ptr<PriorityQueueInterface<std::string>> pqPtr = std::make_unique<SL_PriorityQueue<std::string>>();
   // Use the following if using C++11:
   // std::unique_ptr<PriorityQueueInterface<std::string>> pqPtr(new SL_PriorityQueue<std::string>());

   pqPtr = pqTester(move(pqPtr));
   
   return 0;
}  // end main

void copyConstructorTester()
{
	SL_PriorityQueue<std::string> queue;
   std::string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; i++)
   {
		std::cout << "Adding " << items[i] << std::endl;
      bool success = queue.enqueue(items[i]);
      if (!success)
         std::cout << "Failed to add " << items[i] << " to the queue." << std::endl;
	}
   std::cout << "Queue contains, from front to back, zero two three one four five." << std::endl;
   
   SL_PriorityQueue<std::string> copyOfQueue(queue);
   std::cout << "Copy of queue contains, from front to back, ";
	for (int i = 0; i < 6; i++)
   {
      std::cout << " " << copyOfQueue.peek();
      copyOfQueue.dequeue();
   }
   std::cout << "." << std::endl;
   
   std::cout << "Original queue contains, from front to back,";
	for (int i = 0; i < 6; i++)
   {
      std::cout << " " << queue.peek();
      queue.dequeue();
   }
   std::cout << "." << std::endl << std::endl;
   
}  // end copyConstructorTester


std::unique_ptr<PriorityQueueInterface<std::string>> pqTester(std::unique_ptr<PriorityQueueInterface<std::string>> pqPtr)
{
	std::string items[] = {"one", "two", "three", "four", "five", "six"};
	std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
	for (int i = 0; i < 6; i++)
   {
		std::cout<<"Adding " << items[i] << std::endl;
      bool success = pqPtr->enqueue(items[i]);
      if (!success)
         std::cout << "Failed to add " << items[i] << " to the priority queue." << std::endl;
	}  // end for
   
	std::cout << "Empty?: " << pqPtr->isEmpty() << std::endl;
	
	for (int i = 0; i < 6; i++)
   {
		std::cout << "Loop " << i << std::endl;
      
      try
      {
         std::cout << "peek: " << pqPtr->peek() << std::endl;
      }
      catch (PrecondViolatedExcep e)
      {
         std::cout << e.what() << std::endl;
      }  // end try/catch
      
		std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
		std::cout << "Remove: " << pqPtr->dequeue() << std::endl;
	}  // end for
   
   std::cout << "remove with an empty priority queue: " << std::endl;
	std::cout << "Empty: " << pqPtr->isEmpty() << std::endl;
	std::cout << "remove: " << pqPtr->dequeue() << std::endl; // nothing to remove!
   
   try
   {
      std::cout << "peek with an empty priority queue: " << std::endl;
	   std::cout << "peek: " << pqPtr->peek() << std::endl; // nothing to see!
   }
   catch (PrecondViolatedExcep e)
   {
      std::cout << e.what() << std::endl;;
   }  // end try/catch
   return pqPtr;

} // end pqTester



/*
 Adding zero
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Queue contains, from front to back, zero two three one four five.
 Copy of queue contains, from front to back,  zero two three one four five.
 Original queue contains, from front to back, zero two three one four five.
 
 Testing the priority queue:
 Empty: 1
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Adding six
 Empty?: 0
 Loop 0
 peek: two
 Empty: 0
 Remove: 1
 Loop 1
 peek: three
 Empty: 0
 Remove: 1
 Loop 2
 peek: six
 Empty: 0
 Remove: 1
 Loop 3
 peek: one
 Empty: 0
 Remove: 1
 Loop 4
 peek: four
 Empty: 0
 Remove: 1
 Loop 5
 peek: five
 Empty: 0
 Remove: 1
 remove with an empty priority queue:
 Empty: 1
 remove: 0
 peek with an empty priority queue:
 peek: Precondition Violated Exception: peekFront() called with empty queue.

*/
