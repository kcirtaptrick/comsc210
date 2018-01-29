//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "ArrayQueue.h" // ADT Queue operations
#include "LinkedQueue.h" // ADT Queue operations
#include "ListQueue.h" // ADT Queue operations
#include <iostream>
#include <string>
#include <memory>

void queueTester(std::shared_ptr<QueueInterface<std::string>> queuePtr);
void copyConstructorTester(std::shared_ptr<QueueInterface<std::string>> queuePtr);

int main()
{
   std::shared_ptr<QueueInterface<std::string>> queuePtr;
   bool validUserSelection = false;
   do
   {
      std::cout << "Queue Implementation Test Driver \n";
      std::cout << "Please select on of the following:\n";
      std::cout << "\ta. ArrayQueue Test\n";
      std::cout << "\tb. LinkedQueue Test\n";
      std::cout << "\tc. ListQueue Test\n";
      std::cout << "\tAny other key to exit.\n";
      std::cout << "Your selection: ";
      
      char userSelection = ' ';
      std::cin >> userSelection;
      
      switch (userSelection) {
         case 'a':
            queuePtr = std::make_shared<ArrayQueue<std::string>>();
            validUserSelection = true;
            std::cout << "Testing the Array-based queue:\n";
           break;
         case 'b':
            
            queuePtr = std::make_shared<LinkedQueue<std::string>>();
            validUserSelection = true;
            std::cout << "Testing the Link-based queue:\n";
          break;
            
         case 'c':
            queuePtr = std::make_shared<ListQueue<std::string>>();
            validUserSelection = true;
            std::cout << "Testing the List-based queue:\n";
           break;
            
          default:
            validUserSelection = false;
            break;
      }
      
      if (validUserSelection)
      {
        copyConstructorTester(queuePtr);
        queueTester(queuePtr);
      }
      

   } while(validUserSelection);
   
   std::cout << "Thanks for testing!\n";
   return 0;
}  // end main


void queueTester(std::shared_ptr<QueueInterface<std::string>> queuePtr)
{
   std::string items[] = {"one", "two", "three", "four", "five", "six"};
	std::cout << "Empty: " << queuePtr->isEmpty() << std::endl;
	for (int i = 0; i < 6; i++)
   {
		std::cout<<"Adding " << items[i] << std::endl;
      bool success = queuePtr->enqueue(items[i]);
      if (!success)
         std::cout << "Failed to add " << items[i] << " to the queue." << std::endl;
	}
   
	std::cout << "Empty?: " << queuePtr->isEmpty() << std::endl;
	
	for (int i = 0; i < 6; i++) 
   {
		std::cout << "Loop " << i << std::endl;
      
      try 
      {
         std::cout << "peekFront: " << queuePtr->peekFront() << std::endl;
      } 
      catch (PrecondViolatedExcep e) 
      {
         std::cout << e.what() << std::endl;
      }  // end try/catch

		std::cout << "Empty: " << queuePtr->isEmpty() << std::endl;
		std::cout << "dequeue: " << queuePtr->dequeue() << std::endl;
	}
   
   std::cout << "dequeue with an empty queue: " << std::endl;
	std::cout << "Empty: " << queuePtr->isEmpty() << std::endl;
	std::cout << "dequeue: " << queuePtr->dequeue() << std::endl; // nothing to dequeue!
   
   try 
   {
      std::cout << "peekFront with an empty queue: " << std::endl;
	   std::cout << "peekFront: " << queuePtr->peekFront() << std::endl; // nothing to see!
   } 
   catch (PrecondViolatedExcep e) 
   {
      std::cout << e.what() << std::endl;
   }  // end try/catch
   
}  // end queueTester

void copyConstructorTester(std::shared_ptr<QueueInterface<std::string>> queuePtr)
{
   std::string items[] = {"zero", "one", "two", "three", "four", "five"};
   for (int i = 0; i < 6; i++)
   {
      std::cout << "Adding " << items[i] << std::endl;
      bool success = queuePtr->enqueue(items[i]);
      if (!success)
         std::cout << "Failed to add " << items[i] << " to the queue.\n";
   }
   std::shared_ptr<QueueInterface<std::string>> copyOfQueue(queuePtr);

   std::cout << "Queue contains, from front to back, zero one two three four five.\n";
  
   std::cout << "Original queue contains, from front to back,";
   for (int i = 0; i < 6; i++)
   {
      std::cout << " " << queuePtr->peekFront();
      queuePtr->dequeue();
   }
   std::cout << "." << std::endl << std::endl;
   
   
  std::cout << "Copy of queue contains, from front to back, ";
   for (int i = 0; i < 6; i++)
   {
      try  {
      std::cout << " " << copyOfQueue->peekFront();
      copyOfQueue->dequeue();
      }
      catch (PrecondViolatedExcep e)
      {
         std::cout << e.what() << std::endl;
      }  // end try/catch
   }
   std::cout << "." << std::endl;
   
}  // end copyConstructorTester

/*
 Testing the Array-based queue:
 Empty: 1
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Adding six
 Empty?: 0
 Loop 0
 peekFront: one
 Empty: 0
 dequeue: 1
 Loop 1
 peekFront: two
 Empty: 0
 dequeue: 1
 Loop 2
 peekFront: three
 Empty: 0
 dequeue: 1
 Loop 3
 peekFront: four
 Empty: 0
 dequeue: 1
 Loop 4
 peekFront: five
 Empty: 0
 dequeue: 1
 Loop 5
 peekFront: six
 Empty: 0
 dequeue: 1
 dequeue with an empty queue:
 Empty: 1
 dequeue: 0
 peekFront with an empty queue:
 peekFront: Precondition Violated Exception: peekFront() called with empty queue
 */