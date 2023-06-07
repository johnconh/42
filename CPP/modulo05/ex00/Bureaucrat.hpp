/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:53:02 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/07 20:04:27 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Bureaucrat
{
	private:
		string 	_name;
		int 	_grade;
	public:
		Bureaucrat();
		Bureaucrat(const string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		
		Bureaucrat& operator=(const Bureaucrat& assig);
		
		void validateGrade() const;
		int getGrade() const;
		const string getName() const;
		void incrementGrade();
		void decrementGrade();
		
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

ostream& operator<<(ostream& os,const Bureaucrat& b);

#endif
