/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:40:18 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/31 17:20:05 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamonTrap : public FragTrap, public ScavTrap
{
	private:
		string _name;
		using	FragTrap::inithp;
		using	FragTrap::initdmg;
		using	ScavTrap::initenergy;
	public:
		DiamonTrap();
		DiamonTrap(const string& name);
		DiamonTrap(const DiamonTrap& copy);
		~DiamonTrap();

		DiamonTrap& operator=(const DiamonTrap& assig);
		
		int gethp();
		int getenergy();
		int getatkdmg();
		void whoAmI();
		using ScavTrap::attack;
};

#endif
