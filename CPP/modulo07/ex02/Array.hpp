/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:26:25 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/20 17:09:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
using std::cout;
using std::endl;

template <typename t>
class Array
{
	private:
		t* _elements;
		unsigned int _size;
	public:
		Array(): _elements(NULL), _size(0)
		{
			cout << "Array default constructor called\n";
		}
		
		Array(unsigned int n): _elements(new t[n]), _size(n)
		{
			cout << "Array " << n << " constructor called\n";
		}
		
		Array(const Array& copy): _elements(new t[copy._size]), _size(copy._size)
		{
			cout << "Array copy constructor called\n";
			for(unsigned int i = 0; i < _size; i++)
				_elements[i] = copy._elements[i];
		}
		
		~Array()
		{
			cout << "Array destructor called\n";
			delete [] _elements;
		}
		
		Array& operator=(const Array& assig)
		{
			if (this != &assig)
			{
				delete[] _elements;
				_elements = new t[assig._size];
				_size =  assig._size;
				for(unsigned int i = 0; i < _size; i++)
					_elements[i] = assig._elements[i];
			}
			return *this;
		}
		
		t& operator[](unsigned int index)
		{
			if(index >= _size)
				throw  Indexout();
			return _elements[index];
		}
		
		unsigned int size() const{ return this->_size;}
		
		class Indexout: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Index out of bounds";
				}
		};
};

#endif
