/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:56:58 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/09 17:15:14 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("john"), _status(false), _sign(1), _execute(1)
{
	cout << "AForm default constructor called\n";
}

AForm::AForm(const string& name, int sign, int execute): _name(name), _status(false), _sign(sign), _execute(execute)
{
	validateGrade();
	cout << "AForm name: "<< _name << " constructor called\n";
}

AForm::AForm(const AForm& copy): _name(copy.getName()), _status(copy.isStatus()), _sign(copy.getSign()), _execute(copy.getExecute())
{
	cout << "AForm copy contructor called\n";
	validateGrade();
}

AForm::~AForm()
{
	cout << "AForm destructor called\n";
}

AForm& AForm::operator=(const AForm& assig)
{
	if (this != &assig)
	{
		(string)this->_name = assig.getName();
		this->_status = assig.isStatus();
		validateGrade();
		//(int)this->_sign = assig.getSign();
		//(int)this->_execute = assig.getExecute();
	}
	return (*this);
}

const string AForm::getName() const
{
	return this->_name;
}

int AForm::getSign() const
{
	return this->_sign;
}

int AForm::getExecute() const 
{
	return this->_execute;
}

bool AForm::isStatus() const 
{
	return this->_status;
}

void AForm::validateGrade() const
{
	if (this->_sign < 1 || this->_execute < 1)
		throw GradeTooHighException();
	else if (this->_sign > 150 || this->_execute > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_sign)
		this->_status = true;
	else
		throw GradeTooLowException();
}

ostream& operator<<(ostream& os, const AForm& f)
{
	os << "AForm: " <<  f.getName() <<", Signed: " << (f.isStatus() ? "YES" : "NO")
		<<", Grade Required to sign: " << f.getSign()
		<<", Grade Required to execute: " << f.getExecute();
	return os;
}
