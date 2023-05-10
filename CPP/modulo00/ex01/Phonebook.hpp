/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:37:35 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/09 16:08:18 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>

class Contact 
{
	private:
		std::string first_name, last_name, nickname, phone_number, darkest_secret;
	public:
		void contact_first_name(const std::string firstname);
		void contact_last_name(const std::string lastname);
		void contact_nickname(const std::string _nickname);
		void contact_phone_number(const std::string phonenumber);
		void contact_darkest_secret(const std::string darkestsecret);
		bool empty_contact();
		void print_contact(int i);
		void printselect();
		std::string f_resize(std::string s);
};

class Phonebook
{
	private:
		Contact contact[8];
	public:
		void add();
		void search();
		bool check_space(std::string s);
		bool check_number(std::string s);
};

#endif
