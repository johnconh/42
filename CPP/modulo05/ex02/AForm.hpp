/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:39:05 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/09 17:14:57 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Bureaucrat;

class AForm
{
	private:
		const string	_name;
		bool			_status;
		const int		_sign;
		const int		_execute;
		
	public:
		AForm();
		AForm(const string& name, int sing, int execute);
		AForm(const AForm& copy);
		virtual ~AForm();

		AForm& operator=(const AForm& assig);

		const string getName() const;
		bool isStatus() const;
		int getSign() const;
		int getExecute() const;
		void validateGrade() const;
		void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;

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

		class NoSigned: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Signature not executed";
				}
		};

		class Openfailed: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Open failed";
				}
		};
};

ostream& operator<<(ostream& os, const AForm& f);

#endif
