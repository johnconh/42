/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:08:58 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/15 18:47:39 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int main (int argc, char **argv)
{
	if (argc  != 2)
	{
		cout << "Error: Debes proporcionar solo un argumento\n";
		return -1;
	}
	
	convertoChar(argv[1]);
	convertoInt(argv[1]);
	convertoFloat(argv[1]);
	convertoDouble(argv[1]);

	return 0;
}
