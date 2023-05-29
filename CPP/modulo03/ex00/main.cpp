/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:04:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/29 19:56:26 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	ClapTrap A("Tiny Tina");
	ClapTrap B("Moxxi");
	ClapTrap C (B);
	ClapTrap D;
	ClapTrap E;

	D = A;

	A.attack("Moxxi");
	B.takeDamage(5);
	B.beRepaired(3);
	B.attack("Tiny Tina");
	A.takeDamage(12);
	A.attack("Moxxi");
	C.attack("Tiny Tina");
	D.attack("Claptrap");
	E.attack("Claptrap");
}
