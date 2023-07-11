/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:15:49 by jdasilva          #+#    #+#             */
/*   Updated: 2023/07/11 19:21:39 by jdasilva         ###   ########.fr       */
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

	processFile(filename);

	return 0;
}
