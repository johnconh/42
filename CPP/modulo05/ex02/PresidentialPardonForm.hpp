/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:19:24 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/12 18:10:30 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& assig);
		
		string getTarget() const;
		void execute(const Bureaucrat& executor) const;
};		

#endif
