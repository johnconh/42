/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:35:40 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/01 18:07:53 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& copy)
{
	cout << "Animal copy contructor called\n";
	*this = copy;
}

Animal::~Animal()
{
	cout << "Animal destructor called\n";
}

Animal& Animal::operator=(const Animal& assig)
{
	this->_type = assig._type;
	return *this; 
}

void Animal::makeSound() const
{
	cout << "Generic animal sound\n";
}

const string Animal::getType() const
{
	return this->_type;
}
