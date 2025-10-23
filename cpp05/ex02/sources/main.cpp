/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:34:04 by nihamdan          #+#    #+#             */
/*   Updated: 2025/10/10 00:24:43 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 20);
        Bureaucrat carol("Carol", 1);

        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur");

        std::cout << std::endl;

        alice.executeForm(shrubbery); // Should fail because form is not signed
        alice.executeForm(robotomy);  // Should fail because form is not signed
        alice.executeForm(pardon);    // Should fail because form is not signed

        std::cout << std::endl;

        alice.signForm(shrubbery);   // OK (145 req, Alice=50)
        alice.signForm(robotomy);    // OK (72 req, Alice=50)
        alice.signForm(pardon);       // Should be successful

        std::cout << std::endl;

        alice.executeForm(shrubbery); // Should be successful
        bob.executeForm(robotomy);  // Should be successful
        bob.executeForm(pardon);      // Should fail because Bob's grade is too low

        std::cout << std::endl;

        carol.executeForm(pardon);    // Should fail
        carol.signForm(pardon);
        carol.executeForm(pardon);  // Good now

        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}