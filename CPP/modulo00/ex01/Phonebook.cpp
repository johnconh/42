/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:35:38 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/11 17:04:28 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

bool Phonebook::check_space(std::string s)
{
	for(int i = 0; s[i]; i++)	
		if(!isspace(s[i]))
			return true;
	return false;
}

bool Phonebook::check_number(std::string s)
{
	for(int i = 0; s[i]; i++)
		if(isnumber(s[i]))
			return true;
	return false;
}

void Phonebook::add()
{
	static int index = 0;

	if (index == 8)
		index = 0;
	std::cout << "===== Agrega al usuario ======" << std::endl;
	std::string firstname;
	while(1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, firstname);
		if (check_space(firstname))
			break;
	};
	Phonebook::contact[index].contact_first_name(firstname);
	std::string lastname;
	while(1)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, lastname);
		if (check_space(lastname))
			break;
	}
	Phonebook::contact[index].contact_last_name(lastname);
	std::string nickname;
	while(1)
	{
		std::cout <<"Nickname: ";
		std::getline(std::cin, nickname);
		if (check_space(nickname))
			break;
	}
	Phonebook::contact[index].contact_nickname(nickname);
	std::string phonenumber;
	while(1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, phonenumber);
		if (check_space(phonenumber) && check_number(phonenumber))
			break;
	}
	Phonebook::contact[index].contact_phone_number(phonenumber);
	std::string darkestsecret;
	while(1)
	{
		std::cout <<"Darkest secret: ";
		std::getline(std::cin, darkestsecret);
		if(check_space(darkestsecret))
			break ;
	}
	Phonebook::contact[index].contact_darkest_secret(darkestsecret);
	std::cout << "***** ¡¡AGREGADO!! *****" << std::endl;
	index ++;
}

void Phonebook::search()
{
	if (contact[0].empty_contact())
	{
		std::cout << ">>> No hay contactos añadidos <<<" << std::endl << std::endl;
		return ;
	}
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;
	for(int i = 0; i < 8 && !contact[i].empty_contact(); i++)
		contact[i].print_contact(i);
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Elige un contacto escribiendo su Index (1 al 8), escribe 0 para ir atras" << std::endl;
	std::string index;
	while(1)
	{
		std::cout << "Index: ";
		std::getline(std::cin, index);
		if (check_space(index) && check_number(index))
		{
			if (index > "0" && index <= "8")
			{
				if (contact[index[0] - '0' - 1].empty_contact())
					std::cout << ">>> El contacto no existe<<<" << std::endl << std::endl;
				else
				{
					contact[index[0] - '0' - 1].printselect();
					break;
				}
			}
			if (index == "0")
				break ;
		}
	}
}
