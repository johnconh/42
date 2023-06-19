/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:53:12 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/19 19:06:49 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
using std::cout;
using std::endl;

template<typename t, typename func>
void iter(t* array, size_t length, func f)
{
	for(size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename t>
void print(t element)
{
	cout << element << " ";
}

#endif
