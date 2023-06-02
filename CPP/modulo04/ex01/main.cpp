/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:57:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 18:26:43 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void test1()
{
	const int numAnimales = 6;
    Animal* Animal[numAnimales];

    for (int i = 0; i < numAnimales; i++) {
        if (i % 2 == 0) 
		{
            Animal[i] = new Dog(); 
        } else 
		{
            Animal[i] = new Cat();
        }
    }
	
    for (int i = 0; i < numAnimales; i++) {
        Animal[i]->makeSound();
    }
	
/*     for (int i = 0; i < numAnimales; i++) {
        Dog* perro = dynamic_cast<Dog*>(Animal[i]);
        Cat* gato = dynamic_cast<Cat*>(Animal[i]);

        if (perro) {
            cout << "Dirección de memoria del cerebro del perro " << i + 1 << ": " << perro->getbrain() << endl;
        } else if (gato) {
            cout << "Dirección de memoria del cerebro del gato " << i + 1 << ": " << gato->getbrain() << endl;
        }
    } */
	
    for (int i = 0; i < numAnimales; i++) {
        delete Animal[i];
    }
	
}

void test2()
{
	Cat C1;
	Cat C2(C1);
	cout << C1.getbrain() << "\n";
	cout << C2.getbrain() << "\n";
	
	Dog D1;
	Dog D2(D1);
	cout << D1.getbrain() << "\n";
	cout << D2.getbrain() << "\n";
}


int main()
{
	//test1();
	test2();
    return 0;
}
