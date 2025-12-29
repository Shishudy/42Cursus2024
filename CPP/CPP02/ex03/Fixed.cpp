/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:52:42 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/29 13:49:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_raw = i << _fractionalBits;
}

Fixed::Fixed(const float i)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(i * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_raw = fixed._raw;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	// std::cout << "Greater than comparison operator called" << std::endl;
	return (this->_raw > fixed._raw);
}

bool Fixed::operator<(const Fixed &fixed) const
{
	// std::cout << "Less than comparison operator called" << std::endl;
	return (this->_raw < fixed._raw);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	// std::cout << "Greater than or equal to comparison operator called" << std::endl;
	return (this->_raw >= fixed._raw);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	// std::cout << "Less than or equal to comparison operator called" << std::endl;
	return (this->_raw <= fixed._raw);
}

bool Fixed::operator==(const Fixed &fixed) const
{
	// std::cout << "Equal to comparison operator called" << std::endl;
	return (this->_raw == fixed._raw);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	// std::cout << "Not equal to comparison operator called" << std::endl;
	return (this->_raw != fixed._raw);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed	result;
	
	// std::cout << "Addition arithmetic operator called" << std::endl;
	result.setRawBits(this->_raw + fixed._raw);
	return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed	result;
	
	// std::cout << "Subtraction arithmetic operator called" << std::endl;
	result.setRawBits(this->_raw - fixed._raw);
	return (result);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed	result;
	long	temp;
	
	// std::cout << "Multiplication arithmetic operator called" << std::endl;
	temp = this->_raw * fixed._raw;
	result.setRawBits(temp >> this->_fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed	result;
	
	// std::cout << "Division arithmetic operator called" << std::endl;
	result.setRawBits((this->_raw << this->_fractionalBits) / fixed._raw);
	return (result);
}

Fixed &Fixed::operator++(void)
{
	// std::cout << "Pre-increment operator called" << std::endl;
	this->_raw++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{	
	// std::cout << "Pre-decrement operator called" << std::endl;
	this->_raw--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp(*this);

	// std::cout << "Post-increment operator called" << std::endl;
	this->_raw++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp(*this);

	// std::cout << "Post-decrement operator called" << std::endl;
	this->_raw--;
	return (temp);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1._raw < fixed2._raw)
		return (fixed1);
	return fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1._raw < fixed2._raw)
		return (fixed1);
	return fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1._raw > fixed2._raw)
		return (fixed1);
	return fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1._raw > fixed2._raw)
		return (fixed1);
	return fixed2;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_raw / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_raw >> this->_fractionalBits);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed& fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}