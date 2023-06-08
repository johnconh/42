/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:28:36 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/08 19:50:56 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("john"), _grade(1)
{
	cout << "Bureaucrat: Default construtor called\n";
}

Bureaucrat::Bureaucrat(const string& name, int grade): _name(name), _grade(grade)
{
	validateGrade();
	cout << "Bureaucrat: " << _name << " grade " << _grade << " constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat&  copy)
{
	cout << "Bureaucrat copy constructor called\n";
	*this = copy;
	validateGrade();
}

Bureaucrat::~Bureaucrat()
{
	cout <<"Bureaucrat destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assig)
{
	if( this != &assig)
	{
		this->_name = assig._name;
		this->_grade = assig._grade;
	}
	return *this;
}

void Bureaucrat::validateGrade() const
{
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

const string Bureaucrat::getName() const
{
	return this->_name;
}

void Bureaucrat::incrementGrade()
{
	this->_grade--;
	validateGrade();
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	validateGrade();
}

ostream& operator<<(ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
		cout << this->_name << " signed " << f.getName() << endl;
	}catch(const Form::GradeTooLowException& e)
	{
		cout << this->_name << " couldn’t sign " << f.getName() <<" because " << e.what() << endl;
	}
}