/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:09:23 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/12 21:18:15 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::stack;
using std::cerr;
using std::istringstream;
using std::stoi;

class RPN
{
	private:
		stack<int> _stack;
		RPN& operator=(const RPN& assig);
		bool isOperator(const string& op) const;
		bool isNumber(const string& numb) const;
		int makeOperation(const string& op, int numb1, int numb2);
	public:
		RPN();
		RPN(const RPN& copy);
		~RPN();
		int evaluateRPN(const string& str);
		
	class Invalid: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Invalid";
			}
				
	};

	class Division: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "Division by Zero";
			}
	};
};

#endif
