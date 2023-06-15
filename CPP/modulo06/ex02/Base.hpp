/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:13:09 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/15 20:50:14 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::rand;
using std::srand;

class Base
{
	public:
		virtual ~Base();
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

Base* generate();
void  identify(Base* p);
 
#endif
