/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:04:32 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/25 17:31:21 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(): _numb(0)
{
	cout << "Default constructor called\n";
}

Fixed::Fixed(const int numb): _numb(numb << _bit)
{
	cout << "Int constructor called\n";
}

Fixed::Fixed(const float numb)
{
	_numb = roundf(numb * (1 << _bit));
	cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& assing)
{
	cout << "Assignation operator called\n";
	this->_numb = assing.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	return(this->_numb);
}

void Fixed::setRawBits(int const raw)
{
	this->_numb = raw;
}

int Fixed::toInt(void) const
{
	return (this->_numb >> _bit);
}

float Fixed::toFloat(void) const
{
	return((float)_numb / (1 << _bit));
}

int Fixed:: get_numb() const
{
	return(this->_numb);
}

std::ostream& operator << (std::ostream& os, const Fixed& fix)
{
	float floatvalue = fix.toFloat();
	os << floatvalue;
	return (os);
}
