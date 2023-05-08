/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:35:41 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/08 20:59:17 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void Contact::contact_first_name(const std::string firstname)
{
	this->first_name = firstname;
}

void Contact::contact_last_name(const std::string lastname)
{
	this->last_name = lastname;
}

void Contact::contact_nickname(const std::string _nickname)
{
	this->nickname = _nickname;
}

void Contact::contact_phone_number(const std::string phonenumber)
{
	this->phone_number = phonenumber;
}

void Contact::contact_darkest_secret(const std::string darkestsecret)
{
	this->darkest_secret = darkestsecret;
}

bool Contact::empty_contact()
{
	if (this->first_name.length() == 0)
		return true;
	return false;
}

std::string Contact::f_resize(std::string s)
{
	s.resize(9);
	return s;
}

void Contact::print_contact(int i)
{
	std::cout << std::setw(10) << i + 1 << "|";
	if (this->first_name.length() <= 10)
		std::cout << std::setw(10) << this->first_name << "|";
	else
		std::cout << f_resize(this->first_name) + "." << "|";
	if (this->last_name.length() <= 10)
		std::cout << std::setw(10) << this->last_name << "|";
	else
		std::cout << f_resize(this->last_name) + "." << "|";
	if (this->nickname.length() <= 10)
		std::cout << std::setw(10) << this->nickname << "|" << std::endl;
	else
		std::cout << f_resize(this->nickname) + "." << "|" << std::endl;
}

void Contact::printselect()
{
	std::cout << "First Name: " << this->first_name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nick Name: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl << std::endl;
}

