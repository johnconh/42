/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:00:54 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/31 16:59:30 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamonTrap::DiamonTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
	cout << "ScavTrap Default constructor called\n";
	this->_name = "Borderlands4";
	inithp();
	initdmg();
	initenergy();
}

DiamonTrap::DiamonTrap(const string& name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	cout << "DiamonTrap " << _name << " constructor called\n";
	inithp();
	initdmg();
	initenergy();
}

DiamonTrap::DiamonTrap(const DiamonTrap& copy):ClapTrap()
{
	cout << "Diamond " << copy._name << " Copy constructor called\n";
	*this = copy;
}

DiamonTrap::~DiamonTrap()
{
	cout << "DiamonTrap " << _name << " Destructor called\n";
}

DiamonTrap& DiamonTrap::operator=(const DiamonTrap& assig)
{
	cout << "DiamonTrap " << assig._name << " operator called\n";
	ClapTrap::operator=(assig);
	return *this;
}

void DiamonTrap::whoAmI()
{
	cout << "I am " << _name <<", and my ClapTrap name is " << ClapTrap::_name << endl;
}

int DiamonTrap::gethp()
{
	return this->_hp;
}

int DiamonTrap::getatkdmg()
{
	return this->_atkdmg;
}

int DiamonTrap::getenergy()
{
	return this->_energy;
}
