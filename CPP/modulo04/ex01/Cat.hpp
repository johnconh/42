/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:46:29 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 18:03:13 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain* _Brain;
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat();
		Cat& operator=(const Cat& assig);
		void makeSound() const;
		Brain* getbrain();
};
#endif
