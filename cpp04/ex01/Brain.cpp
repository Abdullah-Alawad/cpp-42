#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy) {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = copy.ideas[i];
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return *this;
}

void Brain::addIdea(int pos, const std::string &idea)
{
    if (pos >= 0 && pos < 100)
        ideas[pos] = idea;
}

std::string Brain::getIdea(int pos)
{
    if (pos >= 0 && pos < 100)
        return (ideas[pos]);
    else
        return (NULL);
}
