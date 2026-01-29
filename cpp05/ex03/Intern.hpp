#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        ~Intern();
        AForm *makeForm(const std::string &form_name, const std::string &target);

        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    };

#endif