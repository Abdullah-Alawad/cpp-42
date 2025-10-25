#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Generic")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy): type(copy.type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Generic WrongAnimal sound" << std::endl;
}
