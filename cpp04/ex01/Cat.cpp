#include "Cat.hpp"
        
Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}
 
Cat::Cat(const Cat &copy)
{
    type = copy.type;
    brain = new Brain(*copy.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &obj)
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

Cat::~Cat()
{
    if (brain)
        delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "cats MEAWSSS" << std::endl;
}