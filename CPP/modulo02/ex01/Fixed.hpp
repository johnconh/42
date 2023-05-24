/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:55:00 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/24 19:18:43 by jdasilva         ###   ########.fr       */
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
		Fixed(const int numb);
		Fixed(const float numb);
		Fixed(const Fixed& copy);
		~Fixed();
		int		get_numb() const;
		Fixed&	operator=(const Fixed& assig);
		int 	getRawBits() const;
		void 	setRawBits(int const raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
};

std::ostream& operator << (std::ostream& os, const Fixed& fix);
#endif
