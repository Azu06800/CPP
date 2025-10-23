/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:34:04 by nihamdan          #+#    #+#             */
/*   Updated: 2025/09/25 02:27:05 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // Passe à 1
        std::cout << b1 << std::endl;

        Form f1("Form B12", 25, 50); // création form fonctionnel
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
        Form f2("Form B14", 0, 50);
        
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade(); // Passe à 150
        std::cout << b2 << std::endl;

        Form f1("Form B12", 150, 170);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Joey", 120);
        std::cout << b3 << std::endl;

        b3.decrementGrade(); // Passe à 150
        std::cout << b3 << std::endl;

        Form f3("Form B77", 100, 100);
        
        b3.signForm(f3);
        std::cout << f3 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}