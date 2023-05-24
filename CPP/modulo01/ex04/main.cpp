/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:57:01 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/22 16:22:30 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Error. Usa <nombre_archivo> <palabra_1> <palabra_2>\n";
		return -1;
	}
	string control = argv[2];
	if(control.empty())
	{
		cout << "Error. La primera palabra a sustituir esta vacia\n";
		return -1;
	}
	replace(argv[1], argv[2], argv[3]);
	return 0;
}