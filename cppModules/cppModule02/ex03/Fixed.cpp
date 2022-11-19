#include "Fixed.hpp"
#include <cmath>

int Fixed::getRawBits( void ) const
{
	return (this->fixed_point_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->fixed_point_value = raw;
}

Fixed::Fixed()
{
	this->fixed_point_value = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	setRawBits(rhs.getRawBits());
	return (*this);
}

//-----------------------------------------------------------------------------------
// EX 01
//-----------------------------------------------------------------------------------

// INT constructor
Fixed::Fixed(int int_arg)
{
	setRawBits(int_arg << this->n_fract_bits);
}

Fixed::Fixed(float float_arg)
{
	this->setRawBits((int)roundf(float_arg * (1 << this->n_fract_bits)));
}

float Fixed::toFloat(void) const
{
	float	f;

	f = (float)this->getRawBits() / (1 << this->n_fract_bits);
	return (f);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->n_fract_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

//-----------------------------------------------------------------------------------
// EX 02
//-----------------------------------------------------------------------------------

// > < >= <= == !=
int Fixed::operator>( Fixed const & rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<( Fixed const & rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=( Fixed const & rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=( Fixed const & rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==( Fixed const & rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=( Fixed const & rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	return (0);
}
//----------------

// + - * /
Fixed Fixed::operator+( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() + rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator-( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() - rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator*( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() * rhs.toFloat());
	
	return (ret);
}

Fixed Fixed::operator/( Fixed const & rhs) const
{
	Fixed ret(this->toFloat() / rhs.toFloat());
	
	return (ret);
}

Fixed & Fixed::operator++( void ) // Prefix (++F)
{
	this->fixed_point_value += 1;
	return (*this);
}

Fixed & Fixed::operator--( void ) // Prefix (--F)
{
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed Fixed::operator++( int ) // Postfix (F++)
{
	Fixed	temp = *this;

	(this->fixed_point_value) +=1 ;
	return (temp);
}

Fixed Fixed::operator--( int ) // Postfix (F--)
{
	Fixed	temp = *this;

	(this->fixed_point_value) -=1 ;
	return (temp);
}

// min & max

Fixed Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
	
Fixed Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
