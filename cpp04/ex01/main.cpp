#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; // Should not leak
    delete i;

    std::cout << "\n--- Array Test ---" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int k = 0; k < size; ++k) {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    for (int k = 0; k < size; ++k)
        delete animals[k];

    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog dog1;
    dog1.makeSound();
    dog1 = Dog(); // assign a new Dog

    Dog dog2(dog1);
    dog2.makeSound();

    return 0;
}