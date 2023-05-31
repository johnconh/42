/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:04:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/31 17:20:58 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main ()
{
	DiamonTrap A("Moxxi");

	cout << "hp: "<< A.gethp() << endl;
	cout << "energy: " << A.getenergy()<< endl;
	cout << "Atak: " << A.getatkdmg() << endl;
	A.attack("Tiny");
	A.whoAmI();
}

