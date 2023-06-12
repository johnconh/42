/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:35:10 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/12 18:22:33 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("john") 
{
	cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
	cout << "ShrubberyCreationForm target " << target << " contructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
	cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assig)
{
	if (this != &assig)
	{
		this->_target = assig._target;
		AForm::operator=(assig);
	}
	return *this;
}

string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if(!this->isStatus())
		throw AForm::NoSigned();
	if(executor.getGrade() > this->getExecute())
		throw AForm::GradeTooLowException();
		
	std::ofstream output((_target + "_shubbery").c_str());
	if(!output)
		throw AForm::Openfailed();
    output <<"           	  %%%,%%%%%%%" << endl;
    output <<"             ,'%% \\-*%%%%%%%" << endl;
    output <<"           ;%%%%%*%   _%%%%" << endl;
    output <<"         ,%%%       \\(_.*%%%%." << endl;
    output <<"         % *%%, ,%%%%*(    '" << endl;
    output <<"       %^     ,*%%% )\\|,%%*%,_"<< endl;
	output <<"            *%    \\/ #).-\"*%%*"<< endl;
    output <<"                 _.) ,/ *%,"<< endl;
    output <<"         _________/)#(_____________" << endl;
	output <<" Se supone que es un arbol :D\n";
	output.close();
} 
