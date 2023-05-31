/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:09:01 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/31 17:18:18 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		void inithp();
		void initenergy();
		void initdmg();
	public:
		FragTrap();
		FragTrap(const string& name);
		FragTrap(const FragTrap& copy);
		~FragTrap();
	
		FragTrap& operator=(const FragTrap& assig);

		void highFivesGuys(void);
};

#endif
