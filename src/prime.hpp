#pragma once

#include <vector>
#include <string>

class Factorizer {
public:
    std::vector<int> primeFactors(int number); //Base requirement: Calculate prime factors of a number

    bool isPrime(int number); //Extra Credit 1: Check if a number is prime

    bool isComposite(int number); //Extra Credit 2: Check if a number is composite

    std::string reduce(int numerator, int denominator); //Extra Credit 3: Reduce a fraction using prime factorization
};