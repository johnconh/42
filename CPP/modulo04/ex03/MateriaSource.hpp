/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:39:01 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/06 18:18:09 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();
		MateriaSource& operator=(const MateriaSource& assig);
		
		void learnMateria(AMateria* materia);
		AMateria* createMateria(string const& type);
};

#endif
