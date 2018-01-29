//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
/** Searches the array anArray[first] through anArray[last]
 for a given value by using a binary search.
 @pre  0 <= first, last <= SIZE - 1, where SIZE is the
 maximum size of the array, and anArray[first] <=
 anArray[first + 1] <= ... <= anArray[last].
 @post  anArray is unchanged and either anArray[index] contains
 the given value or index == -1.
 @param anArray  The array to search.
 @param first  The low index to start searching from.
 @param last  The high index to stop searching at.
 @param target  The search key.
 @return  Either index, such that anArray[index] == target, or -1.
 */
int binarySearch(const int anArray[], int first, int last, int target)
{
   int index;
   if (first > last)
      index = -1; // target not in original array
   else
   {
      // If target is in anArray,
      // anArray[first] <= target <= anArray[last]
      int mid = first + (last - first) / 2;
      if (target == anArray[mid])
         index = mid; // target found at anArray[mid]
      else if (target < anArray[mid])
         // Point X
         index = binarySearch(anArray, first, mid - 1, target);
      else
         // Point Y
         index = binarySearch(anArray, mid + 1, last, target);
   }  // end if
   
   return index;
}  // end binarySearch

/** Computes the factorial of the nonnegative integer n.
 @pre  n must be greater than or equal to 0.
 @post  None.
 @return  The factorial of n; n is unchanged. */
int fact(int n)
{
   if (n == 0)
      return 1;
   else // n > 0, so n-1 >= 0. Thus, fact(n-1) returns (n-1)!
      return n * fact(n - 1); // n * (n-1)! is n!
}  // end fact

/** Computes the number of groups of k out of n things.
 @pre  n and k are nonnegative integers.
 @post  None.
 @param n  The given number of things.
 @param k  The given number to choose.
 @return  g(n, k). */
int getNumberOfGroups(int n, int k)
{
   if ( (k == 0) || (k == n) )
      return 1;
   else if (k > n)
      return 0;
   else
      return getNumberOfGroups(n - 1, k - 1) + getNumberOfGroups(n - 1, k);
}  // end getNumberOfGroups

/** Iterative solution to the rabbit problem. */
int iterativeRabbit(int n)
{
   // Initialize base cases:
   int previous = 1; // Initially rabbit(1)
   int current = 1;  // Initially rabbit(2)
   int next = 1;     // Result when n is 1 or 2
   
   // Compute next rabbit values when n >= 3
   for (int i = 3; i <= n; i++)
   {
      // current is rabbit(i - 1), previous is rabbit(i - 2)
      next = current + previous;   // rabbit(i)
      previous = current;          // Get ready for next iteration
      current = next;
   }  // end for
   
   return next;
}  // end iterativeRabbit

/** Computes a term in the Fibonacci sequence.
 @pre n  is a positive integer.
 @post  None.
 @param n  The given integer.
 @return  The nth Fibonacci number. */
int rabbit(int n)
{
   if (n <= 2)
      return 1;
   else // n > 2, so n - 1 > 0 and n - 2 > 0
      return rabbit(n - 1) + rabbit(n - 2);
}  // end rabbit

void solveTowers(int count, char source, char destination, char spare)
{
   if (count == 1)
   {
      std::cout << "Move top disk from pole " << source
      << " to pole " << destination << std::endl;
   }
   else
   {
      solveTowers(count - 1, source, spare, destination); // X
      solveTowers(1, source, destination, spare);         // Y
      solveTowers(count - 1, spare, destination, source); // Z
   }  // end if
}  // end solveTowers

/** Writes the characters in an array backward.
 @pre  The array anArray contains size characters, where size >= 0.
 @post  None.
 @param anArray  The array to write backward.
 @param first  The index of the first character in the array.
 @param last  The index of the last character in the array. */
void writeArrayBackward(const char anArray[], int first, int last)
{
   if (first <= last)
   {
      // Write the last character
      std::cout << anArray[last];
      
      // Write the rest of the array backward
      writeArrayBackward(anArray, first, last - 1);
   }  // end if
   
   // first > last is the base case - do nothing
}  // end writeArrayBackward

/** Writes a character string backward.
 @pre  The string s to write backward.
 @post  None.
 @param s  The string to write backward. */
void writeBackward(std::string s)
{
   int length = (int)s.size(); // Length of string
   if (length > 0)
   {
      // Write the last character
      std::cout << s.substr(length - 1, 1);
      
      // Write the rest of the string backward
      writeBackward(s.substr(0, length - 1)); // Point A
   } // end if
   
   // length == 0 is the base case - do nothing
}  // end writeBackward

