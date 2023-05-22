/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:23:24 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/18 21:34:58 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void replace(string filename, string s1,  string s2)
{
 	std::ifstream file(filename);	
	if(!file)
	{
		cout << "No se pudo abrir el archivo " << filename << endl;
		return ;
	}
	
	string newfile = filename + "_replace";
	std::ofstream output(newfile);
	if(!output)
	{
		cout << "No se puedo crear el archivo " << newfile << endl;
		file.close();
		return;
	}

	string line;
	while(std::getline(file, line))
	{
		size_t pos = 0;
		while((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		output << line << endl;
	}
	file.close();
	output.close();
}
