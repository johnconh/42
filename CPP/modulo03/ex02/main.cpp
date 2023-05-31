/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:04:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/30 20:41:18 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
	FragTrap A("Tiny Tina");
	FragTrap B("Moxxi");
	ScavTrap D;
	FragTrap C (B);
	FragTrap E;
	

	A.attack("Moxxi");
	B.takeDamage(5);
	B.beRepaired(3);
	B.attack("Tiny Tina");
	A.takeDamage(112);
	A.attack("Moxxi");
	C.attack("Tiny Tina");
	D.attack("Claptrap");
	E.attack("Claptrap");
	E.highFivesGuys();
}
