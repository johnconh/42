/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:47:53 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/06 19:21:48 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

using std::cout;
using std::endl;
using std::string;

class AMateria
{
	protected:
		string _type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& copy);
		virtual ~AMateria();
		AMateria& operator=(const AMateria& assig);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
