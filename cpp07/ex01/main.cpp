#include <iostream>
#include <string>
#include "iter.hpp"

// -------------------------------------------------------------------------
// Helper Functions for Testing
// -------------------------------------------------------------------------

// 1. A simple function template (Instantiated function template)
template <typename T>
void printElement(const T &elem) {
    std::cout << elem << " ";
}

// 2. A function that modifies the element (Non-const reference)
void increment(int &n) {
    n++;
}

// 3. A function that works with a specific type (Const reference)
void printIntEven(const int &n) {
    if (n % 2 == 0)
        std::cout << n << " (Even) ";
    else
        std::cout << n << " (Odd) ";
}

// -------------------------------------------------------------------------
// Main
// -------------------------------------------------------------------------

int main() {
    std::cout << "=== Test 1: Integer Array (Modification) ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;

    std::cout << "Original: ";
    // Use the template function instantiated for int
    iter(intArray, intLen, printElement<int>); 
    std::cout << std::endl;

    std::cout << "Incrementing..." << std::endl;
    iter(intArray, intLen, increment);

    std::cout << "Modified: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl << std::endl;

    // ---------------------------------------------------------

    std::cout << "=== Test 2: Const Correctness (Int array -> Const func) ===" << std::endl;
    // Here we pass a non-const array, but the function takes a const ref.
    // This tests if your template handles implicit qualification conversion.
    iter(intArray, intLen, printIntEven);
    std::cout << std::endl << std::endl;

    // ---------------------------------------------------------

    std::cout << "=== Test 3: String Array ===" << std::endl;
    std::string strArray[] = {"Hello", "World", "from", "42"};
    size_t strLen = 4;

    std::cout << "Strings: ";
    // Instantiated template for string
    iter(strArray, strLen, printElement<std::string>); 
    std::cout << std::endl << std::endl;

    // ---------------------------------------------------------

    std::cout << "=== Test 4: Const Array ===" << std::endl;
    const float floatArray[] = {1.1f, 2.2f, 3.3f};
    
    std::cout << "Const Float: ";
    iter(floatArray, 3, printElement<float>);
    std::cout << std::endl;

    return 0;
}