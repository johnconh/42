/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:53:09 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/29 19:56:07 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class ClapTrap
{
	private:
		string			_name;
		int	_hp;
		int	_energy;
		int	_atkdmg;
	public:
		ClapTrap();
		ClapTrap(const string& name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();
		
		ClapTrap& operator=(const ClapTrap& assig);
		
		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif
