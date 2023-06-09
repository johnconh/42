/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:56:58 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/09 16:55:11 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("john"), _status(false), _sign(1), _execute(1)
{
	cout << "Form default constructor called\n";
}

Form::Form(const string& name, int sign, int execute): _name(name), _status(false), _sign(sign), _execute(execute)
{
	validateGrade();
	cout << "Form name: "<< _name << " constructor called\n";
}

Form::Form(const Form& copy): _name(copy.getName()), _status(copy.isStatus()), _sign(copy.getSign()), _execute(copy.getExecute())
{
	cout << "Form copy contructor called\n";
	validateGrade();
}

Form::~Form()
{
	cout << "Form destructor called\n";
}

Form& Form::operator=(const Form& assig)
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

const string Form::getName() const
{
	return this->_name;
}

int Form::getSign() const
{
	return this->_sign;
}

int Form::getExecute() const 
{
	return this->_execute;
}

bool Form::isStatus() const 
{
	return this->_status;
}

void Form::validateGrade() const
{
	if (this->_sign < 1 || this->_execute < 1)
		throw GradeTooHighException();
	else if (this->_sign > 150 || this->_execute > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->_sign)
		this->_status = true;
	else
		throw GradeTooLowException();
}

ostream& operator<<(ostream& os, const Form& f)
{
	os << "Form: " <<  f.getName() <<", Signed: " << (f.isStatus() ? "YES" : "NO")
		<<", Grade Required to sign: " << f.getSign()
		<<", Grade Required to execute: " << f.getExecute();
	return os;
}
