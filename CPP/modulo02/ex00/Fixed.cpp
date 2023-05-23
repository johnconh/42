/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:04:32 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/22 20:30:01 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _numb(0)
{
	cout << "Default constructor called\n";
}


Fixed::Fixed(const Fixed& copy): _numb(copy._numb)
{
	cout << "Copy constructor called\n";
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
	cout << "getRawBits member function called\n";
	return(this->_numb);
}

void Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called\n";
	this->_numb = raw;
}
