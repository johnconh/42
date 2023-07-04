/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:24:33 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/04 20:10:12 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

using std::stack;


template<typename T, typename Container = std::deque<T> >
class MutantStack: public stack<T, Container>
{
	public:

		MutantStack(){}
		MutantStack(const MutantStack& copy){*this = copy;}
		~MutantStack(){}
		MutantStack& operator=(const MutantStack& assig)
		{
			if(this != &assig)
				stack<T, Container>::operator=(assig);
			return *this;
		}
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		
		iterator begin(){return stack<T, Container>::c.begin();}
		const_iterator cbegin(){return stack<T, Container>::c.cbegin();}
		iterator end(){return stack<T, Container>::c.end();}
		const_iterator cend(){return stack<T, Container>::c.cend();}
		reverse_iterator rbegin(){return stack<T, Container>::c.rbegin();}
		const_reverse_iterator crbegin(){return stack<T, Container>::c.crbegin();}
		reverse_iterator rend() {return stack<T, Container>::c.rend();}
		const_reverse_iterator crend() {return stack<T, Container>::c.crend();}
};

#endif
