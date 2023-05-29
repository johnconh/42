/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:04:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/29 20:01:14 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
	ScavTrap A("Tiny Tina");
	ScavTrap B("Moxxi");
	ScavTrap C (B);
	ScavTrap D;
	ScavTrap E;

	D = A;

	A.attack("Moxxi");
	B.takeDamage(5);
	B.beRepaired(3);
	B.attack("Tiny Tina");
	A.takeDamage(112);
	A.attack("Moxxi");
	C.attack("Tiny Tina");
	D.attack("Claptrap");
	E.attack("Claptrap");
	E.guardGate();
}
