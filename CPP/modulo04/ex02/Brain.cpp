/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:34:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 17:24:46 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain constructor called\n";	
}

Brain::Brain(const Brain& copy)
{
	cout << "Brain copy constructor called\n";
	*this = copy;
}

Brain::~Brain()
{
	cout << "Brain destructor called\n";
}

Brain& Brain::operator=(const Brain& assig)
{
	for(int i = 0; i < 100; i ++)
		this->_ideas[i] = assig._ideas[i];
	return *this;
}
