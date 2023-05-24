/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:18:27 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/17 17:08:24 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 4;
	Zombie *z;

	z = zombieHorde(N, "John");
	for(int i = 0; i < N; i++)
		z[i].announce();
	delete[] z;
	return 0;
}