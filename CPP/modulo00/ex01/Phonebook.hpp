/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:37:35 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/16 19:54:39 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include <iomanip>

using std::string;

class Contact 
{
	private:
		string first_name; 
		string last_name; 
		string nickname; 
		string phone_number;
		string darkest_secret;
	public:
		void contact_first_name(const string firstname);
		void contact_last_name(const string lastname);
		void contact_nickname(const string _nickname);
		void contact_phone_number(const string phonenumber);
		void contact_darkest_secret(const string darkestsecret);
		bool empty_contact();
		void print_contact(int i);
		void printselect();
		string f_resize( string s);
};

class Phonebook
{
	private:
		Contact contact[8];
	public:
		void add();
		void search();
		bool check_space(string s);
		bool check_number(string s);
};

#endif
