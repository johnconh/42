/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:57:51 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/02 18:42:51 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    // Animal animal; // Error: No se puede instanciar la clase Animal (abstracta)
    Dog perro;
    Cat gato;

    Animal* animalD = new Dog();
    Animal* animalC = new Cat();

    perro.makeSound();
    gato.makeSound();
    animalD->makeSound();
    animalC->makeSound();
    
    delete animalD;
    delete animalC;

    return 0;
}
