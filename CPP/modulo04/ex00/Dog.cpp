/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:29:01 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/01 17:35:08 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& copy)
{
	cout << "Dog copy constructor called\n";
	*this = copy;
}

Dog::~Dog()
{
	cout << "Dog destructor called\n";
}

Dog& Dog::operator=(const Dog& assig)
{
	this->_type = assig._type;
	return *this;
}

void Dog::makeSound() const
{
	cout << "Guau!\n";
}
