/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:36:30 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/23 19:09:36 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	cout << "[ DEBUG ]\n";
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!\n"; 
}

void Harl::info(void)
{
	cout << "[ INFO ]\n";
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	cout << "[ WARNING ]\n";
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	cout << "[ ERROR ]\n";
	cout << "This is unacceptable! I want to speak to the manager now.\n";
}

int Harl::getindex(const string& level)
{
	string harlfunct[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if(level == harlfunct[i])
			return (i);
	}
	return (4);
}

void Harl::complain(int index)
{
	switch (index)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}
