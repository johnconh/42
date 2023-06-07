/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:50:14 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/06 18:40:45 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	cout << "Ice contructor called\n";
}

Ice::Ice(const Ice& copy): AMateria(copy)
{
	cout << "Ice copy contructor called\n";
}

Ice::~Ice()
{
	cout << "Ice destructor called\n";
}

Ice& Ice::operator=(const Ice& assig)
{
	this->_type = assig._type;
	return *this;
}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at "<< target.getName() << " *\n";
}
