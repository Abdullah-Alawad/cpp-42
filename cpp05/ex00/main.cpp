#include "Bureaucrat.hpp"

int main() {
    // Test 1: Valid creation
    try {
        const std::string name1 = "Bob";
        Bureaucrat bob(name1, 2);
        std::cout << bob << std::endl;
        
        bob.incrementGrade(); // Should become 1
        std::cout << "After increment: " << bob << std::endl;
        
        // This should throw
        bob.incrementGrade(); 
        std::cout << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // Test 2: Creation with grade too low
    try {
        const std::string name2 = "jim";
        Bureaucrat jim(name2, 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // Test 3: Decrement error
    try {
        const std::string name3 = "alan";
        Bureaucrat alan(name3, 149);
        std::cout << alan << std::endl;
        alan.decrementGrade(); // 150
        std::cout << alan << std::endl;
        alan.decrementGrade(); // 151 -> Throw
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}