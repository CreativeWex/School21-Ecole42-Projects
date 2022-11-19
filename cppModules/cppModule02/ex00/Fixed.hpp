#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor
// 3) '=' Operator overload
// 4) Destructor (virtual!)

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const & src);

		Fixed & operator=( Fixed const & rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int	fixed_point_value;
		static const int n_fract_bits = 8;
};

#endif
