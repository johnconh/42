/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:47:31 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/01 20:22:52 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	cout << "WrongAnimal construtor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	cout << "WrongAnimal copy constructor called\n";
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assig)
{
	this->_type = assig._type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	cout << "Generic animal sound\n";
}

const string WrongAnimal::getType() const
{
	return this->_type;
}
