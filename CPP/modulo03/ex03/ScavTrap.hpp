/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:34:45 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/31 17:07:19 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
		void initenergy();
	private:
		void assigname(const string& name);
		void inithp();
		void initdmg();
	public:
	ScavTrap();
	ScavTrap(const string& name);
	ScavTrap(const ScavTrap& copy);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& assig);
	
	void attack(const string& target);
	void guardGate();
};

#endif
