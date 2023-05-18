/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:13:35 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/17 18:47:44 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

using std::string;

class Zombie
{
	private:
		string _name;
		
	public:
		Zombie();
		Zombie(string name);
		~Zombie();
		void 	announce(void);
};
		
Zombie* newZombie( string name );
void 	randomChump( string name );

#endif
