/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:33:14 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/15 18:36:45 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

void convertoChar(char *argv);
void convertoInt(char *argv);
void convertoFloat(char *argv);
void convertoDouble(char *argv);

bool isDecimal (const string& _str);
bool isNumber (const string& str);
bool isPseudo(const string& str);

#endif
