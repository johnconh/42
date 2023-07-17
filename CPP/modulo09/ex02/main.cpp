/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:57:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/17 17:21:10 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		cerr << "Error: ./PmergeMe <input numbers>\n";
		return 1;
	}
	
	try
	{
		PmergeMe pm;
		pm.sort(argc, argv);
	}catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
