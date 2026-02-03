#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
    private:
        std::vector<int> nbr;
        unsigned int maxSize;
    public:
        Span();
        Span(const unsigned int n);
        Span(const Span &cpy);
        Span&operator=(const Span &other);
        ~Span();
        void addNumber(int number);

        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            // Calculate how many numbers we are trying to add
            unsigned int dist = std::distance(begin, end);
            // Check if there is enough space left
            if (dist > (maxSize - nbr.size()))
                throw std::runtime_error("Not enough space to add range of numbers");
            // Insert the range at the end of our vector
            nbr.insert(nbr.end(), begin, end);
        }
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};


#endif