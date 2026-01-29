#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class Form
{
    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _grade_to_sign;
        const int           _grade_to_execute;
    public:
        Form();
        Form(const Form &cpy);
        Form &operator=(const Form &cpy);
        ~Form();
        Form(const std::string& name, int grade_to_sign, int grade_to_execute);
        const std::string& getName() const;
        bool getSigned() const; // Or isSigned()
        int getGradeToSign() const;
        int getGradeToExecute() const;
        // 3. The Core Functionality
        void beSigned(const Bureaucrat& bureaucrat);

        // 4. Exception Classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& out, const Form& form);
#endif