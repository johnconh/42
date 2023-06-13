/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/13 16:54:18 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


int main() {

    Intern someRandomIntern;
    AForm* rrf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    delete rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    delete rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    delete rrf;

    return 0;
}
