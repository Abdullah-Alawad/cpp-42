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
		Fixed(const Fixed &copy);
		Fixed(const int &num);
		Fixed(const float &num);
		Fixed &operator=(const Fixed &n);
		~Fixed();
		int getRawBits(void);
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		bool operator>(const Fixed &n) const;
		bool operator<(const Fixed &n) const;
		bool operator>=(const Fixed &n) const;
		bool operator<=(const Fixed &n) const;
		bool operator!=(const Fixed &n) const;
		Fixed operator+(const Fixed &n) const;
		Fixed operator-(const Fixed &n) const;
		Fixed operator*(const Fixed &n) const;
		Fixed operator/(const Fixed &n) const;
		Fixed &operator++();	// pre
		Fixed operator++(int);	// post
		Fixed &operator--();	// pre
		Fixed operator--(int);	// post
		static Fixed &min(Fixed &one, Fixed &two);
		static const Fixed &min(const Fixed &one, const Fixed &two);
		static Fixed &max(Fixed &one, Fixed &two);
		static const Fixed &max(const Fixed &one, const Fixed &two);
		int getFraction(void);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif