/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:18:47 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/06 18:31:40 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& copy);
		~Cure();
		Cure& operator=(const Cure& assig);
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif
