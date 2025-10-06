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

int main() { //I am way too tired/lazy to implement user inputs in this program
  Factorizer factorizer; //An object of the Factorizer class named "factorizer"; very creative, yes

  std::cout << "Welcome to the Prime Factorizer!" << std::endl;
  std::cout << "=================================" << std::endl << std::endl;

  //Demonstration 1: Prime Factorization
  std::cout << "Let's factor some numbers:" << std::endl;
  int number = 100;
  std::cout << number << " = ";
  printVector(factorizer.primeFactors(number));
  std::cout << std::endl;

  number = 17;
  std::cout << number << " = ";
  printVector(factorizer.primeFactors(number));
  std::cout << " (prime!)" << std::endl << std::endl;

  //Demonstration 2: Prime checking
  std::cout << "Checking if numbers are prime:" << std::endl;
  std::cout << "Is 17 prime? " << (factorizer.isPrime(17) ? "Yes" : "No") << std::endl; //I found this notation style
  std::cout << "Is 24 prime? " << (factorizer.isPrime(24) ? "Yes" : "No") << std::endl << std::endl; //On a website called "https://www.learncpp.com/"

  //Demonstration 3: Composite checking
  std::cout << "Checking if numbers are composite:" << std::endl;
  std::cout << "Is 9 composite? " << (factorizer.isComposite(9) ? "Yes" : "No") << std::endl;
  std::cout << "Is 13 composite? " << (factorizer.isComposite(13) ? "Yes" : "No") << std::endl << std::endl;

  //Demonstration 4: Fraction reduction
  std::cout << "Simplifying fractions:" << std::endl;
  std::cout << "12/26 simplifies to " << factorizer.reduce(12, 26) << std::endl;
  std::cout << "36/12 simplifies to " << factorizer.reduce(36, 12) << std::endl;
  std::cout << "100/25 simplifies to " << factorizer.reduce(100, 25) << std::endl;

  return 0;
}
