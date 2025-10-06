#include <iostream>

#include "src/prime.hpp"

//This is just used to help print a vector because I don't feel like dealing with messy code in main()
void printVector(const std::vector<int>& vec) { //The '[' and ',' and ']' is there because otherwise C++ just prints whatever is inside the vector, and I'm annoyed by the formatting
  std::cout << "["; //Makes output look pretty
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i];
    if (i < vec.size() - 1) {
      std::cout << ", "; //Makes output look pretty
    }
  }
  std::cout << "]"; //Makes output look pretty
}

int main() {
  Factorizer factorizer; //An object of the Factorizer class named "factorizer"; very creative, yes


}
