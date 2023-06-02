/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:28:38 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 18:35:05 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

using std::cout;
using std::string;
using std::endl;

class Animal
{
	protected:
		string _type;
	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal();
		Animal& operator=(const Animal& assig);
		const string getType() const;
		virtual void makeSound() const = 0;
};
#endif
