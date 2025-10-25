#include "WrongCat.hpp"
        
WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}
 
WrongCat::WrongCat(const WrongCat &copy)
{
    type = copy.type;
    std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
        this->type = obj.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCats MEAWSSS" << std::endl;
}