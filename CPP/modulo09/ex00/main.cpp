/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:15:49 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/12 18:44:34 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Usage: btc <imput-file>\n";
		return 1;
	}

	string filename(argv[1]);
	BitcoinExchange db;
	db.loadPrices("data.csv");

	db.processFile(filename, db);
	
	return 0;
}