/** Iterative version. */
void writeBackwardIterative(std::string s)
{
   int length = (int)s.size();
   while (length > 0)
   {
      std::cout << s.substr(length - 1, 1);
      length--;
   }  // end while
}  // end writeBackwardIterative

// QUESTIONS:
/** Computes the sum of the integers from 1 through n.
 @pre  n > 0.
 @post  None.
 @param n  A positive integer.
 @return  The sum 1 + 2 + . . . + n. */
int sumUpTo(int n)
{
   int sum = 0;
   if (n == 1)
      sum = 1;
   else // n > 1
      sum = n + sumUpTo(n - 1);
   return sum;
}  // end sumUpTo

// EXERCISES:
int getNumberEqual(const int x[], int n, int desiredValue)
{
   int count = 0;
   
   if (n <= 0)
      return 0;
   else
   {
      if (x[n - 1] == desiredValue)
         count = 1;
      
      return getNumberEqual(x, n - 1, desiredValue) + count;
   }  // end else
}  // end getNumberEqual

int getValue(int a, int b, int n)
{
   int returnValue = 0;
   
   std::cout << "Enter: a = " << a << " b = " << b << std::endl;
   int c = (a + b)/2;
   if (c * c <= n)
      returnValue = c;
   else
      returnValue = getValue(a, c-1, n);
   
   std::cout << "Leave: a = " << a << " b = " << b << std::endl;
   
   return returnValue;
}  // end getValue

int search(int first, int last, int n)
{
   int returnValue = 0;
   std::cout << "Enter: first = " << first << " last = "
   << last << std::endl;
   
   int mid = (first + last)/2;
   if ( (mid * mid <= n) && (n < (mid+1) * (mid+1)) )
      returnValue = mid;
   else if (mid * mid > n)
      returnValue = search(first, mid-1, n);
   else
      returnValue = search(mid+1, last, n);
   
   std::cout << "Leave: first = " << first << " last = "
   << last << std::endl;
   return returnValue;
}  // end search

int mystery(int n)
{
   return search(1, n, n);
}  // end mystery

void displayOctal(int n)
{
   if (n > 0)
   {
      if (n / 8 > 0)
         displayOctal(n / 8);
      std::cout << n % 8;
   }  // end if
}  // end displayOctal

/** @pre n >= 0. */
int f(int n)
{
   std::cout << "Function entered with n = " << n << std::endl;
   switch (n)
   {
      case 0: case 1: case 2:
         return n + 1;
      default:
         return f(n-2) * f(n-4);
   }  // end switch
}  // end f

void recurse(int x, int y)
{
   if (y > 0)
   {
      x++;
      y--;
      std::cout << x << " " << y << std::endl;
      recurse(x, y);
      std::cout << x << " " << y << std::endl;
   }  // end if
}  // end recurse

void recurseRef(int& x, int y)
{
   if (y > 0)
   {
      x++;
      y--;
      std::cout << x << " " << y << std::endl;
      recurseRef(x, y);
      std::cout << x << " " << y << std::endl;
   }  // end if
}  // end recurseRef

int gcd(int a, int b)
{
   if (a % b == 0) // Base case
      return b;
   else
      return gcd(b, a % b);
}  // end gcd



