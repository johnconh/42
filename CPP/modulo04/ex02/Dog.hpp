/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:10:27 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 18:03:43 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* _Brain;
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog& operator=(const Dog& assig);
		void makeSound() const;
		Brain* getbrain();
};
#endif
