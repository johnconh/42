/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:11:55 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/12 19:58:17 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp" 

Intern::Intern()
{
	cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern& copy)
{
	cout << "Intern copy constructor called\n";
	*this = copy;
}

Intern::~Intern()
{
	cout << "Intern destructor called\n";
}
Intern& Intern::operator=(const Intern& assig)
{
	(void)assig;
	return *this;
}

AForm* Intern::makeForm(const string& name, const string& target)
{
	int i = 0;
	string selectForm[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* form = NULL;
	
	while( i < 3)
	{
		if(selectForm[i] == name)
			break;
		i ++;
	}
	
	switch (i)
	{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			cout << "Error: Invalid form name.\n";
			return form;
	}

	cout << "Inter creates " << name << endl;
	return form;
}
