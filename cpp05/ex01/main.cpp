#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // --- TEST 1: FORM CREATION BOUNDS ---
    std::cout << "\033[34m--- TEST 1: FORM CREATION BOUNDS ---\033[0m" << std::endl;
    try {
        std::cout << "Trying to create Form with grade 0..." << std::endl;
        Form invalid("Invalid", 0, 50);
    }
    catch (std::exception &e) {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    try {
        std::cout << "Trying to create Form with grade 151..." << std::endl;
        Form invalid("Invalid", 151, 50);
    }
    catch (std::exception &e) {
        std::cout << "\033[31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    std::cout << std::endl;

    // --- TEST 2: SIGNING PROCESS ---
    std::cout << "\033[34m--- TEST 2: SIGNING PROCESS ---\033[0m" << std::endl;
    
    // Create Bureaucrats
    Bureaucrat boss("The Boss", 1);
    Bureaucrat intern("The Intern", 140);

    // Create Forms
    // "Important Contract" needs grade 50 to sign
    Form contract("Important Contract", 50, 50);
    
    // "Coffee Order" needs grade 150 to sign
    Form coffeeOrder("Coffee Order", 150, 150);

    std::cout << "State before signing:" << std::endl;
    std::cout << contract;
    std::cout << coffeeOrder << std::endl;

    // --- SCENARIO A: Intern tries to sign important contract (Should Fail) ---
    std::cout << "\n[Intern tries to sign Important Contract]" << std::endl;
    intern.signForm(contract);

    // --- SCENARIO B: Intern tries to sign coffee order (Should Succeed) ---
    std::cout << "\n[Intern tries to sign Coffee Order]" << std::endl;
    intern.signForm(coffeeOrder);

    // --- SCENARIO C: Boss tries to sign important contract (Should Succeed) ---
    std::cout << "\n[Boss tries to sign Important Contract]" << std::endl;
    boss.signForm(contract);

    std::cout << "\nState after signing attempts:" << std::endl;
    std::cout << contract;     // Should be signed now
    std::cout << coffeeOrder;  // Should be signed now

    return (0);
}