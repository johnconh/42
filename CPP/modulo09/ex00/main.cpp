/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:15:49 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/18 16:59:25 by jdasilva         ###   ########.fr       */
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
	string extension = "";
	size_t doExt = filename.find_last_of('.');
	if (doExt != string::npos)
		extension = filename.substr(doExt + 1);

	if (extension != "csv" || extension != "txt")
	{
		cout << "Error: invalid file extension.\n";
		return 1;
	}	
	
	BitcoinExchange db;
	if(!db.loadPrices("data.csv"))
		return 1;	
	db.processFile(filename, db);
	
	return 0;
}
