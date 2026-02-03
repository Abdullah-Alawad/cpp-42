#include "Span.hpp"

Span::Span() : maxSize(0)
{
}

Span::Span(const unsigned int n) : maxSize(n)
{
    nbr.reserve(n);
}

Span::Span(const Span& cpy) : nbr(cpy.nbr), maxSize(cpy.maxSize)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        nbr = other.nbr;
        maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (nbr.size() >= maxSize)
        throw std::runtime_error("Span is full!");
    nbr.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (nbr.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");

    std::vector<int> sorted = nbr;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        unsigned int span = sorted[i+1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (nbr.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");
    int minVal = *std::min_element(nbr.begin(), nbr.end());
    int maxVal = *std::max_element(nbr.begin(), nbr.end());
    return maxVal - minVal;
}