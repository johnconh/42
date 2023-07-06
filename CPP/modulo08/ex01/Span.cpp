/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:28:47 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/06 19:31:43 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _size(0){}

Span::Span(unsigned int size): _size(size){}

Span::Span(const Span& copy){ *this = copy;}

Span::~Span(){}

Span& Span::operator=(const Span& assig)
{
	if( this != &assig)
	{
		this->_size = assig._size;
		this->_numbers = assig._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if(this->_numbers.size() >= this->_size)
		throw Maximun_number();
	this->_numbers.push_back(number);
}

void Span::addRange(vector<int>::iterator begin, vector<int>::iterator end)
{
	unsigned int count = std::distance(begin, end);
	if(this->_numbers.size() + count > this->_size)
		throw Maximun_number();
	this->_numbers.insert(this->_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (this->_numbers.size() <= 1)
		throw Insufficient();
	
	int mindiff = std::numeric_limits<int>::max(); //Inicializamos con un valor max.
	for (size_t i = 0; i < this->_numbers.size(); i++)
	{
		for (size_t j = i + 1; j < this->_numbers.size(); j++)
		{
			int diff = std::abs(this->_numbers[j] - this->_numbers[i]);//valor absoluto siempre sea positivo.
			if (diff < mindiff)
				mindiff = diff;
		}
	}
	return mindiff;
}

int Span::longestSpan()
{
	if (this->_numbers.size() <= 1)
		throw Insufficient();
	vector<int> sortednumbers = this->_numbers;
	std::sort(sortednumbers.begin(), sortednumbers.end());
	return sortednumbers.back() - sortednumbers.front();
}
