#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;  // 1 -> highest possible grade TO 150 -> lowest possible grade
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& cpy);
        Bureaucrat &operator=(const Bureaucrat& cpy);
        ~Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        const std::string &getName() const;
        int getGrade() const;
        void    setGrade(int grade);
        void    incrementGrade();
        void    decrementGrade();
        void    signForm(AForm& form);
        void executeForm(AForm const &form) const;

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif