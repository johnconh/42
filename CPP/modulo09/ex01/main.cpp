/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:38:53 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/12 21:21:05 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	if(argc != 2)
	{
		cerr << "Error: RPN <expresion>\n";
		return (1);
	}

	try
	{
		RPN rpn;
		string str = argv[1];
		
		int result = rpn.evaluateRPN(str);

		cout << "Resultado: " << result << endl;
	}catch(const std::exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}
