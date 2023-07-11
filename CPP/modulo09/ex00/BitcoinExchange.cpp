/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:56:32 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/11 20:38:33 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){*this = copy;}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assig)
{
	if(this != &assig)
		this->_data = assig._data;
	return *this;
}

void BitcoinExchange::loadPrices(const string& filename)
{
	ifstream file(filename.c_str());
	if(!file)
	{
		cout << "Error: could not open file\n";
		return;
	}
	
	string line;
	while(std::getline(file, line))
	{
		stringstream ss(line);
		string dateStr, valueStr;
		if(std::getline(ss, dateStr, ',') && std::getline(ss, valueStr))
		{
			float value;
			istringstream(valueStr) >> value;
			_data[dateStr] = value;
		}
	}
	file.close();
}

float BitcoinExchange::getData(const string& date) const 
{
	map<string, float>::const_iterator it =this->_data.lower_bound(date);
	if(it == this->_data.end())
		--it; // No se encontro una fecha igual o superior, uso la ultima fecha.
	else if(it !=this->_data.begin() && it->first != date)
	{
		map<string, float>::const_iterator prevIt = it;
		-- prevIt;
		if(date.compare(prevIt->first) - date.compare(it->first) < 0) // se compara para saber cual es la fecha mas cercana a la anterior.
			it = prevIt;
	}

	return it->second;
}

void processFile(const string& filename, const BitcoinExchange& db)
{
	ifstream file(filename.c_str());
	if(!file)
	{
		cout << "Error: coud not open file\n";
		return;
	}

	string line;
	while(getline(file, line))
	{

		stringstream ss(line);
		string dateStr, valueStr;
		if(getline(ss, dateStr, '|') && getline(ss,valueStr))
		{
			istringstream dateStream(dateStr);
			string year, month, day;
			if(getline(dateStream, year, '-') && getline(dateStream, month, '-') && getline(dateStream, day))  
			{
				day.erase(day.find_last_not_of(' ') + 1);
				if (isValidDate(year, month, day))
				{
					float value;
					istringstream valueStream(valueStr);
					if(valueStream >> value)
					{
						if(value > 1000)
							cout << "Error: too large number.\n";
						else if (value < 0)
							cout << "Error: not a positive number\n";
						else
						{
							float data = db.getData(year + '-' + month + "-" + day);
							cout << year << "-" << month << "-" << day <<": "<< value << endl;
							
						}
						
					}
					else
						cout << "Error: Bad input => " << line << endl;
				}
					cout << "Error: Bad input => " << line << endl;
			}
		}
		else
		{
			cout << "Error: Bad input => " << line << endl;
		}
		
	}
	
}

bool isValidDate(string yearStr, string monthStr, string dayStr)
{
	int year = stoi(yearStr);
	int month = stoi(monthStr);
	int day  = stoi(dayStr);

	if( year < 2009 || year > 2022 ||  month < 1 || month > 12 || day < 1)
		return false;

	if(month == 2)
	{
		bool bisiesto = (year % 4 == 0);

		if(bisiesto && day > 29)
			return false; 
		if(!bisiesto && day > 28)
			return false;
		return true;
	} 
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	else if (day > 31)
		return false;
	return true;
}