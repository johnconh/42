/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:39:05 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/09 16:49:53 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Bureaucrat;

class Form
{
	private:
		const string	_name;
		bool			_status;
		const int		_sign;
		const int		_execute;
		
	public:
		Form();
		Form(const string& name, int sing, int execute);
		Form(const Form& copy);
		virtual ~Form();

		Form& operator=(const Form& assig);

		const string getName() const;
		bool isStatus() const;
		int getSign() const;
		int getExecute() const;
		void validateGrade() const;
		void beSigned(const Bureaucrat& b);
		
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Grade Too Low Exception";
				}
		};
		
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what()	const throw()
				{
					return "Grade Too High Exception";
				}
		};	
};

ostream& operator<<(ostream& os, const Form& f);

#endif
