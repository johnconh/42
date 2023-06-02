/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:50:50 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 18:18:06 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): _Brain(new Brain())
{
	this->_type = "Cat";
	cout << "Cat constructor is called\n";
}

Cat::Cat(const Cat& copy)
{
	cout <<"Cat copy constructor is called\n";
	this->_Brain = new Brain(*copy._Brain);
}

Cat::~Cat()
{
	cout <<"Cat destructor is called\n";
	delete _Brain;
}

Cat& Cat::operator=(const Cat& assig)
{
	this->_type = assig._type;
	*(_Brain) = *(assig._Brain);
	return *this;
}

void Cat::makeSound() const
{
	cout << "Miau!\n";
}

Brain* Cat::getbrain()
{
	return this->_Brain;
}
