/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:56:57 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/06 19:04:41 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	cout << "MateriaSource default constructor called\n";
	for(int i= 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if(copy._inventory[i] != NULL)
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	cout << "MateriaSource destructor called\n";
	for (int i = 0; i < 4; i++)
		if(this->_inventory[i] != NULL)
			delete this->_inventory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& assig)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if(assig._inventory[i] != NULL)
			this->_inventory[i] = assig._inventory[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventory[i] && this->_inventory[i]->getType() == type)
			return this->_inventory[i]->clone();
	}
	return NULL;
}
