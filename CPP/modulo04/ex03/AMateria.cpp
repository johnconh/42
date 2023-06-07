/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:08:40 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/06 19:20:15 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	cout << "AMateria default constructor called\n";
}


AMateria::AMateria(string const& type): _type(type)
{
	cout << "AMateria type "<< _type <<" constructor called\n";	
}

AMateria::AMateria(const AMateria& copy): _type(copy._type)
{
	cout << "AMateria copy constructor called\n";
}

AMateria::~AMateria()
{
	cout << "AMateria destructor called\n";
}

AMateria& AMateria::operator=(const AMateria& copy)
{
	this->_type = copy._type;
	return *this;
}

string const& AMateria::getType()const 
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	cout << "* uses " << this->_type << " on " << target.getName() << " *" << endl;
}
