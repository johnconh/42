/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:29:01 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 18:20:44 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): _Brain(new Brain())
{
	this->_type = "Dog";
	cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& copy)
{
	cout << "Dog copy constructor called\n";
	this->_Brain = new Brain(*copy._Brain);
}

Dog::~Dog()
{
	cout << "Dog destructor called\n";
	delete _Brain;
}

Dog& Dog::operator=(const Dog& assig)
{
	this->_type = assig._type;
	*(this->_Brain) = *(assig._Brain);
	return *this;
}

void Dog::makeSound() const
{
	cout << "Guau!\n";
}

Brain* Dog::getbrain()
{
	return this->_Brain;
}
