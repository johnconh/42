/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:55:19 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/12 18:22:06 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), _target("john")
{
	cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const string& target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	cout << "RobotomyRequestForm " << _target << " constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm("RobotomyRequestForm", 72, 45), _target(copy._target) 
{
	cout << "RobotomyRequestForm copy constructor called\n";	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assig)
{
	if (this != &assig)
	{
		this->_target = assig._target;
		AForm::operator=(assig);
	}
	return *this;
}

string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->isStatus())
		throw AForm::NoSigned();
	if(executor.getGrade() > this->getExecute())
		throw AForm::GradeTooLowException();

	cout << "Drilling noises..."<< endl;
	std::srand(std::time(NULL));
	bool success = (std::rand()% 2) == 0;

	if(success)
		cout << _target << " has been robotomized successfully!\n";
	else
		cout << "Robotomy failed for " << _target << endl;
}
