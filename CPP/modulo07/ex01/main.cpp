/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:58:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/19 19:23:26 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int Array[] = {5,2,3,4,5};
	size_t length = sizeof(Array) / sizeof(Array[0]);

	cout << "Iterating over Array: ";
	iter(Array, length, print<int>);
	cout << endl;

	double Darray[] = {4.1, 2.3, 5.44, 10,1, 1029.45};
	size_t dlength = sizeof(Darray) / sizeof(Darray[0]);

	cout << "Iterating over Array: ";
	iter(Darray, dlength, print<double>);
	cout << endl;
}
