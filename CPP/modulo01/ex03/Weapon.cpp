/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:19:17 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/18 18:21:03 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string type):_type(type){}

Weapon::~Weapon(){}

const string& Weapon::getType()
{
	return(_type);
}

void Weapon::setType(string type)
{
	this->_type = type;
}
