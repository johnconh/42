/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:24:42 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/14 21:15:20 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& copy){*this = copy;}

PmergeMe::~PmergeMe(){}

PmergeMe& PmergeMe::operator=(const PmergeMe& assig)
{
	if(this != &assig)
	{
		this->_deque = assig._deque;
		this->_vector = assig._vector;
	}
	return *this;
}

template<typename C>
void PmergeMe::showSequence(const C& c) const
{
	cout << "After:  ";
	for(typename C::const_iterator it = c.begin(); it != c.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

void PmergeMe::sort(int argc, char **argv)
{
	if (argc <= 1)
		throw Error();
		
	for(int i =  1; i < argc; i++)
	{
		int num = atoi(argv[i]);
		if(num > 0)
		{
			this->_deque.push_back(num);
			this->_vector.push_back(num);
		}
		else	
		 throw Error();
	}
	
	clock_t VtimeStart = clock();
	mergeInsertSort(this->_vector);
	clock_t VtimeEnd = clock();

	clock_t DtimeStart = clock();
	mergeInsertSort(this->_deque);
	clock_t DtimeEnd = clock();
	
	cout << "Before: ";
	for(int i = 1; i < argc; i++)
		cout << argv[i] << " ";
	cout << endl;
	showSequence(this->_vector);
	cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << (VtimeEnd - VtimeEnd) / CLOCKS_PER_SEC << " us\n"; 
	cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << (DtimeEnd - DtimeEnd) / CLOCKS_PER_SEC << " us\n"; 
}