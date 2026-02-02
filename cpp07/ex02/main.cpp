// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

#include <iostream>
#include <string>
#include "Array.hpp"

// A simple class to test complex types
class TestClass {
public:
    TestClass() {}
};

int main() {
    std::cout << "--- Test 1: Simple Int Array ---" << std::endl;
    try {
        Array<int> integers(5);
        // Verify default initialization (should be 0)
        std::cout << "Default value at index 0: " << integers[0] << std::endl;

        // Assign values
        for (unsigned int i = 0; i < integers.size(); i++) {
            integers[i] = i * 10;
        }

        // Print values
        for (unsigned int i = 0; i < integers.size(); i++) {
            std::cout << integers[i] << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Deep Copy Check ---" << std::endl;
    try {
        Array<int> original(3);
        original[0] = 1;
        original[1] = 2;
        original[2] = 3;

        Array<int> copy = original; // Copy constructor

        std::cout << "Original[0] before change: " << original[0] << std::endl;
        std::cout << "Copy[0] before change: " << copy[0] << std::endl;

        copy[0] = 999; // Modify copy

        std::cout << "Original[0] after change: " << original[0] << " (Should be 1)" << std::endl;
        std::cout << "Copy[0] after change: " << copy[0] << " (Should be 999)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Out of Bounds Exception ---" << std::endl;
    try {
        Array<int> arr(5);
        std::cout << "Accessing index 10..." << std::endl;
        std::cout << arr[10] << std::endl; // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Array of Strings ---" << std::endl;
    try {
        Array<std::string> strings(2);
        strings[0] = "Hello";
        strings[1] = "World";
        
        std::cout << strings[0] << " " << strings[1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Empty Array ---" << std::endl;
    try {
        Array<int> empty;
        std::cout << "Size of empty: " << empty.size() << std::endl;
        std::cout << empty[0] << std::endl; // Should throw
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}