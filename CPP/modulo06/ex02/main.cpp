/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:40:45 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/15 20:59:59 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(std::time(NULL));
	Base* a = generate();
	Base* b = generate();
	Base* c = generate();

	identify(a);
	identify(b);
	identify(c);

	delete a;
	delete b;
	delete c;
}
