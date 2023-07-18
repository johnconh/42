/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:24:42 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/18 17:28:16 by jdasilva         ###   ########.fr       */
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
	for(int i =  1; i < argc; i++)
	{
		if (!isValidnumber(argv[i]))
			throw Error();
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
	mergeInsertSort(this->_vector.begin(), this->_vector.end());
	clock_t VtimeEnd = clock();

	clock_t DtimeStart = clock();
	mergeInsertSort(this->_deque.begin(), this->_deque.end());
	clock_t DtimeEnd = clock();
	
	cout << "Before: ";
	for(int i = 1; i < argc; i++)
		cout << argv[i] << " ";
	cout << endl;
	showSequence(this->_vector);
	cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << (VtimeEnd - VtimeStart) * 1000.0 / CLOCKS_PER_SEC << " us\n"; 
	cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << (DtimeEnd - DtimeStart) * 1000.0 / CLOCKS_PER_SEC << " us\n"; 
}

bool PmergeMe::isValidnumber(char *argv)
{
	string numb = argv;
	
	if(numb.empty())
		return false;

	for(size_t i = 0; i < numb.length(); i++)
	{
		if(!std::isdigit(numb[i]) && !(i == 0 && (numb[i] == '+' || numb[i]== '-')))
		return false;
	}
	
	return true;
}
