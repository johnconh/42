/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:32:40 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/22 17:56:04 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl h;
	string cmd;
	cout << "Level: ";
	while(1)
	{
		std::cin >> cmd;
		if(cmd == "EXIT")
			break ;
		h.complain(cmd);
		cout << "Level : ";
	}
	return 0;
}
