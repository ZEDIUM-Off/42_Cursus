/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:39:24 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/12 10:05:13 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed()	:	_value(0)
{
}

Fixed::Fixed(const int value) : _value(value << _bits)
{
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits)))
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}


int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << _bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}