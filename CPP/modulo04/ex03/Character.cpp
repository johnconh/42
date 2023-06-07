/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:32:04 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/06 18:37:12 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	cout << "Character default constructor called\n";
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;	
}

Character::Character(const string& name): _name(name)
{
	cout << "Character name: " << _name << " constructor called\n";
	for(int i = 0; i < 4; i++)
		this->_inventory[i] =  NULL;	
}

Character::Character(const Character& copy)
{
	cout << "Character copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if(copy._inventory[i] != NULL)
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character()
{
	cout << "Charater destructor called\n";
	for (int i = 0; i < 4; i++)
		if(this->_inventory[i] != NULL)
			delete this->_inventory[i];
}

Character& Character::operator=(const Character& assig)
{
	this->_name = assig._name;
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

string const& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if(idx >= 0 && idx < 4)
		this->_inventory[idx] = NULL; 
}

void Character::use(int idx, ICharacter& target)
{
	if((idx >=0 && idx < 4) && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}
