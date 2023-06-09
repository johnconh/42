/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:47:48 by jdasilva          #+#    #+#             */
/*   Updated: 2023/06/09 19:09:14 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    try{
        // Crear un Bureaucrat
        Bureaucrat bureaucrat("John", 3);

        //bureaucrat.incrementGrade();
        //bureaucrat.decrementGrade();
        
        // Crear un AFormulario
       // AForm AForm("AFormulario 1", 5, 100);
        //AForm2(AForm);
        //AForm f;

        //f = AForm;
        //AForm AForm2(AForm);
        //cout << AForm << endl;
        //cout << f << endl;

        // Intentar firmar el AFormulario
        //bureaucrat.signAForm(AForm);
        //cout << AForm << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        cout << "Bureaucrat Error: " << e.what() << endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        cout << "Bureaucrat Error: " << e.what() << endl;
    } catch (const AForm::GradeTooLowException& e) {
        cout << "AForm Error: " << e.what() << endl;
    } catch (const AForm::GradeTooHighException& e){
        cout << "AForm Error: " << e.what() << endl;
    }

    // pilla todas las excepciones.
    //catch (const std::exception& e){
    //     cout << "Error: " << e.what() <<endl;
    // }
    
    return 0;
}
