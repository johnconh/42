/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:32:40 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/22 18:34:05 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	int index;
	if (argc != 2)
	{
		cout << "Error\n";
		return 1;
	}
	Harl h;
	index = h.getindex(argv[1]);
	h.complain(index);
	return 0;
}
