/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/09 16:51:47 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try{
        // Crear un Bureaucrat
        Bureaucrat bureaucrat("John", 3);

        //bureaucrat.incrementGrade();
        //bureaucrat.decrementGrade();
        
        // Crear un Formulario
        Form form("Formulario 1", 5, 100);
        //Form2(form);
        //Form f;

        //f = form;
        //Form form2(form);
        //cout << form << endl;
        //cout << f << endl;

        // Intentar firmar el formulario
        bureaucrat.signForm(form);
        //cout << form << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        cout << "Bureaucrat Error: " << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        cout << "Bureaucrat Error: " << e.what() << endl;
    } catch (const Form::GradeTooLowException& e) {
        cout << "Form Error: " << e.what() << endl;
    } catch (const Form::GradeTooHighException& e){
        cout << "Form Error: " << e.what() << endl;
    }

    // pilla todas las excepciones.
    //catch (const std::exception& e){
    //     cout << "Error: " << e.what() <<endl;
    // }
    
    return 0;
}
