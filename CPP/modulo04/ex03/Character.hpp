/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:58:01 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 20:08:32 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		string name;
		AMateria* invetory[4];
	public:
		Character();
		Character(const Character& copy);
		~Character();
		Character& operator=(const Character& assig);
		
		
};

#endif