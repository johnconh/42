/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:37:03 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/20 17:47:17 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> a;
	cout << "Array size: " << a.size() << endl;

	Array<int> b(5);
	cout << "Array size: " << b.size() << endl;

	Array<int> c(b);
	cout << "Array size: "<< c.size() << endl;

	Array<int> d;
	d = b;
	cout << "Array size: "<< d.size() << endl;
	cout << endl;
	
	try
	{
		cout << "Array b[2]: " << b[2] << endl;
		cout << "Array b[10]: " << b[10] << endl;
	}catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
}
