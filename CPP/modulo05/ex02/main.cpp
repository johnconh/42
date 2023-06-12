/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/12 18:23:01 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    try {
        // Crear un burócrata
        Bureaucrat bureaucrat("John", 1);
        std::cout << bureaucrat << std::endl;

        // Crear los formularios
        ShrubberyCreationForm shrubberyForm("garden");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm pardonForm("victim");

        // Firmar los formularios por el burócrata
        shrubberyForm.beSigned(bureaucrat);
        robotomyForm.beSigned(bureaucrat);
        pardonForm.beSigned(bureaucrat);

        // Ejecutar los formularios
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
