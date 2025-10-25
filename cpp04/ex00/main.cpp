#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "-------------------good classes" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "-------------------Bad classes" << std::endl;
    const WrongAnimal *cati = new WrongCat();

    std::cout << cati->getType() << std::endl;
    cati->makeSound();

    delete cati;
    std::cout << "-------------------more tests" << std::endl;
    const WrongCat *cati2 = new WrongCat();
    std::cout << cati2->getType() << std::endl;
    cati2->makeSound();
    delete cati2;
    return 0;
}