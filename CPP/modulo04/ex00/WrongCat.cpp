/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:13:07 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/01 20:23:12 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WronCat";
	cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	cout << "WrongCat copy constructor called\n";
	*this = copy;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& assig)
{
	this->_type = assig._type;
	return *this;
}

void WrongCat::makeSound() const
{
	cout << "miauuuu!!\n";
}
