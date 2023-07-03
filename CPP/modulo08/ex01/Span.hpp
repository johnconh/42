/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:02:58 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/03 20:23:50 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::runtime_error;
using std::exception;

class Span
{
	private:
		unsigned int _size;
		vector<int> _numbers;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		~Span();
		
		Span& operator=(const Span& assig);
		
		void addNumber(int number);
		void addRange(vector<int>::iterator begin, vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		
};
#endif
