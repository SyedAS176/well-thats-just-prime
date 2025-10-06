#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/prime.hpp"

//Prime Factorization Tests
TEST_CASE("primeFactors handles edge cases") {
    Factorizer factorizer;
    REQUIRE(factorizer.primeFactors(0).empty()); //Case of 0
    REQUIRE(factorizer.primeFactors(1).empty()); //Case of 1
    REQUIRE(factorizer.primeFactors(-5).empty()); //Case of # < 0
}

TEST_CASE("primeFactors calculates correct prime factors") {
    Factorizer factorizer;

    std::vector<int> result1 = {3, 3};
    REQUIRE(factorizer.primeFactors(9) == result1); //Prime factors of 9

    std::vector<int> result2 = {2, 5};
    REQUIRE(factorizer.primeFactors(10) == result2); //Prime factors of 10

    std::vector<int> result3 = {2, 2, 5, 5};
    REQUIRE(factorizer.primeFactors(100) == result3); //Prime factors of 100

    std::vector<int> result4 = {5, 7};
    REQUIRE(factorizer.primeFactors(35) == result4); //Prime factors of 35

    std::vector<int> result5 = {2, 2, 2, 3};
    REQUIRE(factorizer.primeFactors(24) == result5); //Prime factors of 24

    //Prime number examples
    std::vector<int> result6 = {17};
    REQUIRE(factorizer.primeFactors(17) == result6);

    std::vector<int> result7 = {2};
    REQUIRE(factorizer.primeFactors(2) == result7);

    std::vector<int> result8 = {3};
    REQUIRE(factorizer.primeFactors(3) == result8);
}

TEST_CASE("isPrime correctly identifies prime numbers") {
    Factorizer factorizer;

    //Edge cases - not prime
    REQUIRE_FALSE(factorizer.isPrime(0));
    REQUIRE_FALSE(factorizer.isPrime(1));
    REQUIRE_FALSE(factorizer.isPrime(-5));

    //Prime numbers
    REQUIRE(factorizer.isPrime(2));
    REQUIRE(factorizer.isPrime(3));
    REQUIRE(factorizer.isPrime(17));
    REQUIRE(factorizer.isPrime(23));
    REQUIRE(factorizer.isPrime(97));

    //Composite numbers
    REQUIRE_FALSE(factorizer.isPrime(4));
    REQUIRE_FALSE(factorizer.isPrime(9));
    REQUIRE_FALSE(factorizer.isPrime(100));
}

TEST_CASE("isComposite correctly identifies composite numbers") {
    Factorizer factorizer;

    //Edge cases - not composite
    REQUIRE_FALSE(factorizer.isComposite(0));
    REQUIRE_FALSE(factorizer.isComposite(1));
    REQUIRE_FALSE(factorizer.isComposite(-5));

    //Prime numbers - not composite
    REQUIRE_FALSE(factorizer.isComposite(2));
    REQUIRE_FALSE(factorizer.isComposite(17));
    REQUIRE_FALSE(factorizer.isComposite(97));

    //Composite numbers
    REQUIRE(factorizer.isComposite(4));
    REQUIRE(factorizer.isComposite(9));
    REQUIRE(factorizer.isComposite(100));
}

TEST_CASE("reduce simplifies fractions correctly") {
    Factorizer factorizer;

    //Some random examples
    REQUIRE(factorizer.reduce(36, 12) == "3");
    REQUIRE(factorizer.reduce(12, 12) == "1");
    REQUIRE(factorizer.reduce(12, 14) == "6/7");
    REQUIRE(factorizer.reduce(12, 37) == "12/37");

    //Edge cases
    REQUIRE(factorizer.reduce(0, 5) == "0");
    REQUIRE(factorizer.reduce(5, 1) == "5");

    //Additional cases
    REQUIRE(factorizer.reduce(100, 25) == "4");
    REQUIRE(factorizer.reduce(18, 24) == "3/4");
    REQUIRE(factorizer.reduce(7, 13) == "7/13");
}