int main()
{
   using std::cout;
   using std::endl;
   
   int searchArray[] = {1, 5, 9, 12, 15, 21, 29, 31};
   cout << "Searching for 9: binarySearch returns "
        << binarySearch(searchArray, 0, 7, 9) << "; should be 2" << endl;
   
   cout << "Searching for 6: binarySearch returns "
        << binarySearch(searchArray, 0, 7, 6) << "; should be -1" << endl;
   cout << endl;
   
   cout << "Factorial(0) = " << fact(0) << "; should be 1" << endl;
   cout << "Factorial(4) = " << fact(4) << "; should be 24" << endl;
   cout << endl;

   cout << "getNumberOfGroups(4, 2) = " << getNumberOfGroups(4, 2) << "; should be 6" << endl;
   cout << "getNumberOfGroups(5, 5) = " << getNumberOfGroups(5, 5) << "; should be 1" << endl;
   cout << "getNumberOfGroups(5, 0) = " << getNumberOfGroups(5, 0) << "; should be 1" << endl;
   cout << "getNumberOfGroups(5, 6) = " << getNumberOfGroups(5, 6) << "; should be 0" << endl;
   cout << endl;

   cout << "rabbit(0) = " << rabbit(0) << "; should be 1" << endl;
   cout << "rabbit(4) = " << rabbit(7) << "; should be 13" << endl;
   cout << endl;

   cout << "iterativeRabbit(0) = " << rabbit(0) << "; should be 1" << endl;
   cout << "iterativeRabbit(4) = " << rabbit(7) << "; should be 13" << endl;
   cout << endl;

   cout << "solveTowers(3, 'A', 'B', 'C') should produce these directions:" << endl;
   cout << "Move top disk from pole A to pole B" << endl;
   cout << "Move top disk from pole A to pole C" << endl;
   cout << "Move top disk from pole B to pole C" << endl;
   cout << "Move top disk from pole A to pole B" << endl;
   cout << "Move top disk from pole C to pole A" << endl;
   cout << "Move top disk from pole C to pole B" << endl;
   cout << "Move top disk from pole A to pole B" << endl;
   cout << endl;
   cout << "solveTowers(3, 'A', 'B', 'C') produces these directions:" << endl;
   solveTowers(3, 'A', 'B', 'C');
   cout << endl;

   cout << "Writing arrays of characters backward:" << endl;
   char anArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
   cout << "Write abcdef backward: ";
   writeArrayBackward(anArray, 0, 5);
   cout << endl;
   
   cout << "Write abcdefg backward: ";
   writeArrayBackward(anArray, 0, 6);
   cout << endl;

   cout << "Write cde backward: ";
   writeArrayBackward(anArray, 2, 4);
   cout << endl << endl;

   cout << "Writing strings backward: " << endl;
   cout << "Write \"abcdef\" backward: ";
   writeBackward("abcdef");
   cout << endl;
   
   cout << "Write \"abcdefg\" backward: ";
   writeBackward("abcdefg");
   cout << endl;
   
   cout << "Write \"cde\" backward: ";
   writeBackward("cde");
   cout << endl << endl;

   cout << "Writing strings backward iteratively: " << endl;
   cout << "Write \"abcdef\" backward: ";
   writeBackwardIterative("abcdef");
   cout << endl;
   
   cout << "Write \"abcdefg\" backward: ";
   writeBackwardIterative("abcdefg");
   cout << endl;
   
   cout << "Write \"cde\" backward: ";
   writeBackwardIterative("cde");
   cout << endl << endl;

   cout << "Checkpoint Question 1: " << endl;
 	cout << " if n = 1, sumUpTo(1) = " << sumUpTo(1) << endl;
   cout << endl;
	cout << " if n = 5, sumUpTo(5) = " << sumUpTo(5) << endl;
   cout << endl;

   cout << "Exercise 1: " << endl;
   int intArray[] = {2, 4, 6, 2, 4, 2, 8, 4, 4, 2, 6, 2, 4, 2, 6};
   cout << "getNumberEqual(intArray, 15, 2) = "
        << getNumberEqual(intArray, 15, 2) << "; should be 6" << endl;
   cout << "getNumberEqual(intArray, 15, 4) = "
        << getNumberEqual(intArray, 15, 4) << "; should be 5" << endl;
   cout << "getNumberEqual(intArray, 15, 2) = "
        << getNumberEqual(intArray, 15, 6) << "; should be 3" << endl;
   cout << "getNumberEqual(intArray, 15, 5) = "
        << getNumberEqual(intArray, 15, 5) << "; should be 0" << endl;
   cout << "getNumberEqual(intArray, 15, 8) = "
        << getNumberEqual(intArray, 15, 8) << "; should be 1" << endl;
   cout << endl;
   
   cout << "Exercise 11: " << endl;
   cout << "getValue(1, 7, 7) produces the following output: " << endl;
   int result = getValue(1, 7, 7);
   cout << "getValue(1, 7, 7) = " << result << "; should be 2" << endl;
   cout << endl;
   
   cout << "Exercise 11: " << endl;
   cout << "mystery(30) produces the following output: " << endl;
   result = mystery(30);
   cout << "mystery(30) = " << result << "; should be 5" << endl;
   cout << endl;

   cout << "Exercise 13: " << endl;
   cout << "displayOctal(100) produces the following output: " << endl;
   displayOctal(100);
   cout << "; should be 144" << endl;
   cout << endl;

   cout << "Exercise 14: " << endl;
   cout << "The value of f(8) is " << f(8) << endl;
   cout << endl;

   cout << "Exercise 15: " << endl;
   cout << "recurse(5, 3) with value parameters." << endl;
   recurse(5, 3);
   cout << endl;

   cout << "recurse(5, 3) with a first reference parameter." << endl;
   int x = 5;
   recurseRef(x, 3);
   cout << endl;

   cout << "Exercise 23: " << endl;
   cout << "gcd(18, 4) = " << gcd(18, 4) << "; should be 2" << endl;
   cout << "gcd(16, 4) = " << gcd(16, 4) << "; should be 4" << endl;
   cout << "gcd(16, 3) = " << gcd(16, 3) << "; should be 1" << endl;
   cout << endl;

   cout << "DONE" << endl;
	
   return 0;
}  // end main

