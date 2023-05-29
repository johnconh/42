/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:48:46 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/29 19:33:41 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	cout << "ScavTrap Default constructor called\n";
	this->_name = "Bordelands2";
	this->_hp = 100;
	this->_energy = 50;
	this->_atkdmg = 20;
}

ScavTrap::ScavTrap(const string& name): ClapTrap(name)
{
	cout << "ScavTrap " << _name << " constructor called\n";
	this->_name = name;
	this->_hp = 100;
	this->_energy = 50;
	this->_atkdmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap()
{
	cout << "Scavtrap " << copy._name << " Copy constructor called\n";
	*this=copy;
}

ScavTrap::~ScavTrap()
{
	cout << "Scavtrap " << _name << " Destructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& assig)
{
	cout << "ScavTrap " << assig._name << " operator called\n";
	ClapTrap::operator=(assig);
	return *this;
}

void ScavTrap::attack(const string& target)
{
	if(_hp > 0 && _energy > 0)
	{
		cout << "ScavTrap " << _name << " attack " << target << " cousing " << _atkdmg << " points fo damage\n";
		_energy --;
	}
	else
	{
		cout << "ScavTrap " << _name << " cannot attack due to lack of life or energy points.\n";
	}
}

void ScavTrap::guardGate()
{
	cout <<"ScavTrap " << _name << " is now in Gate Keeper mode\n";
}
