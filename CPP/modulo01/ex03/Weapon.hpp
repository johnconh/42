/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:10:06 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/18 17:08:16 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Weapon
{
	private:
		string _type;
	public:
		Weapon(string type);
		~Weapon();
		const string& getType();
		void	setType(string type);
};

#endif
