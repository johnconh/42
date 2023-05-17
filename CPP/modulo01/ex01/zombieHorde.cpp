/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:23:23 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/17 16:35:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, string name )
{
	Zombie *z = new Zombie[N];

	for(int i = 0; i < N; i++)
		z[i].nameZombie(name);
	return z;
}
