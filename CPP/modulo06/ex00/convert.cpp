/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:39:06 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/15 19:05:00 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

bool isPseudo(const string& str)
{
	if(str.empty())
		return false;
	
	if(str.compare("nan") == 0 || str.compare("+inf") == 0 || str.compare("-inf") == 0)
		return true;
	else
		return false;
}

bool isNumber (const string& str)
{
	if(str.empty())
		return false;
		
	for(string::size_type i = 0; i < str.length(); i++)
	{
		if(i == 0 && str[0] == '-')
			i++;
		if(!std::isdigit(str[i]))
			return false;
	}
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
		if(i == 0 && str[0] == '-')
			i++;
		if(str[i] == '.' && str[i + 1] != '\0')
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


void convertoChar(char *argv)
{
	string arg = argv;
		
	if(isNumber(arg))
	{
		int valor = std::atoi(argv);
		char car = 0;
		if (valor >=33 && valor <= 126)
		{
			car = static_cast<char>(valor);
			cout << "Char: " << '\'' << car << '\'' << endl;
		}
		else
			cout << "Char: Non displayable\n";
	}
	else if(isDecimal(arg))
	{
		int valor = std::atof(argv);
		char car = 0;
		if (valor >=33 && valor <= 126)
		{
			car = static_cast<char>(valor);
			cout << "Char: " << '\'' << car << '\'' << endl;
		}
		else
			cout << "Char: Non displayable\n";	
	}
	else 
	{
		if(arg.size() == 1)
		{
			if (arg[0] == 32)
				cout << "Char: Non displayable\n";
			else
			{
				char car = static_cast<char>(arg[0]);
				cout << "Char: " << car << endl;
			}
		}
		else
			cout << "Char: impossible\n";
	}
}

void convertoInt(char *argv)
{
	string arg = argv;

	if(isNumber(arg))
	{
		int valor = std::atoi(argv);
		cout << "Int: " << valor << endl;
	}
	else if(isDecimal(arg))
	{
		int value = std::atof(argv);
		cout << "Int: " << value << endl;
	}
	else
	{
		if (arg.size()== 1)
		{
			int intvalue = static_cast<int>(arg[0]);
			cout << "Int: " << intvalue <<endl;
		}
		else
			cout << "Int: impossible\n";
	}
}

void convertoFloat(char *argv)
{
	string arg = argv;

	if(isPseudo(arg))
	{
		cout << "Float: " << arg <<"f\n";
	}
	else if(isNumber(arg))
	{
		int value = std::atoi(argv);
		float fvalue = static_cast<float>(value);
		cout << "Float: " << fvalue <<".0f\n";
	}
	else if(isDecimal(arg))
	{
		float value = std::atof(argv);
		cout << "Float: " << value << "f\n";
	}
	else
	{
		if(arg.size() == 1)
		{
			float fvalue = static_cast<float>(arg[0]);
			cout << "Float: " << fvalue <<".0f\n";
		}
		else
			cout << "Float: impossible\n";
	}
}

void convertoDouble(char *argv)
{
	string arg = argv;

	if(isPseudo(arg))
	{
		cout << "Double: " << arg << endl;
	}
	else if(isNumber(arg))
	{
		int value = std::atoi(argv);
		double dvalue = static_cast<double>(value);
		cout << "Double: " << dvalue << ".0\n";
	}
	else if(isDecimal(arg))
	{
		double value = std::atof(argv);
		cout << "Double: " << value << endl;
	}
	else
	{
		if(arg.size() == 1)
		{
			double fvalue = static_cast<double>(arg[0]);
			cout << "Double: " << fvalue << ".0\n";
		}
		else
			cout << "Double: impossible\n";
	}
}
