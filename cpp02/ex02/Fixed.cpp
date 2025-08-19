#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	value = copy.value;
}

Fixed &Fixed::operator=(const Fixed &n)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &n)
		this->value = n.value;
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructer called" << std::endl;
}

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed::Fixed(const int &num)
{
	//std::cout << "Int constructor called" << std::endl;
	value = roundf(num * (1 << fraction));
}

Fixed::Fixed(const float &num)
{
	//std::cout << "float constructor called" << std::endl;
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

bool Fixed::operator>(const Fixed &n) const
{
	if (value > n.value)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &n) const
{
	return (value < n.value);
}
		
bool Fixed::operator>=(const Fixed &n) const
{
	return (value >= n.value);
}

bool Fixed::operator<=(const Fixed &n) const
{
	return (value <= n.value);
}
		
bool Fixed::operator!=(const Fixed &n) const
{
	return (value != n.value);
}

bool Fixed::operator==(const Fixed &n) const
{
	return (value == n.value);
}

Fixed Fixed::operator+(const Fixed &n) const
{
	Fixed res;
	res.value = ((value) + (n.value)) / (1 << fraction);
	return (res);
}
		
Fixed Fixed::operator-(const Fixed &n) const
{
	Fixed res;
	res.value = ((value) - (n.value)) / (1 << fraction);
	return (res);
}
		
Fixed Fixed::operator*(const Fixed &n) const
{
	Fixed res;
	res.value = ((value) * (n.value)) / (1 << fraction);
	return (res);
}
		
Fixed Fixed::operator/(const Fixed &n) const
{
	Fixed res;
	res.value = ((value) / (n.value)) / (1 << fraction);
	return (res);
}

Fixed &Fixed::operator++()	// pre
{
	value += 1;
	return (*this);
}
		
Fixed Fixed::operator++(int)	// post
{
	Fixed ret(*this);
	value += 1;
	return (ret);
}
		
Fixed &Fixed::operator--()	// pre
{
	value -= 1;
	return (*this);
}
		
Fixed Fixed::operator--(int)	// post
{
	Fixed ret(*this);
	value -= 1;
	return (ret);
}

Fixed &Fixed::min(Fixed &one, Fixed &two)
{
	return (one.value < two.value? one : two);
}

const Fixed &Fixed::min(const Fixed &one, const Fixed &two)
{
	return (one.value < two.value? one : two);
}
		
Fixed &Fixed::max(Fixed &one, Fixed &two)
{
	return (one.value > two.value? one : two);
}
		
const Fixed &Fixed::max(const Fixed &one, const Fixed &two)
{
	return (one.value > two.value? one : two);
}
