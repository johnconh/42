/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:09:05 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/31 17:22:04 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	cout << "FragTrap Default constructor called\n";
	this->_name = "Brodelands3";
	inithp();
	initenergy();
	initdmg();
}

FragTrap::FragTrap(const string& name): ClapTrap(name)
{	
	cout << "FragTrap " << _name << " constructor caled\n";
	inithp();
	initenergy();
	initdmg();
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap()
{
	cout << "FragTrap " << copy._name << " Copy constructor called\n";
	*this=copy;
}

FragTrap::~FragTrap()
{
	cout << "FragTrap " << _name << " Destructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& assig)
{
	cout << "FragTrap " << assig._name << " operator called\n";
	ClapTrap::operator=(assig);
	return *this;
}

void FragTrap::assigname(const string& name)
{
	this->_name = name;
}

void FragTrap::inithp()
{
	this->_hp = 250;
}

void FragTrap::initenergy()
{
	this->_energy = 100;
}

void FragTrap::initdmg()
{
	this->_atkdmg = 30;
}

void FragTrap::highFivesGuys()
{
	cout << "FragTrap " << _name << " requests a positive high five!\n";
}
