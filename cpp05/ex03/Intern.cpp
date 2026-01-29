# include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) 
{
    (void)src;
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return (*this);
}
        
Intern::~Intern() {}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form type not found";
}

static AForm* makeShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm* makePardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}
        
AForm *Intern::makeForm(const std::string &form_name, const std::string &target)
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*funcPtrs[])(const std::string &) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePardon
    };

    for (int i = 0; i < 3; i++) {
        if (form_name == formNames[i]) {
            std::cout << "Intern creates " << form_name << std::endl;
            return (funcPtrs[i](target));
        }
    }
    throw Intern::FormNotFoundException();
}
