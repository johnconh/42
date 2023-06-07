/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/07 20:05:40 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John", 150);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat.getGrade() << std::endl;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat.getGrade() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
