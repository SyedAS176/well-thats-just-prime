#include "prime.hpp"
#include <algorithm>

//For my understanding: this is a return type of vector of int types; primeFactors is a member function of the Factorizer class
std::vector<int> Factorizer::primeFactors(int number) {
    std::vector<int> factors;
    //Return empty vector for numbers <= 1
    if (number <= 1) {
        return factors;
    }
    //Check for factor of 2
    while (number % 2 == 0) {
        factors.push_back(2);
        number = number / 2;
    }
    //Check for odd factors from 3 onwards
    for (int i = 3; i * i <= number; i += 2) {
        while (number % i == 0) {
            factors.push_back(i);
            number = number / i;
        }
    }
    //If number is still greater than 1, then it's a prime factor
    if (number > 1) {
        factors.push_back(number);
    }
    return factors; //Returning a vector of int types
}

//Extra Credit 1: Check if a number is prime
bool Factorizer::isPrime(int number) { //For my understanding: this is a return type of bool; isPrime is a member function of the Factorizer class
    if (number <= 1) { //Numbers <= 1 are not prime
        return false;
    }
    //Get prime factors
    std::vector<int> factors = primeFactors(number);
    //A number is prime if its only prime factor is itself (this is just true, believe it)
    return (factors.size() == 1 && factors[0] == number);
}

//Extra Credit 2: Check if a number is composite
bool Factorizer::isComposite(int number) { //For my understanding: this is a return type of bool; isComposite is a member function of the Factorizer class
    //A number is composite if it's not 1 and not prime (again this is just true, believe it)
    return (number > 1 && !isPrime(number));
}

//Extra Credit 3: Reduce a fraction using prime factorization
std::string Factorizer::reduce(int numerator, int denominator) { //For my understanding: this is a return type of string; reduce is a member function of the Factorizer class
    //Handle edge case of zero denominator
    if (denominator == 0) {
        return "undefined";
    }
    //Handle zero numerator
    if (numerator == 0) {
        return "0";
    }
    //Get prime factors for both numerator and denominator
    std::vector<int> numFactors = primeFactors(numerator); //Just call the function we just made above; grab prime factors
    std::vector<int> denFactors = primeFactors(denominator); //Just call the function we made above; grab prime factors
    //Remove common factors
    for (int i = 0; i < numFactors.size(); i++) {
        bool foundMatch = false;
        for (int j = 0; j < denFactors.size(); j++) {
            if (numFactors[i] == denFactors[j]) {
                //Distinguish factors as removed by setting to 1
                numFactors[i] = 1;
                denFactors[j] = 1;
                foundMatch = true; //Stop looking for more matches for this factor; move to next numerator factor
            }
        }
    }
    //Calculating reduced numerator
    int reducedNum = 1;
    for (int factor : numFactors) {
        if (factor > 1) {
            reducedNum *= factor;
        }
    }
    //Calculating reduced denominator
    int reducedDen = 1;
    for (int factor : denFactors) {
        if (factor > 1) {
            reducedDen *= factor;
        }
    }
    //Formating the output
    if (reducedDen == 1) {
        return (std::to_string(reducedNum));
    } else {
        return (std::to_string(reducedNum) + "/" + std::to_string(reducedDen));
    }
}