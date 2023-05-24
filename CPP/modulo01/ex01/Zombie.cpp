/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:34:31 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/17 18:46:41 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::nameZombie(string name)
{
	this->_name = name;
	std::cout << "Zombie "<< this->_name << " creado"<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie "<< this->_name << " destruido"<< std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}

Zombie::Zombie(){}