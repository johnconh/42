/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:48:10 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/18 17:45:01 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(string name, Weapon &weapon): _name(name), _weapon(&weapon){}

void HumanA::attack()
{
	cout << this->_name << " attacks with their " << _weapon->getType() << endl;
}

HumanA::~HumanA(){}
