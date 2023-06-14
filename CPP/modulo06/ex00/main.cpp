/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:08:58 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/14 20:10:31 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

bool isNumber (const string& str)
{
	if(str.empty())
		return false;
		
	for(string::const_iterator it = str.begin(); it != str.end(); it ++)
		if(!std::isdigit(*it))
			return false;

	return true;
}

bool isDecimal (const string& _str)
{
	string str = _str;
	
	if(str.empty())
		return false;
		
	if(str[str.length() - 1] == 'f')
		str = str.substr(0, str.length() - 1);
	
	bool decimalpointfound = false;
	
	for(string::size_type i = 0; i < str.length(); i++)
	{
		if(str[i] == '.')
		{
			if(decimalpointfound)
				return false;
			decimalpointfound = true;
		}
		else if(!std::isdigit(str[i]))
			return false;
	}

	return decimalpointfound;
}

int main (int argc, char **argv)
{
	if (argc  != 2)
	{
		cout << "Error: Debes proporcionar solo un argumento\n";
		return -1;
	}

	string arg = argv[1];
	
	//convertoChar(argv[1]);
	if(isNumber(arg))
	{
		int valor = std::atoi(argv[1]);
		char car = 0;
		if (valor >=33 && valor <= 126)
		{
			car = static_cast<char>(valor);
			cout << "Char: " << car << endl;
		}
		else
			cout << "Char: Non displayable\n";
	}
	else if(isDecimal(arg))
	{
		int valor = std::atof(argv[1]);
		char car = 0;
		if (valor >=33 && valor <= 126)
		{
			car = static_cast<char>(valor);
			cout << "Char: " << car << endl;
		}
		else
			cout << "Char: Non displayable\n";	
	}
	else 
	{
		if(arg.size() == 1)
		{
			cout << "Char: " << arg << endl;
		}
		else
			cout << "Char: impossible\n";
	}

	
}
