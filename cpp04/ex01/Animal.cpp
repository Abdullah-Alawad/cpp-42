#include "Animal.hpp"

Animal::Animal(): type("Generic")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy): type(copy.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Generic Animal sound" << std::endl;
}
