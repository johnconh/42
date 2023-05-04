/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:36:38 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/04 20:21:53 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void menu()
{
	std::cout << "==== Elige un numero o ingresa el comando que deseas ====\n";
	std::cout << "* 1. ADD:	Agrega contacto\n";
	std::cout << "* 2. SEARCH:	Busca contacto\n";
	std::cout << "* 3. EXIT\n\n";
	std::cout << "> ";
}

int main()
{
	Phonebook	agenda;
	std::string	cmd;

	menu();
	while(getline(std::cin, cmd))
	{
		system("clear");
		menu();
		if(cmd == "ADD" || cmd == "1")
		{
			//agenda.add();
			printf("entra\n");
		}
		else if(cmd == "SEARCH" || cmd == "2")
		{
			//agenda.search();
			printf("entra s\n");
		}
		else if(cmd == "EXIT" || cmd == "3")
			break;
	}
	return 0;
}
