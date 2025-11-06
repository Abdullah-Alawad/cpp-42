#include "Dog.hpp"
        
Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}
 
Dog::Dog(const Dog &copy)
{
    type = copy.type;
    brain = new Brain(*copy.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
        if (brain)
            delete brain;
        brain = new Brain(*obj.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    if (brain)
        delete brain;
    std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound() const
{
    std::cout << "Dogs PARK" << std::endl;
}
