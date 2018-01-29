// following the example from 
// http://www.cplusplus.com/reference/stack/stack/push/

// vector::push/pop
#include <iostream>       // std::cout
#include <vector>          // std::stack (x)

int main () {
  std::vector<int> mystack;

  for (int i=0; i<5; ++i) mystack.push_back(i);
  std::cout << "Popping out elements...";
  while (!mystack.empty()) {
     std::cout << ' ' << mystack.back();
     mystack.pop_back(); }
  std::cout << '\n';

  return 0;}