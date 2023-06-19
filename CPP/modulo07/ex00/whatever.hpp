/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:36:12 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/19 18:11:12 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename t>
void swap(t& a, t&b)
{
	t temp = a;
	a = b;
	b = temp;
}

template <typename t>
t min(t a, t b)
{
	return ((a < b) ? a : b);
} 

template <typename t>
t max(t a, t b)
{
	return ((a > b) ? a : b);
}

#endif
