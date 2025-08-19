#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed c(3.5f);
	Fixed d(c);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "----------------------------------" << std::endl;
	if (c == d)
		std::cout << "c and d are equal" << std::endl; 
	return (0);
}