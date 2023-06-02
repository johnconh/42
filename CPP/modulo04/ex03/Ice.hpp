/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:10:35 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 19:17:15 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{	
	public:
		Ice();
		Ice(const Ice& copy);
		~Ice();
		Ice& operator=(const Ice& assig);
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
