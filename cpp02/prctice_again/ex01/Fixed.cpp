#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	value = other.value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructer called" << std::endl;
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed::Fixed(const int &num)
{
	value = roundf(num * (1 << fraction));
}

Fixed::Fixed(const float &num)
{
	value = roundf(num * (1 << fraction));
}

float Fixed::toFloat(void) const
{
	return ((float)value / (1 << fraction));
}

int Fixed::toInt(void) const
{
	return (value / (1 << fraction));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
