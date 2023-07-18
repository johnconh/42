/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:20:45 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/18 18:15:07 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using std::cout;
using std::vector;
using std::deque;
using std::endl;
using std::atoi;
using std::clock;
using std::cerr;
using std::string;

class PmergeMe
{
	private:
		vector<int> _vector;
		deque<int>	_deque;
		
		template<typename C>
		void showSequence(const C& c) const;
		
		bool isValidnumber(char *argv);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& assig);
		
		void sort(int argc, char **argv);
	
		class Error: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Error";
				}
		};
};


template<typename I>
void mergeInsertSort(I begin, I end)
{
	const size_t size = std::distance(begin, end);
	
	if(size <= 1)
		return;
	
	I mid = begin + size / 2;
	
	mergeInsertSort(begin, mid);
	mergeInsertSort(mid, end);

	std::inplace_merge(begin, mid, end);
	
	for(I it = begin + 1; it != end; ++it)
	{	
		I j = it - 1;
		while(j >= begin && *j > *it)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = *it;
	}
}
#endif
