/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:41:32 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/17 17:08:39 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string s= "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;
	
	std::cout << "La dirección de memoria de la variable de tipo string: " << &s << std::endl;
	std::cout << "La dirección de memoria contenida en stringPTR: " << stringPTR << std::endl;
	std::cout << "La dirección de memoria contenida en stringREF: "<< &stringREF << std::endl;

	std::cout << "El valor de la variable string: " << s << std::endl;
	std::cout << "El valor apuntado por stringPTR: " << *stringPTR << std::endl;
	std::cout << "El valor apuntado por stringREF: " << stringREF << std::endl;
	return 0;
}
