/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/13 16:56:17 by jdasilva         ###   ########.fr       */
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
        Form Form("Formulario 1", 5, 100);
        //Form Form2(Form);
        //cout << Form << endl;
        //cout << Form2 << endl;

        // Intentar firmar el Formulario
        bureaucrat.signForm(Form);
        //cout << Form << std::endl;
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
