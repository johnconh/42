/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:55:23 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/06 17:34:17 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "====MutantStack test====\n";
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;

		mstack.pop();
		
		std::cout <<"Size: " << mstack.size() << std::endl << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << std::endl;
		std::cout << "====test list===\n";
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		
		mstack.pop_back(); //pop_front elimina el primer elemento.
		
		std::cout <<"Size: " << mstack.size() << std::endl << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	return 0;
}