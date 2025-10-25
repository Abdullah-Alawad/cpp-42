#include "Cat.hpp"
        
Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}
 
Cat::Cat(const Cat &copy)
{
    type = copy.type;
    std::cout << "Cat copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &obj)
{
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "cats MEAWSSS" << std::endl;
}