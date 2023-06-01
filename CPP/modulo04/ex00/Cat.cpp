/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:50:50 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/01 18:03:49 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type="Cat";
	cout << "Cat constructor is called\n";
}

Cat::Cat(const Cat& copy)
{
	cout <<"Cat copy constructor is called\n";
	*this = copy;
}

Cat::~Cat()
{
	cout <<"Cat destructor is called\n";
}

Cat& Cat::operator=(const Cat& assig)
{
	this->_type = assig._type;
	return *this;
}

void Cat::makeSound() const
{
	cout << "Miau!\n";
}
