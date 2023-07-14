/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:58:26 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/13 18:21:02 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& copy){*this = copy;}

RPN::~RPN(){}

RPN& RPN::operator=(const RPN& assig)
{
	if(this != &assig)
		this->_stack = assig._stack;
	return *this;
}

bool RPN::isOperator(const string& op) const{return (op == "+" || op == "-" || op == "*" || op ==  "/");}
bool RPN::isNumber(const string& numb) const{return (numb.length() == 1 && std::isdigit(numb[0]));}

int RPN::makeOperation(const string& str, int numb1, int numb2)
{
	char op = str[0];
	
	switch (op)
	{
		case '+':
			return numb1 + numb2;
		case '-':
			return numb1 - numb2;
		case '*':
			return numb1 * numb2;
		case '/':
			if(numb1 == 0)
				throw Division();
			return numb1 / numb2;
		default:
			throw Invalid();
	}	
}

int RPN::evaluateRPN(const string& str)
{
	istringstream ss(str);
	string token;
	
	while(ss >> token)
	{
		if(isNumber(token))
			_stack.push(stoi(token));
		else if(isOperator(token))
		{
			if(_stack.size() < 2)
				throw Invalid();
			
			int numb2 = _stack.top();
			_stack.pop();
			int numb1 =_stack.top();
			_stack.pop();
			
			int result = makeOperation(token, numb1, numb2);
			_stack.push(result);
		}
		else
			throw Invalid();
	}
	if (_stack.size() > 1 || _stack.size() == 0)
		throw  Invalid();
	return _stack.top();
}
