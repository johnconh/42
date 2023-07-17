/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:20:45 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/17 17:45:31 by jdasilva         ###   ########.fr       */
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
					return "Error :C";
				}
		};
};


template<typename C>
void mergeInsertSort(C& sequence)
{
	if (sequence.size()<= 1)
		return;
		
	typename C::iterator mid = sequence.begin() + sequence.size() / 2;
	
	C left(sequence.begin(), mid);
	C rigth(mid, sequence.end());

	mergeInsertSort(left);
	mergeInsertSort(rigth);

	sequence.clear();

	std::merge(left.begin(), left.end(), rigth.begin(), rigth.end(), std::back_inserter(sequence));
	
	typename C::iterator it;
	for(it = sequence.begin() + 1; it != sequence.end(); ++it)
	{	
		typename C::iterator j = it - 1;
		while(j >= sequence.begin() && *j > *it)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = *it;
	}
}
#endif
