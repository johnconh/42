/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:17 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/20 18:42:08 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Notfound: public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Number not found";
		}
};

template<typename T>
typename T::iterator easyfind(T& cont, int value)
{
	typename T::iterator it = cont.begin();
	for(; it != cont.end(); it++)
		if(*it == value)
			return it;
	if(it == cont.end())
		throw Notfound();
	return cont.end();
}

#endif
