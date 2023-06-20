/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:29:34 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/20 19:02:17 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int arr[] = {5, 8, 1, 7, 9};
	vector<int> numb(arr, arr + sizeof(arr) /sizeof(arr[0]));
	int i = 1;

	try
	{
		vector<int>::iterator a = easyfind(numb, i);
		cout << "Valor: " << i << " encontrado en el indice: " << std::distance(numb.begin(), a) << endl;
	}catch(const std::exception& e)
	{
		cout << "Valor: " << i <<" "<< e.what() << endl;
	}
}
