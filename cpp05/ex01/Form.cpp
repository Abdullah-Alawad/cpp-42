#include "Form.hpp"

Form::Form(): _name("Default Form"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

Form::Form(const Form &cpy): _name(cpy._name), _is_signed(cpy._is_signed), _grade_to_sign(cpy._grade_to_sign), _grade_to_execute(cpy._grade_to_execute) {}

Form &Form::operator=(const Form &cpy) {
    if (this != &cpy)
    {
        this->_is_signed = cpy._is_signed;
    }
    return (*this);
}

Form::~Form() {}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
}

const std::string& Form::getName() const {
    return (this->_name);
}

bool Form::getSigned() const {
    return (this->_is_signed);
}

int Form::getGradeToSign() const {
    return (this->_grade_to_sign);
}

int Form::getGradeToExecute() const {
    return (this->_grade_to_execute);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->_grade_to_sign)
        this->_is_signed = true;
    else
        throw Form::GradeTooLowException(); 
}


const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high, max is 1");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low, min is 150");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form name: " << form.getName()
        << "\nis_signed: " << (form.getSigned()? "True" : "False")
        << "\ngrade_to_sign: " << form.getGradeToSign()
        << "\ngrade_to_execute: " << form.getGradeToExecute()
        << std::endl;
    return (out);
}