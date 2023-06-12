/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:37:38 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/12 18:21:26 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("john")
{
	cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const string& target): AForm("PresidentialPardonForm", 25, 5), _target(target) 
{
	cout << "PresidentialPardonForm " << _target << " constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm("PresidentialPardonForm", 25, 5), _target(copy._target)
{
	cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assig)
{
	if (this != &assig)
	{
		this->_target = assig._target;
		AForm::operator=(assig);
	}
	return *this;
}

string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if(!this->isStatus())
		throw AForm::NoSigned();
	if (executor.getGrade() > this->getExecute())
		throw AForm::GradeTooLowException();
	cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
