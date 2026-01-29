#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        AForm* rrf;
        AForm* rrt;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;

        rrt = someRandomIntern.makeForm("presidential pardon", "Target");
        delete rrt;

        rrt = someRandomIntern.makeForm("meaw", "Target");
    }
    catch (std::exception &e) {
        std::cout << "\033[31mCaught Exception: " << e.what() << "\033[0m" << std::endl;
    }
}