/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:12:04 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/17 20:28:49 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::stringstream;
using std::istringstream;
using std::ifstream;
using std::stoi;
using std::strtod;

class BitcoinExchange
{
	private:
		map<string, float> _data;
	
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& assig);
		
		bool loadPrices(const string& file);
	 	float getData(const string& date) const;
		void processFile(const string& file, const BitcoinExchange& db);
		
	private:
		bool isValidDate(const string& yearStr, const string& monthStr, const string& dayStr) const;
		bool isFloat(const string& value) const ;
		bool isNumeric(const string& date) const;
};

#endif
