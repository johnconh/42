/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:28:12 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/19 18:17:59 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	cout << "Base destructor called\n";
}

Base* generate()
{
	//srand(std::time(NULL));
	//Genera un numero aleatorio entre 0 y 2;
	int random = rand() % 3;

	if(random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p) != NULL)
		cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		cout << "A\n";
	}catch(const std::bad_cast&)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			cout << "B\n";
		}catch (const std::bad_cast&)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				cout << "C\n";
			}catch (const std::bad_cast&)
			{
				cout << "Tipo desconocido\n";
			}
		}
	}
}