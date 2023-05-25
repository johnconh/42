/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:04:32 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/25 20:27:14 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _numb(0)
{
	//cout << "Default constructor called\n";
}

Fixed::Fixed(const int numb): _numb(numb << _bit)
{
	//cout << "Int constructor called\n";
}

Fixed::Fixed(const float numb)
{
	_numb = roundf(numb * (1 << _bit));
	//cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	//cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::~Fixed()
{
	//cout << "Destructor called\n";
}

//  operadores aritméticos:
Fixed& Fixed::operator=(const Fixed& assing)
{
	this->_numb = assing.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed& assig)
{
	Fixed result;
	result.setRawBits(this->_numb + assig._numb);
	return result;
}

Fixed Fixed::operator-(const Fixed& assig)
{
	Fixed result;
	result.setRawBits(this->_numb - assig._numb);
	return result;
}

Fixed Fixed::operator*(const Fixed& assig)
{
	Fixed result (toFloat() * assig.toFloat());
	return result;
}

Fixed Fixed::operator/(const Fixed& assig)
{
	Fixed result = (toFloat() / assig.toFloat());
	return result;
}

//operadores de preincremento, predecremiento

Fixed& Fixed::operator++()
{
	_numb += 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	_numb -= 1;
	return *this;
}

// operadores  postincremento y postdecremiento
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

// operaciones de comparación
bool Fixed::operator<(const Fixed& other) const
{
	return (_numb < other._numb);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_numb > other._numb);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_numb>= other._numb);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_numb <= other._numb);	
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_numb == other._numb);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_numb != other._numb);	
}

//======Min
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

//==== Max
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

// ======================
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
