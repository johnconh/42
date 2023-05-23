/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:55:00 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/22 20:26:01 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;

class Fixed
{
	private:
		int _numb;
		static const int _bit = 8 ;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& assig);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits ( int const raw );
};
#endif
