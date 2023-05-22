/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:36:30 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/22 18:22:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!\n"; 
}

void Harl::info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(string level)
{
	string harlfunct[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void (Harl::*p)();
	p functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++)
	{
		if(level == harlfunct[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	cout << "Invalid level specified\n";
}
