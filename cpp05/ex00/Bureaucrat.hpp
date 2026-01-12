#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;  // 1 -> highest possible grade TO 150 -> lowest possible grade
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& cpy);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat& operator=(const Bureaucrat& cpy);
        const std::string &getName() const;
        int getGrade() const;
        void    setGrade(int grade);
        void    incrementGrade();
        void    decrementGrade();
        ~Bureaucrat();

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