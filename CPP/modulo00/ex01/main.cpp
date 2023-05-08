/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:36:38 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/08 18:41:00 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void menu()
{
	std::cout << "==== Elige un numero o ingresa el comando que deseas ====" << std::endl;
	std::cout << "* 1. ADD:	Agrega contacto" << std::endl;
	std::cout << "* 2. SEARCH:	Busca contacto" << std::endl;
	std::cout << "* 3. EXIT\n\n" << std::endl;
	std::cout << "> ";
}

int main()
{
	Phonebook	agenda;
	std::string	cmd;

	menu();
	while(getline(std::cin, cmd))
	{
		if(cmd == "ADD" || cmd == "1")
			agenda.add();
		else if(cmd == "SEARCH" || cmd == "2")
			agenda.search();
		else if(cmd == "EXIT" || cmd == "3")
			break;
		menu();
	}
	return 0;
}
