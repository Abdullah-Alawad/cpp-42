#include "AForm.hpp"

AForm::AForm(): _name("Default AForm"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

AForm::AForm(const AForm &cpy): _name(cpy._name), _is_signed(cpy._is_signed), _grade_to_sign(cpy._grade_to_sign), _grade_to_execute(cpy._grade_to_execute) {}

AForm &AForm::operator=(const AForm &cpy) {
    if (this != &cpy)
    {
        this->_is_signed = cpy._is_signed;
    }
    return (*this);
}

AForm::~AForm() {}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

const std::string& AForm::getName() const {
    return (this->_name);
}

bool AForm::getSigned() const {
    return (this->_is_signed);
}

int AForm::getGradeToSign() const {
    return (this->_grade_to_sign);
}

int AForm::getGradeToExecute() const {
    return (this->_grade_to_execute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->_grade_to_sign)
        this->_is_signed = true;
    else
        throw AForm::GradeTooLowException(); 
}

void AForm::execute(Bureaucrat const &executor) const 
{
    if (this->_is_signed == false)
        throw FormNotSignedException();
    if (executor.getGrade() > this->_grade_to_sign)
        throw GradeTooLowException();
    this->executeAction();
}

void AForm::executeAction() const {}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("form is not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form name: " << form.getName()
        << "\nis_signed: " << (form.getSigned()? "True" : "False")
        << "\ngrade_to_sign: " << form.getGradeToSign()
        << "\ngrade_to_execute: " << form.getGradeToExecute()
        << std::endl;
    return (out);
}