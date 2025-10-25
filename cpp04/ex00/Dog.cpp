#include "Dog.hpp"
        
Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}
 
Dog::Dog(const Dog &copy)
{
    type = copy.type;
    std::cout << "Dog copy constructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dogs PARK" << std::endl;
}
