#include <iostream>
#include <cstdlib> // for srand
#include <ctime>   // for time

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Helper function to print colored titles
void printTitle(std::string title) {
    std::cout << "\n\033[1;34m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
    std::srand(std::time(0));

    try {
        // --- PREPARATION ---
        printTitle("CREATING BUREAUCRATS");
        Bureaucrat boss("The Boss", 1);         // Rank 1 (Highest)
        Bureaucrat manager("Manager", 50);      // Rank 50
        Bureaucrat intern("Intern", 148);       // Rank 148 (Lowest)

        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << intern << std::endl;

        printTitle("CREATING FORMS");
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm   robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        // --- TEST 1: SHRUBBERY CREATION (Sign 145, Exec 137) ---
        printTitle("TEST 1: SHRUBBERY CREATION");
        
        // 1. Intern tries to execute unsigned form (Fail)
        intern.executeForm(shrub);

        // 2. Intern tries to sign (Fail - Grade 148 > 145)
        intern.signForm(shrub);

        // 3. Manager signs it (Success)
        manager.signForm(shrub);

        // 4. Intern tries to execute (Fail - Grade 148 > 137)
        intern.executeForm(shrub);

        // 5. Manager executes (Success)
        manager.executeForm(shrub); 
        // CHECK: "Home_shrubbery" file should exist now.

        // --- TEST 2: ROBOTOMY REQUEST (Sign 72, Exec 45) ---
        printTitle("TEST 2: ROBOTOMY REQUEST");

        // 1. Manager signs (Success - Grade 50 < 72)
        manager.signForm(robot);

        // 2. Manager tries to execute (Fail - Grade 50 > 45)
        manager.executeForm(robot);

        // 3. Boss executes (Success) - We run it 4 times to check 50% random chance
        std::cout << "[Running multiple robotomy attempts to test randomness]" << std::endl;
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);

        // --- TEST 3: PRESIDENTIAL PARDON (Sign 25, Exec 5) ---
        printTitle("TEST 3: PRESIDENTIAL PARDON");

        // 1. Manager tries to sign (Fail - Grade 50 > 25)
        manager.signForm(pardon);

        // 2. Boss signs (Success)
        boss.signForm(pardon);

        // 3. Boss executes (Success)
        boss.executeForm(pardon);

    } 
    catch (std::exception &e) {
        std::cout << "\033[1;31mUnexpected Exception: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}