/*
 
 Searching for 9: binarySearch returns 2; should be 2
 Searching for 6: binarySearch returns -1; should be -1
 
 Factorial(0) = 1; should be 1
 Factorial(4) = 24; should be 24
 
 getNumberOfGroups(4, 2) = 6; should be 6
 getNumberOfGroups(5, 5) = 1; should be 1
 getNumberOfGroups(5, 0) = 1; should be 1
 getNumberOfGroups(5, 6) = 0; should be 0
 
 rabbit(0) = 1; should be 1
 rabbit(4) = 13; should be 13
 
 iterativeRabbit(0) = 1; should be 1
 iterativeRabbit(4) = 13; should be 13
 
 solveTowers(3, 'A', 'B', 'C') should produce these directions:
 Move top disk from pole A to pole B
 Move top disk from pole A to pole C
 Move top disk from pole B to pole C
 Move top disk from pole A to pole B
 Move top disk from pole C to pole A
 Move top disk from pole C to pole B
 Move top disk from pole A to pole B
 
 solveTowers(3, 'A', 'B', 'C') produces these directions:
 Move top disk from pole A to pole B
 Move top disk from pole A to pole C
 Move top disk from pole B to pole C
 Move top disk from pole A to pole B
 Move top disk from pole C to pole A
 Move top disk from pole C to pole B
 Move top disk from pole A to pole B
 
 Writing arrays of characters backward:
 Write abcdef backward: fedcba
 Write abcdefg backward: gfedcba
 Write cde backward: edc
 
 Writing strings backward:
 Write "abcdef" backward: fedcba
 Write "abcdefg" backward: gfedcba
 Write "cde" backward: edc
 
 Writing strings backward iteratively:
 Write "abcdef" backward: fedcba
 Write "abcdefg" backward: gfedcba
 Write "cde" backward: edc
 
 Checkpoint Question 1:
 if n = 1, sumUpTo(1) = 1
 
 if n = 5, sumUpTo(5) = 15
 
 Exercise 1:
 getNumberEqual(intArray, 15, 2) = 6; should be 6
 getNumberEqual(intArray, 15, 4) = 5; should be 5
 getNumberEqual(intArray, 15, 2) = 3; should be 3
 getNumberEqual(intArray, 15, 5) = 0; should be 0
 getNumberEqual(intArray, 15, 8) = 1; should be 1
 
 Exercise 11:
 getValue(1, 7, 7) produces the following output:
 Enter: a = 1 b = 7
 Enter: a = 1 b = 3
 Leave: a = 1 b = 3
 Leave: a = 1 b = 7
 getValue(1, 7, 7) = 2; should be 2
 
 Exercise 11:
 mystery(30) produces the following output:
 Enter: first = 1 last = 30
 Enter: first = 1 last = 14
 Enter: first = 1 last = 6
 Enter: first = 4 last = 6
 Leave: first = 4 last = 6
 Leave: first = 1 last = 6
 Leave: first = 1 last = 14
 Leave: first = 1 last = 30
 mystery(30) = 5; should be 5
 
 Exercise 13:
 displayOctal(100) produces the following output:
 144; should be 144
 
 Exercise 14:
 The value of f(8) is Function entered with n = 8
 Function entered with n = 6
 Function entered with n = 4
 Function entered with n = 2
 Function entered with n = 0
 Function entered with n = 2
 Function entered with n = 4
 Function entered with n = 2
 Function entered with n = 0
 27
 
 Exercise 15:
 recurse(5, 3) with value parameters.
 6 2
 7 1
 8 0
 8 0
 7 1
 6 2
 
 recurse(5, 3) with a first reference parameter.
 6 2
 7 1
 8 0
 8 0
 8 1
 8 2
 
 Exercise 23: 
 gcd(18, 4) = 2; should be 2
 gcd(16, 4) = 4; should be 4
 gcd(16, 3) = 1; should be 1
 
 DONE
*/
