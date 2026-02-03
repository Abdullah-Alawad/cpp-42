#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
    std::cout << "--- Subject Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Range Test (10,000 Numbers) ---" << std::endl;
    try {
        std::vector<int> randomNumbers;
        std::srand(std::time(NULL));
        
        const int N = 10000;
        for (int i = 0; i < N; i++) {
            randomNumbers.push_back(std::rand());
        }
        Span bigSpan(N);
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Span size: " << N << std::endl;
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span:  " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Overflow Test ---" << std::endl;
    try {
        std::vector<int> extra(5, 42);
        Span tinySpan(3);

        // This should throw an exception because 5 > 3
        tinySpan.addNumber(extra.begin(), extra.end());
    }
    catch (const std::exception& e) {
        std::cerr << "Expected Error Caught: " << e.what() << std::endl;
    }

    return 0;
}