/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:13:52 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/15 20:01:52 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

int main()
{
	Data d;
	d.value = 42;

	Data d2;
	d2.value = 42;
	
	// Serializar la direccion de la estructura.
	uintptr_t s =  serialize(&d);
	cout << "direccion d: " << &d << std::endl;
	cout << "direccion s despues serializar: " << &s << std::endl;

	// Deserializar el valor y obtener un puntero a Data.
	Data* ds = deserialize(s);

	cout << "Direcion ds despues de desserializar: " << ds << std::endl;

	// Verificar si los punteros son iguales
	if (ds == &d)
		cout << "Los punteros son iguales\n";
	else
		cout << "Error: los punteros no son iguales\n";
	
}
