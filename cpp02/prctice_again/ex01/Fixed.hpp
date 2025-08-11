#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int value;
		static const int fraction;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int &num);
		Fixed(const float &num);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits(void);
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif