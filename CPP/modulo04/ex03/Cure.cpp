/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:24:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 19:48:48 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	cout << "Cure constructor called\n";
}

Cure::Cure(const Cure& copy): AMateria(copy)
{
	cout << "Cure copy contructor called\n";
}

Cure::~Cure()
{
	cout << "Cure destructor called\n";
}

Cure& Cure::operator=(const Cure& assig)
{
	this->_type = assig._type;
	return *this;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	cout << "* heals " << target.getName() << "’s wounds *\n";
}