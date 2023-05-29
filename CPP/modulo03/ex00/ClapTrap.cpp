/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:13:38 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/29 19:56:12 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_hp(10), _energy(10), _atkdmg(0)
{
	this->_name = "Borderlands";
	cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(const string& name): _name(name), _hp(10), _energy(10), _atkdmg(0)
{
	cout << "ClapTrap " << _name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	cout << "ClapTrap " << copy._name << " Copy constructor called\n";
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap " << _name << " Destructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& assig)
{
	cout << "ClapTrap " << assig._name << " operator called\n";
	this->_name = assig._name;
	this->_hp = assig._hp;
	this->_energy = assig._energy;
	this->_atkdmg = assig._atkdmg;
	return *this;
}

void ClapTrap::attack(const string& target)
{
	if(_hp > 0 && _energy > 0)
	{
		cout << "ClapTrap " << _name << " attack " << target << " cousing " << _atkdmg << " points fo damage\n";
		this->_energy --;
	}
	else
	{
		cout << "ClapTrap " << _name << " cannot attack due to lack of life or energy points.\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hp > 0)
	{
		cout << "ClapTrap " << _name << " receive " << amount << " damage points\n";
		this->_hp -= amount;
		if (_hp <= 0)
		{
			cout << "ClapTrap " << _name << " is destroyed\n";
		}
	}
	else 
	{
		cout << "ClapTrap "<< _name << " has been destroyed\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_hp > 0 && _energy > 0)
	{
		cout << "ClapTrap " << _name << " recover " << amount << "HP\n";
		this->_hp += amount;
		this->_energy --;
	}
	else
	{
		cout << "ClapTrap "<< _name << " cannot attack due to lack of life or energy points.\n";
	}
}
