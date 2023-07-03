/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:18:54 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/03 20:26:02 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(30);
	int array[] = {6, 3, 17, 9, 11, 99, 67, 4, 56, 78, 103};
	vector<int> numbs(array, array + sizeof(array) / sizeof(array[0]));
	try
	{
		sp.addRange(numbs.begin(), numbs.end());

		cout << sp.shortestSpan() << std::endl;	
		cout << sp.longestSpan() << std::endl;
	} catch (const exception& e)
	{
		cout << "Error: " << e.what();
	}
	
	return 0;
}
