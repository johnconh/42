/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:26:16 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/22 18:38:25 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

using std::cout;
using std::string;
using std::endl;

class Harl
{
	private:
		void 	debug(void);
		void 	info(void);
		void 	warning(void);
		void 	error(void);
	public:
		void	complain (int index);
		int		getindex (string level);
};
#endif
