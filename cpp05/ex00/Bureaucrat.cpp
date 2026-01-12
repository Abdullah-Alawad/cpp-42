# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default name"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name(cpy._name), _grade(cpy._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& cpy)
{
    if (this != &cpy)
        this->_grade = cpy._grade;
    return (*this);
}

const std::string &Bureaucrat::getName() const
{
    return (_name);
}
int Bureaucrat::getGrade() const
{
    return (_grade);
}
void    Bureaucrat::setGrade(int grade)
{
    _grade = grade;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
void    Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}
void    Bureaucrat::decrementGrade()
{
        if (_grade + 1 > 150)
    throw GradeTooLowException();
    _grade++;
}
Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high -> max is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low -> lowest is 150");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (out);
}
