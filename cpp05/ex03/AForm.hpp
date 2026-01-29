#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class AForm
{
    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _grade_to_sign;
        const int           _grade_to_execute;
    public:
        AForm();
        AForm(const AForm &cpy);
        AForm &operator=(const AForm &cpy);
        virtual ~AForm();
        AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
        const std::string& getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const &executor) const;
        virtual void executeAction() const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public: 
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif