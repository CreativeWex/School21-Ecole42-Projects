#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		// EX 00
		Fixed();
		~Fixed();
		Fixed(Fixed const & src);

		Fixed & operator=( Fixed const & rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
//-----------------------------------------------------------------------------------
		// EX 01
		Fixed(int const int_arg);
		Fixed(float const float_arg);

		float toFloat(void) const;
		int toInt(void) const;
//-----------------------------------------------------------------------------------
		// EX 02
		// > < >= <= == !=
		int operator>( Fixed const & rhs) const;
		int operator<( Fixed const & rhs) const;
		int operator>=( Fixed const & rhs) const;
		int operator<=( Fixed const & rhs) const;
		int operator==( Fixed const & rhs) const;
		int operator!=( Fixed const & rhs) const;
		
		// + - * /
		Fixed operator+( Fixed const & rhs) const;
		Fixed operator-( Fixed const & rhs) const;
		Fixed operator*( Fixed const & rhs) const;
		Fixed operator/( Fixed const & rhs) const;

		// ++F F++ --F F--
		Fixed & operator++( void ); // Prefix (++F)
		Fixed & operator--( void ); // Prefix (--F)
		Fixed operator++( int n ); // Postfix (F++)
		Fixed operator--( int n ); // Postfix (F--)

		// min & max
		static Fixed & min(Fixed & a, Fixed & b );
		static Fixed & max(Fixed & a, Fixed & b );
		static const Fixed & min(const Fixed & a, const Fixed & b );
		static const Fixed & max(const Fixed & a, const Fixed & b );

	private:
		int	fixed_point_value;
		static const int n_fract_bits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

#endif
