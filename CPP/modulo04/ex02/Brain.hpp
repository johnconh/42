/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:28:23 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 17:24:31 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

using std::cout;
using std::string;
using std::endl;

class Brain
{
	public:
		string _ideas[100];
		Brain();
		Brain(const Brain& copy);
		~Brain();
		Brain& operator=(const Brain& assig);
};

#endif
