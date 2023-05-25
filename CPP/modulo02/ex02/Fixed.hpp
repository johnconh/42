/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:55:00 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/25 20:34:00 by jdasilva         ###   ########.fr       */
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
		
		Fixed&	operator=(const Fixed& assig);
		Fixed 	operator+(const Fixed& assig);
		Fixed	operator-(const Fixed& assig);
		Fixed	operator*(const Fixed& assig);
		Fixed	operator/(const Fixed& assig);
		
		Fixed&	operator++(); //preincremento
		Fixed&	operator--();
		Fixed	operator++(int); 
		Fixed	operator--(int);
		
		bool 	operator< (const Fixed& other) const;
		bool	operator> (const Fixed& other) const;
		bool	operator>= (const Fixed& other) const;
		bool	operator<= (const Fixed& other) const;
		bool	operator== (const Fixed& other) const;
		bool	operator!= (const Fixed& other) const;
		
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
		int		get_numb() const;
		int 	getRawBits() const;
		void 	setRawBits(int const raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
};

std::ostream& operator << (std::ostream& os, const Fixed& fix);
#endif
